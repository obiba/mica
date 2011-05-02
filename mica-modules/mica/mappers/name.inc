<?php

/**
 * Implementation of hook_feeds_node_processor_targets_alter().
 */
function name_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
	foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
		$info = field_info_field($name);
		if ($info['type'] == 'name') {
			$targets[$name.':title'] = array(
	      		'name' => $instance['label'] . ' - Title',
	      		'callback' => 'name_feeds_set_target_name',
	      		'description' => t('The Title of the @name field of the node.', array('@name' => $instance['label'])),
	    	);
	    	$targets[$name.':given'] = array(
	      		'name' => $instance['label'] . ' - Given Name',
	      		'callback' => 'name_feeds_set_target_name',
	      		'description' => t('The Given Name of the @name field of the node.', array('@name' => $instance['label'])),
	    	);
	    	$targets[$name.':family'] = array(
	      		'name' => $instance['label'] . ' - Family Name',
	      		'callback' => 'name_feeds_set_target_name',
	      		'description' => t('The Family Name of the @name field of the node.', array('@name' => $instance['label'])),
	    	);
		}
  	}
}

/*
 * Callback for stuy importer
 */
function name_feeds_set_target_name($source, $entity, $target, $value){
	_name_set_target($source, $entity, $target, $value);
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function _name_set_target($source, $entity, $target, $value, $value_field = 'value') {  
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Iterate over all values.
  $i = 0;
  $info = field_info_field($target);
  list($field_name, $sub_field) = explode(':', $target);
  foreach ($value as $v) {
  	$new_value = clean($v);
    if (!is_array($new_value) && !is_object($new_value)) {
    	if (isset($sub_field)){
    		$field['und'][$i][$sub_field] = $new_value;
    	}
    	else{
      		$field['und'][$i][$value_field] = $new_value;
    	}
    }
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }
 
  if (isset($sub_field)){
  	foreach ($field['und'] as $i => $sub){
 		$entity->{$field_name}['und'][$i][$sub_field] = $field['und'][$i][$sub_field]; 
  	}
  }
  else{
  	$entity->{$field_name} = $field;
  }
}

