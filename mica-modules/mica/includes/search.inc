<?php
/**
 * @file
 * Mica search API utilities
 */

/**
 * Returns an array of search index with bundle name as keys.
 */
function _mica_find_indexes_by_bundle() {
  $indexes = array();
  foreach (entity_load('search_api_index') as $index) {
    $options = $index->options;
    if (!empty($options['data_alter_callbacks']) 
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter'])
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings'])
      && !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles']))
    foreach ($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'] as $bundle) {
      $indexes[$bundle] = array($index->machine_name => $index->name);
    }
  }
  return $indexes;
}

/**
 * Add or update field in search index 
 * Add facet for non Full Text field
 */
function _mica_add_field_index($index_name, $bundle, $field_name, $type) {
 
  if ($type === 'TEXT') {
    $field = field_info_field($field_name);
    $index_type = empty($field['settings']['allowed_values']) ? 'text' : 'string';
  } 
  else {
    $mapping = _mica_magma_search_index_type_mapping();
    $index_type = $mapping[$type];
  }
  
  $field_instance = field_info_instance('node', $field_name, $bundle);
  $field_label = $field_instance['label'];

  $index = search_api_index_load($index_name, TRUE);
  $options = $index->options;
  $fields = $options['fields'];
  $fields[$field_name] = array(
    'name' => $field_label,
    'indexed' => TRUE,
    'type' => $index_type,
    'boost' => '1.0',
  );
  search_api_index_edit_fields($index->id, $fields);
  
  $facets_conditions = array(
    'index_id' => $index->machine_name,
    'field' => $field_name,
  );
  $facet = search_api_facet_load_multiple(FALSE, $facets_conditions, TRUE);
  if ($index_type === 'text') {
    if (!empty($facet)) {
      // delete facet for full text field
      entity_delete_multiple('search_api_facet', array($facet->id));
    }
  }
  else if (empty($facet)) {       
    $facet = new SearchApiFacet(array(
      'index_id' => $index->machine_name,
      'field' => $field_name,
      'name' => $field_label,
      'enabled' => 1,
      'options' => array(),
      'status' => 0,
    ));   
    $facet->save(); 
  } 
  
}

/**
 * Disable field in search index 
 */
function _mica_remove_field_index($index_name, $field_name) {
  $index = search_api_index_load($index_name, TRUE);
  $options = $index->options;
  $fields = $options['fields'];
  if (!empty($fields[$field_name])) {
    $fields[$field_name]['indexed'] = FALSE;
  }
  search_api_index_edit_fields($index->id, $fields);  
  
  $facets_conditions = array(
    'index_id' => $index_name,
    'field' => $field_name,
  );  
  search_api_facet_delete_multiple($facets_conditions);
}

/**
 * Returns the value type mapping between Magma and Search API with Magma values as keys
 */
function _mica_magma_search_index_type_mapping() {
  return array(
    'TEXT' => 'text',
    'INTEGER' => 'integer',
    'DECIMAL' => 'decimal',
    'DATE' => 'date',
    'BOOLEAN' => 'boolean', 
  );
}

