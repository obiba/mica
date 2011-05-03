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
		if(!empty($options['data_alter_callbacks']) 
			&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter'])
			&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings'])
			&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles']))
		foreach ($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'] as $bundle) {
			$indexes[$bundle] = array($index->machine_name => $index->name);
		}
	}
	return $indexes;
}


function _mica_add_field_index($index_name, $bundle, $field_name, $type) {
 
	if($type === 'TEXT') {
	  $field = field_info_field($field_name);
	  $index_type = empty($field['settings']['allowed_values']) ? 'text' : 'string';
	} 
	else {
	  $mapping = _mica_magma_search_index_type_mapping();
	  $index_type = $mapping[$type];
	}
	
  $field_instance = field_info_instance('node', $field_name, $bundle);

	$index = search_api_index_load($index_name, TRUE);
  $options = $index->options;
  $fields = $options['fields'];
	$fields[$field_name] = array(
  	'name' => $field_instance['label'],
    'indexed' => TRUE,
    'type' => $index_type,
		'boost' => '1.0',
  );
  search_api_index_edit_fields($index->id, $fields);
}

function _mica_remove_field_index($index_name, $field_name) {
  debug($index_name, '$index_name');
  $index = search_api_index_load($index_name, TRUE);
  $options = $index->options;
  $fields = $options['fields'];
  if(!empty($fields[$field_name])) {
    $fields[$field_name]['indexed'] = FALSE;
  }
  search_api_index_edit_fields($index->id, $fields);  
}


function _mica_magma_search_index_type_mapping() {
  return array(
    'TEXT' => 'text',
    'INTEGER' => 'integer',
    'DECIMAL' => 'decimal',
    'DATE' => 'date',
    'BOOLEAN' => 'boolean', 
  );
}

