<Style name="ferry-routes">
    <Rule>
      &maxscale_zoom7;
      &minscale_zoom10;
<!-- German Style: set stroke from #66f to #7070d2 -->
      <LineSymbolizer stroke="#7070d2" stroke-width="0.4" stroke-dasharray="4,4" />
    </Rule>
    <Rule>
      &maxscale_zoom11;
<!-- German Style: set stroke from #66f to #7070d2 -->
      <LineSymbolizer stroke="#7070d2" stroke-width="0.8" stroke-dasharray="6,6" />
    </Rule>
</Style>

<Style name="ferry-routes-text">
<!-- note: it seems that a dummy, non-empty name is needed, and also the font definitions are required
     specifying no-text="true does not help
     I found also no way to really center the symbol over the line, it is always somewhat above...
  -->
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_images;/ferry_mini.png" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_images;/ferry_klein.png" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_images;/ferry.png" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
    </Rule>
</Style>

<Layer name="ferry-routes" status="on" srs="&osm2pgsql_projection;">
    <StyleName>ferry-routes</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way from &prefix;_line where route='ferry' ) as routes
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="ferry-routes-text" status="on" srs="&osm2pgsql_projection;">
    <StyleName>ferry-routes-text</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way, ' '::text as ref from &prefix;_line where route='ferry' ) as routes
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
