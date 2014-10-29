<?php
/**
 * @file
 * mica_studies_export_json_dataset.inc
 */
$path_module_protobuf = drupal_get_path('module', 'obiba_protobuf');
include_once($path_module_protobuf . '/protobuf/Protobuf.php');
use \DrSlump\Protobuf;

Protobuf::autoload();

function _mica_studies_export_json_dataset_dto($node, &$context) {
  $dataset_gen_dto = NULL;
  $dataset_type_parse = NULL;
  $resource_serv = NULL;
  $node_type = NULL;
  $wrapper_study = entity_metadata_wrapper('node', $node);

  $dto_util = new QuerySendDto();
  $datasets_to_file_save = array();

  foreach ($wrapper_study->mica_dataset->getIterator() as $dataset) {
    $dataset_name = $dataset->title->value();
    $dce_population_find_param = array(
      'study' => $wrapper_study,
      'datasetId' => $dataset->uuid->value()
    );
    $connector = mica_connector_query($dataset->getIdentifier(), $node->nid);

    if ($dataset->field_dataset_type->value() == 'harmonization') {

      $dataset_gen_dto = _mica_mica_studies_export_json_dataset_harmonized($wrapper_study,
        $connector->options, $dce_population_find_param, $dataset_name);

      $dataset_type_parse = "obiba.mica.HarmonizationDatasetDto.type";
    }

    elseif ($dataset->field_dataset_type->value() == 'study') {
      $dataset_gen_dto = _mica_mica_studies_export_json_dataset_study($wrapper_study,
        $connector->options, $dce_population_find_param, $dataset_name);
      $dataset_type_parse = "obiba.mica.StudyDatasetDto.type";
    }

    $dataset_dto = new \obiba\mica\DatasetDto;
    $dataset_dto->setPublished(FALSE);

    $dto_util->_mica_studies_export_json_add_translated_Field($dataset_dto, 'addName', $dataset, 'title');
    $dto_util->_mica_studies_export_json_add_translated_Field($dataset_dto, 'setDescription', $dataset, 'body', 'value');
    $dataset_dto->setEntityType('Participant');
    $dataset_dto[$dataset_type_parse] = $dataset_gen_dto;

    $raw_response = $dataset->uuid->value();
    $dataset_dto->setId($raw_response);
    //Create  dataset
    $codec = new \DrSlump\Protobuf\Codec\Json();
    $dataset_dto_json = $dataset_dto->serialize($codec);

    $datasets_to_file_save[] = array(
      'uuid' => $raw_response,
      'title_dataset' => $dataset->title->value(),
      'dataset_json' => $dataset_dto_json
    );
  }
  $context['results']['datasets'] = $datasets_to_file_save;
}

function _mica_studies_export_json_get_dce_populations_id($study_wrapper, $dataset_id) {
  foreach ($study_wrapper->field_study_populations->getIterator() as $population) {
    foreach ($population->field_pop_dce->getIterator() as $dce) {
      $dce_id = $dce->uuid->value();
      $population_id = $population->uuid->value();

      $array_id = array(
        'populationId' => $population_id,
        'dceId' => $dce_id
      );
      foreach ($dce->field_dce_dataset->getIterator() as $datasets_dce) {
        if ($datasets_dce->uuid->value() == $dataset_id) {
          return $array_id;
        }
      }

    }
  }
  return FALSE;
}

function _mica_mica_studies_export_json_dataset_harmonized($study_wrapper, $conector_options, $dce_population_find_param = NULL, $dataset_name) {
  $acronym_study = $study_wrapper->field_acroym->value();
  $project = !empty($conector_options) ? $conector_options['datasource'] :
    !empty($acronym_study) ? $acronym_study : $study_wrapper->title_field->value();
  $table = !empty($conector_options) ? $conector_options['table'] : $dataset_name;
  $datset_harmo_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_harmo_dto = new \obiba\mica\HarmonizationDatasetDto;

  $datset_harmo_st_dto->setPopulationId('novalue');
  $datset_harmo_st_dto->setDataCollectionEventId('novalue');
  if (!empty($dce_population_find_param)) {
    $ids = _mica_studies_export_json_get_dce_populations_id($dce_population_find_param['study'], $dce_population_find_param['datasetId']);
    if (!empty($ids['dceId'])) {
      $datset_harmo_st_dto->setPopulationId($ids['populationId']);
      $datset_harmo_st_dto->setDataCollectionEventId($ids['dceId']);
    }
  }
  $datset_harmo_st_dto->setStudyId($study_wrapper->uuid->value());
  $datset_harmo_st_dto->setProject($project);
  $datset_harmo_st_dto->setTable($table);

  $datset_harmo_dto->addStudyTables($datset_harmo_st_dto);

  $datset_harmo_dto->setProject('mica');
  $datset_harmo_dto->setTable($table);
  return $datset_harmo_dto;
}

function _mica_mica_studies_export_json_dataset_study($study_wrapper, $conector_options, $dce_population_find_param = NULL, $dataset_name) {
  $acronym_study = $study_wrapper->field_acroym->value();
  $project = !empty($conector_options) ? $conector_options['datasource'] :
    !empty($acronym_study) ? $acronym_study : $study_wrapper->title_field->value();
  $table = !empty($conector_options) ? $conector_options['table'] : $dataset_name;
  $datset_study_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_study_st_dto->setPopulationId('novalue');
  $datset_study_st_dto->setDataCollectionEventId('novalue');
  if (!empty($dce_population_find_param)) {
    $ids = _mica_studies_export_json_get_dce_populations_id($dce_population_find_param['study'], $dce_population_find_param['datasetId']);
    if (!empty($ids['dceId'])) {
      $datset_study_st_dto->setPopulationId($ids['populationId']);
      $datset_study_st_dto->setDataCollectionEventId($ids['dceId']);
    }
  }
  $datset_study_st_dto->setStudyId($study_wrapper->uuid->value());
  $datset_study_st_dto->setProject($project);
  $datset_study_st_dto->setTable($table);

  $datset_study_dto = new \obiba\mica\StudyDatasetDto;
  $datset_study_dto->setStudyTable($datset_study_st_dto);

  return $datset_study_dto;
}