<?php
/**
 * @file
 * mica_dataschemas.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function mica_dataschemas_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_ds_variable_import';
  $feeds_importer->config = array(
    'name' => 'DS Variable',
    'description' => 'Import DataSchema Variables from CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'multivalue_separator' => '||',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'ds_variable',
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
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_module',
            'target' => 'field_module',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_theme',
            'target' => 'field_theme',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_domain',
            'target' => 'field_domain',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_unit',
            'target' => 'field_unit',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_uri',
            'target' => 'field_uri',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_uri',
            'target' => 'guid',
            'unique' => 0,
          ),
          8 => array(
            'source' => 'field_dim_type',
            'target' => 'field_dim_type',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_dim_collection_mode',
            'target' => 'field_dim_collection_mode',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_dim_format',
            'target' => 'field_dim_format',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'field_dim_sample',
            'target' => 'field_dim_sample',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'field_dim_target_gender',
            'target' => 'field_dim_target_gender',
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
  $export['csv_ds_variable_import'] = $feeds_importer;

  return $export;
}
