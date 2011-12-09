<?php
// $Id$

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');

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

  $field_categories = $field_description->field_categories;
  $discrete = count($field_categories[LANGUAGE_NONE]) > 1;

  if ($type === 'TEXT') {
    $field = field_info_field($field_name);
    $index_type = empty($field['settings']['allowed_values']) ? 'text' : 'string';
  } else {
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
  if (!isset($fields[$field_name]) || empty($fields[$field_name])) {
    $reindex = TRUE;
  } else {
    $reindex = !isset($fields[$field_name]['name'])
      || !isset($fields[$field_name]['indexed'])
      || !isset($fields[$field_name]['type'])
      || $fields[$field_name]['name'] != $field_label
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
  
  // Facets & ranges
  $facet_supported = !_mica_is_field_excluded_form_facets($field_name) && $discrete && _mica_is_type_supports_facet($index_type);
  $range_supported = !_mica_is_field_excluded_form_facets($field_name) && !$discrete && _mica_is_type_supports_ranges($index_type);
  $searcher = 'search_api@' . $index->machine_name;
  $facet = facetapi_facet_load($field_name, $searcher);
  if ($facet) {  
    $adapter = facetapi_adapter_load($searcher);
    $realms = facetapi_get_realm_info();
    foreach ($realms as $realm_name => $realm) {
    	$delta = facetapi_hash_delta(facetapi_build_delta($searcher, $realm_name, $facet['name']));
      if ($facet_supported) {
        if (facetapi_save_facet_enabled($adapter, $realm, $facet)) {
        	_mica_enable_search_block($delta);
        }
      } else if ($range_supported) {
        $settings = $adapter->getFacet($facet)->getSettings($realm);
        $settings->settings['widget'] = 'search_api_ranges_ui_slider';
        ctools_export_crud_save('facetapi', $settings);
        if (facetapi_save_facet_enabled($adapter, $realm, $facet)) {
        	_mica_enable_search_block($delta);
        }        
      } else {
        if (facetapi_save_facet_disabled($adapter, $realm, $facet)) {
          _mica_disable_search_block($delta);
        }
      }
    }
    cache_clear_all();
  }  
}

function _mica_is_field_excluded_form_facets($field_name) {
  // By default some fields don't have any facets...
  $disabled_field_facets = array(
    'mica_study_information:field_selection_criteria',
    'mica_study_information:field_gender',
  );  
  return in_array($field_name, $disabled_field_facets);
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

  $searcher = 'search_api@' . $index->machine_name;
  $facet = facetapi_facet_load($field_name, $searcher);
  if ($facet) {
    $adapter = facetapi_adapter_load($searcher);
    $realms = facetapi_get_realm_info();
    foreach ($realms as $realm_name => $realm) {
      if (facetapi_save_facet_disabled($adapter, $realm, $facet)) {
        _mica_disable_search_block($delta);
      }
    }
  }
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
 * Show this block by default but let individual users hide it.
 * In this case, block will be visible for anonymous users.
 *
 */
function _mica_enable_search_block($facet_delta) {

  $theme_default = variable_get('theme_default', 'mica_samara');
  
  $max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE module = :module AND theme = :theme and region = :region",
    array(
      ':module' => 'facetapi', 
      ':theme' => $theme_default, 
      ':region' => 'sidebar_first'
    )
  )->fetchField();

  $block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme',
    array(
      ':module' => 'facetapi', 
      ':delta' => $facet_delta, 
      ':theme' => $theme_default
    )
  )->fetchObject();
  
  if($block) {
    db_update('block')->fields(
      array(
      	'status' => TRUE,
      	'region' => 'sidebar_first',
      	'weight' => empty($max_weight) ? 0 : ($max_weight + 1),
      )
    )
    ->condition('module', 'facetapi')
    ->condition('delta', $facet_delta)
    ->condition('theme', $theme_default)
    ->execute();    
  } else {
    db_insert('block')->fields(
      array(
      	'status' => TRUE,
      	'region' => 'sidebar_first',
      	'weight' => empty($max_weight) ? 0 : ($max_weight + 1),
    		'custom' => BLOCK_CUSTOM_ENABLED, // Show this block by default but let individual users hide it.
    		'delta' => $facet_delta,
    		'module' => 'facetapi',
    		'theme' => $theme_default,
    		'pages' => '',
      )
    )
    ->execute();
  }

}

function _mica_disable_search_block($facet_delta) {
	$theme_default = variable_get('theme_default', 'mica_samara');
	db_update('block')->fields(
  	array(
    	'status' => 0,
     	'region' => '-1',
	  )
  )
	->condition('module', 'facetapi')
	->condition('delta', $facet_delta)
	->condition('theme', $theme_default)
	->execute();
}

/**
 *
 * Remove index field if exists for this bundle and field name
 * @param string $bundle
 * @param string $field_name
 */
function _mica_drop_search_index_field($bundle, $field_name) {
  $indexes = _mica_find_indexes_by_bundle();
  if (isset($indexes[$bundle])) {
    $bundles_indexes = $indexes[$bundle];
    if (!empty($bundles_indexes)) {
      foreach ($bundles_indexes as $index_machine_name => $index_name) {
        _mica_remove_field_index($index_machine_name, $original_field_name);
      }
    }
  }
}

function mica_configure_current_search_facet_blocks() {
  
  $theme_default = variable_get('theme_default', 'mica_samara');
  
  $min_weight = db_query("SELECT MIN(weight) as max_weight FROM {block} WHERE theme = :theme and region = :region",
    array(
    	':theme' => $theme_default, 
  		':region' => 'sidebar_first'
    )
  )
  ->fetchField();
  $min_weight = empty($min_weight) ? 0 : ($min_weight - 1);
  
  $facet_name = 'search_api@studies_index:current_search';
	$facet_delta = facetapi_hash_delta($facet_name);
  
	if (empty($facet_delta)) {
		drupal_set_message('No facet defined for ' . $facet_name, 'warning');
		continue;
	}
  
	db_insert('block')->fields(
	  array(
      'status' => TRUE,
      'region' => 'sidebar_first',
      'weight' => $min_weight,
  		'module' => 'facetapi',
  		'delta' => $facet_delta,
  		'theme' => $theme_default,
      'status' => 1,
      'visibility' => 1,
      'pages' => '',
      'cache' => -1,
	  )
  )
	->execute();
  		 
  watchdog('mica', 'Configured facet block %facet', array('%facet' => $facet_name), WATCHDOG_INFO);
}
