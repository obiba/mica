<?php
/**
 * @file
 * mica_export_dce.inc
 */

function _mica_studies_export_dto_dce_dto($dto_util, $wrapper) {
  $population_dto = new obiba\mica\StudyDto\PopulationDto\DataCollectionEventDto();

  $dce_title = $wrapper->title_field->value();
  if(!empty($dce_title)){$dto_util->_mica_studies_export_dto_add_translated_Field($population_dto, 'addName',
    $wrapper, 'title_field');
  }

  $dce_description = $wrapper->body->value();
  if(!empty($dce_description)){$dto_util->_mica_studies_export_dto_add_translated_Field($population_dto, 'addDescription',
    $wrapper, 'body', 'value');
  }

  $population_dto->setStartYear($wrapper->field_dce_start_year->value());
  $population_dto->setStartMonth($wrapper->field_dce_start_month->value());
  $population_dto->setEndYear($wrapper->field_dce_end_year->value());
  $population_dto->setEndMonth($wrapper->field_dce_end_month->value());

  foreach ($wrapper->field_dce_data_sources->getIterator() as $sources) {
    if (!empty($sources)) {
      $population_dto->addDataSources($sources->value());
      if ($sources->value() == 'others') {
        $dce_datasource_sp = $wrapper->field_dce_data_sources_sp->value();
        if(!empty($dce_datasource_sp)){
          $dto_util->_mica_studies_export_dto_add_translated_Field($population_dto, 'addOtherDataSources',
            $wrapper, 'field_dce_data_sources_sp');
          }
      }
      if ($sources->value() == 'biological_samples') {
        foreach ($wrapper->field_dce_bio_samples_management->getIterator() as $biosample) {
          if (!empty($biosample)) {
            $population_dto->addBioSamples($biosample->value());
          }
          if ($biosample->value() == 'others') {
            $other_tissue = $wrapper->field_dce_samples_man_other_sp->value();
           if(!empty($other_tissue)){
              $dto_util->_mica_studies_export_dto_add_translated_Field($population_dto, 'addOtherBioSamples',
                $wrapper, 'field_dce_samples_man_other_sp', 'value');
           }
          }
          if ($biosample->value() == 'tissues') {
            $dce_tissue_sp = $wrapper->field_dce_tissues_sp->value();
            if(!empty($dce_tissue_sp)){
              $dto_util->_mica_studies_export_dto_add_translated_Field($population_dto, 'addTissueTypes',
                $wrapper, 'field_dce_tissues_sp');
            }
          }
        }
      }
      if ($sources->value() == 'administratives_databases') {
        foreach ($wrapper->field_dce_data_sources_admin_db->getIterator() as $admindata) {
          if (!empty($admindata)) {
            $population_dto->addAdministrativeDatabases($admindata->value());
          }
        }
      }
    }
  }
  //@TODO deal with attachement files
/////////////////////////////////////
  return $population_dto;
}