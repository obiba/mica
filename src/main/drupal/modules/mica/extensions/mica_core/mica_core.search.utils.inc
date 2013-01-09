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
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'])) {
      foreach ($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'] as $bundle) {
        $indexes[$bundle] = array($index->machine_name => $index->name);
      }
    }
  }
  return $indexes;
}

/**
 * WARNING:
 * Cannot execute this from hook_post_features_rebuild() because of exceptions like
 * Notice: Undefined index: name in FacetapiAdapter->getFacet() (line 823 of sites/all/modules/facetapi/plugins/facetapi/adapter.inc).
 *
 * @param string $search_index index machine name ('variable_index' for example)
 * @param string $content_type
 * @param array $config facet block configuration
 * <code>
 *  $config = array(
 *    'field_bundle' => array(
 *      'name' => t('Content type'),
 *      'collapsible' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
 *    ),
 *  );
 * </code>
 * @param string $page path of the page where to display these blocks ('variable-search' for example)
 * @param string $current_search_delta delta of the current search block ('variable_current_search' for example)
 * @param string $region
 * @throws Exception
 */
function mica_core_configure_facet_blocks($search_index, $content_type, array $config, $page,
  $current_search_delta = NULL, $region = 'sidebar_first') {

  $theme_default = variable_get('theme_default', 'mica_subtheme');
  $search_index = 'search_api@' . $search_index;

  // configure current search
  if (!empty($current_search_delta)) {
    $nb_updated = db_update('block')->fields(
      array(
        'status' => 1,
        'region' => $region,
        'weight' => 0,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => $page,
      )
    )
      ->condition('module', 'current_search')
      ->condition('delta', $current_search_delta)
      ->condition('theme', $theme_default)
      ->execute();
    current_search_set_block_searcher('variable_current_search', $search_index);

    watchdog('mica', 'variable_current_search block configuration', array(),
      $nb_updated > 0 ? WATCHDOG_INFO : WATCHDOG_ERROR);
  }

  $max_weight = db_query('SELECT MAX(weight) as max_weight FROM {block} '
      . 'WHERE theme = :theme and region = :region and delta <> :delta',
    array(
      ':theme' => $theme_default,
      ':region' => $region,
      ':delta' => 'mica-search-filters',
    )
  )->fetchField();
  $max_weight = empty($max_weight) ? 0 : ($max_weight + 1);

  $index = 0;
  foreach ($config as $facet_name => $block_config) {

    try {

      // facetapi_get_delta_map() is not loaded yet so we need to generate hash
      $string = facetapi_build_delta($search_index, 'block', $facet_name);
      $facet_delta = facetapi_hash_delta($string);

      if (empty($facet_delta)) {
        drupal_set_message(t('No facet defined for @facet', array('@facet' => check_plain($facet_name))), 'warning');
        continue;
      }

      // block name
      if (isset($block_config['name']) && !empty($block_config['name'])) {
        $block_title = $block_config['name'];
      }
      else {
        $field_info = field_info_instance('node', $facet_name, $content_type);
        $block_title = $field_info['label'];
      }

      if (drupal_strlen($block_title) > 64) {
        $block_title = truncate_utf8($block_title, 64, TRUE);
      }

      $facet_weight = $max_weight + $index++;

      $block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme',
        array(
          ':module' => 'facetapi',
          ':delta' => $facet_delta,
          ':theme' => $theme_default
        )
      )->fetchObject();

      if ($block) {
        $nb_updated = db_update('block')->fields(
          array(
            'status' => 1,
            'region' => $region,
            'weight' => $facet_weight,
            'visibility' => BLOCK_VISIBILITY_LISTED,
            'pages' => $page,
            'title' => $block_title,
          )
        )
          ->condition('module', 'facetapi')
          ->condition('delta', $facet_delta)
          ->condition('theme', $theme_default)
          ->execute();
      }
      else {

        $nb_updated = db_insert('block')->fields(
          array(
            'status' => 1,
            'region' => $region,
            'weight' => $facet_weight,
            'visibility' => BLOCK_VISIBILITY_LISTED,
            'pages' => $page,
            'custom' => BLOCK_CUSTOM_ENABLED, // Show this block by default but let individual users hide it.
            'delta' => $facet_delta,
            'module' => 'facetapi',
            'theme' => $theme_default,
            'title' => $block_title,
          )
        )
          ->execute();

        $adapter = facetapi_adapter_load($search_index);
        $facet = (array) facetapi_facet_load($facet_name, $search_index);
        $realm = facetapi_realm_load('block');
        facetapi_save_facet_status($adapter, $realm, $facet, TRUE, FALSE, FALSE);
      }

      $success = $nb_updated > 0;

      if ($success) {

        $collapsible = isset($block_config['collapsible']) && !empty($block_config['collapsible'])
          ? $block_config['collapsible']
          : COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT;
        collapsiblock_set_collapsible_type('facetapi', $facet_delta, $collapsible);
      }

      watchdog('mica', 'Facet block configuration for %facet (%delta)',
        array(
          '%facet' => $facet_name,
          '%delta' => $facet_delta
        ),
        $success ? WATCHDOG_INFO : WATCHDOG_ERROR);
    } catch (Exception $e) {
      watchdog_exception('mica', $e, 'Error while configuring facet %facet for %index for %region region (%config)',
        array('%facet' => $facet_name, '%index' => $search_index, '%region' => $region, '%config' => $block_config));
      throw $e;
    }
  }
}

/**
 * Enable facet block
 */
function mica_core_enable_facet_block($facet_delta, $block_title, $page, $region = 'sidebar_first') {

  $theme_default = variable_get('theme_default', 'mica_subtheme');

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
  if (drupal_strlen($block_title) > 64) {
    $block_title = truncate_utf8($block_title, 64, TRUE);
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
