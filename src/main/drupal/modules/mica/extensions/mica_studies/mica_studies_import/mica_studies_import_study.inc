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

  $investigator = $xpath->query('/study/investigators/investigator');

  foreach ($investigator as $key_investi => $investi_value) {
    $investigar_uuid = $investi_value->getAttribute("ref-uuid");

    $investigator_wrapper = _mica_import_find_or_create_node($investigar_uuid, 'contact');
    if ($investigator_wrapper !== FALSE) {
      $nid = $investigator_wrapper->nid->value();
      if (empty($nid)) {
        $investigator_wrapper->save();
      }
      else {
        $wrapper->field_investigators[$key_investi]->set($investigator_wrapper->nid->value());
        $investigator_wrapper->save();
      }
    }
  }

  $contacts = $xpath->query('/study/contacts/contact');

  foreach ($contacts as $key_contact => $contact_value) {
    $contact_uuid = $contact_value->getAttribute("ref-uuid");
    $contact_wrapper = _mica_import_find_or_create_node($contact_uuid, 'contact');
    if ($contact_wrapper !== FALSE) {
      $nid = $contact_wrapper->nid->value();
      if (empty($nid)) {
        $contact_wrapper->save();
      }
      else {
        $wrapper->field_contacts_ref[$key_contact]->set($contact_wrapper->nid->value());
        $contact_wrapper->save();
      }
    }
  }

  $origin_url = $current_document->getAttribute("mica_origin_url");
  if (empty($wrapper->mica_origin_url)) {
    $wrapper->mica_origin_url->set($origin_url);
  }

  $wrapper->body->set(array(
    'value' => $xpath->query('/study/objectives/body')->item(0)->nodeValue,
    'summary' => $xpath->query('/study/objectives/summary')->item(0)->nodeValue,
    'format' => $xpath->query('/study/objectives/format')->item(0)->nodeValue
  ));

  $wrapper->field_website->set(array('url' => $xpath->query('/study/web-site')->item(0)->nodeValue));

  $study_designs = $xpath->query('/study/study-designs/designs/design');
  foreach ($study_designs as $key_disign => $value_design) {
    $wrapper->field_design[$key_disign]->set($value_design->getAttribute('code'));
  }

  $wrapper->field_design_other_sp->set(array(
    'value' => $xpath->query('/study/study-designs/designs/other')
      ->item(0)->nodeValue
  ));
  $wrapper->field_info_design_follow_up->set(array(
    'value' => $xpath
      ->query('/study/study-designs/general-information-follow-up')->item(0)->nodeValue
  ));

  $study_target = $xpath->query('/study/study-designs/recruitment-target/target');
  foreach ($study_target as $key_target => $value_target) {
    $wrapper->field_recruitment[$key_target]->set($value_target->getAttribute('code'));
  }
  $wrapper->field_recruitment_other_sp->set($xpath->query('/study/study-designs/recruitment-target/other')
    ->item(0)->nodeValue);
  $wrapper->field_recruitment_supp_info->set(array(
    'value' => $xpath
      ->query('/study/study-designs/supplementary-information')->item(0)->nodeValue
  ));

  $wrapper->field_target_number_participants->set($xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants/number')->item(0)->nodeValue);
  $wrapper->field_no_limits_participants->set
    ((($xpath->query('/study/study-designs/number-participant/target-number-of-participants/no-limits')
        ->item(0)->nodeValue) == 'true') ? '1' : '0');
  $wrapper->field_target_number_biosamples->set($xpath
    ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/number')
    ->item(0)->nodeValue);
  $wrapper->field_no_limits_samples->set((($xpath
      ->query('/study/study-designs/number-participant/target-number-of-participants-with-biosamples/no-limits')
      ->item(0)->nodeValue) == 'true') ? '1' : '0');

  $wrapper->field_study_start_year->set($xpath->query('/study/study-designs/timeline/start-year')->item(0)->nodeValue);
  $wrapper->field_study_end_year->set($xpath->query('/study/study-designs/timeline/end-year')->item(0)->nodeValue);

  $wrapper->field_access_data->set($xpath->query('/study/access/data')->item(0)->nodeValue);
  $wrapper->field_access_biosamples->set($xpath->query('/study/access/biosamples')->item(0)->nodeValue);
  $wrapper->field_access_other->set($xpath->query('/study/access/other')->item(0)->nodeValue);
  $wrapper->field_access_other_sp->set(array('value' => $xpath->query('/study/access/other-info')->item(0)->nodeValue));

  $wrapper->field_marker_paper->set($xpath->query('/study/maker-paper')->item(0)->nodeValue);
  $wrapper->field_pubmedid->set($xpath->query('/study/pubmed-id')->item(0)->nodeValue);
  $wrapper->field_supp_infos->set(array(
    'value' => $xpath->query('/study/supplementary-information')
      ->item(0)->nodeValue
  ));

  $populations = $xpath->query('/study/populations/population');

  foreach ($populations as $key_population => $value_population) {
    $population_uuid = $value_population->getAttribute("ref-uuid");
    $population_wrapper = _mica_import_find_or_create_node($population_uuid, 'population');
    if ($population_wrapper !== FALSE) {
      $nid = $population_wrapper->nid->value();
      if (empty($nid)) {
        $population_wrapper->save();
      }
      else {
        $wrapper->field_study_populations[$key_population]->set($population_wrapper->nid->value());
        $population_wrapper->save();
      }
    }
  }

  $documents = $xpath->query('/study/files/documents/document');
  _mica_import_attach_file($documents, 'field_documents', $path, $wrapper);

  $attached_logo = $xpath->query('/study/files/logo')->item(0);
  $file_node = _mica_import_copy_file($attached_logo, $path, 'field_logo');
  if ($file_node !== FALSE) {
    try {
      $wrapper->field_logo->set(array(
        'fid' => $file_node->fid,
        'description' => $file_node->description,
        'display' => $file_node->display
      ));
    } catch (Exception $e) {
      watchdog('mica study import', 'Error  : %error <br /> Field => %field_key <br />  File uuid=> %value_document <br /> node type=> %node <br />', array(
        '%error' => $e,
        '%field_key' => 'field_log',
        '%node' => 'Study',
      ), WATCHDOG_ERROR);
      drupal_set_message(t('Fatal error attaching File : @file  to node : @type',array(
        '@file'=>$attached_logo->getElementsByTagName('filename')->item(0)->nodeValue,
        '@type'=>'Study'
      )),'warning');
      throw $e;
    }
  }
}