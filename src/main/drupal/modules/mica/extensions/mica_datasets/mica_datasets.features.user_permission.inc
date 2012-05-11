<?php
/**
 * @file
 * mica_datasets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_datasets_user_default_permissions() {
  $permissions = array();

  // Exported permission: create dataset content.
  $permissions['create dataset content'] = array(
    'name' => 'create dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'dataset reviewer',
      4 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create edit delete own dataset query.
  $permissions['create edit delete own dataset query'] = array(
    'name' => 'create edit delete own dataset query',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'mica_datasets',
  );

  // Exported permission: create study_variable_attributes content.
  $permissions['create study_variable_attributes content'] = array(
    'name' => 'create study_variable_attributes content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create variable content.
  $permissions['create variable content'] = array(
    'name' => 'create variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dataset content.
  $permissions['delete any dataset content'] = array(
    'name' => 'delete any dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study_variable_attributes content.
  $permissions['delete any study_variable_attributes content'] = array(
    'name' => 'delete any study_variable_attributes content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any variable content.
  $permissions['delete any variable content'] = array(
    'name' => 'delete any variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dataset content.
  $permissions['delete own dataset content'] = array(
    'name' => 'delete own dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study_variable_attributes content.
  $permissions['delete own study_variable_attributes content'] = array(
    'name' => 'delete own study_variable_attributes content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own variable content.
  $permissions['delete own variable content'] = array(
    'name' => 'delete own variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dataset content.
  $permissions['edit any dataset content'] = array(
    'name' => 'edit any dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study_variable_attributes content.
  $permissions['edit any study_variable_attributes content'] = array(
    'name' => 'edit any study_variable_attributes content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any variable content.
  $permissions['edit any variable content'] = array(
    'name' => 'edit any variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit delete any dataset query.
  $permissions['edit delete any dataset query'] = array(
    'name' => 'edit delete any dataset query',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'study administrator',
    ),
    'module' => 'mica_datasets',
  );

  // Exported permission: edit own dataset content.
  $permissions['edit own dataset content'] = array(
    'name' => 'edit own dataset content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'dataset reviewer',
      4 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study_variable_attributes content.
  $permissions['edit own study_variable_attributes content'] = array(
    'name' => 'edit own study_variable_attributes content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own variable content.
  $permissions['edit own variable content'] = array(
    'name' => 'edit own variable content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: publish dataset query.
  $permissions['publish dataset query'] = array(
    'name' => 'publish dataset query',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'study administrator',
    ),
    'module' => 'mica_datasets',
  );

  // Exported permission: view any dataset query.
  $permissions['view any dataset query'] = array(
    'name' => 'view any dataset query',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'mica_datasets',
  );

  return $permissions;
}
