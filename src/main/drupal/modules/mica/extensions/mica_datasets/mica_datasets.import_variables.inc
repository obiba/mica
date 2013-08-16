<?php

function mica_datasets_import_variables_callback($type, $dataset_nid, $study_nid = NULL) {
  ctools_include('ajax');
  ctools_add_js('ajax-responder');

  $dataset = entity_load_single('node', $dataset_nid);

  $study_nids = array();
  if (isset($study_nid)) {
    $study_nids = array($study_nid);
  }
  else {
    // fetch all study_nids of the dataset
    $dataset_wrapper = entity_metadata_wrapper('node', $dataset);

    foreach ($dataset_wrapper->field_dataset_studies->value() as $study) {
      $study_nids[] = $study->nid;
    }
  }

  foreach ($study_nids as $nid) {
    $study = entity_load_single('node', $nid);
    $study_wrapper = entity_metadata_wrapper('node', $study);

    $harmonizations = FALSE;
    try {
      $harmonizations = mica_opal_fetch_harmonization_view($dataset_nid, $nid);
    } catch (Exception $e) {
      switch ($e->getCode()) {
        case 404:
          drupal_set_message(
            t('Opal server was not found (error 404) for study %study.',
              array('%study' => $study_wrapper->title->value())),
            'error'
          );
          break;
        default:
          drupal_set_message(
            t('Error while importing variables for study %study: %error',
              array('%study' => $study_wrapper->title->value(), '%error' => $e->getMessage())),
            'error'
          );
      }
    }

    if ($harmonizations) {
      if (FALSE) {
        $nb = mica_datasets_create_variables($harmonizations, $dataset_wrapper->field_dataset_type->value());
      }
      else {
        $nb = mica_datasets_create_variables_turbo($harmonizations, $dataset_wrapper->field_dataset_type->value());
      }

      drupal_set_message(
        t(
          '@count variables have been imported for study @study into the dataset @dataset',
          array(
            '@count' => $nb,
            '@study' => $study_wrapper->title->value(),
            '@dataset' => $dataset->title,
          )
        )
      );
    }
  }
  if ($type === 'ajax') {
    $commands[] = ctools_ajax_command_reload();
    return array(
      '#type' => 'ajax',
      '#commands' => $commands
    );
  }
  else {
    drupal_goto('node/' . $dataset_nid);
  }
}

function mica_datasets_create_variables($harmonizations, $dataset_type) {
  global $user;
  $position = 1;
  $nb_created = 0;

  $dataset = node_load($harmonizations['dataset_nid']);

  // TODO native SQL: select all variables of this dataset (loading nid, title & UUID)
  $elapsed = 0 - microtime(TRUE);
  foreach ($harmonizations['variables'] as $harmonization) {

    //TODO use UUID if exists or variable name
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'variable')
      ->propertyCondition('title', $harmonization['title'])
      ->fieldCondition('field_dataset', 'nid', $harmonizations['dataset_nid'])
      ->execute();

    $default_language = language_default()->language;

    if (empty($result)) {
      $infos = array(
        'type' => 'variable',
        'title' => $harmonization['title'],
        'title_field' => $harmonization['title'],
        'language' => $dataset->language,
        'uid' => $user->uid,
        'status' => NODE_NOT_PUBLISHED,
        'menu' => '',
        'field_dataset' => $harmonizations['dataset_nid'],
        'field_value_type' => $harmonization['value_type'],
        'field_repeatable' => $harmonization['repeatable'],
        'field_unit' => $harmonization['unit'],
        'field_position' => $position++,
      );
      //TODO can we move this to line 1510?
      $wrapper = entity_property_values_create_entity('node', $infos);

      foreach ($harmonization['label'] as $language => $value) {
        $wrapper->language($language)->field_label->set($value);
      }
      foreach ($harmonization['description'] as $language => $value) {
        $wrapper->language($language)->body->value->set($value);
      }

      // Update categories
      $i = 0;
      foreach ($harmonization['categories'] as $category) {
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
    }
    else {
      $variable = node_load(array_shift(array_keys($result['node'])));
      $wrapper = entity_metadata_wrapper('node', $variable);

      $i = 0;
      //$wrapper->field_variable_categories->clear();
      foreach ($harmonization['categories'] as $category) {
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
//        debug("remove cats for ". $wrapper->language($language)->field_variable_categories[$i]->label->value());
        while (isset($wrapper->language($dataset->language)->field_variable_categories[$i])) {
//          debug("delete cat $i");
          //TODO $language is not defined!
          $wrapper->language($language)->field_variable_categories[$i] = NULL;
          $i++;
        }
      }
      $wrapper->save();
    }

    // TODO skip if study dataset
//    if ($dataset_type == "harmonization") {
    // TODO native SQL: load all SVA for this dataset and this study (loading variable_nid)
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'study_variable_attributes')
      ->fieldCondition('field_sva_variable', 'nid', $wrapper->nid->value())
      ->execute();
    if (!empty($results)) {
      foreach ($results['node'] as $result) {
        $sva = entity_metadata_wrapper('node', node_load($result->nid));
        if ($sva->field_sva_study->nid->value() == $harmonizations['study_nid']) {
          $sva->field_sva_script->set($harmonization['script']);
          $sva->field_sva_status->set($harmonization['status']);
          foreach ($harmonization['comment'] as $language => $value) {
            $sva->language($language)->field_sva_comment->set($value);
          }
          $sva->save();
        }
      }
    }
//    }
    $nb_created++;
  }

  $elapsed += microtime(TRUE);
  watchdog('mica', 'mica_datasets_create_variables took ' . $elapsed . ' ms.', array(), WATCHDOG_INFO);
  return $nb_created;
}

function mica_datasets_create_variables_turbo($harmonizations, $dataset_type) {
  $e = 0 - microtime(TRUE);
  global $user;
  $position = 1;
  $nb_created = 0;

  $dataset = node_load($harmonizations['dataset_nid']);

  /**
   * 1) Benchmark:
   * Using this select instead of a EntityFieldQuery into the foreach:
   *  Turbo:  took 377.09767794609 s.
   *  !Turbo: took
   */
  $variables = db_query(
    'SELECT n.title, n.uuid FROM {node} as n, {field_data_field_dataset_variables} as dv WHERE n.type =\'variable\' AND n.nid = dv.field_dataset_variables_nid AND dv.entity_id = :dataset_nid;',
    array(':dataset_nid' => $harmonizations['dataset_nid']))->fetchAllAssoc($harmonizations['primary_key']);

  foreach ($harmonizations['variables'] as $harmonization) {
    $default_language = language_default()->language;

    if (empty($result)) {
      $infos = array(
        'type' => 'variable',
        'title' => $harmonization['title'],
        'title_field' => $harmonization['title'],
        'language' => $dataset->language,
        'uid' => $user->uid,
        'status' => NODE_NOT_PUBLISHED,
        'menu' => '',
        'field_dataset' => $harmonizations['dataset_nid'],
        'field_value_type' => $harmonization['value_type'],
        'field_repeatable' => $harmonization['repeatable'],
        'field_unit' => $harmonization['unit'],
        'field_position' => $position++,
      );
      // Creates a wrapper object without inserting it to the DB
      $wrapper = entity_property_values_create_entity('node', $infos);

      foreach ($harmonization['label'] as $language => $value) {
        $wrapper->language($language)->field_label->set($value);
      }
      foreach ($harmonization['description'] as $language => $value) {
        $wrapper->language($language)->body->value->set($value);
      }

      // Update categories
      $i = 0;
      foreach ($harmonization['categories'] as $category) {
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
    }
    else {
      $variable = node_load($variables[$harmonization['title']]->nid);
      $wrapper = entity_metadata_wrapper('node', $variable);

      $i = 0;
      //$wrapper->field_variable_categories->clear();

      foreach ($harmonization['categories'] as $category) {
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
    }

    if ($dataset_type == "harmonization") {
      $query = new EntityFieldQuery();
      $results = $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'study_variable_attributes')
        ->fieldCondition('field_sva_variable', 'nid', $wrapper->nid->value())
        ->fieldCondition('field_sva_study', 'nid', $harmonizations['study_nid'])
        ->execute();
      if (!empty($results)) {
        foreach ($results['node'] as $result) {
          $sva = entity_metadata_wrapper('node', node_load($result->nid));
          if ($sva->field_sva_study->nid->value() == $harmonizations['study_nid']) {
            $sva->field_sva_script->set($harmonization['script']);
            $sva->field_sva_status->set($harmonization['status']);
            foreach ($harmonization['comment'] as $language => $value) {
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
  watchdog('mica', 'mica_datasets_create_variables_turbo took ' . $e . ' s.', array(), WATCHDOG_INFO);
  return $nb_created;
}