<?php
/**
 * @file
 * Mica relations.
 */

/**
 * Enhance the content type form with mica_relation extensions.
 */
function _mica_node_type_form_alter(&$form, $form_state) {
	module_load_include('inc', 'mica', 'includes/search');
	
	if (isset($form['type'])) {
  	
  	$current_type = $form['#node_type']->type;
		$relation = _mica_find_relation_by_child($current_type);
  	  	
		$existing_types = array();
		foreach (node_type_get_types() as $type) {
			if($type->type != 'mica_relation' && $type->type != $current_type)
			$existing_types[$type->type] = $type->name;
		}  	
		
		$selected_parent_bundle = isset($form_state['values']['parent_bundle']) 
			? $form_state['values']['parent_bundle'] 
			: (empty($relation) ? '' : $relation['parent_bundle']);
			
		
		$indexes = _mica_find_indexes_by_bundle();
		
    $form['mica_relation'] = array(
      '#type' => 'fieldset',
      '#title' => t('Relations'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#group' => 'additional_settings',
      '#attributes' => array(
        'class' => array('relation-node-type-settings-form'),
      ),
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'mica') . '/includes/relations-node-form.js'),
      ),
    );
    
    $form['mica_relation']['parent_bundle'] = array(
      '#type' => 'select',
      '#title' => t('Parent'),
    	'#description' => t('Select parent content type'),
      '#default_value' => $selected_parent_bundle,
      '#options' => array_merge(array('' => t('None')), $existing_types),    
    );  
    
    $form['mica_relation']['cascaded'] = array(
      '#type' => 'checkbox',
      '#title' => t('Cascad events'),
    	'#description' => t('Cascade parent\'s events: create, update, publish, unpublish.'),
      '#default_value' => empty($relation) ? TRUE : $relation['cascaded'],
    );
    
    $form['mica_relation']['indexed'] = array(
      '#type' => 'checkbox',
      '#title' => t('Index content'),
    	'#description' => t('Index as part of its parent'),
      '#default_value' => empty($relation) ? TRUE : $relation['indexed'],
    	'#attributes' => array('class' => array('enabled-for-ajax')),
      '#ajax' => array(
	      'callback' => '_mica_ajax_populate_indexes_callback',
  	    'wrapper' => 'child-indexes-container',
    	),
    );  
    
    $parent_indexes = empty($selected_parent_bundle) ? array() : $indexes[$selected_parent_bundle];
    if(empty($relation)) {
    	if(empty($parent_indexes)) {
    		$child_indexes_default_value = array();
    	} 
    	else {
    		$child_indexes_default_value = array_keys($parent_indexes);
    	}
    } 
    else {
    	$child_indexes_default_value = $relation['child_indexes'];
    };
    
    
    $form['mica_relation']['child_indexes'] = array(
      '#type' => 'checkboxes',
	    '#prefix' => '<div id="child-indexes-container">',
	    '#suffix' => '</div>',    
      '#title' => t('Search indexes'),
    	'#description' => t('Parent\'s search API indexes'),
      '#default_value' => $child_indexes_default_value,
    	'#options' => $parent_indexes,
      '#attributes' => array('class' => array('enabled-for-ajax')),
    );  
    
    $form['#validate'][] = 'mica_validate_node_type_relation';    
    $form['#submit'][] = 'mica_edit_node_type_relation';
  }	
}

/**
 * Returns just the list of search index checkboxes for re-rendering
 */
function _mica_ajax_populate_indexes_callback($form, $form_state) {
  return $form['mica_relation']['child_indexes'];
}

function _mica_validate_node_type_relation($form, &$form_state) {
	$parent_bundle = trim($form_state['values']['parent_bundle']);
	if(!empty($parent_bundle) && $form_state['values']['indexed'] == 1) {
		$valid = FALSE;
		foreach ($form_state['values']['child_indexes'] as $child_indexes) {
			if($child_indexes) {
				$valid = TRUE;
				break;
			}
		}
		if(!$valid) {
			form_set_error('child_indexes', t('You must select a Search Index if you choose to index content.'));
		}
	}
}

/**
 * Save relation info on content type edition 
 */
function _mica_edit_node_type_relation($form, &$form_state) {
	module_load_include('inc', 'mica', 'includes/search');	
	
	$previous_type = $form['#node_type']->type;
	$new_type = trim($form_state['values']['type']);
	$name = trim($form_state['values']['name']);
	$parent_bundle = trim($form_state['values']['parent_bundle']);
	$relation = _mica_find_relation_by_child($previous_type);
		
	if(empty($parent_bundle)) {
		
		if(!empty($relation)) {
			_mica_delete_relation($relation);
			watchdog('mica', 'Delete relation between parent %parent and child %child', 
				array(
					'%parent' => $relation['parent_bundle'],
					'%child' => $relation['child_bundle'], 
				), WATCHDOG_INFO);					
		}
					
	} 
	else {
		
		$relation['parent_bundle'] = $parent_bundle;
		$relation['child_bundle'] = $new_type;		
		$relation['cascaded'] = $form_state['values']['cascaded'];
		$relation['indexed'] = $form_state['values']['indexed'];
		if($relation['indexed']) {
			$relation['child_indexes'] = $form_state['values']['child_indexes'];
		} 
		else {
			$relation['child_indexes'] = array();
		}
				
		$previous_relation = _mica_find_relation_by_child($previous_type);
		if(empty($previous_relation)) { 
			
			// create new relation
			
			watchdog('mica', 'Create relation between parent %parent and child %child', 
				array(
					'%parent' => $relation['parent_bundle'],
					'%child' => $relation['child_bundle'], 
				), WATCHDOG_INFO);						
				
				
			$indexes = _mica_find_indexes_by_bundle();
			$relation['parent_indexes'] = empty($indexes[$relation['parent_bundle']]) ? array() : array_keys($indexes[$relation['parent_bundle']]);
			
			// set reference node and relation only at creation
			$relation['node_reference'] = 'mica_' . $new_type;	
			$relation['relation'] = $relation['parent_bundle'] . '_' . $relation['child_bundle'];	
			$relation['relation_parent_field'] = $relation['child_bundle'] . '_relation';	
			$relation['relation_child_field'] = $relation['parent_bundle'] . '_relation';
			
			//TODO create relation	
			
			// create node reference field
			_mica_add_node_reference_to_parent($relation, $name);
			
			// check if parent type already has content
			$query = new EntityFieldQuery;
			$result = $query->entityCondition('entity_type', 'node')
											->entityCondition('bundle', $relation['parent_bundle'])
											->execute();			
			if (!empty($result['node'])) {
	 			$entities = entity_load('node', array_keys($result['node']));
	 			foreach ($entities as $entity) {
	 				mica_node_insert($entity);	// create missing child content
	 			}
			}												
			
		} 
		else {
			
			// check if parent type has content
			$query = new EntityFieldQuery;
			$result = $query->entityCondition('entity_type', 'node')
											->entityCondition('bundle', $previous_relation['parent_bundle'])
											->execute();			
			if(empty($result)) {
				
				// no content for parent type, we can replace node reference field and relation
				field_delete_field($previous_relation['node_reference']);
				$relation['node_reference'] = 'mica_' . $new_type;					
				_mica_add_node_reference_to_parent($relation, $name);

				//TODO recreate relation	
				
			} 
			else {
				
				// update node reference field label
				$field_instance = field_info_instance('node', $previous_relation['node_reference'], $previous_relation['parent_bundle']);
				$field_instance['label'] = $name;
				field_update_instance($field_instance);
				
			}
			
									
		}
		_mica_save_relation($relation);
	}
	
}

/**
 * create and add node reference field for parent type
 */
function _mica_add_node_reference_to_parent(array $relation, $child_name) {
	
	field_create_field(array(
		'field_name' => $relation['node_reference'],
    'type' => 'node_reference',
    'cardinality' => 1,
    'settings' => array(
    	'referenceable_types' => array(
				$relation['child_bundle'] => $relation['child_bundle']
			),
    	'field_permissions' => array(
    		'create' => 'create',
    		'view' => 'view',
			),
		),			
	));

	field_create_instance(array(
		'field_name' => $relation['node_reference'],
	  'label' => $child_name,
    'entity_type' => 'node',
    'bundle' => $relation['parent_bundle'],
    'widget' => array('type' => 'options_select'),
	));
	
	// give 'view' field permission to everyone
	user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('view ' . $relation['node_reference']));
	user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('view ' . $relation['node_reference']));	

	// give 'create' field permission to studies administrator and study administrator
	$admin_role = user_role_load_by_name('administrator');
	$studies_admin_role = user_role_load_by_name('studies administrator');
	$study_admin_role = user_role_load_by_name('study administrator');
	user_role_grant_permissions($admin_role->rid, array('create ' . $relation['node_reference']));
	user_role_grant_permissions($studies_admin_role->rid, array('create ' . $relation['node_reference']));
	user_role_grant_permissions($study_admin_role->rid, array('create ' . $relation['node_reference']));
}

/**
 * Returns an array of relations with relation ID as key
 */
function _mica_find_relation_by_parent_or_child($parent_or_child_bundle) {
	$relations = array();
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.parent_bundle = :bundle or r.child_bundle = :bundle', 
							array(':bundle' => $parent_or_child_bundle));	
	foreach ($result as $record) {
		$relations[$record->id] = _mica_load_relation($record);
	}
	return $relations;	
}

function _mica_save_relation(array $relation) {
	if(isset($relation['id'])) {
		// update
		db_update('mica_relation')
		  ->fields(array(
			    'parent_bundle' => $relation['parent_bundle'],
			    'child_bundle' => $relation['child_bundle'],
			    'node_reference' => $relation['node_reference'],
			    'indexed' => $relation['indexed'],
			    'cascaded' => $relation['cascaded'],
			    'relation' => $relation['relation'],
			    'relation_parent_field' => $relation['relation_parent_field'],
			    'relation_child_field' => $relation['relation_child_field'],
		 	 	))
		  ->condition('id', $relation['id'])
		  ->execute();
	} 
	else {
		// insert
		$relation['id'] = db_insert('mica_relation')
											  ->fields(array(
											    'parent_bundle' => $relation['parent_bundle'],
											    'child_bundle' => $relation['child_bundle'],
											    'node_reference' => $relation['node_reference'],
											    'indexed' => $relation['indexed'],
											    'cascaded' => $relation['cascaded'],
											    'relation' => $relation['relation'],
											    'relation_parent_field' => $relation['relation_parent_field'],
											    'relation_child_field' => $relation['relation_child_field'],
									 	 		))
									 	 		->execute();		
	}
	
	// add child to search index
	$indexes = entity_load('search_api_index', array_keys($relation['child_indexes']));
	foreach($indexes as $index) {
		$options = $index->options;
		$options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'][$relation['child_bundle']] = $relation['child_bundle'];
		entity_save('search_api_index', $index);
	}		
	return $relation;	
}

/**
 * Returns an array of relations for this parent type with relation ID as key
 */
function _mica_find_relations_by_parent($parent_bundle) {
	$relations = array();
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.parent_bundle = :parent', array(':parent' => $parent_bundle));	
	foreach ($result as $record) {
		$relations[$record->id] = _mica_load_relation($record);
	}
	return $relations;
}

/**
 * Returns a unique relation for this child type 
 */
function _mica_find_relation_by_child($child_bundle) {
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.child_bundle = :child', array(':child' => $child_bundle));	
	foreach ($result as $record) {
		return _mica_load_relation($record);
	}
	return NULL;
}

function _mica_load_relation($mica_relation_record) {
	module_load_include('inc', 'mica', 'includes/search');
	
	$relation = array(
		'id' => $mica_relation_record->id,
		'parent_bundle' => $mica_relation_record->parent_bundle,
		'child_bundle' => $mica_relation_record->child_bundle,
		'node_reference' => $mica_relation_record->node_reference,
		'indexed' => $mica_relation_record->indexed,
		'cascaded' => $mica_relation_record->cascaded,
		'relation' => $mica_relation_record->relation,
		'relation_parent_field' => $mica_relation_record->relation_parent_field,
		'relation_child_field' => $mica_relation_record->relation_child_field,
		'parent_indexes' => array(),
		'child_indexes' => array(),
	);
	$indexes = _mica_find_indexes_by_bundle();
	if(!empty($indexes[$mica_relation_record->parent_bundle])) {
		$relation['parent_indexes'] = array_keys($indexes[$mica_relation_record->parent_bundle]);
	}
	if(!empty($indexes[$mica_relation_record->child_bundle])) {
		$relation['child_indexes'] = array_keys($indexes[$mica_relation_record->child_bundle]);
	}
	return $relation;
}

/**
 * Delete relation by id
 */
function _mica_delete_relation($relation) {
	db_delete('mica_relation')->condition('id', $relation['id'])->execute();
}

