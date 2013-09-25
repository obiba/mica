<?php

function _mica_datasets_import_variables_callback($dataset_nid, $study_nid = NULL) {

  if (!is_numeric($dataset_nid)) {
    $dataset_nid = $dataset_nid->nid;
  }
  if (!empty($study_nid) && !is_numeric($study_nid)) {
    $study_nid = $study_nid->nid;
  }

  $operations = array();
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);
  $is_harmonization = $dataset_wrapper->field_dataset_type->value() === 'harmonization';
  $study_harmonizations = array();
  if (isset($study_nid)) {
    $study_harmonizations[$study_nid] = _mica_datasets_fetch_study_harmonization_view($dataset_nid, $study_nid);
  }
  else {
    foreach ($dataset_wrapper->field_dataset_studies->getIterator() as $study) {
      $nid = $study->nid->value();
      $harmonization_view = _mica_datasets_fetch_study_harmonization_view($dataset_nid, $nid);
      if (!empty($harmonization_view)) {
        $study_harmonizations[$nid] = $harmonization_view;

        if (!$is_harmonization) {
          break;
        }
      }
    }
  }

  if (!empty($study_harmonizations)) {
    $first_key = key($study_harmonizations);
    $operations = _mica_datasets_prepare_batch_variable_import($dataset_nid, $first_key, $study_harmonizations[$first_key]);
    if ($is_harmonization) {
      _mica_datasets_prepare_batch_sva_import($dataset_nid, $study_harmonizations, $operations);
    }
  }

  batch_set(array(
    'operations' => $operations,
    'finished' => '_mica_datasets_batch_variable_import_finished',
  ));

  $redirect = 'node/' . $dataset_nid;
  if (!empty($study_nid)) {
    $redirect .= '/dataset-harmonization';
  }
  batch_process($redirect);
}

function _mica_datasets_prepare_batch_variable_import($dataset_nid, $study_nid, $harmonizations) {
  $operations = array();
  foreach ($harmonizations['variables'] as $harmonization_variable) {
    $operations[] = array(
      '_mica_datasets_batch_import_variables',
      array($dataset_nid, $study_nid, $harmonization_variable)
    );
  }
  return $operations;
}

function _mica_datasets_prepare_batch_sva_import($dataset_nid, $study_harmonizations, &$operations) {
  foreach ($study_harmonizations as $study_nid => $harmonizations) {
    foreach ($harmonizations['variables'] as $harmonization_variable) {
      $operations[] = array(
        '_mica_datasets_batch_import_svas',
        array($dataset_nid, $study_nid, $harmonization_variable)
      );
    }
  }
}

function _mica_datasets_batch_variable_import_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Import finished: @nb_created variables created and @nb_updated updated.', array(
      '@nb_created' => $results['nb_created'],
      '@nb_updated' => $results['nb_updated'],
    )));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array(
      '@operation' => $error_operation[0],
      '@args' => print_r($error_operation[0], TRUE)
    )));
  }
}

function _mica_datasets_fetch_study_harmonization_view($dataset_nid, $study_nid) {
  try {
    return mica_opal_fetch_harmonization_view($dataset_nid, $study_nid);
  } catch (Exception $e) {
    $study_wrapper = entity_metadata_wrapper('node', $study_nid);
    $study_title = $study_wrapper->title->value();
    switch ($e->getCode()) {
      case 404:
        drupal_set_message(
          t('Opal server was not found (error 404) for study %study.',
            array('%study' => $study_title)),
          'error'
        );
        break;
      default:
        drupal_set_message(
          t('Error while importing variables for study %study: %error',
            array('%study' => $study_title, '%error' => $e->getMessage())),
          'error'
        );
    }
  }
  return NULL;
}

function _mica_datasets_batch_import_variables($dataset_nid, $study_nid, $harmonization_variable, &$context) {

  // keep current dataset variables between batch steps
  if (empty($context['results']) || $context['results']['study']->nid->value() != $study_nid) {
    watchdog('mica', 'Cache batch dataset info %nid', array('%nid' => $dataset_nid), WATCHDOG_DEBUG);
    $primary_key = isset($harmonization_variable['uuid']) ? 'uuid' : 'title';
    $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);
    $context['results'] = array(
      'last_position' => 1,
      'variables' => db_query(
        'SELECT n.nid, n.title, n.uuid FROM {node} as n, {field_data_field_dataset_variables} as dv WHERE n.type = :type AND n.nid = dv.field_dataset_variables_nid AND dv.entity_id = :dataset_nid;',
        array(':dataset_nid' => $dataset_nid, ':type' => 'variable'))
        ->fetchAllAssoc($primary_key),
      'nb_created' => 0,
      'nb_updated' => 0,
      'dataset' => $dataset_wrapper,
      'study' => entity_metadata_wrapper('node', $study_nid),
      'key' => $primary_key,
    );
  }

  $dataset_wrapper = $context['results']['dataset'];
  $variables = $context['results']['variables'];
  $key = $context['results']['key'];
  $variable_nid = NULL;

  if (isset($variables[$harmonization_variable[$key]])) {
    $context['message'] = t('Updating %var for study: %study.', array(
      '%var' => $harmonization_variable['title'],
      '%study' => $context['results']['study']->title->value()
    ));
    $variable = $variables[$harmonization_variable[$key]];
    $variable_nid = _mica_datasets_update_variable($variable->nid, $dataset_wrapper->value()->language, $harmonization_variable);
    $context['results']['nb_updated']++;
  }
  else {
    $context['message'] = t('Creating %var for study: %study.', array(
      '%var' => $harmonization_variable['title'],
      '%study' => $context['results']['study']->title->value()
    ));
    $variable_nid = _mica_datasets_create_variable($dataset_wrapper->value(), $harmonization_variable, $context['results']['last_position']);
    $context['results']['last_position']++;
    $context['results']['nb_created']++;
  }

  $context['results']['variables_nids'][$harmonization_variable[$key]] = $variable_nid;
}

function _mica_datasets_batch_import_svas($dataset_nid, $study_nid, $harmonization_variable, &$context) {

//  $primary_key = isset($harmonization_variable['uuid']) ? 'uuid' : 'title';
  // keep current dataset variables between batch steps
  if (empty($context['results']['svas'])) {
    // Get all sva for this dataset
    $all_svas = db_query(
      'SELECT sva.entity_id, s.field_sva_study_nid, dv.field_dataset_variables_nid FROM {field_data_field_sva_variable} as sva LEFT OUTER JOIN {field_data_field_dataset_variables} as dv ON sva.field_sva_variable_nid = dv.field_dataset_variables_nid, {field_data_field_sva_study} as s WHERE dv.entity_id=:dataset_nid AND sva.entity_id = s.entity_id', array(':dataset_nid' => $dataset_nid))
      ->fetchAll();

    $svas = array();
    foreach ($all_svas as $sva) {
      $svas[$sva->field_sva_study_nid][$sva->field_dataset_variables_nid] = $sva;
    }
    $context['results']['svas'] = $svas;
  }
  // reload study if changed
  if (isset($context['results']['study']) && $context['results']['study']->nid->value() != $study_nid) {
    $context['results']['study'] = entity_metadata_wrapper('node', $study_nid);
  }

  $context['message'] = t('Updating study variable attribute for %var and study %study.', array(
    '%var' => $harmonization_variable['title'],
    '%study' => $context['results']['study']->title->value()
  ));
  $svas = $context['results']['svas'];
  $key = $context['results']['key'];
  $variable_nid = $context['results']['variables_nids'][$harmonization_variable[$key]];
  if (isset($svas[$study_nid][$variable_nid])) {
    _mica_datasets_update_sva($svas[$study_nid][$variable_nid]->entity_id, $harmonization_variable);
  }
}

function _mica_datasets_create_variable($dataset, $harmonization_variable, $position) {

  watchdog('mica', 'Create new variable %title', array('%title' => $harmonization_variable['title']), WATCHDOG_DEBUG);

  global $user;

  $infos = array(
    'type' => 'variable',
    'language' => $dataset->language,
    'uid' => $user->uid,
    'status' => NODE_NOT_PUBLISHED,
    'menu' => '',
    'field_dataset' => $dataset->nid,
    'field_position' => $position,
  );
  // Copy uuid
  if (isset($harmonization_variable['uuid'])) {
    $infos['uuid'] = $harmonization_variable['uuid'];
  }

  // Creates a wrapper object without inserting it to the DB
  $wrapper = entity_property_values_create_entity('node', $infos);

  return _mica_datasets_update_variable_wrapper($harmonization_variable, $dataset->language, $wrapper);
}

function _mica_datasets_update_variable($variable_nid, $dataset_language, $harmonization_variable) {

  watchdog('mica', 'Update variable %nid', array('%nid' => $variable_nid), WATCHDOG_DEBUG);

  $wrapper = entity_metadata_wrapper('node', $variable_nid);

  // Allow to update title

  return _mica_datasets_update_variable_wrapper($harmonization_variable, $dataset_language, $wrapper);
}

function _mica_datasets_update_variable_wrapper($harmonization_variable, $dataset_language, $wrapper) {

  $wrapper->title->set($harmonization_variable['title']);
  $wrapper->title_field->set($harmonization_variable['title']);
  $wrapper->field_value_type->set($harmonization_variable['value_type']);
  $wrapper->field_repeatable->set($harmonization_variable['repeatable']);
  if (!empty($harmonization_variable['unit'])) {
    $wrapper->field_unit->set($harmonization_variable['unit']);
  }

  foreach ($harmonization_variable['label'] as $language => $value) {
    $wrapper->language($language)->field_label->set($value);
  }
  foreach ($harmonization_variable['description'] as $language => $value) {
    $wrapper->language($language)->body->value->set($value);
  }

  $category_index = 0;
  foreach ($harmonization_variable['categories'] as $category) {
    $wrapper->language($dataset_language)->field_variable_categories[$category_index]->name->set($category['name']);
    $wrapper->language($dataset_language)->field_variable_categories[$category_index]->missing->set($category['missing']);
    if (isset($category['label'])) {
      foreach ($category['label'] as $language => $value) {
        $wrapper->language($language)->field_variable_categories[$category_index]->label->set($value);

        // needed to share values between languages
        $wrapper->language($language)->field_variable_categories[$category_index]->name->set($category['name']);
        $wrapper->language($language)->field_variable_categories[$category_index]->missing->set($category['missing']);
      }
    }
    $category_index++;
  }
  if ($category_index < count($wrapper->language($dataset_language)->field_variable_categories)) {
    while (isset($wrapper->language($dataset_language)->field_variable_categories[$category_index])) {
      $wrapper->language($dataset_language)->field_variable_categories[$category_index] = NULL;
      $category_index++;
    }
  }
  $wrapper->save();
  return $wrapper->nid->value();
}

/**
 * @param $variable_nid
 * @param $harmonization_variable
 * @param $context
 */
function _mica_datasets_update_sva($sva_nid, $harmonization_variable) {
  // update SVA if exists, SVA creation is done by hook_insert
  $sva = entity_metadata_wrapper('node', $sva_nid);
  $sva->field_sva_script->set($harmonization_variable['script']);
  $sva->field_sva_status->set($harmonization_variable['status']);
  foreach ($harmonization_variable['comment'] as $language => $value) {
    $sva->language($language)->field_sva_comment->set($value);
  }
  $sva->save();
}