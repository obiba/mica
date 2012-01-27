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

  $feeds_importer = new stdClass;
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
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'documents',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_files',
            'target' => 'field_files',
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

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_field_description_import';
  $feeds_importer->config = array(
    'name' => 'Field Description',
    'description' => 'Import Field Description from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'field_description',
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
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'field_bundle',
            'target' => 'field_bundle',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_value_type',
            'target' => 'field_value_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_original_field_name',
            'target' => 'field_original_field_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_original_field_label',
            'target' => 'field_original_field_label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_bundle_label',
            'target' => 'field_bundle_label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_repeatable',
            'target' => 'field_repeatable',
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
  $export['csv_field_description_import'] = $feeds_importer;

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
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
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
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'field_logo',
            'target' => 'field_logo',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_full_name',
            'target' => 'field_full_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_investigator',
            'target' => 'field_investigator:title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_contact',
            'target' => 'field_contact:title',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_target_number_participants',
            'target' => 'field_target_number_participants',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_target_number_biosamples',
            'target' => 'field_target_number_biosamples',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'field_p3g_observatory_link',
            'target' => 'field_p3g_observatory_link:url',
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
