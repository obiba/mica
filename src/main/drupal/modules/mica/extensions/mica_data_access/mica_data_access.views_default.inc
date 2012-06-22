<?php
/**
 * @file
 * mica_data_access.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_data_access_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'data_access';
  $view->description = '';
  $view->tag = 'data_access';
  $view->base_table = 'node';
  $view->human_name = 'Data Access';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DACO Approved Projects';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_data_access_committee';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No approved data access found.';
  /* Relationship: Content: Data Access Review (field_data_access_review) */
  $handler->display->display_options['relationships']['field_data_access_review_nid']['id'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['table'] = 'field_data_field_data_access_review';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['field'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_data_access_review_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project';
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
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_project_summary']['id'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['field'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['field_api_classes'] = 0;
  /* Field: Content: Representative Name */
  $handler->display->display_options['fields']['field_representative']['id'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['table'] = 'field_data_field_representative';
  $handler->display->display_options['fields']['field_representative']['field'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['label'] = 'Representative';
  $handler->display->display_options['fields']['field_representative']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_representative']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_representative']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_representative']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_representative']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_representative']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_representative']['field_api_classes'] = 0;
  /* Field: Content: Institution Name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'Institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_review_status) */
  $handler->display->display_options['arguments']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['arguments']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_review_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_review_status_value']['break_phrase'] = 0;
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
    'data_access_request' => 'data_access_request',
  );
  /* Filter criterion: Content: Status (field_review_status) */
  $handler->display->display_options['filters']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['filters']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['filters']['field_review_status_value']['value'] = array(
    'accepted' => 'accepted',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'data-access/approved';
  $export['data_access'] = $view;

  $view = new view;
  $view->name = 'data_access_admin';
  $view->description = '';
  $view->tag = 'data_access';
  $view->base_table = 'node';
  $view->human_name = 'Data Access Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Access Administration';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_data_access';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No data access request found.';
  /* Relationship: Content: Data Access Review (field_data_access_review) */
  $handler->display->display_options['relationships']['field_data_access_review_nid']['id'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['table'] = 'field_data_field_data_access_review';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['field'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_data_access_review_nid']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project';
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
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_project_summary']['id'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['field'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['field_api_classes'] = 0;
  /* Field: Content: Representative Name */
  $handler->display->display_options['fields']['field_representative']['id'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['table'] = 'field_data_field_representative';
  $handler->display->display_options['fields']['field_representative']['field'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['label'] = 'Representative';
  $handler->display->display_options['fields']['field_representative']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_representative']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_representative']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_representative']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_representative']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_representative']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_representative']['field_api_classes'] = 0;
  /* Field: Content: Institution Name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'Institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['field_api_classes'] = 0;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['fields']['field_review_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_review_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_review_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_review_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_review_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_review_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_review_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_review_status']['field_api_classes'] = 0;
  /* Field: Content: Data Access Review */
  $handler->display->display_options['fields']['field_data_access_review']['id'] = 'field_data_access_review';
  $handler->display->display_options['fields']['field_data_access_review']['table'] = 'field_data_field_data_access_review';
  $handler->display->display_options['fields']['field_data_access_review']['field'] = 'field_data_access_review';
  $handler->display->display_options['fields']['field_data_access_review']['label'] = 'Review';
  $handler->display->display_options['fields']['field_data_access_review']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['empty'] = '<a href="?q=node/[nid]/review">Start Review</a>';
  $handler->display->display_options['fields']['field_data_access_review']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_review_status) */
  $handler->display->display_options['arguments']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['arguments']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_review_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_review_status_value']['break_phrase'] = 0;
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
    'data_access_request' => 'data_access_request',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'data-access/admin';
  $export['data_access_admin'] = $view;

  $view = new view;
  $view->name = 'data_access_committee';
  $view->description = '';
  $view->tag = 'data_access';
  $view->base_table = 'node';
  $view->human_name = 'Data Access Committee';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Access Committee';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_data_access_committee';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No data access committee member found.';
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_contact_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['link_class'] = '[title]';
  $handler->display->display_options['fields']['field_contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_contact_name]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Institution Name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'Institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['field_api_classes'] = 0;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'contact' => 'contact',
  );
  /* Filter criterion: Content: Data Access Committee member (field_daco) */
  $handler->display->display_options['filters']['field_daco_value']['id'] = 'field_daco_value';
  $handler->display->display_options['filters']['field_daco_value']['table'] = 'field_data_field_daco';
  $handler->display->display_options['filters']['field_daco_value']['field'] = 'field_daco_value';
  $handler->display->display_options['filters']['field_daco_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'data-access/committee';
  $export['data_access_committee'] = $view;

  $view = new view;
  $view->name = 'my_data_access_requests';
  $view->description = '';
  $view->tag = 'data_access';
  $view->base_table = 'node';
  $view->human_name = 'My Data Access Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Data Access Requests';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_data_access';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No data access request found.';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Content: Data Access Review (field_data_access_review) */
  $handler->display->display_options['relationships']['field_data_access_review_nid']['id'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['table'] = 'field_data_field_data_access_review';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['field'] = 'field_data_access_review_nid';
  $handler->display->display_options['relationships']['field_data_access_review_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_data_access_review_nid']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project';
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
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_project_summary']['id'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['field'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_summary']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['field_api_classes'] = 0;
  /* Field: Content: Representative Name */
  $handler->display->display_options['fields']['field_representative']['id'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['table'] = 'field_data_field_representative';
  $handler->display->display_options['fields']['field_representative']['field'] = 'field_representative';
  $handler->display->display_options['fields']['field_representative']['label'] = 'Representative';
  $handler->display->display_options['fields']['field_representative']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_representative']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_representative']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_representative']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_representative']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_representative']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_representative']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_representative']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_representative']['field_api_classes'] = 0;
  /* Field: Content: Institution Name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'Institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_institution_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['field_api_classes'] = 0;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['fields']['field_review_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_review_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_review_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_review_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_review_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_review_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_review_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_review_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_review_status']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Status (field_review_status) */
  $handler->display->display_options['arguments']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['arguments']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['arguments']['field_review_status_value']['relationship'] = 'field_data_access_review_nid';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_review_status_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_review_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_review_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_review_status_value']['break_phrase'] = 0;
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
    'data_access_request' => 'data_access_request',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'data-access/requests';
  $export['my_data_access_requests'] = $view;

  return $export;
}
