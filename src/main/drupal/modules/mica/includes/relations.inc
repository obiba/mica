<?php
// $Id$

include_once(drupal_get_path('module', 'mica_core') . '/mica_core.search.utils.inc');

/**
 * @file
 * Mica relations utilities.
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
      if ($type->type != 'mica_relation' && $type->type != $current_type)
      $existing_types[$type->type] = $type->name;
    }

    $selected_parent_bundle = isset($form_state['values']['parent_bundle'])
    ? $form_state['values']['parent_bundle']
    : (empty($relation) ? '' : $relation->parent_bundle);


    $indexes = mica_core_find_indexes_by_bundle();

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
      '#title' => t('Cascade events'),
      '#description' => t('Cascade parent\'s events: create, update, publish, unpublish.'),
      '#default_value' => empty($relation) ? TRUE : $relation->options['cascaded'],
    );

    $form['mica_relation']['indexed'] = array(
      '#type' => 'checkbox',
      '#title' => t('Index content'),
      '#description' => t('Index as part of its parent'),
      '#default_value' => empty($relation) ? TRUE : $relation->options['indexed'],
      '#attributes' => array('class' => array('enabled-for-ajax')),
      '#ajax' => array(
        'callback' => '_mica_ajax_populate_indexes_callback',
        'wrapper' => 'child-indexes-container',
      ),
    );

    $parent_indexes = empty($selected_parent_bundle) || !array_key_exists($selected_parent_bundle, $indexes) 
      ? array() 
      : $indexes[$selected_parent_bundle];
    if (empty($relation)) {
      if (empty($parent_indexes)) {
        $child_indexes_default_value = array();
      }
      else {
        $child_indexes_default_value = array_keys($parent_indexes);
      }
    }
    else {
      $child_indexes_default_value = empty($relation->options['child_indexes'])
        ? array()
        : $relation->options['child_indexes'];
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
  if (!empty($parent_bundle) && $form_state['values']['indexed'] == 1) {
    $valid = FALSE;
    foreach ($form_state['values']['child_indexes'] as $child_indexes) {
      if ($child_indexes) {
        $valid = TRUE;
        break;
      }
    }
    if (!$valid) {
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

  if (empty($parent_bundle)) {

    if (!empty($relation)) {
      $relation->delete();
      watchdog('mica', 'Delete relation between parent %parent and child %child',
      array(
          '%parent' => $relation->parent_bundle,
          '%child' => $relation->child_bundle, 
      ), WATCHDOG_INFO);
    }

  }
  else {
     
    if (empty($relation)) {
      $relation = new MicaRelation();
      $relation->parent_bundle = $parent_bundle;
      $relation->child_bundle = $new_type;

      $parent_bundle_infos = node_type_load($parent_bundle);
      $child_bundle_infos = node_type_load($new_type);
      $relation->label = $parent_bundle_infos->name . ' » ' . $child_bundle_infos->name;
    }

    $relation->options['cascaded'] = $form_state['values']['cascaded'];
    $relation->options['indexed'] = $form_state['values']['indexed'];
    if ($relation->options['indexed']) {
      $relation->options['child_indexes'] = $form_state['values']['child_indexes'];
    }
    else {
      $relation->options['child_indexes'] = array();
    }

    $previous_relation = _mica_find_relation_by_child($previous_type);
    if (empty($previous_relation)) {

      // create new relation

      watchdog('mica', 'Create relation between parent %parent and child %child',
        array(
          '%parent' => $relation->parent_bundle,
          '%child' => $relation->child_bundle, 
        ), WATCHDOG_INFO);

      $indexes = mica_core_find_indexes_by_bundle();
      $relation->options['parent_indexes'] = empty($indexes[$relation->parent_bundle])
        ? array()
        : array_keys($indexes[$relation->parent_bundle]);

      // set reference node and relation only at creation
      $relation->options['node_reference'] = 'mica_' . $new_type;
      $relation->options['relation'] = $relation->parent_bundle . '_' . $relation->child_bundle;
      $relation->options['relation_parent_field'] = $relation->child_bundle . '_relation';
      $relation->options['relation_child_field'] = $relation->parent_bundle . '_relation';

      // create node reference field
      $relation->add_node_reference_to_parent($name);

      // check if parent type already has content
      $query = new EntityFieldQuery;
      $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $relation->parent_bundle)
      ->execute();
      if (!empty($result['node']) && $relation->options['cascaded']) {
        $entities = entity_load('node', array_keys($result['node']));
        foreach ($entities as $entity) {
          // create missing child nodes
          if ($relation->create_child_node($entity, isset($entity->menu) ? $entity->menu : array())) {
            node_save($entity);
          }
        }
      }

    }
    else {

      // check if parent type has content
      $query = new EntityFieldQuery;
      $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $previous_relation->parent_bundle)
      ->execute();
      if (empty($result)) {

        // no content for parent type, we can replace node reference field and relation
        field_delete_field($previous_relation->options['node_reference']);
        $relation->options['node_reference'] = 'mica_' . $new_type;
        $relation->add_node_reference_to_parent($name);

      }
      else {

        // update node reference field label
        $field_instance = field_info_instance('node', $previous_relation->options['node_reference'], $previous_relation->parent_bundle);
        $field_instance['label'] = $name;
        field_update_instance($field_instance);

      }
    }
    $relation->save();
  }

}

/**
 * Returns an array of MicaRelations with relation ID as key
 */
function _mica_find_relation_by_parent_or_child($parent_or_child_bundle) {
  $query = new EntityFieldQuery;
  $parent_result = $query->entityCondition('entity_type', 'mica_relation')
  ->propertyCondition('parent_bundle', $parent_or_child_bundle)
  ->execute();
  $child_result = $query->entityCondition('entity_type', 'mica_relation')
  ->propertyCondition('child_bundle', $parent_or_child_bundle)
  ->execute();
  $result = array();
  if (isset($parent_result['mica_relation']) && isset($child_result['mica_relation'])) {
    $result = array_merge($parent_result['mica_relation'], $child_result['mica_relation']);
  }
  if (!empty($result)) {
    return entity_load('mica_relation', array_keys($result));
  }
  return array();
}

/**
 * Returns an array of MicaRelations for this parent type with relation ID as key
 */
function _mica_find_relations_by_parent($parent_bundle) {
  $query = new EntityFieldQuery;
  $result = $query->entityCondition('entity_type', 'mica_relation')
  ->propertyCondition('parent_bundle', $parent_bundle)
  ->execute();
  if (!empty($result['mica_relation'])) {
    return entity_load('mica_relation', array_keys($result['mica_relation']));
  }
  return array();
}

/**
 * Returns a unique MicaRelation for this parent and child type with relation ID as key
 */
function _mica_find_relations_by_parent_and_child($parent_bundle, $child_bundle) {
  $query = new EntityFieldQuery;
  $result = $query->entityCondition('entity_type', 'mica_relation')
  ->propertyCondition('parent_bundle', $parent_bundle)
  ->propertyCondition('child_bundle', $child_bundle)
  ->execute();
  if (!empty($result['mica_relation'])) {
    $keys = array_keys($result['mica_relation']);
    $relations = entity_load('mica_relation', $keys);
    return $relations[$keys[0]];
  }
  return NULL;
}

/**
 * Returns a unique MicaRelation for this child type
 */
function _mica_find_relation_by_child($child_bundle) {
  $query = new EntityFieldQuery;
  $result = $query->entityCondition('entity_type', 'mica_relation')
  ->propertyCondition('child_bundle', $child_bundle)
  ->execute();
  if (!empty($result['mica_relation'])) {
    $keys = array_keys($result['mica_relation']);
    $relations = entity_load('mica_relation', $keys);
    return $relations[$keys[0]];
  }
  return NULL;
}

function mica_node_title_exists($node_type, $title)  {
  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->condition('n.type', $node_type);
  $q->condition('n.title', $title);
  $q->range(0,1);
  $result = $q->execute();

  return $result->fetchField() ? TRUE : FALSE;
}
