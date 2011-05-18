<?php
// $Id$

/**
 * @file
 * Mica search API utilities
 */

/**
 * Create or update search index for this field description
 * @param stdClass $field_description
 */
function _mica_update_index_for_field_description(stdClass $field_description) {
  
  $field_bundle = $field_description->field_bundle;
  $bundle = $field_bundle[LANGUAGE_NONE][0]['value'];  

  $indexes = _mica_find_indexes_by_bundle();
  $bundles_indexes = $indexes[$bundle];
  if (!empty($bundles_indexes)) {
    foreach ($bundles_indexes as $index_machine_name => $index_name) {
      _mica_add_field_index($index_machine_name, $field_description);
    }
  }  
}

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
 * 
 * @param string $index_name
 * @param stdClass $field_description  
 */
function _mica_add_field_index($index_name, stdClass $field_description) {
	
  module_load_include('inc', 'mica', 'includes/relations');	

  $field_bundle = $field_description->field_bundle;
  $bundle = $field_bundle[LANGUAGE_NONE][0]['value'];  
  
  $field_original_field_name = $field_description->field_original_field_name;
  $field_name = $field_original_field_name[LANGUAGE_NONE][0]['value'];  
  
  $field_value_type = $field_description->field_value_type;
  $type = $field_value_type[LANGUAGE_NONE][0]['value'];  

  $field_repeatable = $field_description->field_repeatable;
  $repeatable = $field_repeatable[LANGUAGE_NONE][0]['value'];  

  $field_discrete = $field_description->field_discrete;
  $discrete = $field_discrete[LANGUAGE_NONE][0]['value'];  
  
  if ($type === 'TEXT') {
    $field = field_info_field($field_name);
    $index_type = empty($field['settings']['allowed_values']) ? 'text' : 'string';
  } 
  else {
    $mapping = _mica_magma_search_index_type_mapping();
    $index_type = $mapping[$type];
  }
  
  if ($repeatable) {
  	$index_type = 'list<' . $index_type . '>';
  }
  
  $field_instance = field_info_instance('node', $field_name, $bundle);
  $field_label = $field_instance['label'];

  $index = search_api_index_load($index_name, TRUE);
  $options = $index->options;
  $fields = $options['fields'];
  
  // check if this bundle is a child of a relation
  $relation = _mica_find_relation_by_child($bundle);
  if (!empty($relation)) {
  	$field_name = $relation->options['node_reference'] . ':' . $field_name;
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
  
  // trim facet name to 80
  $facet_name = $field_label;
  if (drupal_strlen($facet_name) > 80) {
    $facet_name = drupal_substr($facet_name, 0 , 77) . '...';
  }
    
  // facet
  $facets_conditions = array(
  	'index_id' => $index->machine_name,
    'field' => $field_name,
  );
  
  $facet_array = search_api_facet_load_multiple(FALSE, $facets_conditions, TRUE);
  $facet_key = array_keys($facet_array);
  $facet = empty($facet_key) ? NULL : $facet_array[$facet_key[0]];
  if ($discrete && _mica_is_type_supports_facet($index_type)) {
  	
  	if (empty($facet)) {
  		
			$facet = new SearchApiFacet(array(
	      'index_id' => $index->machine_name,
	      'field' => $field_name,
	      'name' => $facet_name,
	      'enabled' => TRUE,
	      'options' => array(),
	      'status' => 0,
	    ));     		
  		$facet->save();
  		
  		_mica_configure_search_block($facet, 'search_api_facets', 'facet');

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
  $range_array = search_api_range_load_multiple(FALSE, $facets_conditions, TRUE);
  $range_key = array_keys($range_array);
  $range = empty($range_key) ? NULL : $range_array[$range_key[0]];
  if (!$discrete && _mica_is_type_supports_ranges($index_type)) {
  	
  	if (empty($range)) {
  		
			$range = new SearchApiRange(array(
	      'index_id' => $index->machine_name,
	      'field' => $field_name,
	      'name' => $facet_name,
	      'enabled' => TRUE,
	      'options' => array(),
	      'status' => 0,
	    ));     		
  		$range->save(); 
  		
  		_mica_configure_search_block($range, 'search_api_ranges', 'range');
  		
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
	return $index_type === 'string' || $index_type === 'boolean' 
		|| $index_type === 'list<string>' || $index_type === 'list<boolean>' || $index_type === 'list<integer>' 
		|| $index_type === 'list<decimal>' || $index_type === 'list<date>'; 
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

/**
 * Add Facet/Range block to sidebar_first in mica_samara theme as last facet/range item. 
 * Hide this block by default but let individual users show it.
 *
 * @param SearchApiFacet or SearchApiRange $facet Facet or Range item
 * @param string $module 'search_api_ranges' or 'search_api_facets'
 * @param string $module_item 'range' or 'facet'
 */
function _mica_configure_search_block($facet, $module, $module_item) {
	
	db_update('block')
  	->fields(array(
				'custom' => BLOCK_CUSTOM_DISABLED, // Hide this block by default but let individual users show it.
	    ))
		->condition('module', $module)
	  ->condition('delta', $facet->delta)
	  ->execute();	   		
  		
	$theme_default = variable_get('theme_default', 'mica_samara');
  		
	$max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE module = :module AND theme = :theme and region = :region", 
  								array(
  									':module' => $module, 
  									':theme' => $theme_default, 
  									':region' => 'sidebar_first',
  								))->fetchField();
	  								  	
	db_update('block')
  	->fields(array(
				'status' => TRUE,
		    'region' => 'sidebar_first',
		    'weight' => empty($max_weight) ? 0 : ($max_weight + 1),
			))
		->condition('module', $module)
	  ->condition('delta', $facet->delta)
	  ->condition('theme', $theme_default)
	  ->execute();

	$block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme',
							array(
								':module' => $module, 
								':delta' => $facet->delta, 
								':theme' => $theme_default)
							)->fetchObject();
	
	$block = get_object_vars($block);							 
	$block[$module_item] = $facet;
	module_invoke($module, 'block_save', $facet->delta, $block);

	cache_clear_all();  			  
}

/**
 * 
 * Remove index field if exists for this bundle and field name
 * @param string $bundle
 * @param string $field_name
 */
function _mica_drop_search_index_field($bundle, $field_name) {
  $indexes = _mica_find_indexes_by_bundle();
  $bundles_indexes = $indexes[$bundle];
  if (!empty($bundles_indexes)) {
    foreach ($bundles_indexes as $index_machine_name => $index_name) {
      _mica_remove_field_index($index_machine_name, $original_field_name);
    }
  }     
}
