<?php

/**
 * @file
 * Hooks provided by the Mica Datasets module.
 */

/**
 * Defines one or more operations to import taxonomies.
 */
function hook_taxonomies_operations_import() {
  $operations = array();
  return $operations;
}

/**
 * Theme based on Twitter Bootstrap should implements this hook and return TRUE.
 */
function hook_bootstrap_based_theme() {
  return array('theme_name' => TRUE);
}

/*
 * hook_create_default_menu_module()
 */

function hook_create_default_menu_module() {
  // add default menu
}