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

  $view = new view;
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
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'titre';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
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
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_original_field_label']['id'] = 'field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['table'] = 'field_data_field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['field'] = 'field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['label'] = 'field_original_field_label';
  $handler->display->display_options['fields']['field_original_field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_original_field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_original_field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_original_field_label']['field_api_classes'] = 0;
  /* Field: Content: Field Name */
  $handler->display->display_options['fields']['field_original_field_name']['id'] = 'field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['table'] = 'field_data_field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['field'] = 'field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['label'] = 'field_original_field_name';
  $handler->display->display_options['fields']['field_original_field_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['field_api_classes'] = 0;
  /* Field: Content: Content Type Label */
  $handler->display->display_options['fields']['field_bundle_label']['id'] = 'field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['table'] = 'field_data_field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['field'] = 'field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['label'] = 'field_bundle_label';
  $handler->display->display_options['fields']['field_bundle_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_bundle_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_bundle_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_bundle_label']['field_api_classes'] = 0;
  /* Field: Content: Content Type */
  $handler->display->display_options['fields']['field_bundle']['id'] = 'field_bundle';
  $handler->display->display_options['fields']['field_bundle']['table'] = 'field_data_field_bundle';
  $handler->display->display_options['fields']['field_bundle']['field'] = 'field_bundle';
  $handler->display->display_options['fields']['field_bundle']['label'] = 'field_bundle';
  $handler->display->display_options['fields']['field_bundle']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_bundle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_bundle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_bundle']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_bundle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_bundle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_bundle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_bundle']['field_api_classes'] = 0;
  /* Field: Content: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'field_data_field_value_type';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['label'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_categories']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_categories']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_categories']['separator'] = '|';
  $handler->display->display_options['fields']['field_categories']['field_api_classes'] = 0;
  /* Field: Content: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'field_data_field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['label'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['empty'] = '0';
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_repeatable']['field_api_classes'] = 0;
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
  $translatables['csv_field_description_export'] = array(
    t('Master'),
    t('CSV Contact Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
    t('titre'),
    t('body'),
    t('field_original_field_label'),
    t('field_original_field_name'),
    t('field_bundle_label'),
    t('field_bundle'),
    t('field_value_type'),
    t('field_categories'),
    t('field_repeatable'),
    t('Data export'),
  );
  $export['csv_field_description_export'] = $view;

  $view = new view;
  $view->name = 'fields_description_search';
  $view->description = '';
  $view->tag = 'field_description,search';
  $view->base_table = 'search_api_index_fields_description_index';
  $view->human_name = 'Fields Description Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Filters';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: The main body text: Text (indexed) */
  $handler->display->display_options['fields']['body_value']['id'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['fields']['body_value']['field'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body_value']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Indexed Node: Content Type */
  $handler->display->display_options['filters']['field_bundle']['id'] = 'field_bundle';
  $handler->display->display_options['filters']['field_bundle']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['filters']['field_bundle']['field'] = 'field_bundle';
  $handler->display->display_options['filters']['field_bundle']['value'] = 'field_description';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'fields-description-search';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['fields_description_search'] = array(
    t('Master'),
    t('Search Filters'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
    t('Name'),
    t('Text (indexed)'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['fields_description_search'] = $view;

  return $export;
}
