<?php
/**
 * @file
 * mica_datasets.default_corresponding_node_references_presets.inc
 */

/**
 * Implements hook_default_corresponding_node_references().
 */
function mica_datasets_default_corresponding_node_references() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->node_types_content_fields = 'data_collection_event*field_dce_dataset*dataset*field_dataset_dces';
  $cnr_obj->enabled = 1;
  $export['data_collection_event*field_dce_dataset*dataset*field_dataset_dces'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->node_types_content_fields = 'dataset*field_dataset_studies*study*mica_dataset';
  $cnr_obj->enabled = 1;
  $export['dataset*field_dataset_studies*study*mica_dataset'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->node_types_content_fields = 'dataset*field_dataset_variables*variable*field_dataset';
  $cnr_obj->enabled = 1;
  $export['dataset*field_dataset_variables*variable*field_dataset'] = $cnr_obj;

  return $export;
}
