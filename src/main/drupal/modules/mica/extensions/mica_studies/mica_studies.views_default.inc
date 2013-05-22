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

  $view = new view();
  $view->name = 'contact_csv_export';
  $view->description = 'Export of all Contacts in CSV';
  $view->tag = 'csv';
  $view->base_table = 'node';
  $view->human_name = 'Contact CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['fields']['field_contact_name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_1']['type'] = 'name_default_title';
  $handler->display->display_options['fields']['field_contact_name_1']['settings'] = array(
    'markup' => 0,
  );
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name_2']['id'] = 'field_contact_name_2';
  $handler->display->display_options['fields']['field_contact_name_2']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name_2']['label'] = 'given_name';
  $handler->display->display_options['fields']['field_contact_name_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_contact_name_2']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name_2']['type'] = 'name_default_given';
  $handler->display->display_options['fields']['field_contact_name_2']['settings'] = array(
    'markup' => 0,
  );
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'family_name';
  $handler->display->display_options['fields']['field_contact_name']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_contact_name']['type'] = 'name_default_family';
  $handler->display->display_options['fields']['field_contact_name']['settings'] = array(
    'markup' => 0,
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'email';
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Telephone */
  $handler->display->display_options['fields']['field_telephone']['id'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['table'] = 'field_data_field_telephone';
  $handler->display->display_options['fields']['field_telephone']['field'] = 'field_telephone';
  $handler->display->display_options['fields']['field_telephone']['label'] = 'telephone';
  $handler->display->display_options['fields']['field_telephone']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Institution name */
  $handler->display->display_options['fields']['field_institution_name']['id'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['table'] = 'field_data_field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['field'] = 'field_institution_name';
  $handler->display->display_options['fields']['field_institution_name']['label'] = 'institution';
  $handler->display->display_options['fields']['field_institution_name']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = 'address';
  $handler->display->display_options['fields']['field_address']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = 'city';
  $handler->display->display_options['fields']['field_city']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_postal_code']['id'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['table'] = 'field_data_field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['field'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['label'] = 'postal_code';
  $handler->display->display_options['fields']['field_postal_code']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = 'state';
  $handler->display->display_options['fields']['field_state']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_contact_country']['id'] = 'field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['table'] = 'field_data_field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['field'] = 'field_contact_country';
  $handler->display->display_options['fields']['field_contact_country']['label'] = 'country';
  $handler->display->display_options['fields']['field_contact_country']['type'] = 'country_alpha_2';
  /* Field: Content: Data Access Committee member */
  $handler->display->display_options['fields']['field_daco']['id'] = 'field_daco';
  $handler->display->display_options['fields']['field_daco']['table'] = 'field_data_field_daco';
  $handler->display->display_options['fields']['field_daco']['field'] = 'field_daco';
  $handler->display->display_options['fields']['field_daco']['label'] = 'data_access_committee_member';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $export['contact_csv_export'] = $view;

  $view = new view();
  $view->name = 'csv_study_export';
  $view->description = 'Export of all studies in CSV';
  $view->tag = 'csv,study';
  $view->base_table = 'node';
  $view->human_name = 'Study CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSV Study Export';
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
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  /* Field: Content: Acronym */
  $handler->display->display_options['fields']['field_acroym']['id'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['table'] = 'field_data_field_acroym';
  $handler->display->display_options['fields']['field_acroym']['field'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['label'] = 'acronym';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_contacts_ref']['id'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['field'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['label'] = 'contacts';
  $handler->display->display_options['fields']['field_contacts_ref']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_contacts_ref']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_contacts_ref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contacts_ref']['separator'] = '|';
  /* Field: Content: Investigators */
  $handler->display->display_options['fields']['field_investigators']['id'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['table'] = 'field_data_field_investigators';
  $handler->display->display_options['fields']['field_investigators']['field'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['label'] = 'investigators';
  $handler->display->display_options['fields']['field_investigators']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_investigators']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_investigators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_investigators']['separator'] = '|';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'objectives';
  $handler->display->display_options['fields']['body_1']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Authorization Specific */
  $handler->display->display_options['fields']['field_authorization_specific']['id'] = 'field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['table'] = 'field_data_field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['field'] = 'field_authorization_specific';
  $handler->display->display_options['fields']['field_authorization_specific']['label'] = 'authorization_from_contributors_to_the_specific_network_catalogues';
  $handler->display->display_options['fields']['field_authorization_specific']['type'] = 'list_key';
  /* Field: Content: Name of the person authorising the contribution to [SPECIFIC NETWORK] */
  $handler->display->display_options['fields']['field_authorising_person_name']['id'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['table'] = 'field_data_field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['field'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['label'] = 'name_of_the_person_authorising_the_contribution_to_specific_network';
  /* Field: Content: Authorising date */
  $handler->display->display_options['fields']['field_authorising_date']['id'] = 'field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['table'] = 'field_data_field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['field'] = 'field_authorising_date';
  $handler->display->display_options['fields']['field_authorising_date']['label'] = 'authorization_date_from_contributors_to_the_specific_network_catalogues';
  $handler->display->display_options['fields']['field_authorising_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Authorization Maelstrom */
  $handler->display->display_options['fields']['field_authorization_maelstrom']['id'] = 'field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['table'] = 'field_data_field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['field'] = 'field_authorization_maelstrom';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['label'] = 'authorization_from_contributors_to_the_maelstrom_catalogues';
  $handler->display->display_options['fields']['field_authorization_maelstrom']['type'] = 'list_key';
  /* Field: Content: Name of the person authorising the contribution to Maelstrom Research */
  $handler->display->display_options['fields']['field_authorising_person_name_m']['id'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['table'] = 'field_data_field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['field'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['label'] = 'name_of_the_person_authorising_the_contribution_to_maelstrom_research';
  /* Field: Content: Authorising date */
  $handler->display->display_options['fields']['field_authorising_date_m']['id'] = 'field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['table'] = 'field_data_field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['field'] = 'field_authorising_date_m';
  $handler->display->display_options['fields']['field_authorising_date_m']['label'] = 'authorization_date_from_contributors_to_the_maelstrom_catalogues';
  $handler->display->display_options['fields']['field_authorising_date_m']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['label'] = 'baseline_design_of_the_study';
  $handler->display->display_options['fields']['field_design']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_design']['separator'] = ',';
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['label'] = 'other_baseline_design_of_the_study';
  /* Field: Content: Recruitment target */
  $handler->display->display_options['fields']['field_recruitment']['id'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['table'] = 'field_data_field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['field'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['label'] = 'study_recruitment_targets';
  $handler->display->display_options['fields']['field_recruitment']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_recruitment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_recruitment']['separator'] = ',';
  /* Field: Content: Other recruitment target */
  $handler->display->display_options['fields']['field_recruitment_other_sp']['id'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['table'] = 'field_data_field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['field'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['label'] = 'other_recruitment_target';
  /* Field: Content: Supplementary information about study design */
  $handler->display->display_options['fields']['field_recruitment_supp_info']['id'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['table'] = 'field_data_field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['field'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['label'] = 'study_design_supplementary_information';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'headline_number_of_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: No limits in the number of participants */
  $handler->display->display_options['fields']['field_no_limits_participants']['id'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['table'] = 'field_data_field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['field'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['label'] = 'no_limits_in_the_number_of_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['type'] = 'list_key';
  /* Field: Content: Supplementary information about target number of participants */
  $handler->display->display_options['fields']['field_target_nb_supp_info']['id'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['table'] = 'field_data_field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['field'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['label'] = 'target_number_of_participants_supplementary_information';
  /* Field: Content: Target number of participants with biological samples */
  $handler->display->display_options['fields']['field_target_number_biosamples']['id'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['label'] = 'headline_number_of_participants_with_samples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: No limits in the number of samples */
  $handler->display->display_options['fields']['field_no_limits_samples']['id'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['table'] = 'field_data_field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['field'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['label'] = 'no_limits_in_the_number_of_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_participants_nb']['id'] = 'field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['table'] = 'field_data_field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['field'] = 'field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['label'] = 'current_number_of_participants_recruited';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_part_nb_date']['id'] = 'field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['table'] = 'field_data_field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['field'] = 'field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['label'] = 'date_of_current_number_of_participants_recruited_at_baseline';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_supp_info']['id'] = 'field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['table'] = 'field_data_field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['field'] = 'field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['label'] = 'current_number_of_participants_recruited_at_baseline_supplementary_information';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_samples_nb']['id'] = 'field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['table'] = 'field_data_field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['field'] = 'field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['label'] = 'current_number_of_collected_biological_samples';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_samples_date']['id'] = 'field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['table'] = 'field_data_field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['field'] = 'field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['label'] = 'date_of_current_number_of_collected_biological_samples';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_sam_supp_info']['id'] = 'field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['table'] = 'field_data_field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['field'] = 'field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['label'] = 'current_number_of_collected_biological_samples_supplementary_information';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_select_criteria']['id'] = 'field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['table'] = 'field_data_field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['field'] = 'field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['label'] = 'study_inclusion_criteria_for_participants_selection';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_age_min']['id'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['table'] = 'field_data_field_age_min';
  $handler->display->display_options['fields']['field_age_min']['field'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['label'] = 'age_min';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_age_max']['id'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['table'] = 'field_data_field_age_max';
  $handler->display->display_options['fields']['field_age_max']['field'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['label'] = 'age_max';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = 'country';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_territory']['id'] = 'field_territory';
  $handler->display->display_options['fields']['field_territory']['table'] = 'field_data_field_territory';
  $handler->display->display_options['fields']['field_territory']['field'] = 'field_territory';
  $handler->display->display_options['fields']['field_territory']['label'] = 'territory';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_ethnic_origin']['id'] = 'field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['table'] = 'field_data_field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['field'] = 'field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['label'] = 'ethnic_origin';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_health_status']['id'] = 'field_health_status';
  $handler->display->display_options['fields']['field_health_status']['table'] = 'field_data_field_health_status';
  $handler->display->display_options['fields']['field_health_status']['field'] = 'field_health_status';
  $handler->display->display_options['fields']['field_health_status']['label'] = 'health_status';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_selection_others_sp']['id'] = 'field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['table'] = 'field_data_field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['field'] = 'field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['label'] = 'other_selection_criteria';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['id'] = 'field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['table'] = 'field_data_field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['field'] = 'field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['label'] = 'selection_criteria_supplementary_information';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_recruitment_other']['id'] = 'field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['table'] = 'field_data_field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['field'] = 'field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['label'] = 'other_sources_of_recruitment';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_recruitement_supp_info']['id'] = 'field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['table'] = 'field_data_field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['field'] = 'field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['label'] = 'recruitment_procedures_supplementary_information';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_data_sources']['id'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['field'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['label'] = 'data_sources';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_data_sources_sp']['id'] = 'field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['table'] = 'field_data_field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['field'] = 'field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['label'] = 'other_data_sources';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bio_samples_management']['id'] = 'field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['table'] = 'field_data_field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['field'] = 'field_bio_samples_management';
  $handler->display->display_options['fields']['field_bio_samples_management']['label'] = 'biological_samples';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tissues_sp']['id'] = 'field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['table'] = 'field_data_field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['field'] = 'field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['label'] = 'other_type_of_tissues';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_samples_man_other_sp']['id'] = 'field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['table'] = 'field_data_field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['field'] = 'field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['label'] = 'other_sample_management';
  /* Field: Content: Data (questionnaire-derived, measured...) */
  $handler->display->display_options['fields']['field_access_data']['id'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['table'] = 'field_data_field_access_data';
  $handler->display->display_options['fields']['field_access_data']['field'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['label'] = 'data_access';
  $handler->display->display_options['fields']['field_access_data']['type'] = 'list_key';
  /* Field: Content: Biological samples */
  $handler->display->display_options['fields']['field_access_biosamples']['id'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['table'] = 'field_data_field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['field'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['label'] = 'biological_samples_access';
  $handler->display->display_options['fields']['field_access_biosamples']['type'] = 'list_key';
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_access_other']['id'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['table'] = 'field_data_field_access_other';
  $handler->display->display_options['fields']['field_access_other']['field'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['label'] = 'other_access';
  $handler->display->display_options['fields']['field_access_other']['type'] = 'list_key';
  /* Field: Content: Other access */
  $handler->display->display_options['fields']['field_access_other_sp']['id'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['table'] = 'field_data_field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['field'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['label'] = 'access_supplementary_information';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_preparation_start_year']['id'] = 'field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['table'] = 'field_data_field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['field'] = 'field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['label'] = 'preparation_phase_start_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_preparation_end_year']['id'] = 'field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['table'] = 'field_data_field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['field'] = 'field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['label'] = 'preparation_phase_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_baseline_start_year']['id'] = 'field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['table'] = 'field_data_field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['field'] = 'field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['label'] = 'baseline_recruitment_start_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_baseline_end_year']['id'] = 'field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['table'] = 'field_data_field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['field'] = 'field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['label'] = 'baseline_recruitment_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_followup_start_year']['id'] = 'field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['table'] = 'field_data_field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['field'] = 'field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['label'] = 'followup_start_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_followup_end_year']['id'] = 'field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['table'] = 'field_data_field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['field'] = 'field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['label'] = 'followup_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_ended_end_year']['id'] = 'field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['table'] = 'field_data_field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['field'] = 'field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['label'] = 'study_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_status_supp_info']['id'] = 'field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['table'] = 'field_data_field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['field'] = 'field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['label'] = 'current_status_supplementary_information';
  /* Field: Content: Supplementary information */
  $handler->display->display_options['fields']['field_supp_infos']['id'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['table'] = 'field_data_field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['field'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['label'] = 'supplementary_information';
  /* Field: Content: Marker paper */
  $handler->display->display_options['fields']['field_marker_paper']['id'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['table'] = 'field_data_field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['field'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['label'] = 'marker_paper';
  /* Field: Content: Pubmed ID */
  $handler->display->display_options['fields']['field_pubmedid']['id'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['table'] = 'field_data_field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['field'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['label'] = 'pubmed_id';
  /* Field: Content: Documents */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['label'] = 'documents';
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_documents']['separator'] = ',';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = 'logo';
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Opal */
  $handler->display->display_options['fields']['mica_opal']['id'] = 'mica_opal';
  $handler->display->display_options['fields']['mica_opal']['table'] = 'field_data_mica_opal';
  $handler->display->display_options['fields']['mica_opal']['field'] = 'mica_opal';
  $handler->display->display_options['fields']['mica_opal']['label'] = 'opal';
  $handler->display->display_options['fields']['mica_opal']['click_sort_column'] = 'url';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = 'gender';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'csv-study-html';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '1';
  $export['csv_study_export'] = $view;

  $view = new view();
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
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_documents';
  $handler->display->display_options['empty']['area']['content'] = 'No document found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Files */
  $handler->display->display_options['fields']['field_files']['id'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['table'] = 'field_data_field_files';
  $handler->display->display_options['fields']['field_files']['field'] = 'field_files';
  $handler->display->display_options['fields']['field_files']['label'] = 'Download';
  $handler->display->display_options['fields']['field_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_files']['multi_type'] = 'ol';
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'documents';
  $export['documents'] = $view;

  $view = new view();
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
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_news';
  $handler->display->display_options['empty']['area']['content'] = 'No news found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'news';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'recent_news');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['news'] = $view;

  $view = new view();
  $view->name = 'studies';
  $view->description = '';
  $view->tag = 'study';
  $view->base_table = 'node';
  $view->human_name = 'Studies';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All - ';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title_field' => 'title_field',
    'field_design_other_sp' => 'field_design_other_sp',
    'field_design' => 'field_design',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
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
      'sortable' => 0,
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
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies. 

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_studies';
  $handler->display->display_options['empty']['area']['content'] = 'No study found.';
  /* Relationship: Content: Populations (field_study_populations) */
  $handler->display->display_options['relationships']['field_study_populations_nid']['id'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['table'] = 'field_data_field_study_populations';
  $handler->display->display_options['relationships']['field_study_populations_nid']['field'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['label'] = '';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['element_label_colon'] = FALSE;
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp]';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Field: Content: Acronym */
  $handler->display->display_options['fields']['field_acroym']['id'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['table'] = 'field_data_field_acroym';
  $handler->display->display_options['fields']['field_acroym']['field'] = 'field_acroym';
  /* Field: Content: Biological samples */
  $handler->display->display_options['fields']['field_access_biosamples']['id'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['table'] = 'field_data_field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['field'] = 'field_access_biosamples';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_contacts_ref']['id'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['field'] = 'field_contacts_ref';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_country_1']['id'] = 'field_country_1';
  $handler->display->display_options['fields']['field_country_1']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country_1']['field'] = 'field_country';
  /* Field: Content: Data (questionnaire-derived, measured...) */
  $handler->display->display_options['fields']['field_access_data']['id'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['table'] = 'field_data_field_access_data';
  $handler->display->display_options['fields']['field_access_data']['field'] = 'field_access_data';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_data_sources']['id'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['field'] = 'field_data_sources';
  /* Field: Content: Datasets */
  $handler->display->display_options['fields']['mica_dataset']['id'] = 'mica_dataset';
  $handler->display->display_options['fields']['mica_dataset']['table'] = 'field_data_mica_dataset';
  $handler->display->display_options['fields']['mica_dataset']['field'] = 'mica_dataset';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_followup_end_year']['id'] = 'field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['table'] = 'field_data_field_followup_end_year';
  $handler->display->display_options['fields']['field_followup_end_year']['field'] = 'field_followup_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_ended_end_year']['id'] = 'field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['table'] = 'field_data_field_ended_end_year';
  $handler->display->display_options['fields']['field_ended_end_year']['field'] = 'field_ended_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_preparation_end_year']['id'] = 'field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['table'] = 'field_data_field_preparation_end_year';
  $handler->display->display_options['fields']['field_preparation_end_year']['field'] = 'field_preparation_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_baseline_end_year']['id'] = 'field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['table'] = 'field_data_field_baseline_end_year';
  $handler->display->display_options['fields']['field_baseline_end_year']['field'] = 'field_baseline_end_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_ethnic_origin']['id'] = 'field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['table'] = 'field_data_field_ethnic_origin';
  $handler->display->display_options['fields']['field_ethnic_origin']['field'] = 'field_ethnic_origin';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_samples_nb']['id'] = 'field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['table'] = 'field_data_field_current_samples_nb';
  $handler->display->display_options['fields']['field_current_samples_nb']['field'] = 'field_current_samples_nb';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_health_status']['id'] = 'field_health_status';
  $handler->display->display_options['fields']['field_health_status']['table'] = 'field_data_field_health_status';
  $handler->display->display_options['fields']['field_health_status']['field'] = 'field_health_status';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants_1']['id'] = 'field_target_number_participants_1';
  $handler->display->display_options['fields']['field_target_number_participants_1']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants_1']['field'] = 'field_target_number_participants';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_participants_nb']['id'] = 'field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['table'] = 'field_data_field_current_participants_nb';
  $handler->display->display_options['fields']['field_current_participants_nb']['field'] = 'field_current_participants_nb';
  /* Field: Content: Target number of participants with biological samples */
  $handler->display->display_options['fields']['field_target_number_biosamples']['id'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['field'] = 'field_target_number_biosamples';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_sam_supp_info']['id'] = 'field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['table'] = 'field_data_field_current_sam_supp_info';
  $handler->display->display_options['fields']['field_current_sam_supp_info']['field'] = 'field_current_sam_supp_info';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_supp_info']['id'] = 'field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['table'] = 'field_data_field_current_supp_info';
  $handler->display->display_options['fields']['field_current_supp_info']['field'] = 'field_current_supp_info';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_status_supp_info']['id'] = 'field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['table'] = 'field_data_field_status_supp_info';
  $handler->display->display_options['fields']['field_status_supp_info']['field'] = 'field_status_supp_info';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_recruitement_supp_info']['id'] = 'field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['table'] = 'field_data_field_recruitement_supp_info';
  $handler->display->display_options['fields']['field_recruitement_supp_info']['field'] = 'field_recruitement_supp_info';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['id'] = 'field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['table'] = 'field_data_field_partcipant_sel_supp_info';
  $handler->display->display_options['fields']['field_partcipant_sel_supp_info']['field'] = 'field_partcipant_sel_supp_info';
  /* Field: Content: Supplementary information about study design */
  $handler->display->display_options['fields']['field_recruitment_supp_info']['id'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['table'] = 'field_data_field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['field'] = 'field_recruitment_supp_info';
  /* Field: Content: Supplementary information about target number of participants */
  $handler->display->display_options['fields']['field_target_nb_supp_info']['id'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['table'] = 'field_data_field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['field'] = 'field_target_nb_supp_info';
  /* Field: Content: Investigators */
  $handler->display->display_options['fields']['field_investigators']['id'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['table'] = 'field_data_field_investigators';
  $handler->display->display_options['fields']['field_investigators']['field'] = 'field_investigators';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  /* Field: Content: Marker paper */
  $handler->display->display_options['fields']['field_marker_paper']['id'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['table'] = 'field_data_field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['field'] = 'field_marker_paper';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_age_max']['id'] = 'field_age_max';
  $handler->display->display_options['fields']['field_age_max']['table'] = 'field_data_field_age_max';
  $handler->display->display_options['fields']['field_age_max']['field'] = 'field_age_max';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_age_min']['id'] = 'field_age_min';
  $handler->display->display_options['fields']['field_age_min']['table'] = 'field_data_field_age_min';
  $handler->display->display_options['fields']['field_age_min']['field'] = 'field_age_min';
  /* Field: Content: Name of the person authorising the contribution to [SPECIFIC NETWORK] */
  $handler->display->display_options['fields']['field_authorising_person_name']['id'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['table'] = 'field_data_field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['field'] = 'field_authorising_person_name';
  /* Field: Content: Name of the person authorising the contribution to Maelstrom Research */
  $handler->display->display_options['fields']['field_authorising_person_name_m']['id'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['table'] = 'field_data_field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['field'] = 'field_authorising_person_name_m';
  /* Field: Content: No limits in the number of participants */
  $handler->display->display_options['fields']['field_no_limits_participants']['id'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['table'] = 'field_data_field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['field'] = 'field_no_limits_participants';
  /* Field: Content: No limits in the number of samples */
  $handler->display->display_options['fields']['field_no_limits_samples']['id'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['table'] = 'field_data_field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['field'] = 'field_no_limits_samples';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_samples_date']['id'] = 'field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['table'] = 'field_data_field_current_samples_date';
  $handler->display->display_options['fields']['field_current_samples_date']['field'] = 'field_current_samples_date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_current_part_nb_date']['id'] = 'field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['table'] = 'field_data_field_current_part_nb_date';
  $handler->display->display_options['fields']['field_current_part_nb_date']['field'] = 'field_current_part_nb_date';
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_access_other']['id'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['table'] = 'field_data_field_access_other';
  $handler->display->display_options['fields']['field_access_other']['field'] = 'field_access_other';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tissues_sp']['id'] = 'field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['table'] = 'field_data_field_tissues_sp';
  $handler->display->display_options['fields']['field_tissues_sp']['field'] = 'field_tissues_sp';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_samples_man_other_sp']['id'] = 'field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['table'] = 'field_data_field_samples_man_other_sp';
  $handler->display->display_options['fields']['field_samples_man_other_sp']['field'] = 'field_samples_man_other_sp';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_data_sources_sp']['id'] = 'field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['table'] = 'field_data_field_data_sources_sp';
  $handler->display->display_options['fields']['field_data_sources_sp']['field'] = 'field_data_sources_sp';
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp_1']['id'] = 'field_design_other_sp_1';
  $handler->display->display_options['fields']['field_design_other_sp_1']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp_1']['field'] = 'field_design_other_sp';
  /* Field: Content: Other recruitment target */
  $handler->display->display_options['fields']['field_recruitment_other_sp']['id'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['table'] = 'field_data_field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['field'] = 'field_recruitment_other_sp';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_selection_others_sp']['id'] = 'field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['table'] = 'field_data_field_selection_others_sp';
  $handler->display->display_options['fields']['field_selection_others_sp']['field'] = 'field_selection_others_sp';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_recruitment_other']['id'] = 'field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['table'] = 'field_data_field_recruitment_other';
  $handler->display->display_options['fields']['field_recruitment_other']['field'] = 'field_recruitment_other';
  /* Field: Content: Other access */
  $handler->display->display_options['fields']['field_access_other_sp']['id'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['table'] = 'field_data_field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['field'] = 'field_access_other_sp';
  /* Field: Content: Pubmed ID */
  $handler->display->display_options['fields']['field_pubmedid']['id'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['table'] = 'field_data_field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['field'] = 'field_pubmedid';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_recruitment_procedures']['id'] = 'field_recruitment_procedures';
  $handler->display->display_options['fields']['field_recruitment_procedures']['table'] = 'field_data_field_recruitment_procedures';
  $handler->display->display_options['fields']['field_recruitment_procedures']['field'] = 'field_recruitment_procedures';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_followup_start_year']['id'] = 'field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['table'] = 'field_data_field_followup_start_year';
  $handler->display->display_options['fields']['field_followup_start_year']['field'] = 'field_followup_start_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_baseline_start_year']['id'] = 'field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['table'] = 'field_data_field_baseline_start_year';
  $handler->display->display_options['fields']['field_baseline_start_year']['field'] = 'field_baseline_start_year';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_preparation_start_year']['id'] = 'field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['table'] = 'field_data_field_preparation_start_year';
  $handler->display->display_options['fields']['field_preparation_start_year']['field'] = 'field_preparation_start_year';
  /* Field: Content: Supplementary information */
  $handler->display->display_options['fields']['field_supp_infos']['id'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['table'] = 'field_data_field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['field'] = 'field_supp_infos';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_territory']['id'] = 'field_territory';
  $handler->display->display_options['fields']['field_territory']['table'] = 'field_data_field_territory';
  $handler->display->display_options['fields']['field_territory']['field'] = 'field_territory';
  /* Field: Content: Recruitment target */
  $handler->display->display_options['fields']['field_recruitment']['id'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['table'] = 'field_data_field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['field'] = 'field_recruitment';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_select_criteria']['id'] = 'field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['table'] = 'field_data_field_select_criteria';
  $handler->display->display_options['fields']['field_select_criteria']['field'] = 'field_select_criteria';
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design_1']['id'] = 'field_design_1';
  $handler->display->display_options['fields']['field_design_1']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design_1']['field'] = 'field_design';
  /* Field: Content: Study design (field_design:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
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

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Studies (csv)';
  $handler->display->display_options['display_description'] = 'Export studies to CSV file';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-yyyy%timestamp-mm%timestamp-dd%timestamp-hh%timestamp-ii%timestamp-ss.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Acronym */
  $handler->display->display_options['fields']['field_acroym']['id'] = 'field_acroym';
  $handler->display->display_options['fields']['field_acroym']['table'] = 'field_data_field_acroym';
  $handler->display->display_options['fields']['field_acroym']['field'] = 'field_acroym';
  /* Field: Content: Investigators */
  $handler->display->display_options['fields']['field_investigators']['id'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['table'] = 'field_data_field_investigators';
  $handler->display->display_options['fields']['field_investigators']['field'] = 'field_investigators';
  $handler->display->display_options['fields']['field_investigators']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_investigators']['delta_offset'] = '0';
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_contacts_ref']['id'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['field'] = 'field_contacts_ref';
  $handler->display->display_options['fields']['field_contacts_ref']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_contacts_ref']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  /* Field: Content: Name of the person authorising the contribution to [SPECIFIC NETWORK] */
  $handler->display->display_options['fields']['field_authorising_person_name']['id'] = 'field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['table'] = 'field_data_field_authorising_person_name';
  $handler->display->display_options['fields']['field_authorising_person_name']['field'] = 'field_authorising_person_name';
  /* Field: Content: Name of the person authorising the contribution to Maelstrom Research */
  $handler->display->display_options['fields']['field_authorising_person_name_m']['id'] = 'field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['table'] = 'field_data_field_authorising_person_name_m';
  $handler->display->display_options['fields']['field_authorising_person_name_m']['field'] = 'field_authorising_person_name_m';
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp]';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp_1']['id'] = 'field_design_other_sp_1';
  $handler->display->display_options['fields']['field_design_other_sp_1']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp_1']['field'] = 'field_design_other_sp';
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['label'] = '';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['element_label_colon'] = FALSE;
  /* Field: Content: Recruitment target */
  $handler->display->display_options['fields']['field_recruitment']['id'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['table'] = 'field_data_field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['field'] = 'field_recruitment';
  $handler->display->display_options['fields']['field_recruitment']['delta_offset'] = '0';
  /* Field: Content: Other recruitment target */
  $handler->display->display_options['fields']['field_recruitment_other_sp']['id'] = 'field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['table'] = 'field_data_field_recruitment_other_sp';
  $handler->display->display_options['fields']['field_recruitment_other_sp']['field'] = 'field_recruitment_other_sp';
  /* Field: Content: Supplementary information about study design */
  $handler->display->display_options['fields']['field_recruitment_supp_info']['id'] = 'field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['table'] = 'field_data_field_recruitment_supp_info';
  $handler->display->display_options['fields']['field_recruitment_supp_info']['field'] = 'field_recruitment_supp_info';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants_1']['id'] = 'field_target_number_participants_1';
  $handler->display->display_options['fields']['field_target_number_participants_1']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants_1']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: No limits in the number of participants */
  $handler->display->display_options['fields']['field_no_limits_participants']['id'] = 'field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['table'] = 'field_data_field_no_limits_participants';
  $handler->display->display_options['fields']['field_no_limits_participants']['field'] = 'field_no_limits_participants';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Supplementary information about target number of participants */
  $handler->display->display_options['fields']['field_target_nb_supp_info']['id'] = 'field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['table'] = 'field_data_field_target_nb_supp_info';
  $handler->display->display_options['fields']['field_target_nb_supp_info']['field'] = 'field_target_nb_supp_info';
  /* Field: Content: Target number of participants with biological samples */
  $handler->display->display_options['fields']['field_target_number_biosamples']['id'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['table'] = 'field_data_field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['field'] = 'field_target_number_biosamples';
  $handler->display->display_options['fields']['field_target_number_biosamples']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Biological samples */
  $handler->display->display_options['fields']['field_access_biosamples']['id'] = 'field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['table'] = 'field_data_field_access_biosamples';
  $handler->display->display_options['fields']['field_access_biosamples']['field'] = 'field_access_biosamples';
  /* Field: Content: Data (questionnaire-derived, measured...) */
  $handler->display->display_options['fields']['field_access_data']['id'] = 'field_access_data';
  $handler->display->display_options['fields']['field_access_data']['table'] = 'field_data_field_access_data';
  $handler->display->display_options['fields']['field_access_data']['field'] = 'field_access_data';
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_access_other']['id'] = 'field_access_other';
  $handler->display->display_options['fields']['field_access_other']['table'] = 'field_data_field_access_other';
  $handler->display->display_options['fields']['field_access_other']['field'] = 'field_access_other';
  /* Field: Content: Other access */
  $handler->display->display_options['fields']['field_access_other_sp']['id'] = 'field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['table'] = 'field_data_field_access_other_sp';
  $handler->display->display_options['fields']['field_access_other_sp']['field'] = 'field_access_other_sp';
  /* Field: Content: Datasets */
  $handler->display->display_options['fields']['mica_dataset']['id'] = 'mica_dataset';
  $handler->display->display_options['fields']['mica_dataset']['table'] = 'field_data_mica_dataset';
  $handler->display->display_options['fields']['mica_dataset']['field'] = 'mica_dataset';
  $handler->display->display_options['fields']['mica_dataset']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['mica_dataset']['delta_offset'] = '0';
  /* Field: Content: No limits in the number of samples */
  $handler->display->display_options['fields']['field_no_limits_samples']['id'] = 'field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['table'] = 'field_data_field_no_limits_samples';
  $handler->display->display_options['fields']['field_no_limits_samples']['field'] = 'field_no_limits_samples';
  /* Field: Content: Marker paper */
  $handler->display->display_options['fields']['field_marker_paper']['id'] = 'field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['table'] = 'field_data_field_marker_paper';
  $handler->display->display_options['fields']['field_marker_paper']['field'] = 'field_marker_paper';
  /* Field: Content: Pubmed ID */
  $handler->display->display_options['fields']['field_pubmedid']['id'] = 'field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['table'] = 'field_data_field_pubmedid';
  $handler->display->display_options['fields']['field_pubmedid']['field'] = 'field_pubmedid';
  /* Field: Content: Supplementary information */
  $handler->display->display_options['fields']['field_supp_infos']['id'] = 'field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['table'] = 'field_data_field_supp_infos';
  $handler->display->display_options['fields']['field_supp_infos']['field'] = 'field_supp_infos';
  $handler->display->display_options['path'] = 'studies-csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = '0';
  $export['studies'] = $view;

  $view = new view();
  $view->name = 'studies_search';
  $view->description = '';
  $view->tag = 'study,search';
  $view->base_table = 'search_api_index_studies_index';
  $view->human_name = 'Studies Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies Search';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_ajax'] = TRUE;
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies.

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_studies';
  $handler->display->display_options['empty']['area']['content'] = 'No study found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Node: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  /* Field: Indexed Node: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp]';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Indexed Node: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Populations: Country of residence (indexed) */
  $handler->display->display_options['fields']['field_study_populations_field_pop_country']['id'] = 'field_study_populations_field_pop_country';
  $handler->display->display_options['fields']['field_study_populations_field_pop_country']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['fields']['field_study_populations_field_pop_country']['field'] = 'field_study_populations_field_pop_country';
  $handler->display->display_options['fields']['field_study_populations_field_pop_country']['label'] = 'Country of residence';
  $handler->display->display_options['fields']['field_study_populations_field_pop_country']['delta_offset'] = '0';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'studies-search';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This page displays the list of the consortium\'s studies. Each study is described in a same standard way that can be easily customized to reflect consortium specificities. However, Mica suggests by default a list of important study characteristics that should be considered if there is an aim for the consortium to participate in data harmonization projects with other consortia or studies. 

This Mica study catalogue comes with an advanced query tool using user-friendly facets <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_studies_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'studies';
  $export['studies_search'] = $view;

  return $export;
}
