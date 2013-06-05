<?php
/**
 * @file
 * mica_core.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function mica_core_filter_default_formats() {
  $formats = array();

  // Exported format: Bootstrap.
  $formats['bootstrap'] = array(
    'format' => 'bootstrap',
    'name' => 'Bootstrap',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array('bootstrap'),
  );

  return $formats;
}