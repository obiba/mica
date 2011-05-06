<?php
// $Id$

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
	
  module_load_include('inc', 'mica', 'includes/relations');	
 
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
  
  // check if this bundle is a child of a relation
  $relation = _mica_find_relation_by_child($bundle);
  if (!empty($relation)) {
  	$field_name = $relation['node_reference'] . ':' . $field_name;
  	$bundle_info = node_type_load($bundle);
  	$field_label = $bundle_info->name . ' » ' . $field_label;
  }  
  
  // check if we need to reindex content
  if (empty($fields[$field_name])) {
    $reindex = TRUE;
  } 
  else {
    $reindex = $fields[$field_name]['name'] != $field_label
      || !$fields[$field_name]['indexed']
      || $fields[$field_name]['type'] != $index_type;
  }
  
  $fields[$field_name] = array(
    'name' => $field_label,
    'indexed' => TRUE,
    'type' => $index_type,
    'boost' => '1.0',
  );
  search_api_index_edit_fields($index->id, $fields);
  
  if ($reindex) {
    $index->reindex();
  }
    
  // facet
 $facets_conditions = array(
    'index_id' => $index->machine_name,
    'field' => $field_name,
  );
  $facet = search_api_facet_load_multiple(FALSE, $facets_conditions, TRUE);
  if (_mica_is_type_supports_facet($index_type)) {
  	if (empty($facet)) {
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
  	elseif ($reindex) { 
  		// field was changed, update facet
  		$facet->field = $field_name;
  		$facet->name = $field_label;
  		$facet->enabled = 1;
  		$facet->save(); 
  	}
  } 
  elseif (!empty($facet)) {
		// delete facet for unsupported field type
    entity_delete_multiple('search_api_facet', array($facet->id));  	
  }
  
  // ranges
  $range = search_api_range_load_multiple(FALSE, $facets_conditions, TRUE);
  if (_mica_is_type_supports_ranges($index_type)) {
  	if (empty($range)) {
			$range = new SearchApiRange(array(
	      'index_id' => $index->machine_name,
	      'field' => $field_name,
	      'name' => $field_label,
	      'enabled' => 1,
	      'options' => array(),
	      'status' => 0,
	    ));     		
  		$range->save(); 
  	} 
  	elseif ($reindex) { 
  		// field was changed, update facet
  		$range->field = $field_name;
  		$range->name = $field_label;
  		$range->enabled = 1;
  		$range->save(); 
  	}
  } 
  elseif (!empty($range)) {
		// delete range for unsupported field type
    entity_delete_multiple('search_api_range', array($range->id));  	
  }
}

function _mica_is_type_supports_facet($index_type) {
	return $index_type === 'string' || $index_type === 'boolean'; 
}

function _mica_is_type_supports_ranges($index_type) {
	return $index_type === 'integer' || $index_type === 'decimal' || $index_type === 'date'; 
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
    search_api_index_edit_fields($index->id, $fields);
    $index->reindex();      
  }
  
  $facets_conditions = array(
    'index_id' => $index_name,
    'field' => $field_name,
  );  
  search_api_facet_delete_multiple($facets_conditions);
	search_api_range_delete_multiple($facets_conditions);  	  
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

