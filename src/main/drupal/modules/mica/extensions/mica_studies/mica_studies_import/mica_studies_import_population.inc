<?php
/**
 * @file
 * mica_studies_import_population.inc
 */

function   _mica_studies_mica_import_set_population_properties($dom, $wrapper) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);

  //Required field
  if (!empty($xpath->query('/population/title')->item(0)->nodeValue)) {
    $wrapper->title->set($xpath->query('/population/title')->item(0)->nodeValue);
    $wrapper->title_field->set($xpath->query('/population/title')->item(0)->nodeValue);
  }
  else {
    try {
      $wrapper->title->set();
      $wrapper->title_field->set();
    } catch (Exception $e) {
      throw new Exception(t('Population : Field title required'));
    }

  }

  if (!empty($xpath->query('/population/general-information/body')->item(0)->nodeValue)) {
    $wrapper->body->set(array(
      'value' => $xpath->query('/population/general-information/body')->item(0)->nodeValue,
      'summary' => $xpath->query('/population/general-information/summary')->item(0)->nodeValue,
      'format' => $xpath->query('/population/general-information/format')->item(0)->nodeValue
    ));
  }
  else {
    try {
      $wrapper->body->set();
    } catch (Exception $e) {
      throw new Exception(t('Population : Field Body description required'));
    }
  }

  $dce_elements = $xpath->query('/population/data-collection-events/data-collection-event');
  $wrapper->field_pop_dce->set();
  if (!empty($dce_elements)) {
    foreach ($dce_elements as $index_dce_elements => $dce_element) {
      $dce_wrapper = _mica_import_find_or_create_node($dce_element->getAttribute("ref-uuid"), 'data_collection_event', $dce_element->getAttribute("mica_origin_url"));
      $nid = $dce_wrapper->nid->value();
      if (empty($nid)) {
        $dce_wrapper->save();
      }
      $wrapper->field_pop_dce[$index_dce_elements]->set($dce_wrapper->nid->value());
    }
  }

  $recruit_sources_element = $xpath->query('/population/recruitment-procedure/sources-of-recruit/source');
  $wrapper->field_pop_src_recruit->set();
  if (!empty($recruit_sources_element)) {
    foreach ($recruit_sources_element as $index_recruit_sources_element => $source_element) {
      $wrapper->field_pop_src_recruit[$index_recruit_sources_element]->set($source_element->getAttribute('code'));
    }
  }

  $general_pop_elements = $xpath->query('/population/recruitment-procedure/general-populations/population');
  $wrapper->field_pop_general_pop_recruit->set();
  if (!empty($general_pop_elements)) {
    foreach ($general_pop_elements as $index_general_pop_elements => $pop_element) {
      $wrapper->field_pop_general_pop_recruit[$index_general_pop_elements]->set($pop_element->getAttribute('code'));
    }
  }
  $study_elements = $xpath->query('/population/recruitment-procedure/participants-from-existing-studies/study');
  $wrapper->field_pop_exist_study_part->set();
  if (!empty($study_elements)) {
    foreach ($study_elements as $index_study_elements => $study_element) {
      $wrapper->field_pop_exist_study_part[$index_study_elements]->set($study_element->nodeValue);
    }
  }
  $specific_pop_elements = $xpath->query('/population/recruitment-procedure/specific-populations/population');
  $wrapper->field_pop_specific_pop->set();
  if (!empty($specific_pop_elements)) {
    foreach ($specific_pop_elements as $index_specific_pop_elements => $pop_element) {
      $wrapper->field_pop_specific_pop[$index_specific_pop_elements]->set($pop_element->getAttribute('code'));
    }
  }

  $dom_pop_specific_pop_other_sp = $xpath->query('/population/recruitment-procedure/specific-populations/other');
  $pop_specific_pop_other_sp = $dom_pop_specific_pop_other_sp->item(0)->nodeValue;
  $wrapper->field_pop_specific_pop_other_sp->set();
  if (!empty($pop_specific_pop_other_sp)) {
    $wrapper->field_pop_specific_pop_other_sp->set(array(
      'value' => $pop_specific_pop_other_sp,
      'format' => $dom_pop_specific_pop_other_sp->item(0)->getAttribute('format')
    ));
  }

  $dom_pop_recruitment_other = $xpath->query('/population/recruitment-procedure/other-recruitment-source');
  $pop_recruitment_other = $dom_pop_recruitment_other->item(0)->nodeValue;
  $wrapper->field_pop_recruitment_other->set();
  if (!empty($pop_recruitment_other)) {
    $wrapper->field_pop_recruitment_other->set(array(
      'value' => $pop_recruitment_other,
      'format' => $dom_pop_recruitment_other->item(0)->getAttribute('format')
    ));
  }

  $dom_pop_recruit_supp_info = $xpath->query('/population/recruitment-procedure/supplementary-information');
  $pop_recruit_supp_info = $dom_pop_recruit_supp_info->item(0)->nodeValue;
  $wrapper->field_pop_recruitment_other->set();
  if (!empty($pop_recruit_supp_info)) {
    $wrapper->field_pop_recruitment_other->set(array(
      'value' => $pop_recruit_supp_info,
      'format' => $dom_pop_recruit_supp_info->item(0)->getAttribute('format')
    ));
  }

  $gender = $xpath->query('/population/characteristics-of-the-population/gender')->item(0)->nodeValue;
  $wrapper->field_pop_gender->set();
  if (!empty($gender)) {
    $wrapper->field_pop_gender->set($gender);
  }
  $age_max = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  $wrapper->field_pop_age_max->set();
  if (!empty($age_max)) {
    $wrapper->field_pop_age_max->set($age_max);
  }
  $age_min = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  $wrapper->field_pop_age_min->set();
  if (!empty($age_min)) {
    $wrapper->field_pop_age_min->set($age_min);
  }

  $country_elements = $xpath->query('/population/characteristics-of-the-population/countries-of-residence/country');
  $wrapper->field_pop_country->set();
  if (!empty($country_elements)) {
    foreach ($country_elements as $index_country_elements => $country_element) {
      $wrapper->field_pop_country[$index_country_elements]->set($country_element->getAttribute('code'));
    }
  }

  $dom_pop_territory = $xpath->query('/population/characteristics-of-the-population/territory-city-of-residence');
  $pop_territory = $dom_pop_territory->item(0)->nodeValue;
  $wrapper->field_pop_territory->set();
  if (!empty($pop_territory)) {
    $wrapper->field_pop_territory->set(array(
      'value' => $pop_territory,
      'format' => $dom_pop_territory->item(0)->getAttribute('format')
    ));
  }

  $criteria_elements = $xpath->query('/population/characteristics-of-the-population/selections-criteria/criteria');
  $wrapper->field_pop_select_criteria->set();
  if (!empty($criteria_elements)) {
    foreach ($criteria_elements as $index_criteria_elements => $criteria_element) {
      $wrapper->field_pop_select_criteria[$index_criteria_elements]->set($criteria_element->getAttribute('code'));
    }
  }

  $ethnic_elements = $xpath->query('/population/characteristics-of-the-population/ethnic-origins/ethnic-origin');
  $wrapper->field_pop_ethnic_origin->set();
  if (!empty($ethnic_elements)) {
    foreach ($ethnic_elements as $index_ethnic_element => $ethnic_element) {
      $wrapper->field_pop_ethnic_origin[$index_ethnic_element]->set($ethnic_element->nodeValue);
    }
  }

  $health_status_elements = $xpath->query('/population/characteristics-of-the-population/healths-status/status');
  $wrapper->field_pop_health_status->set();
  if (!empty($health_status_elements)) {
    foreach ($health_status_elements as $index_health_status_elements => $health_status_element) {
      $wrapper->field_pop_health_status[$index_health_status_elements]->set($health_status_element->nodeValue);
    }
  }

  $dom_selection_others_sp = $xpath->query('/population/characteristics-of-the-population/other-selection-criteria');
  $selection_others_sp = $dom_selection_others_sp->item(0)->nodeValue;
  $wrapper->field_pop_selection_others_sp->set();
  if (!empty($selection_others_sp)) {
    $wrapper->field_pop_selection_others_sp->set(array(
      'value' => $selection_others_sp,
      'format' => $dom_selection_others_sp->item(0)->getAttribute('format')
    ));
  }

  $dom_pop_partcipant_sel_supp_in = $xpath->query('/population/characteristics-of-the-population/supplementary-information');
  $pop_partcipant_sel_supp_in = $dom_pop_partcipant_sel_supp_in->item(0)->nodeValue;
  $wrapper->field_pop_partcipant_sel_supp_in->set();
  if (!empty($pop_partcipant_sel_supp_in)) {
    $wrapper->field_pop_partcipant_sel_supp_in->set(array(
      'value' => $pop_partcipant_sel_supp_in,
      'format' => $dom_pop_partcipant_sel_supp_in->item(0)->getAttribute('format')
    ));
  }

  $nb_participants = $xpath->query('/population/number-participant/target-number-of-participants/number')
    ->item(0)->nodeValue;
  $wrapper->field_pop_participants_nb->set();
  if (!empty($nb_participants)) {
    $wrapper->field_pop_participants_nb->set($nb_participants);
  }

  $wrapper->field_pop_no_limits_participants->set($xpath
    ->query('/population/number-participant/target-number-of-participants/no-limit')->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $number_samples = $xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/number')->item(0)->nodeValue;
  $wrapper->field_pop_participants_nb_s->set();
  if (!empty($number_samples)) {
    $wrapper->field_pop_participants_nb_s->set($number_samples);
  }

  $wrapper->field_pop_no_lim_participants_s->set($xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/no-limit')
    ->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $dom_pop_participants_nb_supp_i = $xpath->query('/population/number-participant/supplementary-information');
  $pop_participants_nb_supp_i = $dom_pop_participants_nb_supp_i->item(0)->nodeValue;
  $wrapper->field_pop_participants_nb_supp_i->set();
  if (!empty($pop_participants_nb_supp_i)) {
    $wrapper->field_pop_participants_nb_supp_i->set(array(
      'value' => $pop_participants_nb_supp_i,
      'format' => $dom_pop_participants_nb_supp_i->item(0)->getAttribute('format')
    ));
  }

  $dom_pop_supp_infos = $xpath->query('/population/supplementary-information');
  $pop_supp_infos = $dom_pop_supp_infos->item(0)->nodeValue;
  $wrapper->field_pop_supp_infos->set();
  if (!empty($pop_supp_infos)) {
    $wrapper->field_pop_supp_infos->set(array(
      'value' => $pop_supp_infos,
      'format' => $dom_pop_supp_infos->item(0)->getAttribute('format')
    ));
  }

}