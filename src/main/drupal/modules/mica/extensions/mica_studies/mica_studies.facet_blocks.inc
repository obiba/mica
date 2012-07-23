<?php
/**
 * @file
 * Studies facet blocks configuration
 */

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');
include_once(drupal_get_path('module', 'current_search') . '/current_search.block.inc');
include_once(drupal_get_path('module', 'mica_field_description') . '/mica_field_description.module');
include_once(drupal_get_path('module', 'mica_core') . '/mica_core.search.utils.inc');


function mica_studies_configure_facet_blocks() {

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
          _mica_field_description_disable_search_block($delta);
        }
      }
    }
  }

  $config = array(
    'field_design' => array(),
    'field_country' => array(),
    'field_age_min' => array(),
    'field_age_max' => array(),
    'field_gender' => array(),
    'field_target_number_participants' => array(),
    'field_target_number_biosamples' => array(),
    'field_bio_samples_management' => array(),
    'field_select_criteria' => array(),
    'field_data_sources' => array(),
    'field_recruitment' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_recruitment_sources' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_access_data' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_access_biosamples' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_preparation_start_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_preparation_end_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_baseline_start_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_baseline_end_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_followup_start_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_followup_end_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
    'field_ended_end_year' => array(
      'collapsible' => COLLAPSIBLOCK_TYPE_COLLAPSED_BY_DEFAULT
    ),
  );
  mica_core_configure_facet_blocks('studies_index', 'study', $config, 'studies-search', 'study_current_search');
}
