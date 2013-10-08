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
  $uuid = $current_document->getAttribute("uuid");
  //Can't set mica_origin_url using  wrapper  Error : .. 'Entity property mica_origin_url doesn't support writing
  if (!empty($origin_url)) {
    $nodes = entity_load('node', FALSE, array('uuid' => $uuid));
    foreach ($nodes as $node) {
      $node->mica_origin_url = $origin_url;
      // $node->body['und'][0]['format'] = $xpath->query('/population/general-information/format')->item(0)->nodeValue;
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
    foreach ($dce_elements as $dce_index => $dce_element) {
      $dce_uuid = $dce_element->getAttribute("ref-uuid");
      $dce_wrapper = _mica_import_find_or_create_node($dce_uuid, 'data_collection_event');
      $nid = $dce_wrapper->nid->value();
      if (empty($nid)) {
        $dce_wrapper->save();

      }
      $wrapper->field_pop_dce[$dce_index]->set($dce_wrapper->nid->value());
    }
  }
  $resources_recruitment = $xpath->query('/population/recruitment-procedure/sources-of-recruit/source');
  if (!empty($resources_recruitment)) {
    foreach ($resources_recruitment as $key_resource => $value_resource) {

      $wrapper->field_pop_src_recruit[$key_resource]->set($value_resource->getAttribute('code'));
    }
  }

  $resources_pop_recruit = $xpath->query('/population/recruitment-procedure/general-populations/population');
  if (!empty($resources_pop_recruit)) {
    foreach ($resources_pop_recruit as $key_pop => $value_pop) {
      $wrapper->field_pop_general_pop_recruit[$key_pop]->set($value_pop->getAttribute('code'));
    }
  }
  $resources_study = $xpath->query('/population/recruitment-procedure/participants-from-existing-studies/study');
  if (!empty($resources_study)) {
    foreach ($resources_study as $key_recrut_study => $value_recrut_study) {
      $wrapper->field_pop_exist_study_part[$key_recrut_study]->set($value_recrut_study->nodeValue);
    }
  }
  $pop_specific_pops = $xpath->query('/population/recruitment-procedure/specific-populations/population');
  if (!empty($pop_specific_pops)) {
    foreach ($pop_specific_pops as $key_spec_pop => $value_spec_pop) {
      $wrapper->field_pop_specific_pop[$key_spec_pop]->set($value_spec_pop->getAttribute('code'));
    }
  }

  $pop_specific_pop_other_sp = $xpath->query('/population/recruitment-procedure/specific-populations/other')
    ->item(0)->nodeValue;
  if (!empty($pop_specific_pop_other_sp)) {
    $wrapper->field_pop_specific_pop_other_sp->set(array('value' => $pop_specific_pop_other_sp));
  }
  $pop_recruitment_other = $xpath->query('/population/recruitment-procedure/other-recruitment-source')
    ->item(0)->nodeValue;
  if (!empty($pop_recruitment_other)) {
    $wrapper->field_pop_recruitment_other->set(array('value' => $pop_recruitment_other));
  }

  $op_recruit_supp_info = $xpath->query('/population/recruitment-procedure/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($op_recruit_supp_info)) {
    $wrapper->field_pop_recruit_supp_info->set(array('value' => $op_recruit_supp_info));
  }

  $pop_gender = $xpath->query('/population/characteristics-of-the-population/gender')->item(0)->nodeValue;
  if (!empty($pop_gender)) {
    $wrapper->field_pop_gender->set($pop_gender);
  }

  $pop_age_max = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  if (!empty($pop_gender)) {
    $wrapper->field_pop_age_max->set($pop_age_max);
  }
  $pop_age_min = $xpath->query('/population/characteristics-of-the-population/age/max-age')->item(0)->nodeValue;
  if (!empty($pop_age_min)) {
    $wrapper->field_pop_age_min->set($pop_age_min);
  }
  $resources_country = $xpath->query('/population/characteristics-of-the-population/countries-of-residence/country');
  if (!empty($resources_country)) {
    foreach ($resources_country as $key_country => $value_country) {
      $wrapper->field_pop_country[$key_country]->set($value_country->getAttribute('code'));
    }
  }
  $pop_territory = $xpath->query('/population/characteristics-of-the-population/territory-city-of-residence')
    ->item(0)->nodeValue;
  if (!empty($pop_territory)) {
    $wrapper->field_pop_territory->set(array('value' => $pop_territory));
  }

  $resources_criteria = $xpath->query('/population/characteristics-of-the-population/selections-criteria/criteria');
  if (!empty($resources_criteria)) {
    foreach ($resources_criteria as $key_criteria => $value_criteria) {
      $wrapper->field_pop_select_criteria[$key_criteria]->set($value_criteria->getAttribute('code'));
    }
  }

  $resources_ethnic_origin = $xpath->query('/population/characteristics-of-the-population/ethnic-origins/ethnic-origin');
  if (!empty($resources_ethnic_origin)) {
    foreach ($resources_ethnic_origin as $key_ethnic => $value_ethnic) {
      $wrapper->field_pop_ethnic_origin[$key_ethnic]->set($value_ethnic->nodeValue);
    }
  }

  $resources_health_status = $xpath->query('/population/characteristics-of-the-population/healths-status/status');
  if (!empty($resources_health_status)) {
    foreach ($resources_health_status as $key_health_status => $value_health_status) {
      $wrapper->field_pop_health_status[$key_health_status]->set($value_health_status->nodeValue);
    }
  }

  $pop_selection_others_sp = $xpath->query('/population/characteristics-of-the-population/other-selection-criteria')
    ->item(0)->nodeValue;
  if (!empty($pop_selection_others_sp)) {
    $wrapper->field_pop_selection_others_sp->set(array('value' => $pop_selection_others_sp));
  }

  $pop_partcipant_sel_supp_in = $xpath->query('/population/characteristics-of-the-population/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($pop_selection_others_sp)) {
    $wrapper->field_pop_partcipant_sel_supp_in->set(array('value' => $pop_partcipant_sel_supp_in));
  }
  $pop_participants_nb = $xpath->query('/population/number-participant/target-number-of-participants/number')
    ->item(0)->nodeValue;
  (!empty($pop_participants_nb)) ? $wrapper->field_pop_participants_nb->set($pop_participants_nb) : NULL;

  $limit_val_part = ($xpath->query('/population/number-participant/target-number-of-participants/no-limit')
    ->item(0)->nodeValue) == 'true' ? '1' : '0';
  $wrapper->field_pop_no_limits_participants->set($limit_val_part);

  $pop_participants_nb_s = $xpath
    ->query('/population/number-participant/target-number-of-participants-with-biosamples/number')->item(0)->nodeValue;
  (!empty($pop_participants_nb_s)) ? $wrapper->field_pop_participants_nb_s->set($pop_participants_nb_s) : NULL;

  $limit_val = ($xpath->query('/population/number-participant/target-number-of-participants-with-biosamples/no-limit')
    ->item(0)->nodeValue) == 'true' ? '1' : '0';
  $wrapper->field_pop_no_lim_participants_s->set($limit_val);

  $pop_participants_nb_supp_i = $xpath->query('/population/number-participant/supplementary-information')
    ->item(0)->nodeValue;
  if (!empty($pop_participants_nb_supp_i)) {
    $wrapper->field_pop_participants_nb_supp_i->set(array('value' => $pop_participants_nb_supp_i));
  }
  $pop_supp_infos = $xpath->query('/population/supplementary-information')->item(0)->nodeValue;
  if (!empty($pop_supp_infos)) {
    $wrapper->field_pop_supp_infos->set(array('value' => $pop_supp_infos));
  }
}