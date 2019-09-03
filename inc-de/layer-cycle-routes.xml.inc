<Style name="cycle-routes">
    <Rule>
      &maxscale_zoom7;
      &minscale_zoom10;
      <LineSymbolizer stroke="blue" stroke-width="0.4" stroke-dasharray="2,2" stroke-opacity="0.5" />
    </Rule>
    <Rule>
      &maxscale_zoom11;
      <LineSymbolizer stroke="blue" stroke-width="0.8" stroke-dasharray="2,2" stroke-opacity="0.5" />
    </Rule>
</Style>

<Style name="cycle-routes-label">
    <Rule>
      <Filter>[ref]='R1.png'</Filter>
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/R1.png" minimum-distance="30" spacing="750">[empty]</ShieldSymbolizer>
    </Rule>
    <Rule>
      <Filter>[ref]='M.png'</Filter>
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/M.png" minimum-distance="30" spacing="750">[empty]</ShieldSymbolizer>
    </Rule>
    <Rule>
      <Filter>[ref]='SPR.gif'</Filter>
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/SPR-orig.png" minimum-distance="30" spacing="750">[empty]</ShieldSymbolizer>
    </Rule>
    <Rule>
      <Filter>[ref]='BU.gif'</Filter>
      <ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&bbbike_comments_route_images;/BU.gif" minimum-distance="30" spacing="750">[empty]</ShieldSymbolizer>
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
