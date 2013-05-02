<?php

function _mica_studies_block_study_menu($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  // see http://jqueryfordesigners.com/fixed-floating-elements/

  return array(
    'subject' => t('Navigation'),
    'content' => NULL,
  );
}