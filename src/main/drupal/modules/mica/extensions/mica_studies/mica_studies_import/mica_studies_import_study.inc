<?php
/**
 * @file
 * mica_studies_import_study.inc
 */

function _mica_study_import_set_study_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;
  $wrapper->title->set($xpath->query('/study/title')->item(0)->nodeValue);
  $wrapper->title_field->set($xpath->query('/study/title')->item(0)->nodeValue);
  $wrapper->field_acroym->set($xpath->query('/study/acronym')->item(0)->nodeValue);

  $origin_url = $current_document->getAttribute("mica_origin_url");
  $uuid = $current_document->getAttribute("uuid");
  //Can't set mica_origin_url using  wrapper  Error : .. 'Entity property mica_origin_url doesn't support writing
  if (!empty($origin_url)) {
    $nodes = entity_load('node', FALSE, array('uuid' => $uuid));
    foreach ($nodes as $node) {
      $node->mica_origin_url = $origin_url;
      node_save($node);
    }
  }

  $investigator = $xpath->query('/study/investigators/investigator');
  if (!empty($investigator)) {
    foreach ($investigator as $key_investi => $investi_value) {
      $investigar_uuid = $investi_value->getAttribute("ref-uuid");

      $investigator_wrapper = _mica_import_find_or_create_node($investigar_uuid, 'contact');
      $nid = $investigator_wrapper->nid->value();
      if (empty($nid)) {
        $investigator_wrapper->save();
      }

      $wrapper->field_investigators[$key_investi]->set($investigator_wrapper->nid->value());
    }
  }
  $contacts = $xpath->query('/study/contacts/contact');
  if (!empty($contacts)) {
    foreach ($contacts as $key_contact => $contact_value) {
      $contact_uuid = $contact_value->getAttribute("ref-uuid");
      $contact_wrapper = _mica_import_find_or_create_node($contact_uuid, 'contact');
      $nid = $contact_wrapper->nid->value();
      if (empty($nid)) {
        $contact_wrapper->save();
      }
      $wrapper->field_contacts_ref[$key_contact]->set($contact_wrapper->nid->value());
    }
  }
  $wrapper->body->set(array(
    'value' => $xpath->query('/study/objectives/body')->item(0)->nodeValue,
    'summary' => $xpath->query('/study/objectives/summary')->item(0)->nodeValue,
    'format' => $xpath->query('/study/objectives/format')->item(0)->nodeValue
  ));

  $web_url = $xpath->query('/study/web-site')->item(0)->nodeValue;
  $wrapper->field_website->set(array('url' => $web_url));

  $study_designs = $xpath->query('/study/study-designs/designs/design');
  if (!empty($study_designs)) {
    foreach ($study_designs as $key_disign => $value_design) {
      $wrapper->field_design[$key_disign]->set($value_design->getAttribute('code'));
    }
  }
  $design_other_sp = $xpath->query('/study/study-designs/designs/other')->item(0)->nodeValue;
  if (!empty($design_other_sp)) {
    $wrapper->field_design_other_sp->set(array('value' => $design_other_sp));
  }

  $info_design_follow_up = $xpath->query('/study/study-designs/general-information-follow-up')->item(0)->nodeValue;
  if (!empty($info_design_follow_up)) {
    $wrapper->field_info_design_follow_up->set(array('value' => $info_design_follow_up));
  }

  $study_target = $xpath->query('/study/study-designs/recruitment-target/target');
  if (!empty($info_design_follow_up)) {
    foreach ($study_target as $key_target => $value_target) {
      $wrapper->field_recruitment[$key_target]->set($value_target->getAttribute('code'));
    }
  }

  $recruitment_other_sp = $xpath->query('/study/study-designs/recruitment-target/other')->item(0)->nodeValue;
  if (!empty($recruitment_other_sp)) {
    $wrapper->field_recruitment_other_sp->set($recruitment_other_sp);
  }

  $recruitment_supp_info = $xpath->query('/study/study-designs/supplementary-information')->item(0)->nodeValue;
  if (!empty($recruitment_supp_info)) {
    $wrapper->field_recruitment_supp_info->set(array('value' => $recruitment_supp_info));
  }

  $target_number_participants = $xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants/number')->item(0)->nodeValue;
  (!empty($target_number_participants)) ? $wrapper->field_target_number_participants->set($target_number_participants) : NULL;

  $wrapper->field_no_limits_participants->set
    ((($xpath->query('/study/study-designs/number-participant/target-number-of-participants/no-limits')
        ->item(0)->nodeValue) == 'true') ? '1' : '0');

  $target_number_biosamples = $xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/number')
    ->item(0)->nodeValue;
  if (!empty($target_number_biosamples)) {
    $wrapper->field_target_number_biosamples->set($target_number_biosamples);
  }

  $wrapper->field_no_limits_samples->set((($xpath
      ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/no-limits')
      ->item(0)->nodeValue) == 'true') ? '1' : '0');

  $study_start_year = $xpath->query('/study/study-designs/timeline/start-year')->item(0)->nodeValue;
  if (!empty($study_start_year)) {
    $wrapper->field_study_start_year->set($study_start_year);
  }
  $study_end_year = $xpath->query('/study/study-designs/timeline/end-year')->item(0)->nodeValue;
  if (!empty($study_end_year)) {
    $wrapper->field_study_end_year->set($study_end_year);
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
  $access_other_sp = $xpath->query('/study/access/other-info')->item(0)->nodeValue;
  if (!empty($access_other_sp)) {
    $wrapper->field_access_other_sp->set(array('value' => $access_other_sp));
  }
  $marker_paper = $xpath->query('/study/maker-paper')->item(0)->nodeValue;
  if (!empty($marker_paper)) {
    $wrapper->field_marker_paper->set($marker_paper);
  }
  $pubmedid = $xpath->query('/study/pubmed-id')->item(0)->nodeValue;
  if (!empty($pubmedid)) {
    $wrapper->field_pubmedid->set($pubmedid);
  }
  $supp_infos = $xpath->query('/study/supplementary-information')->item(0)->nodeValue;
  if (!empty($supp_infos)) {
    $wrapper->field_supp_infos->set(array('value' => $supp_infos));
  }
  $populations = $xpath->query('/study/populations/population');
  if (!empty($populations)) {
    foreach ($populations as $key_population => $value_population) {
      $population_uuid = $value_population->getAttribute("ref-uuid");
      $population_wrapper = _mica_import_find_or_create_node($population_uuid, 'population');
      $nid = $population_wrapper->nid->value();
      if (empty($nid)) {
        $population_wrapper->save();
      }
      $wrapper->field_study_populations[$key_population]->set($population_wrapper->nid->value());
    }
  }

  $documents = $xpath->query('/study/files/documents/document');
  _mica_import_attach_file($documents, 'field_documents', $path, $wrapper);

  $attached_logo = $xpath->query('/study/files/logo')->item(0);
  $file_node = _mica_import_copy_file($attached_logo, $path, 'field_logo');
  $wrapper->field_logo->set(array(
    'fid' => $file_node->fid,
    'description' => $file_node->description,
    'display' => $file_node->display
  ));

}