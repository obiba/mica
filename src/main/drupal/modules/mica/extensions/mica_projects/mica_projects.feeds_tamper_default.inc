<?php
/**
 * @file
 * mica_projects.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function mica_projects_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_project_import-field_files-explode';
  $feeds_tamper->importer = 'csv_project_import';
  $feeds_tamper->source = 'field_files';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_project_import-field_files-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_project_import-field_studies-explode';
  $feeds_tamper->importer = 'csv_project_import';
  $feeds_tamper->source = 'field_studies';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_project_import-field_studies-explode'] = $feeds_tamper;

  return $export;
}
