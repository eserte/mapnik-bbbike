<Style name="buildings">
    <Rule>
      <Filter>[railway] = 'station' or [building] = 'station'</Filter>
      &maxscale_zoom10;
     <PolygonSymbolizer fill="#d4aaaa" />
    </Rule>
    <Rule>
      <Filter>[building] = 'supermarket'</Filter>
      &maxscale_zoom10;
      <PolygonSymbolizer fill="pink" fill-opacity="0.5" />
    </Rule>
    <Rule>
      <Filter>[amenity] = 'place_of_worship'</Filter>
      &maxscale_zoom10;
      &minscale_zoom14;
      <PolygonSymbolizer fill="#777" fill-opacity="0.5" />
    </Rule>
    <Rule>
      <Filter>[amenity] = 'place_of_worship'</Filter>
      &maxscale_zoom15;
      <PolygonSymbolizer fill="#777" fill-opacity="0.5" />
      <LineSymbolizer stroke="#111" stroke-width="0.3" />
    </Rule>
    <Rule>
      <Filter>[building] &lt;&gt; 'station' and [building] &lt;&gt; 'supermarket' and [building] &lt;&gt; '' and (not [amenity] &lt;&gt; '' or [amenity] &lt;&gt; 'place_of_worship')</Filter>
      &maxscale_zoom10;
      <PolygonSymbolizer fill="#bca9a9" />
    </Rule>
    <Rule>
      <Filter>[aeroway] = 'terminal'</Filter>
      &maxscale_zoom12;
      <PolygonSymbolizer fill="#cc99ff" />
    </Rule>
    <Rule>
      <Filter>[aeroway] = 'terminal'</Filter>
      &maxscale_zoom14;
      <LineSymbolizer stroke="#330066" stroke-width="0.2" />
    </Rule>
</Style>

<Layer name="buildings" status="on" srs="&osm2pgsql_projection;">
    <StyleName>buildings</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,building,leisure,railway,amenity,aeroway from &prefix;_polygon
       where (building is not null and building != 'no')
          or railway='station'
          or amenity='place_of_worship'
          or aeroway='terminal'
       order by z_order,way_area desc) as buildings
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>

