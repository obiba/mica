<?php
/**
 * @file
 * mica_export_dce.inc
 */

function _mica_studies_export_dto_dce_dto($dto_util, $wrapper) {
  $dce_dto = new obiba\mica\StudyDto\PopulationDto\DataCollectionEventDto();

  $dce_title = $wrapper->title_field->value();
  if (!empty($dce_title)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($dce_dto, 'addName',
      $wrapper, 'title_field');
  }

  $dce_description = $wrapper->body->value();
  if (!empty($dce_description)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($dce_dto, 'addDescription',
      $wrapper, 'body', 'value');
  }

  $dce_dto->setStartYear($wrapper->field_dce_start_year->value());
  $dce_dto->setStartMonth($wrapper->field_dce_start_month->value());
  $dce_dto->setEndYear($wrapper->field_dce_end_year->value());
  $dce_dto->setEndMonth($wrapper->field_dce_end_month->value());

  foreach ($wrapper->field_dce_data_sources->getIterator() as $sources) {
    if (!empty($sources)) {
      $dce_dto->addDataSources($sources->value());
      if ($sources->value() == 'others') {
        $dce_datasource_sp = $wrapper->field_dce_data_sources_sp->value();
        if (!empty($dce_datasource_sp)) {
          $dto_util->_mica_studies_export_dto_add_translated_Field($dce_dto, 'addOtherDataSources',
            $wrapper, 'field_dce_data_sources_sp');
        }
      }
      if ($sources->value() == 'biological_samples') {
        foreach ($wrapper->field_dce_bio_samples_management->getIterator() as $biosample) {
          if (!empty($biosample)) {
            $dce_dto->addBioSamples($biosample->value());
          }
          if ($biosample->value() == 'others') {
            $other_tissue = $wrapper->field_dce_samples_man_other_sp->value();
            if (!empty($other_tissue)) {
              $dto_util->_mica_studies_export_dto_add_translated_Field($dce_dto, 'addOtherBioSamples',
                $wrapper, 'field_dce_samples_man_other_sp', 'value');
            }
          }
          if ($biosample->value() == 'tissues') {
            $dce_tissue_sp = $wrapper->field_dce_tissues_sp->value();
            if (!empty($dce_tissue_sp)) {
              $dto_util->_mica_studies_export_dto_add_translated_Field($dce_dto, 'addTissueTypes',
                $wrapper, 'field_dce_tissues_sp');
            }
          }
        }
      }
      if ($sources->value() == 'administratives_databases') {
        foreach ($wrapper->field_dce_data_sources_admin_db->getIterator() as $admindata) {
          if (!empty($admindata)) {
            $dce_dto->addAdministrativeDatabases($admindata->value());
          }
        }
      }
    }
  }

  foreach ($wrapper->field_dce_data_dictionaries->value() as $attachement) {
    $id_file_server_response = $dto_util->export_file($attachement);
    if (!empty($id_file_server_response)) {
      $attachement_dto = $dto_util->_mica_studies_export_dto_attachement_construct($attachement, $id_file_server_response, $attachement, $dce_dto);

      $dce_dto->addAttachments($attachement_dto);
    }
  }
  return $dce_dto;
}