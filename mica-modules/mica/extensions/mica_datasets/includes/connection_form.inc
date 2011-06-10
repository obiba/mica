<?php

/**
 * @file
 * Mica Datasets connection form.
 */

/**
 * @defgroup mica_datasets_form_constants Mica datasets form constants
 * @{
 * Constants used to build the Mica dataset entity forms.
 */

define('MICA_STUDY_ID', 'study-id');
define('MICA_DATASET_ID', 'dataset-id');
define('MICA_CONNECTION_PREFIX', 'connection-');
define('MICA_CONNECTION_TYPE', 'connection-type');
define('MICA_CONNECTION_CONFIG', 'connection-config');

/**
 * @} End of "Mica datasets form constants".
 */

//
// connection form functions
//

/**
 * Base form for connectors.
 */
function _mica_datasets_connectors_form() {
  $form = array();
  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css'),),
    '#attributes' => array('id' => 'dataset-connectors'),
  );
  return $form;
}

/**
 * Build a connection data structure.
 * @param $dataset_node
 * @param $study_node
 * @param $parent_node
 */
function _mica_datasets_connection_data(&$dataset_node, &$study_node, $parent_node) {
  // todo fetch the connector entity
  $child_node = $parent_node->nid == $dataset_node->nid ? $study_node : $dataset_node;

  $connector = mica_dataset_connector_query($dataset_node->nid, $study_node->nid);

  $row = array(
    'parent' => _mica_datasets_connection_data_node($parent_node),
    'child' => _mica_datasets_connection_data_node($child_node),
    'connector' => array(
      'id' => $connector ? $connector->id : 0,
  MICA_DATASET_ID => $dataset_node->nid,
  MICA_STUDY_ID => $study_node->nid,
      'type' => $connector ? $connector->class : 'none',
      'description' => $connector ? $connector->description : '',
  ),
  );

  return $row;
}

/**
 * Extract usefull information from a node.
 * @param $node
 */
function _mica_datasets_connection_data_node(&$node) {
  $uri = entity_uri('node', $node);
  return array(
      'title' => $node->title,
      'id' => $node->nid, 
      'type' => $node->type,
      'path' => $uri['path'],
  );
}

/**
 * Add a tableselect option.
 * @param $options
 * @param $dataset_node
 * @param $study_node
 * @param $parent_node
 */
function _mica_datasets_add_connection_option(&$options, &$dataset_node, &$study_node, &$parent_node) {
  $data = _mica_datasets_connection_data($dataset_node, $study_node, $parent_node);
  $options[$data['child']['id']] = array(
      'child' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $data['child']['title'],
          '#href' => $data['child']['path'],
  )),
      'connection-type' => $data['connector']['type'],
      'description' => $data['connector']['description'],
      'actions' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => 'Edit',
          '#href' => 'mica/dataset/connector/' . $data['connector']['id'] . '/' . $data['connector'][MICA_DATASET_ID] . '/' . $data['connector'][MICA_STUDY_ID] . '/edit',
  )),
      'row' => $data,
  );
}

/**
 * Add tableselect form with delete selected items button.
 * @param $form
 * @param $header first column header
 * @param $empty text when list is empty
 * @param $options list of rows
 */
function _mica_datasets_add_table_form(&$form, $header, $empty, &$options) {
  $header = array (
    'child' => t($header),
    'connection-type' => t('Connection Type'),
    'description' => t('Description'),
    'actions' => '',
  );

  $form['table'] = array (
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t($empty),
  );

  if (!empty($options)) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected items'),
    );
  }
}

function _mica_datasets_connectors_form_submit($form, &$form_state) {

  switch ($form_state['triggering_element']['#value']) {
    case t('Delete selected items'):
      foreach ($form_state['values']['table'] as $selection) {
        if ($selection != 0) {
          $row = $form['table']['#options'][$selection]['row'];
          // update node referenced by the form_state
          $node = _mica_datasets_get_node_form_arg($form_state);
          if ($node->type != 'study') {
            $node = node_load($row['connector'][MICA_STUDY_ID]);
          }
          _mica_datasets_dataset_connection_delete($node, $row['connector'][MICA_DATASET_ID]);
        }
      }
      break;
    case t('Add Dataset'):
      // update node referenced by the form_state
      $study_node = $form_state['build_info']['args'][0];
      $study_node->mica_dataset[$study_node->language][] = array('nid' => $form_state['values']['datasets']);
      node_save($study_node);
      break;
    case t('Add Study'):
      // update selected node referenced with the one from the form_state
      $dataset_node = $form_state['build_info']['args'][0];
      $study_node = node_load($form_state['values']['studies']);
      $study_node->mica_dataset[$study_node->language][] = array('nid' => $dataset_node->nid);
      node_save($study_node);
      break;
  }

  // anything else will cause rebuild of the form and present it again.
  $form_state['rebuild'] = TRUE;
}

function _mica_datasets_dataset_connection_delete(&$study_node, $dataset_node_id) {
  foreach ($study_node->mica_dataset[$study_node->language] as $key => $value) {
    if ($value['nid'] == $dataset_node_id) {
      unset($study_node->mica_dataset[$study_node->language][$key]);
      // todo delete connector entity too
      $connector = mica_dataset_connector_query($dataset_node_id, $study_node->nid);
      if ($connector) {
        $connector->delete();
      }
      break;
    }
  }
  node_save($study_node);
}

function _mica_datasets_add_connection_config_implementation_form(&$study_node, $selected_type) {
  $form_items = array();

  // todo load the right MicaDatasetConnectionInterface implementation
  if ($selected_type == 'MicaDatasetOpalConnection') {
    $form_items = _mica_datasets_opal_connector_form($study_node);
  }

  return $form_items;
}

//
// utilities
//

function _mica_datasets_connection_types() {
  // todo get list of MicaDatasetConnectionInterface implementations
  //debug(mica_datasets_get_connection_info());
  return array(
    'none' => t('-none-'), 
    'MicaDatasetOpalConnection' => t('Opal'),
  );
}

function _mica_datasets_connection_options_validate(&$form, &$values, &$form_state, $connection_type) {
  $form_errors = array();
    
  // todo make it validate by MicaDatasetConnectionInterface implementation
  if ($connection_type == 'MicaDatasetOpalConnection') {
    $form_errors = _mica_datasets_opal_connector_form_validate($form, $values, $form_state);
  }
}

/**
 * Submit the options 
 * @param $form
 * @param $form_state
 * @param $connection_type
 */
function _mica_datasets_connection_options_submit(&$form, &$form_state, $connection_type) {
  $options = _mica_datasets_connection_config_values($form, $form_state);
  
  // todo make it submit by MicaDatasetConnectionInterface implementation
  if ($connection_type == 'MicaDatasetOpalConnection') {
    $options = _mica_datasets_opal_connector_form_submit($form, $options, $form_state);
  }
  
  return $options;
}

/**
 * Get the node provided provided as an argument to the form.
 * @param  $form_state
 */
function _mica_datasets_get_node_form_arg(&$form_state) {
  return $form_state['build_info']['args'][0];
}

/**
 * Get all nodes of dataset type that are published, accessible
 * and not already datasets of current study.
 * @param study node $study_node
 */
function _mica_datasets_datasets_options($study_node)  {
  $rval = array();
  $dataset_node_ids = array();
  foreach (_mica_datasets_node_field_values($study_node, 'mica_dataset') as $dataset_node_id_value) {
    $dataset_node_ids[] = $dataset_node_id_value['nid'];
  }

  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->addField('n', 'title');
  $q->condition('n.type', 'dataset','=');
  $q->condition('n.status', 1);
  if (!empty($dataset_node_ids)) {
    $q->condition('n.nid', $dataset_node_ids, 'NOT IN');
  }
  $q->addTag('node_access');
  $q->orderBy('n.title');

  $result = $q->execute();

  while($record = $result->fetchAssoc()) {
    $rval[$record['nid']] = $record['title'];
  }

  return $rval;
}

/**
 * Get all nodes of study type that are published, accessible
 * and are not already related to current dataset.
 * @param $study_node_ids
 */
function _mica_datasets_studies_options(&$study_node_ids) {
  $rval = array();

  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->addField('n', 'title');
  $q->condition('n.type', 'study','=');
  $q->condition('n.status', 1);
  if (!empty($study_node_ids)) {
    $q->condition('n.nid', array_keys($study_node_ids), 'NOT IN');
  }
  $q->addTag('node_access');
  $q->orderBy('n.title');

  $result = $q->execute();

  while($record = $result->fetchAssoc()) {
    $rval[$record['nid']] = $record['title'];
  }

  return $rval;
}

/**
 * Get all nodes of study type that are published, accessible
 * and are related to current dataset.
 * @param $dataset_node_id
 */
function _mica_datasets_get_study_ids($dataset_node_id) {
  $rval = array();

  $q = db_select('field_data_mica_dataset', 'f');
  $q->addField('f', 'entity_id');
  $q->condition('f.mica_dataset_nid', $dataset_node_id,'=');
  $q->condition('f.entity_type', 'node');
  $q->condition('f.bundle', 'study');
  $q->condition('f.deleted', 0);
  $q->addTag('node_access');

  $result = $q->execute();

  while($record = $result->fetchAssoc()) {
    $node = node_load($record['entity_id']);
    // study is published and is updatable
    if ($node->status == 1 && node_access('update', $node)) {
      $rval[$record['entity_id']] = $node;
    }
  }

  return $rval;
}

/**
 * Get all nodes of dataset type that are published, accessible
 * and are related to current study.
 * @param $study_node_id
 */
function _mica_datasets_get_dataset_ids($study_node_id) {
  $rval = array();

  $q = db_select('field_data_mica_dataset', 'f');
  $q->addField('f', 'mica_dataset_nid');
  $q->condition('f.entity_id', $study_node_id,'=');
  $q->condition('f.entity_type', 'node');
  $q->condition('f.bundle', 'study');
  $q->condition('f.deleted', 0);
  $q->addTag('node_access');

  $result = $q->execute();

  while($record = $result->fetchAssoc()) {
    $node = node_load($record['mica_dataset_nid']);
    // dataset is published and is updatable
    if ($node->status == 1 && node_access('view', $node)) {
      $rval[$record['mica_dataset_nid']] = $node;
    }
  }

  return $rval;
}

/**
 * Get the values for a node field.
 * @param node $node
 * @param string $field_name
 */
function _mica_datasets_node_field_values($node, $field_name) {
  $field = $node->$field_name;
  if ($field) {
    return $field[$node->language];
  }
  return array();
}

/**
 * Extract connection config specific values from form_state.
 * @param $form
 * @param $form_state
 */
function _mica_datasets_connection_config_values(&$form, &$form_state) {
  $values = array();
  foreach ($form_state['values'] as $key => $value) {
    if (array_key_exists($key, $form[MICA_CONNECTION_CONFIG])) {
      $values[$key] = $value;
    }
  }
  return $values;
}

//
// connection implementations, to be moved
//

function _mica_datasets_opal_connector_form($study_node) {
  $form_items = array();
  $opal_url = _mica_datasets_node_field_values($study_node, 'mica_opal');

  if (!empty($opal_url)) {
    $form_items['opal-url'] = array (
        '#type' => 'item',
        '#title' => t('Opal server'),
        '#markup' => !empty($opal_url) ? '<a href="' . $opal_url[0]['url'] . '">' . $opal_url[0]['url'] . '</a></div>' : '',
    );
  }
  else {
    $form_items['opal-url'] = array (
      '#title' => t('Opal server'),
      '#type' => 'textfield',
      '#description' => t('The Opal server secured url (https is required).'),
      '#required' => TRUE,
    );
  }
  $form_items['datasource'] = array (
    '#title' => t('Datasource'),
    '#type' => 'textfield',
    '#description' => t('The Opal datasource name.'),
    '#required' => TRUE,
  );
  $form_items['table'] = array (
    '#title' => t('Table'),
    '#type' => 'textfield',
    '#description' => t('The Opal table name from which variables and data can be fetched.'),
    '#required' => TRUE,
  );

  return $form_items;
}

function _mica_datasets_opal_connector_form_validate($form, &$values, &$form_state) {
  $form_errors = array();

  if (array_key_exists('opal-url', $values)) {
    $value = trim($values['opal-url']);
    if ($value == '' || strpos($value,'https://') === FALSE) {
      $form_errors['opal-url'] = t('You must provide a valid Opal server url: https://...');
    }
  }
  // todo check for valid chars in names
  $value = trim($values['datasource']);
  if ($value == '') {
    $form_errors['datasource'] = t('You must provide a valid Opal datasource name.');
  }
  $value = trim($values['table']);
  if ($value == '') {
    $form_errors['table'] = t('You must provide a valid Opal table name.');
  }

  return $form_errors;
}

function _mica_datasets_opal_connector_form_submit($form, &$values, &$form_state) {
  $options = array();
  if (array_key_exists('opal-url', $values)) {
    $study_node = node_load($form_state['values'][MICA_STUDY_ID]);
    $study_node->mica_opal[$study_node->language][] = array('url' => $values['opal-url']);
    node_save($study_node);
  }
  $options['datasource'] = trim($values['datasource']);
  $options['table'] = trim($values['table']);
  
  return $options;
}

