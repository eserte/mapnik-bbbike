#!/usr/bin/env python

try:
  from mapnik import *
except:
  from mapnik2 import *

import argparse

import os
rootdir = os.path.dirname(os.path.abspath(os.path.dirname(__file__)))

parser = argparse.ArgumentParser(description='Test renderer for mapnik-bbbike style')
parser.add_argument('--mapfile', default="bbbike",
                    help='map file, specify without .xml extension (default: bbbike, other possibilities: bbbike-smoothness, bbbike-smoothness-solid, bbbike-handicap, bbbike-cycleway, bbbike-cycles-routes)')
parser.add_argument('--outfile',
                    help='path of generated png file')
parser.add_argument('--view', action='store_true',
                    help='display file immediately with ImageMagick')
args = parser.parse_args()

mapfile = rootdir + '/' + args.mapfile + '.xml'

m = Map(1024,768)
load_map(m, mapfile)
#bbox=(Envelope( 13.432570,52.504220, 13.458203,52.516270 ))
#bbox=(Envelope( 52.516270,13.432570, 52.504220,13.458203 ))
#bbox=(Envelope( -85,-170,85,170 ))
#bbox=(Envelope(1481888.238355513,6883816.509324187,1495738.040636882,6896019.182691022));
bbox=(Envelope(1486304.184101673,6886729.462978764,1494880.051892038,6893551.420543496));
#bbox=(Envelope(1086304.184101673,6386729.462978764,2094880.051892038,7393551.420543496));
#bbox=(Envelope(486304.184101673,5886729.462978764,2494880.051892038,7893551.420543496));

if args.view:
    import tempfile
    map_output_file = tempfile.NamedTemporaryFile(suffix=".png")
    map_output = map_output_file.name
elif args.outfile == None:
    print "Please specify either --outfile or --view"
    exit(1)
else:
    map_output = args.outfile

m.zoom_to_box(bbox)
print "Scale = " , m.scale()
render_to_file(m, map_output)

if args.view:
    import subprocess
    render_to_file(m, map_output)
    subprocess.call(["display", map_output])
