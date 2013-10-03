<?php
/**
 * @file
 * mica_studies_import_population.inc
 */

function   _mica_studies_mica_import_set_population_properties($dom, $wrapper) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;
  $origin_url = $current_document->getAttribute("mica_origin_url");
  if (empty($wrapper->mica_origin_url)) {
    $wrapper->mica_origin_url->set($origin_url);
  }
  $wrapper->title->set($xpath->query('/population/title')->item(0)->nodeValue);
  $wrapper->title_field->set($xpath->query('/population/title')->item(0)->nodeValue);

  $wrapper->body->value->set($xpath->query('/population/general-information/body')->item(0)->nodeValue);
  $wrapper->body->summary->set($xpath->query('/population/general-information/summary')->item(0)->nodeValue);
  // $wrapper->body->format->set($xpath->query('/population/general-information/format')->item(0)->nodeValue);

  $dce_elements = $xpath->query('/population/data-collection-events/data-collection-event');
  foreach ($dce_elements as $index => $dce_element) {
    $dce_uuid = $dce_element->getAttribute("ref-uuid");
    $dce_wrapper = _mica_import_find_or_create_node($dce_uuid, 'data_collection_event');
    if ($dce_wrapper !== FALSE) {
      $nid = $dce_wrapper->nid->value();
      if (empty($nid)) {
        $dce_wrapper->save();
      }
      else {
        $wrapper->field_pop_dce[$index]->set($dce_wrapper->nid->value());
        $dce_wrapper->save();
      }
    }
    else {
      watchdog('mica studio import', t('can\'t set  dce nid => you don\'t have permission to edit/create data_collection_event</ br>'), array(), WATCHDOG_WARNING);
      return $wrapper;

    }
  }

  $resources_recruitment = $xpath->query('/population/recruitment-procedure/sources-of-recruit/source');
  foreach ($resources_recruitment as $key_resource => $value_resource) {

    $wrapper->field_pop_src_recruit[$key_resource]->set($value_resource->getAttribute('code'));
  }
  $resources_pop_recruit = $xpath->query('/population/recruitment-procedure/general-populations/population');
  foreach ($resources_pop_recruit as $key_pop => $value_pop) {
    $wrapper->field_pop_general_pop_recruit[$key_pop]->set($value_pop->getAttribute('code'));
  }

  $resources_study = $xpath->query('/population/recruitment-procedure/participants-from-existing-studies/study');
  foreach ($resources_study as $key_recrut_study => $value_recrut_study) {
    $wrapper->field_pop_exist_study_part[$key_recrut_study]->set($value_recrut_study->nodeValue);
  }

  $resources_study = $xpath->query('/population/recruitment-procedure/specific-populations/population');
  foreach ($resources_study as $key_spec_pop => $value_spec_pop) {
    $wrapper->field_pop_specific_pop[$key_spec_pop]->set($value_spec_pop->getAttribute('code'));
  }

  $wrapper->field_pop_specific_pop_other_sp->set(array(
    'value' => $xpath
      ->query('/population/recruitment-procedure/specific-populations/other')->item(0)->nodeValue
  ));

  $wrapper->field_pop_recruitment_other->set(array(
    'value' => $xpath->query('/population/recruitment-procedure/other-recruitment-source')
      ->item(0)->nodeValue
  ));

  $wrapper->field_pop_recruit_supp_info->set(array(
    'value' => $xpath
      ->query('/population/recruitment-procedure/supplementary-information')->item(0)->nodeValue
  ));

  $wrapper->field_pop_gender->set($xpath->query('/population/characteristics-of-the-population/gender')
    ->item(0)->nodeValue);

  $wrapper->field_pop_age_max->set($xpath->query('/population/characteristics-of-the-population/age/max-age')
    ->item(0)->nodeValue);

  $wrapper->field_pop_age_min->set($xpath->query('/population/characteristics-of-the-population/age/max-age')
    ->item(0)->nodeValue);

  $resources_country = $xpath->query('/population/characteristics-of-the-population/countries-of-residence/country');
  foreach ($resources_country as $key_country => $value_country) {
    $wrapper->field_pop_country[$key_country]->set($value_country->getAttribute('code'));
  }

  $wrapper->field_pop_territory->set(array(
    'value' => $xpath
      ->query('/population/characteristics-of-the-population/territory-city-of-residence')->item(0)->nodeValue
  ));

  $resources_criteria = $xpath->query('/population/characteristics-of-the-population/selections-criteria/criteria');
  foreach ($resources_criteria as $key_criteria => $value_criteria) {
    $wrapper->field_pop_select_criteria[$key_criteria]->set($value_criteria->getAttribute('code'));
  }

  $resources_ethnic_origin = $xpath->query('/population/characteristics-of-the-population/ethnic-origins/ethnic-origin');
  foreach ($resources_ethnic_origin as $key_ethnic => $value_ethnic) {
    $wrapper->field_pop_ethnic_origin[$key_ethnic]->set($value_ethnic->nodeValue);
  }
  $resources_health_status = $xpath->query('/population/characteristics-of-the-population/healths-status/status');
  foreach ($resources_health_status as $key_health_status => $value_health_status) {
    $wrapper->field_pop_health_status[$key_health_status]->set($value_health_status->nodeValue);
  }

  $wrapper->field_pop_selection_others_sp->set(array(
    'value' => $xpath
      ->query('/population/characteristics-of-the-population/other-selection-criteria')->item(0)->nodeValue
  ));

  $wrapper->field_pop_partcipant_sel_supp_in->set(array(
    'value' => $xpath
      ->query('/population/characteristics-of-the-population/supplementary-information')->item(0)->nodeValue
  ));

  $wrapper->field_pop_participants_nb->set($xpath
    ->query('/population/number-participant/target-number-of-participants/number')->item(0)->nodeValue);
  $limit_val_part = ($xpath->query('/population/number-participant/target-number-of-participants/no-limit')
    ->item(0)->nodeValue) == 'true' ? '1' : '0';
  $wrapper->field_pop_no_limits_participants->set($limit_val_part);
  $wrapper->field_pop_participants_nb_s->set($xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/number')->item(0)->nodeValue);
  $limit_val = ($xpath->query('/population/number-participant/target-number-of-participants-with-biosamples/no-limit')
    ->item(0)->nodeValue) == 'true' ? '1' : '0';
  $wrapper->field_pop_no_lim_participants_s->set($limit_val);

  $wrapper->field_pop_participants_nb_supp_i->set(array(
    'value' => $xpath
      ->query('/population/number-participant/supplementary-information')->item(0)->nodeValue
  ));

  $wrapper->field_pop_supp_infos->set(array(
    'value' => $xpath->query('/population/supplementary-information')
      ->item(0)->nodeValue
  ));
}