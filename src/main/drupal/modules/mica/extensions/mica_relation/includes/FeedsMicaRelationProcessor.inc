<?php
/**
 * @file
 * Class definition of FeedsMicaRelationProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class FeedsMicaRelationProcessor extends FeedsNodeProcessor {

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $types = node_type_get_names();
    $type = isset($types['article']) ? 'article' : key($types);
    return array(
      'content_type' => $type,
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
      'parent_bundle' => '',
      'parent_unique_id_field' => '',
    ) + parent::configDefaults();
  }

  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $types = node_type_get_names();
    // filter entity types that have mica_relation
    array_walk($types, 'check_plain');

    $form['parent_bundle'] = array(
      '#type' => 'select',
      '#title' => t('Parent content type'),
      '#description' => t('Select the content type for the parent node.'),
      '#options' => $types,
      '#default_value' => $this->config['parent_bundle'],
    );
    $form['parent_unique_id_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Parent unique id field'),
      '#description' => t('Select the field that will be used to find the parent node e.g. when importing nodes related to a Study, the value should be \'field_study_legacy_id\'.<br/><b>This field cannot be \'title\' or \'body\'</b>.'),
      '#default_value' => $this->config['parent_unique_id_field'],
      '#required' => TRUE,
    );
    return $form;
  }

  /**
   * Loads the existing Study Child from its existing parent
   */
  protected function loadParentEntity(FeedsSource $source, $parent_id) {

    $query = db_select('field_data_' . $this->config['parent_unique_id_field'], 'f')
      ->condition('bundle', $this->config['parent_bundle'])
      ->condition($this->config['parent_unique_id_field'] . '_value', $parent_id)
      ->fields('f', array('entity_id'));
    $result = $query->execute();
    // Exception when the parent does not exist return null
    foreach ($result as $row) {
      // Get the mica relation based on the type...
      $relation = mica_relation_find_relations_by_parent_and_child($this->config['parent_bundle'], $this->config['content_type']);
      if (!empty($relation)) {
        $parent = entity_load('node', array($row->entity_id));
        $child_id = $parent[$row->entity_id]->{$relation->options['node_reference']}[LANGUAGE_NONE][0]['nid'];
        $nodes = entity_load('node', array($child_id));
        $node = $nodes[$child_id];
        $node->changed = REQUEST_TIME;
        $node->log = 'Updated by FeedsMicaProcessor';
      }
    }
    return $node;
  }

  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);

    while ($item = $parser_result->shiftItem()) {
      // Always load from study_legacy_id
      if (!($entity_id = $this->existingEntityId($source, $parser_result)) ||
        ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)
      ) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }

        try {
          // Assemble node, map item to it, save.
          if (empty($entity_id)) {
            // Get the node from the parent study...
            $study_id_field = 'field_study_legacy_id'; // default study id field name
            foreach ($this->config['mappings'] as $mapping) {
              if ($mapping['target'] === 'field_study_legacy_id') {
                $study_id_field = $mapping['source'];
                break;
              }
            }
            $parent_id = $parser_result->current_item[$study_id_field];
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
        } catch (Exception $e) {
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
      '@entity' => drupal_strtolower($info['label']),
      '@entities' => drupal_strtolower($info['label plural']),
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
        'message' => t('There are no new @entities.', array('@entities' => drupal_strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message, array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }

}


