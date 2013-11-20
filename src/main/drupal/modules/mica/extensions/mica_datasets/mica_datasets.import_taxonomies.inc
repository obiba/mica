<?php

/**
 * @file
 * Mica Datasets taxonomies importer
 */

function _mica_datasets_taxonomies() {
  return array(
    array('anthropometric_structures.csv', 'Anthropometric structures'),
    array('body_functions.csv', 'Body functions'),
    array('body_structures.csv', 'Body structures'),
    array('data_source.csv', 'Data source'),
    array('disease_history.csv', 'Diseases history and related health problems'),
    array('early_life.csv', 'Participant\'s early life/Childhood'),
    array('laboratory_measures.csv', 'Laboratory Measures'),
    array('life_habits_behaviours.csv', 'Life habits/Behaviours'),
    array('medical_health_intervention.csv', 'Medical health interventions/Health services utilization'),
    array('medication.csv', 'Medication'),
    array('perception_of_health.csv', 'Perception of health/Quality of life'),
    array('physical_environment.csv', 'Physical environment'),
    array('reproductive_history.csv', 'Reproductive health and history'),
    array('social_environment.csv', 'Social environment'),
    array('sociodemographic_characteristics.csv', 'Sociodemographic/Socioeconomic characteristics'),
    array('target.csv', 'Target'),
    array('administrative_information.csv', 'Administrative Information'),
  );
}

/**
 * Implements hook_taxonomies_operations_import().
 */
function mica_datasets_taxonomies_operations_import() {
  $base_path = drupal_get_path('module', 'mica_datasets') . '/taxonomies/';
  $operations = array();
  foreach (_mica_datasets_taxonomies() as $taxonomy) {
    $operations[] = array('mica_core_taxonomy_import', array($taxonomy[0], $base_path, $taxonomy[1]));
  }
  return $operations;
}