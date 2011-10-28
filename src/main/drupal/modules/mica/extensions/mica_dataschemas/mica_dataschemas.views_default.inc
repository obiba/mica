<?php
/**
 * @file
 * mica_dataschemas.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function mica_dataschemas_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dataschemas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DataSchemas';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DataSchemas';
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
    'field_full_name' => 'field_full_name',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_study_country' => 'field_study_country',
    'field_p3g_observatory_link' => 'field_p3g_observatory_link',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_full_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_target_number_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_study_country' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_p3g_observatory_link' => array(
      'sortable' => 0,
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
  $handler->display->display_options['header']['area']['content'] = 'This page displays the list of the consortium\'s DataSchemas.<br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_studies';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No DataSchemas found.';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
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
    'dataschema' => 'dataschema',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataschemas';
  $export['dataschemas'] = $view;

  $view = new view;
  $view->name = 'datasschema_variables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DatasSchema Variables';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DataSchema Variables';
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
    'field_full_name' => 'field_full_name',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_study_country' => 'field_study_country',
    'field_p3g_observatory_link' => 'field_p3g_observatory_link',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_full_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_target_number_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_study_country' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_p3g_observatory_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataschema_variables';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No variables found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: DataSchemas (field_dataschemas) */
  $handler->display->display_options['relationships']['field_dataschemas_nid']['id'] = 'field_dataschemas_nid';
  $handler->display->display_options['relationships']['field_dataschemas_nid']['table'] = 'field_data_field_dataschemas';
  $handler->display->display_options['relationships']['field_dataschemas_nid']['field'] = 'field_dataschemas_nid';
  $handler->display->display_options['relationships']['field_dataschemas_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_dataschemas_nid']['delta'] = '0';
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
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: DataSchemas */
  $handler->display->display_options['fields']['field_dataschemas']['id'] = 'field_dataschemas';
  $handler->display->display_options['fields']['field_dataschemas']['table'] = 'field_data_field_dataschemas';
  $handler->display->display_options['fields']['field_dataschemas']['field'] = 'field_dataschemas';
  $handler->display->display_options['fields']['field_dataschemas']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataschemas']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataschemas']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_dataschemas']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_dataschemas']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_dataschemas']['field_api_classes'] = 0;
  /* Field: Content: Domain */
  $handler->display->display_options['fields']['field_domain']['id'] = 'field_domain';
  $handler->display->display_options['fields']['field_domain']['table'] = 'field_data_field_domain';
  $handler->display->display_options['fields']['field_domain']['field'] = 'field_domain';
  $handler->display->display_options['fields']['field_domain']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_domain']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_domain']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_domain']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_domain']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_domain']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_domain']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_domain']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_domain']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_domain']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_domain']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_domain']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_domain']['field_api_classes'] = 0;
  /* Field: Content: Module */
  $handler->display->display_options['fields']['field_module']['id'] = 'field_module';
  $handler->display->display_options['fields']['field_module']['table'] = 'field_data_field_module';
  $handler->display->display_options['fields']['field_module']['field'] = 'field_module';
  $handler->display->display_options['fields']['field_module']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_module']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_module']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_module']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_module']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_module']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_module']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_module']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_module']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_module']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_module']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_module']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_module']['field_api_classes'] = 0;
  /* Field: Content: Theme */
  $handler->display->display_options['fields']['field_theme']['id'] = 'field_theme';
  $handler->display->display_options['fields']['field_theme']['table'] = 'field_data_field_theme';
  $handler->display->display_options['fields']['field_theme']['field'] = 'field_theme';
  $handler->display->display_options['fields']['field_theme']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_theme']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_theme']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_theme']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_theme']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_theme']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_theme']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_theme']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_theme']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_theme']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_theme']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_theme']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_theme']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: DataSchemas (field_dataschemas) */
  $handler->display->display_options['arguments']['field_dataschemas_nid']['id'] = 'field_dataschemas_nid';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['table'] = 'field_data_field_dataschemas';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['field'] = 'field_dataschemas_nid';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_dataschemas_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_dataschemas_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_dataschemas_nid']['not'] = 0;
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
    'ds_variable' => 'ds_variable',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataschema-variables';
  $export['datasschema_variables'] = $view;

  return $export;
}
