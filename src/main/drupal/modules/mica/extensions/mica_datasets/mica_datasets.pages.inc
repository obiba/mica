<?php

/**
 * @file
 * Mica Datasets pages.
 */

include_once(drupal_get_path('module', 'mica_connector') . '/mica_connector.connection.form.inc');


/**
 * Display form for linking datsets to a given study.
 */
function mica_datasets_study_datasets_edit_page($node) {
  drupal_set_title(t('!title -- Datasets', array('!title' => check_plain($node->title))));
  if (!property_exists($node, 'mica_dataset')) {
    drupal_set_message(t('dataset content type is broken, missing field: mica_dataset'), 'error');
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
  drupal_set_title(t('!title -- Studies', array('!title' => check_plain($node->title))));
  return drupal_get_form('mica_datasets_dataset_studies_form', $node);
}

/**
 * Display form for fetching variables for a given dataset.
 */
function mica_datasets_dataset_variables_edit_page($node) {
  drupal_set_title(t('!title -- Variables', array('!title' => check_plain($node->title))));
  return drupal_get_form('mica_datasets_dataset_variables_form', $node);
}

function mica_datasets_dataset_variables_form_submit($form, &$form_state) {

  // Save source and import.
  $source = feeds_source($form['#importer_id']);
  $source->addConfig($form_state['values']['feeds']);

  $fetcher_config = $source->getConfigFor($source->importer->fetcher);
  $fetcher_config['mica_connector'] = $form['#mica_connector_id'];
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
  $mica_connectors = mica_connector_query_multiple($node->nid, TRUE);

  if (!empty($mica_connectors)) {
    $connector_id = $mica_connectors[0]->id;
    $importer_id = $mica_connectors[0]->getImporterId();
  }
  else {
    form_set_error('', t('This dataset is not linked to a study or no external connection has been set.'));
    return NULL;
  }

  $source = feeds_source($importer_id);
  $fetcher_config = $source->getConfigFor($source->importer->fetcher);
  $fetcher_config['mica_connector'] = $connector_id;
  $source->setConfigFor($source->importer->fetcher, $fetcher_config);

  //following code is from feeds.pages.inc
  $form = array();
  $form['#importer_id'] = $importer_id;
  $form['#mica_connector_id'] = $connector_id;

  // @todo Move this into fetcher?
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['source_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status'),
    '#tree' => TRUE,
    '#value' => _mica_datasets_feeds_source_status($source),
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
function _mica_datasets_feeds_source_status($source) {
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

  $dataset_node = _mica_connector_get_node_form_arg($form_state);

  $study_node_ids = _mica_connector_get_study_ids($dataset_node->nid);

  $form = _mica_connector_form();

  // study list
  $studies_options = _mica_connector_studies_options($study_node_ids);
  if (!empty($studies_options)) {
    $form['add-study'] = array(
      '#type' => 'item',
      '#description' => t('Select the studies that are part of the dataset.'),
    );
    $form['add-study']['studies'] = array(
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
  foreach ($study_node_ids as $study_node) {
    _mica_connector_add_connection_option($options, $dataset_node, $study_node, $dataset_node);
  }

  _mica_connector_add_table_form($form, t('Study'), t('No studies found'), $options);

  return $form;
}

/**
 * Submit the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_dataset_studies_form_submit($form, &$form_state) {
  _mica_connector_connectors_form_submit($form, $form_state);
}


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

  $study_node = _mica_connector_get_node_form_arg($form_state);

  $dataset_node_ids = _mica_connector_get_dataset_ids($study_node->nid);

  $form = _mica_connector_form();

  // dataset list
  $datasets_options = _mica_connector_datasets_options($study_node);
  if (!empty($datasets_options)) {
    $form['add-dataset'] = array(
      '#type' => 'item',
      '#description' => t('Select the datasets in which the study is involved.'),
    );
    $form['add-dataset']['datasets'] = array(
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
  foreach ($dataset_node_ids as $dataset_node) {
    _mica_connector_add_connection_option($options, $dataset_node, $study_node, $study_node);
  }

  _mica_connector_add_table_form($form, 'Dataset', 'No datasets found', $options);

  return $form;
}

/**
 * Submit the study datasets form.
 * @param $form
 * @param $form_state
 */
function mica_datasets_study_datasets_form_submit($form, &$form_state) {
  _mica_connector_connectors_form_submit($form, $form_state);
}

/**
 * Replacement of the default ajax_form_callback: has study and dataset node as argument for editing connection form.
 */
function mica_dataset_edit_ajax_form_callback($dataset_node, $study_node) {
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);
  return $form[MICA_CONNECTION_CONFIG];
}

function mica_datasets_variables_autocomplete($dataset_nid, $string) {
  $variables = array();
  foreach (mica_dataset_dataset_variables($dataset_nid) as $variable) {
    if (strpos(drupal_strtolower($variable->title), $string) === 0 || $string === "*") {
      $variables[$variable->title] = $variable->title;
    }
  }
  print drupal_json_encode($variables);
  exit;
}