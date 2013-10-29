<?php
require_once('mica_studies.install');
function _mica_studies_longitudinal_migration() {

  drupal_flush_all_caches();

  $operations[] = array('_mica_studies_features_revert', array());

  // Migrate content
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $study) {
      $operations[] = array('_mica_studies_migrate_content_types', array($study, count($study)));
    }
  }

  // Delete deprecated field groups
  $operations[] = array('_mica_studies_delete_deprecated_fields_groups', array());

  // configure blocks node types
  $operations[] = array('_mica_studies_config_blocks', array());

  $batch = array(
    'operations' => $operations,
    'title' => st('Enable Longitudinal Studies'),
    'init_message' => st('Starting upgrade'),
    'error_message' => st('Error while enabling longitudinal studies'),
    'finished' => '_mica_studies_migrate_finished',
    'file' => drupal_get_path('module', 'mica_studies') . '/mica_studies.migrate.inc',
  );

  batch_set($batch);
  //batch_process('node/1');
}

function _mica_studies_features_revert(&$context) {
  $context['message'] = t('Reverting studies feature');

  features_revert(array(
    'mica_studies' => array(
      'field',
      'field_group',
      'variable',
      'views_view',
      'user_permission',
      'search_api_index',
      'node'
    )
  ));
}

function _mica_studies_migrate_content_types($study, $nb_studies, &$context) {
  $context['message'] = t('Migrating content types: Study, Population and Data Collection Event');

  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $nb_studies;
  }

  $study_wrapper = entity_metadata_wrapper('node', $study);

  $pop_src_recruit = array();
  $pop_general_src_recruit = array();
  $pop_specific_src_recruit = array();
  $general = FALSE;
  $specific = FALSE;
  //recruitment sources upgrade
  foreach ($study_wrapper->field_recruitment_sources->value() as $source) {
    if ($source->name == "General population") {
      $pop_src_recruit[] = "general";
      $general = TRUE;
    }
    else if ($source->name == "Participants from existing studies") {
      $pop_src_recruit[] = "exist_studies";
    }
    else if ($source->name == "Specific population") {
      $pop_src_recruit[] = "specific_population";
      $specific = TRUE;
    }
    else if ($source->name == "Volunteer enrolment") {
      if ($general) {
        $pop_general_src_recruit[] = "volunteer";
      }
    }
    else if ($source->tid == "4") {
      if ($general) {
        $pop_general_src_recruit[] = "selected_samples";
      }
    }
    else if ($source->name == "Clinic patients") {
      if ($specific) {
        $pop_specific_src_recruit[] = "clinic_patients";
      }
    }
    else if ($source->tid == "8") {
      if ($specific) {
        $pop_specific_src_recruit[] = "specific_association";
      }
    }
    else if ($source->name == "Other source") {
      if ($specific) {
        $pop_specific_src_recruit[] = "other";
      }
    }
  }

  // create population
  $population_values = array(
    'type' => 'population',
    'title' => $study_wrapper->title->value() . ' -- population',
    'language' => $study_wrapper->language->value(),
    'field_pop_select_criteria' => $study_wrapper->field_select_criteria->value(),
    'field_pop_gender' => $study_wrapper->field_gender->value(),
    'field_pop_age_min' => $study_wrapper->field_age_min->value(),
    'field_pop_age_max' => $study_wrapper->field_age_max->value(),
    'field_pop_country' => $study_wrapper->field_country->value(),

    'field_pop_territory_value' => $study_wrapper->field_territory->value(),
    'field_pop_territory_format' => 'filtered_html',

    'field_pop_ethnic_origin' => $study_wrapper->field_ethnic_origin->value(),
    'field_pop_health_status' => $study_wrapper->field_health_status->value(),

    'field_pop_partcipant_sel_supp_in_value' => $study_wrapper->field_partcipant_sel_supp_info->value(),
    'field_pop_partcipant_sel_supp_in_format' => 'filtered_html',

    'field_pop_selection_others_sp_value' => $study_wrapper->field_selection_others_sp->value(),
    'field_pop_selection_others_sp_format' => 'filtered_html',

    'field_pop_src_recruit' => $pop_src_recruit,
    'field_pop_exist_study_part' => NULL,
    'field_pop_general_pop_recruit' => $pop_general_src_recruit,
    'field_pop_specific_pop' => $pop_specific_src_recruit,
    'field_pop_specific_pop_other_sp' => NULL,
    'field_pop_recruitment_other_value' => $study_wrapper->field_recruitment_other->value(),
    'field_pop_recruitment_other_format' => 'filtered_html',
    'field_pop_recruit_supp_info_value' => $study_wrapper->field_recruitement_supp_info->value(),
    'field_pop_recruit_supp_info_format' => 'filtered_html',

    'field_pop_participants_nb' => $study_wrapper->field_target_number_participants->value(),
    'field_pop_no_limits_participants' => $study_wrapper->field_no_limits_participants->value() ? 1 : 0,

    'field_pop_participants_nb_supp_i_value' => $study_wrapper->field_target_nb_supp_info->value(),
    'field_pop_participants_nb_supp_i_format' => 'filtered_html',

    'field_pop_participants_nb_s' => $study_wrapper->field_target_number_biosamples->value(),
    'field_pop_no_lim_participants_s' => $study_wrapper->field_no_limits_samples->value() ? 1 : 0,
    'uid' => $study->uid,
  );

  $population_wrapper = entity_property_values_create_entity('node', $population_values);

  $population_wrapper->value()->field_pop_study = array(
    LANGUAGE_NONE => array(
      0 => array(
        'nid' => array(
          $study_wrapper->nid->value() => $study_wrapper->nid->value()
        )
      )
    )
  );
  $population_wrapper->save();
  //Data collection Event
  //  Preparation phase
  $start_year = $study_wrapper->field_preparation_start_year->value();
  $end_year = $study_wrapper->field_preparation_end_year->value();
  if (!empty($start_year)) {

    $dce_values = array(
      'type' => 'data_collection_event',
      'title' => $study_wrapper->title->value() . ' -- Data Collection Event Preparation',
      'language' => $study_wrapper->language->value(),
      'field_dce_start_year' => $start_year,
      'field_dce_end_year' => $end_year,
      'field_dce_start_month' => 1,
      'field_dce_end_month' => 12,
      'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
      'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
      'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
      'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),

      'field_dce_samples_man_other_sp_value' => $study_wrapper->field_samples_man_other_sp->value(),
      'field_dce_samples_man_other_sp_format' => 'filtered_html',

      'field_dce_questionnaires' => $study_wrapper->field_questionnaires->value(),
      'field_dce_others' => $study_wrapper->field_documents->value(),
      'uid' => $study->uid,
    );
    $dce_wrapper = entity_property_values_create_entity('node', $dce_values);

    $dce_wrapper->value()->field_dce_population = array(
      LANGUAGE_NONE => array(
        0 => array(
          'nid' => array(
            $population_wrapper->nid->value() => $population_wrapper->nid->value()
          )
        )
      )
    );
    $dce_wrapper->save();
  }
  //  Baseline phase
  $start_year = $study_wrapper->field_baseline_start_year->value();
  $end_year = $study_wrapper->field_baseline_end_year->value();
  if (!empty($start_year)) {

    $dce_values = array(
      'type' => 'data_collection_event',
      'title' => $study_wrapper->title->value() . ' -- Data Collection Event Baseline',
      'language' => $study_wrapper->language->value(),
      'field_dce_start_year' => $start_year,
      'field_dce_end_year' => $end_year,
      'field_dce_start_month' => 1,
      'field_dce_end_month' => 12,
      'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
      'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
      'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
      'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),

      'field_dce_samples_man_other_sp_value' => $study_wrapper->field_samples_man_other_sp->value(),
      'field_dce_samples_man_other_sp_format' => 'filtered_html',

      'field_dce_questionnaires' => $study_wrapper->field_questionnaires->value(),
      'field_dce_others' => $study_wrapper->field_documents->value(),
      'uid' => $study->uid,
    );

    $dce_wrapper = entity_property_values_create_entity('node', $dce_values);
    $dce_wrapper->value()->field_dce_population = array(
      LANGUAGE_NONE => array(
        0 => array(
          'nid' => array(
            $population_wrapper->nid->value() => $population_wrapper->nid->value()
          )
        )
      )
    );
    $dce_wrapper->save();
  }

  //  Follow-Up phase
  $start_year = $study_wrapper->field_followup_start_year->value();
  $end_year = $study_wrapper->field_followup_end_year->value();
  if (!empty($start_year)) {

    $dce_values = array(
      'type' => 'data_collection_event',
      'title' => $study_wrapper->title->value() . ' -- Data Collection Event Follow-up',
      'language' => $study_wrapper->language->value(),
      'field_dce_start_year' => $start_year,
      'field_dce_end_year' => $end_year,
      'field_dce_start_month' => 1,
      'field_dce_end_month' => 12,
      'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
      'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
      'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
      'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),

      'field_dce_samples_man_other_sp_value' => $study_wrapper->field_samples_man_other_sp->value(),
      'field_dce_samples_man_other_sp_format' => 'filtered_html',

      'field_dce_questionnaires' => $study_wrapper->field_questionnaires->value(),
      'field_dce_others' => $study_wrapper->field_documents->value(),
      'uid' => $study->uid,
    );

    $dce_wrapper = entity_property_values_create_entity('node', $dce_values);
    $dce_wrapper->value()->field_dce_population = array(
      LANGUAGE_NONE => array(
        0 => array(
          'nid' => array(
            $population_wrapper->nid->value() => $population_wrapper->nid->value()
          )
        )
      )
    );
    $dce_wrapper->save();
  }

  // modifying study state
  $sp_target_nb = $study_wrapper->field_target_nb_supp_info->value();
  $sp_samples_nb = $study_wrapper->field_samples_supp_info->value();

  $study2 = node_load($study->nid);
  $study_wrapper = entity_metadata_wrapper('node', $study2);
  $study_wrapper->field_study_start_year->set($study_wrapper->field_preparation_start_year->value());
  $study_wrapper->field_study_end_year->set($study_wrapper->field_followup_end_year->value());
  $study_wrapper->field_target_nb_supp_info->set(array(
    'value' => "$sp_target_nb $sp_samples_nb",
    'format' => 'filtered_html'
  ));

  $study_wrapper->save();

  $context['sandbox']['progress']++;

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function _mica_studies_delete_deprecated_fields_groups(&$context) {
  $context['message'] = t('Deleting deprecated content types');

  // deleting deprecated fields
  field_delete_field('field_current_participants_nb');
  field_delete_field('field_current_part_nb_date');
  field_delete_field('field_current_participants_nb');
  field_delete_field('field_current_supp_info');
  field_delete_field('field_current_samples_nb');
  field_delete_field('field_current_samples_date');
  field_delete_field('field_current_sam_supp_info');
  field_delete_field('field_select_criteria');
  field_delete_field('field_gender');
  field_delete_field('field_age_min');
  field_delete_field('field_age_max');
  field_delete_field('field_country');
  field_delete_field('field_territory');
  field_delete_field('field_ethnic_origin');
  field_delete_field('field_health_status');
  field_delete_field('field_partcipant_sel_supp_info');
  field_delete_field('field_selection_others_sp');
  field_delete_field('field_recruitment_sources');
  field_delete_field('field_recruitment_other');
  field_delete_field('field_recruitement_supp_info');
  field_delete_field('field_data_sources');
  field_delete_field('field_data_sources_sp');
  field_delete_field('field_bio_samples_management');
  field_delete_field('field_tissues_sp');
  field_delete_field('field_samples_man_other_sp');
  field_delete_field('field_preparation_start_year');
  field_delete_field('field_preparation_end_year');
  field_delete_field('field_baseline_start_year');
  field_delete_field('field_baseline_end_year');
  field_delete_field('field_followup_start_year');
  field_delete_field('field_followup_end_year');
  field_delete_field('field_ended_end_year');
  field_delete_field('field_status_supp_info');
  field_delete_field('field_questionnaires');
  field_delete_field('field_samples_supp_info');

  // deleting deprecated groups
  _delete_groups('group_authorising_person');
  _delete_groups('group_authorising_person_m');
  _delete_groups('group_current_number');
  _delete_groups('group_current_number_samples');
  _delete_groups('group_participants_selection');
  _delete_groups('group_selection_criteria');
  _delete_groups('group_countries');
  _delete_groups('group_recruitment_procedures');
  _delete_groups('group_data_collection');
  _delete_groups('group_sample_management');
  _delete_groups('group_status');
  _delete_groups('group_current_status');
  _delete_groups('group_preparation_phase');
  _delete_groups('group_baseline_phase');
  _delete_groups('group_followup_phase');
  _delete_groups('group_ended_phase');
  _delete_groups('group_general_design');
}

function _mica_studies_migrate_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = 'All studies have been migrated.';
    drupal_set_message($message);
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

function _delete_groups($groups) {
  ctools_include('export');
  $objects = ctools_export_load_object('field_group', 'conditions', array(
    'group_name' => $groups,
  ));
  $object = array_shift($objects);
  field_group_group_export_delete($object, FALSE);
}

function _mica_studies_longitudinal_migration_clear() {
  drupal_set_message(t("Run clear method..."));

  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'population')
    ->execute();
  if (!empty($entities)) {
    foreach (array_keys($entities['node']) as $nid) {
      entity_metadata_wrapper('node', $nid) . delete();
    }
  }
}