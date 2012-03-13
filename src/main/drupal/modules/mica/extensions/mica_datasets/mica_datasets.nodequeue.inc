<?php


/**
 * @file
 * Mica Datasets nodequeue
 */

define('MICA_DATASET_QUEUE', 'mica_dataset_variable_queue');


function _mica_datasets_create_queue($dataset) {
  $wrapper = entity_metadata_wrapper('node', $dataset);

  $machine_name = 'dataset_' . preg_replace('/[^a-z0-9-]+/', '_', strtolower($wrapper->title->value()));
  $i = 1;
  $machine_name_exists = nodequeue_machine_name_exists($machine_name);
  while ($machine_name_exists) {
    $machine_name = $machine_name . '_' . $i++;
    $machine_name_exists = nodequeue_machine_name_exists($machine_name);
  }

  $manipulate_all_queues = user_roles(FALSE, 'manipulate all queues');
  $manipulate_queues = user_roles(FALSE, 'manipulate queues');
  $roles = $manipulate_all_queues + $manipulate_queues;

  $queue = new nodequeue_queue('nodequeue');
  $queue->new = TRUE;
  $queue->title = $wrapper->title->value();
  $queue->name = $machine_name;
  $queue->size = 0; // no limit
  $queue->show_in_links = 0;
  $queue->show_in_tab = 1;
  $queue->show_in_ui = 1;
  $queue->i18n = 0;
  $queue->reverse = 0;
  $queue->reference = 0;
  $queue->roles = array_keys($roles);
  $queue->types = array('variable');

  nodequeue_api_queue_form_submit($queue, $form_state);
  nodequeue_save($queue);
  nodequeue_api_queue_form_submit_finish($queue, $form_state);

  _mica_datasets_set_dataset_queue($dataset->nid, $queue->name);
}

function _mica_datasets_update_queue($dataset) {
  $wrapper = entity_metadata_wrapper('node', $dataset);
  $queue = _mica_datasets_get_dataset_queue($dataset->nid);
  $queue->title = $wrapper->title->value();
  nodequeue_api_queue_form_submit($queue, $form_state);
  nodequeue_save($queue);
  nodequeue_api_queue_form_submit_finish($queue, $form_state);
}

function _mica_datasets_delete_queue($dataset) {
  $queue = _mica_datasets_get_dataset_queue($dataset->nid);
  nodequeue_delete($queue->qid);
  _mica_datasets_set_dataset_queue($dataset->nid, NULL);
}

function _mica_datasets_set_dataset_queue($dataset_id, $nodequeue_name) {
  $queues = variable_get(MICA_DATASET_QUEUE, array());
  if (empty($nodequeue_name)) {
    unset($queues[$dataset_id]);
  } else {
    $queues[$dataset_id] = $nodequeue_name;
  }
  variable_set(MICA_DATASET_QUEUE, $queues);
}

function _mica_datasets_get_dataset_queue($dataset_id) {
  $queues = variable_get(MICA_DATASET_QUEUE, array());
  if (isset($queues[$dataset_id])) {
    return nodequeue_load_queue_by_name($queues[$dataset_id]);
  }
  return NULL;
}

function _mica_datasets_add_variable_to_queue($variable) {
  $wrapper = entity_metadata_wrapper('node', $variable);
  $dataset_id = $wrapper->field_dataset->nid->value();
  $queue = _mica_datasets_get_dataset_queue($dataset_id);
  $subqueues = nodequeue_load_subqueues_by_queue($queue->qid);
  $id = nodequeue_get_content_id($queue, $variable);
  nodequeue_subqueue_add($queue, array_pop($subqueues), $id);
}