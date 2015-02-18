<?php
/**
 * @file
 * mica_export_population.inc
 */

function _mica_studies_export_json_population_dto($dto_util, $wrapper, &$context) {

  $population_dto = new obiba\mica\StudyDto\PopulationDto();

  $dto_util->_mica_studies_export_json_add_translated_Field($population_dto, 'addName', $wrapper, 'title_field');

  $dto_util->_mica_studies_export_json_add_translated_Field($population_dto, 'addDescription', $wrapper, 'body', 'value');
  $population_dto->setId($wrapper->uuid->value());
  $recruitment = new \obiba\mica\StudyDto\PopulationDto\RecruitmentDto();

  foreach ($wrapper->field_pop_src_recruit->getIterator() as $recruit) {
    switch ($recruit->value()) {
      case 'general':
        $recruitment->addDataSources('general_population');
        foreach ($wrapper->field_pop_general_pop_recruit->getIterator() as $pop_gen_recrui) {
          $recruitment->addGeneralPopulationSources($pop_gen_recrui->value());
        }
        break;
      case 'exist_studies':
        $recruitment->addDataSources('existing_studies');
        foreach ($wrapper->field_pop_exist_study_part->getIterator() as $index_study => $study) {
          $recruitment->addStudies($dto_util->_set_LocalizedStringDtos($wrapper, 'field_pop_exist_study_part', $index_study));
        }
        break;
      case 'specific_population':
        $recruitment->addDataSources('specific_population');
        foreach ($wrapper->field_pop_specific_pop->getIterator() as $specific_population) {
          $recruitment->addSpecificPopulationSources($specific_population->value());
          if ($specific_population->value() == 'other') {
            $pop_specific_pop_other_sp = $wrapper->field_pop_specific_pop_other_sp->value();
            if (!empty($pop_specific_pop_other_sp)) {
              $dto_util->_mica_studies_export_json_add_translated_Field($recruitment, 'addOtherSpecificPopulationSource',
                $wrapper, 'field_pop_specific_pop_other_sp', 'value');
            }
          }
        }
        break;
      default :
        $recruitment->addDataSources($recruit->value());
        break;
    }
  }

  $sup_info_recrutment = $wrapper->field_pop_recruit_supp_info->value();
  if (!empty($sup_info_recrutment)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($recruitment, 'addInfo',
      $wrapper, 'field_pop_recruit_supp_info', 'value');
  }

  $population_dto->setRecruitment($recruitment);

  $selection_criteria = new obiba\mica\StudyDto\PopulationDto\SelectionCriteriaDto();
  $selection_criteria->setGender($dto_util->_set_gender_to_export_dto($wrapper->field_pop_gender->value()));
  $selection_criteria->setAgeMin($wrapper->field_pop_age_min->value());
  $selection_criteria->setAgeMax($wrapper->field_pop_age_max->value());
  foreach ($wrapper->field_pop_country->getIterator() as $country) {
    $selection_criteria->addCountriesIso($dto_util->_convert_Iso2_to_3($country->value()));
  }

  $sel_crit_territory = $pop_territory = $wrapper->field_pop_territory->value();
  if (!empty($sel_crit_territory)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($selection_criteria,
      'addTerritory', $wrapper, 'field_pop_territory', 'value');
  }

  foreach ($wrapper->field_pop_select_criteria->getIterator() as $criteria) {
    $selection_criteria->addCriteria($criteria->value());
  }

  foreach ($wrapper->field_pop_ethnic_origin->getIterator() as $index_ethnic => $ethnic) {
    $ethnic_origin = $ethnic->value();
    if (!empty($ethnic_origin)) {
      $selection_criteria->addEthnicOrigin($dto_util->_set_LocalizedStringDtos($wrapper, 'field_pop_ethnic_origin', $index_ethnic));
    }
  }

  foreach ($wrapper->field_pop_health_status->getIterator() as $index_health => $health) {
    $health_status = $health->value();
    if (!empty($health_status)) {
      $selection_criteria->addHealthStatus($dto_util->_set_LocalizedStringDtos($wrapper, 'field_pop_health_status', $index_health));
    }
  }

  $other_criteria_other_info = $wrapper->field_pop_selection_others_sp->value();
  if (!empty($other_criteria_other_info)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($selection_criteria, 'addOtherCriteria', $wrapper,
      'field_pop_selection_others_sp', 'value');
  }

  $other_criteria_sup_info = $wrapper->field_pop_partcipant_sel_supp_in->value();
  if (!empty($other_criteria_sup_info)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($selection_criteria,
      'addInfo', $wrapper, 'field_pop_partcipant_sel_supp_in', 'value');
  }

  $participant_sample['number'] = $wrapper->field_pop_participants_nb->value();
  $participant_sample['noLimit'] = $wrapper->field_pop_no_limits_participants->value();
  $biosample['number'] = $wrapper->field_pop_participants_nb_s->value();
  $biosample['noLimit'] = $wrapper->field_pop_no_lim_participants_s->value();
  $population_dto->setNumberOfParticipants(
    mica_studies_export_json_set_number_of_participants($participant_sample,
      $biosample, $wrapper, 'field_pop_participants_nb_supp_i'));

  $population_dto->setSelectionCriteria($selection_criteria);

  $pop_supp_infos = $wrapper->field_pop_supp_infos->value();
  if (!empty($pop_supp_infos)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($population_dto,
      'addInfo', $wrapper, 'field_pop_supp_infos', 'value');
  }

//
  foreach ($wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
    if (!empty($dce_wrapper)) {
      $dce = _mica_studies_export_json_dce_dto($dto_util, $dce_wrapper, $context);
      $population_dto->addDataCollectionEvents($dce);
    }
  }

  return $population_dto;
}