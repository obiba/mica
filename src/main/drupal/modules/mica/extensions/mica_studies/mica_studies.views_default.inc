<?php
/**
 * @file
 * mica_studies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_studies_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'csv_contact_export';
  $view->description = 'Export of all contacts in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Contact Export';
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
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
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
  /* Field: Field collection item: Investigator Name */
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
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_2']['type'] = 'name_raw_title';
  $handler->display->display_options['fields']['field_contact_name_2']['field_api_classes'] = 0;
  /* Field: Field collection item: Investigator Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'field_contact_name:given';
  $handler->display->display_options['fields']['field_contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name']['type'] = 'name_plain_given';
  $handler->display->display_options['fields']['field_contact_name']['field_api_classes'] = 0;
  /* Field: Field collection item: Investigator Name */
  $handler->display->display_options['fields']['field_contact_name_1']['id'] = 'field_contact_name_1';
  $handler->display->display_options['fields']['field_contact_name_1']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['label'] = 'field_contact_name:family';
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_1']['type'] = 'name_plain_family';
  $handler->display->display_options['fields']['field_contact_name_1']['field_api_classes'] = 0;
  /* Field: Field collection item: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'field_contact_email:email';
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
  /* Field: Field collection item: Telephone */
  $handler->display->display_options['fields']['field_telephone']['id'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['table'] = 'field_data_field_telephone';
  $handler->display->display_options['fields']['field_telephone']['field'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['label'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_telephone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_telephone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_telephone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_telephone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_telephone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_telephone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_telephone']['field_api_classes'] = 0;
  /* Field: Field collection item: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['label'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_institution']['alter']['trim'] = 0;
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
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
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('titre'),
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
  $view->name = 'csv_field_description_export';
  $view->description = 'Export of all field descriptions in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Field Description Export';
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
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
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
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_field_description_export'] = array(
    t('Master'),
    t('CSV Contact Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
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
  $view->name = 'csv_institution_export';
  $view->description = 'Export of all institutions in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CSV Institution Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Institution Export';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
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
  $handler->display->display_options['fields']['field_street']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_street']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_street']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_street']['alter']['trim'] = 0;
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
  $handler->display->display_options['fields']['field_city']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_city']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['trim'] = 0;
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
  $handler->display->display_options['fields']['field_postal_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['field_api_classes'] = 0;
  /* Field: Field collection item: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim'] = 0;
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
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
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('titre'),
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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Study Export';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_study_legacy_id']['id'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['table'] = 'field_data_field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['field'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['label'] = 'field_study_legacy_id';
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_legacy_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_legacy_id']['empty_zero'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_full_name']['empty_zero'] = 0;
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
  $handler->display->display_options['fields']['field_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim'] = 0;
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
  $handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['label'] = 'field_contact';
  $handler->display->display_options['fields']['field_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact']['empty_zero'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_investigator']['id'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['table'] = 'field_data_field_investigator';
  $handler->display->display_options['fields']['field_investigator']['field'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['label'] = 'field_investigator';
  $handler->display->display_options['fields']['field_investigator']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_investigator']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_investigator']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_investigator']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_investigator']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_investigator']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_investigator']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_investigator']['empty_zero'] = 0;
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: How many people have provided or should provide biological samples, frolm which DNA could be extracted? */
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['id'] = 'field_target_number_biosamples_1';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['label'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples_1']['alter']['trim'] = 0;
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_p3g_observatory_link']['id'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['table'] = 'field_data_field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['field'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['label'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['text'] = '[field_p3g_observatory_link-url]';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['empty_zero'] = 0;
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
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-study';
  $handler->display->display_options['use_batch'] = '0';
  $translatables['csv_study_export'] = array(
    t('Master'),
    t('CSV Study Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('field_study_legacy_id'),
    t('titre'),
    t('body'),
    t('Broken handler field_data_field_full_name.field_full_name'),
    t('field_website'),
    t('field_contact'),
    t('field_investigator'),
    t('field_target_number_participants'),
    t('field_target_number_biosamples'),
    t('field_p3g_observatory_link'),
    t('[field_p3g_observatory_link-url]'),
    t('Data export'),
  );
  $export['csv_study_export'] = $view;

  $view = new view;
  $view->name = 'documents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Documents';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_files' => 'field_files',
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
    'field_files' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_documents';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No document found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nom';
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
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['label'] = 'Download';
  $handler->display->display_options['fields']['field_files']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_files']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_files']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_files']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_files']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_files']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_files']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_files']['multi_type'] = 'ol';
  $handler->display->display_options['fields']['field_files']['field_api_classes'] = 0;
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
    'documents' => 'documents',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'documents';
  $translatables['documents'] = array(
    t('Master'),
    t('Documents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('empty_documents'),
    t('No document found.'),
    t('Nom'),
    t('Description'),
    t('Download'),
    t('Page'),
  );
  $export['documents'] = $view;

  $view = new view;
  $view->name = 'fields_description_search';
  $view->description = '';
  $view->tag = 'default';
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
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nom';
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
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_fields_description_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'field_description' => 'field_description',
  );

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
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('Nom'),
    t('Text (indexed)'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['fields_description_search'] = $view;

  $view = new view;
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent News';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_news';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No news found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'news';
  $translatables['news'] = array(
    t('Master'),
    t('Recent News'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('empty_news'),
    t('No news found.'),
    t('Page'),
  );
  $export['news'] = $view;

  $view = new view;
  $view->name = 'studies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Studies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Études';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
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
  $handler->display->display_options['header']['area']['content'] = 'This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies. 

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_studies';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No study found.';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['mica_study_information_nid']['id'] = 'mica_study_information_nid';
  $handler->display->display_options['relationships']['mica_study_information_nid']['table'] = 'field_data_mica_study_information';
  $handler->display->display_options['relationships']['mica_study_information_nid']['field'] = 'mica_study_information_nid';
  $handler->display->display_options['relationships']['mica_study_information_nid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nom';
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_full_name']['empty_zero'] = 0;
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'Combien de participants seront recrutés ? Ou, si le recrutement est terminé, quel est le nombre final de participants ?';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
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
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_study_country']['id'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['table'] = 'field_data_field_study_country';
  $handler->display->display_options['fields']['field_study_country']['field'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['relationship'] = 'mica_study_information_nid';
  $handler->display->display_options['fields']['field_study_country']['label'] = 'Pays';
  $handler->display->display_options['fields']['field_study_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_country']['empty_zero'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_p3g_observatory_link']['id'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['table'] = 'field_data_field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['field'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['empty_zero'] = 0;
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
  $translatables['studies'] = array(
    t('Master'),
    t('Études'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies. 

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>'),
    t('empty_studies'),
    t('No study found.'),
    t('mica_study_information_nid'),
    t('Nom'),
    t('Broken handler field_data_field_full_name.field_full_name'),
    t('Combien de participants seront recrutés ? Ou, si le recrutement est terminé, quel est le nombre final de participants ?'),
    t('Pays'),
    t('Broken handler field_data_field_p3g_observatory_link.field_p3g_observatory_link'),
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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies Search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout - ';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_full_name' => 'field_full_name',
    'field_target_number_participants' => 'field_target_number_participants',
    'mica_study_information_field_study_country' => 'mica_study_information_field_study_country',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_full_name' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_target_number_participants' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'mica_study_information_field_study_country' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_studies';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No study found.';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nom';
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_full_name']['empty_zero'] = 0;
  /* Field: Indexed Node: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'Combien de participants seront recrutés ? Ou, si le recrutement est terminé, quel est le nombre final de participants ?';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['id'] = 'mica_study_information_field_study_country';
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['field'] = 'mica_study_information_field_study_country';
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['label'] = 'Pays';
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mica_study_information_field_study_country']['empty_zero'] = 0;
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
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'studies-search';
  $translatables['studies_search'] = array(
    t('Master'),
    t('Studies Search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items par page'),
    t('- Tout - '),
    t('Décalage'),
    t('empty_studies'),
    t('No study found.'),
    t('Nom'),
    t('Broken handler search_api_index_studies_index.field_full_name'),
    t('Combien de participants seront recrutés ? Ou, si le recrutement est terminé, quel est le nombre final de participants ?'),
    t('Pays'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['studies_search'] = $view;

  return $export;
}
