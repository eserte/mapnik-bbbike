#!/usr/bin/env python

from mapnik import *

import os
rootdir = os.path.dirname(os.path.abspath(os.path.dirname(__file__)))

mapfile = rootdir + '/bbbike.xml'
#mapfile = rootdir + '/bbbike-smoothness.xml'
#mapfile = rootdir + '/bbbike-smoothness-solid.xml'
#mapfile = rootdir + '/bbbike-handicap.xml'
#mapfile = rootdir + '/bbbike-cycleway.xml'
#mapfile = rootdir + '/bbbike-cycle-routes.xml'

map_output = '/tmp/mymap.png'

m = Map(1024,768)
load_map(m, mapfile)
#bbox=(Envelope( 13.432570,52.504220, 13.458203,52.516270 ))
#bbox=(Envelope( 52.516270,13.432570, 52.504220,13.458203 ))
#bbox=(Envelope( -85,-170,85,170 ))
#bbox=(Envelope(1481888.238355513,6883816.509324187,1495738.040636882,6896019.182691022));
bbox=(Envelope(1486304.184101673,6886729.462978764,1494880.051892038,6893551.420543496));
#bbox=(Envelope(1086304.184101673,6386729.462978764,2094880.051892038,7393551.420543496));
#bbox=(Envelope(486304.184101673,5886729.462978764,2494880.051892038,7893551.420543496));

m.zoom_to_box(bbox)
print "Scale = " , m.scale()
render_to_file(m, map_output)

