import os
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class TestMapnikRendering(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.work_dir = tempfile.mkdtemp(prefix="mapnik_test_")
        cls.bbbike_dir = os.path.join(cls.work_dir, "bbbike")
        cls.osm_file = os.path.join(cls.work_dir, "bbbike-mapnik.osm")
        cls.db_name = "mapnik_test_db"

        # 1. Clone eserte/bbbike repository if not present
        if not os.path.exists(cls.bbbike_dir):
            subprocess.run(
                ["git", "clone", "--depth", "1", "https://github.com/eserte/bbbike.git", cls.bbbike_dir],
                check=True,
            )

        # 2. Generate OSM file using bbd2osm
        bbd2osm_script = os.path.join(cls.bbbike_dir, "miscsrc", "bbd2osm")
        bbbike_data_dir = os.path.join(cls.bbbike_dir, "data")

        with open(cls.osm_file, "w") as f:
            subprocess.run(
                [bbd2osm_script, "--optimize-for=mapnik-bbbike", bbbike_data_dir],
                stdout=f,
                check=True,
            )

        # 3. Setup Postgres / PostGIS DB
        # Ensure postgres service is running
        subprocess.run(["sudo", "service", "postgresql", "start"], check=False)

        # Drop DB if exists and create fresh
        subprocess.run(["dropdb", "--if-exists", cls.db_name], check=False)
        subprocess.run(["createdb", "-E", "UTF8", cls.db_name], check=True)

        subprocess.run(
            ["psql", "-d", cls.db_name, "-c", "CREATE EXTENSION IF NOT EXISTS postgis;"],
            check=True,
        )

        # 4. Import data using osm2pgsql
        style_file = os.path.join(ROOT_DIR, "tools", "osm2pgsql", "bbbike.style")
        subprocess.run(
            ["osm2pgsql", "--slim", "-S", style_file, "-d", cls.db_name, "-c", cls.osm_file],
            check=True,
        )

        # 5. Create include configuration files in inc-de/
        inc_de_dir = os.path.join(ROOT_DIR, "inc-de")
        datasource_inc = os.path.join(inc_de_dir, "datasource-settings.xml.inc")
        fontset_inc = os.path.join(inc_de_dir, "fontset-settings.xml.inc")
        settings_inc = os.path.join(inc_de_dir, "settings.xml.inc")

        images_dir = os.path.join(cls.bbbike_dir, "images")
        comments_dir = os.path.join(cls.bbbike_dir, "data", "comments_route_img")

        with open(datasource_inc, "w") as f:
            f.write(f"""<Parameter name="type">postgis</Parameter>
<Parameter name="password"></Parameter>
<Parameter name="host"></Parameter>
<Parameter name="port"></Parameter>
<Parameter name="user"></Parameter>
<Parameter name="dbname">{cls.db_name}</Parameter>
<Parameter name="estimate_extent">false</Parameter>
<Parameter name="extent">-20037508.34 -20037508.34 20037508.34 20037508.34</Parameter>
""")

        with open(fontset_inc, "w") as f:
            f.write("""<FontSet name="book-fonts">
  <Font face-name="DejaVu Sans Book" />
</FontSet>
<FontSet name="bold-fonts">
  <Font face-name="DejaVu Sans Bold" />
</FontSet>
<FontSet name="oblique-fonts">
  <Font face-name="DejaVu Sans Oblique" />
</FontSet>
""")

        with open(settings_inc, "w") as f:
            f.write(f"""<!ENTITY symbols "symbols">
<!ENTITY osm2pgsql_projection "&srs900913;">
<!ENTITY dwithin_900913 "0.1">
<!ENTITY dwithin_4326 "0.00001">
<!ENTITY dwithin_node_way "&dwithin_900913;">
<!ENTITY world_boundaries "world_boundaries">
<!ENTITY prefix "planet_osm">
<!ENTITY bbbike_images "{images_dir}">
<!ENTITY bbbike_comments_route_images "{comments_dir}">
""")

    @classmethod
    def tearDownClass(cls):
        subprocess.run(["dropdb", "--if-exists", cls.db_name], check=False)

        # Remove generated inc-de configuration files
        inc_de_dir = os.path.join(ROOT_DIR, "inc-de")
        for inc_file in ["datasource-settings.xml.inc", "fontset-settings.xml.inc", "settings.xml.inc"]:
            path = os.path.join(inc_de_dir, inc_file)
            if os.path.exists(path):
                os.remove(path)

        if os.path.exists(cls.work_dir):
            shutil.rmtree(cls.work_dir, ignore_errors=True)

    def test_render_maps(self):
        mapfiles = [
            "bbbike",
            "bbbike-smoothness",
            "bbbike-smoothness-solid",
            "bbbike-handicap",
            "bbbike-cycleway",
            "bbbike-cycle-routes",
            "bbbike-green",
            "bbbike-unknown",
            "bbbike-unlit",
        ]

        renderer_script = os.path.join(ROOT_DIR, "tools", "renderer.py")

        for mapfile in mapfiles:
            with self.subTest(mapfile=mapfile):
                outfile = os.path.join(self.work_dir, f"{mapfile}.png")
                res = subprocess.run(
                    [sys.executable, renderer_script, "--mapfile", mapfile, "--outfile", outfile],
                    capture_output=True,
                    text=True,
                )
                self.assertEqual(res.returncode, 0, f"Renderer failed for {mapfile}:\nSTDOUT: {res.stdout}\nSTDERR: {res.stderr}")
                self.assertTrue(os.path.exists(outfile), f"Output file missing: {outfile}")
                self.assertGreater(os.path.getsize(outfile), 1000, f"Output file too small or empty: {outfile}")


if __name__ == "__main__":
    unittest.main()
