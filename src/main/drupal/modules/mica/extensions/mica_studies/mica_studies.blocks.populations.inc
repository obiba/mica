<?php

function _mica_studies_block_study_populations($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $populations = $wrapper->field_study_populations->value();
//  dpm($populations, '$populations');

  if (empty($populations)) {
    return NULL;
  }
  return array(
    'subject' => t('Populations'),
    'content' => node_view_multiple($populations, 'full'),
  );
}