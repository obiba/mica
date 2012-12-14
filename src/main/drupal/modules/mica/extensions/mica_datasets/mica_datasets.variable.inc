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
  );
}