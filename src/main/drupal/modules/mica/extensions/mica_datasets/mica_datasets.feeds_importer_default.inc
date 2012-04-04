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
          9 => array(
            'source' => 'disease_history',
            'target' => 'field_disease_history',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'medical_health_interv',
            'target' => 'field_medical_health_interv',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'medication',
            'target' => 'field_medication',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'reproductive_history',
            'target' => 'field_reproductive_history',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'early_life',
            'target' => 'field_early_life',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'life_habits_behaviours',
            'target' => 'field_life_habits_behaviours',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'sociodemographic_charact',
            'target' => 'field_sociodemographic_charact',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'physical_environment',
            'target' => 'field_physical_environment',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'social_environment',
            'target' => 'field_social_environment',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'perception_of_health',
            'target' => 'field_perception_of_health',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'anthropometric_structures',
            'target' => 'field_anthropometric_structures',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'body_structures',
            'target' => 'field_body_structures',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'body_functions',
            'target' => 'field_body_functions',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'data_source',
            'target' => 'field_data_source',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'response_unit',
            'target' => 'field_response_unit',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'target',
            'target' => 'field_target',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'target_gender',
            'target' => 'field_target_gender',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'period',
            'target' => 'field_period',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'class',
            'target' => 'field_class',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'format',
            'target' => 'field_format',
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

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dataset';
  $feeds_importer->config = array(
    'name' => 'Dataset',
    'description' => 'Import Datasets from a CSV file',
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
        'content_type' => 'dataset',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body',
            'target' => 'body',
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
  $export['dataset'] = $feeds_importer;

  return $export;
}
