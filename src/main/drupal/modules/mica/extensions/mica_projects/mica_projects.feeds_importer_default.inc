<?php
/**
 * @file
 * mica_projects.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_projects_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_project_import';
  $feeds_importer->config = array(
    'name' => 'Project',
    'description' => 'Import Project from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'content_type' => 'project',
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
            'source' => 'field_studies',
            'target' => 'field_studies:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_files',
            'target' => 'field_files',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
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
  $export['csv_project_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_teleconference_import';
  $feeds_importer->config = array(
    'name' => 'Teleconference',
    'description' => 'Import Teleconference from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'content_type' => 'teleconference',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'field_teleconference_description',
            'target' => 'field_teleconference_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_teleconference_date:start',
            'target' => 'field_teleconference_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_teleconference_date:end',
            'target' => 'field_teleconference_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_project',
            'target' => 'field_project:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_instructions',
            'target' => 'field_instructions',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'title',
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
  $export['csv_teleconference_import'] = $feeds_importer;

  return $export;
}
