<?php
/**
 * @file
 * mica_field_description.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_field_description_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'csv_field_description_export';
  $view->description = 'Export of all field descriptions in CSV';
  $view->tag = 'field_description,csv';
  $view->base_table = 'node';
  $view->human_name = 'Field Description CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Contact Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'titre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_original_field_label']['id'] = 'field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['table'] = 'field_data_field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['field'] = 'field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['label'] = 'field_original_field_label';
  /* Field: Content: Field Name */
  $handler->display->display_options['fields']['field_original_field_name']['id'] = 'field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['table'] = 'field_data_field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['field'] = 'field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['label'] = 'field_original_field_name';
  /* Field: Content: Content Type Label */
  $handler->display->display_options['fields']['field_bundle_label']['id'] = 'field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['table'] = 'field_data_field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['field'] = 'field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['label'] = 'field_bundle_label';
  /* Field: Content: Content Type */
  $handler->display->display_options['fields']['field_bundle']['id'] = 'field_bundle';
  $handler->display->display_options['fields']['field_bundle']['table'] = 'field_data_field_bundle';
  $handler->display->display_options['fields']['field_bundle']['field'] = 'field_bundle';
  $handler->display->display_options['fields']['field_bundle']['label'] = 'field_bundle';
  /* Field: Content: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'field_data_field_value_type';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['label'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_categories']['separator'] = '|';
  /* Field: Content: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'field_data_field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['label'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['empty'] = '0';
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
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
    'field_description' => 'field_description',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-field-description';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '1';
  $export['csv_field_description_export'] = $view;

  $view = new view();
  $view->name = 'fields_description_search';
  $view->description = '';
  $view->tag = 'field_description, search';
  $view->base_table = 'search_api_index_fields_description_index';
  $view->human_name = 'Fields Description Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Filters';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'fields-description-search';
  $export['fields_description_search'] = $view;

  return $export;
}
