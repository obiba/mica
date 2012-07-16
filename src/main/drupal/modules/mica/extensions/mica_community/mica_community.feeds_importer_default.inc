<?php
/**
 * @file
 * mica_community.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mica_community_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_event_import';
  $feeds_importer->config = array(
    'name' => 'Event',
    'description' => 'Import Event from CSV files',
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
        'content_type' => 'event',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_event_date:start',
            'target' => 'field_event_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_event_date:end',
            'target' => 'field_event_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_event_link:title',
            'target' => 'field_event_link:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_event_link:url',
            'target' => 'field_event_link:url',
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
  $export['csv_event_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_publication_import';
  $feeds_importer->config = array(
    'name' => 'Publication',
    'description' => 'Import Publication from CSV files',
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
        'content_type' => 'publication',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'field_publication_pmid',
            'target' => 'field_publication_pmid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_publication_url:url',
            'target' => 'field_publication_url:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_abstract',
            'target' => 'field_abstract',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_authors',
            'target' => 'field_authors',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_publication_url:title',
            'target' => 'field_publication_url:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_reference',
            'target' => 'field_publication_reference',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'title',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
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
  $export['csv_publication_import'] = $feeds_importer;

  return $export;
}
