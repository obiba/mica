<?php

/**
 * @file
 * Mica Datasets pages.
 */

include_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'mica_datasets') . '/includes/connection_form.inc');

function mica_datasets_dataset_page($dataset_node) {
  drupal_goto('node/' . $dataset_node->nid . '/queries');
}

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

function mica_datasets_dataset_connection_modal_page($js = NULL, $connection_entity, $dataset_node, $study_node) {
  if ($js) {
    $title = t('!dataset -- !study', array(
      '!dataset' => $dataset_node->title, 
      '!study' => $study_node->title));

    mica_core_modal_form_render($title, 'mica_datasets_dataset_connection_form', $connection_entity, $dataset_node, $study_node);
  }
  else {
    // fallback to plain page
    return mica_datasets_dataset_connection_page($connection_entity, $dataset_node, $study_node);
  }
}

/**
 * Display form from CRUD a dataset connection entity.
 * @param $connection_id
 * @param $dataset_node
 * @param $study_node
 */
function mica_datasets_dataset_connection_page($connection_entity, $dataset_node, $study_node) {
  drupal_set_title(t('!dataset -- !study', array(
      '!dataset' => $dataset_node->title, 
      '!study' => $study_node->title)));

  return drupal_get_form('mica_datasets_dataset_connection_form', $connection_entity, $dataset_node, $study_node);
}

/**
 * Display form for fetching variables for a given dataset.
 */
function mica_datasets_dataset_variables_edit_page($node) {
  drupal_set_title(t('!title -- Variables', array('!title' => $node->title)));
  return drupal_get_form('mica_datasets_dataset_variables_form', $node);
}

function mica_datasets_dataset_variables_form_submit($form, &$form_state) {

  // Save source and import.
  $source = feeds_source($form['#importer_id']);
  $source->addConfig($form_state['values']['feeds']);

  $fetcher_config = $source->getConfigFor($source->importer->fetcher);
  $fetcher_config['mica_dataset_connector'] = $form['#mica_dataset_connector_id'];
  $source->setConfigFor($source->importer->fetcher, $fetcher_config);
  $source->save();

  // Refresh feed if import on create is selected.
  if ($source->importer->config['import_on_create']) {
    $source->startImport();
  }

  // Add to schedule, make sure importer is scheduled, too.
  $source->schedule();
  $source->importer->schedule();
}

/**
 * ADJUST FROM feeds.pages.inc
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @param unknown_type $node
 */
//TODO maybe I can call directly form feeds in feeds.pages.inc but failed...
function mica_datasets_dataset_variables_form($form, &$form_state, $node) {
  $mica_dataset_connectors = mica_dataset_connector_query_multiple($node->nid, TRUE);

  if (!empty($mica_dataset_connectors)) {
    $connector_id = $mica_dataset_connectors[0]->id;
    $importer_id = $mica_dataset_connectors[0]->getImporterId();
  } else {
    form_set_error('',t('This dataset is not linked to a study or no external connection has been set.'));
    return;
  }
   
  $source = feeds_source($importer_id);
  $fetcher_config = $source->getConfigFor($source->importer->fetcher);
  $fetcher_config['mica_dataset_connector'] = $connector_id;
  $source->setConfigFor($source->importer->fetcher, $fetcher_config);

  //following code is from feeds.pages.inc
  $form = array();
  $form['#importer_id'] = $importer_id;
  $form['#mica_dataset_connector_id'] = $connector_id;

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
 * Validation handler for node forms and feeds_import_form().
 */
function mica_datasets_dataset_variables_form_validate($form, &$form_state) {
  // @todo This may be a problem here, as we don't have a feed_nid at this point.
  feeds_source($form['#importer_id'])->configFormValidate($form_state['values']['feeds']);
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

//
// mica_datasets_dataset_studies_form
//

/**
 * Build the dataset studies form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_dataset_studies_form($form, &$form_state) {
  mica_core_modal_prepare(array(
    array(
      'name' => 'edit-style',
      'width' => 700,
      'height' => 650,
    ),
  ));

  $dataset_node = _mica_datasets_get_node_form_arg($form_state);
  $dataset_node_id = $dataset_node->nid;

  $study_node_ids = _mica_datasets_get_study_ids($dataset_node->nid);

  $form = _mica_datasets_connectors_form();

  // study list
  $studies_options = _mica_datasets_studies_options($study_node_ids);
  if (!empty($studies_options)) {
    $form['add-study'] = array(
      '#type' => 'item',
      '#description' => t('Select the studies that are part of the dataset.'),
    );
    $form['add-study']['studies']= array(
      '#type' => 'select', 
      '#title' => t('Studies'), 
      '#options' => $studies_options,
    );
    $form['add-study']['add'] = array(
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
  mica_core_modal_prepare(array(
    array(
      'name' => 'edit-style',
      'width' => 700,
      'height' => 650,
    ),
  ));
  
  $study_node = _mica_datasets_get_node_form_arg($form_state);
  $study_node_id = $study_node->nid;

  $dataset_node_ids = _mica_datasets_get_dataset_ids($study_node->nid);

  $form = _mica_datasets_connectors_form();

  // dataset list
  $datasets_options = _mica_datasets_datasets_options($study_node);
  if (!empty($datasets_options)) {
    $form['add-dataset'] = array(
      '#type' => 'item',
      '#description' => t('Select the datasets in which the study is involved.'),
    );
    $form['add-dataset']['datasets']= array(
      '#type' => 'select', 
      '#title' => t('Datasets'), 
      '#options' => $datasets_options,
    );
    $form['add-dataset']['add'] = array(
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

function mica_datasets_dataset_connection_form($form, &$form_state, $connection_entity, $dataset_node, $study_node) {
  $connector = $connection_entity ? $connection_entity : FALSE;

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
    '#title' => $dataset_node->title,
    '#href' => 'node/' . $dataset_node->nid . '/studies',
    '#attributes' => array('style' => 'margin:0 5px 0 5px;'),
  );

  $form['study-link'] = array(
    '#type' => 'link',
    '#title' => $study_node->title,
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

function mica_datasets_dataset_connection_form_validate($form, &$form_state) {
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  if ($connection_type != 'none') {
    $values = _mica_datasets_connection_config_values($form, $form_state);

    $form_errors = _mica_datasets_connection_options_validate($form, $values, $form_state, $connection_type);

    // display errors
    if (!empty($form_errors)) {
      foreach ($form_errors as $key => $msg) {
        form_set_error($key, $msg);
      }
    }
  }
}

function mica_datasets_dataset_connection_form_submit($form, &$form_state) {
  $connector = $form_state['build_info']['args'][0];
  $dataset_node = $form_state['build_info']['args'][1];
  $study_node = $form_state['build_info']['args'][2];
  $connection_type = $form_state['values'][MICA_CONNECTION_TYPE];

  switch ($form_state['triggering_element']['#value']) {
    case t('Save'):
      $options = _mica_datasets_connection_options_submit($form, $form_state, $connection_type);

      $values = array();

      if ($connector == 0) {
        $values['name'] = $dataset_node->title . ' -- ' . $study_node->title;
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
        $connector->description = $form_state['values']['description'];
        $connector->class = $connection_type;
        $connector->options = $options;
        $connector->enabled = $connection_type == 'none' ? FALSE : TRUE;

        if ($connector->save() === FALSE) {
          drupal_set_message(t('Unable to save connection: !name', array('!name' => $connector->name)), 'error');
        }
      }
      $form_state['complete'] = TRUE;
      break;
  }

  $form_state['redirect'] = 'node/' . $dataset_node->nid . '/studies';
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for editing connection form.
 */
function mica_dataset_edit_ajax_form_callback($dataset_node, $study_node) {
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);
  return $form[MICA_CONNECTION_CONFIG];
}