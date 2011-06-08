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
define('MICA_DATASET_PREFIX', 'dataset-');
define('MICA_CONNECTION_TYPE', 'connection-type');
define('MICA_CONNECTION_CONFIG', 'connection-config');

/**
 * @} End of "Mica datasets form constants".
 */

/**
 * Display form for creating dataset entities for a given study.
 */
function mica_datasets_edit_page($node) {
  drupal_set_title(t('!title Dataset Connections', array('!title' => $node->title)));
  return drupal_get_form('mica_datasets_edit_form', $node);
}

function _mica_datasets_node_field_values($node, $field_name) {
  $field = $node->$field_name;
  if ($field) {
    return $field[$node->language];
  }
  return array();
}

function mica_datasets_edit_form($form, &$form_state) {
  $node = $form_state['build_info']['args'][0];
  $dataset_node_ids = _mica_datasets_node_field_values($node, 'mica_dataset');

  $form = array();
  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/dataset_connection.css'),),
    '#attributes' => array('id' => 'dataset-connectors'),
  );

  // todo get list of MicaDatasetConnectionInterface implementations
  //debug(mica_datasets_get_connection_info());
  $connection_types = array(
    'none' => t('-none-'), 
    'opal' => t('Opal'),
  );


  foreach ($dataset_node_ids as $dataset_node_id_value) {
    $dataset_node_id = $dataset_node_id_value['nid'];
    $dataset_node = node_load($dataset_node_id);
    $dataset_form_id = MICA_DATASET_PREFIX . $dataset_node_id;

    $selected_type = isset($form_state['values'][$dataset_form_id][MICA_CONNECTION_TYPE]) ? $form_state['values'][$dataset_form_id][MICA_CONNECTION_TYPE] : key($connection_types);

    $form[$dataset_form_id ] = array(
      '#type' => 'fieldset',
      '#title' => $dataset_node->title,
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      '#tree' => TRUE,
      '#prefix' => '<div id="connector-' . $dataset_node_id . '-replace">',
      '#suffix' => '</div>',
    );

    $form[$dataset_form_id][MICA_DATASET_ID] = array(
      '#type' => 'hidden', 
      '#value' => $dataset_node_id,
    );

    // connection-type
    $form[$dataset_form_id][MICA_CONNECTION_TYPE]= array(
      '#type' => 'select', 
      '#title' => t('Connection'), 
      '#options' => $connection_types,
      '#description' => t('Select which type of connection is to be used to retrieve variables and data from the study to contribute to the dataset.'),
      '#ajax' => array(
        'path' => 'mica/ajax/dataset/' . $dataset_node_id . '/' . $node->nid . '/edit',
        'wrapper' => 'connection-config-' . $dataset_node_id . '-replace',
    ),
    );

    // connection-config
    $prefix = '<div id="connection-config-' . $dataset_node_id . '-replace">';
    if ($selected_type == 'none') {
      $prefix = '<div id="connection-config-' . $dataset_node_id . '-replace" style="display:none;">';
    }
    $form[$dataset_form_id][MICA_CONNECTION_CONFIG]= array(
      '#title' => t('Configuration'),
      '#type' => 'fieldset',
      '#prefix' => $prefix,
      '#suffix' => '</div>',
    );
    // todo ask MicaDatasetConnectionInterface
    if ($selected_type == 'opal') {
      $opal_url = _mica_datasets_node_field_values($node, 'mica_opal');
      if (!empty($opal_url)) {
        $form[$dataset_form_id][MICA_CONNECTION_CONFIG]['opal-url'] = array (
        '#type' => 'item',
        '#title' => t('Opal server'),
        '#markup' => !empty($opal_url) ? '<a href="' . $opal_url[0]['url'] . '">' . $opal_url[0]['url'] . '</a></div>' : '',
        );
      }
      else {
        $form[$dataset_form_id][MICA_CONNECTION_CONFIG]['opal-url'] = array (
          '#title' => t('Opal server'),
          '#type' => 'textfield',
        );
      }
      $form[$dataset_form_id][MICA_CONNECTION_CONFIG]['datasource'] = array (
        '#title' => t('Datasource'),
        '#type' => 'textfield',
      );
      $form[$dataset_form_id][MICA_CONNECTION_CONFIG]['table'] = array (
        '#title' => t('Table'),
        '#type' => 'textfield',
      );
    }

    $form[$dataset_form_id]['remove-' . $dataset_form_id] = array(
      '#type' => 'submit',
      '#value' => t('Remove Dataset'),
      '#ajax' => array(
        'path' => 'mica/ajax/dataset/' . $dataset_node_id . '/' . $node->nid . '/delete',
        'wrapper' => 'dataset-connectors',
    ),
    );
  }

  // dataset list
  $datasets_options = _mica_datasets_datasets_options($node);
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

  $form[MICA_STUDY_ID] = array(
    '#type' => 'hidden', 
    '#value' => $node->nid,
  );

  if (!empty($dataset_node_ids)) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
      '#attributes' => array('style' => array('display:block;')),
    );
  }

  return $form;
}

function _mica_datasets_datasets_options($node)  {
  $rval = array();
  $dataset_node_ids = array();
  foreach (_mica_datasets_node_field_values($node, 'mica_dataset') as $dataset_node_id_value) {
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

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for editing connection form.
 */
function mica_dataset_edit_ajax_form_callback($dataset_node, $node) {
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);
  return $form[MICA_DATASET_PREFIX . $dataset_node->nid][MICA_CONNECTION_CONFIG];
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for deleting a dataset.
 */
function mica_dataset_delete_ajax_form_callback($dataset_node, $node) {
  list($form, $form_state) = ajax_get_form();

  // update node referenced by the form_state
  $node = $form_state['build_info']['args'][0];
  foreach ($node->mica_dataset[$node->language] as $key => $value) {
    if ($value['nid'] == $dataset_node->nid) {
      unset($node->mica_dataset[$node->language][$key]);
      break;
    }
  }
  node_save($node);

  drupal_process_form($form['#form_id'], $form, $form_state);
  debug($form);
  
  return $form;
}

function mica_datasets_edit_form_validate($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (strpos($key,MICA_DATASET_PREFIX) !== FALSE) {
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

function mica_datasets_edit_form_submit($form, &$form_state) {

  // only submit will result in actual submission, all others rebuild.
  switch ($form_state['triggering_element']['#value']) {
    case t('Save'): // Submit: We're done.
      drupal_set_message(t('Your values have been submitted.'));
      return;
    case t('Add Dataset'):
      // update node referenced by the form_state
      $node = $form_state['build_info']['args'][0];
      $node->mica_dataset[$node->language][] = array('nid' => $form_state['values']['datasets']);
      node_save($node);
      break;
  }

  // anything else will cause rebuild of the form and present it again.
  $form_state['rebuild'] = TRUE;
}



