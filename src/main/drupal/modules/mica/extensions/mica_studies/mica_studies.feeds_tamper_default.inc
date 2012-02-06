<?php
/**
 * @file
 * mica_studies.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function mica_studies_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_contact_import-published-convert_to_boolean';
  $feeds_tamper->importer = 'csv_contact_import';
  $feeds_tamper->source = 'published';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['csv_contact_import-published-convert_to_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_study_import-contacts-explode';
  $feeds_tamper->importer = 'csv_study_import';
  $feeds_tamper->source = 'contacts';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_study_import-contacts-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_study_import-country-explode_country';
  $feeds_tamper->importer = 'csv_study_import';
  $feeds_tamper->source = 'country';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_study_import-country-explode_country'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_study_import-documents-explode';
  $feeds_tamper->importer = 'csv_study_import';
  $feeds_tamper->source = 'documents';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_study_import-documents-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_study_import-investigators-explode';
  $feeds_tamper->importer = 'csv_study_import';
  $feeds_tamper->source = 'investigators';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_study_import-investigators-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_study_import-published-convert_to_boolean';
  $feeds_tamper->importer = 'csv_study_import';
  $feeds_tamper->source = 'published';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['csv_study_import-published-convert_to_boolean'] = $feeds_tamper;

  return $export;
}
