<?php

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');
include_once(drupal_get_path('module', 'current_search') . '/current_search.block.inc');
include_once(drupal_get_path('module', 'mica_field_description') . '/mica_field_description.module');

function mica_studies_configure_facet_blocks() {

  $theme_default = variable_get('theme_default', 'mica_samara');

  // configure current search
  $nb_updated = db_update('block')->fields(
      array(
        'status' => 1,
        'region' => 'sidebar_second',
        'weight' => 0,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => 'studies-search',
      )
    )
    ->condition('module', 'current_search')
    ->condition('delta', 'standard')
    ->condition('theme', $theme_default)
    ->execute();
  current_search_set_block_searcher('standard', 'search_api@studies_index');
  watchdog('mica', 'Configured current_search block: %status',
    array('%status' => ($nb_updated> 0 ? 'Done' : 'Error')), WATCHDOG_DEBUG);

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
    $facet = facetapi_facet_load($disabled_facet, $searcher);
    if ($facet) {
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
    	'field_design',
    	'field_data_sources',
  		'field_select_criteria',
    	'field_country',
    	'field_selection_gender',
    	'field_age_min',
    	'field_age_max',
    	),
    'sidebar_first' => array(
      'field_target_number_participants',
      'field_target_number_biosamples',
      'field_access_data',
      'field_access_biosamples',
      'field_bio_samples_management',
      'field_recruitment',
      'field_recruitment_procedures',
      'field_preparation_start_year',
      'field_preparation_end_year',
      'field_baseline_start_year',
      'field_baseline_end_year',
      'field_followup_start_year',
      'field_followup_end_year',
      'field_ended_end_year',
    )
  );
  
  foreach ($facet_order_by_region as $region => $facet_order) {
    
    $max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE theme = :theme and region = :region",
      array(
      	':theme' => $theme_default, 
        ':region' => $region
      )
    )->fetchField();
    $max_weight = empty($max_weight) ? 0 : ($max_weight + 1);
    
    foreach ($facet_order as $index => $facet) {
      // facetapi_get_delta_map() is not loaded yet so we need to generate hash
      $facet_delta = facetapi_hash_delta('search_api@studies_index:block:' . $facet);
      
      if (empty($facet_delta)) {
        drupal_set_message('No facet defined for ' . $facet, 'warning');
        continue;
      }
      
    	$facet_weight = $max_weight + $index;

      $nb_updated = db_update('block')->fields(
          array(
            'status' => 1,
            'region' => $region,
            'weight' => $facet_weight,
            'visibility' => BLOCK_VISIBILITY_LISTED,
            'pages' => 'studies-search',
          )
        )
        ->condition('module', 'facetapi')
        ->condition('delta', $facet_delta)
        ->condition('theme', $theme_default)
        ->execute();

      watchdog('mica', 'Configured facet block %facet: %status',
        array('%facet' => $facet, '%status' => ($nb_updated> 0 ? 'Done' : 'Error')), WATCHDOG_DEBUG);
    }    
    
  }

}

