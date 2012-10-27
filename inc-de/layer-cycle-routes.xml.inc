<Style name="cycle-routes">
    <Rule>
      &maxscale_zoom7;
      &minscale_zoom10;
      <LineSymbolizer>
        <CssParameter name="stroke">blue</CssParameter>
        <CssParameter name="stroke-width">0.4</CssParameter>
        <CssParameter name="stroke-dasharray">2,2</CssParameter>
	<CssParameter name="stroke-opacity">0.5</CssParameter>
      </LineSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom11;
      <LineSymbolizer>
        <CssParameter name="stroke">blue</CssParameter>
        <CssParameter name="stroke-width">0.8</CssParameter>
        <CssParameter name="stroke-dasharray">2,2</CssParameter>
	<CssParameter name="stroke-opacity">0.5</CssParameter>
      </LineSymbolizer>
    </Rule>
</Style>

<Style name="cycle-routes-label">
    <Rule>
      <Filter>[ref]='R1.png'</Filter>
      <ShieldSymbolizer name="empty" fontset_name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/R1.png" min_distance="30" spacing="750"/>
    </Rule>
    <Rule>
      <Filter>[ref]='M.gif'</Filter>
      <ShieldSymbolizer name="empty" fontset_name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/M.png" min_distance="30" spacing="750"/>
    </Rule>
    <Rule>
      <Filter>[ref]='SPR.gif'</Filter>
      <ShieldSymbolizer name="empty" fontset_name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/SPR-orig.png" min_distance="30" spacing="750"/>
    </Rule>
</Style>

<Layer name="cycle-routes" status="on" srs="&osm2pgsql_projection;">
    <StyleName>cycle-routes</StyleName>
    <StyleName>cycle-routes-label</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,ref,' '::text as empty from &prefix;_line where route='bicycle' ) as routes
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
