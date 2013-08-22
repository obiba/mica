<?php

/**
 * Delete all populations and DCE associated with the study
 */
function _mica_studies_study_delete($study) {

  $study_wrapper = entity_metadata_wrapper('node', $study->nid);
  watchdog('mica', 'Delete cascade for %study', array('%study' => $study_wrapper->title->value()), WATCHDOG_DEBUG);

  $deleted_nids = array();
  foreach ($study_wrapper->field_study_populations->getIterator() as $pop_wrapper) {
    foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $dce_nid = $dce_wrapper->nid->value();
      if (!isset($deleted_nids[$dce_nid])) {
        watchdog('mica', 'Delete DCE %dce', array('%dce' => $dce_wrapper->title->value()), WATCHDOG_DEBUG);
        $dce_wrapper->delete();
        $deleted_nids[$dce_nid] = $dce_nid;
      }
    }
    $pop_nid = $pop_wrapper->nid->value();
    if (!isset($deleted_nids[$pop_nid])) {
      watchdog('mica', 'Delete Population %pop', array('%pop' => $pop_wrapper->title->value()), WATCHDOG_DEBUG);
      $pop_wrapper->delete();
      $deleted_nids[$pop_nid] = $pop_nid;
    }
  }
}