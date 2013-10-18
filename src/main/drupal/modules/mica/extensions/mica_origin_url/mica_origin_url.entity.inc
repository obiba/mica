<?php

/**
 * @file
 * Entity related functions for mica_origin_url  module.
 */

/**
 * Helper function that returns entity info for all supported core modules,
 * relevant for mica_origin_url functionality.
 *
 * @see mica_origin_url_entity_info()
 * @see mica_origin_url_schema_alter()
 * @see mica_origin_url_install()
 * @see mica_origin_url_uninstall()
 */

/**
 * Implements of hook_entity_info_alter().
 *
 * @see mica_origin_url_core_entity_info().
 */
function mica_origin_url_entity_info_alter(&$info) {
  $core_info = array(
    'base table' => 'node',
    'entity keys' => array(
      'mica_origin_url' => 'mica_origin_url'
    )
  );
  $info['node']['mica_origin_url'] = TRUE;
  $info['node']['entity keys']['mica_origin_url'] = $core_info['entity keys']['mica_origin_url'];
}

/**
 * Implements of hook_entity_property_info_alter().
 *
 * This adds the mica_origin_url  as an entity property for all mica_origin_url-enabled entities
 * which automatically gives us token and Rules integration.
 */
function mica_origin_url_entity_property_info_alter(&$info) {
  foreach (entity_get_info() as $entity_type => $entity_info) {
    if (isset($entity_info['mica_origin_url'])
      && $entity_info['mica_origin_url'] == TRUE
      && !empty($entity_info['entity keys']['mica_origin_url'])
    ) {

      $info[$entity_type]['properties'][$entity_info['entity keys']['mica_origin_url']] = array(
        'label' => t('Mica Origin Url'),
        'type' => 'text',
        'description' => t('Mica Origin Url'),
        'schema field' => $entity_info['entity keys']['mica_origin_url'],
      );
    }
  }
}

///**
// * Implements of hook_entity_presave().
// */
function mica_origin_url_entity_presave($entity, $entity_type) {
  global $base_url;
  if ($entity_type === 'node' && empty($entity->mica_origin_url)) {
    $entity->mica_origin_url = $base_url;
  }
}