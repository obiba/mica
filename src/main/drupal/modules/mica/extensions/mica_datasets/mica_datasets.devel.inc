<?php

include_once('mica_datasets.import_taxonomies.inc');

function _mica_datasets_devel_form() {
  $form['taxonomy_import']['description'] = array(
    '#markup' => '<p>' . t('Import all taxonomies') . '</p>',
  );
  $form['taxonomy_import']['run'] = array(
    '#type' => 'submit',
    '#value' => t('Run taxonomy import'),
    '#submit' => array('_mica_datasets_import_taxonomies_run'),
  );
  $form['taxonomy_delete']['description'] = array(
    '#markup' => '<p>' . t('Delete all taxonomies') . '</p>',
  );
  $form['taxonomy_delete']['run'] = array(
    '#type' => 'submit',
    '#value' => t('Run taxonomy delete'),
    '#submit' => array('_mica_datasets_delete_taxonomies'),
  );
  return $form;
}

function _mica_datasets_delete_taxonomies() {
  $taxonomies = taxonomy_vocabulary_get_names();
  foreach (_mica_datasets_taxonomies() as $dimensions) {
    $machine_name = substr($dimensions[0], 0, strlen($dimensions[0]) - 4);
    drupal_set_message("Deleting " . $machine_name);
    taxonomy_vocabulary_delete($taxonomies[$machine_name]->vid);
  }
}

function _mica_datasets_import_taxonomies_run() {
  $node = mica_add_book_page('Dimensions', 'Here is a description of our dimensions');
  foreach (_mica_datasets_taxonomies() as $taxonomy) {
    $machine_name = substr($taxonomy[0], 0, strlen($taxonomy[0]) - 4);
    drupal_set_message("Importing " . $machine_name);
    _mica_datasets_taxonomy_import($taxonomy[0], $taxonomy[1]);
    
    mica_add_book_page($taxonomy[1], "List of terms for $taxonomy[1]", $node->nid);
  }
}