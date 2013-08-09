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

  $view = new view();
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
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Relationship: Content: Studies (field_studies) */
  $handler->display->display_options['relationships']['field_studies_nid']['id'] = 'field_studies_nid';
  $handler->display->display_options['relationships']['field_studies_nid']['table'] = 'field_data_field_studies';
  $handler->display->display_options['relationships']['field_studies_nid']['field'] = 'field_studies_nid';
  $handler->display->display_options['relationships']['field_studies_nid']['delta'] = '-1';
  /* Relationship: Content: Populations (field_study_populations) */
  $handler->display->display_options['relationships']['field_study_populations_nid']['id'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['table'] = 'field_data_field_study_populations';
  $handler->display->display_options['relationships']['field_study_populations_nid']['field'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['delta'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp]';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['relationship'] = 'field_studies_nid';
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Country of residence */
  $handler->display->display_options['fields']['field_pop_country']['id'] = 'field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['table'] = 'field_data_field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['field'] = 'field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['relationship'] = 'field_study_populations_nid';
  $handler->display->display_options['fields']['field_pop_country']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['project_studies'] = $view;

  $view = new view();
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
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header_projects';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'List of all projects of the consortium';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_projects';
  $handler->display->display_options['empty']['area']['content'] = 'No project found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'projects';
  $export['projects'] = $view;

  $view = new view();
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
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_teleconferences';
  $handler->display->display_options['empty']['area']['content'] = 'No teleconference found.';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_teleconference_date']['id'] = 'field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['table'] = 'field_data_field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['field'] = 'field_teleconference_date';
  $handler->display->display_options['fields']['field_teleconference_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_teleconference_description']['id'] = 'field_teleconference_description';
  $handler->display->display_options['fields']['field_teleconference_description']['table'] = 'field_data_field_teleconference_description';
  $handler->display->display_options['fields']['field_teleconference_description']['field'] = 'field_teleconference_description';
  /* Field: Content: Instructions */
  $handler->display->display_options['fields']['field_instructions']['id'] = 'field_instructions';
  $handler->display->display_options['fields']['field_instructions']['table'] = 'field_data_field_instructions';
  $handler->display->display_options['fields']['field_instructions']['field'] = 'field_instructions';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Project (field_project) */
  $handler->display->display_options['arguments']['field_project_nid']['id'] = 'field_project_nid';
  $handler->display->display_options['arguments']['field_project_nid']['table'] = 'field_data_field_project';
  $handler->display->display_options['arguments']['field_project_nid']['field'] = 'field_project_nid';
  $handler->display->display_options['arguments']['field_project_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'teleconferences';
  $export['teleconferences'] = $view;

  return $export;
}
