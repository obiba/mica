<?php
/**
 * @file
 * Mica Datasets developper utilities
 */

function _mica_i18n_devel_form() {

  $form['update'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update Content Types, Search indexes, taxonomies and menus'),
    '#description' => t('Update to support internationalization.'),
  );
  $form['update']['update_content_types'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('_mica_i18n_update'),
  );

  return $form;
}

function _mica_i18n_update() {
  mica_i18n_fix_entity_display();

  // Explicitly set 'Default translated' display format for all fields of type list_text
  mica_i18n_fix_views_display();

  // Modify all search index... Add language field and processors
  mica_i18n_search_index_update();

  // set all taxonomies to be localizable
  mica_i18n_taxonomy_localizable();
}