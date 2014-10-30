<?php

/**
 * Implements hook_variable_info().
 */
function mica_datasets_variable_info($options) {
  return array(
    'mica_datasets_split_dataset' => array(
      'title' => t('Split datasets by type', array(), $options),
      'description' => t('Separate study and harmonization datasets', array(), $options),
      'default' => FALSE,
      'type' => 'boolean',
      'group' => 'mica_configuration',
    ),
    'mica_datasets_connection_errors' => array(
      'title' => t('Display Opal connection errors', array(), $options),
      'description' => t('Display Opal connection errors to users', array(), $options),
      'default' => TRUE,
      'type' => 'boolean',
      'group' => 'mica_configuration',
    ),
    'mica_datasets_connection_errors_message' => array(
      'title' => t('Alternative Opal connection errors', array(), $options),
      'description' => t('The message to be displayed on Opal connection error', array(), $options),
      'default' => '',
      'type' => 'text',
      'group' => 'mica_configuration',
    ),
  );
}