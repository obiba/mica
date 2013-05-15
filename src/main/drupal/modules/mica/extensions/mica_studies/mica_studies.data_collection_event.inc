<?php

function _mica_studies_dce_view(&$node, $view_mode, $langcode) {
  _mica_studies_dce_view_data_sources($node);
  _mica_studies_dce_view_samples($node);

  // Breadcrumbs
  // retrieve first population of the dce
  $pop_link = NULL;
  $study_id = NULL;
  $wrapper = entity_metadata_wrapper('node', $node);
  foreach ($wrapper->field_dce_population->getIterator() as $pop_wrapper) {
    $pop_link = l($pop_wrapper->title->value(), 'node/' . $pop_wrapper->nid->value());
    $study_id = $pop_wrapper->field_pop_study->nid->value();
    break;
  }

  // generate specific breadcrumbs for dce pages
  $breadcrumbs = array();
  $breadcrumbs[] = l(t('Home'), '');
  $breadcrumb = _mica_studies_menu_generate_breadcrumbs('node/' . $study_id);
  for ($i = 0; $i < count($breadcrumb); $i++) {
    $breadcrumbs[] = l($breadcrumb[$i]['link_title'], $breadcrumb[$i]['link_path']);
  }
  $breadcrumbs[] = $pop_link;

  drupal_set_breadcrumb($breadcrumbs);
}

function _mica_studies_dce_view_data_sources(&$node) {

  $wrapper = entity_metadata_wrapper('node', $node);

  if (!isset($node->content['field_dce_data_sources'])) {
    // create empty field_dce_data_sources if it has no values
    mica_core_create_empty_field($node, 'field_dce_data_sources');
  }

  $data_sources = $wrapper->field_dce_data_sources->value();

  $db_index = array_search('administratives_databases', $data_sources);
  if ($db_index !== FALSE) {
    $field_dce_data_sources_admin_db = $wrapper->field_dce_data_sources_admin_db->value();
    if (!empty($field_dce_data_sources_admin_db)) {
      $nb_items = count($field_dce_data_sources_admin_db);
      $content = array();
      for ($i = 0; $i < $nb_items; $i++) {
        $content[] = $node->content['field_dce_data_sources_admin_db'][$i]['#markup'];
      }
      $node->content['field_dce_data_sources'][$db_index]['#markup'] .= ' (' . implode(', ', $content) . ')';
      $node->content['field_dce_data_sources_admin_db']['#access'] = FALSE;
    }
  }

  $other_index = array_search('others', $data_sources);
  if ($other_index !== FALSE) {
    $field_dce_data_sources_sp = $wrapper->field_dce_data_sources_sp->value();
    if (!empty($field_dce_data_sources_sp)) {
      $node->content['field_dce_data_sources'][$other_index]['#markup'] = $node->content['field_dce_data_sources_sp'][0]['#markup'];
      $node->content['field_dce_data_sources_sp']['#access'] = FALSE;
    }
  }

  if (strlen($node->content['field_dce_data_sources'][0]['#markup']) === 0) {
    $node->content['field_dce_data_sources']['#access'] = FALSE;
  }

}

function _mica_studies_dce_view_samples(&$node) {

  $wrapper = entity_metadata_wrapper('node', $node);

  if (!isset($node->content['field_dce_bio_samples_management'])) {
    // create empty field_dce_data_sources if it has no values
    mica_core_create_empty_field($node, 'field_dce_bio_samples_management');
  }

  $samples = $wrapper->field_dce_bio_samples_management->value();

  $tissues_index = array_search('tissues', $samples);
  if ($tissues_index !== FALSE) {
    $field_dce_tissues_sp = $wrapper->field_dce_tissues_sp->value();
    if (!empty($field_dce_tissues_sp)) {
      $node->content['field_dce_bio_samples_management'][$tissues_index]['#markup'] .= ' (' . $node->content['field_dce_tissues_sp'][0]['#markup'] . ')';
      $node->content['field_dce_tissues_sp']['#access'] = FALSE;
    }
  }

  $other_index = array_search('others', $samples);
  if ($other_index !== FALSE) {
    $field_dce_samples_man_other_sp = $wrapper->field_dce_samples_man_other_sp->value();
    if (!empty($field_dce_samples_man_other_sp)) {
      $node->content['field_dce_bio_samples_management'][$other_index]['#markup'] = $node->content['field_dce_samples_man_other_sp'][0]['#markup'];
      $node->content['field_dce_samples_man_other_sp']['#access'] = FALSE;
    }
  }

  if (strlen($node->content['field_dce_bio_samples_management'][0]['#markup']) === 0) {
    $node->content['field_dce_bio_samples_management']['#access'] = FALSE;
  }

}

function _mica_studies_get_dce_study_nid($dce) {
  $wrapper = entity_metadata_wrapper('node', $dce);
  foreach ($wrapper->field_dce_population->getIterator() as $pop_wrapper) {
    return $pop_wrapper->field_pop_study->nid->value();
  }
  return NULL;
}