<?php
/**
 * @file
 * mica_studies.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function mica_studies_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_access';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_access';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_access'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_biosamples_collected';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_biosamples_collected';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_biosamples_collected'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_design';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_design';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_design'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_design_target';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_design_target';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_design_target'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_gender';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_gender';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_gender'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_gwas_analysis';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_gwas_analysis';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_gwas_analysis'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_selection_criteria';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_selection_criteria';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_selection_criteria'] = $facet;

  $facet = new stdClass;
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@studies_index:block:mica_study_information:field_study_country';
  $facet->searcher = 'search_api@studies_index';
  $facet->realm = 'block';
  $facet->facet = 'mica_study_information:field_study_country';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'show_expanded' => 0,
  );
  $export['search_api@studies_index:block:mica_study_information:field_study_country'] = $facet;

  return $export;
}
