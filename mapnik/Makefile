BBBIKEDIR=		$(HOME)/src/bbbike
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

import-postgres:
	osm2pgsql --slim -S /usr/share/osm2pgsql/osm2pgsql/default.style -c $(BBBIKETMPDIR)/bbbike-mapnik.osm.gz
