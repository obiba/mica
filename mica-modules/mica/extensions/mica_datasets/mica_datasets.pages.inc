<?php

/**
 * @file
 * Mica Datasets pages.
 */

/**
* Display form for creating dataset entities for a given study.
*/
function mica_datasets_edit_page($node) {
  drupal_set_title(t('Connections to Datasets of !title', array('!title' => $node->title)));

  $field = $node->mica_dataset;
  //debug($field);
  $output = '';
  if ($field) {
    $dataset_nodes = array();
    foreach ($field[$node->language] as $value) {
      $dataset_node = node_load($value['nid']);
      $dataset_nodes[] = $dataset_node;
    }
    $output = drupal_get_form('mica_datasets_edit_form', $node, $dataset_nodes);
    //debug($output);    
  }
  else {
    $output =  '<div>' . t('No dataset for this study.') . ' ';
    $output =  $output . t('You can') . ' <a href="?q=node/' . $node->nid . '/edit">' . t('join the study to some datasets'). '</a>.</div>';
  }

  return $output;
}

function mica_datasets_edit_form($form, &$form_state, $node, $dataset_nodes) {
  
  $form = array();

  $connection_types = array(
    'none' => t('-none-'), 
    'opal' => t('Opal'), // todo get list
  );

  foreach ($dataset_nodes as $dataset_node) {
    $selected_type = isset($form_state['values']['dataset-' . $dataset_node->nid]['connection-type']) ? $form_state['values']['dataset-' . $dataset_node->nid]['connection-type'] : key($connection_types);

    $form['dataset-' . $dataset_node->nid] = array(
      '#type' => 'fieldset',
      '#title' => $dataset_node->title,
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );
    $form['dataset-' . $dataset_node->nid]['connection-type']= array(
      '#type' => 'select', 
      '#title' => t('Connection'), 
      '#options' => $connection_types,
      '#description' => t('Select which type of connection is to be used to retrieve variables and data from the study to contribute to the dataset.'),
      '#ajax' => array(
        'path' => 'mica/ajax/dataset/' . $node->nid . '/' . $dataset_node->nid,
        'wrapper' => 'connection-config-' . $dataset_node->nid . '-replace',
    ),
    );
    $form['dataset-' . $dataset_node->nid]['connection-config']= array(
      '#title' => 'Table reference',
      '#type' => 'textfield',
      '#default_value' => '',
      '#prefix' => '<div id="connection-config-' . $dataset_node->nid . '-replace">',
      '#suffix' => '</div>',
    );
    watchdog('mica_datasets', 'connection-type-' . $dataset_node->nid . '=' . $selected_type);
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
* Replacement of the default ajax_form_callback
*/
function mica_dataset_edit_ajax_form_callback($node, $dataset_node) {
  //watchdog('mica_datasets', 'mica_dataset_edit_ajax_form_callback');
  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  //debug($form_state['values']['dataset-' . $dataset_node->nid]['connection-config']);
  //debug($form['dataset-' . $dataset_node->nid]['connection-config']);
  return $form['dataset-' . $dataset_node->nid]['connection-config'];
}

function mica_datasets_edit_form_submit($form, &$form_state) {
}
