<?php
/**
 * @file
 * mica_datasets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_datasets_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dataschemas';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'node';
  $view->human_name = 'Dataschemas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dataschemas';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_dataschema' => 'field_dataschema',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_dataschema' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'A DataSchema identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting. 
It also contains associated support material including variable definitions, links to relevant Ontologies and Classifications, and access to reference questionnaires and operating procedures.<br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataschemas';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No dataschema found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Filter criterion: Content: Type (field_dataset_type) */
  $handler->display->display_options['filters']['field_dataset_type_value']['id'] = 'field_dataset_type_value';
  $handler->display->display_options['filters']['field_dataset_type_value']['table'] = 'field_data_field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type_value']['field'] = 'field_dataset_type_value';
  $handler->display->display_options['filters']['field_dataset_type_value']['value'] = array(
    'dataschema' => 'dataschema',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataschemas';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'datasets.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['dataschemas'] = array(
    t('Master'),
    t('Dataschemas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('A DataSchema identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting. 
It also contains associated support material including variable definitions, links to relevant Ontologies and Classifications, and access to reference questionnaires and operating procedures.<br/><br/>'),
    t('empty_dataschemas'),
    t('No dataschema found.'),
    t('Name'),
    t('Description'),
    t('Page'),
    t('Feed'),
  );
  $export['dataschemas'] = $view;

  $view = new view;
  $view->name = 'dataset_csv_export';
  $view->description = 'Export of all Dataset in CSV';
  $view->tag = 'csv';
  $view->base_table = 'node';
  $view->human_name = 'Dataset CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_dataset_type']['id'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['table'] = 'field_data_field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['field'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['label'] = 'dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset_type']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'dataset-csv';
  $translatables['dataset_csv_export'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('title'),
    t('dataset_type'),
    t('body'),
    t('published'),
    t('[status]'),
    t('Data export'),
  );
  $export['dataset_csv_export'] = $view;

  $view = new view;
  $view->name = 'dataset_studies';
  $view->description = '';
  $view->tag = 'study, dataset';
  $view->base_table = 'node';
  $view->human_name = 'Dataset Studies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_design_other_sp' => 'field_design_other_sp',
    'field_design' => 'field_design',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_design_other_sp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_design' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_number_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataset_studies';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No studies found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Please specify what other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['field_api_classes'] = 0;
  /* Field: Content: What is the study design? */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['label'] = 'Study design';
  $handler->display->display_options['fields']['field_design']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp] ';
  $handler->display->display_options['fields']['field_design']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_design']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_design']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_design']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_design']['field_api_classes'] = 0;
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'Target number of participants';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: Country of residence */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_country']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_country']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_country']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_country']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Datasets (mica_dataset) */
  $handler->display->display_options['arguments']['mica_dataset_nid']['id'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['table'] = 'field_data_mica_dataset';
  $handler->display->display_options['arguments']['mica_dataset_nid']['field'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['mica_dataset_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['mica_dataset_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['dataset_studies'] = array(
    t('Master'),
    t('Studies'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_dataset_studies'),
    t('No studies found.'),
    t('Name'),
    t('Please specify what other design'),
    t('([field_design_other_sp])'),
    t('Study design'),
    t('[field_design] [field_design_other_sp] '),
    t('Target number of participants'),
    t('Country of residence'),
    t('All'),
    t('Block'),
  );
  $export['dataset_studies'] = $view;

  $view = new view;
  $view->name = 'dataset_variables';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'search_api_index_variable_index';
  $view->human_name = 'Dataset Variables';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dataset Variables';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_label' => 'field_label',
    'field_value_type' => 'field_value_type',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_value_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Field: Indexed Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
  /* Contextual filter: Dataset: Node ID (indexed) */
  $handler->display->display_options['arguments']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['arguments']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['format'] = 'default_summary';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['dataset_variables'] = array(
    t('Master'),
    t('Dataset Variables'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Name'),
    t('Label'),
    t('Value Type'),
    t('All'),
    t('Block'),
  );
  $export['dataset_variables'] = $view;

  $view = new view;
  $view->name = 'datasets';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'node';
  $view->human_name = 'Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Datasets';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_dataschema' => 'field_dataschema',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_dataschema' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'The consortium makes available different datasets to the research community. Each dataset is described by a comprehensive data dictionary which gives details on each available variable. Moreover, Mica includes for  studies using the OBiBa Opal software as main database solution, a distributed query engine that enables researchers to obtain real-time aggregated reports on the exact number of participant with specific characteristics or phenotypes. Mica makes even possible to run remotely some regression analyses on the real study data using the DataSHIELD method (Wolfson M et al. <i>Int J Epidemiol</i>. 2010) which is implemented both in Mica and Opal. <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_datasets';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No dataset found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Filter criterion: Content: Type (field_dataset_type) */
  $handler->display->display_options['filters']['field_dataset_type_value']['id'] = 'field_dataset_type_value';
  $handler->display->display_options['filters']['field_dataset_type_value']['table'] = 'field_data_field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type_value']['field'] = 'field_dataset_type_value';
  $handler->display->display_options['filters']['field_dataset_type_value']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'datasets';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'datasets.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['datasets'] = array(
    t('Master'),
    t('Datasets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('The consortium makes available different datasets to the research community. Each dataset is described by a comprehensive data dictionary which gives details on each available variable. Moreover, Mica includes for  studies using the OBiBa Opal software as main database solution, a distributed query engine that enables researchers to obtain real-time aggregated reports on the exact number of participant with specific characteristics or phenotypes. Mica makes even possible to run remotely some regression analyses on the real study data using the DataSHIELD method (Wolfson M et al. <i>Int J Epidemiol</i>. 2010) which is implemented both in Mica and Opal. <br/><br/>'),
    t('empty_datasets'),
    t('No dataset found.'),
    t('Name'),
    t('Description'),
    t('Page'),
    t('Feed'),
  );
  $export['datasets'] = $view;

  $view = new view;
  $view->name = 'variable_csv_export';
  $view->description = 'Export of all Variables in CSV';
  $view->tag = 'csv';
  $view->base_table = 'node';
  $view->human_name = 'Variable CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'field_data_field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['label'] = 'anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_anthropometric_structures']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_anthropometric_structures']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['separator'] = '|';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'body';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body_1']['field_api_classes'] = 0;
  /* Field: Content: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'field_data_field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['label'] = 'body_functions';
  $handler->display->display_options['fields']['field_body_functions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_body_functions']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_body_functions']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['separator'] = '|';
  $handler->display->display_options['fields']['field_body_functions']['field_api_classes'] = 0;
  /* Field: Content: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'field_data_field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['label'] = 'body_structures';
  $handler->display->display_options['fields']['field_body_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_body_structures']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_body_structures']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['separator'] = '|';
  $handler->display->display_options['fields']['field_body_structures']['field_api_classes'] = 0;
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_class']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_class']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_class']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_class']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_class']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_class']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_class']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_class']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_class']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_class']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_class']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_class']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_class']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_class']['separator'] = '|';
  $handler->display->display_options['fields']['field_class']['field_api_classes'] = 0;
  /* Field: Content: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'field_data_field_data_source';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['label'] = 'data_source';
  $handler->display->display_options['fields']['field_data_source']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_source']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_source']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_source']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_source']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_source']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_data_source']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_data_source']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_data_source']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_data_source']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_data_source']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_data_source']['separator'] = '|';
  $handler->display->display_options['fields']['field_data_source']['field_api_classes'] = 0;
  /* Field: Content: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['label'] = 'dataset';
  $handler->display->display_options['fields']['field_dataset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_dataset']['field_api_classes'] = 0;
  /* Field: Content: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'field_data_field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['label'] = 'disease_history';
  $handler->display->display_options['fields']['field_disease_history']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_disease_history']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_disease_history']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['separator'] = '|';
  $handler->display->display_options['fields']['field_disease_history']['field_api_classes'] = 0;
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['label'] = 'format';
  $handler->display->display_options['fields']['field_format']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_format']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_format']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_format']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_format']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_format']['field_api_classes'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['label'] = 'label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Field: Content: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'field_data_field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['label'] = 'life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['separator'] = '|';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field_api_classes'] = 0;
  /* Field: Content: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'field_data_field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['label'] = 'medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_medical_health_interv']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_medical_health_interv']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['separator'] = '|';
  $handler->display->display_options['fields']['field_medical_health_interv']['field_api_classes'] = 0;
  /* Field: Content: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'field_data_field_medication';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['label'] = 'medication';
  $handler->display->display_options['fields']['field_medication']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medication']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medication']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medication']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medication']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medication']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medication']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_medication']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_medication']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_medication']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_medication']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_medication']['separator'] = '|';
  $handler->display->display_options['fields']['field_medication']['field_api_classes'] = 0;
  /* Field: Content: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'field_data_field_early_life';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['label'] = 'early_life';
  $handler->display->display_options['fields']['field_early_life']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_early_life']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_early_life']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_early_life']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_early_life']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_early_life']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_early_life']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_early_life']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_early_life']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_early_life']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_early_life']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_early_life']['separator'] = '|';
  $handler->display->display_options['fields']['field_early_life']['field_api_classes'] = 0;
  /* Field: Content: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'field_data_field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['label'] = 'perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_perception_of_health']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_perception_of_health']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['separator'] = '|';
  $handler->display->display_options['fields']['field_perception_of_health']['field_api_classes'] = 0;
  /* Field: Content: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = 'period';
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_period']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_period']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_period']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_period']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_period']['field_api_classes'] = 0;
  /* Field: Content: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'field_data_field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['label'] = 'physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_physical_environment']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_physical_environment']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['separator'] = '|';
  $handler->display->display_options['fields']['field_physical_environment']['field_api_classes'] = 0;
  /* Field: Content: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'field_data_field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['label'] = 'repeatable';
  $handler->display->display_options['fields']['field_repeatable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['field_api_classes'] = 0;
  /* Field: Content: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'field_data_field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['label'] = 'reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_reproductive_history']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_reproductive_history']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['separator'] = '|';
  $handler->display->display_options['fields']['field_reproductive_history']['field_api_classes'] = 0;
  /* Field: Content: Response Unit */
  $handler->display->display_options['fields']['field_response_unit']['id'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['table'] = 'field_data_field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['field'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['label'] = 'response_unit';
  $handler->display->display_options['fields']['field_response_unit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_response_unit']['field_api_classes'] = 0;
  /* Field: Content: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'field_data_field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['label'] = 'social_environment';
  $handler->display->display_options['fields']['field_social_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_social_environment']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_social_environment']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['separator'] = '|';
  $handler->display->display_options['fields']['field_social_environment']['field_api_classes'] = 0;
  /* Field: Content: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'field_data_field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['label'] = 'sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['separator'] = '|';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field_api_classes'] = 0;
  /* Field: Content: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'field_data_field_target';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['label'] = 'target';
  $handler->display->display_options['fields']['field_target']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_target']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_target']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_target']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_target']['separator'] = '|';
  $handler->display->display_options['fields']['field_target']['field_api_classes'] = 0;
  /* Field: Content: Target Gender */
  $handler->display->display_options['fields']['field_target_gender']['id'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['table'] = 'field_data_field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['field'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['label'] = 'target_gender';
  $handler->display->display_options['fields']['field_target_gender']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target_gender']['field_api_classes'] = 0;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['label'] = 'category_label';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = '[field_variable_categories-label]';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['separator'] = '| ';
  $handler->display->display_options['fields']['field_variable_categories']['field_api_classes'] = 0;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_1']['id'] = 'field_variable_categories_1';
  $handler->display->display_options['fields']['field_variable_categories_1']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['label'] = 'categories_name';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['text'] = '[field_variable_categories_1-name]';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_1']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_1']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_1']['separator'] = '|';
  $handler->display->display_options['fields']['field_variable_categories_1']['field_api_classes'] = 0;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_2']['id'] = 'field_variable_categories_2';
  $handler->display->display_options['fields']['field_variable_categories_2']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['label'] = 'categories_missing';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['text'] = '[field_variable_categories_2-missing]';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_2']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_2']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_variable_categories_2']['separator'] = '|';
  $handler->display->display_options['fields']['field_variable_categories_2']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'variable' => 'variable',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'variable-csv';
  $translatables['variable_csv_export'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('title'),
    t('body'),
    t('published'),
    t('[status]'),
    t('anthropometric_structures'),
    t('body_functions'),
    t('body_structures'),
    t('Class'),
    t('data_source'),
    t('dataset'),
    t('disease_history'),
    t('format'),
    t('label'),
    t('life_habits_behaviours'),
    t('medical_health_interv'),
    t('medication'),
    t('early_life'),
    t('perception_of_health'),
    t('period'),
    t('physical_environment'),
    t('repeatable'),
    t('reproductive_history'),
    t('response_unit'),
    t('social_environment'),
    t('sociodemographic_charact'),
    t('target'),
    t('target_gender'),
    t('category_label'),
    t('[field_variable_categories-label]'),
    t('categories_name'),
    t('[field_variable_categories_1-name]'),
    t('categories_missing'),
    t('[field_variable_categories_2-missing]'),
    t('Data export'),
  );
  $export['variable_csv_export'] = $view;

  $view = new view;
  $view->name = 'variable_search';
  $view->description = '';
  $view->tag = 'dataset, search';
  $view->base_table = 'search_api_index_variable_index';
  $view->human_name = 'Variable Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Dictionnary';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_label' => 'field_label',
    'field_dataset' => 'field_dataset',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dataset' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_variables';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No variables found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'search_api_aggregation_1' => 'search_api_aggregation_1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'variable-search';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-yyyy%timestamp-mm%timestamp-dd%timestamp-hh%timestamp-ii%timestamp-ss.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = 'Label:[field_variable_categories-name] Name: [field_variable_categories-name] Missing:[field_variable_categories-missing]';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['field_api_classes'] = 0;
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_source']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_source']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_source']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_source']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_source']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset_1']['id'] = 'field_dataset_1';
  $handler->display->display_options['fields']['field_dataset_1']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset_1']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['view_mode'] = 'full';
  /* Field: Indexed Node: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_format']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_format']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_format']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_format']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_format']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_format']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medication']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medication']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medication']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medication']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medication']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_early_life']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_early_life']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_early_life']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_early_life']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_early_life']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_period']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_period']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_period']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_period']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_period']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_repeatable']['field_api_classes'] = 0;
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Response Unit */
  $handler->display->display_options['fields']['field_response_unit']['id'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_response_unit']['field'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  /* Field: Indexed Node: Target Gender */
  $handler->display->display_options['fields']['field_target_gender']['id'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target_gender']['field'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['view_mode'] = 'full';
  /* Field: Indexed Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'variables-search-xls';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['use_batch'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-yyyy%timestamp-mm%timestamp-dd%timestamp-hh%timestamp-ii%timestamp-ss.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = 'Label:[field_variable_categories-name] Name: [field_variable_categories-name] Missing:[field_variable_categories-missing]';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_variable_categories']['field_api_classes'] = 0;
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_source']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_source']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_source']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_source']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_source']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_source']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_source']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset_1']['id'] = 'field_dataset_1';
  $handler->display->display_options['fields']['field_dataset_1']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset_1']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_dataset_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_1']['view_mode'] = 'full';
  /* Field: Indexed Node: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_format']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_format']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_format']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_format']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_format']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_format']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_format']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_format']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_medication']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_medication']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_medication']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_medication']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_medication']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_medication']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_medication']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_early_life']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_early_life']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_early_life']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_early_life']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_early_life']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_early_life']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_early_life']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_period']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_period']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_period']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_period']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_period']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_period']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_period']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_repeatable']['field_api_classes'] = 0;
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Response Unit */
  $handler->display->display_options['fields']['field_response_unit']['id'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_response_unit']['field'] = 'field_response_unit';
  $handler->display->display_options['fields']['field_response_unit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_response_unit']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_response_unit']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  /* Field: Indexed Node: Target Gender */
  $handler->display->display_options['fields']['field_target_gender']['id'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target_gender']['field'] = 'field_target_gender';
  $handler->display->display_options['fields']['field_target_gender']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_gender']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target_gender']['view_mode'] = 'full';
  /* Field: Indexed Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'variables-search-csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['use_batch'] = '0';
  $translatables['variable_search'] = array(
    t('Master'),
    t('Data Dictionnary'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_variables'),
    t('No variables found.'),
    t('Name'),
    t('Label'),
    t('Dataset'),
    t('Fulltext search'),
    t('Page'),
    t('Data export'),
    t('Anthropometric Structures'),
    t('Body Functions'),
    t('Body Structures'),
    t('Categories'),
    t('Label:[field_variable_categories-name] Name: [field_variable_categories-name] Missing:[field_variable_categories-missing]'),
    t('Data Source'),
    t('Format'),
    t('Life Habits/Behaviours'),
    t('Medical Health Interventions/Health Services Utilization'),
    t('Medication'),
    t('Participant\'s Early Life/Childhood'),
    t('Perception of Health/Quality of life'),
    t('Period'),
    t('Physical Environment'),
    t('Repeatable'),
    t('Reproductive Health and History'),
    t('Response Unit'),
    t('Social Environment'),
    t('Sociodemographic/Socioeconomic Characteristics'),
    t('Target'),
    t('Target Gender'),
    t('Value Type'),
  );
  $export['variable_search'] = $view;

  return $export;
}
