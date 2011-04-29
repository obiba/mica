<?php

/**
 * Enhance the field settings form with variable extensions.
 */
function _mica_field_settings_form_alter(&$form, $form_state, $form_id) {
	
	$field_name = $form_state['build_info']['args'][0]['field_name'];
	$bundle = $form_state['build_info']['args'][0]['bundle'];
	
	$variable = _mica_find_variable($bundle, $field_name);

  $form['field']['settings']['variable_infos'] = array(
		'#type' => 'fieldset', 
	  '#title' => t('Variable settings'), 
		'#collapsible' => FALSE, 
  	'#collapsed' => FALSE,  
    '#attached' => array(
    	'js' => array(drupal_get_path('module', 'mica') . '/includes/variables-field-form.js'),
		),
	);
	
  $form['field']['settings']['variable_infos']['variable'] = array(
		'#type' => 'checkbox',
    '#title' => t('Variable'),
    '#description' => t("This field will be considered as a variable"),
  	'#default_value' => !empty($variable), 
  );
  
  // retrieve available select options from variable field 'field_value_type'
  $field_value_type = field_info_field('field_value_type');
  if(empty($variable)) {
  	$default_value_type = NULL;
  } else {
  	$variable_field_value_type = $variable->field_value_type;
  	$default_value_type = $variable_field_value_type[LANGUAGE_NONE][0]['value'];
  }
  
  $form['field']['settings']['variable_infos']['variable_value_type'] = array(
		'#type' => 'select',
    '#title' => t('Variable value type'),
  	// TODO variable_value_type should be required if 'variable' checkbox is checked
    '#required' => FALSE, 
 		'#options' => $field_value_type['settings']['allowed_values'],  
  	'#default_value' => $default_value_type,
    // Enabled only when the 'variable' checkbox is checked
    '#states' => array(
    	'enabled' => array('input[name="field[settings][variable_infos][variable]"]' => array('checked' => TRUE)),
    ),      
  );
  
  if(empty($variable)) {
  	$default_body = NULL;
  } else {
  	$variable_body = $variable->body;
  	$default_body = $variable_body[LANGUAGE_NONE][0]['value'];
  }  
  
  $form['field']['settings']['variable_infos']['variable_body'] = array(
		'#type' => 'textarea',
    '#title' => t('Description'),
  	'#default_value' => $default_body,
  	'#required' => FALSE,  
    // Enabled only when the 'variable' checkbox is checked
    '#states' => array(
    	'enabled' => array('input[name="field[settings][variable_infos][variable]"]' => array('checked' => TRUE)),
    ),    
  );  
  
  $form['#submit'][] = '_mica_edit_field_variable';      
}

/**
 * Additional submit handler for the 'Edit field instance' form.
 */
function _mica_edit_field_variable($form, &$form_state) {
	$is_variable = $form_state['values']['field']['settings']['variable_infos']['variable'];
	$field_name = $form_state['values']['instance']['field_name'];
	$bundle = $form_state['values']['instance']['bundle'];
	
	$variable_infos = array(
		'title' => preg_replace('/^field_/', '', $field_name),
		'body' => $is_variable ? $form_state['values']['field']['settings']['variable_infos']['variable_body'] : NULL,
		'bundle' => $bundle,
		'original_field_name' => $field_name,
		'value_type' => $is_variable ? $form_state['values']['field']['settings']['variable_infos']['variable_value_type'] : NULL,
	);
	
	$variable = _mica_find_variable($bundle, $field_name);
	if(empty($variable)) {	
		if($is_variable) {
			_mica_create_variable($variable_infos);
		}		
	} else {
		if($is_variable) {
			_mica_update_variable($variable, $variable_infos);
		} else {
			_mica_delete_variable($variable);
		}		
	}
}

/**
 * Returns a unique variable for a bundle and field name or NULL
 */
function _mica_find_variable($bundle, $field_name) {
	$query = new EntityFieldQuery;
	$result = $query->entityCondition('entity_type', 'node')
									->entityCondition('bundle', 'variable')
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

function _mica_create_variable(array $variable_infos) {
	$variable = new stdClass();
	$variable->type = 'variable';
	node_object_prepare($variable);
	$variable->language = LANGUAGE_NONE;
	$variable->title = $variable_infos['title'];
	//TODO set variable author 
	
	$variable->body = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['body'],
			),
		),
	);
	$variable->field_bundle = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['bundle'],
			),
		),
	);
	$variable->field_value_type = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['value_type'],
			),
		),
	);	
	$variable->field_original_field_name = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['original_field_name'],
			),
		),
	);
	node_save($variable);		
	
	watchdog('mica', 'Create Variable for %field of %bundle', 
		array(
			'%field' => $variable_infos['original_field_name'], 
			'%bundle' => $variable_infos['bundle'],
		), WATCHDOG_INFO);
	
	//TODO add this field to Studies Index
	//$studies_index = search_api_index_load('studies_index');
	//debug($search_server, '$search_server');
}

function _mica_update_variable($variable, array $variable_infos) {
	$variable->field_value_type = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['value_type'],
			),
		),
	);		
	$variable->body = array(
		LANGUAGE_NONE => array(
			0 => array(
				'value' => $variable_infos['body'],
			),
		),
	);	
	node_save($variable);
}

/**
 * Delete variable
 */
function _mica_delete_variable($variable) {
	node_delete($variable->nid);
	//TODO delete this field from Studies Index
	
	$field_bundle = $variable->field_bundle;
	$field_original_field_name = $variable->field_original_field_name;
	
	watchdog('mica', 'Delete Variable for %field of %bundle', 
		array(
			'%field' => $field_original_field_name[LANGUAGE_NONE][0]['value'], 
			'%bundle' => $field_bundle[LANGUAGE_NONE][0]['value'],
		), WATCHDOG_INFO);	
}

/**
 * On field instance deletion, delete variable if it extists for this field.
 */
function _mica_delete_variable_for_field_instance($instance) {
	$variable = _mica_find_variable($instance['bundle'], $instance['field_name']);
	if(!empty($variable)) {
		_mica_delete_variable($variable);
	}
}