<?php
/**
 * @file
 * Mica Datasets facet block configuration
 */

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');
include_once(drupal_get_path('module', 'current_search') . '/current_search.block.inc');

function mica_datasets_configure_facet_blocks() {

  $theme_default = variable_get('theme_default', 'mica_samara');
  $page = 'variable-search';
  $search_index = 'search_api@variable_index';

  // configure current search
  $nb_updated = db_update('block')->fields(
    array(
      'status' => 1,
      'region' => 'sidebar_second',
      'weight' => 0,
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'pages' => $page,
    )
  )
    ->condition('module', 'current_search')
    ->condition('delta', 'variable_current_search')
    ->condition('theme', $theme_default)
    ->execute();
  current_search_set_block_searcher('variable_current_search', $search_index);

  watchdog('mica', 'variable_current_search block configuration', array(),
    $nb_updated > 0 ? WATCHDOG_INFO : WATCHDOG_ERROR);

  // configure facets
  $facet_order_by_region = array(
    'sidebar_second' => array(
      'field_dataset:field_dataset_type',
      'field_dataset',
      'field_variable_study_var_att:field_sva_status',
      'search_api_combined_1',
      'field_data_source',
      'field_individual_participant_mea',
      'field_disease_history',
      'field_medical_health_interv',
      'field_medication',
      'field_reproductive_history',
      'field_early_life',
      'field_life_habits_behaviours',
      'field_sociodemographic_charact',
      'field_physical_environment',
      'field_social_environment',
      'field_perception_of_health',
      'field_anthropometric_structures',
      'field_body_structures',
      'field_body_functions',
      'field_laboratory_measures',
      'field_essence',
      'field_target',
      'field_period',
      'field_measure',
      'field_value_type',
    )
  );

  $facet_block_name = array(
    'field_dataset:field_dataset_type' => t('Dataset Type'),
    'field_variable_study_var_att:field_sva_status' => t('Harmonization Status'),
    'search_api_combined_1' => t('Study'),
  );

  foreach ($facet_order_by_region as $region => $facet_order) {

    $max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE theme = :theme and region = :region",
      array(
        ':theme' => $theme_default,
        ':region' => $region
      )
    )->fetchField();
    $max_weight = empty($max_weight) ? 0 : ($max_weight + 1);

    foreach ($facet_order as $index => $facet_field) {
      // facetapi_get_delta_map() is not loaded yet so we need to generate hash
      $string = facetapi_build_delta($search_index, 'block', $facet_field);
      $facet_delta = facetapi_hash_delta($string);

      if (empty($facet_delta)) {
        drupal_set_message(t('No facet defined for @facet', array('@facet' => check_plain($facet_field))), 'warning');
        continue;
      }

      $facet_weight = $max_weight + $index;

      $block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme',
        array(
          ':module' => 'facetapi',
          ':delta' => $facet_delta,
          ':theme' => $theme_default
        )
      )->fetchObject();

      // block name
      if (isset($facet_block_name[$facet_field])) {
        $block_title = $facet_block_name[$facet_field];
      }
      else {
        $field_info = field_info_instance('node', $facet_field, 'variable');
        $block_title = $field_info['label'];
      }

      debug($facet_field . ' -> ' . $block_title);

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
        
        $searcher = 'search_api@variable_index';
        $adapter = facetapi_adapter_load($searcher);
        $facet = (array) facetapi_facet_load($facet_field, $searcher);
        $realm = facetapi_realm_load('block');
        facetapi_save_facet_status($adapter, $realm, $facet, TRUE, FALSE, FALSE);
      }

      $success = $nb_updated > 0;

      if ($success) {
        collapsiblock_set_collapsible_type('facetapi', $facet_delta,
          $index < 4 ? COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT : COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT);
      }

      watchdog('mica', 'Facet block configuration for %facet (%delta)',
        array(
          '%facet' => $facet_field,
          '%delta' => $facet_delta),
        $success ? WATCHDOG_INFO : WATCHDOG_ERROR);
    }

  }

}

