<?php

/**
 * Form constructor for the node deletion confirmation form.
 *
 * @see node_delete_confirm_submit()
 */
function _mica_datasets_node_delete_confirm($form, &$form_state, $node) {
  if ($node->type === 'dataset') {
    $form['#node'] = $node;
    // Always provide entity id in the same form key as in the entity edit form.
    $form['nid'] = array('#type' => 'value', '#value' => $node->nid);
    return confirm_form($form,
      t('Are you sure you want to delete %title?', array('%title' => $node->title)),
      'node/' . $node->nid,
      t('It will also delete all its variables, queries and study connectors.')
      . '<br />' . t('This action cannot be undone.') . '<br /><br />',
      t('Delete'),
      t('Cancel')
    );
  }
  module_load_include('inc', 'node', 'node.pages');
  return node_delete_confirm($form, $form_state, $node);
}

/**
 * Executes node deletion.
 *
 * @see _mica_datasets_node_delete_confirm()
 */
function _mica_datasets_node_delete_confirm_submit($form, &$form_state) {
  if ($form['#node']->type === 'dataset') {
    if ($form_state['values']['confirm']) {
      $batch = array(
        'operations' => _mica_datasets_prepare_delete_dataset_batch_operations($form_state['values']['nid']),
        'finished' => '_mica_datasets_delete_dataset_batch_finished',
        'file' => drupal_get_path('module', 'mica_datasets') . '/mica_datasets.delete_dataset_batch.inc',
      );
      batch_set($batch);
    }
    else {
      $form_state['redirect'] = 'node/' . $form_state['values']['nid'];
    }
  }
  else {
    module_load_include('inc', 'node', 'node.pages');
    node_delete_confirm_submit($form, $form_state);
  }
}

function _mica_datasets_prepare_delete_dataset_batch_operations($dataset_nid) {

  $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);

  $operations = array();
  foreach ($dataset_wrapper->field_dataset_variables->getIterator() as $variable_wrapper) {
    $operations[] = array('_mica_datasets_batch_delete_dataset_delete_variable', array($variable_wrapper));
  }

  foreach ($dataset_wrapper->field_dataset_studies->getIterator() as $study_wrapper) {
    $operations[] = array(
      '_mica_datasets_batch_delete_dataset_delete_study_connector',
      array($dataset_nid, $study_wrapper->nid->value())
    );
  }

  $operations[] = array('_mica_datasets_batch_delete_dataset_delete_queries', array($dataset_nid));

  $operations[] = array('_mica_datasets_batch_delete_dataset_delete_node', array($dataset_nid));

  return $operations;
}

function _mica_datasets_delete_dataset_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Dataset successfully deleted (%nb variables deleted).',
      array('%nb' => $results['variable_deleted'])));
    drupal_goto('/datasets');
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    drupal_set_message($message, 'error');
  }
}

function _mica_datasets_batch_delete_dataset_delete_queries($dataset_nid, &$context) {
  $context['message'] = t('Delete dataset queries');
  $queries = MicaDatasetQueryManager::getPersistedQueries($dataset_nid);
  if (!empty($queries)) {
    foreach ($queries as $query) {
      watchdog('mica', 'Delete query %nid', array('%nid' => $query->id), WATCHDOG_DEBUG);
      mica_query_delete_query($query->id);
    }
  }
  MicaDatasetQueryManager::deleteQueries($dataset_nid);
}

function _mica_datasets_batch_delete_dataset_delete_variable($variable_wrapper, &$context) {
  watchdog('mica', 'Delete variable %variable', array('%variable' => $variable_wrapper->title->value()), WATCHDOG_DEBUG);
  $context['message'] = t('Delete variable %variable', array('%variable' => $variable_wrapper->title->value()));
  if (empty($context['results']) || !isset($context['results']['variable_deleted'])) {
    $context['results']['variable_deleted'] = 0;
  }
  $variable_wrapper->delete();
  $context['results']['variable_deleted']++;
}

function _mica_datasets_batch_delete_dataset_delete_study_connector($dataset_nid, $study_nid, &$context) {
  $context['message'] = t('Delete study connectors');
  $connector = mica_connector_query($dataset_nid, $study_nid);
  if ($connector) {
    $connector->delete();
  }
}

function _mica_datasets_batch_delete_dataset_delete_node($dataset_nid, &$context) {
  $context['message'] = t('Delete dataset node');
  node_delete($dataset_nid);
}