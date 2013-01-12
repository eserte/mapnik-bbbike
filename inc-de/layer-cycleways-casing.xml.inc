<Style name="cycleway-casing">
  
    <Rule>
<!--      <Filter>[cycleway] = 'track' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'track'</Filter>
      &maxscale_zoom13;
      &minscale_zoom14;
      <LinePatternSymbolizer file="&symbols;/RW2_w8.png" />
    </Rule>
    <Rule>
<!--      <Filter>[cycleway] = 'track' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'track'</Filter>
      &maxscale_zoom15;
      &minscale_zoom16;
      <LinePatternSymbolizer file="&symbols;/RW2_w12.png" />
    </Rule>
    <Rule>
<!--      <Filter>[cycleway] = 'track' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'track'</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LinePatternSymbolizer file="&symbols;/RW2_w16.png" />
    </Rule>

    <Rule>
<!--      <Filter>[cycleway] = 'lane' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'lane'</Filter>
      &maxscale_zoom13;
      &minscale_zoom14;
      <LinePatternSymbolizer file="&symbols;/RW4_w8.png" />
    </Rule>
    <Rule>
<!--      <Filter>[cycleway] = 'lane' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'lane'</Filter>
      &maxscale_zoom15;
      &minscale_zoom16;
      <LinePatternSymbolizer file="&symbols;/RW4_w12.png" />
    </Rule>
    <Rule>
<!--      <Filter>[cycleway] = 'lane' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[cycleway] = 'lane'</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LinePatternSymbolizer file="&symbols;/RW4_w16.png" />
    </Rule>

    <Rule>
<!--      <Filter>[psv] = 'yes' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[psv] = 'yes'</Filter>
      &maxscale_zoom13;
      &minscale_zoom14;
      <LinePatternSymbolizer file="&symbols;/RW5_w8.png" />
    </Rule>
    <Rule>
<!--      <Filter>[psv] = 'yes' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[psv] = 'yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom16;
      <LinePatternSymbolizer file="&symbols;/RW5_w12.png" />
    </Rule>
    <Rule>
<!--      <Filter>[psv] = 'yes' and ([highway] = 'primary' or [highway] = 'secondary')</Filter> -->
      <Filter>[psv] = 'yes'</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LinePatternSymbolizer file="&symbols;/RW5_w16.png" />
    </Rule>

</Style>

<Layer name="cycleway-casing" status="on" srs="&osm2pgsql_projection;">
    <StyleName>cycleway-casing</StyleName>
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
