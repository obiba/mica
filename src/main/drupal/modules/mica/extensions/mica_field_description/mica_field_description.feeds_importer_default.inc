<?php
/**
 * @file
 * mica_field_description.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_field_description_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
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
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
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
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'field_bundle',
            'target' => 'field_bundle',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_value_type',
            'target' => 'field_value_type',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_original_field_name',
            'target' => 'field_original_field_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_original_field_label',
            'target' => 'field_original_field_label',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_bundle_label',
            'target' => 'field_bundle_label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_repeatable',
            'target' => 'field_repeatable',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'authorize' => 1,
        'skip_hash_check' => 0,
        'bundle' => 'field_description',
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

  return $export;
}
