<?php

/**
 * @file
 * Mica Studies taxonomies importer
 */

function _mica_studies_taxonomies() {
  return array(
    array('sources_of_recruitment.csv', 'Source of Recruitment'),
  );
}

/**
 * Implements hook_taxonomies_operations_import().
 */
function mica_studies_taxonomies_operations_import() {
  $base_path = drupal_get_path('module', 'mica_studies') . '/taxonomies/';
  $operations = array();
  foreach (_mica_studies_taxonomies() as $taxonomy) {
    $operations[] = array('mica_core_taxonomy_import', array($taxonomy[0], $base_path, $taxonomy[1]));
  }
  return $operations;
}