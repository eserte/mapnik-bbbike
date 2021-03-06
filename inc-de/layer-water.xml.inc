<Style name="water_areas">
    <Rule>
      <Filter>[natural] = 'glacier'</Filter>
      &maxscale_zoom6;
      &minscale_zoom7;
      <LineSymbolizer stroke="#9cf" stroke-width="1.5" stroke-dasharray="4,2" />
      <PolygonPatternSymbolizer file="&symbols;/glacier.png" />
    </Rule>
    <Rule>
      <Filter>[natural] = 'glacier'</Filter>
      &maxscale_zoom8;
      <LineSymbolizer stroke="#9cf" stroke-width="1.5" stroke-dasharray="4,2" />
      <PolygonPatternSymbolizer file="&symbols;/glacier2.png" />
    </Rule>
    <Rule>
      <Filter>[waterway] = 'dock' or [waterway] = 'mill_pond' or [waterway]='canal'</Filter>
      &maxscale_zoom9;
      <PolygonSymbolizer fill="#bad5f7" gamma=".75" />
    </Rule>
    <Rule>
      <Filter>[landuse] = 'basin'</Filter>
      &maxscale_zoom7;
      <PolygonSymbolizer fill="#bad5f7" gamma=".75" />
    </Rule>
    <Rule>
      <Filter>[natural] = 'lake' or [natural] = 'water' or [landuse] = 'reservoir' or [waterway] = 'riverbank' or [landuse] = 'water'</Filter>
      &maxscale_zoom6;
      <PolygonSymbolizer fill="#bad5f7" gamma=".75" />
    </Rule>
    <Rule>
      &maxscale_zoom13;
      <Filter>[natural] = 'marsh' or [natural] = 'wetland'</Filter>
      <PolygonPatternSymbolizer file="&symbols;/marsh.png" />
    </Rule>
    <Rule>
      <Filter>[natural] = 'mud'</Filter>
      &maxscale_zoom13;
      <PolygonPatternSymbolizer file="&symbols;/mud.png" />
    </Rule>
    <Rule>
      &maxscale_zoom13;
      <Filter>[natural] = 'scrub'</Filter>
      <PolygonPatternSymbolizer file="&symbols;/scrub.png" />
    </Rule>
    <Rule>
      <Filter>[natural] = 'land'</Filter>
      &maxscale_zoom10;
      <PolygonSymbolizer fill="#f2efe9" />
    </Rule>
</Style>
<Style name="glaciers-text">
    <Rule> 
      <Filter>[way_area] &gt;= 10000000</Filter>
      &maxscale_zoom10;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#99f" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[way_area] &gt;= 5000000 and [way_area] &lt; 10000000</Filter>
      &maxscale_zoom11;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#99f" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[way_area] &lt; 5000000</Filter>
      &maxscale_zoom12;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#99f" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
</Style>
<Style name="water_lines">
    <Rule>
      <Filter>[waterway]='weir'</Filter>
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#aaa" stroke-width="2" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='wadi'</Filter>
      &maxscale_zoom13;
      &minscale_zoom15;
      <LineSymbolizer stroke="#bad5f7" stroke-width="1" stroke-linejoin="round" stroke-linecap="round" stroke-dasharray="4,4" />
    </Rule>
    <Rule>
      <Filter>[waterway]='wadi'</Filter>
      &maxscale_zoom16;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2" stroke-linejoin="round" stroke-linecap="round" stroke-dasharray="4,4" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom12;
      &minscale_zoom12;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom13;
      &minscale_zoom13;
      <LineSymbolizer stroke="#bad5f7" stroke-width="3" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom14;
      &minscale_zoom14;
      <LineSymbolizer stroke="#bad5f7" stroke-width="5" stroke-linejoin="round" stroke-linecap="round" />
    </Rule><Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom16;
      <LineSymbolizer stroke="#bad5f7" stroke-width="6" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom17;
      &minscale_zoom17;
      <LineSymbolizer stroke="#bad5f7" stroke-width="10" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and not [tunnel] = 'yes'</Filter>
      &maxscale_zoom18;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="12" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and not [disused]='yes'</Filter>
      &maxscale_zoom12;
      &minscale_zoom12;
      <LineSymbolizer stroke="#bad5f7" stroke-width="3" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and not [disused]='yes'</Filter>
      &maxscale_zoom13;
      &minscale_zoom13;
      <LineSymbolizer stroke="#bad5f7" stroke-width="4" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="8" fill="#6699cc" halo-radius="1" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <ElseFilter/> <!--[waterway]='stream'</Filter>-->
      &maxscale_zoom13;
      &minscale_zoom14;
      <LineSymbolizer stroke="#bad5f7" stroke-width="1" />
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom14;
      &minscale_zoom14;
      <LineSymbolizer stroke="#bad5f7" stroke-width="6" stroke-dasharray="4,2" />
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#6699cc" halo-radius="1" placement="line" minimum-distance="200">[name]</TextSymbolizer>
    </Rule><Rule>
      <Filter>[waterway]='river' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom16;
      <LineSymbolizer stroke="#bad5f7" stroke-width="7" stroke-dasharray="6,4" />
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#6699cc" halo-radius="1" placement="line" minimum-distance="200">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom17;
      &minscale_zoom17;
      <LineSymbolizer stroke="#bad5f7" stroke-width="11" stroke-dasharray="8,6" />
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#6699cc" halo-radius="1" placement="line" minimum-distance="200">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='river' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="13" stroke-dasharray="12,8" />
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#6699cc" halo-radius="1" placement="line" minimum-distance="200">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom14;
      &minscale_zoom16;
      <LineSymbolizer stroke="#bad5f7" stroke-width="7" stroke-dasharray="4,2" />
      <LineSymbolizer stroke="white" stroke-width="3" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#6699cc" halo-radius="1" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and not ([tunnel] = 'yes' or [disused]='yes')</Filter>
      &maxscale_zoom14;
      &minscale_zoom16;
      <LineSymbolizer stroke="#bad5f7" stroke-width="7" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#6699cc" halo-radius="1" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and [tunnel] = 'yes'</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="11" stroke-dasharray="4,2" />
      <LineSymbolizer stroke="white" stroke-width="7" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#6699cc" halo-radius="1" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and not ([tunnel] = 'yes' or [disused]='yes' or [lock]='yes')</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="11" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#6699cc" halo-radius="1" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='canal' and not ([tunnel] = 'yes' or [disused]='yes') and [lock]='yes'</Filter>
      &maxscale_zoom17;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="7" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#6699cc" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='derelict_canal' or ([waterway]='canal' and [disused]='yes')</Filter>
      &maxscale_zoom12;
      &minscale_zoom12;
      <LineSymbolizer stroke="#bad5f7" stroke-width="1.5" stroke-dasharray="4,4" stroke-opacity="0.5" stroke-linejoin="round" stroke-linecap="round" />
    </Rule>
    <Rule>
      <Filter>[waterway]='derelict_canal' or ([waterway]='canal' and [disused]='yes')</Filter>
      &maxscale_zoom13;
      &minscale_zoom13;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2.5" stroke-dasharray="4,6" stroke-opacity="0.5" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#80d1ae" halo-radius="1" spacing="600" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='derelict_canal' or ([waterway]='canal' and [disused]='yes')</Filter>
      &maxscale_zoom14;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="4.5" stroke-dasharray="4,8" stroke-opacity="0.5" stroke-linejoin="round" stroke-linecap="round" />
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#80d1ae" halo-radius="1" spacing="600" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[waterway]='stream' and [tunnel]='yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2.4" stroke-dasharray="4,2" />
      <LineSymbolizer stroke="#f3f7f7" stroke-width="1.2" />
    </Rule>
    <Rule>
      <Filter>[waterway]='stream' and not [tunnel]='yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2" />
      <TextSymbolizer fontset-name="book-fonts" size="8" fill="#6699cc" halo-radius="1" spacing="600" placement="line">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>([waterway]='drain' or [waterway]='ditch') and [tunnel]='yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2" stroke-dasharray="4,2" />
      <LineSymbolizer stroke="#f3f7f7" stroke-width="1" />
    </Rule>
    <Rule>
      <Filter>([waterway]='drain' or [waterway]='ditch') and not [tunnel]='yes'</Filter>
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="1" />
      <TextSymbolizer fontset-name="book-fonts" size="8" fill="#6699cc" halo-radius="1" spacing="600" placement="line">[name]</TextSymbolizer>
    </Rule>

    <Rule>
      <ElseFilter/> <!--[waterway]='stream'</Filter>-->
      &maxscale_zoom15;
      &minscale_zoom18;
      <LineSymbolizer stroke="#bad5f7" stroke-width="2" />
    </Rule>
</Style>

<Layer name="water_areas" status="on" srs="&osm2pgsql_projection;">
    <StyleName>water_areas</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,"natural",waterway,landuse,name
      from &prefix;_polygon
      where waterway in ('dock','mill_pond','riverbank','canal')
         or landuse in ('reservoir','water','basin')
         or "natural" in ('lake','water','land','marsh','scrub','wetland','glacier','mud')
      order by z_order,way_area desc
      ) as water_areas</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="glaciers-text" status="on" srs="&osm2pgsql_projection;">
    <StyleName>glaciers-text</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,name,way_area
      from &prefix;_polygon
      where "natural"='glacier'
      order by way_area desc
      ) as glaciers</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="water_lines" status="on" srs="&osm2pgsql_projection;">
    <StyleName>water_lines</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,waterway,disused,lock,name,
      case when tunnel in ('yes','true','1') then 'yes'::text else tunnel end as tunnel
      from &prefix;_line
      where waterway in ('weir','river','canal','derelict_canal','stream','drain','ditch','wadi')
        and (bridge is null or bridge not in ('yes','true','1','aqueduct'))
      order by z_order
      ) as water_lines</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
