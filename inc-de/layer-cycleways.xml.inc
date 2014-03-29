<Style name="cycleway">
    <Rule>
      <Filter>[cycleway] = 'track'</Filter>
      &maxscale_zoom1;
      &minscale_zoom12;
      <LineSymbolizer stroke="&color_RW2;" stroke-width="1" />
    </Rule>

    <Rule>
      <Filter>[cycleway] = 'lane'</Filter>
      &maxscale_zoom1;
      &minscale_zoom12;
      <LineSymbolizer stroke="&color_RW4;" stroke-width="1" />
    </Rule>

    <Rule>
      <Filter>[psv] = 'yes'</Filter>
      &maxscale_zoom1;
      &minscale_zoom12;
      <LineSymbolizer stroke="&color_RW5;" stroke-width="1" />
    </Rule>
</Style>

<Layer name="cycleway" status="on" srs="&osm2pgsql_projection;">
    <StyleName>cycleway</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,cycleway,psv
       from &prefix;_line
       where cycleway is not null or psv = 'yes'
       order by z_order) as roads
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
