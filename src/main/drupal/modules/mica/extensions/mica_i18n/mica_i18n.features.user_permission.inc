<?php
/**
 * @file
 * mica_i18n.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_i18n_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer content translations.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: administer entity translation.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: administer languages.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: toggle field translatability.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate admin strings.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: translate any entity.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate comment entities.
  $permissions['translate comment entities'] = array(
    'name' => 'translate comment entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate interface.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: translate node entities.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'dataset administrator',
      3 => 'dataset reviewer',
      4 => 'study administrator',
      5 => 'study reviewer',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate taxonomy_term entities.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate user entities.
  $permissions['translate user entities'] = array(
    'name' => 'translate user entities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: translate user-defined strings.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'i18n_string',
  );

  return $permissions;
}
