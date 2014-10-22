<?php
/**
 * @file
 * mica_studies_export_dto_dataset.inc
 */
$path_module_protobuf = drupal_get_path('module', 'obiba_protobuf');
include_once($path_module_protobuf . '/protobuf/Protobuf.php');
use \DrSlump\Protobuf;

Protobuf::autoload();

function _mica_studies_export_dto_dataset_dto($node, &$context) {
  $dataset_gen_dto = NULL;
  $dataset_type_parse = NULL;
  $resource_serv = NULL;
  $node_type = NULL;
  $wrapper_study = entity_metadata_wrapper('node', $node);

  $dto_util = new QuerySendDto();
  $datasets_to_file_save = array();

  foreach ($wrapper_study->mica_dataset->getIterator() as $dataset) {
    $dataset_node = node_load($dataset->getIdentifier());
    $dce_population_find_param = array(
      'study' => $wrapper_study,
      'datasetId' => $dataset->getIdentifier()
    );
    $connector = mica_connector_query($dataset->getIdentifier(), $node->nid);

    if ($dataset->field_dataset_type->value() == 'harmonization') {

      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_harmonized($context['results']['study']['created_study'],
        $connector->options, $dce_population_find_param);

      $dataset_type_parse = "obiba.mica.HarmonizationDatasetDto.type";
      $resource_serv = 'harmonization-datasets';
      $node_type = 'harmonization-dataset';
    }

    elseif ($dataset->field_dataset_type->value() == 'study') {
      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_study($context['results']['study']['created_study'],
        $connector->options, $dce_population_find_param);
      $dataset_type_parse = "obiba.mica.StudyDatasetDto.type";
      $resource_serv = 'study-datasets';
      $node_type = 'study-dataset';
    }

    $dataset_dto = new \obiba\mica\DatasetDto;
    $dataset_dto->setPublished(FALSE);

    $dto_util->_mica_studies_export_dto_add_translated_Field($dataset_dto, 'addName', $dataset, 'title');
    $dto_util->_mica_studies_export_dto_add_translated_Field($dataset_dto, 'setDescription', $dataset, 'body', 'value');
    $dataset_dto->setEntityType('participant');
    $dataset_dto[$dataset_type_parse] = $dataset_gen_dto;

    //Create  dataset
    $codec = new \DrSlump\Protobuf\Codec\Json();
    $dataset_dto_json = $dataset_dto->serialize($codec);
    $raw_response = $dataset->getIdentifier();

    $datasets_to_file_save[] = array(
      'created_dataset' => $raw_response,
      'title_dataset' => $dataset->title->value(),
      'dataset_json' => $dataset_dto_json
    );
  }
  $context['results']['datasets'] = $datasets_to_file_save;
}

function _mica_studies_export_dto_get_dce_populations_id($study_wrapper, $dataset_id) {
  foreach ($study_wrapper->field_study_populations->getIterator() as $population) {
    foreach ($population->field_pop_dce->getIterator() as $dce) {
      $dce_id = $dce->getIdentifier();
      $population_id = $population->getIdentifier();

      $array_id = array(
        'populationId' => $population_id,
        'dceId' => $dce_id
      );
      foreach ($dce->field_dce_dataset->getIterator() as $datasets_dce) {
        if ($datasets_dce->getIdentifier() == $dataset_id) {
          return $array_id;
        }
      }

    }
  }
  return FALSE;
}

function _mica_mica_studies_export_dto_dataset_harmonized($study_id, $conector_options, $dce_population_find_param = NULL) {
  $project = !empty($conector_options) ? $conector_options['datasource'] : 'mica';
  $table = !empty($conector_options) ? $conector_options['table'] : 'und';
  $study_exist = FALSE;
  $datset_harmo_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;

  $datset_harmo_dto = new \obiba\mica\HarmonizationDatasetDto;

  foreach ($datset_harmo_dto->studyTables as $study_table) {
    if ($study_table->studyId == $study_id) {
      $study_exist = TRUE;
    }
  }

  $datset_harmo_st_dto->setPopulationId('novalue');
  $datset_harmo_st_dto->setDataCollectionEventId('novalue');
  if (!empty($dce_population_find_param)) {
    $ids = _mica_studies_export_dto_get_dce_populations_id($dce_population_find_param['study'], $dce_population_find_param['datasetId']);
    if (!empty($ids['dceId'])) {
      $datset_harmo_st_dto->setPopulationId($ids['populationId']);
      $datset_harmo_st_dto->setDataCollectionEventId($ids['dceId']);
    }
  }
  $datset_harmo_st_dto->setStudyId($study_id);
  $datset_harmo_st_dto->setProject($project);
  $datset_harmo_st_dto->setTable($table);
  if (!$datset_harmo_dto->hasProject() || !$datset_harmo_dto->hasTable()) {
    $datset_harmo_dto->setProject($project);
    $datset_harmo_dto->setTable($table);
  }
  if (!$study_exist) {
    $datset_harmo_dto->addStudyTables($datset_harmo_st_dto);
  }
  return $datset_harmo_dto;
}

function _mica_mica_studies_export_dto_dataset_study($study_id, $conector_options, $dce_population_find_param = NULL) {
  $project = !empty($conector_options) ? $conector_options['datasource'] : 'mica';
  $table = !empty($conector_options) ? $conector_options['table'] : 'und';
  $datset_study_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_study_st_dto->setPopulationId('novalue');
  $datset_study_st_dto->setDataCollectionEventId('novalue');
  if (!empty($dce_population_find_param)) {
    $ids = _mica_studies_export_dto_get_dce_populations_id($dce_population_find_param['study'], $dce_population_find_param['datasetId']);
    if (!empty($ids['dceId'])) {
      $datset_study_st_dto->setPopulationId($ids['populationId']);
      $datset_study_st_dto->setDataCollectionEventId($ids['dceId']);
    }
  }
  $datset_study_st_dto->setStudyId($study_id);
  $datset_study_st_dto->setProject($project);
  $datset_study_st_dto->setTable($table);

  $datset_study_dto = new \obiba\mica\StudyDatasetDto;
  $datset_study_dto->setStudyTable($datset_study_st_dto);

  return $datset_study_dto;
}