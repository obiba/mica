<?php
/**
 * @file
 * mica_studies.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_studies_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_contact_import';
  $feeds_importer->config = array(
    'name' => 'Contact',
    'description' => 'Import Contact from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'contact',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'contact_title',
            'target' => 'field_contact_name:title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'given_name',
            'target' => 'field_contact_name:given',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'family_name',
            'target' => 'field_contact_name:family',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'email',
            'target' => 'field_contact_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'telephone',
            'target' => 'field_telephone',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'institution',
            'target' => 'field_institution_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'address',
            'target' => 'field_address',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'city',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'postal_code',
            'target' => 'field_postal_code',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'state',
            'target' => 'field_state',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'country',
            'target' => 'node:contact:field_contact_country:iso2',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'data_access_committee_member',
            'target' => 'field_daco',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          13 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_contact_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_documents_import';
  $feeds_importer->config = array(
    'name' => 'Documents',
    'description' => 'Import Documents from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'documents',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_files',
            'target' => 'field_files',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'title',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_documents_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_import';
  $feeds_importer->config = array(
    'name' => 'Study',
    'description' => 'Import Study from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'study',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'acronym',
            'target' => 'field_acroym',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'objectives',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'authorization_from_contributors_to_the_specific_network_catalogues',
            'target' => 'field_authorization_specific',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'name_of_the_person_authorising_the_contribution_to_specific_network',
            'target' => 'field_authorising_person_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'authorization_date_from_contributors_to_the_specific_network_catalogues',
            'target' => 'field_authorising_date:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'authorization_from_contributors_to_the_maelstrom_catalogues',
            'target' => 'field_authorization_maelstrom',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'name_of_the_person_authorising_the_contribution_to_maelstrom_research',
            'target' => 'field_authorising_person_name_m',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'authorization_date_from_contributors_to_the_maelstrom_catalogues',
            'target' => 'field_authorising_date_m:start',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'baseline_design_of_the_study',
            'target' => 'field_design',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'other_baseline_design_of_the_study',
            'target' => 'field_design_other_sp',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'study_recruitment_targets',
            'target' => 'field_recruitment',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'other_recruitment_target',
            'target' => 'field_recruitment_supp_info',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'study_design_supplementary_information',
            'target' => 'field_recruitment_supp_info',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'headline_number_of_participants',
            'target' => 'field_target_number_participants',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'no_limits_in_the_number_of_participants',
            'target' => 'field_no_limits_participants',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'target_number_of_participants_supplementary_information',
            'target' => 'field_target_nb_supp_info',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'headline_number_of_participants_with_samples',
            'target' => 'field_target_number_biosamples',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'no_limits_in_the_number_of_samples',
            'target' => 'field_no_limits_samples',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'target_number_of_biological_samples_supplementary_information',
            'target' => 'field_samples_supp_info',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'current_number_of_participants_recruited',
            'target' => 'field_current_participants_nb',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'date_of_current_number_of_participants_recruited_at_baseline',
            'target' => 'field_current_part_nb_date:start',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'current_number_of_participants_recruited_at_baseline_supplementary_information',
            'target' => 'field_current_supp_info',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'current_number_of_collected_biological_samples',
            'target' => 'field_current_samples_nb',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'date_of_current_number_of_collected_biological_samples',
            'target' => 'field_current_samples_date:start',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'current_number_of_collected_biological_samples_supplementary_information',
            'target' => 'field_current_sam_supp_info',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'study_inclusion_criteria_for_participants_selection',
            'target' => 'field_select_criteria',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'age_min',
            'target' => 'field_age_min',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'age_max',
            'target' => 'field_age_max',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'territory',
            'target' => 'field_territory',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'ethnic_origin',
            'target' => 'field_ethnic_origin',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'health_status',
            'target' => 'field_health_status',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'other_selection_criteria',
            'target' => 'field_selection_others_sp',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'selection_criteria_supplementary_information',
            'target' => 'field_partcipant_sel_supp_info',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'sources_of_recruitment',
            'target' => 'field_recruitment_sources',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'Other sources of recruitment',
            'target' => 'field_recruitment_other',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'recruitment_procedures_supplementary_information',
            'target' => 'field_recruitement_supp_info',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'data_sources',
            'target' => 'field_data_sources',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'other_data_sources',
            'target' => 'field_data_sources_sp',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'biological_samples',
            'target' => 'field_bio_samples_management',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'other_type_of_tissues',
            'target' => 'field_tissues_sp',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'other_sample_management',
            'target' => 'field_samples_man_other_sp',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'data_access',
            'target' => 'field_access_data',
            'unique' => FALSE,
          ),
          43 => array(
            'source' => 'biological_samples_access',
            'target' => 'field_access_biosamples',
            'unique' => FALSE,
          ),
          44 => array(
            'source' => 'other_access',
            'target' => 'field_access_other',
            'unique' => FALSE,
          ),
          45 => array(
            'source' => 'access_supplementary_information',
            'target' => 'field_access_other_sp',
            'unique' => FALSE,
          ),
          46 => array(
            'source' => 'preparation_phase_start_year',
            'target' => 'field_preparation_start_year',
            'unique' => FALSE,
          ),
          47 => array(
            'source' => 'preparation_phase_end_year',
            'target' => 'field_preparation_end_year',
            'unique' => FALSE,
          ),
          48 => array(
            'source' => 'baseline_recruitment_start_year',
            'target' => 'field_baseline_start_year',
            'unique' => FALSE,
          ),
          49 => array(
            'source' => 'baseline_recruitment_end_year',
            'target' => 'field_baseline_end_year',
            'unique' => FALSE,
          ),
          50 => array(
            'source' => 'followup_start_year',
            'target' => 'field_followup_start_year',
            'unique' => FALSE,
          ),
          51 => array(
            'source' => 'followup_end_year',
            'target' => 'field_followup_end_year',
            'unique' => FALSE,
          ),
          52 => array(
            'source' => 'study_end_year',
            'target' => 'field_ended_end_year',
            'unique' => FALSE,
          ),
          53 => array(
            'source' => 'current_status_supplementary_information',
            'target' => 'field_status_supp_info',
            'unique' => FALSE,
          ),
          54 => array(
            'source' => 'marker_paper',
            'target' => 'field_marker_paper',
            'unique' => FALSE,
          ),
          55 => array(
            'source' => 'pubmed_id',
            'target' => 'field_pubmedid',
            'unique' => FALSE,
          ),
          56 => array(
            'source' => 'opal',
            'target' => 'mica_opal:url',
            'unique' => FALSE,
          ),
          57 => array(
            'source' => 'supplementary_information',
            'target' => 'field_supp_infos',
            'unique' => FALSE,
          ),
          58 => array(
            'source' => 'documents',
            'target' => 'field_documents',
            'unique' => FALSE,
          ),
          59 => array(
            'source' => 'logo',
            'target' => 'field_logo',
            'unique' => FALSE,
          ),
          60 => array(
            'source' => 'contacts',
            'target' => 'field_contacts_ref:title',
            'unique' => FALSE,
          ),
          61 => array(
            'source' => 'investigators',
            'target' => 'field_investigators:title',
            'unique' => FALSE,
          ),
          62 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          63 => array(
            'source' => 'country',
            'target' => 'field_country',
            'unique' => FALSE,
          ),
          64 => array(
            'source' => 'complete_name',
            'target' => 'title',
            'unique' => 0,
          ),
          65 => array(
            'source' => 'gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          66 => array(
            'source' => 'dataset',
            'target' => 'mica_dataset:title',
            'unique' => FALSE,
          ),
          67 => array(
            'source' => 'complete_name',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_study_import'] = $feeds_importer;

  return $export;
}
