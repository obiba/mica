<?php

/**
 * @file
 * Search API utilities
 */

/**
 * Returns an array of search index with bundle name as keys.
 */
function mica_core_find_indexes_by_bundle() {
  $indexes = array();
  foreach (entity_load('search_api_index') as $index) {
    $options = $index->options;
    if (!empty($options['data_alter_callbacks'])
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter'])
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings'])
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'])
    )
      foreach ($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'] as $bundle) {
        $indexes[$bundle] = array($index->machine_name => $index->name);
      }
  }
  return $indexes;
}

/**
 * Enable facet block
 */
function mica_core_enable_facet_block($facet_delta, $block_title, $page, $region = 'sidebar_second') {

  $theme_default = variable_get('theme_default', 'mica_samara');

  $max_weight = db_query(
    "SELECT MAX(weight) as max_weight FROM {block} WHERE module = :module AND theme = :theme and region = :region",
    array(
      ':module' => 'facetapi',
      ':theme' => $theme_default,
      ':region' => $region
    )
  )->fetchField();
  $facet_weight = empty($max_weight) ? 0 : ($max_weight + 1);

  $block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme',
    array(
      ':module' => 'facetapi',
      ':delta' => $facet_delta,
      ':theme' => $theme_default
    )
  )->fetchObject();

  // trim to 64 char max because of block table title field limitation
  if (strlen($block_title) > 64) {
    $block_title = substr($block_title, 0, 64);
  }

  if ($block) {
    db_update('block')->fields(
      array(
        'status' => 1,
        'region' => $region,
        'weight' => $facet_weight,
        'pages' => $page,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'title' => $block_title,
      )
    )
      ->condition('module', 'facetapi')
      ->condition('delta', $facet_delta)
      ->condition('theme', $theme_default)
      ->execute();
  }
  else {
    db_insert('block')->fields(
      array(
        'status' => 1,
        'region' => $region,
        'weight' => $facet_weight,
        'custom' => BLOCK_CUSTOM_ENABLED, // Show this block by default but let individual users hide it.
        'delta' => $facet_delta,
        'module' => 'facetapi',
        'theme' => $theme_default,
        'pages' => $page,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'title' => $block_title,
      )
    )
      ->execute();
  }

  collapsiblock_set_collapsible_type('facetapi', $facet_delta, COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT);
}
