<?php
/**
 * @file
 * mica_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_projects_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'project_studies';
  $view->description = '';
  $view->tag = 'study, project';
  $view->base_table = 'node';
  $view->human_name = 'Project Studies';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  /* Relationship: Content: Studies (field_studies) */
  $handler->display->display_options['relationships']['field_studies_nid']['id'] = 'field_studies_nid';
  $handler->display->display_options['relationships']['field_studies_nid']['table'] = 'field_data_field_studies';
  $handler->display->display_options['relationships']['field_studies_nid']['field'] = 'field_studies_nid';
  $handler->display->display_options['relationships']['field_studies_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_studies_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_studies_nid';
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
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Please specify what other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['relationship'] = 'field_studies_nid';
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
  $handler->display->display_options['fields']['field_design']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['fields']['field_design']['label'] = 'Study design';
  $handler->display->display_options['fields']['field_design']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp]';
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
  $handler->display->display_options['fields']['field_target_number_participants']['relationship'] = 'field_studies_nid';
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
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: Country of residence */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'field_studies_nid';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
  $handler->display->display_options['filters']['type']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['project_studies'] = $view;

  $view = new view;
  $view->name = 'projects';
  $view->description = '';
  $view->tag = 'project';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
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
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header_projects';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'List of all projects of the consortium';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_projects';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No project found.';
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
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
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
    'project' => 'project',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['projects'] = $view;

  $view = new view;
  $view->name = 'teleconferences';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teleconferences';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teleconferences';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_teleconference_date' => 'field_teleconference_date',
    'title' => 'title',
    'field_teleconference_description' => 'field_teleconference_description',
    'field_instructions' => 'field_instructions',
  );
  $handler->display->display_options['style_options']['default'] = 'field_teleconference_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_teleconference_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_teleconference_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_instructions' => array(
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
  $handler->display->display_options['empty']['area']['label'] = 'empty_teleconferences';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No teleconference found.';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_teleconference_date']['id'] = 'field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['table'] = 'field_data_field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['field'] = 'field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_teleconference_date']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_teleconference_description']['id'] = 'field_teleconference_description';
  $handler->display->display_options['fields']['field_teleconference_description']['table'] = 'field_data_field_teleconference_description';
  $handler->display->display_options['fields']['field_teleconference_description']['field'] = 'field_teleconference_description';
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['field_api_classes'] = 0;
  /* Field: Content: Instructions */
  $handler->display->display_options['fields']['field_instructions']['id'] = 'field_instructions';
  $handler->display->display_options['fields']['field_instructions']['table'] = 'field_data_field_instructions';
  $handler->display->display_options['fields']['field_instructions']['field'] = 'field_instructions';
  $handler->display->display_options['fields']['field_instructions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instructions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instructions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_instructions']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_instructions']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_instructions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_instructions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_instructions']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Project (field_project) */
  $handler->display->display_options['arguments']['field_project_nid']['id'] = 'field_project_nid';
  $handler->display->display_options['arguments']['field_project_nid']['table'] = 'field_data_field_project';
  $handler->display->display_options['arguments']['field_project_nid']['field'] = 'field_project_nid';
  $handler->display->display_options['arguments']['field_project_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_nid']['not'] = 0;
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
    'teleconference' => 'teleconference',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'teleconferences';
  $handler->display->display_options['menu']['title'] = 'Studies';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['teleconferences'] = $view;

  return $export;
}
