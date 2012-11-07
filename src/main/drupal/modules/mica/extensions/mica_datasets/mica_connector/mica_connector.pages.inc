<?php

/**
 * @file
 * Mica Connector pages.
 */

include_once('mica_connector.connection.form.inc');


function mica_connector_dataset_connection_modal_page($js = NULL, $connection_entity, $dataset_node, $study_node) {
  if ($js) {
    $title = t('!dataset -- !study', array(
      '!dataset' => $dataset_node->title,
      '!study' => $study_node->title
    ));

    mica_core_modal_form_render($title, 'mica_connector_dataset_connection_form', $connection_entity, $dataset_node, $study_node);
  }
  else {
    // fallback to plain page
    return mica_connector_dataset_connection_page($connection_entity, $dataset_node, $study_node);
  }
}

/**
 * Display form from CRUD a dataset connection entity.
 * @param $connection_id
 * @param $dataset_node
 * @param $study_node
 */
function mica_connector_dataset_connection_page($connection_entity, $dataset_node, $study_node) {
  drupal_set_title(t('!dataset -- !study', array(
    '!dataset' => check_plain($dataset_node->title),
    '!study' => check_plain($study_node->title)
  )));

  return drupal_get_form('mica_connector_dataset_connection_form', $connection_entity, $dataset_node, $study_node);
}

function mica_connector_dataset_connection_form($form, &$form_state, $connection_entity, $dataset_node, $study_node) {
  $connector = $connection_entity ? $connection_entity : FALSE;

  $form = _mica_connector_form();

  $connection_types = _mica_connector_connection_types();
  $selected_type = NULL;
  if (isset($form_state['values'][MICA_CONNECTION_TYPE])) {
    $selected_type = $form_state['values'][MICA_CONNECTION_TYPE];
  }
  elseif ($connector) {
    $selected_type = $connector->class;
  }
  else {
    $selected_type = key($connection_types);
  }

  // description
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $connector ? $connector->description : '',
    '#rows' => 3,
    '#description' => t('A description of the study\'s data contributing to the dataset.'),
  );

  // connection-type
  $form[MICA_CONNECTION_TYPE] = array(
    '#type' => 'select',
    '#title' => t('Connection Type'),
    '#options' => $connection_types,
    '#default_value' => $connector ? $connector->class : 'none',
    '#description' => t('Select which type of connection is to be used to retrieve variables and data from the study to contribute to the dataset.'),
    '#ajax' => array(
      'path' => 'mica/ajax/dataset/' . $dataset_node->nid . '/' . $study_node->nid . '/edit',
      'wrapper' => MICA_CONNECTION_CONFIG . '-replace',
    ),
  );

  // connection-config
  $prefix = '<div id="' . MICA_CONNECTION_CONFIG . '-replace">';
  if ($selected_type == 'none') {
    $prefix = '<div id="' . MICA_CONNECTION_CONFIG . '-replace" style="display:none;">';
  }
  $form[MICA_CONNECTION_CONFIG] = array(
    '#title' => t('Configuration'),
    '#type' => 'fieldset',
    '#prefix' => $prefix,
    '#suffix' => '</div>',
  );

  // connection-config implementation
  if ($selected_type != 'none') {
    $form_items = _mica_connector_add_connection_config_implementation_form($study_node, $selected_type);
    foreach ($form_items as $key => &$form_item) {
      $form[MICA_CONNECTION_CONFIG][$key] = $form_item;
      if ($connector) {
        $options = $connector->options;
        if ($options != NULL && array_key_exists($key, $options)) {
          $form[MICA_CONNECTION_CONFIG][$key]['#default_value'] = $options[$key];
        }
      }
    }
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['dataset-link'] = array(
    '#type' => 'link',
    '#title' => check_plain($dataset_node->title),
    '#href' => 'node/' . $dataset_node->nid . '/studies',
    '#attributes' => array('style' => 'margin:0 5px 0 5px;'),
  );

  $form['study-link'] = array(
    '#type' => 'link',
    '#title' => check_plain($study_node->title),
    '#href' => 'node/' . $study_node->nid . '/datasets',
    '#attributes' => array('style' => 'margin:0 5px 0 5px;'),
  );

  $form[MICA_DATASET_ID] = array(
    '#type' => 'hidden',
    '#value' => $dataset_node->nid,
  );

  $form[MICA_STUDY_ID] = array(
    '#type' => 'hidden',
    '#value' => $study_node->nid,
  );

  return $form;
}

function mica_connector_dataset_connection_form_validate($form, &$form_state) {
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  if ($connection_type != 'none') {
    $values = _mica_connector_connection_config_values($form, $form_state);

    $form_errors = _mica_connector_connection_options_validate($form, $values, $form_state, $connection_type);

    // display errors
    if (!empty($form_errors)) {
      foreach ($form_errors as $key => $msg) {
        form_set_error($key, check_plain($msg));
      }
    }
  }
}

function mica_connector_dataset_connection_form_submit($form, &$form_state) {
  $connector = $form_state['build_info']['args'][0];
  $dataset_node = $form_state['build_info']['args'][1];
  $study_node = $form_state['build_info']['args'][2];
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  switch ($form_state['triggering_element']['#value']) {
    case t('Save'):
      $options = _mica_connector_connection_options_submit($form, $form_state, $connection_type);

      $values = array();

      $class_name = empty($connector) ? '': get_class($connector);
      if (($class_name !== 'MicaDatasetConnector' && is_int($connector)) || ($class_name !== 'MicaDatasetConnector' && $connector == 0)) {
        $values['name'] = $dataset_node->title . ' -- ' . $study_node->title;
        $values['description'] = $form_state['values']['description'];
        $values['dataset_id'] = $dataset_node->nid;
        $values['study_id'] = $study_node->nid;
        $values['class'] = $connection_type;
        $values['options'] = $options;
        $values['enabled'] = $connection_type == 'none' ? FALSE : TRUE;
        $values['module'] = 'mica_datasets';

        if (mica_connector_insert($values) === FALSE) {
          drupal_set_message(check_plain(t('Unable to save connection: !name', array('!name' => check_plain($values['name'])))), 'error');
        }
      }
      else {
        $connector->description = $form_state['values']['description'];
        $connector->class = $connection_type;
        $connector->options = $options;
        $connector->enabled = $connection_type == 'none' ? FALSE : TRUE;

        if ($connector->save() === FALSE) {
          drupal_set_message(check_plain(t('Unable to save connection: !name', array('!name' => check_plain($connector->name)))), 'error');
        }
      }
      $form_state['complete'] = TRUE;
      break;
  }

  $form_state['redirect'] = 'node/' . $dataset_node->nid . '/studies';
}