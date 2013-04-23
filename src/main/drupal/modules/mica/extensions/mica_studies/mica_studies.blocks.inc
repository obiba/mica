<?php

function _mica_studies_block_study_general_info($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }
  $content = array(
    field_view_field('node', $study, 'field_acroym', array('label' => 'inline', 'weight' => 10)),
    field_view_field('node', $study, 'field_website', array('label' => 'inline', 'weight' => 20)),
    field_view_field('node', $study, 'field_investigators', array('label' => 'inline', 'weight' => 30)),
    field_view_field('node', $study, 'field_contacts_ref', array('label' => 'inline', 'weight' => 40)),
    field_view_field('node', $study, 'field_study_start_date', array('label' => 'inline', 'weight' => 50)),
    field_view_field('node', $study, 'field_study_end_date', array('label' => 'inline', 'weight' => 60)),
  );
  return array(
    'subject' => t('General Information'),
    'content' => $content,
  );
}

function _mica_studies_block_study_general_design($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $content = array(
    _mica_studies_block_study_general_design_field_design($wrapper),
    field_view_field('node', $study, 'field_info_design_follow_up', array('label' => 'inline', 'weight' => 30)),
    field_view_field('node', $study, 'field_recruitment', array('label' => 'inline', 'weight' => 40)),
    field_view_field('node', $study, 'field_recruitment_other_sp', array('label' => 'inline', 'weight' => 50)),
    field_view_field('node', $study, 'field_recruitment_supp_info', array('label' => 'inline', 'weight' => 60)),
    field_view_field('node', $study, 'field_target_number_participants', array('label' => 'inline', 'weight' => 70)),
    //TODO hide if no
    field_view_field('node', $study, 'field_no_limits_participants', array('label' => 'inline', 'weight' => 80)),
    field_view_field('node', $study, 'field_target_nb_supp_info', array('label' => 'inline', 'weight' => 90)),
    field_view_field('node', $study, 'field_target_number_biosamples', array('label' => 'inline', 'weight' => 100)),
    //TODO hide if no
    field_view_field('node', $study, 'field_no_limits_samples', array('label' => 'inline', 'weight' => 110)),
    field_view_field('node', $study, 'field_samples_supp_info', array('label' => 'inline', 'weight' => 120)),
  );
  return array(
    'subject' => t('General Design'),
    'content' => $content,
  );
}

function _mica_studies_block_study_general_design_field_design($study_wrapper) {
  $design_view = field_view_field('node', $study_wrapper->value(), 'field_design', array(
    'label' => 'inline',
    'weight' => 10
  ));
  $design = $study_wrapper->field_design->value();
  $other_sp = $study_wrapper->field_design_other_sp->value();
  if (in_array('other', $design) && !empty($other_sp)) {
    $design_other_sp_view = field_view_field('node', $study_wrapper->value(), 'field_design_other_sp');
    $design_view[count($design) - 1]['#markup'] .= ' - ' . $design_other_sp_view[0]['#markup'];
  }
  return $design_view;
}

function _mica_studies_block_study_access($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $content = array(
    field_view_field('node', $study, 'field_access_data', array('label' => 'inline', 'weight' => 10)),
    field_view_field('node', $study, 'field_access_biosamples', array('label' => 'inline', 'weight' => 20)),
  );
  $other = _mica_studies_simulate_other_specify_field($study, 'field_access_other', 'field_access_other_sp', 30);
  if (!empty($other)) {
    $content[] = $other;
  }
  return array(
    'subject' => t('Access'),
    'content' => $content,
  );
}

function _mica_studies_block_study_marker_paper($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $marker_paper = $wrapper->field_marker_paper->value();
  $pubmedid = $wrapper->field_pubmedid->value();

  $content = empty($marker_paper) && empty($pubmedid)
    ? NULL
    : array(
      field_view_field('node', $study, 'field_marker_paper', array('label' => 'inline', 'weight' => 10)),
      field_view_field('node', $study, 'field_pubmedid', array(
          'label' => 'inline',
          'type' => 'mica_pubmed_url',
          'weight' => 20
        )
      ),
    );
  return array(
    'subject' => t('Marker Paper'),
    'content' => $content,
  );
}

function _mica_studies_block_study_documents($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $docs = $wrapper->field_supp_infos->value();
  $content = empty($docs)
    ? NULL
    : array(field_view_field('node', $study, 'field_documents', array('label' => 'hidden', 'weight' => 10)));
  return array(
    'subject' => t('Documents'),
    'content' => $content,
  );
}

function _mica_studies_block_study_supp_infos($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $supp_infos = $wrapper->field_supp_infos->value();
  $content = empty($supp_infos)
    ? NULL
    : array(field_view_field('node', $study, 'field_supp_infos', array('label' => 'hidden', 'weight' => 10)));
  return array(
    'subject' => t('Supplementary Information'),
    'content' => $content,
  );
}

function _mica_studies_block_study_authorization($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }
  $content = array(
    field_view_field('node', $study, 'field_authorization_specific', array('label' => 'inline', 'weight' => 10)),
    field_view_field('node', $study, 'field_authorising_person_name', array('label' => 'inline', 'weight' => 20)),
    field_view_field('node', $study, 'field_authorising_date', array('label' => 'inline', 'weight' => 30)),
    field_view_field('node', $study, 'field_authorization_maelstrom', array('label' => 'inline', 'weight' => 40)),
    field_view_field('node', $study, 'field_authorising_person_name_m', array('label' => 'inline', 'weight' => 50)),
    field_view_field('node', $study, 'field_authorising_date_m', array('label' => 'inline', 'weight' => 60)),
  );
  return array(
    'subject' => t('Authorization'),
    'content' => $content,
  );
}

function _mica_studies_simulate_other_specify_field($node, $field_other, $field_specify, $weight) {
  $wrapper = entity_metadata_wrapper('node', $node);
  $other = $wrapper->{$field_other}->value();
  if (empty($other)) {
    return NULL;
  }

  $field_other_view = field_view_field('node', $node, $field_other, array('label' => 'inline', 'weight' => $weight));
  $other_sp = $wrapper->{$field_specify}->value();
  if (!empty($other_sp)) {
    $field_specify_view = field_view_field('node', $node, $field_specify);
    $field_other_view[0]['#markup'] .= ' - ' . $field_specify_view[0]['#markup'];
  }
  return $field_other_view;
}