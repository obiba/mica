<?php

/**
 * @file
 * Obiba Mica client module settings UI.
 */

/**
 * Provides settings pages.
 */
function mica_export_client_model_admin_settings() {
  $form['server'] = array(
    '#type' => 'fieldset',
    '#title' => t('OBiBa study server (Mica)'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $info = variable_get_info('mica_url');
  $form['server']['mica_url'] = array(
    '#type' => 'textfield',
    '#title' => $info['title'],
    '#required' => TRUE,
    '#default_value' => variable_get_value('mica_url'),
    '#maxlength' => 255,
    '#description' => $info['description'],
  );

  $info = variable_get_info('mica_admin_name');
  $form['server']['mica_admin_name'] = array(
    '#type' => 'textfield',
    '#title' => $info['title'],
    '#required' => TRUE,
    '#default_value' => variable_get_value('mica_admin_name'),
    '#maxlength' => 255,
    '#description' => $info['description'],
  );

  $info = variable_get_info('mica_admin_password');
  $form['server']['mica_admin_password'] = array(
    '#type' => 'password',
    '#title' => $info['title'],
    '#required' => TRUE,
    '#default_value' => variable_get_value('mica_admin_password'),
    '#maxlength' => 255,
    '#description' => $info['description'],
  );

  return system_settings_form($form);
}
