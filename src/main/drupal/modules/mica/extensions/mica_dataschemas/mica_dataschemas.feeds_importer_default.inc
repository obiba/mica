<?php
/**
 * @file
 * mica_dataschemas.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_dataschemas_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_category_import';
  $feeds_importer->config = array(
    'name' => 'DataSchema Category',
    'description' => 'Import Categories from a CSV file',
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
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'category',
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
            'source' => 'field_name',
            'target' => 'field_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_is_missing',
            'target' => 'field_is_missing',
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
  $export['csv_category_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_dataschema_import';
  $feeds_importer->config = array(
    'name' => 'DataSchema',
    'description' => 'Import DataSchema from a CSV file',
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
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'dataschema',
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
            'source' => 'body',
            'target' => 'body',
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
  $export['csv_dataschema_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_ds_variable_import';
  $feeds_importer->config = array(
    'name' => 'DataSchema Variable',
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
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
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
            'source' => 'field_unit',
            'target' => 'field_unit',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_uri',
            'target' => 'field_uri',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_uri',
            'target' => 'guid',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'field_dim_type',
            'target' => 'field_dim_type',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_dim_collection_mode',
            'target' => 'field_dim_collection_mode',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_dim_format',
            'target' => 'field_dim_format',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_dim_sample',
            'target' => 'field_dim_sample',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_dim_target_gender',
            'target' => 'field_dim_target_gender',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_dataschema_ref',
            'target' => 'field_dataschema_ref:title',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'field_interpretation_variables',
            'target' => 'field_interpretation_variables:title',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'field_computation_variables',
            'target' => 'field_computation_variables:title',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'field_contraindication_variables',
            'target' => 'field_contraindication_variables:title',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'field_variable_categories',
            'target' => 'field_variable_categories:title',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          16 => array(
            'source' => 'field_dim_disease',
            'target' => 'field_dim_disease',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'field_dim_class',
            'target' => 'field_dim_class',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'field_dim_med_health_interv',
            'target' => 'field_dim_med_health_interv',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'field_dim_period',
            'target' => 'field_dim_period',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'field_dim_source_of_info',
            'target' => 'field_dim_source_of_info',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'field_dim_target',
            'target' => 'field_dim_target',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'field_dim_health_information ',
            'target' => 'field_dim_health_information',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'field_dim_disease_history ',
            'target' => 'field_dim_disease_history',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'field_dim_life_habits_behaviours',
            'target' => 'field_dim_life_habits_behaviours',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'field_dim_sociodemo_charact',
            'target' => 'field_dim_sociodemo_charact',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'field_dim_socioeco',
            'target' => 'field_dim_socioeco',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'field_dim_body_structure',
            'target' => 'field_dim_body_structure',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'field_dim_body_functions',
            'target' => 'field_dim_body_functions',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'field_dim_sample',
            'target' => 'field_dim_sample',
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

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_pairing_import';
  $feeds_importer->config = array(
    'name' => 'Pairing',
    'description' => 'Import Pairings from a CSV file',
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
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'pairing',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'field_match',
            'target' => 'field_match',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_project',
            'target' => 'field_project:title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'field_study',
            'target' => 'field_study:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_variable',
            'target' => 'field_variable:title',
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
  $export['csv_pairing_import'] = $feeds_importer;

  return $export;
}
