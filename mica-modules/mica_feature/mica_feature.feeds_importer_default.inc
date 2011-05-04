<?php
/**
 * @file
 * mica_feature.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function mica_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_contact_import';
  $feeds_importer->config = array(
    'name' => 'Contact',
    'description' => 'Import Contact from a CSV file',
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
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'contact',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_contact_name:title',
            'target' => 'field_contact_name:title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_contact_name:given',
            'target' => 'field_contact_name:given',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_contact_name:family',
            'target' => 'field_contact_name:family',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_role_title',
            'target' => 'field_role_title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_telephone',
            'target' => 'field_telephone',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_institution',
            'target' => 'field_institution:title',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_contact_email',
            'target' => 'field_contact_email',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          9 => array(
            'source' => 'status',
            'target' => 'status',
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
  $export['csv_contact_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_institution_import';
  $feeds_importer->config = array(
    'name' => 'Institution',
    'description' => 'Import Institution from a CSV file',
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
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'institution',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'field_street',
            'target' => 'field_street',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_city',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_country',
            'target' => 'field_country',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_postal_code',
            'target' => 'field_postal_code',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_institution_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
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
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'study',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'field_study_legacy_id',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'field_study_legacy_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
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

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_information_import';
  $feeds_importer->config = array(
    'name' => 'Study Information',
    'description' => 'Import Study Information from a CSV file',
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
      'plugin_key' => 'FeedsStudyChildProcessor',
      'config' => array(
        'content_type' => 'study_information',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_investigator',
            'target' => 'field_investigator:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_contact',
            'target' => 'field_contact:title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_design',
            'target' => 'field_design',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_design_other',
            'target' => 'field_design_other',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_design_target',
            'target' => 'field_design_target',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_target_other',
            'target' => 'field_target_other',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_target_number_participants',
            'target' => 'field_target_number_participants',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_selection_criteria',
            'target' => 'field_selection_criteria',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'field_study_country',
            'target' => 'field_study_country',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'field_age_min',
            'target' => 'field_age_min',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'field_age_max',
            'target' => 'field_age_max',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'field_biosamples_collected',
            'target' => 'field_biosamples_collected',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'field_biosamples_collected_other',
            'target' => 'field_biosamples_collected_other',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'field_biosamples_tissues',
            'target' => 'field_biosamples_tissues',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'field_gwas_analysis',
            'target' => 'field_gwas_analysis',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'field_gwas_number',
            'target' => 'field_gwas_number',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'field_access',
            'target' => 'field_access',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'field_access_other',
            'target' => 'field_access_other',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'field_status_start',
            'target' => 'field_status_start',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'field_status_end',
            'target' => 'field_status_end',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'status',
            'target' => 'status',
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
  $export['csv_study_information_import'] = $feeds_importer;

  return $export;
}
