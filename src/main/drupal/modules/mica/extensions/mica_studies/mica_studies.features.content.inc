<?php
/**
 * @file
 * mica_studies.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function mica_studies_content_defaults() {
  $content = array();

  $content['about'] = (object) array(
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/about',
      'router_path' => 'node/%',
      'link_title' => 'About',
      'options' => array(
        'langcode' => 'en',
      ),
      'module' => 'menu',
      'hidden' => '0',
      'external' => '0',
      'has_children' => '0',
      'expanded' => '1',
      'weight' => '-44',
      'identifier' => 'main-menu:node-name/about',
    ),
    'exported_path' => 'content/about-mica',
    'title' => 'About Mica',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794278',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'about',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>Welcome to Mica, a powerful software application used to create web portals for epidemiological study consortia.</p>
      <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (www.obiba.org).</p>
      <p>Mica is based on the content management software Drupal (www.drupal.org) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
      <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
      ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>Welcome to Mica, a powerful software application used to create web portals for epidemiological study consortia.</p>
  <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (<a href="http://www.obiba.org">www.obiba.org</a>).</p>
  <p>Mica is based on the content management software Drupal (<a href="http://www.drupal.org">www.drupal.org</a>) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
  <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
  ',
          'safe_summary' => '',
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => '<p>Bienvenue sur Mica, une application permettant aux consortiums d&#39;&eacute;tudes &eacute;pid&eacute;miologiques de cr&eacute;er leur propre portails.</p>
            <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (www.obiba.org).</p>
            <p>Mica is based on the content management software Drupal (www.drupal.org) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
            <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
            ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>Bienvenue sur Mica, une application permettant aux consortiums d\'études épidémiologiques de créer leur propre portails.</p>
  <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (<a href="http://www.obiba.org">www.obiba.org</a>).</p>
  <p>Mica is based on the content management software Drupal (<a href="http://www.drupal.org">www.drupal.org</a>) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
  <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
  ',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['mica'] = (object) array(
    'exported_path' => 'content/mica',
    'title' => 'Mica',
    'status' => '1',
    'promote' => '0',
    'sticky' => '1',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794278',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'mica',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>Welcome to Mica, a powerful software application used to create web portals for epidemiological study consortia.</p>
      <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (www.obiba.org).</p>
      <p>Mica is based on the content management software Drupal (www.drupal.org) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
      <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
      ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>Welcome to Mica, a powerful software application used to create web portals for epidemiological study consortia.</p>
  <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (<a href="http://www.obiba.org">www.obiba.org</a>).</p>
  <p>Mica is based on the content management software Drupal (<a href="http://www.drupal.org">www.drupal.org</a>) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
  <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
  ',
          'safe_summary' => '',
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => '<p>&nbsp;</p>
            <div>
            	<p>Bienvenue sur Mica, une application permettant aux consortiums d&#39;&eacute;tudes &eacute;pid&eacute;miologiques de cr&eacute;er leur propre portails.</p>
            	<p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (www.obiba.org).</p>
            	<p>Mica is based on the content management software Drupal (www.drupal.org) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
            	<p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
            </div>
            <p>&nbsp;</p>
            ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p> </p>
  <div>
  <p>Bienvenue sur Mica, une application permettant aux consortiums d\'études épidémiologiques de créer leur propre portails.</p>
  <p>Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (<a href="http://www.obiba.org">www.obiba.org</a>).</p>
  <p>Mica is based on the content management software Drupal (<a href="http://www.drupal.org">www.drupal.org</a>) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.</p>
  <p>Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.</p>
  </div>
  <p> </p>
  ',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['research'] = (object) array(
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/research',
      'router_path' => 'node/%',
      'link_title' => 'Research',
      'options' => array(
        'attributes' => array(),
      ),
      'module' => 'menu',
      'hidden' => '0',
      'external' => '0',
      'has_children' => '1',
      'expanded' => '1',
      'weight' => '-46',
      'identifier' => 'main-menu:node-name/research',
    ),
    'exported_path' => 'content/research',
    'title' => 'Research',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794227',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'research',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>This section...</p>',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>This section...</p>',
          'safe_summary' => '',
        ),
        'fr' => array(
          0 => array(
            'value' => '<p>Cette section permet de pr&eacute;senter les activit&eacute;s de recherches qui sont g&eacute;n&eacute;r&eacute;es par le consortium</p>',
            'summary' => '',
            'format' => 'full_html',
            'safe_value' => '<p>Cette section permet de présenter les activités de recherches qui sont générées par le consortium</p>',
            'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['resources'] = (object) array(
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/resources',
      'router_path' => 'node/%',
      'link_title' => 'Resources',
      'options' => array(
        'attributes' => array(),
        'langcode' => 'en',
      ),
      'module' => 'menu',
      'hidden' => '0',
      'external' => '0',
      'has_children' => '1',
      'expanded' => '1',
      'weight' => '-48',
      'identifier' => 'main-menu:node-name/resources',
    ),
    'exported_path' => 'content/resources',
    'title' => 'Resources',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794227',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'resources',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>This page aims to display the consortium resources offered to the scientific community. Two kinds of resource are currently offered with the Mica default configuration: the <a href="?q=datasets">consortium datasets</a> and the <a href="?q=documents">consortium documents</a>.</p>
      ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>This page aims to display the consortium resources offered to the scientific community. Two kinds of resource are currently offered with the Mica default configuration: the <a href="?q=datasets">consortium datasets</a> and the <a href="?q=documents">consortium documents</a>.</p>
  ',
          'safe_summary' => '',
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => '<p>Cette page a pour but de pr&eacute;senter les ressources du consortium qui sont offertes &agrave; la communaut&eacute; scientifique. Deux types de ressources sont pr&eacute;sentement offertes avec l&#39;installation par d&eacute;faut de Mica: les&nbsp;<a href="?q=datasets">consortium datasets</a> et les&nbsp;<a href="?q=documents">consortium documents</a>.</p>
            ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>Cette page a pour but de présenter les ressources du consortium qui sont offertes à la communauté scientifique. Deux types de ressources sont présentement offertes avec l\'installation par défaut de Mica: les <a href="?q=datasets">consortium datasets</a> et les <a href="?q=documents">consortium documents</a>.</p>
  ',
          'safe_summary' => '',
        ),
      ),
    ),
  );

return $content;
}
