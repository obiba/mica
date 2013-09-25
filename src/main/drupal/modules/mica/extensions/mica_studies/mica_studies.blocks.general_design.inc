<?php

function _mica_studies_block_study_general_design($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $weight = 0;

  $wrapper = entity_metadata_wrapper('node', $study);
  $content = array();
  $content[] = _mica_studies_block_study_general_design_field_design($wrapper, ++$weight);
  $content[] = field_view_field('node', $study, 'field_info_design_follow_up', array(
    'label' => 'inline',
    'weight' => ++$weight
  ));
  $content[] = _mica_studies_block_study_general_design_field_recruitment($wrapper, ++$weight);

  $content[] = _mica_studies_block_study_general_design_field_nb_participants($wrapper, ++$weight);
  $content[] = _mica_studies_block_study_general_design_field_nb_samples($wrapper, ++$weight);
  $content[] = field_view_field('node', $study, 'field_target_nb_supp_info', array(
    'label' => 'inline',
    'weight' => ++$weight
  ));

  $content[] = field_view_field('node', $study, 'field_recruitment_supp_info', array(
    'label' => 'inline',
    'weight' => ++$weight
  ));

  return array(
    'subject' => t('General Design') . '<a name="general-design"> </a>',
    'content' => array_filter($content),
  );
}

function _mica_studies_block_study_general_design_field_design($study_wrapper, $weight) {
  $field_view = field_view_field('node', $study_wrapper->value(), 'field_design', array(
    'label' => 'inline',
    'weight' => $weight,
    'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
  ));
  $design = $study_wrapper->field_design->value();
  $other_sp = $study_wrapper->field_design_other_sp->value();
  if (in_array('other', $design) && !empty($other_sp)) {
    $design_other_sp_view = field_view_field('node', $study_wrapper->value(), 'field_design_other_sp');
    $label = '<span class="other-sub-title">' . $field_view[count($design) - 1]['#markup'] . ': </span>';
    $field_view[count($design) - 1]['#markup'] = $label .'<span class="other-sub-value">'. $design_other_sp_view[0]['#markup'] .'</span>';
  }
  return $field_view;
}

function _mica_studies_block_study_general_design_field_recruitment($study_wrapper, $weight) {
  $field_view = field_view_field('node', $study_wrapper->value(), 'field_recruitment', array(
    'label' => 'inline',
    'weight' => $weight,
    'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
  ));
  $recruitment = $study_wrapper->field_recruitment->value();
  $other_sp = $study_wrapper->field_recruitment_other_sp->value();
  if (in_array('other', $recruitment) && !empty($other_sp)) {
    $design_other_sp_view = field_view_field('node', $study_wrapper->value(), 'field_recruitment_other_sp');
    $field_view[count($recruitment) - 1]['#markup'] .= ' - ' . $design_other_sp_view[0]['#markup'];
  }
  return $field_view;
}

function _mica_studies_block_study_general_design_field_nb_participants($study_wrapper, $weight) {
  $field = array(
    '#theme' => 'field',
    '#weight' => $weight,
    '#title' => t('Target number of participants'),
    '#label_display' => 'inline',
    '#field_type' => 'text',
    '#formatter' => 'text_default',
    '#field_name' => 'field_target_number_participants',
    '#bundle' => 'study',
    '#entity_type' => 'node',
    '#items' => array(),
  );

  $target_number = $study_wrapper->field_target_number_participants->value();
  if (!empty($target_number)) {
    $field['#items'][] = number_format($target_number, 0, '.', ' ');
    $field[]['#markup'] = number_format($target_number, 0, '.', ' ');
  }

  $no_limits = $study_wrapper->field_no_limits_participants->value();
  if ($no_limits) {
    $field['#items'][] = t('No limit');
    $field[]['#markup'] = t('No limit');
  }

  return empty($field['#items']) ? NULL : $field;
}

function _mica_studies_block_study_general_design_field_nb_samples($study_wrapper, $weight) {
  $field = array(
    '#theme' => 'field',
    '#weight' => $weight,
    '#title' => t('Target number of participants with biological samples'),
    '#label_display' => 'inline',
    '#field_type' => 'text',
    '#formatter' => 'text_default',
    '#field_name' => 'field_target_number_biosamples',
    '#bundle' => 'study',
    '#entity_type' => 'node',
    '#items' => array(),
  );

  $target_number = $study_wrapper->field_target_number_biosamples->value();
  if (!empty($target_number)) {
    $field['#items'][] = number_format($target_number, 0, '.', ' ');
    $field[]['#markup'] = number_format($target_number, 0, '.', ' ');
  }

  $no_limits = $study_wrapper->field_no_limits_samples->value();
  if ($no_limits) {
    $field['#items'][] = t('No limit');
    $field[]['#markup'] = t('No limit');
  }

  return empty($field['#items']) ? NULL : $field;
}

