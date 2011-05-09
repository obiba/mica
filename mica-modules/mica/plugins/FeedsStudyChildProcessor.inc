<?php
// $Id$ 

/**
 * @file
 * Class definition of FeedsStudyChildProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class FeedsStudyChildProcessor extends FeedsNodeProcessor {

  /**
   * Loads the existing Study Child from its existing parent
   */
  protected function loadParentEntity(FeedsSource $source, $parent_id, $child_type) {
    $query = db_select('field_data_field_study_legacy_id', 'f')
      ->condition('bundle', 'study')
      ->condition('field_study_legacy_id_value', $parent_id)
      ->fields('f', array('entity_id'));
    $result = $query->execute();

    // Exception when the parent does not exist return null
    // Get the mica relation based on the type...
    module_load_include('inc', 'mica', 'includes/relations');
    foreach ($result as $row) {
      $parent = entity_load('node', array($row->entity_id));
      $relations = _mica_find_relations_by_parent('study');
      if (!empty($relations)) {
        foreach ($relations as $relation) {
          $child_relation_type = $relation->child_bundle;
          if ($child_relation_type == $this->config['content_type']) {
            $child_id = $parent[$row->entity_id]->{$relation->options['node_reference']}['und'][0]['nid'];
            $nodes = entity_load('node', array($child_id));
            
            $node = $nodes[$child_id];
            $node->type = $this->config['content_type'];
            $node->changed = REQUEST_TIME;
            $node->language = LANGUAGE_NONE;
            node_object_prepare($node);
            // Populate properties that are set by node_object_prepare().
            $node->log = 'Updated by FeedsStudyInfoProcessor';
            //$node->uid = $this->config['author'];
               
            break;
          }
        }
      }
    }
    return $node;
  }
  
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);

    while ($item = $parser_result->shiftItem()) {
      // Always load from study_legacy_id
      if (!($entity_id = $this->existingEntityId($source, $parser_result)) ||
           ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }

        try {
          // Assemble node, map item to it, save.
          if (empty($entity_id)) {
            // Get the node from the parent study...
            $parent_id = $parser_result->current_item['field_study_legacy_id'];
            $entity = $this->loadParentEntity($source, $parent_id);
            // check if node is empty
            if (empty($entity)) {
              throw new FeedsValidationException(t('There is no Study with specified Legacy Id:') . $parent_id);
            }
            $this->newItemInfo($entity, $source->feed_nid, $hash);
          }
          else {
            $entity = $this->entityLoad($source, $entity_id);
            // If an existing item info can't be loaded, create one.
            if (!$this->loadItemInfo($entity)) {
              $this->newItemInfo($entity, $source->feed_nid, $hash);
              $entity->feeds_item->entity_id = $entity_id;
            }
          }
          $this->map($source, $parser_result, $entity);
          $this->entityValidate($entity);
          $this->entitySave($entity);

          // Track progress.
          if (empty($entity_id)) {
            $state->created++;
          }
          else {
            $state->updated++;
          }
        }
        catch (Exception $e) {
          $state->failed++;
          drupal_set_message($e->getMessage(), 'warning');
          $message = $e->getMessage();
          $message .= '<h3>Original item</h3>';
          $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
          $message .= '<h3>Entity</h3>';
          $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
          $source->log('import', $message, array(), WATCHDOG_ERROR);
        }
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Created @number @entity',
          'Created @number @entities',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity',
          'Updated @number @entities',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity',
          'Failed importing @number @entities',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message, array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }
  
}
