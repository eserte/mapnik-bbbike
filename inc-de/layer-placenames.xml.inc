<Style name="continent">
    <Rule>
      <Filter>[place] = 'continent'</Filter>
      &maxscale_zoom1;
      &minscale_zoom2;
<!-- German Style: set fill from #9d6c9d to #3d383d -->
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#3d383d" dy="0" halo-radius="2" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
</Style>
<Style name="country">
    <Rule>
      <Filter>[place] = 'country'</Filter>
      &maxscale_zoom2;
      &minscale_zoom3;
<!-- German Style: set fill from #9d6c9d to #3d383d -->
<!-- German Style: set size from 8 to 9-->
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#3d383d" dy="0" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'country'</Filter>
      &maxscale_zoom4;
      &minscale_zoom5;
      <TextSymbolizer fontset-name="book-fonts" size="11" fill="#3d383d" dy="0" halo-radius="1" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'country'</Filter>
      &maxscale_zoom6;
      &minscale_zoom6;
<!-- German Style: set fill from #9d6c9d to #3d383d -->
<!-- German Style: set size from 10 to 12 -->
<!-- German Style: set halo_fill -->
      <TextSymbolizer fontset-name="book-fonts" size="12" fill="#3d383d" dy="0" halo-radius="2" halo-fill="rgba(255,255,255,0.5)" wrap-width="20">[name]</TextSymbolizer>
    </Rule>
</Style>
<Style name="state">
    <Rule>
      <Filter>[place] = 'state'</Filter>
      &maxscale_zoom4;
      &minscale_zoom4;
<!-- German Style: set fill from #9d6c9d to #375841 -->
      <TextSymbolizer fontset-name="oblique-fonts" size="9" fill="#375841" dy="0" halo-radius="1" wrap-width="0">[ref]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'state'</Filter>
      &maxscale_zoom5;
      &minscale_zoom5;
      <TextSymbolizer fontset-name="oblique-fonts" size="9" fill="#629471" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'state'</Filter>
      &maxscale_zoom6;
      &minscale_zoom6;
<!-- German Style: set fill from #9d6c9d to #538562 -->
      <TextSymbolizer fontset-name="oblique-fonts" size="9" fill="#538562" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'state'</Filter>
      &maxscale_zoom7;
      &minscale_zoom8;
<!-- German Style: set fill from #9d6c9d to #629b74 -->
<!-- German Style: set halo_fill -->
      <TextSymbolizer fontset-name="oblique-fonts" size="11" fill="#629b74" dy="0" halo-radius="2" halo-fill="rgba(255,255,255,0.5)" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
</Style>
<Style name="capital">
     <Rule>
      &maxscale_zoom5;
      &minscale_zoom5;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom6;
      &minscale_zoom8;
      <TextSymbolizer fontset-name="book-fonts" size="11" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom9;
      &minscale_zoom10;
      <TextSymbolizer fontset-name="book-fonts" size="11" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      &maxscale_zoom11;
      &minscale_zoom14;
      <TextSymbolizer fontset-name="book-fonts" size="14" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
</Style>
<!-- German Style: set city1 -->
<Style name="city1">
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
      &maxscale_zoom6;
      &minscale_zoom6;
<!-- German Style: set size from 8 to 9 -->
<!-- German Style: set allow-overlap="false" and minimum-distance="2" -->
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#000" dy="0" halo-radius="1" wrap-width="0" allow-overlap="false" minimum-distance="2">[name]</TextSymbolizer>
    </Rule>
</Style>
<Style name="city2">
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
<!-- German Style: set zoom level 7 -->
      &maxscale_zoom7;
      &minscale_zoom7;
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
<!-- German Style: set zoom level 8 -->
      &maxscale_zoom8;
      &minscale_zoom8;
      <TextSymbolizer fontset-name="book-fonts" size="11" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
<!-- German Style: set zoom level 9 -->
      &maxscale_zoom9;
      &minscale_zoom9;
      <TextSymbolizer fontset-name="book-fonts" size="14" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
      &maxscale_zoom10;
      &minscale_zoom10;
<!-- German Style: set size from 8 to 15-->
      <TextSymbolizer fontset-name="book-fonts" size="15" fill="#000" dy="0" halo-radius="2" halo-fill="rgba(255,255,255,0.25)" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
      &maxscale_zoom11;
      &minscale_zoom11;
<!-- German Style: set size from 10 to 16-->
      <TextSymbolizer fontset-name="book-fonts" size="16" fill="#000" dy="0" halo-radius="2" halo-fill="rgba(255,255,255,0.25)" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'city' or [place]='metropolis'</Filter>
      &maxscale_zoom11;
      &minscale_zoom14;
      <TextSymbolizer fontset-name="book-fonts" size="16" fill="#000" dy="0" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
</Style>
<!-- German Style: set new style "town" -->
<Style name="town">
 <Rule>
    <Filter>[place] = 'town' or [place]='large_town'</Filter>
    &maxscale_zoom9;
    &minscale_zoom9;
    <TextSymbolizer fontset-name="book-fonts" size="8" fill="#000" halo-radius="1" wrap-width="0" minimum-distance="6">[name]</TextSymbolizer>
  </Rule>
  <Rule>
    <Filter>[place] = 'town' or [place]='large_town'</Filter>
    &maxscale_zoom10;
    &minscale_zoom10;
    <TextSymbolizer fontset-name="book-fonts" size="9" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
  </Rule>
  <Rule>
    <Filter>[place] = 'town' or [place]='large_town'</Filter>
    &maxscale_zoom11;
    &minscale_zoom13;
    <TextSymbolizer fontset-name="book-fonts" size="10" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
  </Rule>
  <Rule>
    <Filter>[place] = 'town' or [place]='large_town'</Filter>
    &maxscale_zoom14;
    <TextSymbolizer fontset-name="book-fonts" size="14" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
  </Rule>
</Style>
<Style name="town2">
  <Rule>
    <Filter>[place] = 'small_town'</Filter>
    &maxscale_zoom11;
    &minscale_zoom12;
    <TextSymbolizer fontset-name="book-fonts" size="9" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
  </Rule>
  <Rule>
    <Filter>[place] = 'small_town'</Filter>
    &maxscale_zoom13;
    &minscale_zoom15;
    <TextSymbolizer fontset-name="book-fonts" size="10" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
  </Rule>
</Style>
<Style name="suburb">
    <Rule>
      <Filter>[place] = 'suburb'</Filter>
      &maxscale_zoom12;
      &minscale_zoom13;
      <TextSymbolizer fontset-name="book-fonts" size="10" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
    </Rule>
    <Rule>
      <Filter>[place] = 'suburb'</Filter>
      &maxscale_zoom14;
      <TextSymbolizer fontset-name="book-fonts" size="13" fill="#777777" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
      <PointSymbolizer file="&symbols;/city.png" />
    </Rule>
</Style>
<Style name="village">
    <Rule>
      <Filter>[place] = 'village' or [place]='large_village'</Filter>
      &maxscale_zoom12;
      &minscale_zoom14;
      <TextSymbolizer fontset-name="book-fonts" size="9" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
      <PointSymbolizer file="&symbols;/city.png" />
    </Rule>
    <Rule>
      <Filter>[place] = 'village' or [place]='large_village'</Filter>
      &maxscale_zoom15;
      <TextSymbolizer fontset-name="book-fonts" size="12" fill="#777777" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
      <PointSymbolizer file="&symbols;/city.png" />
    </Rule>
</Style>
<Style name="hamlet">
    <Rule>
      <Filter>[place] = 'hamlet' or [place] = 'locality' or [place] = 'isolated_dwelling'</Filter>
      &maxscale_zoom14;
      &minscale_zoom15;
      <TextSymbolizer fontset-name="book-fonts" size="8" fill="#000" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
      <PointSymbolizer file="&symbols;/city.png" />
    </Rule>
    <Rule>
      <Filter>[place] = 'hamlet' or [place] = 'locality' or [place] = 'isolated_dwelling'</Filter>
      &maxscale_zoom16;
      <TextSymbolizer fontset-name="book-fonts" size="11" fill="#777777" halo-radius="1" wrap-width="0">[name]</TextSymbolizer>
      <PointSymbolizer file="&symbols;/city.png" />
    </Rule>
</Style>

<Layer name="placenames-large" status="on" srs="&osm2pgsql_projection;">
    <StyleName>continent</StyleName>
    <StyleName>country</StyleName>
    <StyleName>state</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,place,name,ref
       from &prefix;_point
       where place in ('country','state','continent')

      ) as placenames</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="placenames-capital" status="on" srs="&osm2pgsql_projection;">
    <StyleName>capital</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,place,name,ref
       from &prefix;_point
       where place in ('city','metropolis','town') and capital='yes'
      ) as placenames</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="placenames-medium" status="on" srs="&osm2pgsql_projection;">
    <StyleName>city1</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,place,name
      from &prefix;_point
      where place in ('city','metropolis')
      and (capital is null or capital&lt;&gt;'yes')
      ) as placenames</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="placenames-medium" status="on" srs="&osm2pgsql_projection;">
    <StyleName>city2</StyleName>
    <StyleName>town</StyleName>
    <StyleName>town2</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,place,name
      from &prefix;_point
      where place in ('city','metropolis','town','large_town','small_town')
        and (capital is null or capital&lt;&gt;'yes')
      ) as placenames</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="placenames-small" status="on" srs="&osm2pgsql_projection;">
    <StyleName>suburb</StyleName>
    <StyleName>village</StyleName>
    <StyleName>hamlet</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,place,name
      from &prefix;_point
      where place in ('suburb','village','large_village','hamlet','locality','isolated_dwelling')
      ) as placenames</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
