<?php
/**
 * @file
 * mica_studies_import_population.inc
 */

function   _mica_studies_mica_import_set_population_properties($dom, $wrapper) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;

  //TODO remove this as it already done
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

  $wrapper->title->set($xpath->query('/population/title')->item(0)->nodeValue);
  $wrapper->title_field->set($xpath->query('/population/title')->item(0)->nodeValue);

  $wrapper->body->set(array(
    'value' => $xpath->query('/population/general-information/body')->item(0)->nodeValue,
    'summary' => $xpath->query('/population/general-information/summary')->item(0)->nodeValue,
    'format' => $xpath->query('/population/general-information/format')->item(0)->nodeValue
  ));

  $dce_elements = $xpath->query('/population/data-collection-events/data-collection-event');
  if (!empty($dce_elements)) {
    foreach ($dce_elements as $index => $dce_element) {
      $dce_uuid = $dce_element->getAttribute("ref-uuid");
      $dce_wrapper = _mica_import_find_or_create_node($dce_uuid, 'data_collection_event');
      $nid = $dce_wrapper->nid->value();
      if (empty($nid)) {
        $dce_wrapper->save();
      }
      $wrapper->field_pop_dce[$index]->set($dce_wrapper->nid->value());
    }
  }
  $recruit_sources_element = $xpath->query('/population/recruitment-procedure/sources-of-recruit/source');
  if (!empty($recruit_sources_element)) {
    foreach ($recruit_sources_element as $index => $source_element) {
      $wrapper->field_pop_src_recruit[$index]->set($source_element->getAttribute('code'));
    }
  }

  $general_pop_elements = $xpath->query('/population/recruitment-procedure/general-populations/population');
  if (!empty($general_pop_elements)) {
    foreach ($general_pop_elements as $index => $pop_element) {
      $wrapper->field_pop_general_pop_recruit[$index]->set($pop_element->getAttribute('code'));
    }
  }
  $study_elements = $xpath->query('/population/recruitment-procedure/participants-from-existing-studies/study');
  if (!empty($study_elements)) {
    foreach ($study_elements as $index => $study_element) {
      $wrapper->field_pop_exist_study_part[$index]->set($study_element->nodeValue);
    }
  }
  $specific_pop_elements = $xpath->query('/population/recruitment-procedure/specific-populations/population');
  if (!empty($specific_pop_elements)) {
    foreach ($specific_pop_elements as $index => $pop_element) {
      $wrapper->field_pop_specific_pop[$index]->set($pop_element->getAttribute('code'));
    }
  }

  $other_pop = $xpath->query('/population/recruitment-procedure/specific-populations/other')
    ->item(0)->nodeValue;
  if (!empty($other_pop)) {
    $wrapper->field_pop_specific_pop_other_sp->set(array('value' => $other_pop));
  }
  $other_recruit = $xpath->query('/population/recruitment-procedure/other-recruitment-source')
    ->item(0)->nodeValue;
  if (!empty($other_recruit)) {
    $wrapper->field_pop_recruitment_other->set(array('value' => $other_recruit));
  }

  $recruit_supp_info = $xpath->query('/population/recruitment-procedure/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($recruit_supp_info)) {
    $wrapper->field_pop_recruit_supp_info->set(array('value' => $recruit_supp_info));
  }

  $gender = $xpath->query('/population/characteristics-of-the-population/gender')->item(0)->nodeValue;
  if (!empty($gender)) {
    $wrapper->field_pop_gender->set($gender);
  }

  $age_max = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  if (!empty($age_max)) {
    $wrapper->field_pop_age_max->set($age_max);
  }
  $age_min = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  if (!empty($age_min)) {
    $wrapper->field_pop_age_min->set($age_min);
  }

  $country_elements = $xpath->query('/population/characteristics-of-the-population/countries-of-residence/country');
  if (!empty($country_elements)) {
    foreach ($country_elements as $index => $country_element) {
      $wrapper->field_pop_country[$index]->set($country_element->getAttribute('code'));
    }
  }
  $territory = $xpath->query('/population/characteristics-of-the-population/territory-city-of-residence')
    ->item(0)->nodeValue;
  if (!empty($territory)) {
    $wrapper->field_pop_territory->set(array('value' => $territory));
  }

  $criteria_elements = $xpath->query('/population/characteristics-of-the-population/selections-criteria/criteria');
  if (!empty($criteria_elements)) {
    foreach ($criteria_elements as $index => $criteria_element) {
      $wrapper->field_pop_select_criteria[$index]->set($criteria_element->getAttribute('code'));
    }
  }

  $ethnic_elements = $xpath->query('/population/characteristics-of-the-population/ethnic-origins/ethnic-origin');
  if (!empty($ethnic_elements)) {
    foreach ($ethnic_elements as $index => $ethnic_element) {
      $wrapper->field_pop_ethnic_origin[$index]->set($ethnic_element->nodeValue);
    }
  }

  $health_status_elements = $xpath->query('/population/characteristics-of-the-population/healths-status/status');
  if (!empty($health_status_elements)) {
    foreach ($health_status_elements as $index => $health_status_element) {
      $wrapper->field_pop_health_status[$index]->set($health_status_element->nodeValue);
    }
  }

  $selection_others_sp = $xpath->query('/population/characteristics-of-the-population/other-selection-criteria')
    ->item(0)->nodeValue;
  if (!empty($selection_others_sp)) {
    $wrapper->field_pop_selection_others_sp->set(array('value' => $selection_others_sp));
  }

  $charact_supp_infos = $xpath->query('/population/characteristics-of-the-population/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($charact_supp_infos)) {
    $wrapper->field_pop_partcipant_sel_supp_in->set(array('value' => $charact_supp_infos));
  }
  $nb_participants = $xpath->query('/population/number-participant/target-number-of-participants/number')
    ->item(0)->nodeValue;
  if (!empty($nb_participants)) {
    $wrapper->field_pop_participants_nb->set($nb_participants);
  }

  $wrapper->field_pop_no_limits_participants->set($xpath
    ->query('/population/number-participant/target-number-of-participants/no-limit')->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $number_samples = $xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/number')->item(0)->nodeValue;
  if (!empty($number_samples)) {
    $wrapper->field_pop_participants_nb_s->set($number_samples);
  }

  $wrapper->field_pop_no_lim_participants_s->set($xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/no-limit')
    ->item(0)->nodeValue == 'true'
    ? '1'
    : '0');

  $nb_supp_info = $xpath->query('/population/number-participant/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($nb_supp_info)) {
    $wrapper->field_pop_participants_nb_supp_i->set(array('value' => $nb_supp_info));
  }
  $supp_infos = $xpath->query('/population/supplementary-information')->item(0)->nodeValue;
  if (!empty($supp_infos)) {
    $wrapper->field_pop_supp_infos->set(array('value' => $supp_infos));
  }
}