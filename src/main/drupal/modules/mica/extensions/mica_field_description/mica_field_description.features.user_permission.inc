<?php
/**
 * @file
 * mica_field_description.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_field_description_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear csv_field_description_import feeds'.
  $permissions['clear csv_field_description_import feeds'] = array(
    'name' => 'clear csv_field_description_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create field_description content'.
  $permissions['create field_description content'] = array(
    'name' => 'create field_description content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any field_description content'.
  $permissions['delete any field_description content'] = array(
    'name' => 'delete any field_description content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own field_description content'.
  $permissions['delete own field_description content'] = array(
    'name' => 'delete own field_description content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any field_description content'.
  $permissions['edit any field_description content'] = array(
    'name' => 'edit any field_description content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_description content'.
  $permissions['edit own field_description content'] = array(
    'name' => 'edit own field_description content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'import csv_field_description_import feeds'.
  $permissions['import csv_field_description_import feeds'] = array(
    'name' => 'import csv_field_description_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper csv_field_description_import'.
  $permissions['tamper csv_field_description_import'] = array(
    'name' => 'tamper csv_field_description_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  return $permissions;
}
