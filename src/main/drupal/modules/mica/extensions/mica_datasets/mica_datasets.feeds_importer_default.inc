<?php
/**
 * @file
 * mica_datasets.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_datasets_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_variables';
  $feeds_importer->config = array(
    'name' => 'Variables from CSV',
    'description' => 'Import Variables from a CSV file',
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
        'content_type' => 'variable',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'label',
            'target' => 'field_label',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'value_type',
            'target' => 'field_value_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'repeatable',
            'target' => 'field_repeatable',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'dataset_name',
            'target' => 'field_dataset:title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'categories_name',
            'target' => 'field_variable_categories:name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'categories_label',
            'target' => 'field_variable_categories:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'categories_missing',
            'target' => 'field_variable_categories:missing',
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
  $export['csv_variables'] = $feeds_importer;

  return $export;
}
