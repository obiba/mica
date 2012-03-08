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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
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
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
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
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['field_api_classes'] = 0;
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
    'title' => 'title',
    'search_api_aggregation_1' => 'search_api_aggregation_1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'variable-search';
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
    t('Value Type'),
    t('Repeatable'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['variable_search'] = $view;

  $view = new view;
  $view->name = 'variables';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'node';
  $view->human_name = 'Variables';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Dictionnary';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_variables';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No variables found.';
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
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Dataset (field_dataset) */
  $handler->display->display_options['arguments']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['arguments']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_dataset_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_dataset_nid']['not'] = 0;
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
    'variable' => 'variable',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'variables';
  $translatables['variables'] = array(
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
    t('All'),
    t('Page'),
  );
  $export['variables'] = $view;

  return $export;
}
