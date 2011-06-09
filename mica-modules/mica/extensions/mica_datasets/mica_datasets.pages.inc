<?php

/**
 * @file
 * Mica Datasets pages.
 */

include_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'mica_datasets') .  '/includes/connection_form.inc');

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
  return drupal_get_form('mica_datasets_dataset_variables_form');
}

function mica_datasets_dataset_variables_form_submit($form, &$form_state) {
  debug('submit');
}

function mica_datasets_dataset_variables_form($form, &$form_state) {
 /* $_importer_id="OPAL_IMPORTER_ID_TEMPORARY";
  
  $source = feeds_source($_importer_id, empty($form['nid']['#value']) ? 0 : $form['nid']['#value']);

  $form = array();
  $form['#importer_id'] = $_importer_id;
  // @todo Move this into fetcher?
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['source_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status'),
    '#tree' => TRUE,
    '#value' => feeds_source_status($source),
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
  return $form;*/
}


/**
 * Display form for submitting queries.
 */
function mica_datasets_dataset_query_page($node) {
  drupal_set_title(t('!title -- Query', array('!title' => $node->title)));
  return 'TODO';
  //return drupal_get_form('example_form', $node);
  /*$header =
  // Simple row
  array(
  'Header 1', 'Header 2', 'Header 3'
  );

  $rows = array(
  // Simple row
  array(
  'Cell 1', 'Cell 2', 'Cell 3'
  ),
  // Row with attributes on the row and some of its cells.
  array(
  'data' => array('Cell 1', array('data' => 'Cell 2', 'colspan' => 2)),
  'class' => array('funky')
  ),
  array(
  'data' => array(
  array('data' => 'Group'),
  array('data' => array(
  '#type' => 'select',
  '#options' => array(
  'and' => t('AND'),
  'or' => t('OR'),
  ),
  )),
  ),
  ),
  );

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  return $output;*/
}

/*function example_form($form, &$form_state){

$rows = array();
$rows[] = array(1, 'A', 'a', 1);
$rows[] = array(2, 'B', 'b', 1);
$rows[] = array(2, 'C', 'c', 1);

foreach ($rows as $row) {
//create a partial table row containing the data from the table
$data = array(
$row[1],
$row[2]
);

//add our static "row" data into a form value
$form['rows'][$row[0]]['data']=array(
'#type' => 'value',
'#value' => $data
);

//now create the weight form element.
//NOTE how we add the id into the element key
$form['rows'][$row[0]]['weight-'.$row[0]]=array(
'#type'=>'textfield',
'#size'=>5,
'#default_value'=>$row[3],
//add a specific class in here - we need this later
'#attributes' => array('class'=>'weight'),
);
}

//Don't forget the submit button
$form['submit']=array(
'#type'=>'submit',
'#value'=>t('Save changes'),
);

return $form;
}*/

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
  $node = _mica_datasets_get_node_form_arg($form_state);
  if ($node->type != 'study') {
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
