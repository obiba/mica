<?php
// $Id$

include_once(drupal_get_path('module', 'facetapi') . '/facetapi.block.inc');

/**
 * @file
 * Mica search API utilities
 */
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
