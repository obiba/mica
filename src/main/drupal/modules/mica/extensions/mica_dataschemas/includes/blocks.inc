<?php

function _mica_dataschemas_configure_facet_blocks() {
  
  $facet_order = array(
  	'Dataschema facet',
  	'Health information facet',
  	'Life habits / Behaviours facet',
  	'Disease history (ICD10) facet',
  	'Physical environment facet',
  	'Body functions facet',
  	'Body structure facet', 
  	'Social environment facet',
  	'Sociodemographic characteristics facet',
  	'Socioeconomic characteristics facet',
    'Class facet',  
    'Type facet',  
    'Format facet',
    'Collection mode facet',
    'Source of information facet',
    'Target facet',
    'Target gender facet',
    'Disease facet',
    'Period facet',
    'Medical health intervention facet',
    'Sample facet');
  
  $theme_default = variable_get('theme_default', 'mica_samara');
  $max_weight = db_query("SELECT MAX(weight) as max_weight FROM {block} WHERE theme = :theme and region = :region",
    array(
      ':theme' => $theme_default, 
      ':region' => 'sidebar_first')
     )->fetchField();
  $max_weight = empty($max_weight) ? 0 : ($max_weight + 1);
    
  $query = new EntityFieldQuery;
  $result = $query->entityCondition('entity_type', 'search_api_facet')
                  ->propertyCondition('index_id', 'dataschema_variables_index')
                  ->propertyCondition('enabled', '1')
                  ->execute();
  if (!empty($result['search_api_facet'])) {
  	$keys = array_keys($result['search_api_facet']);
  	$facets = entity_load('search_api_facet', $keys);
  	foreach ($facets as $facet) {
  	  $facet_index = array_keys($facet_order, $facet->name);
      $facet_weight = $max_weight + $facet_index[0];
  		db_update('block')->fields(array(
          'status' => TRUE,
          'region' => 'sidebar_first',
          'weight' => $facet_weight
    		))
    		->condition('module', 'search_api_facets')
    		->condition('delta', $facet->delta)
    		->condition('theme', $theme_default)
    		->execute();
  	}
  }
}

