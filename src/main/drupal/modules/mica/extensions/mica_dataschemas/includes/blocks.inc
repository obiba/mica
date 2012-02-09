<?php

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');

function mica_dataschemas_configure_facet_blocks() {
  
  $facet_order_by_region = array(
    'sidebar_second' => array(
  		'search_api@dataschema_variables_index:current_search', 
    	'search_api@dataschema_variables_index:block:field_dataschema_ref',
  		'search_api@dataschema_variables_index:block:field_dim_collection_mode',
    	'search_api@dataschema_variables_index:block:field_dim_life_habits_behaviours',
    	'search_api@dataschema_variables_index:block:field_dim_disease_history',
    	'search_api@dataschema_variables_index:block:field_dim_therapeutic_inter',
    	'search_api@dataschema_variables_index:block:field_dim_medication',
    	'search_api@dataschema_variables_index:block:field_dim_reproductive_history',
    	'search_api@dataschema_variables_index:block:field_dim_body_functions_meas', 
    	'search_api@dataschema_variables_index:block:field_dim_environmental_exp',
    	'search_api@dataschema_variables_index:block:field_dim_biochemical_measures',
    	'search_api@dataschema_variables_index:block:field_dim_sociodemo_charact',
    	),
    'sidebar_first' => array(
      'search_api@dataschema_variables_index:block:field_dim_class',  
      'search_api@dataschema_variables_index:block:field_dim_type',  
      'search_api@dataschema_variables_index:block:field_dim_format',
      'search_api@dataschema_variables_index:block:field_dim_source_of_info',
      'search_api@dataschema_variables_index:block:field_dim_target',
      'search_api@dataschema_variables_index:block:field_dim_target_gender',
      'search_api@dataschema_variables_index:block:field_dim_period',
      'search_api@dataschema_variables_index:block:field_dim_sample',
    )
  );
  
  $theme_default = variable_get('theme_default', 'mica_samara');
  
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
      $facet_delta = facetapi_hash_delta($facet);
      
      if (empty($facet_delta)) {
        drupal_set_message('No facet defined for ' . $facet, 'warning');
        continue;
      }
      
    	$facet_weight = $max_weight + $index;
    	
    	db_insert('block')->fields(array(
        'status' => TRUE,
        'region' => $region,
        'weight' => $facet_weight,
    		'module' => 'facetapi',
    		'delta' => $facet_delta,
    		'theme' => $theme_default,
        'visibility' => 1,
        'pages' => 'dataschema-variables',
        'cache' => -1,
    	))
    	->execute();
    	
      watchdog('mica', 'Configured facet block %facet', array('%facet' => $facet), WATCHDOG_INFO);
    }    
    
  }

}

