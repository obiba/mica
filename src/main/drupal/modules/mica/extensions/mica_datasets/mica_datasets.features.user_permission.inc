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

  // Exported permission: 'clear csv_variables feeds'.
  $permissions['clear csv_variables feeds'] = array(
    'name' => 'clear csv_variables feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear dataset feeds'.
  $permissions['clear dataset feeds'] = array(
    'name' => 'clear dataset feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create dataset content'.
  $permissions['create dataset content'] = array(
    'name' => 'create dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create study_variable_attributes content'.
  $permissions['create study_variable_attributes content'] = array(
    'name' => 'create study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create variable content'.
  $permissions['create variable content'] = array(
    'name' => 'create variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any dataset content'.
  $permissions['delete any dataset content'] = array(
    'name' => 'delete any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any study_variable_attributes content'.
  $permissions['delete any study_variable_attributes content'] = array(
    'name' => 'delete any study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any variable content'.
  $permissions['delete any variable content'] = array(
    'name' => 'delete any variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dataset content'.
  $permissions['delete own dataset content'] = array(
    'name' => 'delete own dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own study_variable_attributes content'.
  $permissions['delete own study_variable_attributes content'] = array(
    'name' => 'delete own study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own variable content'.
  $permissions['delete own variable content'] = array(
    'name' => 'delete own variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dataset content'.
  $permissions['edit any dataset content'] = array(
    'name' => 'edit any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any study_variable_attributes content'.
  $permissions['edit any study_variable_attributes content'] = array(
    'name' => 'edit any study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any variable content'.
  $permissions['edit any variable content'] = array(
    'name' => 'edit any variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dataset content'.
  $permissions['edit own dataset content'] = array(
    'name' => 'edit own dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own study_variable_attributes content'.
  $permissions['edit own study_variable_attributes content'] = array(
    'name' => 'edit own study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own variable content'.
  $permissions['edit own variable content'] = array(
    'name' => 'edit own variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'import csv_variables feeds'.
  $permissions['import csv_variables feeds'] = array(
    'name' => 'import csv_variables feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import dataset feeds'.
  $permissions['import dataset feeds'] = array(
    'name' => 'import dataset feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper csv_variables'.
  $permissions['tamper csv_variables'] = array(
    'name' => 'tamper csv_variables',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper dataset'.
  $permissions['tamper dataset'] = array(
    'name' => 'tamper dataset',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'view any unpublished dataset content'.
  $permissions['view any unpublished dataset content'] = array(
    'name' => 'view any unpublished dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished study_variable_attributes content'.
  $permissions['view any unpublished study_variable_attributes content'] = array(
    'name' => 'view any unpublished study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished variable content'.
  $permissions['view any unpublished variable content'] = array(
    'name' => 'view any unpublished variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
