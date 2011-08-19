<?php
/**
 * @file
 * mica_projects.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function mica_projects_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $translatables['projects'] = array(
    t('Master'),
    t('Projects'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_projects'),
    t('No project found.'),
    t('Page'),
  );
  $export['projects'] = $view;

  $view = new view;
  $view->name = 'teleconferences';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teleconferences';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teleconferences';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teleconference_date']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_teleconference_description']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['field_instructions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_instructions']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['field_instructions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_instructions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_instructions']['alter']['strip_tags'] = 0;
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
  /* Contextual filter: Fields: Project (field_project) - nid */
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
  $translatables['teleconferences'] = array(
    t('Master'),
    t('Teleconferences'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_teleconferences'),
    t('No teleconference found.'),
    t('Date'),
    t('Title'),
    t('Description'),
    t('Instructions'),
    t('All'),
    t('Page'),
  );
  $export['teleconferences'] = $view;

  return $export;
}
