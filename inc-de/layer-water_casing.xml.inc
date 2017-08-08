<Style name="water_areas_casing">
    <Rule>
      <Filter>[natural] = 'lake' or [natural] = 'water' or [landuse] = 'reservoir' or [landuse] = 'water' or [waterway] = 'riverbank'</Filter>
      &maxscale_zoom6;
      <LineSymbolizer stroke="#3d8ff7" stroke-width="1.5" />
    </Rule>
</Style>

<Layer name="water_areas" status="on" srs="&osm2pgsql_projection;">
    <StyleName>water_areas_casing</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,"natural",waterway,landuse,name
      from &prefix;_polygon
      where waterway in ('riverbank')
         or landuse in ('reservoir','water')
         or "natural" in ('lake','water')
      order by z_order,way_area desc
      ) as water_areas_casing</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
