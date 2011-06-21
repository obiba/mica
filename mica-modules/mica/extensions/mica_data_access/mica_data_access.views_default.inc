<?php
/**
 * @file
 * mica_data_access.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function mica_data_access_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'data_access_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data Access Requests';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Access Requests';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
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
  $handler->display->display_options['fields']['field_project_summary']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_project_summary']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_project_summary']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_data_access_review']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_access_review']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_access_review']['hide_alter_empty'] = 0;
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
  $handler->display->display_options['arguments']['field_review_status_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_review_status_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_review_status_value']['transform_dash'] = 0;
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
  $handler->display->display_options['path'] = 'data-access-requests';
  $export['data_access_requests'] = $view;

  return $export;
}
