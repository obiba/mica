<?php

/**
 * Implements hook_variable_group_info().
 */
function mica_core_variable_group_info() {
  return array(
    'mica_configuration' => array(
      'title' => t('Mica'),
      'description' => t('Mica Configuration'),
      'access' => 'administer site configuration',
      'path' => array('admin/config/system/variable/mica'),
    )
  );
}