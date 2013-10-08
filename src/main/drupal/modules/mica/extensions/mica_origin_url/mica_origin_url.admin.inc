<?php

/**
 * @file
 * Administration functions for the origin url module.
 */

/**
 * Menu callback: options for mica_origin_url.
 */
function mica_origin_url_admin_form($form) {
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
  _mica_origin_url_sync_table();
  drupal_set_message(t('Generated missing Mica Origin Url(s).'));
}

function _mica_origin_url_sync_table() {
  // Fetch  nodes to update ->$origin_url_field are empty .
  global $base_url;
  $nodes = entity_load('node', FALSE, array('mica_origin_url' => ''));
  foreach ($nodes as $node) {
    $node->mica_origin_url = $base_url;
    node_save($node);
  }
}