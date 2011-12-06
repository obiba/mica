<?php
/**
 * @file
 * mica_dataschemas.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_dataschemas_user_default_permissions() {
  $permissions = array();

  // Exported permission: create dataschema content
  $permissions['create dataschema content'] = array(
    'name' => 'create dataschema content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dataschema_variable content
  $permissions['create dataschema_variable content'] = array(
    'name' => 'create dataschema_variable content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create pairing content
  $permissions['create pairing content'] = array(
    'name' => 'create pairing content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dataschema content
  $permissions['delete any dataschema content'] = array(
    'name' => 'delete any dataschema content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dataschema_variable content
  $permissions['delete any dataschema_variable content'] = array(
    'name' => 'delete any dataschema_variable content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any pairing content
  $permissions['delete any pairing content'] = array(
    'name' => 'delete any pairing content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dataschema content
  $permissions['delete own dataschema content'] = array(
    'name' => 'delete own dataschema content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dataschema_variable content
  $permissions['delete own dataschema_variable content'] = array(
    'name' => 'delete own dataschema_variable content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own pairing content
  $permissions['delete own pairing content'] = array(
    'name' => 'delete own pairing content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dataschema content
  $permissions['edit any dataschema content'] = array(
    'name' => 'edit any dataschema content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dataschema_variable content
  $permissions['edit any dataschema_variable content'] = array(
    'name' => 'edit any dataschema_variable content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any pairing content
  $permissions['edit any pairing content'] = array(
    'name' => 'edit any pairing content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dataschema content
  $permissions['edit own dataschema content'] = array(
    'name' => 'edit own dataschema content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dataschema_variable content
  $permissions['edit own dataschema_variable content'] = array(
    'name' => 'edit own dataschema_variable content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own pairing content
  $permissions['edit own pairing content'] = array(
    'name' => 'edit own pairing content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
