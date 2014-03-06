BBBIKEDIR?=		../../../src/bbbike
BBBIKETMPDIR=		$(BBBIKEDIR)/tmp
BBBIKEDATADIR=		$(BBBIKEDIR)/data
BBBIKEMISCSRCDIR=	$(BBBIKEDIR)/miscsrc

all:	bbbike2wgs84-mapnik

nightly:	bbbike2wgs84-mapnik

bbbike2wgs84-mapnik:	$(BBBIKETMPDIR)/bbbike-mapnik.osm.gz

# Mention only the most important files as deps
$(BBBIKETMPDIR)/bbbike-mapnik.osm.gz:	$(BBBIKEDATADIR)/strassen $(BBBIKEDATADIR)/flaechen $(BBBIKEDATADIR)/wasserstrassen \
					$(BBBIKEMISCSRCDIR)/bbd2osm
	$(BBBIKEMISCSRCDIR)/bbd2osm --optimize-for=mapnik-bbbike | gzip > $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz~
	mv -f $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz~ $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz

experimental:
	$(BBBIKEMISCSRCDIR)/bbd2osm --optimize-for=mapnik-bbbike --experiment=cycle-route | gzip > $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz~
	mv -f $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz~ $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz

import-postgres:
	osm2pgsql --slim -S osm2pgsql/bbbike.style -c $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz

# Create symlinks, works also on cvrsnica-wheezy
setup-mapnik-on-mosor:
	test -e ../inc-de/datasource-settings.xml.inc || (cd ../inc-de && ln -s datasource-settings.xml.inc.mosor datasource-settings.xml.inc)
	test -e ../inc-de/fontset-settings.xml.inc    || (cd ../inc-de && ln -s fontset-settings.xml.inc.mosor    fontset-settings.xml.inc)
	test -e ../inc-de/settings.xml.inc            || (cd ../inc-de && ln -s settings.xml.inc.mosor            settings.xml.inc)

######################################################################
# HOW TO
#
# Make sure that mapnik-bbbike is checked out next to bbbike.
#
# Prerequisites on a FreeBSD system
# * a running postgresql server (e.g. version 8.4 or 9.1)
# * installed osm2pgsql (freebsd: converters/osm2pgsql)
# * installed postgis (freebsd: databases/postgis)
# * make yourself a postgres superuser:
#    $ sudo -H -u pgsql createuser $USER
#    Soll die neue Rolle ein Superuser sein? (j/n) j
# * create the gis database
#    $ createdb gis
# * do some postgis stuff
#    $ sudo -H -u pgsql createlang plpgsql gis
#    $ sudo -H -u pgsql psql -d gis -f /usr/local/share/postgis/contrib/postgis-1.5/postgis.sql 
#    $ sudo -H -u pgsql psql -d gis -f /usr/local/share/postgis/contrib/postgis-1.5/spatial_ref_sys.sql
#
# Prerequisites on a Debian/wheezy system
#    $ sudo aptitude install osm2pgsql
#    $ sudo -u postgres createuser $USER
#    $ sudo -u postgres createuser $USER
#    $ createdb -E UTF8 gis
#    $ psql -d gis -f /usr/share/postgresql/9.1/contrib/postgis-1.5/postgis.sql
#    $ psql -d gis -f /usr/share/postgresql/9.1/contrib/postgis-1.5/spatial_ref_sys.sql 
#
# Prerequisites on a Debian/squeeze system
#    $ sudo aptitude install osm2pgsql
#    $ sudo -u postgres createuser $USER
#    $ createdb -E UTF8 gis
#    $ createlang plpgsql gis
#    $ psql -d gis -f /usr/share/postgresql/8.4/contrib/postgis-1.5/postgis.sql
#    $ psql -d gis -f /usr/share/postgresql/8.4/contrib/postgis-1.5/spatial_ref_sys.sql 
#
# Then (all systems): create the configuration files in ../inc-de:
# datasource-settings.xml.inc, fontset-settings.xml.inc, and
# settings.xml.inc. On a Debian/wheezy system, just calling
#    $ make setup-mapnik-on-mosor
# might work. Otherwise create the files manually, e.g. by using
# the *.xml.inc.template files as a template.

# Then (all systems)
#    $ make nightly
#    $ make import-postgres
#
# Finally try out the renderer script (needs ImageMagick for the
# --view option, otherwise write into a file using --outfile).
#
# Standard map, center of Berlin:
#    $ ./renderer.py --view
# Quality map, with dashed lines:
#    $ ./renderer.py --view --mapfile=bbbike-smoothness
# Quality map, with solid lines:
#    $ ./renderer.py --view --mapfile=bbbike-smoothness-solid
# Change bounding box and size of map
#    $ ./renderer.py  --view --bbox=13.823245,53.273525,14.049413,53.353898 --geometry 800x800
#
