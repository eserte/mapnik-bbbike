<Style name="stations">

<!-- DISUSED/UNDER CONSTRUCTION SUBWAY STATIONS (U-Bhf) -->
<!-- XXX deactivated because of symbol layering problems
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_subway' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/ubahn_grau_mini.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_subway' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/ubahn_grau_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_subway' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/ubahn_grau.png" allow-overlap="true" />
    </Rule>
-->
<!-- DISUSED/UNDER CONSTRUCTION LIGHT RAIL STATIONS (S-Bhf) -->
<!-- XXX deactivated because of symbol layering problems
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_light_rail' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/sbahn_grau_mini.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_light_rail' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/sbahn_grau_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_light_rail' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&symbols;/sbahn_grau.png" allow-overlap="true" />
    </Rule>
-->

<!-- RAILWAY STATIONS -->
    <Rule>
<!-- German Style: set maxscale_zoom from 12 to 13 -->
      &maxscale_zoom13;
      &minscale_zoom13;
      <Filter>[railway]='station' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_mini.png" allow-overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
<!-- German Style: set minscale_zoom from 14 to 15 -->
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
      &maxscale_zoom14;
      <Filter>[railway]='station' and ([disused]='yes' or not [construction]=null)</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_stillg_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='station' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn.png" allow-overlap="true" />
    </Rule>

<!-- SUBWAY STATIONS (U-Bhf) -->
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_subway' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn_mini.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_subway' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_subway' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn.png" allow-overlap="true" />
    </Rule>

<!-- LIGHT RAIL STATIONS (S-Bhf) -->
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_light_rail' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn_mini.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_light_rail' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn_klein.png" allow-overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_light_rail' and not [disused]='yes' and [construction]=null</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn.png" allow-overlap="true" />
    </Rule>

<!-- MISC -->
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <PointSymbolizer file="&symbols;/halt.png" allow-overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <PointSymbolizer file="&symbols;/station_small.png" allow-overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 14 to 15 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom15;
      &minscale_zoom15;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <TextSymbolizer fontset-name="book-fonts" size="8" fill="#66f" dy="-8" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway] ='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#66f" dy="-10" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 14 to 15 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom15;
      &minscale_zoom15;
      <Filter>([railway]='station' or [railway]='station_subway' or [railway]='station_light_rail') and not [disused]='yes' and [construction]=null</Filter>
      <TextSymbolizer fontset-name="bold-fonts" size="9" fill="#66f" dy="-8" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>([railway]='station' or [railway]='station_subway' or [railway]='station_light_rail') and not [disused]='yes' and [construction]=null</Filter>
      <TextSymbolizer fontset-name="bold-fonts" size="11" fill="#66f" dy="-10" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='station' and ([disused]='yes' or not [construction]=null)</Filter>
      <TextSymbolizer fontset-name="bold-fonts" size="9" fill="grey" dy="-9" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>

</Style>
<Layer name="amenity-stations" status="on" srs="&osm2pgsql_projection;">
    <StyleName>stations</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,name,railway,aerialway,disused,construction
      from &prefix;_point
      where railway in ('station','station_subway','station_light_rail','station_narrow_gauge','halt','tram_stop')
         or aerialway='station'
      ) as stations
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="amenity-stations-poly" status="on" srs="&osm2pgsql_projection;">
    <StyleName>stations</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,name,railway,aerialway,disused,construction
      from &prefix;_polygon
      where railway in ('station','station_subway','station_light_rail','station_narrow_gauge','halt','tram_stop')
         or aerialway='station'
      ) as stations
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>

