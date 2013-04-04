<?php
function _mica_studies_devel_form() {

  $form['migrate'] = array(
    '#type' => 'fieldset',
    '#title' => t('study migration'),
    '#description' => NULL,
  );
  $form['migrate']['migration'] = array(
    '#type' => 'submit',
    '#value' => t('Run migration method'),
    '#submit' => array('_mica_studies_longitudinal_migration'),
  );
  $form['migrate']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Run clear method'),
    '#submit' => array('_mica_studies_longitudinal_migration_clear'),
  );

  return $form;
}

function _mica_studies_longitudinal_migration() {
  drupal_set_message(t("Run migration method..."));

  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study')
    ->execute();
  if (empty($entities)) {
    return;
  }

  $nodes = node_load_multiple(array_keys($entities['node']));
  foreach ($nodes as $study) {

    $study_wrapper = entity_metadata_wrapper('node', $study);

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
      'field_pop_territory' => $study_wrapper->field_territory->value(),
      'field_pop_ethnic_origin' => $study_wrapper->field_ethnic_origin->value(),
      'field_pop_health_status' => $study_wrapper->field_health_status->value(),
      'field_pop_partcipant_sel_supp_in' => $study_wrapper->field_partcipant_sel_supp_info->value(),
      'field_pop_selection_others_sp' => $study_wrapper->field_selection_others_sp->value(),
      'field_pop_src_recruit' => $study_wrapper->field_recruitment_sources->value(),
      'field_pop_exist_study_part' => null,
      'field_pop_general_pop_recruit' => null,
      'field_pop_specific_pop' => null,
      'field_pop_specific_pop_info' => null,
      'field_pop_recruitment_other' => $study_wrapper->field_recruitment_other->value(),
      'field_pop_recruitement_supp_info' => $study_wrapper->field_recruitement_supp_info->value(),
      'field_pop_participants_nb' => $study_wrapper->field_target_number_participants->value(),
      'field_pop_no_limits_participants' => $study_wrapper->field_no_limits_participants->value() ? 1 : 0,
      'field_pop_participants_nb_supp_i' => $study_wrapper->field_target_nb_supp_info->value(),
      'field_pop_participants_nb_s' => $study_wrapper->field_target_number_biosamples->value(),
      'field_pop_no_lim_participants_s' => $study_wrapper->field_no_limits_samples->value() ? 1 : 0,
      'field_pop_participants_nb_s_info' => $study_wrapper->field_samples_supp_info->value(),
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
    $study_wrapper = entity_metadata_wrapper('node', $study);
    //  Preparation phase
    $start_year = $study_wrapper->field_preparation_start_year->value();
    $end_year = $study_wrapper->field_preparation_end_year->value();
    if (!empty($start_year)) {

      $dce_values = array(
        'type' => 'data_collection_event',
        'title' => $study_wrapper->title->value() . ' -- Data Collection Event Preparation',
        'language' => $study_wrapper->language->value(),
        'field_dce_start_date' => strtotime($start_year . "-01-01 00:00:00"),
        'field_dce_end_date' => strtotime($end_year . "-01-01 00:00:00"),
        'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
        'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
        'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
        'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),
        'field_dce_samples_man_other_sp' => $study_wrapper->field_samples_man_other_sp->value(),
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
        'field_dce_start_date' => strtotime($start_year . "-01-01 00:00:00"),
        'field_dce_end_date' => strtotime($end_year . "-01-01 00:00:00"),
        'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
        'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
        'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
        'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),
        'field_dce_samples_man_other_sp' => $study_wrapper->field_samples_man_other_sp->value(),
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
        'field_dce_start_date' => strtotime($start_year . "-01-01 00:00:00"),
        'field_dce_end_date' => strtotime($end_year . "-01-01 00:00:00"),
        'field_dce_data_sources' => $study_wrapper->field_data_sources->value(),
        'field_dce_data_sources_sp' => $study_wrapper->field_data_sources_sp->value(),
        'field_dce_bio_samples_management' => $study_wrapper->field_bio_samples_management->value(),
        'field_dce_tissues_sp' => $study_wrapper->field_tissues_sp->value(),
        'field_dce_samples_man_other_sp' => $study_wrapper->field_samples_man_other_sp->value(),
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
    $start_year = $study_wrapper->field_preparation_start_year->value();
    $end_year = $study_wrapper->field_followup_end_year->value();
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $study_wrapper->value()->field_study_start_date = strtotime($start_year . "-01-01 00:00:00");
    $study_wrapper->value()->field_study_end_date = strtotime($end_year . "-01-01 00:00:00");
    $study_wrapper->save();

  }

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
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $pop_wrapper = entity_metadata_wrapper('node', $node);
      node_delete($pop_wrapper->nid->value());
    }
  }

}