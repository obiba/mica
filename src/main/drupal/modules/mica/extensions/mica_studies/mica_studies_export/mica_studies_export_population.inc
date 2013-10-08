<?php
/**
 * @file
 * mica_export_population.inc
 */

function _mica_studies_export_population_xml($nid) {

  $wrapper = entity_metadata_wrapper('node', $nid);

  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('population');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $dom->appendChild($root);

  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));

  $study_element = $root->appendChild($dom->createElement('study'));
  $study_element->setAttribute('ref-uuid', $wrapper->field_pop_study->uuid->value());

  $gen_info_element = $root->appendChild($dom->createElement('general-information'));
  $gen_info_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $gen_info_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $gen_info_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $dces_element = $root->appendChild($dom->createElement('data-collection-event'));
  foreach ($wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
    $dce_element = $dces_element->appendChild($dom->createElement('data-collection-event'));
    $dce_element->setAttribute('ref-uuid', $dce_wrapper->uuid->value());
  }

  $recruit_proc_element = $root->appendChild($dom->createElement('recruitment-procedure'));

  $source_recru_element = $dom->createElement('source-of-recruit');
  $recruit_proc_element->appendChild($source_recru_element);
  foreach ($wrapper->field_pop_src_recruit->getIterator() as $recruit) {
    $dce_element = $source_recru_element->appendChild($dom->createElement('source'));
    $dce_element->appendChild($dom->createTextNode($recruit->label()));
    $dce_element->setAttribute('code', $recruit->value());
  }

  $gener_popula_element = $dom->createElement('general-population');
  $recruit_proc_element->appendChild($gener_popula_element);
  foreach ($wrapper->field_pop_general_pop_recruit->getIterator() as $popul) {
    $dce_element = $gener_popula_element->appendChild($dom->createElement('population'));
    $dce_element->appendChild($dom->createTextNode($popul->label()));
    $dce_element->setAttribute('code', $popul->value());
  }

  $exist_studies_element = $dom->createElement('participants-from-existing-studies');
  $recruit_proc_element->appendChild($exist_studies_element);
  foreach ($wrapper->field_pop_exist_study_part->getIterator() as $study) {
    $dce_element = $exist_studies_element->appendChild($dom->createElement('study'));
    $dce_element->appendChild($dom->createTextNode($study->value()));
  }

  $specific_population_element = $dom->createElement('specific-population');
  $recruit_proc_element->appendChild($specific_population_element);
  foreach ($wrapper->field_pop_specific_pop->getIterator() as $specpopu) {
    $dce_element = $specific_population_element->appendChild($dom->createElement('population'));
    $dce_element->appendChild($dom->createTextNode($specpopu->label()));
    $dce_element->setAttribute('code', $specpopu->value());
  }
  $specific_population_element->appendChild($dom->createElement('other'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_specific_pop_other_sp->value()));

  $recruit_proc_element->appendChild($dom->createElement('other-recruitment-source'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_recruitment_other->value()));
  $recruit_proc_element->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_recruit_supp_info->value()));

  $charac_population_element = $root->appendChild($dom->createElement('characteristics-of-the-population'));
  $charac_population_element->appendChild($dom->createElement('gender'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_gender->value()));

  $recru_age_element = $dom->createElement('age');
  $recru_age_min_maxelement = $charac_population_element->appendChild($recru_age_element);
  $recru_age_min_maxelement->appendChild($dom->createElement('max-age'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_age_max->value()));
  $recru_age_min_maxelement->appendChild($dom->createElement('min-age'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_age_min->value()));

  $country_resident_element = $dom->createElement('countries-of-residence');
  $charac_population_element->appendChild($country_resident_element);
  foreach ($wrapper->field_pop_country->getIterator() as $country) {
    $dce_element = $country_resident_element->appendChild($dom->createElement('country'));
    $dce_element->appendChild($dom->createTextNode($country->label()));
    $dce_element->setAttribute('code', $country->value());
  }

  $charac_population_element->appendChild($dom->createElement('territory-city-of-residence'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_territory->value()));

  $sect_criteria_element = $dom->createElement('selection-criteria');
  $charac_population_element->appendChild($sect_criteria_element);
  foreach ($wrapper->field_pop_select_criteria->getIterator() as $criteria) {
    $dce_element = $sect_criteria_element->appendChild($dom->createElement('criteria'));
    $dce_element->appendChild($dom->createTextNode($criteria->label()));
    $dce_element->setAttribute('code', $criteria->value());
  }

  $ethnic_origin_element = $dom->createElement('ethnic-origins');
  $charac_population_element->appendChild($ethnic_origin_element);
  foreach ($wrapper->field_pop_ethnic_origin->value() as $ethnic) {
    $dce_element = $ethnic_origin_element->appendChild($dom->createElement('ethnic-origin'));
    $dce_element->appendChild($dom->createTextNode($ethnic));
  }

  $health_status_element = $dom->createElement('health-status');
  $charac_population_element->appendChild($health_status_element);
  foreach ($wrapper->field_pop_health_status->value() as $health) {
    $dce_element = $health_status_element->appendChild($dom->createElement('status'));
    $dce_element->appendChild($dom->createTextNode($health));

  }

  $charac_population_element->appendChild($dom->createElement('other-selection-criteria'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_selection_others_sp->value()));
  $charac_population_element->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_partcipant_sel_supp_in->value()));

  $partic_numb__element = $root->appendChild($dom->createElement('number-participant'));

  $target_number_element = $dom->createElement('target-number-of-participants');
  $partic_numb__element->appendChild($target_number_element);
  $target_number_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_participants_nb->value()));
  $target_number_element->appendChild($dom->createElement('no-limit'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_no_limits_participants->value() ? 'true' : 'false'));

  $target_number_biosample_element = $dom->createElement('target-number-of-participants-with-biosamples');
  $partic_numb__element->appendChild($target_number_biosample_element);
  $target_number_biosample_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_participants_nb_s->value()));
  $target_number_biosample_element->appendChild($dom->createElement('no-limit'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_no_lim_participants_s->value() ? 'true' : 'false'));

  $partic_numb__element->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_participants_nb_supp_i->value()));

  $root->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_supp_infos->value()));

  return $dom->saveXML();
}