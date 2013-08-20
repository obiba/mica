<?php

/**
 * @file
 * Mica Datasets connection form.
 */

/**
 * @defgroup mica_datasets_form_constants Mica connector form constants
 * @{
 *           Constants used to build the Mica connector entity forms.
 */

define('MICA_STUDY_ID', 'study-id');
define('MICA_DATASET_ID', 'dataset-id');
define('MICA_CONNECTION_PREFIX', 'connection-');
define('MICA_CONNECTION_TYPE', 'connection-type');
define('MICA_CONNECTION_CONFIG', 'connection-config');

/**
 * @} End of "Mica connector form constants".
 */

//
// connection form functions
//

/**
 * Base form for connectors.
 */
function _mica_connector_form() {
  $form = array(
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'mica_connector') . '/css/mica_connector.css')
    ),
    '#attributes' => array('id' => 'dataset-connectors'),
  );
  return $form;
}

/**
 * Build a connection data structure.
 *
 * @param $dataset_node
 * @param $study_node
 * @param $parent_node
 */
function _mica_connector_connection_data(&$dataset_node, &$study_node, $parent_node) {
  // todo fetch the connector entity
  $child_node = $parent_node->nid == $dataset_node->nid ? $study_node : $dataset_node;

  $connector = mica_connector_query($dataset_node->nid, $study_node->nid);

  $row = array(
    'parent' => _mica_connector_connection_data_node($parent_node),
    'child' => _mica_connector_connection_data_node($child_node),
    'connector' => array(
      'id' => $connector ? $connector->id : 0,
      MICA_DATASET_ID => $dataset_node->nid,
      MICA_STUDY_ID => $study_node->nid,
      'type' => $connector ? _mica_connector_connection_type_name($connector->class) : t('-none-'),
      'description' => $connector ? $connector->description : '',
    ),
  );

  return $row;
}

/**
 * Extract usefull information from a node.
 *
 * @param $node
 */
function _mica_connector_connection_data_node(&$node) {
  $uri = entity_uri('node', $node);
  return array(
    'title' => $node->title,
    'id' => $node->nid,
    'type' => $node->type,
    'path' => $uri['path'],
  );
}

/**
 * Add a tableselect option.
 *
 * @param $options
 * @param $dataset_node
 * @param $study_node
 * @param $parent_node
 */
function _mica_connector_add_connection_option(array &$options, &$dataset_node, &$study_node, &$parent_node) {
  $data = _mica_connector_connection_data($dataset_node, $study_node, $parent_node);
  $href = 'node/' . $data['connector'][MICA_DATASET_ID] . '/study/' . $data['connector'][MICA_STUDY_ID]
    . '/connector/' . (($data['connector']['id'] != '0') ? ($data['connector']['id'] . '/edit') : 'add');

  $options[$data['child']['id']] = array(
    'child' => array(
      'data' => array(
        '#type' => 'link',
        '#title' => $data['child']['title'],
        '#href' => $data['child']['path'],
      )
    ),
    'connection-type' => $data['connector']['type'],
    'description' => $data['connector']['description'],
    'actions' => array(
      'data' => array(
        array(
          '#markup' => ctools_modal_text_button(
            t('Edit'), 'mica/nojs/' . $href, t('Edit study connection options'),
            'ctools-modal-edit-style'
          ),
        ),
      ),
    ),
    'row' => $data,
  );
}

/**
 * Add tableselect form with delete selected items button.
 *
 * @param $form
 * @param $header  first column header
 * @param $empty   text when list is empty
 * @param $options list of rows
 */
function _mica_connector_add_table_form(&$form, $header, $empty, array &$options) {
  $header = array(
    'child' => t('@header', array('@header' => $header)),
    'connection-type' => t('Connection Type'),
    'description' => t('Description'),
    'actions' => t('Operations'),
  );

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('@empty', array('@empty' => $empty)),
  );

  if (!empty($options)) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected items'),
    );
    $form['test'] = array(
      '#type' => 'submit',
      '#value' => t('Test connections'),
    );
  }
}

function _mica_connector_connectors_form_submit($form, &$form_state) {

  switch ($form_state['triggering_element']['#value']) {
    case t('Delete selected items'):
      foreach ($form_state['values']['table'] as $selection) {
        if ($selection != 0) {
          $row = $form['table']['#options'][$selection]['row'];
          // update node referenced by the form_state
          $node = _mica_connector_get_node_form_arg($form_state);
          if ($node->type !== 'study') {
            $node = node_load($row['connector'][MICA_STUDY_ID]);
          }
          _mica_connector_dataset_connection_delete($node, $row['connector'][MICA_DATASET_ID]);
        }
      }
      break;

    case t('Test connections'):
      _testConnections($form_state['build_info']['args'][0]->nid);
      break;

    case t('Add Dataset'):
      // update node referenced by the form_state
      $dataset_node = node_load($form_state['values']['datasets']);
      $study_node = $form_state['build_info']['args'][0];
      _mica_connector_add_study_to_dataset($study_node, $dataset_node);
      break;

    case t('Add Study'):
      // update selected node referenced with the one from the form_state
      $dataset_node = $form_state['build_info']['args'][0];
      $study_node = node_load($form_state['values']['studies']);
      _mica_connector_add_study_to_dataset($study_node, $dataset_node);
      break;
  }

  // anything else will cause rebuild of the form and present it again.
  $form_state['rebuild'] = TRUE;
}

function _mica_connector_add_study_to_dataset($study, $dataset) {
  $study_wrapper = entity_metadata_wrapper('node', $study);
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset);

  _mica_datasets_add_element_in_entity_list_wrapper($study_wrapper, $dataset_wrapper, 'mica_dataset');
  $study_wrapper->save();

  _mica_datasets_create_svas($study, $dataset);

  // No need to update the dataset since we have the corresponding node reference module
}

function _mica_connector_dataset_connection_delete(&$study_node, $dataset_node_id) {
  _mica_connector_remove_study_to_dataset($study_node, node_load($dataset_node_id));

  // todo delete connector entity too
  $connector = mica_connector_query($dataset_node_id, $study_node->nid);
  if ($connector) {
    $connector->delete();
  }
}

function _mica_connector_remove_study_to_dataset(&$study, &$dataset) {
  $study_wrapper = entity_metadata_wrapper('node', $study);
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset);

  _mica_datasets_remove_and_save_element_from_entity_list_wrapper($study_wrapper, $dataset_wrapper, 'mica_dataset');
  _mica_datasets_delete_svas($dataset_wrapper, $study->nid);
}

//
// utilities
//

function _mica_connector_connection_type_name($type) {
  if ($type == 'none') {
    return t('-none-');
  }
  $connection = mica_connector_get_connection_info($type);
  if (isset($connection) && array_key_exists('name', $connection)) {
    return $connection['name'];
  }
  return $type;
}

function _mica_connector_connection_types() {
  // todo get list of MicaDatasetConnectionInterface implementations
  $types = array(
    'none' => t('-none-'),
  );

  $connections = mica_connector_get_connection_info();
  if (isset($connections)) {
    foreach ($connections as $key => $connection) {
      $types[$key] = $connection['name'];
    }
  }

  return $types;
}

function _mica_connector_add_connection_config_implementation_form(&$study_node, $connection_type) {
  return _mica_connector_new_connector($connection_type)->configurationForm($study_node);
}

function _mica_connector_connection_options_validate(&$form, &$values, &$form_state, $connection_type) {
  return _mica_connector_new_connector($connection_type)->configurationFormValidate($form, $values, $form_state);
}

function _mica_connector_new_connector($connection_type) {
  return new MicaDatasetConnector(array('class' => $connection_type));
}

/**
 * Submit the options
 *
 * @param $form
 * @param $form_state
 * @param $connection_type
 */
function _mica_connector_connection_options_submit(&$form, &$form_state, $connection_type) {
  $options = _mica_connector_connection_config_values($form, $form_state);
  if ($connection_type === 'none') {
    return $options;
  }
  return _mica_connector_new_connector($connection_type)->configurationFormSubmit($form, $options, $form_state);
}

/**
 * Get the node provided provided as an argument to the form.
 *
 * @param  $form_state
 */
function _mica_connector_get_node_form_arg(&$form_state) {
  return $form_state['build_info']['args'][0];
}

/**
 * Get all nodes of dataset type, accessible and not already datasets of current study.
 *
 * @param study node $study_node
 */
function _mica_connector_datasets_options($study_node) {
  $rval = array();
  $dataset_node_ids = array();
  foreach (_mica_connector_node_field_values($study_node, 'mica_dataset') as $dataset_node_id_value) {
    $dataset_node_ids[] = $dataset_node_id_value['nid'];
  }

  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->addField('n', 'title');
  $q->condition('n.type', 'dataset');
  if (!empty($dataset_node_ids)) {
    $q->condition('n.nid', $dataset_node_ids, 'NOT IN');
  }
  $q->addTag('node_access');
  $q->orderBy('n.title');

  $result = $q->execute();

  while ($record = $result->fetchAssoc()) {
    $rval[$record['nid']] = $record['title'];
  }

  return $rval;
}

/**
 * Get all nodes of study type that are published, accessible
 * and are not already related to current dataset.
 *
 * @param $study_node_ids
 */
function _mica_connector_studies_options(&$study_node_ids) {
  $rval = array();

  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->addField('n', 'title');
  $q->condition('n.type', 'study');
  if (!empty($study_node_ids)) {
    $q->condition('n.nid', array_keys($study_node_ids), 'NOT IN');
  }
  $q->addTag('node_access');
  $q->orderBy('n.title');

  $result = $q->execute();

  while ($record = $result->fetchAssoc()) {
    $rval[$record['nid']] = $record['title'];
  }

  return $rval;
}

/**
 * Get all nodes of study type that accessible and are related to current dataset.
 *
 * @param $dataset_node_id
 */
function _mica_connector_get_study_ids($dataset_node_id) {
  $rval = array();

  // Get field information
  $field = field_info_field('mica_dataset');
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study')
    ->fieldCondition($field, 'nid', $dataset_node_id);
  $entities = $query->execute();

  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      // study is updatable
      if (node_access('update', $node)) {
        $rval[$node->nid] = $node;
      }
    }
  }

  return $rval;
}

/**
 * Get all nodes of dataset type that are published, accessible
 * and are related to current study.
 *
 * @param $study_node_id
 */
function _mica_connector_get_dataset_ids($study_node_id) {
  $rval = array();

  $q = db_select('field_data_mica_dataset', 'f');
  $q->addField('f', 'mica_dataset_nid');
  $q->condition('f.entity_id', $study_node_id);
  $q->condition('f.entity_type', 'node');
  $q->condition('f.bundle', 'study');
  $q->condition('f.deleted', 0);

  $result = $q->execute();

  while ($record = $result->fetchAssoc()) {
    $node = node_load($record['mica_dataset_nid']);
    // dataset is updatable
    if (node_access('view', $node)) {
      $rval[$record['mica_dataset_nid']] = $node;
    }
  }

  return $rval;
}

/**
 * Get the values for a node field.
 *
 * @param node $node
 * @param string $field_name
 */
function _mica_connector_node_field_values($node, $field_name) {
  $field = $node->$field_name;
  if ($field) {
    return $field[$node->language];
  }
  return array();
}

/**
 * Extract connection config specific values from form_state.
 *
 * @param $form
 * @param $form_state
 */
function _mica_connector_connection_config_values(&$form, &$form_state) {
  $values = array();
  foreach ($form_state['values'] as $key => $value) {
    if (array_key_exists($key, $form[MICA_CONNECTION_CONFIG])) {
      $values[$key] = $value;
    }
  }
  return $values;
}

function _testConnections($nid) {
  $mica_connectors = mica_connector_query_multiple($nid, TRUE);

  $errors = 0;
  foreach ($mica_connectors as $connector) {

    try {
      $connector->query(array());
    } catch (Exception $e) {
      $connector->displayError($e);
      $errors++;
    }
  }

  if ($errors < 1) {
    drupal_set_message(t('All connections are successful.'));
  }
}
