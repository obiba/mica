<?php

/**
 * Enhance the content type form with mica_relation extensions.
 */
function _mica_node_type_form_alter(&$form, $form_state) {
	if (isset($form['type'])) {
  	
  	$current_type = $form['#node_type']->type;
		$relation = _mica_find_relation_by_child($current_type);
  	  	
		$existing_types = array();
		foreach (node_type_get_types() as $type) {
			if($type->type != 'mica_relation' && $type->type != $current_type)
			$existing_types[$type->type] = $type->name;
		}  	
  	
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
        'js' => array(drupal_get_path('module', 'mica') . '/mica-node-form.js'),
      ),    
    );
    $form['mica_relation']['parent_type'] = array(
      '#type' => 'select',
      '#title' => t('Parent'),
    	'#description' => t('Select parent content type'),
      '#default_value' => empty($relation) ? '' : $relation['parent'],
      '#options' => array_merge(array('' => t('None')), $existing_types),    
    );  
    
    $form['#submit'][] = '_mica_edit_node_type_relation';    
  }	
}

/**
 * Save relation info on content type edition 
 */
function _mica_edit_node_type_relation($form, &$form_state) {
	$previous_type = $form['#node_type']->type;
	$new_type = trim($form_state['values']['type']);
	$name = trim($form_state['values']['name']);
	$parent_type = trim($form_state['values']['parent_type']);
	$relation = _mica_find_relation_by_child($previous_type);
		
	if(empty($parent_type)) {
		
		if(!empty($relation)) {
			_mica_delete_relation_by_id($relation['id']);
		}
					
	} else {
		
		$relation['parent'] = $parent_type;
		$relation['child'] = $new_type;		
		
		$previous_relation = _mica_find_relation_by_child($previous_type);
		if(empty($previous_relation)) {

			// set reference node name only on creation
			$relation['node_reference'] = 'mica_' . $new_type;	
			
			// create node reference field
			_mica_add_node_reference_to_parent($relation, $name);
			
			// check if parent type already has content
			$query = new EntityFieldQuery;
			$result = $query->entityCondition('entity_type', 'node')
											->entityCondition('bundle', $relation['parent'])
											->propertyCondition('status', 1)
											->execute();			
			if (!empty($result['node'])) {
	 			$entities = entity_load('node', array_keys($result['node']));
	 			foreach ($entities as $entity) {
	 				mica_node_insert($entity);	// create missing child content
	 			}
			}												
			
		} else {
			
			// check if parent type has content
			$query = new EntityFieldQuery;
			$result = $query->entityCondition('entity_type', 'node')
											->entityCondition('bundle', $previous_relation['parent'])
											->propertyCondition('status', 1)
											->execute();			
			if(empty($result)) {
				// no content for parent type, we can replace node reference field
				field_delete_field($previous_relation['node_reference']);
				$relation['node_reference'] = 'mica_' . $new_type;					
				_mica_add_node_reference_to_parent($relation, $name);				 
			} else {
				// update node reference field label
				$field_instance = field_info_instance('node', $previous_relation['node_reference'], $previous_relation['parent']);
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
				$relation['child'] => $relation['child']
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
    'bundle' => $relation['parent'],
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
function _mica_find_relation_by_parent_or_child($parent_or_child_type) {
	$relations = array();
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.parent = :type or r.child = :type', 
							array(':type' => $parent_or_child_type));	
	foreach ($result as $record) {
		$relations[$record->id] = array(
			'id' => $record->id,
			'parent' => $record->parent,
			'child' => $record->child,
			'node_reference' => $record->node_reference,
		);
	}
	return $relations;	
}

function _mica_save_relation(array $relation) {
	if(isset($relation['id'])) {
		// update
		db_update('mica_relation')
		  ->fields(array(
			    'parent' => $relation['parent'],
			    'child' => $relation['child'],
			    'node_reference' => $relation['node_reference'],
		 	 	))
		  ->condition('id', $relation['id'])
		  ->execute();
	} else {
		// insert
		$relation['id'] = db_insert('mica_relation')->fields($relation)->execute();		
	}
	return $relation;	
}

/**
 * Returns an array of relations for this parent type with relation ID as key
 */
function _mica_find_relations_by_parent($parent_type) {
	$relations = array();
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.parent = :parent', array(':parent' => $parent_type));	
	foreach ($result as $record) {
		$relations[$record->id] = array(
			'id' => $record->id,
			'parent' => $record->parent,
			'child' => $record->child,
			'node_reference' => $record->node_reference,
		);
	}
	return $relations;
}

/**
 * Returns a unique relation for this child type 
 */
function _mica_find_relation_by_child($child_type) {
	$result = db_query('SELECT * FROM {mica_relation} r WHERE r.child = :child', array(':child' => $child_type));	
	foreach ($result as $record) {
		return array(
			'id' => $record->id,
			'parent' => $record->parent,
			'child' => $record->child,
			'node_reference' => $record->node_reference,
		);
	}
	return NULL;
}

/**
 * Delete relations where this type is parent or child
 */
function _mica_delete_relation_by_parent_or_child($parent_or_child_type) {
	$or = db_or()->condition('parent', $parent_or_child_type)->condition('child', $parent_or_child_type);
	db_delete('mica_relation')->condition($or)->execute();
}

/**
 * Delete relation by id
 */
function _mica_delete_relation_by_id($id) {
	db_delete('mica_relation')->condition('id', $id)->execute();
}