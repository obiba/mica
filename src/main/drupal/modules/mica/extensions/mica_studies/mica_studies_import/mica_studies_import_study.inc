<?php
/**
 * @file
 * mica_studies_import_study.inc
 */

function _mica_study_import_set_study_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $wrapper->title->set($xpath->query('/study/title')->item(0)->nodeValue);
  $wrapper->title_field->set($xpath->query('/study/title')->item(0)->nodeValue);
  $wrapper->field_acroym->set($xpath->query('/study/acronym')->item(0)->nodeValue);

  $investigator_elements = $xpath->query('/study/investigators/investigator');
  if (!empty($investigator_elements)) {
    foreach ($investigator_elements as $index => $investigator_element) {
      $investigator_wrapper = _mica_import_find_or_create_node($investigator_element->getAttribute("ref-uuid"), 'contact',$investigator_element->getAttribute("mica_origin_url"));
      $nid = $investigator_wrapper->nid->value();
      if (empty($nid)) {
        $investigator_wrapper->save();
      }
      $wrapper->field_investigators[$index]->set($investigator_wrapper->nid->value());
    }
  }

  $contact_elements = $xpath->query('/study/contacts/contact');
  if (!empty($contact_elements)) {
    foreach ($contact_elements as $index => $contact_element) {
      $contact_wrapper = _mica_import_find_or_create_node($contact_element->getAttribute("ref-uuid"), 'contact',$contact_element->getAttribute("mica_origin_url"));
      $nid = $contact_wrapper->nid->value();
      if (empty($nid)) {
        $contact_wrapper->save();
      }
      $wrapper->field_contacts_ref[$index]->set($contact_wrapper->nid->value());
    }
  }

  $wrapper->body->set(array(
    'value' => $xpath->query('/study/objectives/body')->item(0)->nodeValue,
    'summary' => $xpath->query('/study/objectives/summary')->item(0)->nodeValue,
    'format' => $xpath->query('/study/objectives/format')->item(0)->nodeValue
  ));

  $wrapper->field_website->set(array('url' => $xpath->query('/study/web-site')->item(0)->nodeValue));

  $design_elements = $xpath->query('/study/study-designs/designs/design');
  if (!empty($design_elements)) {
    foreach ($design_elements as $index => $design_element) {
      $wrapper->field_design[$index]->set($design_element->getAttribute('code'));
    }
  }

  $dom_design_other_sp = $xpath->query('/study/study-designs/designs/other');
  $design_other_sp = $dom_design_other_sp->item(0)->nodeValue;
  if (!empty($design_other_sp)) {
    $wrapper->field_design_other_sp->set(array(
      'value' => $design_other_sp,
      'format' => $dom_design_other_sp->item(0)->getAttribute('format')
    ));
  }

  $dom_info_design_follow_up = $xpath->query('/study/study-designs/general-information-follow-up');
  $info_design_follow_up = $dom_info_design_follow_up->item(0)->nodeValue;
  if (!empty($info_design_follow_up)) {
    $wrapper->field_info_design_follow_up->set(array(
      'value' => $info_design_follow_up,
      'format' => $dom_info_design_follow_up->item(0)->getAttribute('format')
    ));
  }

  $target_elements = $xpath->query('/study/study-designs/recruitment-target/target');
  if (!empty($target_elements)) {
    foreach ($target_elements as $index => $target_element) {
      $wrapper->field_recruitment[$index]->set($target_element->getAttribute('code'));
    }
  }

  if (!empty($target_other)) {
    $wrapper->field_recruitment_other_sp->set($xpath->query('/study/study-designs/recruitment-target/other')->item(0)->nodeValue);
  }

  $dom_recruitment_supp_info = $xpath->query('/study/study-designs/supplementary-information');
  $recruitment_supp_info = $dom_recruitment_supp_info->item(0)->nodeValue;
  if (!empty($recruitment_supp_info)) {
    $wrapper->field_recruitment_supp_info->set(array(
      'value' => $recruitment_supp_info,
      'format' => $dom_recruitment_supp_info->item(0)->getAttribute('format')
    ));
  }

  $number_participants = $xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants/number')->item(0)->nodeValue;
  if (!empty($number_participants)) {
    $wrapper->field_target_number_participants->set($number_participants);
  }

  $wrapper->field_no_limits_participants->set($xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants/no-limits')
    ->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $nb_sample_element = $xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/number')
    ->item(0)->nodeValue;
  if (!empty($nb_sample_element)) {
    $wrapper->field_target_number_biosamples->set($nb_sample_element);
  }

  $wrapper->field_no_limits_samples->set($xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/no-limits')
    ->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $start_year = $xpath->query('/study/study-designs/timeline/start-year')->item(0)->nodeValue;
  if (!empty($start_year)) {
    $wrapper->field_study_start_year->set($start_year);
  }
  $end_year = $xpath->query('/study/study-designs/timeline/end-year')->item(0)->nodeValue;
  if (!empty($end_year)) {
    $wrapper->field_study_end_year->set($end_year);
  }
  $access_data = $xpath->query('/study/access/data')->item(0)->nodeValue;
  if (!empty($access_data)) {
    $wrapper->field_access_data->set($access_data);
  }
  $access_biosamples = $xpath->query('/study/access/biosamples')->item(0)->nodeValue;
  if (!empty($access_biosamples)) {
    $wrapper->field_access_biosamples->set($access_biosamples);
  }
  $access_other = $xpath->query('/study/access/other')->item(0)->nodeValue;
  if (!empty($access_other)) {
    $wrapper->field_access_other->set($access_other);
  }

  $dom_access_other_sp = $xpath->query('/study/access/other-info');
  $access_other_sp = $dom_access_other_sp->item(0)->nodeValue;
  if (!empty($access_other_sp)) {
    $wrapper->field_access_other_sp->set(array(
      'value' => $access_other_sp,
      'format' => $dom_access_other_sp->item(0)->getAttribute('format')
    ));
  }

  $marker_paper = $xpath->query('/study/maker-paper')->item(0)->nodeValue;
  if (!empty($marker_paper)) {
    $wrapper->field_marker_paper->set($marker_paper);
  }
  $pubmedid = $xpath->query('/study/pubmed-id')->item(0)->nodeValue;
  if (!empty($pubmedid)) {
    $wrapper->field_pubmedid->set($pubmedid);
  }

  $dom_supp_infos = $xpath->query('/study/supplementary-information');
  $supp_infos = $dom_supp_infos->item(0)->nodeValue;
  if (!empty($supp_infos)) {
    $wrapper->field_supp_infos->set(array(
      'value' => $supp_infos,
      'format' => $dom_supp_infos->item(0)->getAttribute('format')
    ));
  }

  $population_elements = $xpath->query('/study/populations/population');
  if (!empty($population_elements)) {
    foreach ($population_elements as $index => $population_element) {
      $population_wrapper = _mica_import_find_or_create_node($population_element->getAttribute("ref-uuid"), 'population',$population_element->getAttribute("mica_origin_url"));
      $nid = $population_wrapper->nid->value();
      if (empty($nid)) {
        $population_wrapper->save();
      }
      $wrapper->field_study_populations[$index]->set($population_wrapper->nid->value());
    }
  }

  _mica_import_attach_file($xpath->query('/study/files/documents/document'), 'field_documents', $path, $wrapper);

  $logo_file_node = _mica_import_copy_file($xpath->query('/study/files/logo')->item(0), $path, 'field_logo');
  $wrapper->field_logo->set(array(
    'fid' => $logo_file_node->fid,
    'description' => $logo_file_node->description,
    'display' => $logo_file_node->display
  ));

}