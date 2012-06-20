<?php
/**
 * @file
 * Studies facet blocks configuration
 */

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');
include_once(drupal_get_path('module', 'current_search') . '/current_search.block.inc');
include_once(drupal_get_path('module', 'mica_field_description') . '/mica_field_description.module');

function mica_studies_configure_facet_blocks() {

  $theme_default = variable_get('theme_default', 'mica_samara');
  $page = 'studies-search';

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
    ->condition('delta', 'study_current_search')
    ->condition('theme', $theme_default)
    ->execute();
  current_search_set_block_searcher('study_current_search', 'search_api@studies_index');

  watchdog('mica', 'Configured study_current_search block: %status',
    array('%status' => ($nb_updated > 0 ? 'Done' : 'Error')), WATCHDOG_DEBUG);

  // disable some facets because Features/FacetAPI always export them as enabled: http://drupal.org/node/1439950
  $disabled_facets = array(
    'field_access_other',
    'field_current_part_nb_date',
    'field_current_samples_date',
    'field_no_limits_participants',
    'field_no_limits_samples',
    'field_current_participants_nb',
    'field_current_samples_nb',
  );
  $searcher = 'search_api@studies_index';
  foreach ($disabled_facets as $disabled_facet) {
    $facet = (array) facetapi_facet_load($disabled_facet, $searcher);
    if (!empty($facet) && isset($facet['name'])) {
      $adapter = facetapi_adapter_load($searcher);
      $realms = facetapi_get_realm_info();
      foreach ($realms as $realm_name => $realm) {
        $delta = facetapi_hash_delta(facetapi_build_delta($searcher, $realm_name, $facet['name']));
        if (facetapi_save_facet_disabled($adapter, $realm, $facet)) {
          _disable_search_block($delta);
        }
      }
    }
  }

  // configure facets
  $facet_order_by_region = array(
    'sidebar_second' => array(
      'field_design' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_country' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_age_min' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_age_max' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_gender' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_target_number_participants' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_target_number_biosamples' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_bio_samples_management' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_select_criteria' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_data_sources' => COLLAPSIBLOCK_TYPE_EXPANDED_BY_DEFAULT,
      'field_recruitment' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_recruitment_sources' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_access_data' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_access_biosamples' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_preparation_start_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_preparation_end_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_baseline_start_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_baseline_end_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_followup_start_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_followup_end_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
      'field_ended_end_year' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT,
    )
  );

  mica_studies_configure_facets($facet_order_by_region, $page, $theme_default);
}

function mica_studies_configure_facets($facet_order_by_region, $page, $theme_default) {

  foreach ($facet_order_by_region as $region => $facet_order) {

    $max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE theme = :theme and region = :region",
      array(
        ':theme' => $theme_default,
        ':region' => $region
      )
    )->fetchField();
    $max_weight = empty($max_weight) ? 0 : ($max_weight + 1);

    $index = 0;
    foreach ($facet_order as $facet_field => $collapsible_status) {

      // facetapi_get_delta_map() is not loaded yet so we need to generate hash
      $string = facetapi_build_delta('search_api@studies_index', 'block', $facet_field);
      $facet_delta = facetapi_hash_delta($string);

      if (empty($facet_delta)) {
        drupal_set_message(t('No facet defined for @facet', array('@facet' => check_plain($facet_field))), 'warning');
        continue;
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
          )
        )
          ->condition('module', 'facetapi')
          ->condition('delta', $facet_delta)
          ->condition('theme', $theme_default)
          ->execute();
      }
      else {

        $field_info = field_info_instance('node', $facet_field, 'study');
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
            'title' => truncate_utf8($field_info['label'], 64),
            'cache' => -1,
          )
        )
          ->execute();

        $searcher = 'search_api@studies_index';
        $adapter = facetapi_adapter_load($searcher);
        $facet = (array) facetapi_facet_load($facet_field, $searcher);
        $realm = facetapi_realm_load('block');
        facetapi_save_facet_status($adapter, $realm, $facet, TRUE, FALSE, FALSE);
      }

      $success = $nb_updated > 0;

      if ($success) {
        collapsiblock_set_collapsible_type('facetapi', $facet_delta, $collapsible_status);
      }

      watchdog('mica', 'Facet block configuration for %facet (%delta)',
        array(
          '%facet' => $facet_field,
          '%delta' => $facet_delta),
        $success ? WATCHDOG_INFO : WATCHDOG_ERROR);

    }
  }

}