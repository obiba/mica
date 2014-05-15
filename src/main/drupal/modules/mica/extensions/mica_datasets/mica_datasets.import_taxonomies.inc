<?php

/**
 * @file
 * Mica Datasets taxonomies importer
 */

function _mica_datasets_taxonomies() {
  return array(
    array('disease_history.csv', 'Diseases history and related health problems'),
    array('medical_health_intervention.csv', 'Medical health interventions/Health services utilization'),
    array('medication.csv', 'Medication'),
    array('reproductive_history.csv', 'Reproductive health and history'),
    array('early_life.csv', 'Participant\'s early life/Childhood'),
    array('life_habits_behaviours.csv', 'Life habits/Behaviours'),
    array('sociodemographic_characteristics.csv', 'Sociodemographic/Socioeconomic characteristics'),
    array('physical_environment.csv', 'Physical environment'),
    array('social_environment.csv', 'Social environment'),
    array('perception_of_health.csv', 'Perception of health/Quality of life'),
    array('anthropometric_structures.csv', 'Anthropometric structures'),
    array('body_structures.csv', 'Body structures'),
    array('body_functions.csv', 'Body functions'),
    array('laboratory_measures.csv', 'Laboratory Measures'),
    array('administrative_information.csv', 'Administrative Information'),
    array('data_source.csv', 'Data source'),
    array('target.csv', 'Target'),

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