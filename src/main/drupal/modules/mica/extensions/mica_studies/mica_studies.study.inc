<?php

/**
 * Delete all populations and DCE associated with the study
 */
function _mica_studies_study_delete($study) {

  $study_wrapper = entity_metadata_wrapper('node', $study->nid);
  watchdog('mica', 'Delete cascade for %study', array('%study' => $study_wrapper->title->value()), WATCHDOG_DEBUG);

  $deleted_nids = array();
  //Todo perform this deletion in a batch
//  foreach($study_wrapper->field_study_study_variable_att ->getIterator() as $var_sva_wrapper){
//        $sva_nid = $var_sva_wrapper->getIdentifier();
//    if (!empty($sva_nid)) {
//      watchdog('mica', 'Delete Study Variable attribute %sva', array('%sva' => $sva_nid), WATCHDOG_DEBUG);
//      $var_sva_wrapper->delete();
//    }
//  }
  foreach ($study_wrapper->field_study_populations->getIterator() as $pop_wrapper) {
    foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $dce_nid = $dce_wrapper->getIdentifier();
      if (empty($deleted_nids[$dce_nid])) {
        watchdog('mica', 'Delete DCE %dce', array('%dce' => $dce_wrapper->title->value()), WATCHDOG_DEBUG);
        $dce_wrapper->delete();
        $deleted_nids[$dce_nid] = $dce_nid;
      }
    }
    $pop_nid = $pop_wrapper->getIdentifier();
    if (empty($deleted_nids[$pop_nid])) {
      watchdog('mica', 'Delete Population %pop', array('%pop' => $pop_wrapper->title->value()), WATCHDOG_DEBUG);
      $pop_wrapper->delete();
      $deleted_nids[$pop_nid] = $pop_nid;
    }
  }
}