#!/usr/bin/env python

# The projection stuff taken from
# http://svn.openstreetmap.org/applications/rendering/mapnik/generate_image.py

try:
    import mapnik
except:
    import mapnik2 as mapnik

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
parser.add_argument('--geometry', default="1024x768",
                    help='size of image in the form widthxheight (default: 1024x768)')
parser.add_argument('--bbox', default="13.338273,52.535687,13.451261,52.499058",
                    help='coordinates of the visible map in the form minlon,minlat,maxlon,maxlat (default: center of Berlin)')
args = parser.parse_args()

mapfile = rootdir + '/' + args.mapfile + '.xml'

[w,h] = args.geometry.split('x')
w = int(w)
h = int(h)
m = mapnik.Map(w,h)

if args.bbox == None:
    args.bbox = "13.338273,52.535687,13.451261,52.499058"
bounds = map(lambda x: float(x), args.bbox.split(','))

merc = mapnik.Projection('+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs +over')
longlat = mapnik.Projection('+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs')

mapnik.load_map(m, mapfile)

# ensure the target map projection is mercator
m.srs = merc.params()

if hasattr(mapnik,'Box2d'):
    bbox = mapnik.Box2d(*bounds)
else:
    bbox = mapnik.Envelope(*bounds)

# Our bounds above are in long/lat, but our map
# is in spherical mercator, so we need to transform
# the bounding box to mercator to properly position
# the Map when we call `zoom_to_box()`
transform = mapnik.ProjTransform(longlat,merc)
merc_bbox = transform.forward(bbox)

# Mapnik internally will fix the aspect ratio of the bounding box
# to match the aspect ratio of the target image width and height
# This behavior is controlled by setting the `m.aspect_fix_mode`
# and defaults to GROW_BBOX, but you can also change it to alter
# the target image size by setting aspect_fix_mode to GROW_CANVAS
#m.aspect_fix_mode = mapnik.GROW_CANVAS
# Note: aspect_fix_mode is only available in Mapnik >= 0.6.0
m.zoom_to_box(merc_bbox)

if args.view:
    import tempfile
    map_output_file = tempfile.NamedTemporaryFile(suffix=".png")
    map_output = map_output_file.name
elif args.outfile == None:
    print "Please specify either --outfile or --view"
    exit(1)
else:
    map_output = args.outfile

print "Scale = " , m.scale()
mapnik.render_to_file(m, map_output)

if args.view:
    import subprocess
    subprocess.call(["display", map_output])
