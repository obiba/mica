<?php

function _mica_studies_block_study_populations($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);

  $content = array();
  foreach ($wrapper->field_study_populations->getIterator() as $population_wrapper) {
    $dce_rows = array();
    foreach ($population_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $start = $dce_wrapper->field_dce_start_date->value();
      $end = $dce_wrapper->field_dce_end_date->value();
      $dce_rows[] = array(
        l($dce_wrapper->title->value(), 'node/' . $dce_wrapper->nid->value()),
        empty($start) ? '' : date("Y M", $start),
        empty($end) ? '' : date("Y M", $end),
      );
    }
    $pop = node_view($population_wrapper->value(), 'full');
    if (!empty($dce_rows)) {
      $pop['data-collection-event'] = array(
        '#weight' => '100',
        '#theme' => 'table',
        '#caption' => t('Data Collection Events') . ': ',
        '#attributes' => array('class' => array('pop-dce')),
        '#header' => array(t('Name'), t('Start'), t('End')),
        '#rows' => $dce_rows,
      );
    }
    $content[] = $pop;
  }
  return array(
    'subject' => t('Populations'),
    'content' => $content,
  );
}
