<?php
/**
 * @file
 * Mica Datasets developper utilities
 */

include_once('mica_datasets.import_taxonomies.inc');
include_once('mica_datasets.menu.inc');

function _mica_datasets_devel_form() {

  $form['generate_menus'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menus'),
    '#description' => t('Regenerate dataset and variables menus.'),
  );
  $form['generate_menus']['run'] = array(
    '#type' => 'submit',
    '#value' => t('Regenerate menus'),
    '#submit' => array('_mica_datasets_regenerate_menus'),
  );

  $form['taxonomy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dataset Taxonomies'),
  );
  $form['taxonomy']['import'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
    '#submit' => array('_mica_datasets_import_taxonomies_run'),
  );
  $form['taxonomy']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('_mica_datasets_delete_taxonomies'),
  );
  $form['reset_variables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Erase Variables Menus'),
  );
  $form['reset_variables']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Erase'),
    '#submit' => array('_mica_datasets_variables_reset_menus'),
  );

  return $form;
}

function _mica_datasets_delete_taxonomies() {
  $taxonomies = taxonomy_vocabulary_get_names();
  foreach (_mica_datasets_taxonomies() as $dimensions) {
    $machine_name = substr($dimensions[0], 0, drupal_strlen($dimensions[0]) - 4);
    drupal_set_message(t('Deleting @name', array('@name' => check_plain($machine_name))));
    taxonomy_vocabulary_delete($taxonomies[$machine_name]->vid);
  }
}

function _mica_datasets_import_taxonomies_run() {
  foreach (_mica_datasets_taxonomies() as $taxonomy) {
    $machine_name = substr($taxonomy[0], 0, drupal_strlen($taxonomy[0]) - 4);
    drupal_set_message(t('Importing @name', array('@name' => check_plain($machine_name))));
    //_mica_datasets_taxonomy_import($taxonomy[0], $taxonomy[1]);
    mica_core_taxonomy_import($taxonomy[0], drupal_get_path('module', 'mica_datasets') . '/taxonomies/', $taxonomy[1]);
  }
}