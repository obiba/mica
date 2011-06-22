<?php
/**
 * @file
 * mica_datasets.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_datasets_user_default_permissions() {
  $permissions = array();

  // Exported permission: create dataset content
  $permissions['create dataset content'] = array(
    'name' => 'create dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create participant_variable content
  $permissions['create participant_variable content'] = array(
    'name' => 'create participant_variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dataset content
  $permissions['delete any dataset content'] = array(
    'name' => 'delete any dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any participant_variable content
  $permissions['delete any participant_variable content'] = array(
    'name' => 'delete any participant_variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dataset content
  $permissions['delete own dataset content'] = array(
    'name' => 'delete own dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own participant_variable content
  $permissions['delete own participant_variable content'] = array(
    'name' => 'delete own participant_variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dataset content
  $permissions['edit any dataset content'] = array(
    'name' => 'edit any dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any participant_variable content
  $permissions['edit any participant_variable content'] = array(
    'name' => 'edit any participant_variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dataset content
  $permissions['edit own dataset content'] = array(
    'name' => 'edit own dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own participant_variable content
  $permissions['edit own participant_variable content'] = array(
    'name' => 'edit own participant_variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
