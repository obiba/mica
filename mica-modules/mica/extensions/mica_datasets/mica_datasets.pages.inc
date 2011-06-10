<?php

/**
 * @file
 * Mica Datasets pages.
 */

include_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'mica_datasets') .  '/includes/connection_form.inc');

/**
 * Display form for linking datsets to a given study.
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
 * Display form for linking studies to a given dataset.
 */
function mica_datasets_dataset_studies_edit_page($node) {
  drupal_set_title(t('!title -- Studies', array('!title' => $node->title)));
  return drupal_get_form('mica_datasets_dataset_studies_form', $node);
}

/**
 * Display form from CRUD a dataset connection entity.
 * @param $connection_id
 * @param $dataset_node
 * @param $study_node
 */
function mica_datasets_dataset_connection_page($connection_id, $dataset_node, $study_node) {
  drupal_set_title(t('!dataset -- !study', array(
      '!dataset' => $dataset_node->title, 
      '!study' => $study_node->title)));

  return drupal_get_form('mica_datasets_dataset_connection_form', $connection_id, $dataset_node, $study_node);
}

/**
 * Display form for fetching variables for a given dataset.
 */
function mica_datasets_dataset_variables_edit_page($node) {
  drupal_set_title(t('!title -- Participant Variables', array('!title' => $node->title)));
  return drupal_get_form('mica_datasets_dataset_variables_form', $node);
}

function mica_datasets_dataset_variables_form_submit($form, &$form_state) {
  debug('submit');
}

/**
 * ADJUST FROM feeds.pages.inc
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @param unknown_type $node
 */
function mica_datasets_dataset_variables_form($form, &$form_state, $node) {
  $_importer_id='opal_participant_variables';

  $source = feeds_source($_importer_id, empty($form['nid']['#value']) ? 0 : $form['nid']['#value']);

  // nothing for the moment
  $mica_dataset_connector = mica_dataset_connector_load($node->nid);

  // mandatory to have FeedsHTTPSFetcher ?
  $source->setConfig(array('FeedsHTTPSFetcher' => array('source'=>$mica_dataset_connector->id)));

  $form = array();
  $form['#importer_id'] = $_importer_id;
  // @todo Move this into fetcher?
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['source_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status'),
    '#tree' => TRUE,
    '#value' => _feeds_source_status($source),
  );
  $form['feeds'] = array(
  '#type' => 'fieldset',
  '#title' => t('Import'),
  '#tree' => TRUE,
  );
  $form['feeds'] += $source->configForm($form_state);
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Update variables'),
  );
  $progress = $source->progressImporting();
  if ($progress !== FEEDS_BATCH_COMPLETE) {
    $form['submit']['#disabled'] = TRUE;
    $form['submit']['#value'] =
    t('Importing (@progress %)', array('@progress' => number_format(100 * $progress, 0)));
  }
  return $form;
}

/**
 * TODO COPY FROM feeds.page.inc, call of feeds_source_status($source) failed...
 * Renders a status display for a source.
 */
function _feeds_source_status($source) {
  $progress_importing = $source->progressImporting();
  $v = array();
  if ($progress_importing != FEEDS_BATCH_COMPLETE) {
    $v['progress_importing'] = $progress_importing;
  }
  $progress_clearing = $source->progressClearing();
  if ($progress_clearing != FEEDS_BATCH_COMPLETE) {
    $v['progress_clearing'] = $progress_clearing;
  }
  $v['imported'] = $source->imported;
  $v['count'] = $source->itemCount();
  if (!empty($v)) {
    return theme('feeds_source_status', $v);
  }
}


/**
 * Display form for submitting queries.
 */
function mica_datasets_dataset_query_page($node) {
  drupal_set_title(t('!title -- Query', array('!title' => $node->title)));
  return 'TODO';
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

  $form = _mica_datasets_connectors_form();

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

  // build the table options
  $options = array();
  foreach ($study_node_ids as $study_node_id => $study_node) {
    _mica_datasets_add_connection_option($options, $dataset_node, $study_node, $dataset_node);
  }

  _mica_datasets_add_table_form($form, 'Study', 'No studies found', $options);


  return $form;
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
  //module_load_include('inc', 'mica_datasets', 'includes/connection_form');
  $study_node = _mica_datasets_get_node_form_arg($form_state);
  $study_node_id = $study_node->nid;

  $dataset_node_ids = _mica_datasets_get_dataset_ids($study_node->nid);

  $form = _mica_datasets_connectors_form();

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

  // build the table options
  $options = array();
  foreach ($dataset_node_ids as $dataset_node_id => $dataset_node) {
    _mica_datasets_add_connection_option($options, $dataset_node, $study_node, $study_node);
  }

  _mica_datasets_add_table_form($form, 'Dataset', 'No datasets found', $options);

  return $form;
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
// mica_datasets_dataset_connection_form
//

function mica_datasets_dataset_connection_form($form, &$form_state, $connection_id, $dataset_node, $study_node) {
  $connector = $connection_id != 0 ? mica_dataset_connector_load($connection_id) : FALSE;

  $form = _mica_datasets_connectors_form();

  $connection_types = _mica_datasets_connection_types();
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
  $form[MICA_CONNECTION_TYPE]= array(
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
  $form[MICA_CONNECTION_CONFIG]= array(
    '#title' => t('Configuration'),
    '#type' => 'fieldset',
    '#prefix' => $prefix,
    '#suffix' => '</div>',
  );

  // connection-config implementation
  if ($selected_type != 'none') {
    $form_items = _mica_datasets_add_connection_config_implementation_form($study_node, $selected_type);
    foreach ($form_items as $key => &$form_item) {
      $form[MICA_CONNECTION_CONFIG][$key] = $form_item;
      if ($connector) {
        $options = $connector->options;
        if (array_key_exists($key, $options)) {
          $form[MICA_CONNECTION_CONFIG][$key]['#default_value'] = $options[$key];
        }
      }
    }
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['dataset-link'] = array(
    '#type' => 'link',
    '#title' => $dataset_node->title,
    '#href' => 'node/' . $dataset_node->nid . '/edit-studies',
    '#attributes' => array('style' => 'margin:0 5px 0 5px;'),
  );

  $form['study-link'] = array(
    '#type' => 'link',
    '#title' => $study_node->title,
    '#href' => 'node/' . $study_node->nid . '/edit-datasets',
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

function mica_datasets_dataset_connection_form_validate($form, &$form_state) {
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  if ($connection_type != 'none') {
    $values = _mica_datasets_connection_config_values($form, $form_state);

    // todo make it validate by MicaDatasetConnectionInterface implementation
    $form_errors = array();
    if ($connection_type == 'MicaDatasetOpalConnection') {
      $form_errors = _mica_datasets_opal_connector_form_validate($form, $values, $form_state);
    }

    // display errors
    if (!empty($form_errors)) {
      foreach ($form_errors as $key => $msg) {
        form_set_error($key, $msg);
      }
    }
  }
}

function mica_datasets_dataset_connection_form_submit($form, &$form_state) {
  $connector_id = $form_state['build_info']['args'][0];
  $dataset_node = $form_state['build_info']['args'][1];
  $study_node = $form_state['build_info']['args'][2];
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  switch ($form_state['triggering_element']['#value']) {
    case t('Delete'):
      _mica_datasets_dataset_connection_delete($study_node, $dataset_node->nid);
      break;
    case t('Save'):
      $options = _mica_datasets_connection_config_values($form, $form_state);
      // todo make it submit by MicaDatasetConnectionInterface implementation
      if ($connection_type == 'MicaDatasetOpalConnection') {
        $options = _mica_datasets_opal_connector_form_submit($form, $options, $form_state);
      }

      $values = array();

      if ($connector_id == 0) {
        $values['name'] = $dataset_node->title . ' -- ' . $study_node->title;
        $values['machine_name'] = strtolower(str_replace(array(' ','-',',','.',':',';','/'),'_', $values['name']));
        $values['description'] = $form_state['values']['description'];
        $values['dataset_id'] = $dataset_node->nid;
        $values['study_id'] = $study_node->nid;
        $values['class'] = $connection_type;
        $values['options'] = $options;
        $values['enabled'] = $connection_type == 'none' ? FALSE : TRUE;
        $values['module'] = 'mica_datasets';

        if (mica_dataset_connector_insert($values) === FALSE) {
          drupal_set_message(t('Unable to save connection: !name', array('!name' => $values['name'])), 'error');
        }
      }
      else {
        $connector = mica_dataset_connector_load($connector_id);
        $connector->description = $form_state['values']['description'];
        $connector->class = $connection_type;
        $connector->options = $options;
        $connector->enabled = $connection_type == 'none' ? FALSE : TRUE;

        if ($connector->save() === FALSE) {
          drupal_set_message(t('Unable to save connection: !name', array('!name' => $connector->name)), 'error');
        }
      }
      break;
  }

  $form_state['redirect'] = 'node/' . $dataset_node->nid . '/edit-studies';
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for editing connection form.
 */
function mica_dataset_edit_ajax_form_callback($dataset_node, $study_node) {
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);
  return $form[MICA_CONNECTION_CONFIG];
}