<?php
/**
 * @file
 * mica_studies_import_study.inc
 */

function _mica_studies_import_set_study_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  //Required field
  $study_title = $xpath->query('/study/title')->item(0)->nodeValue;
  if (empty($study_title)) {
    throw new Exception(t('Study : Field title required'));
  }
  else {
    $wrapper->title->set($study_title);
    $wrapper->title_field->set($study_title);
  }

  $wrapper->field_acroym->set(mica_studies_import_get_node_value($xpath, '/study/acronym'));

  $investigator_elements = $xpath->query('/study/investigators/investigator');
  //Destroy all existing fields entries
  $wrapper->field_investigators->set();
  if (!empty($investigator_elements)) {
    foreach ($investigator_elements as $index => $investigator_element) {
      $investigator_wrapper = _mica_import_find_or_create_node($investigator_element->getAttribute("ref-uuid"), 'contact', $investigator_element->getAttribute("mica_origin_url"));
      $nid = $investigator_wrapper->nid->value();
      if (empty($nid)) {
        $investigator_wrapper->save();
      }
      $wrapper->field_investigators[$index]->set($investigator_wrapper->nid->value());
    }
  }

  $contact_elements = $xpath->query('/study/contacts/contact');
  $wrapper->field_contacts_ref->set();
  if (!empty($contact_elements)) {
    foreach ($contact_elements as $index => $contact_element) {
      $contact_wrapper = _mica_import_find_or_create_node($contact_element->getAttribute("ref-uuid"), 'contact', $contact_element->getAttribute("mica_origin_url"));
      $nid = $contact_wrapper->nid->value();
      if (empty($nid)) {
        $contact_wrapper->save();
      }
      $wrapper->field_contacts_ref[$index]->set($contact_wrapper->nid->value());
    }
  }

  if (empty($xpath->query('/study/objectives/body')->item(0)->nodeValue)) {
    throw new Exception(t('Study: Field Body description required'));
  }
  else {
    $wrapper->body->set(array(
      'value' => $xpath->query('/study/objectives/body')->item(0)->nodeValue,
      'summary' => $xpath->query('/study/objectives/summary')->item(0)->nodeValue,
      'format' => $xpath->query('/study/objectives/format')->item(0)->nodeValue
    ));
  }

  $website = mica_studies_import_get_node_value($xpath, '/study/web-site');
  $wrapper->field_website->set(empty($website) ? NULL : array('url' => $website));

  $design_elements = $xpath->query('/study/study-designs/designs/design');
  $wrapper->field_design->set();
  if (!empty($design_elements)) {
    foreach ($design_elements as $index => $design_element) {
      $wrapper->field_design[$index]->set($design_element->getAttribute('code'));
    }
  }

  $dom_design_other_sp = $xpath->query('/study/study-designs/designs/other_design');
  $design_other_sp = $dom_design_other_sp->item(0)->nodeValue;
  if (empty($design_other_sp)) {
    $wrapper->field_design_other_sp->set();
  }
  else {
    $wrapper->field_design_other_sp->set(array(
      'value' => $design_other_sp,
      'format' => $dom_design_other_sp->item(0)->getAttribute('format')
    ));
  }

  $dom_info_design_follow_up = $xpath->query('/study/study-designs/general-information-follow-up');
  $info_design_follow_up = $dom_info_design_follow_up->item(0)->nodeValue;
  if (empty($info_design_follow_up)) {
    $wrapper->field_info_design_follow_up->set();
  }
  else {
    $wrapper->field_info_design_follow_up->set(array(
      'value' => $info_design_follow_up,
      'format' => $dom_info_design_follow_up->item(0)->getAttribute('format')
    ));
  }

  $target_elements = $xpath->query('/study/study-designs/recruitment-target/target');
  $wrapper->field_recruitment->set();
  if (!empty($target_elements)) {
    foreach ($target_elements as $index => $target_element) {
      $wrapper->field_recruitment[$index]->set($target_element->getAttribute('code'));
    }
  }

  $wrapper->field_recruitment_other_sp->set(mica_studies_import_get_node_value($xpath, '/study/study-designs/recruitment-target/other_target'));

  $dom_recruitment_supp_info = $xpath->query('/study/study-designs/supplementary-information');
  $recruitment_supp_info = $dom_recruitment_supp_info->item(0)->nodeValue;
  if (empty($recruitment_supp_info)) {
    $wrapper->field_recruitment_supp_info->set();
  }
  else {
    $wrapper->field_recruitment_supp_info->set(array(
      'value' => $recruitment_supp_info,
      'format' => $dom_recruitment_supp_info->item(0)->getAttribute('format')
    ));
  }

  $wrapper->field_target_number_participants->set(
    mica_studies_import_get_node_value($xpath, '/study/study-designs/number-participant/target-number-of-participants/number')
  );

  $wrapper->field_no_limits_participants->set(
    mica_studies_import_get_node_value($xpath, '/study/study-designs/number-participant/target-number-of-participants/no-limits') == 'true'
      ? '1'
      : '0');

  $wrapper->field_target_number_biosamples->set(
    mica_studies_import_get_node_value($xpath, '/study/study-designs/number-participant/target-number-of-participants-with-biosamples/number')
  );

  $wrapper->field_no_limits_samples->set(
    mica_studies_import_get_node_value($xpath, '/study/study-designs/number-participant/target-number-of-participants-with-biosamples/no-limits') == 'true'
      ? '1'
      : '0');

  $dom_target_nb_supp_info = $xpath->query('/study/study-designs/number-participant/supplementary-information');
  $target_nb_supp_info = $dom_target_nb_supp_info->item(0)->nodeValue;
  if (empty($target_nb_supp_info)) {
    $wrapper->field_target_nb_supp_info->set();
  }
  else {
    $wrapper->field_target_nb_supp_info->set(array(
      'value' => $target_nb_supp_info,
      'format' => $dom_target_nb_supp_info->item(0)->getAttribute('format')
    ));
  }

  $wrapper->field_study_start_year->set(mica_studies_import_get_node_value($xpath, '/study/study-designs/timeline/start-year'));

  $wrapper->field_study_end_year->set(mica_studies_import_get_node_value($xpath, '/study/study-designs/timeline/end-year'));

  $access_data = mica_studies_import_get_node_value($xpath, '/study/access/data');
  $wrapper->field_access_data->set($access_data == 'true' ? '1' : ($access_data == 'false' ? '0' : NULL));

  $access_biosamples = mica_studies_import_get_node_value($xpath, '/study/access/biosamples');
  $wrapper->field_access_biosamples->set($access_biosamples == 'true' ? '1' : ($access_biosamples == 'false' ? '0' : NULL));

  $access_other = mica_studies_import_get_node_value($xpath, '/study/access/other_access');
  $wrapper->field_access_other->set($access_other == 'true' ? '1' : ($access_other == 'false' ? '0' : NULL));

  $dom_access_other_sp = $xpath->query('/study/access/other-info');
  $access_other_sp = $dom_access_other_sp->item(0)->nodeValue;
  if (empty($access_other_sp)) {
    $wrapper->field_access_other_sp->set();
  }
  else {
    $wrapper->field_access_other_sp->set(array(
      'value' => $access_other_sp,
      'format' => $dom_access_other_sp->item(0)->getAttribute('format')
    ));
  }

  $wrapper->field_marker_paper->set(mica_studies_import_get_node_value($xpath, '/study/maker-paper'));

  $wrapper->field_pubmedid->set(mica_studies_import_get_node_value($xpath, '/study/pubmed-id'));

  $dom_supp_infos = $xpath->query('/study/supplementary-information');
  $supp_infos = $dom_supp_infos->item(0)->nodeValue;
  if (empty($supp_infos)) {
    $wrapper->field_supp_infos->set();
  }
  else {
    $wrapper->field_supp_infos->set(array(
      'value' => $supp_infos,
      'format' => $dom_supp_infos->item(0)->getAttribute('format')
    ));
  }

  $population_elements = $xpath->query('/study/populations/population');
  $wrapper->field_study_populations->set();
  if (!empty($population_elements)) {
    foreach ($population_elements as $index => $population_element) {
      $population_wrapper = _mica_import_find_or_create_node($population_element->getAttribute("ref-uuid"), 'population', $population_element->getAttribute("mica_origin_url"));
      $nid = $population_wrapper->nid->value();
      if (empty($nid)) {
        $population_wrapper->save();
      }
      $wrapper->field_study_populations[$index]->set($population_wrapper->nid->value());
    }
  }

  _mica_import_attach_file($xpath->query('/study/files/documents/document'), 'field_documents', $path, $wrapper);

  $logo_uuid = $xpath->query('/study/files/logo')->item(0)->getAttribute("ref-uuid");
  $wrapper->field_logo->set();
  if (!empty($logo_uuid)) {
    $logo_file_node = _mica_import_copy_file($xpath->query('/study/files/logo')->item(0), $path, 'field_logo');
    $wrapper->field_logo->set(array(
      'fid' => $logo_file_node->fid,
      'description' => $logo_file_node->description,
      'display' => $logo_file_node->display
    ));
  }
}