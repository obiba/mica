<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mica_standard_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

function mica_standard_install_tasks($install_state){
  include_once(drupal_get_path('profile', 'mica_minimal') . '/mica_minimal.profile');
  $tasks = mica_minimal_install_tasks($install_state);
  
  return $tasks;
}