<?php
/**
 * @file
 * mica_community.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function mica_community_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_publication_import-field_authors-explode';
  $feeds_tamper->importer = 'csv_publication_import';
  $feeds_tamper->source = 'field_authors';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_publication_import-field_authors-explode'] = $feeds_tamper;

  return $export;
}
