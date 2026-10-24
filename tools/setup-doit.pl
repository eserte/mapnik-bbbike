#!/usr/bin/env perl
# -*- perl -*-

use if !$ENV{DOIT_IN_REMOTE}, lib => "$ENV{HOME}/src/Doit/lib";
use Doit; # install from CPAN or do "git clone https://github.com/eserte/doit.git ~/src/Doit"
use Doit::Log;
use Doit::Util 'in_directory', 'get_os_release';
use FindBin;

return 1 if caller;

my $bbbikedir = "$FindBin::RealBin/../../bbbike";

my $doit = Doit->init;
$doit->add_component('deb');
$doit->add_component('guarded');

my $os_release = get_os_release;

$doit->deb_install_packages('osm2pgsql');

my $user = $ENV{USER} // error 'Cannot get current user from USER env var';

in_directory {
    if ('' eq $doit->info_qx({quiet=>1}, qw(sudo -u postgres psql -tAc), "SELECT 1 FROM pg_roles WHERE rolname='$user'")) {
	$doit->system(qw(sudo -H -u postgres createuser --superuser), $user);
    }
    if ('' eq $doit->info_qx({quiet=>1}, qw(sudo -u postgres psql -tAc), "SELECT 1 FROM pg_database WHERE datname='gis'")) {
	$doit->system(qw(createdb -E UTF8 gis));
    }

## XXX not needed? instead create extension, see below
#    if ('' eq $doit->info_qx({quiet=>1}, qw(psql -d gis -tAc), q{SELECT 1 FROM pg_tables WHERE tablename = 'spatial_ref_sys'})) {
#	# XXX use the current psql version to get the right version
#	my @postgis_sql = glob("/usr/share/postgresql/*/contrib/postgis-*/postgis.sql");
#	if (@postgis_sql != 1) {
#	    error "Too many or too few postgis.sql files in the system: @postgis_sql";
#	}
#	my @spatial_ref_sys_sql = glob("/usr/share/postgresql/*/contrib/postgis-*/spatial_ref_sys.sql");
#	if (@spatial_ref_sys_sql != 1) {
#	    error "Too many or too few postgis.sql files in the system: @spatial_ref_sys_sql";
#	}
#
#	$doit->system(qw(psql -d gis -f), @postgis_sql);
#	$doit->system(qw(psql -d gis -f), @spatial_ref_sys_sql);
#    }

    # XXX check missing
    $doit->system(qw(psql -d gis -c), "CREATE EXTENSION IF NOT EXISTS postgis;");
} '/tmp'; # psql wants to access the current directory, so change to one which is guaranteed to be accessible

my $inc_de_dir = "$FindBin::RealBin/../inc-de";
in_directory {
    # note: there are no system-specific settings in the ...mosor file
    $doit->copy('datasource-settings.xml.inc.mosor', 'datasource-settings.xml.inc');
    $doit->copy('fontset-settings.xml.inc.template', 'fontset-settings.xml.inc');
    if (!-d '../../../src/bbbike/images') {
	warning "The settings.xml.inc file expects that bbbike and mapnik-bbbike are checked out in the same directory";
    }
    $doit->copy('settings.xml.inc.mosor', 'settings.xml.inc');
} $inc_de_dir;

# workaround for ubuntu 22.04: the provided mapnik comes without proj support
# add the ubuntugis ppa to fix this problem
if ("@{$os_release}{qw(ID VERSION_ID)}" eq 'ubuntu 22.04') {
    my $ppa_owner = 'ubuntugis';
    my $ppa_dist  = $os_release->{ID};
    my $ppa_name  = 'ppa';
    my $ppa_codename = $os_release->{VERSION_CODENAME};
    $doit->guarded_step(
	"ppa for $ppa_name",
	ensure => sub {
	    my $ppa_list = "/etc/apt/sources.list.d/${ppa_owner}-${ppa_dist}-${ppa_name}-${ppa_codename}.list";
	    return 1 if -r $ppa_list;
	    info "$ppa_list is not yet available";
	    0;
	},
	using => sub {
	    my $d = shift;
	    my $sudo = $doit->do_sudo;
	    $sudo->system('add-apt-repository', "ppa:${ppa_owner}/${ppa_name}");
	    $sudo->system(qw(apt-get update));
	},
    );
}

$doit->deb_install_packages('python3-mapnik');

in_directory {
    $doit->system(qw(make nightly));

    # XXX need to set -d gis
    #$doit->system(qw(make import-postgres));
    $doit->system(qw(osm2pgsql --slim -d gis -S osm2pgsql/bbbike.style -c), "$bbbikedir/tmp/bbbike-mapnik.osm.gz");
} $FindBin::RealBin;

__END__
