<?php

/**
 * @file
 * Class definition of FeedsStudyInfoProcessor.
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
    
    /*$targets = parent::getMappingTargets();
    foreach ($targets as $key => $value){
    	 $fields[$key] = $targets[$key]['name'];
    }
    
    $types = node_type_get_names();
    $form['content_type'] = array(
      '#type' => 'select',
      '#title' => t('Content type'),
      '#description' => t('Select the content type for the nodes to be created. <strong>Note:</strong> Users with "import !feed_id feeds" permissions will be able to <strong>import</strong> nodes of the content type selected here regardless of the node level permissions. Further, users with "clear !feed_id permissions" will be able to <strong>delete</strong> imported nodes regardless of their node level permissions.', array('!feed_id' => $this->id)),
      '#options' => $types,
      '#default_value' => $this->config['content_type'],
      '#attributes' => array('class' => array('enabled-for-ajax')),
      //'#ajax' => array(
      //  'callback' => '_refresh_key_field',
      //	'wrapper' => 'key_field_container',	
      //),
    );*/
    
    $form['key_field'] = array(
      //'#type' => 'select',
      '#type' => 'textfield',
      '#title' => t('Unique field'),
      '#description' => t('Select the field that will be used to check if the imported item already exists as a node. In the case of a Study you should use the field_study_legacy_id.'),
      '#default_value' => $this->config['key_field'],
      //'#options' => $fields,
      '#required' => TRUE,
      //'#prefix' => '<div id="key_field_container">',
      //'#suffix' => '</div>',
      //'#attributes' => array('class' => array('enabled-for-ajax')),
    );
        
    return $form;
  }
  
  //public function refresh_key_field($form, $form_state){
  //	return $form;
  //}
  
  public function configFormSubmit(&$values) {
    parent::configFormSubmit($values);
  }

  /**
   * Try to load an existing node
   */
  protected function loadOrCreateNewEntity(FeedsSource $source, $item) {
    $query = db_select('node', 'n')
      ->condition('type', $this->config['content_type'])
      ->condition($this->config['key_field'], $item[$this->config['key_field']])
      ->fields('n', array('nid'));
      $result = $query->execute();

    foreach($result as $row){
      return node_load($row->nid);
    }

    return parent::newEntity($source);
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
          $message .= '<pre>' . var_export($item, true) . '</pre>';
          $message .= '<h3>Entity</h3>';
          $message .= '<pre>' . var_export($entity, true) . '</pre>';
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
