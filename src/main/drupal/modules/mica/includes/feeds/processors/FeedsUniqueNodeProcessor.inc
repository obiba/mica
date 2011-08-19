<?php
// $Id$

/**
 * @file
 * Class definition of FeedsUniqueNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class FeedsUniqueNodeProcessor extends FeedsNodeProcessor {

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
      'key_field' => 'title',
    ) + parent::configDefaults();
  }
  
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $form['key_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Unique field'),
      '#description' => t('Select the field that will be used to check if the imported item already exists as a node.'),
      '#default_value' => $this->config['key_field'],
      '#required' => TRUE,
    );
        
    return $form;
  }
  
  public function configFormSubmit(&$values) {
    parent::configFormSubmit($values);
  }

  /**
   * Try to load an existing node
   */
  protected function loadOrCreateNewEntity(FeedsSource $source, $item) {
    $query = new EntityFieldQuery();
    if ($this->config['key_field'] == 'title') {
      $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', $this->config['content_type'])
                  ->propertyCondition($this->config['key_field'], $item[$this->config['key_field']])
                  ->execute();
    }
    else{
      $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', $this->config['content_type'])
                  ->fieldCondition($this->config['key_field'], 'value', $item[$this->config['key_field']], '=')
                  ->execute();
    }
                   
    if (!empty($result['node'])) {
      $entities = entity_load('node', array_keys($result['node']));
      $entity_id = array_keys($entities);
      
      // register it to Feeds
      
      return $entities[$entity_id[0]];
    }
    
    return parent::newEntity($source);
  }
  
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
  $state = $source->state(FEEDS_PROCESS);

    while ($item = $parser_result->shiftItem()) {
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
            $item = $parser_result->current_item;
            $entity = $this->loadOrCreateNewEntity($source, $item);
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