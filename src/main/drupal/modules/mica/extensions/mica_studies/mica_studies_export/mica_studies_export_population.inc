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
  $root->setAttribute('mica_origin_url', $wrapper->mica_origin_url->value());
  $dom->appendChild($root);

  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));

  $root->appendChild($dom->createElement('study'))->setAttribute('ref-uuid', $wrapper->field_pop_study->uuid->value());

  $gen_info_element = $root->appendChild($dom->createElement('general-information'));
  $gen_info_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $gen_info_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $gen_info_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $gen_info_dce = $root->appendChild($dom->createElement('data-collection-events'));
  foreach ($wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
    $element = $gen_info_dce->appendChild($dom->createElement('data-collection-event'));
    $element->setAttribute('ref-uuid', $dce_wrapper->uuid->value());
  }

  $recru_proc_element = $root->appendChild($dom->createElement('recruitment-procedure'));

  $source_recruit_element = $dom->createElement('sources-of-recruit');
  $recru_proc_element->appendChild($source_recruit_element);
  foreach ($wrapper->field_pop_src_recruit->getIterator() as $recruit) {
    $element = $source_recruit_element->appendChild($dom->createElement('source'));
    $element->appendChild($dom->createTextNode($recruit->label()));
    $element->setAttribute('code', $recruit->value());
  }

  $gener_popula_element = $dom->createElement('general-populations');
  $recru_proc_element->appendChild($gener_popula_element);
  foreach ($wrapper->field_pop_general_pop_recruit->getIterator() as $pop) {
    $element = $gener_popula_element->appendChild($dom->createElement('population'));
    $element->appendChild($dom->createTextNode($pop->label()));
    $element->setAttribute('code', $pop->value());
  }

  $exist_sudi_element = $dom->createElement('participants-from-existing-studies');
  $recru_proc_element->appendChild($exist_sudi_element);
  foreach ($wrapper->field_pop_exist_study_part->getIterator() as $study) {
    $element = $exist_sudi_element->appendChild($dom->createElement('study'));
    $element->appendChild($dom->createTextNode($study->value()));
  }

  $specific_population_element = $dom->createElement('specific-populations');
  $recru_proc_element->appendChild($specific_population_element);
  foreach ($wrapper->field_pop_specific_pop->getIterator() as $specpopu) {
    $element = $specific_population_element->appendChild($dom->createElement('population'));
    $element->appendChild($dom->createTextNode($specpopu->label()));
    $element->setAttribute('code', $specpopu->value());
  }

  $pop_specific_pop_other = $wrapper->field_pop_specific_pop_other_sp->value();
  $parent_specific_population_element = $specific_population_element->appendChild($dom->createElement('other'));
  $parent_specific_population_element->appendChild($dom->createTextNode(isset($pop_specific_pop_other) ? $wrapper->field_pop_specific_pop_other_sp->value->value() : ''));
  $parent_specific_population_element->setAttribute('format', isset($pop_specific_pop_other) ? $wrapper->field_pop_specific_pop_other_sp->format->value() : '');

  $pop_recruitmenet_other = $wrapper->field_pop_recruitment_other->value();
  $parent_recru_proc_element = $recru_proc_element->appendChild($dom->createElement('other-recruitment-source'));
  $parent_recru_proc_element->appendChild($dom->createTextNode(isset($pop_recruitmenet_other) ? $wrapper->field_pop_recruitment_other->value->value() : ''));
  $parent_recru_proc_element->setAttribute('format', isset($pop_recruitmenet_other) ? $wrapper->field_pop_recruitment_other->format->value() : '');

  $pop_recruit_supp_info = $wrapper->field_pop_recruit_supp_info->value();
  $parent_recru_proc_element_sup = $recru_proc_element->appendChild($dom->createElement('supplementary-information'));
  $parent_recru_proc_element_sup->appendChild($dom->createTextNode(isset($pop_recruit_supp_info) ? $wrapper->field_pop_recruit_supp_info->value->value() : ''));
  $parent_recru_proc_element_sup->setAttribute('format', isset($pop_recruit_supp_info) ? $wrapper->field_pop_recruit_supp_info->format->value() : '');

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
    $element = $country_resident_element->appendChild($dom->createElement('country'));
    $element->appendChild($dom->createTextNode($country->label()));
    $element->setAttribute('code', $country->value());
  }

  $pop_territory = $wrapper->field_pop_territory->value();
  $parent_charac_population_element = $charac_population_element->appendChild($dom->createElement('territory-city-of-residence'));
  $parent_charac_population_element->appendChild($dom->createTextNode(isset($pop_territory) ? $wrapper->field_pop_territory->value->value() : ''));
  $parent_charac_population_element->setAttribute('format', isset($pop_territory) ? $wrapper->field_pop_territory->format->value() : '');

  $sect_criteria_element = $dom->createElement('selections-criteria');
  $charac_population_element->appendChild($sect_criteria_element);
  foreach ($wrapper->field_pop_select_criteria->getIterator() as $criteria) {
    $element = $sect_criteria_element->appendChild($dom->createElement('criteria'));
    $element->appendChild($dom->createTextNode($criteria->label()));
    $element->setAttribute('code', $criteria->value());
  }

  $ethnic_origin_element = $dom->createElement('ethnic-origins');
  $charac_population_element->appendChild($ethnic_origin_element);
  foreach ($wrapper->field_pop_ethnic_origin->getIterator() as $ethnic) {
    $element = $ethnic_origin_element->appendChild($dom->createElement('ethnic-origin'));
    $element->appendChild($dom->createTextNode($ethnic->value()));
  }

  $health_status_element = $dom->createElement('healths-status');
  $charac_population_element->appendChild($health_status_element);
  foreach ($wrapper->field_pop_health_status->getIterator() as $health) {
    $element = $health_status_element->appendChild($dom->createElement('status'));
    $element->appendChild($dom->createTextNode($health->value()));
  }

  $pop_selection_others = $wrapper->field_pop_selection_others_sp->value();
  $parent_charac_population_element = $charac_population_element->appendChild($dom->createElement('other-selection-criteria'));
  $parent_charac_population_element->appendChild($dom->createTextNode(isset($pop_selection_others) ? $wrapper->field_pop_selection_others_sp->value->value() : ''));
  $parent_charac_population_element->setAttribute('format', isset($pop_selection_others) ? $wrapper->field_pop_selection_others_sp->format->value() : '');

  $pop_partcipant_sel_supp_in = $wrapper->field_pop_partcipant_sel_supp_in->value();
  $parent2_charac_population_element = $charac_population_element->appendChild($dom->createElement('supplementary-information'));
  $parent2_charac_population_element->appendChild($dom->createTextNode(isset($pop_partcipant_sel_supp_in) ? $wrapper->field_pop_partcipant_sel_supp_in->value->value() : ''));
  $parent2_charac_population_element->setAttribute('format', isset($pop_partcipant_sel_supp_in) ? $wrapper->field_pop_partcipant_sel_supp_in->format->value() : '');

  $partic_numb_element = $root->appendChild($dom->createElement('number-participant'));

  $target_number_element = $dom->createElement('target-number-of-participants');
  $partic_numb_element->appendChild($target_number_element);
  $target_number_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_participants_nb->value()));
  $target_number_element->appendChild($dom->createElement('no-limit'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_no_limits_participants->value() ? 'true' : 'false'));

  $target_number_biosample_element = $dom->createElement('target-number-of-participants-with-biosamples');
  $partic_numb_element->appendChild($target_number_biosample_element);
  $target_number_biosample_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_participants_nb_s->value()));
  $target_number_biosample_element->appendChild($dom->createElement('no-limit'))
    ->appendChild($dom->createTextNode($wrapper->field_pop_no_lim_participants_s->value() ? 'true' : 'false'));

  $pop_participants_nb_supp_i = $wrapper->field_pop_participants_nb_supp_i->value();
  $parent_partic_numb_element = $partic_numb_element->appendChild($dom->createElement('supplementary-information'));
  $parent_partic_numb_element->appendChild($dom->createTextNode(isset($pop_participants_nb_supp_i) ? $wrapper->field_pop_participants_nb_supp_i->value->value() : ''));
  $parent_partic_numb_element->setAttribute('format', isset($pop_participants_nb_supp_i) ? $wrapper->field_pop_participants_nb_supp_i->format->value() : '');

  $pop_supp_infos = $wrapper->field_pop_supp_infos->value();
  $parent_pop_supp_infos = $root->appendChild($dom->createElement('supplementary-information'));
  $parent_pop_supp_infos->appendChild($dom->createTextNode(isset($pop_supp_infos) ? $wrapper->field_pop_supp_infos->value->value() : ''));
  $parent_pop_supp_infos->setAttribute('format', isset($pop_supp_infos) ? $wrapper->field_pop_supp_infos->format->value() : '');
  return $dom->saveXML();
}