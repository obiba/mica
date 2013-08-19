<?php

function mica_datasets_import_variables_callback($type, $dataset_nid, $study_nid = NULL) {

  $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);

  if (isset($study_nid)) {
    _mica_datasets_import_variables_for_study($dataset_wrapper, $study_nid);
  }
  else {
    // fetch all study_nids of the dataset
    foreach ($dataset_wrapper->field_dataset_studies->getIterator() as $study) {
      _mica_datasets_import_variables_for_study($dataset_wrapper, $study->nid->value());
    }
  }

  if ($type === 'ajax') {
    ctools_include('ajax');
    ctools_add_js('ajax-responder');

    $commands[] = ctools_ajax_command_reload();
    return array(
      '#type' => 'ajax',
      '#commands' => $commands
    );
  }
  drupal_goto('node/' . $dataset_nid);
}

function _mica_datasets_import_variables_for_study($dataset_wrapper, $study_nid) {
  $study_wrapper = entity_metadata_wrapper('node', $study_nid);
  $study_title = $study_wrapper->title->value();

  try {
    $harmonizations = mica_opal_fetch_harmonization_view($dataset_wrapper->nid->value(), $study_nid);
    $nb = _mica_datasets_import_variables($harmonizations, $dataset_wrapper->field_dataset_type->value());
    drupal_set_message(
      t(
        '@count variables have been imported for study @study into the dataset @dataset',
        array(
          '@count' => $nb,
          '@study' => $study_title,
          '@dataset' => $dataset_wrapper->title->value(),
        )
      )
    );
  } catch (Exception $e) {
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

function _mica_datasets_import_variables($harmonizations, $dataset_type) {
  $e = 0 - microtime(TRUE);
  global $user;
  $position = 1;
  $nb_created = 0;

  $dataset = node_load($harmonizations['dataset_nid']);

  $primary_key = $harmonizations['primary_key'];
  $variables = db_query(
    "SELECT n.title, n.uuid FROM {node} as n, {field_data_field_dataset_variables} as dv " .
    "WHERE n.type ='variable' AND n.nid = dv.field_dataset_variables_nid AND dv.entity_id = :dataset_nid;",
    array(':dataset_nid' => $harmonizations['dataset_nid']))->fetchAllAssoc($primary_key);

  foreach ($harmonizations['variables'] as $harmonization_variable) {

    $variable_nid = NULL;
    if (isset($variables[$harmonization_variable[$primary_key]])) {
      $variable = $harmonization_variable[$primary_key];
      $variable_nid = _mica_datasets_update_variable($variable, $dataset, $harmonization_variable);
    }
    else {
      $variable_nid = _mica_datasets_create_variable($dataset, $harmonization_variable, $position++);
    }

    if ($dataset_type === "harmonization") {
      // TODO native SQL: load all SVA for this dataset and this study (loading variable_nid)
      $query = new EntityFieldQuery();
      $results = $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'study_variable_attributes')
        ->fieldCondition('field_sva_variable', 'nid', $variable_nid)
        ->fieldCondition('field_sva_study', 'nid', $harmonizations['study_nid'])
        ->execute();
      if (!empty($results)) {
        foreach ($results['node'] as $result) {
          $sva = entity_metadata_wrapper('node', node_load($result->nid));
          if ($sva->field_sva_study->nid->value() == $harmonizations['study_nid']) {
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
    $nb_created++;
  }

  $e += microtime(TRUE);
  watchdog('mica', 'mica_datasets_create_variables took %time s.', array('%time' => $e), WATCHDOG_INFO);
  return $nb_created;
}

function _mica_datasets_create_variable($dataset, $harmonization_variable, $position) {
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

function _mica_datasets_update_variable($variable, $dataset, $harmonization_variable) {
  $wrapper = entity_metadata_wrapper('node', $variable->nid);

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
  if ($i < count($wrapper->language($dataset->language)->field_variable_categories)) {
    while (isset($wrapper->language($dataset->language)->field_variable_categories[$i])) {
      $wrapper->language($dataset->language)->field_variable_categories[$i] = NULL;
      $i++;
    }
  }
  $wrapper->save();
  return $wrapper->nid->value();
}