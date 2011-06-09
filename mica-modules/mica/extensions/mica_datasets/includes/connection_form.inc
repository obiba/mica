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

function _mica_datasets_create_connectors_form() {
  $form = array();
  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css'),),
    '#attributes' => array('id' => 'dataset-connectors'),
  );
  return $form;
}

function _mica_datasets_connection_form_id($dataset_node_id, $study_node_id) {
  return MICA_CONNECTION_PREFIX . $dataset_node_id . '-' . $study_node_id;
}

function _mica_datasets_add_connection_form(&$form, &$form_state, $dataset_node_id, $study_node_id, $title) {
  _mica_datasets_add_connection_container_form($form, $form_state, $dataset_node_id, $study_node_id, $title);
  _mica_datasets_add_connection_type_form($form, $dataset_node_id, $study_node_id);
  _mica_datasets_add_connection_config_form($form, $form_state, $dataset_node_id, $study_node_id);
  _mica_datasets_add_connection_remove_button($form, $dataset_node_id, $study_node_id);
}

function _mica_datasets_add_submit_button(&$form) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#attributes' => array('style' => array('display:block;')),
  );
}

function _mica_datasets_add_connection_container_form(&$form, &$form_state, $dataset_node_id, $study_node_id, $title) {
  $connection_form_id = _mica_datasets_connection_form_id($dataset_node_id,$study_node_id);

    
  $form[$connection_form_id] = array(
    '#type' => 'fieldset',
    '#title' => $title,
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#prefix' => '<div id="' . $connection_form_id . '-replace">',
    '#suffix' => '</div>',
  );

  $form[$connection_form_id][MICA_DATASET_ID] = array(
    '#type' => 'hidden', 
    '#value' => $dataset_node_id,
  );

  $form[$connection_form_id][MICA_STUDY_ID] = array(
    '#type' => 'hidden', 
    '#value' => $study_node_id,
  );

  /*$node_arg = _mica_datasets_get_node_form_arg($form_state);
  $node = NULL;
  if ($node_arg->type == 'dataset') {
    $node = node_load($study_node_id);
  }
  else {
    $node = node_load($dataset_node_id);
  }
  $uri = entity_uri('node', $node);
  $form[$connection_form_id]['link'] = array(
    '#type' => 'link',
    '#title' => $node->title,
    '#href' => $uri['path'],
    '#options' => $uri['options'],
  );*/
}

function _mica_datasets_add_connection_type_form(&$form, $dataset_node_id, $study_node_id) {
  $connection_form_id = _mica_datasets_connection_form_id($dataset_node_id,$study_node_id);

  // connection-type
  $form[$connection_form_id][MICA_CONNECTION_TYPE]= array(
    '#type' => 'select', 
    '#title' => t('Connection'), 
    '#options' => _mica_datasets_connection_types(),
  //'#description' => t('Select which type of connection is to be used to retrieve variables and data from the study to contribute to the dataset.'),
    '#ajax' => array(
      'path' => 'mica/ajax/dataset/' . $dataset_node_id . '/' . $study_node_id . '/edit',
      'wrapper' => $connection_form_id .'-' . MICA_CONNECTION_CONFIG . '-replace',
  ),
  );
}

function _mica_datasets_add_connection_config_form(&$form, &$form_state, $dataset_node_id, $study_node_id) {
  $connection_form_id = _mica_datasets_connection_form_id($dataset_node_id,$study_node_id);
  $connection_types = _mica_datasets_connection_types();

  $selected_type = isset($form_state['values'][$connection_form_id][MICA_CONNECTION_TYPE]) ? $form_state['values'][$connection_form_id][MICA_CONNECTION_TYPE] : key($connection_types);

  // connection-config
  $prefix = '<div id="' . $connection_form_id .'-' . MICA_CONNECTION_CONFIG . '-replace">';
  if ($selected_type == 'none') {
    $prefix = '<div id="' . $connection_form_id .'-' . MICA_CONNECTION_CONFIG . '-replace" style="display:none;">';
  }
  $form[$connection_form_id][MICA_CONNECTION_CONFIG]= array(
    '#title' => t('Configuration'),
    '#type' => 'fieldset',
    '#prefix' => $prefix,
    '#suffix' => '</div>',
  );

  // connection-config implementation
  if ($selected_type != 'none') {
    $study_node = node_load($study_node_id);
    $form_items = _mica_datasets_add_connection_config_implementation_form($study_node, $selected_type);
    foreach ($form_items as $key => &$form_item) {
      $form[$connection_form_id][MICA_CONNECTION_CONFIG][$key] = $form_item;
    }
  }

}

function _mica_datasets_add_connection_config_implementation_form(&$study_node, $selected_type) {
  $form_items = array();

  // todo load the right MicaDatasetConnectionInterface implementation
  if ($selected_type == 'opal') {
    $form_items = _mica_datasets_opal_connector_form($study_node);
  }

  return $form_items;
}

function _mica_datasets_add_connection_remove_button(&$form, $dataset_node_id, $study_node_id) {
  $connection_form_id = _mica_datasets_connection_form_id($dataset_node_id,$study_node_id);

  $form[$connection_form_id]['remove'] = array(
      '#type' => 'submit',
      '#value' => t('Remove'),
      '#ajax' => array(
        'path' => 'mica/ajax/dataset/' . $dataset_node_id . '/' . $study_node_id . '/delete',
        'wrapper' => 'dataset-connectors',
  ),
  );
}

function _mica_datasets_connectors_form_validate($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (strpos($key,MICA_CONNECTION_PREFIX) !== FALSE) {
      $connection_type = $form_state['values'][$key][MICA_CONNECTION_TYPE];

      if (array_key_exists(MICA_CONNECTION_CONFIG, $form_state['values'][$key]) && $connection_type != 'none') {
        //debug($form_state['values'][$key][MICA_CONNECTION_CONFIG]);
        $form_state['values'][$key][MICA_CONNECTION_CONFIG][MICA_STUDY_ID] = $form_state['values'][$key][MICA_STUDY_ID];
        $form_state['values'][$key][MICA_CONNECTION_CONFIG][MICA_DATASET_ID] = $form_state['values'][$key][MICA_DATASET_ID];

        // todo make it validate by MicaDatasetConnectionInterface implementation
        $form_errors = array();
        if ($connection_type == 'opal') {
          $form_errors = _mica_datasets_opal_connector_form_validate($form, $form_state['values'][$key][MICA_CONNECTION_CONFIG], $form_state);

        }

        // display errors
        if (!empty($form_errors)) {
          $dataset_form_path = $key . '][' . MICA_CONNECTION_CONFIG . '][';
          foreach ($form_errors as $key => $msg) {
            form_set_error($dataset_form_path . $key, $msg);
          }
        }
      }
    }
  }
}

function _mica_datasets_connectors_form_submit($form, &$form_state) {
  // only submit will result in actual submission, all others rebuild.
  switch ($form_state['triggering_element']['#value']) {
    case t('Save'): // Submit: We're done.
      drupal_set_message(t('Your values have been submitted.'));
      return;
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

//
// utilities
//

function _mica_datasets_connection_types() {
  // todo get list of MicaDatasetConnectionInterface implementations
  //debug(mica_datasets_get_connection_info());
  return array(
    'none' => t('-none-'), 
    'opal' => t('Opal'),
  );
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

  // 
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
    $study_node = node_load($record['entity_id']);
    // study is published and is updatable
    if ($study_node->status == 1 && node_access('update', $study_node)) {
      $rval[$record['entity_id']] = $study_node;
    }
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
    );
  }
  $form_items['datasource'] = array (
      '#title' => t('Datasource'),
      '#type' => 'textfield',
  );
  $form_items['table'] = array (
      '#title' => t('Table'),
      '#type' => 'textfield',
  );

  return $form_items;
}

function _mica_datasets_opal_connector_form_validate($form, &$values, &$form_state) {
  //debug($values);
  $form_errors = array();

  if (array_key_exists('opal-url', $values)) {
    $value = trim($values['opal-url']);
    if ($value == '' || strpos($value,'https://') === FALSE) {
      $form_errors['opal-url'] = t('You must provide a valid Opal server url: https://...');
    }
  }
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

