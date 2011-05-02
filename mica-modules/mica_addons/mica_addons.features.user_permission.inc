<?php
/**
 * @file
 * mica_addons.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_addons_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog content
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create event content
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create forum content
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any blog content
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any event content
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any forum content
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own blog content
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own event content
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own forum content
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any blog content
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any event content
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any forum content
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own blog content
  $permissions['edit own blog content'] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own event content
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own forum content
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
