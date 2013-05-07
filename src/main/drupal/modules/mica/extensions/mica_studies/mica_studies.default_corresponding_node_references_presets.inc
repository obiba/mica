<?php
/**
 * @file
 * mica_studies.default_corresponding_node_references_presets.inc
 */

/**
 * Implements hook_default_corresponding_node_references().
 */
function mica_studies_default_corresponding_node_references() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->node_types_content_fields = 'data_collection_event*field_dce_population*population*field_pop_dce';
  $cnr_obj->enabled = 1;
  $export['data_collection_event*field_dce_population*population*field_pop_dce'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->node_types_content_fields = 'population*field_pop_study*study*field_study_populations';
  $cnr_obj->enabled = 1;
  $export['population*field_pop_study*study*field_study_populations'] = $cnr_obj;

  return $export;
}
