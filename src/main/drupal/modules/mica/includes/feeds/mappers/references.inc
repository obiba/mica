<?php
// $Id$

/**
 * @file
 * Mapper that handles any fields added by the References module (node_reference, user_reference)
 *
 * Code is effectively a port of the mapper_for_nodereference_field patch to drupal 7, and borrows
 * heavily from the nodereference patch
 *
 */

/**
 * Implements hook_feeds_processor_targets_alter() for node_reference fields
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 *
 */
function node_reference_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'node_reference') {

      $targets[$name . ':title'] = array(
        'name' => $instance['label'] .  t(' (Node reference by node title)'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the node matched by node title.', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':nid'] = array(
        'name' => $instance['label'] . t(' (Node reference by node ID)'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the node matched by node ID.', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':title:duplicates'] = array(
        'name' => $instance['label'] . t(' (Node reference by node title) -- allow duplicate nodes'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the node matched by node title. This target allows duplicate nodes (nodes can appear more than once in a field).', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':nid:duplicates'] = array(
        'name' => $instance['label'] . t(' (Node reference by node ID) -- allow duplicate nodes'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the node matched by node ID.  This target allows duplicate nodes (nodes can appear more than once in a field).', array('@label' => $instance['label'])),
        'real_target' => $name);
    }
  }
}
/**
 * Implements hook_feeds_processor_targets_alter() for user_reference fields
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 *
 */
function user_reference_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'user_reference') {

      $targets[$name . ':name'] = array(
        'name' => $instance['label'] . t(' (User reference by user name)'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the user matched by user name. ', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':uid'] = array(
        'name' => $instance['label'] . t(' (User reference by user ID)'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the user matched by user ID.', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':name:duplicates'] = array(
        'name' => $instance['label'] . t(' (User reference by user name) -- allow duplicate users'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the user matched by user name.  This target allows duplicate users (users can appear more than once in a field).', array('@label' => $instance['label'])),
        'real_target' => $name);

      $targets[$name . ':uid:duplicates'] = array(
        'name' => $instance['label'] . t(' (User reference by user ID) -- allow duplicate users'),
        'callback' => 'references_feeds_set_target',
        'description' => t('The @label field of the user matched by user ID.  This target allows duplicate users (users can appear more than once in a field).', array('@label' => $instance['label'])),
        'real_target' => $name);
    }
  }
}

/**
 * Callback for mapping both node reference and user_reference fields
 *
 * Implementation of hook_feeds_set_target().
 *
 * @param $source
 *   A FeedsSource object.
 * @param $entity
 *   The entity to map to.
 * @param $target
 *   The target key on $entity to map to.
 * @param $value
 *   The value to map. Can be an array or a string.
 */
function references_feeds_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple values.
  if (!is_array($value)) {
    $value = explode(',', $value);
  }

  // Determine whether we are matching against the title/user or nid/uid, and whether duplicates are allowed.
  $match_key;
  $duplicates;
  if (strpos($target, ':') !== FALSE) {
    $exploded = explode(':', $target, 3);
    $target = $exploded[0];
    $match_key = $exploded[1];
    if (array_key_exists(2, $exploded)) {
      $duplicates = $exploded[2];
    }
  }
  if (empty($duplicates)) {
    $value = array_unique($value);
  }

  // Load field definition.
  $info = field_info_field($target);
  // Parameters to handle differences between node references and user references
  if ($info['type'] == 'user_reference') {
    $idname = 'uid';
    $typename = 'user';
    $validate_function = 'user_reference_potential_references';
  }
  else {
    $idname = 'nid';
    $typename = 'node';
    $validate_function = 'node_reference_potential_references';
  }

  $field = isset($entity->$target) ? $entity->$target : array();
  if (!isset($field['und'])) {
    $field['und'] = array();
  }

  // Match values against nodes and add to field.
  foreach ($value as $v) {
    $id = NULL;

    switch ($match_key) {
      case 'title':
      case 'name':
        // Validate node title or user name.
        if ((is_string($v) && $v != '') || is_numeric($v)) {
          // Lookup potential exact matches for the value (limit to one result).
          // signature of _node_reference_potential_references has changed
          $options = array(
            'string' => $v,
            'match' => 'equals',
            'ids' => array(),
            'limit' => 1,
          );
          $matches = $validate_function($info, $options);
          // Use the first element of the potential matches.
          $id = key($matches);
        }

        // Alert if no match is found.
        if (empty($id)) {
          $f = field_info_field_by_id($info['id']);
          $reference_type_nb = 0;
  
          // Create a new node only if there is only one content type that can be referenced
          foreach ($f['settings']['referenceable_types'] as $key => $type) {
            if ($f['settings']['referenceable_types'][$key]) {
              $reference_type = $type;
              $reference_type_nb++;
            }
          }
          
          if ($reference_type_nb === 1 && isset($reference_type)) {
            // Check if the node exists
            $query = new EntityFieldQuery();
            $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', $reference_type)
                  ->propertyCondition('title', $v)
                  ->execute();
                  
            if (!empty($result['node'])) {
              $entities = entity_load('node', array_keys($result['node']));
              $entity_id = array_keys($entities);
              
              $node = $entities[$entity_id[0]];
              
              $id = $node->nid;
            }
            else {
              // create the node empty
              $node = new stdClass();
              $node->type = $reference_type;
              $node->title = $v;
              $node->changed = REQUEST_TIME;
              $node->language = LANGUAGE_NONE;
              node_object_prepare($node);
              // Populate properties that are set by node_object_prepare().
              $node->log = 'Created by References';
              $node->uid = $entity->uid;
              $node->status = $entity->status;
              node_save($node);
              
              $id = $node->nid;
              
              //drupal_set_message(t('Node %title has been automatically created !', array('%title' => $v)));
            }
          }
          else{
            drupal_set_message(t('%title does not match an existing ' . $typename, array('%title' => $v)));        
          }
        }
        break;

      case 'nid':
      case 'uid':
        // Make sure it is a positive integer.
        if ((is_int($v) || ctype_digit($v)) && $v > 0 && $v !== '') {
          // Make sure it is a valid node id or user id for this field.
          $matches = $validate_function($info, array('ids' => array($v)));
          $id = key($matches);
        }

        // Alert if no match is found.
        if (empty($id)) {
          drupal_set_message(t('%id is not a valid ' . $typename . ' id for this field.', array('%id' => $v)));
        }
        break;
    }

    if (isset($id)) {
      $reference = array($idname => $id);
      if (!empty($duplicates)) {
        // Add the reference, ignoring duplicates.
        $field['und'][] = $reference;
      }
      elseif (!in_array($reference, $field['und'])) {
        // Add the reference only if it doesn't already exist.
        $field['und'][] = $reference;
      }
     
      if ($info['cardinality'] == 1) {
        break;
      }
    }
  }
  $entity->{$target} = $field;
}