<?php

function _mica_datasets_import_variables_callback($type, $dataset_nid, $study_nid = NULL) {

  $study_harmonizations = array();
  if (isset($study_nid)) {
    $study_harmonizations[$study_nid] = _mica_datasets_fetch_study_harmonization_view($dataset_nid, $study_nid);
  }
  else {
    // fetch all studies of the dataset
    $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);
    foreach ($dataset_wrapper->field_dataset_studies->getIterator() as $study) {
      $nid = $study->nid->value();
      $study_harmonizations[$nid] = _mica_datasets_fetch_study_harmonization_view($dataset_nid, $nid);
    }
  }

  $operations = _mica_datasets_prepare_batch_variable_import($dataset_nid, $study_harmonizations);
  batch_set(array(
    'operations' => $operations,
    'finished' => '_mica_datasets_batch_variable_import_finished',
  ));

  //TODO support ajax reload
  batch_process('node/' . $dataset_nid);

//  if ($type === 'ajax') {
//    ctools_include('ajax');
//    ctools_add_js('ajax-responder');
//
//    $commands[] = ctools_ajax_command_reload();
//    return array(
//      '#type' => 'ajax',
//      '#commands' => $commands
//    );
//  }
//  drupal_goto('node/' . $dataset_nid);
}

function _mica_datasets_prepare_batch_variable_import($dataset_nid, $study_harmonizations) {
  $operations = array();
  foreach ($study_harmonizations as $study_nid => $harmonizations) {
    foreach ($harmonizations['variables'] as $harmonization_variable) {
      $operations[] = array(
        '_mica_datasets_batch_import_variables',
        array($dataset_nid, $study_nid, $harmonizations['primary_key'], $harmonization_variable)
      );
    }
  }
  return $operations;
}

function _mica_datasets_batch_variable_import_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('@count variables imported', array(
      '@count' => count($results),
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
  //TODO ajax reload
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
}

function _mica_datasets_batch_import_variables($dataset_nid, $study_nid, $primary_key, $harmonization_variable, &$context) {

  // keep current dataset variables between batch steps
  if (empty($context['results']) || $context['results']['dataset_nid'] != $dataset_nid) {
    watchdog('mica', 'Cache batch dataset info %nid', array('%nid' => $dataset_nid), WATCHDOG_DEBUG);
    $context['results'] = array(
      'dataset_nid' => $dataset_nid,
      'last_position' => 1,
      'variables' => db_query(
        "SELECT n.nid, n.title, n.uuid FROM {node} as n, {field_data_field_dataset_variables} as dv WHERE n.type = :type AND n.nid = dv.field_dataset_variables_nid AND dv.entity_id = :dataset_nid;",
        array(':dataset_nid' => $dataset_nid, ':type' => 'variable'))
        ->fetchAllAssoc($primary_key),
    );
    //TODO load SVA if harmonization
  }

  $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);
  $variables = $context['results']['variables'];
  $variable_nid = NULL;

  if (isset($variables[$harmonization_variable[$primary_key]])) {
    $variable = $variables[$harmonization_variable[$primary_key]];
    $variable_nid = _mica_datasets_update_variable($variable->nid, $dataset_wrapper->value()->language, $harmonization_variable);
  }
  else {
    $variable_nid = _mica_datasets_create_variable($dataset_wrapper->value(), $harmonization_variable, $context['results']['last_position']);
    $context['results']['last_position']++;
  }

  if ($dataset_wrapper->field_dataset_type->value() === 'harmonization') {
    // update SVA if exists, SVA creation is done by hook_insert

    // TODO native SQL: load all SVA for this dataset and this study (loading variable_nid)
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'study_variable_attributes')
      ->fieldCondition('field_sva_variable', 'nid', $variable_nid)
      ->fieldCondition('field_sva_study', 'nid', $study_nid)
      ->execute();
    if (!empty($results)) {
      foreach ($results['node'] as $result) {
        $sva = entity_metadata_wrapper('node', node_load($result->nid));
        if ($sva->field_sva_study->nid->value() == $study_nid) {
          $sva->field_sva_script->set($harmonization_variable['script']);
          $sva->field_sva_status->set($harmonization_variable['status']);
          foreach ($harmonization_variable['comment'] as $language => $value) {
            $sva->language($language)->field_sva_comment->set($value);
          }
          $sva->save();
        }
      }
    }
  }
}

function _mica_datasets_create_variable($dataset, $harmonization_variable, $position) {

  watchdog('mica', 'Create new variable %title', array('%title' => $harmonization_variable['title']), WATCHDOG_DEBUG);

  global $user;

  $infos = array(
    'type' => 'variable',
    'title' => $harmonization_variable['title'],
    'title_field' => $harmonization_variable['title'],
    'language' => $dataset->language,
    'uid' => $user->uid,
    'status' => NODE_NOT_PUBLISHED,
    'menu' => '',
    'field_dataset' => $dataset->nid,
    'field_value_type' => $harmonization_variable['value_type'],
    'field_repeatable' => $harmonization_variable['repeatable'],
    'field_unit' => $harmonization_variable['unit'],
    'field_position' => $position,
  );
  // Creates a wrapper object without inserting it to the DB
  $wrapper = entity_property_values_create_entity('node', $infos);

  foreach ($harmonization_variable['label'] as $language => $value) {
    $wrapper->language($language)->field_label->set($value);
  }
  foreach ($harmonization_variable['description'] as $language => $value) {
    $wrapper->language($language)->body->value->set($value);
  }

  // Update categories
  $i = 0;
  foreach ($harmonization_variable['categories'] as $category) {
    $wrapper->language($dataset->language)->field_variable_categories[$i]->name->set($category['name']);
    $wrapper->language($dataset->language)->field_variable_categories[$i]->missing->set($category['missing']);
    if (isset($category['label'])) {
      foreach ($category['label'] as $language => $value) {
        $wrapper->language($language)->field_variable_categories[$i]->label->set($value);

        // needed to share values between languages
        $wrapper->language($language)->field_variable_categories[$i]->name->set($category['name']);
        $wrapper->language($language)->field_variable_categories[$i]->missing->set($category['missing']);
      }
    }
    $i++;
  }
  $wrapper->save();
  return $wrapper->nid->value();
}

function _mica_datasets_update_variable($variable_nid, $dataset_language, $harmonization_variable) {

  watchdog('mica', 'Update variable %nid', array('%nid' => $variable_nid), WATCHDOG_DEBUG);

  $wrapper = entity_metadata_wrapper('node', $variable_nid);

  $i = 0;
  foreach ($harmonization_variable['categories'] as $category) {
    $wrapper->language($dataset_language)->field_variable_categories[$i]->name->set($category['name']);
    $wrapper->language($dataset_language)->field_variable_categories[$i]->missing->set($category['missing']);
    if (isset($category['label'])) {
      foreach ($category['label'] as $language => $value) {
        $wrapper->language($language)->field_variable_categories[$i]->label->set($value);

        // needed to share values between languages
        $wrapper->language($language)->field_variable_categories[$i]->name->set($category['name']);
        $wrapper->language($language)->field_variable_categories[$i]->missing->set($category['missing']);
      }
    }
    $i++;
  }
  if ($i < count($wrapper->language($dataset_language)->field_variable_categories)) {
    while (isset($wrapper->language($dataset_language)->field_variable_categories[$i])) {
      $wrapper->language($dataset_language)->field_variable_categories[$i] = NULL;
      $i++;
    }
  }
  $wrapper->save();
  return $wrapper->nid->value();
}