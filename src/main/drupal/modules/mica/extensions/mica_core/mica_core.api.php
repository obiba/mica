<?php

/**
 * @file
 * Hooks provided by the Mica Datasets module.
 */


/**
 * Create default content after site is setup
 */
function hook_create_default_content() {
}

/**
 * Defines one or more operations to import taxonomies.
 * //TODO merge this with hook_create_default_content
 */
function hook_taxonomies_operations_import() {
  $operations = array();
  return $operations;
}

