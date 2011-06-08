<?php

/**
 * @file
 * Mica Datasets pages.
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

/**
 * Display form for creating dataset connection entities for a given study.
 */
function mica_datasets_study_datasets_edit_page($node) {
  drupal_set_title(t('!title -- Datasets', array('!title' => $node->title)));
  if (!property_exists($node, 'mica_dataset'))  {
    drupal_set_message(t('dataset content type is broken, missing field: !name', array('!name' => 'mica_dataset')), 'error');
    return '';
  }
  else {
    return drupal_get_form('mica_datasets_study_datasets_form', $node);
  }
}

/**
 * Display form for creating dataset connection entities for a given dataset.
 */
function mica_datasets_dataset_studies_edit_page($node) {
  drupal_set_title(t('!title -- Studies', array('!title' => $node->title)));
  return drupal_get_form('mica_datasets_dataset_studies_form', $node);
}

/**
 * Display form for fetching variables for a given dataset.
 */
function mica_datasets_dataset_variables_edit_page($node) {
  drupal_set_title(t('!title -- Participant Variables', array('!title' => $node->title)));
  return 'TODO';
}


/**
 * Display form for submitting queries.
 */
function mica_datasets_dataset_query_page($node) {
  drupal_set_title(t('!title Query', array('!title' => $node->title)));
  return 'TODO';
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for editing connection form.
 */
function mica_dataset_edit_ajax_form_callback($dataset_node, $study_node) {
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);
  return $form[_mica_datasets_connection_form_id($dataset_node->nid, $study_node->nid)][MICA_CONNECTION_CONFIG];
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument
 * for deleting a dataset reference in a study.
 */
function mica_dataset_delete_ajax_form_callback($dataset_node, $study_node) {
  list($form, $form_state) = ajax_get_form();

  // update node referenced by the form_state
  $node_arg = $form_state['build_info']['args'][0];
  $node = $node_arg;
  if ($node_arg->type != 'study') {
    $node = $study_node;
  }
  foreach ($node->mica_dataset[$node->language] as $key => $value) {
    if ($value['nid'] == $dataset_node->nid) {
      unset($node->mica_dataset[$node->language][$key]);
      break;
    }
  }
  node_save($node);

  $connection_form_id = _mica_datasets_connection_form_id($dataset_node->nid, $study_node->nid);

  // remove the input values so that the part of the form which is removed is not validated.
  unset($form_state['input'][$connection_form_id]);

  // todo remove the corresponding connector entity
  drupal_process_form($form['#form_id'], $form, $form_state);
   
  return $form;
}


//
// mica_datasets_dataset_studies_form
//

/**
 * Build the dataset studies form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_dataset_studies_form($form, &$form_state) {
  $dataset_node = _mica_datasets_get_node_form_arg($form_state);
  $dataset_node_id = $dataset_node->nid;

  $study_node_ids = _mica_datasets_get_study_ids($dataset_node->nid);

  $form = _mica_datasets_create_connectors_form();
  
  // study list
  $studies_options = _mica_datasets_studies_options($study_node_ids);
  if (!empty($studies_options)) {
    $form['studies']= array(
      '#type' => 'select', 
      '#title' => t('Studies'), 
      '#options' => $studies_options,
    );
    $form['add-study'] = array(
      '#type' => 'submit',
      '#value' => t('Add Study'),
    );
  }

  foreach ($study_node_ids as $study_node_id => $study_node) {
    _mica_datasets_add_connection_form($form, $form_state, $dataset_node_id, $study_node_id, $study_node->title);
  }

  if (!empty($study_node_ids)) {
    _mica_datasets_add_submit_button($form);
  }

  return $form;
}

/**
 * Validate the dataset studies form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_dataset_studies_form_validate($form, &$form_state) {
  _mica_datasets_connectors_form_validate($form, $form_state);
}

/**
 * Submit the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_dataset_studies_form_submit($form, &$form_state) {
  _mica_datasets_connectors_form_submit($form, $form_state);
}

//
// mica_datasets_study_datasets_form
//

/**
 * Build the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_study_datasets_form($form, &$form_state) {
  $study_node = _mica_datasets_get_node_form_arg($form_state);
  $study_node_id = $study_node->nid;

  $dataset_node_ids = _mica_datasets_node_field_values($study_node, 'mica_dataset');

  $form = _mica_datasets_create_connectors_form();

  // dataset list
  $datasets_options = _mica_datasets_datasets_options($study_node);
  if (!empty($datasets_options)) {
    $form['datasets']= array(
      '#type' => 'select', 
      '#title' => t('Datasets'), 
      '#options' => $datasets_options,
    );
    $form['add-dataset'] = array(
      '#type' => 'submit',
      '#value' => t('Add Dataset'),
    );
  }

  foreach ($dataset_node_ids as $dataset_node_id_value) {
    $dataset_node_id = $dataset_node_id_value['nid'];
    $dataset_node = node_load($dataset_node_id);

    _mica_datasets_add_connection_form($form, $form_state, $dataset_node_id, $study_node_id, $dataset_node->title);
  }

  if (!empty($dataset_node_ids)) {
    _mica_datasets_add_submit_button($form);
  }

  return $form;
}

/**
 * Validate the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_study_datasets_form_validate($form, &$form_state) {
  _mica_datasets_connectors_form_validate($form, $form_state);
}

/**
 * Submit the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_study_datasets_form_submit($form, &$form_state) {
  _mica_datasets_connectors_form_submit($form, $form_state);
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

function _mica_datasets_create_connectors_form() {
  $form = array();
  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/dataset_connection.css'),),
    '#attributes' => array('id' => 'dataset-connectors'),
  );
  return $form;
}

function _mica_datasets_get_node_form_arg(&$form_state) {
  return $form_state['build_info']['args'][0];
}

/**
 * Get the list of dataset nodes that can be added to the given study node.
 * @param study node $study_node
 */
function _mica_datasets_datasets_options($study_node)  {
  $rval = array();
  $dataset_node_ids = array();
  foreach (_mica_datasets_node_field_values($study_node, 'mica_dataset') as $dataset_node_id_value) {
    $dataset_node_ids[] = $dataset_node_id_value['nid'];
  }

  // get all nodes of dataset type that are published, accessible
  // and not already datasets of current study
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

function _mica_datasets_get_study_ids($dataset_node_id) {
  $rval = array();

  // get all nodes of study type that are published, accessible
  // and are related to current dataset
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

function _mica_datasets_studies_options(&$study_node_ids) {
  $rval = array();

  // get all nodes of study type that are published, accessible
  // and are not already related to current dataset
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
// connection form functions
//

function _mica_datasets_connection_form_id($dataset_node_id, $study_node_id) {
  return MICA_CONNECTION_PREFIX . $dataset_node_id . '-' . $study_node_id;
}

function _mica_datasets_add_connection_form(&$form, &$form_state, $dataset_node_id, $study_node_id, $title) {
  _mica_datasets_add_connection_container_form($form, $dataset_node_id, $study_node_id, $title);
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

function _mica_datasets_add_connection_container_form(&$form, $dataset_node_id, $study_node_id, $title) {
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

function _mica_datasets_add_connection_config_implementation_form($study_node, $selected_type) {
  $form_items = array();
  
  // todo load the right MicaDatasetConnectionInterface implementation  
  if ($selected_type == 'opal') {
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

      // todo make it validate by MicaDatasetConnectionInterface
      if (array_key_exists(MICA_CONNECTION_CONFIG, $form_state['values'][$key]) && $connection_type == 'opal') {
        //debug($form_state['values'][$key][MICA_CONNECTION_CONFIG]);
        $form_state['values'][$key][MICA_CONNECTION_CONFIG][MICA_STUDY_ID] = $form_state['values'][MICA_STUDY_ID];
        $form_state['values'][$key][MICA_CONNECTION_CONFIG][MICA_DATASET_ID] = $form_state['values'][$key][MICA_DATASET_ID];

        _mica_datasets_edit_opal_form_validate($form, $form_state['values'][$key][MICA_CONNECTION_CONFIG], $form_state);
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
// connection implementations, to be moved
//

function _mica_datasets_edit_opal_form_validate($form, &$values, &$form_state) {
  //debug($values);
  $dataset_form_path = MICA_DATASET_PREFIX . $values[MICA_DATASET_ID] . '][' . MICA_CONNECTION_CONFIG . ']';

  if (array_key_exists('opal-url', $values)) {
    $value = trim($values['opal-url']);
    if ($value == '' || strpos($value,'https://') === FALSE) {
      form_set_error($dataset_form_path . '[opal-url', t('You must provide a valid Opal server url: https://...'));
    }
  }
  $value = trim($values['datasource']);
  if ($value == '') {
    form_set_error($dataset_form_path . '[datasource', t('You must provide a valid Opal datasource name.'));
  }
  $value = trim($values['table']);
  if ($value == '') {
    form_set_error($dataset_form_path . '[table', t('You must provide a valid Opal table name.'));
  }
}

