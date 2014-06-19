<?php
/**
 * @file
 * mica_publications.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_publications_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@publications';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@publications'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_publication';
  $strongarm->value = 'main-menu:653';
  $export['menu_parent_publication'] = $strongarm;

  return $export;
}
