<Style name="citywalls">
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom14;
      <LineSymbolizer stroke="grey" stroke-width="4" stroke-opacity="0.8" stroke-linejoin="round" />
    </Rule>
    <Rule>
      &maxscale_zoom15;
      &minscale_zoom15;
      <LineSymbolizer stroke="grey" stroke-width="6" stroke-opacity="0.8" stroke-linejoin="round" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      &minscale_zoom18;
      <LineSymbolizer stroke="grey" stroke-width="9" stroke-opacity="0.8" stroke-linejoin="round" />
    </Rule>
</Style>

<Layer name="citywalls" status="on" srs="&osm2pgsql_projection;">
    <StyleName>citywalls</StyleName>
    <Datasource>
      <Parameter name="table">(select way from &prefix;_line where "historic"='citywalls') as citywalls</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>

