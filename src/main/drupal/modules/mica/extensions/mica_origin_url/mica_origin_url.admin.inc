<?php

/**
 * @file
 * Administration functions for the origin url module.
 */

/**
 * Menu callback: options for mica_origin_url.
 */
function mica_origin_url_admin_form() {
  $form = array();

  $form['sync'] = array(
    '#type' => 'fieldset',
    '#title' => t('Synchronization'),
  );

  $form['sync']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create missing Origin Urls'),
    '#submit' => array('mica_origin_url_admin_sync_submit'),
  );

  return system_settings_form($form);
}

/**
 * Submit handler for the Origin_url sync.
 */

function mica_origin_url_admin_sync_submit() {
  _mica_origin_url_sync_table('node', 'mica_origin_url');
  drupal_set_message(t('Generated missing Origin Url(s).'));
}

function _mica_origin_url_sync_table($table, $origin_url_field) {
  // Fetch  nodes to update -> origin_url_field are empty .
  global $base_url;
  $result = db_select($table, 't')
    ->fields('t', array('nid'))
    ->condition(db_or()->condition($origin_url_field, '')->isNull($origin_url_field))
    ->execute();

  // Update empty records.
  foreach ($result as $record) {
    db_update($table)
      ->fields(array($origin_url_field => $base_url))
      ->condition('nid', $record->nid)
      ->execute();
  }

}


