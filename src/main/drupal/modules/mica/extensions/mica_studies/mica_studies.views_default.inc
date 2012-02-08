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
  $view->name = 'contact_csv_export';
  $view->description = 'Export of all Contacts in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contact CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name_1']['id'] = 'field_contact_name_1';
  $handler->display->display_options['fields']['field_contact_name_1']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_1']['label'] = 'contact_title';
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_1']['type'] = 'name_default_title';
  $handler->display->display_options['fields']['field_contact_name_1']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_contact_name_1']['field_api_classes'] = 0;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name_2']['id'] = 'field_contact_name_2';
  $handler->display->display_options['fields']['field_contact_name_2']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['label'] = 'given_name';
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_name_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_name_2']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_2']['type'] = 'name_default_given';
  $handler->display->display_options['fields']['field_contact_name_2']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_contact_name_2']['field_api_classes'] = 0;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'family_name';
  $handler->display->display_options['fields']['field_contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_name']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['field_contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name']['type'] = 'name_default_family';
  $handler->display->display_options['fields']['field_contact_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_contact_name']['field_api_classes'] = 0;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'email';
  $handler->display->display_options['fields']['field_contact_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['field_contact_email']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['field_api_classes'] = 0;
  /* Field: Content: Telephone */
  $handler->display->display_options['fields']['field_telephone']['id'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['table'] = 'field_data_field_telephone';
  $handler->display->display_options['fields']['field_telephone']['field'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['label'] = 'telephone';
  $handler->display->display_options['fields']['field_telephone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_telephone']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['field_telephone']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_telephone']['field_api_classes'] = 0;
  /* Field: Content: Institution Name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim_whitespace'] = 1;
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
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = 'address';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = 0;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_city']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['field_city']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_city']['field_api_classes'] = 0;
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_postal_code']['id'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['table'] = 'field_data_field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['field'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['label'] = 'postal_code';
  $handler->display->display_options['fields']['field_postal_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_postal_code']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['field_postal_code']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_postal_code']['field_api_classes'] = 0;
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = 'state';
  $handler->display->display_options['fields']['field_state']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_state']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_state']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_state']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_state']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_state']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_state']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_state']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_state']['field_api_classes'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_contact_country']['id'] = 'field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['table'] = 'field_data_field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['field'] = 'field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['label'] = 'country';
  $handler->display->display_options['fields']['field_contact_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_country']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_country']['type'] = 'country_alpha_2';
  $handler->display->display_options['fields']['field_contact_country']['field_api_classes'] = 0;
  /* Field: Content: Data Access Committee member */
  $handler->display->display_options['fields']['field_daco']['id'] = 'field_daco';
  $handler->display->display_options['fields']['field_daco']['table'] = 'field_data_field_daco';
  $handler->display->display_options['fields']['field_daco']['field'] = 'field_daco';
  $handler->display->display_options['fields']['field_daco']['label'] = 'data_access_committee_member';
  $handler->display->display_options['fields']['field_daco']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_daco']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_daco']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_daco']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_daco']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_daco']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_daco']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_daco']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_daco']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_daco']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'id';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 1;
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
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 1;
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
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'contact-csv';
  $translatables['contact_csv_export'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('contact_title'),
    t('given_name'),
    t('family_name'),
    t('email'),
    t('telephone'),
    t('institution'),
    t('address'),
    t('city'),
    t('postal_code'),
    t('state'),
    t('country'),
    t('data_access_committee_member'),
    t('id'),
    t('title'),
    t('published'),
    t('[status]'),
    t('Data export'),
  );
  $export['contact_csv_export'] = $view;

  $view = new view;
  $view->name = 'csv_study_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study CSV Export';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Complete name */
  $handler->display->display_options['fields']['field_complete_name']['id'] = 'field_complete_name';
  $handler->display->display_options['fields']['field_complete_name']['table'] = 'field_data_field_complete_name';
  $handler->display->display_options['fields']['field_complete_name']['field'] = 'field_complete_name';
  $handler->display->display_options['fields']['field_complete_name']['label'] = 'complete_name';
  $handler->display->display_options['fields']['field_complete_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_complete_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_complete_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_complete_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_complete_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_complete_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_complete_name']['field_api_classes'] = 0;
  /* Field: Content: Acronym */
  $handler->display->display_options['fields']['field_acroym']['id'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['table'] = 'field_data_field_acroym';
  $handler->display->display_options['fields']['field_acroym']['field'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['label'] = 'acronym';
  $handler->display->display_options['fields']['field_acroym']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_acroym']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_acroym']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_acroym']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_acroym']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_acroym']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_acroym']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_acroym']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_acroym']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_acroym']['field_api_classes'] = 0;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'website';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_website']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['field_api_classes'] = 0;
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_contacts_ref']['id'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['field'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['label'] = 'contacts';
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_contacts_ref']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_contacts_ref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contacts_ref']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_contacts_ref']['separator'] = ',';
  $handler->display->display_options['fields']['field_contacts_ref']['field_api_classes'] = 0;
  /* Field: Content: Investigators */
  $handler->display->display_options['fields']['field_investigators']['id'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['table'] = 'field_data_field_investigators';
  $handler->display->display_options['fields']['field_investigators']['field'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['label'] = 'investigators';
  $handler->display->display_options['fields']['field_investigators']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_investigators']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_investigators']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_investigators']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_investigators']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_investigators']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_investigators']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_investigators']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_investigators']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_investigators']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_investigators']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_investigators']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_investigators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_investigators']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_investigators']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_investigators']['separator'] = ',';
  $handler->display->display_options['fields']['field_investigators']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'objectives';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body_1']['field_api_classes'] = 0;
  /* Field: Content: Authorization Specific */
  $handler->display->display_options['fields']['field_authorization_specific']['id'] = 'field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['table'] = 'field_data_field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['field'] = 'field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['label'] = 'authorization_from_contributors_to_the_specific_network_catalogues';
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorization_specific']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorization_specific']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorization_specific']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorization_specific']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_authorization_specific']['field_api_classes'] = 0;
  /* Field: Content: Name of the person authorising the contribution to [SPECIFIC NETWORK] */
  $handler->display->display_options['fields']['field_authorising_person_name']['id'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['table'] = 'field_data_field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['field'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['label'] = 'name_of_the_person_authorising_the_contribution_to_specific_network';
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name']['field_api_classes'] = 0;
  /* Field: Content: Authorising date */
  $handler->display->display_options['fields']['field_authorising_date']['id'] = 'field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['table'] = 'field_data_field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['field'] = 'field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['label'] = 'authorization_date_from_contributors_to_the_specific_network_catalogues';
  $handler->display->display_options['fields']['field_authorising_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorising_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorising_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorising_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorising_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_authorising_date']['field_api_classes'] = 0;
  /* Field: Content: Authorization Maelstrom */
  $handler->display->display_options['fields']['field_authorization_maelstrom']['id'] = 'field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['table'] = 'field_data_field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['field'] = 'field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['label'] = 'authorization_from_contributors_to_the_maelstrom_catalogues';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorization_maelstrom']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['field_api_classes'] = 0;
  /* Field: Content: Name of the person authorising the contribution to Maelstrom Research */
  $handler->display->display_options['fields']['field_authorising_person_name_m']['id'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['table'] = 'field_data_field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['field'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['label'] = 'name_of_the_person_authorising_the_contribution_to_maelstrom_research';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorising_person_name_m']['field_api_classes'] = 0;
  /* Field: Content: Authorising date */
  $handler->display->display_options['fields']['field_authorising_date_m']['id'] = 'field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['table'] = 'field_data_field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['field'] = 'field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['label'] = 'authorization_date_from_contributors_to_the_maelstrom_catalogues';
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_authorising_date_m']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_authorising_date_m']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_authorising_date_m']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_authorising_date_m']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_authorising_date_m']['field_api_classes'] = 0;
  /* Field: Content: What is the baseline design of the study */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['label'] = 'baseline_design_of_the_study';
  $handler->display->display_options['fields']['field_design']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_design']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_design']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_design']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_design']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_design']['separator'] = ',';
  $handler->display->display_options['fields']['field_design']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['label'] = 'other_baseline_design_of_the_study';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_design_other_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_design_other_sp']['field_api_classes'] = 0;
  /* Field: Content: The study targets the recruitment of */
  $handler->display->display_options['fields']['field_recruitment']['id'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['table'] = 'field_data_field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['field'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['label'] = 'study_recruitment_targets';
  $handler->display->display_options['fields']['field_recruitment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_recruitment']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_recruitment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_recruitment']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_recruitment']['separator'] = ',';
  $handler->display->display_options['fields']['field_recruitment']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other recruitment target */
  $handler->display->display_options['fields']['field_recruitment_other_sp']['id'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['table'] = 'field_data_field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['field'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['label'] = 'other_recruitment_target';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other_sp']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_recruitment_supp_info']['id'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['table'] = 'field_data_field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['field'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['label'] = 'study_design_supplementary_information';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitment_supp_info']['field_api_classes'] = 0;
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'headline_number_of_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: No limits in the number of participants */
  $handler->display->display_options['fields']['field_no_limits_participants']['id'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['table'] = 'field_data_field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['field'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['label'] = 'no_limits_in_the_number_of_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_no_limits_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_no_limits_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_no_limits_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_no_limits_participants']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_no_limits_participants']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_target_nb_supp_info']['id'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['table'] = 'field_data_field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['field'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['label'] = 'target_number_of_participants_supplementary_information';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_nb_supp_info']['field_api_classes'] = 0;
  /* Field: Content: How many people have provided or should provide biological samples, from which DNA could be extracted? */
  $handler->display->display_options['fields']['field_target_number_biosamples']['id'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['label'] = 'headline_number_of_participants_with_samples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_biosamples']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_number_biosamples']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_target_number_biosamples']['field_api_classes'] = 0;
  /* Field: Content: No limits in the number of samples */
  $handler->display->display_options['fields']['field_no_limits_samples']['id'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['table'] = 'field_data_field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['field'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['label'] = 'no_limits_in_the_number_of_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_no_limits_samples']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_no_limits_samples']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_no_limits_samples']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_no_limits_samples']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_no_limits_samples']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_samples_supp_info']['id'] = 'field_samples_supp_info';
  $handler->display->display_options['fields']['field_samples_supp_info']['table'] = 'field_data_field_samples_supp_info';
  $handler->display->display_options['fields']['field_samples_supp_info']['field'] = 'field_samples_supp_info';
  $handler->display->display_options['fields']['field_samples_supp_info']['label'] = 'target_number_of_biological_samples_supplementary_information';
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_samples_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_samples_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_samples_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_samples_supp_info']['field_api_classes'] = 0;
  /* Field: Content: How many people have joined the study? */
  $handler->display->display_options['fields']['field_current_participants_nb']['id'] = 'field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['table'] = 'field_data_field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['field'] = 'field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['label'] = 'current_number_of_participants_recruited';
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_participants_nb']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_participants_nb']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_participants_nb']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_participants_nb']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_current_participants_nb']['field_api_classes'] = 0;
  /* Field: Content: In date of */
  $handler->display->display_options['fields']['field_current_part_nb_date']['id'] = 'field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['table'] = 'field_data_field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['field'] = 'field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['label'] = 'date_of_current_number_of_participants_recruited_at_baseline';
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_part_nb_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_part_nb_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_part_nb_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_part_nb_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_current_part_nb_date']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_current_supp_info']['id'] = 'field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['table'] = 'field_data_field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['field'] = 'field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['label'] = 'current_number_of_participants_recruited_at_baseline_supplementary_information';
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_supp_info']['field_api_classes'] = 0;
  /* Field: Content: For how many people have biological samples been collected? */
  $handler->display->display_options['fields']['field_current_samples_nb']['id'] = 'field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['table'] = 'field_data_field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['field'] = 'field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['label'] = 'current_number_of_collected_biological_samples';
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_samples_nb']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_samples_nb']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_samples_nb']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_samples_nb']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_current_samples_nb']['field_api_classes'] = 0;
  /* Field: Content: In date of */
  $handler->display->display_options['fields']['field_current_samples_date']['id'] = 'field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['table'] = 'field_data_field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['field'] = 'field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['label'] = 'date_of_current_number_of_collected_biological_samples';
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_samples_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_samples_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_samples_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_samples_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_current_samples_date']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_current_sam_supp_info']['id'] = 'field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['table'] = 'field_data_field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['field'] = 'field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['label'] = 'current_number_of_collected_biological_samples_supplementary_information';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_current_sam_supp_info']['field_api_classes'] = 0;
  /* Field: Content: What are the inclusion criteria for participants’ selection */
  $handler->display->display_options['fields']['field_select_criteria']['id'] = 'field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['table'] = 'field_data_field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['field'] = 'field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['label'] = 'study_inclusion_criteria_for_participants_selection';
  $handler->display->display_options['fields']['field_select_criteria']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_select_criteria']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_select_criteria']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_select_criteria']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_select_criteria']['separator'] = ',';
  $handler->display->display_options['fields']['field_select_criteria']['field_api_classes'] = 0;
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_selection_gender']['id'] = 'field_selection_gender';
  $handler->display->display_options['fields']['field_selection_gender']['table'] = 'field_data_field_selection_gender';
  $handler->display->display_options['fields']['field_selection_gender']['field'] = 'field_selection_gender';
  $handler->display->display_options['fields']['field_selection_gender']['label'] = 'gender';
  $handler->display->display_options['fields']['field_selection_gender']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_selection_gender']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_selection_gender']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_selection_gender']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_selection_gender']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_selection_gender']['field_api_classes'] = 0;
  /* Field: Content: Age min */
  $handler->display->display_options['fields']['field_age_min']['id'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['table'] = 'field_data_field_age_min';
  $handler->display->display_options['fields']['field_age_min']['field'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['label'] = 'age_min';
  $handler->display->display_options['fields']['field_age_min']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_age_min']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_age_min']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_age_min']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_age_min']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_age_min']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_age_min']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_age_min']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_age_min']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_age_min']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_age_min']['field_api_classes'] = 0;
  /* Field: Content: Age max */
  $handler->display->display_options['fields']['field_age_max']['id'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['table'] = 'field_data_field_age_max';
  $handler->display->display_options['fields']['field_age_max']['field'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['label'] = 'age_max';
  $handler->display->display_options['fields']['field_age_max']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_age_max']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_age_max']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_age_max']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_age_max']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_age_max']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_age_max']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_age_max']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_age_max']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_age_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_age_max']['field_api_classes'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = 'country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_country']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_country']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_country']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_country']['separator'] = ',';
  $handler->display->display_options['fields']['field_country']['field_api_classes'] = 0;
  /* Field: Content: Territory */
  $handler->display->display_options['fields']['field_territory']['id'] = 'field_territory';
  $handler->display->display_options['fields']['field_territory']['table'] = 'field_data_field_territory';
  $handler->display->display_options['fields']['field_territory']['field'] = 'field_territory';
  $handler->display->display_options['fields']['field_territory']['label'] = 'territory';
  $handler->display->display_options['fields']['field_territory']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_territory']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_territory']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_territory']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_territory']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_territory']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_territory']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_territory']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_territory']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_territory']['field_api_classes'] = 0;
  /* Field: Content: Ethnic origin */
  $handler->display->display_options['fields']['field_ethnic_origin']['id'] = 'field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['table'] = 'field_data_field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['field'] = 'field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['label'] = 'ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_ethnic_origin']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ethnic_origin']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_ethnic_origin']['separator'] = ',';
  $handler->display->display_options['fields']['field_ethnic_origin']['field_api_classes'] = 0;
  /* Field: Content: Health status */
  $handler->display->display_options['fields']['field_health_status']['id'] = 'field_health_status';
  $handler->display->display_options['fields']['field_health_status']['table'] = 'field_data_field_health_status';
  $handler->display->display_options['fields']['field_health_status']['field'] = 'field_health_status';
  $handler->display->display_options['fields']['field_health_status']['label'] = 'health_status';
  $handler->display->display_options['fields']['field_health_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_health_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_health_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_health_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_health_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_health_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_health_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_health_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_health_status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_health_status']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_health_status']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_health_status']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_health_status']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_health_status']['separator'] = ',';
  $handler->display->display_options['fields']['field_health_status']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other selection criteria */
  $handler->display->display_options['fields']['field_selection_others_sp']['id'] = 'field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['table'] = 'field_data_field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['field'] = 'field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['label'] = 'other_selection_criteria';
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_selection_others_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_selection_others_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_selection_others_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_selection_others_sp']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['id'] = 'field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['table'] = 'field_data_field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['field'] = 'field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['label'] = 'selection_criteria_supplementary_information';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['field_api_classes'] = 0;
  /* Field: Content: Specify the sources of recruitment */
  $handler->display->display_options['fields']['field_recruitment_procedures']['id'] = 'field_recruitment_procedures';
  $handler->display->display_options['fields']['field_recruitment_procedures']['table'] = 'field_data_field_recruitment_procedures';
  $handler->display->display_options['fields']['field_recruitment_procedures']['field'] = 'field_recruitment_procedures';
  $handler->display->display_options['fields']['field_recruitment_procedures']['label'] = 'sources_of_recruitment';
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_recruitment_procedures']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_recruitment_procedures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_recruitment_procedures']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_recruitment_procedures']['separator'] = ',';
  $handler->display->display_options['fields']['field_recruitment_procedures']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other source of recruitment */
  $handler->display->display_options['fields']['field_recruitment_other']['id'] = 'field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['table'] = 'field_data_field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['field'] = 'field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['label'] = 'other_sources_of_recruitment';
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitment_other']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitment_other']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_recruitement_supp_info']['id'] = 'field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['table'] = 'field_data_field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['field'] = 'field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['label'] = 'recruitment_procedures_supplementary_information';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recruitement_supp_info']['field_api_classes'] = 0;
  /* Field: Content: Data Sources */
  $handler->display->display_options['fields']['field_data_sources']['id'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['field'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['label'] = 'data_sources';
  $handler->display->display_options['fields']['field_data_sources']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_data_sources']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_data_sources']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_data_sources']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_data_sources']['separator'] = ',';
  $handler->display->display_options['fields']['field_data_sources']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other data sources */
  $handler->display->display_options['fields']['field_data_sources_sp']['id'] = 'field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['table'] = 'field_data_field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['field'] = 'field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['label'] = 'other_data_sources';
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_data_sources_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_data_sources_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_data_sources_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_data_sources_sp']['field_api_classes'] = 0;
  /* Field: Content: Biological samples */
  $handler->display->display_options['fields']['field_bio_samples_management']['id'] = 'field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['table'] = 'field_data_field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['field'] = 'field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['label'] = 'biological_samples';
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_bio_samples_management']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_bio_samples_management']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bio_samples_management']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_bio_samples_management']['separator'] = ',';
  $handler->display->display_options['fields']['field_bio_samples_management']['field_api_classes'] = 0;
  /* Field: Content: Please specify type of tissues */
  $handler->display->display_options['fields']['field_tissues_sp']['id'] = 'field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['table'] = 'field_data_field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['field'] = 'field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['label'] = 'other_type_of_tissues';
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_tissues_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tissues_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tissues_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_tissues_sp']['field_api_classes'] = 0;
  /* Field: Content: Please specify what other biological samples */
  $handler->display->display_options['fields']['field_samples_man_other_sp']['id'] = 'field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['table'] = 'field_data_field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['field'] = 'field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['label'] = 'other_sample_management';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_samples_man_other_sp']['field_api_classes'] = 0;
  /* Field: Content: Data (questionnaire-derived, measured…) */
  $handler->display->display_options['fields']['field_access_data']['id'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['table'] = 'field_data_field_access_data';
  $handler->display->display_options['fields']['field_access_data']['field'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['label'] = 'data_access';
  $handler->display->display_options['fields']['field_access_data']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access_data']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access_data']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access_data']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access_data']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access_data']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access_data']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access_data']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access_data']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_access_data']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_access_data']['field_api_classes'] = 0;
  /* Field: Content: Biological samples */
  $handler->display->display_options['fields']['field_access_biosamples']['id'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['table'] = 'field_data_field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['field'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['label'] = 'biological_samples_access';
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access_biosamples']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access_biosamples']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access_biosamples']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_access_biosamples']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_access_biosamples']['field_api_classes'] = 0;
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_access_other']['id'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['table'] = 'field_data_field_access_other';
  $handler->display->display_options['fields']['field_access_other']['field'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['label'] = 'other_access';
  $handler->display->display_options['fields']['field_access_other']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access_other']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access_other']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access_other']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access_other']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access_other']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access_other']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access_other']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access_other']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_access_other']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_access_other']['field_api_classes'] = 0;
  /* Field: Content: Please specify what study feature */
  $handler->display->display_options['fields']['field_access_other_sp']['id'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['table'] = 'field_data_field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['field'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['label'] = 'access_supplementary_information';
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_access_other_sp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_access_other_sp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_access_other_sp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_access_other_sp']['field_api_classes'] = 0;
  /* Field: Content: Start year */
  $handler->display->display_options['fields']['field_preparation_start_year']['id'] = 'field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['table'] = 'field_data_field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['field'] = 'field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['label'] = 'preparation_phase_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_preparation_start_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_preparation_start_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_preparation_start_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_preparation_start_year']['field_api_classes'] = 0;
  /* Field: Content: End year */
  $handler->display->display_options['fields']['field_preparation_end_year']['id'] = 'field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['table'] = 'field_data_field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['field'] = 'field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['label'] = 'preparation_phase_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_preparation_end_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_preparation_end_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_preparation_end_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_preparation_end_year']['field_api_classes'] = 0;
  /* Field: Content: Start year */
  $handler->display->display_options['fields']['field_baseline_start_year']['id'] = 'field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['table'] = 'field_data_field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['field'] = 'field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['label'] = 'baseline_recruitment_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_baseline_start_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_baseline_start_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_baseline_start_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_baseline_start_year']['field_api_classes'] = 0;
  /* Field: Content: End year */
  $handler->display->display_options['fields']['field_baseline_end_year']['id'] = 'field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['table'] = 'field_data_field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['field'] = 'field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['label'] = 'baseline_recruitment_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_baseline_end_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_baseline_end_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_baseline_end_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_baseline_end_year']['field_api_classes'] = 0;
  /* Field: Content: Start year */
  $handler->display->display_options['fields']['field_followup_start_year']['id'] = 'field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['table'] = 'field_data_field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['field'] = 'field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['label'] = 'followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_followup_start_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_followup_start_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_followup_start_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_followup_start_year']['field_api_classes'] = 0;
  /* Field: Content: End year */
  $handler->display->display_options['fields']['field_followup_end_year']['id'] = 'field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['table'] = 'field_data_field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['field'] = 'field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['label'] = 'followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_followup_end_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_followup_end_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_followup_end_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_followup_end_year']['field_api_classes'] = 0;
  /* Field: Content: End year */
  $handler->display->display_options['fields']['field_ended_end_year']['id'] = 'field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['table'] = 'field_data_field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['field'] = 'field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['label'] = 'study_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ended_end_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ended_end_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ended_end_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ended_end_year']['field_api_classes'] = 0;
  /* Field: Content: If needed, supplementary information */
  $handler->display->display_options['fields']['field_status_supp_info']['id'] = 'field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['table'] = 'field_data_field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['field'] = 'field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['label'] = 'current_status_supplementary_information';
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_status_supp_info']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_status_supp_info']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_status_supp_info']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_status_supp_info']['field_api_classes'] = 0;
  /* Field: Content: Supplementary information */
  $handler->display->display_options['fields']['field_supp_infos']['id'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['table'] = 'field_data_field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['field'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['label'] = 'supplementary_information';
  $handler->display->display_options['fields']['field_supp_infos']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_supp_infos']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_supp_infos']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_supp_infos']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_supp_infos']['field_api_classes'] = 0;
  /* Field: Content: Marker paper describing your study */
  $handler->display->display_options['fields']['field_marker_paper']['id'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['table'] = 'field_data_field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['field'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['label'] = 'marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_marker_paper']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_marker_paper']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_marker_paper']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_marker_paper']['field_api_classes'] = 0;
  /* Field: Content: Pubmed Id */
  $handler->display->display_options['fields']['field_pubmedid']['id'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['table'] = 'field_data_field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['field'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['label'] = 'pubmed_id';
  $handler->display->display_options['fields']['field_pubmedid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_pubmedid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_pubmedid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_pubmedid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_pubmedid']['field_api_classes'] = 0;
  /* Field: Content: Documents */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['label'] = 'documents';
  $handler->display->display_options['fields']['field_documents']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_documents']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_documents']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_documents']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_documents']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_documents']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_documents']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_documents']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_documents']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_documents']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_documents']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_documents']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_documents']['separator'] = ',';
  $handler->display->display_options['fields']['field_documents']['field_api_classes'] = 0;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = 'logo';
  $handler->display->display_options['fields']['field_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_logo']['field_api_classes'] = 0;
  /* Field: Content: Opal */
  $handler->display->display_options['fields']['mica_opal']['id'] = 'mica_opal';
  $handler->display->display_options['fields']['mica_opal']['table'] = 'field_data_mica_opal';
  $handler->display->display_options['fields']['mica_opal']['field'] = 'mica_opal';
  $handler->display->display_options['fields']['mica_opal']['label'] = 'opal';
  $handler->display->display_options['fields']['mica_opal']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mica_opal']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mica_opal']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mica_opal']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mica_opal']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['mica_opal']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mica_opal']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mica_opal']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mica_opal']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['mica_opal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['mica_opal']['field_api_classes'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
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
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'csv-study';
  $handler->display->display_options['use_batch'] = '1';
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
    t('- All - '),
    t('Offset'),
    t('complete_name'),
    t('acronym'),
    t('website'),
    t('contacts'),
    t('investigators'),
    t('objectives'),
    t('authorization_from_contributors_to_the_specific_network_catalogues'),
    t('name_of_the_person_authorising_the_contribution_to_specific_network'),
    t('authorization_date_from_contributors_to_the_specific_network_catalogues'),
    t('authorization_from_contributors_to_the_maelstrom_catalogues'),
    t('name_of_the_person_authorising_the_contribution_to_maelstrom_research'),
    t('authorization_date_from_contributors_to_the_maelstrom_catalogues'),
    t('baseline_design_of_the_study'),
    t('other_baseline_design_of_the_study'),
    t('study_recruitment_targets'),
    t('other_recruitment_target'),
    t('study_design_supplementary_information'),
    t('headline_number_of_participants'),
    t('no_limits_in_the_number_of_participants'),
    t('target_number_of_participants_supplementary_information'),
    t('headline_number_of_participants_with_samples'),
    t('no_limits_in_the_number_of_samples'),
    t('target_number_of_biological_samples_supplementary_information'),
    t('current_number_of_participants_recruited'),
    t('date_of_current_number_of_participants_recruited_at_baseline'),
    t('current_number_of_participants_recruited_at_baseline_supplementary_information'),
    t('current_number_of_collected_biological_samples'),
    t('date_of_current_number_of_collected_biological_samples'),
    t('current_number_of_collected_biological_samples_supplementary_information'),
    t('study_inclusion_criteria_for_participants_selection'),
    t('gender'),
    t('age_min'),
    t('age_max'),
    t('country'),
    t('territory'),
    t('ethnic_origin'),
    t('health_status'),
    t('other_selection_criteria'),
    t('selection_criteria_supplementary_information'),
    t('sources_of_recruitment'),
    t('other_sources_of_recruitment'),
    t('recruitment_procedures_supplementary_information'),
    t('data_sources'),
    t('other_data_sources'),
    t('biological_samples'),
    t('other_type_of_tissues'),
    t('other_sample_management'),
    t('data_access'),
    t('biological_samples_access'),
    t('other_access'),
    t('access_supplementary_information'),
    t('preparation_phase_start_year'),
    t('preparation_phase_end_year'),
    t('baseline_recruitment_start_year'),
    t('baseline_recruitment_end_year'),
    t('followup_start_year'),
    t('followup_end_year'),
    t('study_end_year'),
    t('current_status_supplementary_information'),
    t('supplementary_information'),
    t('marker_paper'),
    t('pubmed_id'),
    t('documents'),
    t('logo'),
    t('opal'),
    t('published'),
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
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
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
    t('empty_documents'),
    t('No document found.'),
    t('Name'),
    t('Description'),
    t('Download'),
    t('Page'),
  );
  $export['documents'] = $view;

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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
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
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
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
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
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
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
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
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_country']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_country']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_country']['field_api_classes'] = 0;
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
    t('Studies'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
    t('This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies. 

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>'),
    t('empty_studies'),
    t('No study found.'),
    t('Name'),
    t('Target number of participants'),
    t('Country'),
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
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
  /* Field: Indexed Node: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
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
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_target_number_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_target_number_participants']['field_api_classes'] = 0;
  /* Field: Indexed Node: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country']['alter']['trim_whitespace'] = 0;
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
  $handler->display->display_options['fields']['field_country']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_country']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_country']['field_api_classes'] = 0;
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
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    0 => '0',
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
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All - '),
    t('Offset'),
    t('empty_studies'),
    t('No study found.'),
    t('Name'),
    t('Target number of participants'),
    t('Country'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['studies_search'] = $view;

  return $export;
}
