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

    dpm($study, 'study');

    $study_wrapper = entity_metadata_wrapper('node', $study);
    $study_name = $study_wrapper->title->value();

    //dvm($study_name, '$study_name');

    // create population
    $population_values = array(
      'type' => 'population',
      'title' => $study_name . ' -- population',
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
      'field_pop_recruitment_sources' => $study_wrapper->field_recruitment_sources->value(),
      'field_pop_recruitment_other' => $study_wrapper->field_recruitment_other->value(),
      'field_pop_recruitement_supp_info' => $study_wrapper->field_recruitement_supp_info->value(),
      'field_pop_participants_nb' => $study_wrapper->field_target_number_participants->value(),
      'field_pop_no_limits_participants' => $study_wrapper->field_no_limits_participants->value() ? 1 : 0,
      'field_pop_participants_nb_supp_i' => $study_wrapper->field_target_nb_supp_info->value(),
      'field_pop_participants_nb_s' => $study_wrapper->field_target_number_biosamples->value(),
      'field_pop_no_lim_participants_s' => $study_wrapper->field_no_limits_samples->value() ? 1 : 0,
      'field_pop_participants_nb_s_info' => $study_wrapper->field_samples_supp_info->value(),
      'field_pop_supp_infos' => '',
      'uid' => $study->uid,
    );

    dvm($population_values);
    $population_wrapper = entity_property_values_create_entity('node', $population_values);
    $population_wrapper->save();

    $study->field_study_populations[LANGUAGE_NONE][0]['nid'][$population_wrapper->nid->value()];
    $study->field_study_populations = array(
      LANGUAGE_NONE => array(
        0 => array(
          'nid' => array(
            $population_wrapper->nid->value() => $population_wrapper->nid->value()
          )
        )
      )
    );

//    $study_wrapper->field_study_populations[0]->set(array('nid' => $population_wrapper->nid->value()));
    $study_wrapper->save();

    //dpm($population_wrapper->value(), 'population');

  }
}

function _mica_studies_longitudinal_migration_clear() {
  drupal_set_message(t("Run clear method..."));

  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'population')
    ->execute();
  if (empty($entities)) {
    return;
  }

  $nodes = node_load_multiple(array_keys($entities['node']));
  foreach ($nodes as $node) {
    $pop_wrapper = entity_metadata_wrapper('node', $node);
    node_delete($pop_wrapper->nid->value());
  }
}