<?php

/**
 * @file
 * Mica Datasets pages.
 */

/**
* Display form for creating dataset entities for a given study.
*/
function _study_datasets_page($node) {
  drupal_set_title(t('Connections to Datasets of !title', array('!title' => $node->title)));
  $output =  '<div>' . t('No dataset for this study.') . '</div>';

  $field = $node->mica_dataset;
  //debug($field);
  if ($field) {
    $output = '';
    foreach ($field[$node->language] as $value) {
      $dataset_node = node_load($value['nid']);
      $output =  $output . '<div>' . $dataset_node->title . '</div>';
    }
  }
  

  return $output;
}
