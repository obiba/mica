<?php
/**
 * @file
 * mica_feature.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function mica_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'csv_contact_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Contact Export';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Contact Export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name_2']['id'] = 'field_contact_name_2';
  $handler->display->display_options['fields']['field_contact_name_2']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['label'] = 'field_contact_name:title';
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['text'] = '[field_contact_name_2-title]';
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_2']['type'] = 'name_raw_title';
  $handler->display->display_options['fields']['field_contact_name_2']['field_api_classes'] = 0;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'field_contact_name:given';
  $handler->display->display_options['fields']['field_contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name']['type'] = 'name_plain_given';
  $handler->display->display_options['fields']['field_contact_name']['field_api_classes'] = 0;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name_1']['id'] = 'field_contact_name_1';
  $handler->display->display_options['fields']['field_contact_name_1']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['label'] = 'field_contact_name:family';
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_1']['type'] = 'name_plain_family';
  $handler->display->display_options['fields']['field_contact_name_1']['field_api_classes'] = 0;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'field_contact_email:email';
  $handler->display->display_options['fields']['field_contact_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['type'] = 'email_default';
  $handler->display->display_options['fields']['field_contact_email']['field_api_classes'] = 0;
  /* Field: Content: Telephone */
  $handler->display->display_options['fields']['field_telephone']['id'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['table'] = 'field_data_field_telephone';
  $handler->display->display_options['fields']['field_telephone']['field'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['label'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_telephone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_telephone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_telephone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_telephone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_telephone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_telephone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_telephone']['field_api_classes'] = 0;
  /* Field: Content: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['label'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_institution']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_institution']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_institution']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_institution']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_institution']['field_api_classes'] = 0;
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-contact';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_contact_export'] = array(
    t('Master'),
    t('CSV Contact Export'),
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
    t('field_contact_name:title'),
    t('[field_contact_name_2-title]'),
    t('field_contact_name:given'),
    t('field_contact_name:family'),
    t('field_contact_email:email'),
    t('field_telephone'),
    t('field_institution'),
    t('Data export'),
  );
  $export['csv_contact_export'] = $view;

  $view = new view;
  $view->name = 'csv_institution_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Institution Export';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Institution Export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Street */
  $handler->display->display_options['fields']['field_street']['id'] = 'field_street';
  $handler->display->display_options['fields']['field_street']['table'] = 'field_data_field_street';
  $handler->display->display_options['fields']['field_street']['field'] = 'field_street';
  $handler->display->display_options['fields']['field_street']['label'] = 'field_street';
  $handler->display->display_options['fields']['field_street']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_street']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_street']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_street']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_street']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_street']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_street']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_street']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_city']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_city']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_city']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_city']['field_api_classes'] = 0;
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_postal_code']['id'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['table'] = 'field_data_field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['field'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['label'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['field_api_classes'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_country']['empty_zero'] = 0;
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
    'institution' => 'institution',
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-institution';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_institution_export'] = array(
    t('Master'),
    t('CSV Institution Export'),
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
    t('field_street'),
    t('field_city'),
    t('field_postal_code'),
    t('field_country'),
    t('Data export'),
  );
  $export['csv_institution_export'] = $view;

  $view = new view;
  $view->name = 'csv_study_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Study Export';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Study Export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Study Legacy Id */
  $handler->display->display_options['fields']['field_study_legacy_id']['id'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['table'] = 'field_data_field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['field'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['label'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_study_legacy_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_study_legacy_id']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'plain';
  $handler->display->display_options['fields']['field_website']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_website']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_website']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_website']['field_api_classes'] = 0;
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
    'study' => 'study',
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-study';
  $handler->display->display_options['use_batch'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'study-export';
  $translatables['csv_study_export'] = array(
    t('Master'),
    t('CSV Study Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_study_legacy_id'),
    t('title'),
    t('body'),
    t('field_website'),
    t('Data export'),
    t('Page'),
  );
  $export['csv_study_export'] = $view;

  $view = new view;
  $view->name = 'csv_study_information_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Study Information Export';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Study Information Export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Access to the following features is provided or foreseen */
  $handler->display->display_options['fields']['field_access']['id'] = 'field_access';
  $handler->display->display_options['fields']['field_access']['table'] = 'field_data_field_access';
  $handler->display->display_options['fields']['field_access']['field'] = 'field_access';
  $handler->display->display_options['fields']['field_access']['label'] = 'field_access';
  $handler->display->display_options['fields']['field_access']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_access']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_access']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_access']['field_api_classes'] = 0;
  /* Field: Content: Specify type of access */
  $handler->display->display_options['fields']['field_access_other']['id'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['table'] = 'field_data_field_access_other';
  $handler->display->display_options['fields']['field_access_other']['field'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['label'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access_other']['field_api_classes'] = 0;
  /* Field: Content: Max age */
  $handler->display->display_options['fields']['field_age_max']['id'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['table'] = 'field_data_field_age_max';
  $handler->display->display_options['fields']['field_age_max']['field'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['label'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_age_max']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_age_max']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_age_max']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_age_max']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_age_max']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_age_max']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_age_max']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_age_max']['field_api_classes'] = 0;
  /* Field: Content: Min age */
  $handler->display->display_options['fields']['field_age_min']['id'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['table'] = 'field_data_field_age_min';
  $handler->display->display_options['fields']['field_age_min']['field'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['label'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_age_min']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_age_min']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_age_min']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_age_min']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_age_min']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_age_min']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_age_min']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_age_min']['field_api_classes'] = 0;
  /* Field: Content: Biological Samples Collected */
  $handler->display->display_options['fields']['field_biosamples_collected']['id'] = 'field_biosamples_collected';
  $handler->display->display_options['fields']['field_biosamples_collected']['table'] = 'field_data_field_biosamples_collected';
  $handler->display->display_options['fields']['field_biosamples_collected']['field'] = 'field_biosamples_collected';
  $handler->display->display_options['fields']['field_biosamples_collected']['label'] = 'field_biosamples_collected';
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biosamples_collected']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected']['field_api_classes'] = 0;
  /* Field: Content: Specify type of samples collected */
  $handler->display->display_options['fields']['field_biosamples_collected_other']['id'] = 'field_biosamples_collected_other';
  $handler->display->display_options['fields']['field_biosamples_collected_other']['table'] = 'field_data_field_biosamples_collected_other';
  $handler->display->display_options['fields']['field_biosamples_collected_other']['field'] = 'field_biosamples_collected_other';
  $handler->display->display_options['fields']['field_biosamples_collected_other']['label'] = 'field_design_other';
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_biosamples_collected_other']['field_api_classes'] = 0;
  /* Field: Content: Specify type of tissues collected */
  $handler->display->display_options['fields']['field_biosamples_tissues']['id'] = 'field_biosamples_tissues';
  $handler->display->display_options['fields']['field_biosamples_tissues']['table'] = 'field_data_field_biosamples_tissues';
  $handler->display->display_options['fields']['field_biosamples_tissues']['field'] = 'field_biosamples_tissues';
  $handler->display->display_options['fields']['field_biosamples_tissues']['label'] = 'field_target_other';
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_biosamples_tissues']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_biosamples_tissues']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_biosamples_tissues']['field_api_classes'] = 0;
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['label'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_contact']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_contact']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_contact']['separator'] = '|';
  $handler->display->display_options['fields']['field_contact']['field_api_classes'] = 0;
  /* Field: Content: Baseline Design of the Study */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['label'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_design']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_design']['field_api_classes'] = 0;
  /* Field: Content: Specify type of design */
  $handler->display->display_options['fields']['field_design_other']['id'] = 'field_design_other';
  $handler->display->display_options['fields']['field_design_other']['table'] = 'field_data_field_design_other';
  $handler->display->display_options['fields']['field_design_other']['field'] = 'field_design_other';
  $handler->display->display_options['fields']['field_design_other']['label'] = 'field_biosamples_collected_other';
  $handler->display->display_options['fields']['field_design_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design_other']['field_api_classes'] = 0;
  /* Field: Content: Targets Recruitment of */
  $handler->display->display_options['fields']['field_design_target']['id'] = 'field_design_target';
  $handler->display->display_options['fields']['field_design_target']['table'] = 'field_data_field_design_target';
  $handler->display->display_options['fields']['field_design_target']['field'] = 'field_design_target';
  $handler->display->display_options['fields']['field_design_target']['label'] = 'field_design_target';
  $handler->display->display_options['fields']['field_design_target']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design_target']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design_target']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design_target']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design_target']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design_target']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design_target']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design_target']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design_target']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_design_target']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_design_target']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_design_target']['separator'] = '|';
  $handler->display->display_options['fields']['field_design_target']['field_api_classes'] = 0;
  /* Field: Content: Specify Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gender']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gender']['field_api_classes'] = 0;
  /* Field: Content: Proceeding to Genome-Wide Association (GWA) Analysis */
  $handler->display->display_options['fields']['field_gwas_analysis']['id'] = 'field_gwas_analysis';
  $handler->display->display_options['fields']['field_gwas_analysis']['table'] = 'field_data_field_gwas_analysis';
  $handler->display->display_options['fields']['field_gwas_analysis']['field'] = 'field_gwas_analysis';
  $handler->display->display_options['fields']['field_gwas_analysis']['label'] = 'field_gwas_analysis';
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_gwas_analysis']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gwas_analysis']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gwas_analysis']['field_api_classes'] = 0;
  /* Field: Content: Please specify the approximate number of participants */
  $handler->display->display_options['fields']['field_gwas_number']['id'] = 'field_gwas_number';
  $handler->display->display_options['fields']['field_gwas_number']['table'] = 'field_data_field_gwas_number';
  $handler->display->display_options['fields']['field_gwas_number']['field'] = 'field_gwas_number';
  $handler->display->display_options['fields']['field_gwas_number']['label'] = 'field_gwas_number';
  $handler->display->display_options['fields']['field_gwas_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_gwas_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gwas_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gwas_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_gwas_number']['field_api_classes'] = 0;
  /* Field: Content: Investigator */
  $handler->display->display_options['fields']['field_investigator']['id'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['table'] = 'field_data_field_investigator';
  $handler->display->display_options['fields']['field_investigator']['field'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['label'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_investigator']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_investigator']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_investigator']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_investigator']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_investigator']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_investigator']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_investigator']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_investigator']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_investigator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_investigator']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_investigator']['separator'] = '|';
  $handler->display->display_options['fields']['field_investigator']['field_api_classes'] = 0;
  /* Field: Content: Selection Criteria / Charactecteristic of the Population */
  $handler->display->display_options['fields']['field_selection_criteria']['id'] = 'field_selection_criteria';
  $handler->display->display_options['fields']['field_selection_criteria']['table'] = 'field_data_field_selection_criteria';
  $handler->display->display_options['fields']['field_selection_criteria']['field'] = 'field_selection_criteria';
  $handler->display->display_options['fields']['field_selection_criteria']['label'] = 'field_selection_criteria';
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_selection_criteria']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_selection_criteria']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_selection_criteria']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_selection_criteria']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_selection_criteria']['separator'] = '|';
  $handler->display->display_options['fields']['field_selection_criteria']['field_api_classes'] = 0;
  /* Field: Content: End year */
  $handler->display->display_options['fields']['field_status_end']['id'] = 'field_status_end';
  $handler->display->display_options['fields']['field_status_end']['table'] = 'field_data_field_status_end';
  $handler->display->display_options['fields']['field_status_end']['field'] = 'field_status_end';
  $handler->display->display_options['fields']['field_status_end']['label'] = 'field_status_end';
  $handler->display->display_options['fields']['field_status_end']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_status_end']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_status_end']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_status_end']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_status_end']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_status_end']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_status_end']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_status_end']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_status_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_status_end']['field_api_classes'] = 0;
  /* Field: Content: Start year */
  $handler->display->display_options['fields']['field_status_start']['id'] = 'field_status_start';
  $handler->display->display_options['fields']['field_status_start']['table'] = 'field_data_field_status_start';
  $handler->display->display_options['fields']['field_status_start']['field'] = 'field_status_start';
  $handler->display->display_options['fields']['field_status_start']['label'] = 'field_status_start';
  $handler->display->display_options['fields']['field_status_start']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_status_start']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_status_start']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_status_start']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_status_start']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_status_start']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_status_start']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_status_start']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_status_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_status_start']['field_api_classes'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_study_country']['id'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['table'] = 'field_data_field_study_country';
  $handler->display->display_options['fields']['field_study_country']['field'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['label'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_country']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_study_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_study_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_study_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_study_country']['field_api_classes'] = 0;
  /* Field: Content: Study Legacy Id */
  $handler->display->display_options['fields']['field_study_legacy_id']['id'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['table'] = 'field_data_field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['field'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['label'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_study_legacy_id']['field_api_classes'] = 0;
  /* Field: Content: Target Number of Biological Samples */
  $handler->display->display_options['fields']['field_target_number_biosamples']['id'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['label'] = 'field_gwas_number';
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_biosamples']['field_api_classes'] = 0;
  /* Field: Content: Target Number of Biological Samples */
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['id'] = 'field_target_number_biosamples_1';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['label'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['field_api_classes'] = 0;
  /* Field: Content: Target Number of Participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: Specify type of target */
  $handler->display->display_options['fields']['field_target_other']['id'] = 'field_target_other';
  $handler->display->display_options['fields']['field_target_other']['table'] = 'field_data_field_target_other';
  $handler->display->display_options['fields']['field_target_other']['field'] = 'field_target_other';
  $handler->display->display_options['fields']['field_target_other']['label'] = 'field_biosamples_tissues';
  $handler->display->display_options['fields']['field_target_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_other']['field_api_classes'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'title';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Full Name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_full_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_full_name']['field_api_classes'] = 0;
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
    'study_information' => 'study_information',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm%timestamp-dd-%timestamp-hh%timestamp-ii%timestamp-ss-.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-study-information';
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_study_information_export'] = array(
    t('Master'),
    t('CSV Study Information Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('field_access'),
    t('field_access_other'),
    t('field_age_max'),
    t('field_age_min'),
    t('field_biosamples_collected'),
    t('field_design_other'),
    t('field_target_other'),
    t('field_contact'),
    t('field_design'),
    t('field_biosamples_collected_other'),
    t('field_design_target'),
    t('field_gender'),
    t('field_gwas_analysis'),
    t('field_gwas_number'),
    t('field_investigator'),
    t('field_selection_criteria'),
    t('field_status_end'),
    t('field_status_start'),
    t('field_study_country'),
    t('field_study_legacy_id'),
    t('field_target_number_biosamples'),
    t('field_target_number_participants'),
    t('field_biosamples_tissues'),
    t('status'),
    t('title'),
    t('field_full_name'),
    t('Data export'),
  );
  $export['csv_study_information_export'] = $view;

  $view = new view;
  $view->name = 'csv_variable_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Variable Export';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Contact Export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['field_bundle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_bundle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_bundle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_bundle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_bundle']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_bundle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_bundle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_bundle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_bundle']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_original_field_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_original_field_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_original_field_name']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_value_type']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-variable';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_variable_export'] = array(
    t('Master'),
    t('CSV Contact Export'),
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
    t('field_bundle'),
    t('field_original_field_name'),
    t('field_value_type'),
    t('body'),
    t('Data export'),
  );
  $export['csv_variable_export'] = $view;

  $view = new view;
  $view->name = 'studies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Studies';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
    'study' => 'study',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'studies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Studies';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['studies'] = array(
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
    t('Page'),
  );
  $export['studies'] = $view;

  $view = new view;
  $view->name = 'studies_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_studies_index';
  $view->human_name = 'Studies Search';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies Search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'studies-search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Studies Search';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['studies_search'] = array(
    t('Master'),
    t('Studies Search'),
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
    t('Content type'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['studies_search'] = $view;

  $view = new view;
  $view->name = 'variables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Variables';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Variables';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
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
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Variables';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['variables'] = array(
    t('Master'),
    t('Variables'),
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
    t('Description'),
    t('Page'),
    t('Block'),
  );
  $export['variables'] = $view;

  $view = new view;
  $view->name = 'variables_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_variables_index';
  $view->human_name = 'Variables Search';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Variables Search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variables_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_variables_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_variables_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_variables_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'variable' => 'variable',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'variables-search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Variables Search';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['variables_search'] = array(
    t('Master'),
    t('Variables Search'),
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
    t('Content type'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['variables_search'] = $view;

  return $export;
}
