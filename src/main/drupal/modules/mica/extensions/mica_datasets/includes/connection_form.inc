<?php

/**
 * @file
 * Mica Datasets connection form.
 */

/**
 * @defgroup mica_datasets_form_constants Mica datasets form constants
 * @{
 *           Constants used to build the Mica dataset entity forms.
 */

define('MICA_STUDY_ID', 'study-id');
define('MICA_DATASET_ID', 'dataset-id');
define('MICA_CONNECTION_PREFIX', 'connection-');
define('MICA_CONNECTION_TYPE', 'connection-type');
define('MICA_CONNECTION_CONFIG', 'connection-config');

/**
 * @} End of "Mica datasets form constants".
 */

//
// connection form functions
//

/**
 * Base form for connectors.
 */
function _mica_datasets_connectors_form() {
  $form = array(
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css')
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
function _mica_datasets_connection_data(&$dataset_node, &$study_node, $parent_node) {
  // todo fetch the connector entity
  $child_node = $parent_node->nid == $dataset_node->nid ? $study_node : $dataset_node;

  $connector = mica_dataset_connector_query($dataset_node->nid, $study_node->nid);

  $row = array(
    'parent' => _mica_datasets_connection_data_node($parent_node),
    'child' => _mica_datasets_connection_data_node($child_node),
    'connector' => array(
      'id' => $connector ? $connector->id : 0,
      MICA_DATASET_ID => $dataset_node->nid,
      MICA_STUDY_ID => $study_node->nid,
      'type' => $connector ? _mica_datasets_connection_type_name($connector->class) : t('-none-'),
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
function _mica_datasets_connection_data_node(&$node) {
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
function _mica_datasets_add_connection_option(&$options, &$dataset_node, &$study_node, &$parent_node) {
  $data = _mica_datasets_connection_data($dataset_node, $study_node, $parent_node);
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
function _mica_datasets_add_table_form(&$form, $header, $empty, &$options) {
  $header = array(
    'child' => t($header),
    'connection-type' => t('Connection Type'),
    'description' => t('Description'),
    'actions' => t('Operations'),
  );

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t($empty),
  );

  if (!empty($options)) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected items'),
    );
  }
}

function _mica_datasets_connectors_form_submit($form, &$form_state) {

  switch ($form_state['triggering_element']['#value']) {
    case t('Delete selected items'):
      foreach ($form_state['values']['table'] as $selection) {
        if ($selection != 0) {
          $row = $form['table']['#options'][$selection]['row'];
          // update node referenced by the form_state
          $node = _mica_datasets_get_node_form_arg($form_state);
          if ($node->type !== 'study') {
            $node = node_load($row['connector'][MICA_STUDY_ID]);
          }
          _mica_datasets_dataset_connection_delete($node, $row['connector'][MICA_DATASET_ID]);
        }
      }
      break;

    case t('Add Dataset'):
      // update node referenced by the form_state
      $dataset_node = node_load($form_state['values']['datasets']);
      $study_node = $form_state['build_info']['args'][0];
      _mica_datasets_add_study_to_dataset($study_node, $dataset_node);
      break;

    case t('Add Study'):
      // update selected node referenced with the one from the form_state
      $dataset_node = $form_state['build_info']['args'][0];
      $study_node = node_load($form_state['values']['studies']);
      _mica_datasets_add_study_to_dataset($study_node, $dataset_node);
      break;
  }

  // anything else will cause rebuild of the form and present it again.
  $form_state['rebuild'] = TRUE;
}

function _mica_datasets_add_study_to_dataset($study, $dataset) {
  // Check if study already exists
  $study->mica_dataset[$study->language][] = array('nid' => $dataset->nid);
  node_save($study);

  _mica_datasets_study_variable($study, $dataset);

  // No need to update the dataset since we have the corresponding node reference module
}

/**
 * @param $study
 * @param $dataset
 *
 * For all variable in $dataset,link them to $study with Study Variables entity
 */
function _mica_datasets_study_variable(&$study, &$dataset) {
  global $user;
  $wrapper_study = entity_metadata_wrapper('node', $study);
  $wrapper_dataset = entity_metadata_wrapper('node', $dataset);

  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study_variable')
    ->fieldCondition('field_sv_study', 'nid', $wrapper_study->nid->value())
    ->execute();

  $study_variables = array();
  if (empty($results['node']) == FALSE) {
    $study_variables = entity_load('node', array_keys($results['node']));
  }

  foreach ($wrapper_dataset->field_dataset_variables as $wrapper_variable) {
    $exist = FALSE;
    foreach ($study_variables as $sv) {
      $wrapper_sv = entity_metadata_wrapper('node', $sv);
      if ($wrapper_sv->field_sv_variable->nid->value() === $wrapper_variable->nid->value()
        && $wrapper_sv->field_sv_study->nid->value() === $wrapper_study->nid->value()
      ) {
        $exist = TRUE;
      }
    }
    if ($exist === FALSE) {
      _mica_datasets_create_study_variable($wrapper_study, $wrapper_variable);
    }
  }
}

function _mica_datasets_dataset_connection_delete(&$study_node, $dataset_node_id) {
  _mica_datasets_remove_study_to_dataset($study_node, node_load($dataset_node_id));

  // todo delete connector entity too
  $connector = mica_dataset_connector_query($dataset_node_id, $study_node->nid);
  if ($connector) {
    $connector->delete();
  }
}

function _mica_datasets_remove_study_to_dataset(&$study, &$dataset) {
  foreach ($study->mica_dataset[$study->language] as $key => $value) {
    if ($value['nid'] == $dataset->nid) {
      unset($study->mica_dataset[$study->language][$key]);
      node_save($study);
      break;
    }
  }
  // No need to update the dataset since we have the corresponding node reference module
}

//
// utilities
//

function _mica_datasets_connection_type_name($type) {
  if ($type == 'none') {
    return t('-none-');
  }
  $connection = mica_datasets_get_connection_info($type);
  if (isset($connection) && array_key_exists('name', $connection)) {
    return $connection['name'];
  }
  return $type;
}

function _mica_datasets_connection_types() {
  // todo get list of MicaDatasetConnectionInterface implementations
  $types = array(
    'none' => t('-none-'),
  );

  //debug(mica_datasets_get_connection_info());
  $connections = mica_datasets_get_connection_info();

  if (isset($connections)) {
    foreach ($connections as $key => $connection) {
      $types[$key] = $connection['name'];
    }
  }

  return $types;
}

function _mica_datasets_add_connection_config_implementation_form(&$study_node, $connection_type) {
  return _mica_datasets_new_connector($connection_type)->configurationForm($study_node);
}

function _mica_datasets_connection_options_validate(&$form, &$values, &$form_state, $connection_type) {
  return _mica_datasets_new_connector($connection_type)->configurationFormValidate($form, $values, $form_state);
}

function _mica_datasets_new_connector($connection_type) {
  return new MicaDatasetConnector(array('class' => $connection_type));
}

/**
 * Submit the options
 *
 * @param $form
 * @param $form_state
 * @param $connection_type
 */
function _mica_datasets_connection_options_submit(&$form, &$form_state, $connection_type) {
  $options = _mica_datasets_connection_config_values($form, $form_state);
  if ($connection_type == 'none') {
    return $options;
  }
  return _mica_datasets_new_connector($connection_type)->configurationFormSubmit($form, $options, $form_state);
}

/**
 * Get the node provided provided as an argument to the form.
 *
 * @param  $form_state
 */
function _mica_datasets_get_node_form_arg(&$form_state) {
  return $form_state['build_info']['args'][0];
}

/**
 * Get all nodes of dataset type that are published, accessible
 * and not already datasets of current study.
 *
 * @param study node $study_node
 */
function _mica_datasets_datasets_options($study_node) {
  $rval = array();
  $dataset_node_ids = array();
  foreach (_mica_datasets_node_field_values($study_node, 'mica_dataset') as $dataset_node_id_value) {
    $dataset_node_ids[] = $dataset_node_id_value['nid'];
  }

  $q = db_select('node', 'n');
  $q->addField('n', 'nid');
  $q->addField('n', 'title');
  $q->condition('n.type', 'dataset');
  $q->condition('n.status', 1);
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
function _mica_datasets_studies_options(&$study_node_ids) {
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
 * Get all nodes of study type that are published, accessible
 * and are related to current dataset.
 *
 * @param $dataset_node_id
 */
function _mica_datasets_get_study_ids($dataset_node_id) {
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
function _mica_datasets_get_dataset_ids($study_node_id) {
  $rval = array();

  $q = db_select('field_data_mica_dataset', 'f');
  $q->addField('f', 'mica_dataset_nid');
  $q->condition('f.entity_id', $study_node_id, '=');
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
 * @param node   $node
 * @param string $field_name
 */
function _mica_datasets_node_field_values($node, $field_name) {
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
function _mica_datasets_connection_config_values(&$form, &$form_state) {
  $values = array();
  foreach ($form_state['values'] as $key => $value) {
    if (array_key_exists($key, $form[MICA_CONNECTION_CONFIG])) {
      $values[$key] = $value;
    }
  }
  return $values;
}
