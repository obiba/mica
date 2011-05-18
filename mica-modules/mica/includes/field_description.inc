<?php
// $Id$

/**
 * @file
 * Field Description content relation with fields. 
 */

/**
 * Enhance the field settings form with field_description extensions.
 */
function _mica_field_settings_form_alter(&$form, $form_state, $form_id) {
  
  $bundle = $form_state['build_info']['args'][0]['bundle'];
  if ($bundle === 'field_description') {
    return; // cannot create field_description form field_description content type field
  }
  
  $field_name = $form_state['build_info']['args'][0]['field_name'];
  $field_description = _mica_find_field_description($bundle, $field_name);

  $form['field']['settings']['field_description_infos'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Field Description'), 
    '#collapsible' => FALSE, 
    '#collapsed' => FALSE,  
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'mica') . '/includes/field_description-field-form.js'),
    ),
  );
  
  $form['field']['settings']['field_description_infos']['field_description'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Field Descriptor for this field'),
    '#default_value' => !empty($field_description), 
  );
  
  if (empty($field_description)) {
  	
  	// auto-detect value type based on field value type
  	$field_value_type = $form_state['build_info']['args'][0]['display']['default']['type'];
  	switch ($field_value_type) {
  		
  		case 'list_boolean':
  			$default_value_type = 'BOOLEAN';
  			break;
  			
  		case 'date':
  		case 'datestamp':
  		case 'datetime':
  			$default_value_type = 'DATE';
  			break;
  			
  		case 'number_float':
  		case 'list_float':
  		case 'number_decimal':
  			$default_value_type = 'DECIMAL';
  			break;
  			
  		case 'email':
  		case 'link_field':
  		case 'list_text':
  		case 'text_long':
  		case 'text_with_summary':
  		case 'text':
  		case 'text_default':
  			$default_value_type = 'TEXT';
  			break;
  			
  		case 'number_integer':
  		case 'list_integer':
  			$default_value_type = 'INTEGER';
  			break;
  			
  		default:
  			$default_value_type = NULL;
  			break;
  	}

  } 
  else {
    $field_description_field_value_type = $field_description->field_value_type;
    $default_value_type = $field_description_field_value_type[LANGUAGE_NONE][0]['value'];
  }
  
  // retrieve available select options from field_description field 'field_value_type'
  $field_value_type_options = field_info_field('field_value_type');
  
  $form['field']['settings']['field_description_infos']['field_description_value_type'] = array(
    '#type' => 'select',
	  // enables value type input only if we were not able to detect it
  	// '#disabled' => !empty($default_value_type),
    '#title' => t('Field value type'),
    '#required' => FALSE, 
    '#options' => $field_value_type_options['settings']['allowed_values'],  
    '#default_value' => $default_value_type,
    // Enabled only when the 'field_description' checkbox is checked
    '#states' => array(
    	'enabled' => array(
      	'input[name="field[settings][field_description_infos][field_description]"]' => array('checked' => TRUE)
      ),
    ),      
  );
  
  if (empty($field_description)) {
    $default_body = NULL;
  } 
  else {
    $field_description_body = $field_description->body;
    $default_body = $field_description_body[LANGUAGE_NONE][0]['value'];
  }  
  
  $form['field']['settings']['field_description_infos']['field_description_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $default_body,
    '#required' => FALSE,  
    // Enabled only when the 'field_description' checkbox is checked
    '#states' => array(
      'enabled' => array(
      	'input[name="field[settings][field_description_infos][field_description]"]' => array('checked' => TRUE)
      ),
    ),    
  );  
  
  $form['#submit'][] = '_mica_edit_field_field_description';      
}

/**
 * Additional submit handler for the 'Edit field instance' form.
 */
function _mica_edit_field_field_description($form, &$form_state) {
	
  $is_field_description = $form_state['values']['field']['settings']['field_description_infos']['field_description'];
  $field_name = $form_state['values']['instance']['field_name'];
  $bundle = $form_state['values']['instance']['bundle'];
  $field_info = field_info_field($field_name);
  $node_type = node_type_load($bundle);
  
  $field_description_infos = array(
    'title' => $node_type->name . ' » ' . $form_state['values']['instance']['label'],
    'desc' => $is_field_description ? $form_state['values']['field']['settings']['field_description_infos']['field_description_body'] : NULL,
    'bundle' => $bundle,
    'bundle_label' => $node_type->name,
    'original_field_name' => $field_name,
    'original_field_label' => $form_state['values']['instance']['label'],
    'value_type' => $is_field_description ? $form_state['values']['field']['settings']['field_description_infos']['field_description_value_type'] : NULL,
  	'repeatable' => $form_state['values']['field']['cardinality'] != 1,
		'discrete' => !empty($form_state['values']['field']['settings']['allowed_values']),  										
  	'categories' => empty($field_info['settings']) || empty($field_info['settings']['allowed_values']) 
  										? array() 
  										: array_keys($field_info['settings']['allowed_values']),
  );
  
  $field_description = _mica_find_field_description($bundle, $field_name);
  if (empty($field_description)) {  
    if ($is_field_description) {
      _mica_create_field_description($field_description_infos);
    }   
  } 
  else {
    if ($is_field_description) {
      _mica_update_field_description($field_description, $field_description_infos);
    } 
    else {
      node_delete($field_description);
    }   
  }
}

/**
 * Returns a unique field_description for a bundle and field name or NULL
 */
function _mica_find_field_description($bundle, $field_name) {
  $query = new EntityFieldQuery;
  $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'field_description')
                  ->fieldCondition('field_bundle', 'value', $bundle, '=')
                  ->fieldCondition('field_original_field_name', 'value', $field_name, '=')
                  ->execute();      
  if (!empty($result['node'])) {
    $entities = entity_load('node', array_keys($result['node']));
    $entity_id = array_keys($entities);
    return $entities[$entity_id[0]];
  }
  return array();             
}

/**
 * Create Field Description and corresponding search index
 * 
 * @param array $field_description_infos with 'title', 'desc', 'bundle', 'original_field_name', 'value_type', 'repeatable', 'categories' 
 */
function _mica_create_field_description(array $field_description_infos) {
  
  $field_description = new stdClass();
  $field_description->type = 'field_description';
  node_object_prepare($field_description);
  $field_description->language = LANGUAGE_NONE;
  
  _mica_update_field_description($field_description, $field_description_infos);

  watchdog('mica', 'Create Field Description for %field of %bundle', 
    array(
      '%field' => $field_description_infos['original_field_label'], 
      '%bundle' => $field_description_infos['bundle_label'],
    ), WATCHDOG_INFO);
}

/**
 * Update Field Description and corresponding search index
 * 
 * @param stdClass $field_description 
 * @param array $field_description_infos with 'title', 'desc', 'bundle', 'bundle_label', 'original_field_name', 
 * 'original_field_label', 'value_type', 'repeatable', 'categories' 
 */
function _mica_update_field_description(stdClass $field_description, array $field_description_infos) {
	$field_description->title = $field_description_infos['title'];
	$field_description->body = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['desc'],
      ),
    ),
  );
  $field_description->field_bundle = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['bundle'],
      ),
    ),
  );
  $field_description->field_bundle_label = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['bundle_label'],
      ),
    ),
  );
  $field_description->field_original_field_name = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['original_field_name'],
      ),
    ),
  );
  $field_description->field_original_field_label = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['original_field_label'],
      ),
    ),
  );
  $field_description->field_value_type = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['value_type'],
      ),
    ),
  );  
  $field_description->field_repeatable = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['repeatable'] ? 1 : 0,
      ),
    ),
  );
  $field_description->field_discrete = array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $field_description_infos['discrete'] ? 1 : 0,
      ),
    ),
  );
  
  $field_description->field_categories = array();
  $field_description->field_categories[LANGUAGE_NONE] = array();
  foreach ($field_description_infos['categories'] as $delta => $category) {
		$field_description->field_categories[LANGUAGE_NONE][$delta] = array(
    	'value' => $category,
	  );
  }
  
  node_save($field_description);
}

/**
 * On field instance deletion, delete field_description if it exists for this field.
 */
function _mica_delete_field_description_for_field_instance($instance) {
  $field_description = _mica_find_field_description($instance['bundle'], $instance['field_name']);
  if (!empty($field_description)) {
    node_delete($field_description);
  }
}

