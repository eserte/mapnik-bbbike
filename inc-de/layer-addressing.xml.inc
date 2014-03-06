<Style name="interpolation">
    <Rule>
      &maxscale_zoom17;
      <LineSymbolizer stroke="#888" stroke-width="1" stroke-dasharray="2,4" />
    </Rule>
</Style>
<Style name="way_numbers">
    <Rule>
      &maxscale_zoom17;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#444" dy="0" wrap-width="0">[addr:housenumber]</TextSymbolizer>
    </Rule>
</Style>
<Style name="node_numbers">
    <Rule>
      &maxscale_zoom17;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#444" dy="0" wrap-width="0">[addr:housenumber]</TextSymbolizer>
    </Rule>
</Style>

<Layer name="interpolation_lines" status="on" srs="&osm2pgsql_projection;">
     <StyleName>interpolation</StyleName>
     <Datasource>
      <Parameter name="table">
       (select way from &prefix;_line where "addr:interpolation" is not null) as interpolation
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="housenumb_ways" status="on" srs="&osm2pgsql_projection;">
    <StyleName>way_numbers</StyleName>
    <Datasource>
      <Parameter name="table">(select way,"addr:housenumber" from &prefix;_polygon where "addr:housenumber" is not null and building is not null) as way_numbers</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="housenumb_nodes" status="on" srs="&osm2pgsql_projection;">
    <StyleName>node_numbers</StyleName>
    <Datasource>
      <Parameter name="table">(select way,"addr:housenumber" from &prefix;_point where "addr:housenumber" is not null) as node_numbers</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
