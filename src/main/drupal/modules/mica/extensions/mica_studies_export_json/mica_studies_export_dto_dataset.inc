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
  $hamonizaed_dataset_dto = NULL;
  $wrapper_study = entity_metadata_wrapper('node', $node);

  $dto_util = new QuerySendDto();
//  $context['results'] = $context['results'];
  $datasets_to_file_save = array();
  foreach ($wrapper_study->mica_dataset->getIterator() as $dataset) {
    $mica_server_id = NULL;
    $dataset_finded_mica_server = NULL;
    $dataset_node = node_load($dataset->getIdentifier());
    $mica_server_id = trim($dataset_node->mica_server_id);
    $dce_population_find_param = array(
      'study' => $wrapper_study,
      'datasetId' => $dataset->getIdentifier()
    );
    $connector = mica_connector_query($dataset->getIdentifier(), $node->nid);

    if ($dataset->field_dataset_type->value() == 'harmonization') {
      if (!empty($mica_server_id)) {
        $harmo_dataset_finded_mica_server_json = $dto_util->get_from_mica_server('/draft/harmonization-dataset/' . $mica_server_id);

        $dtoObj = new \obiba\mica\DatasetDto;
        $codec = new \DrSlump\Protobuf\Codec\Json();
        $harmo_dataset_finded_mica_server = $codec->decode($dtoObj, $harmo_dataset_finded_mica_server_json);

        if (empty($harmo_dataset_finded_mica_server_json)) {
          $harmo_dataset_finded_mica_server_json = $dto_util->get_from_mica_server('/harmonization-dataset/' . $mica_server_id);

          $dtoObj = new \obiba\mica\DatasetDto;
          $codec = new \DrSlump\Protobuf\Codec\Json();
          $harmo_dataset_finded_mica_server = $codec->decode($dtoObj, $harmo_dataset_finded_mica_server_json);
        }
      }
      if (!empty($harmo_dataset_finded_mica_server)) {
        $hamonizaed_dataset_dto = $harmo_dataset_finded_mica_server->getExtensionList('obiba.mica.HarmonizationDatasetDto.type');

      }

      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_harmonized($context['results']['study']['created_study'],
        $connector->options, $hamonizaed_dataset_dto, $dce_population_find_param);

      $dataset_type_parse = "obiba.mica.HarmonizationDatasetDto.type";
      $resource_serv = 'harmonization-datasets';
      $node_type = 'harmonization-dataset';
    }

    elseif ($dataset->field_dataset_type->value() == 'study') {
      if (!empty($mica_server_id)) {
        $study_dataset_finded_mica_server_json = $dto_util->get_from_mica_server('/draft/study-dataset/' . $mica_server_id);

        $dtoObj = new \obiba\mica\DatasetDto;
        $codec = new \DrSlump\Protobuf\Codec\Json();
        $study_dataset_finded_mica_server = $codec->decode($dtoObj, $study_dataset_finded_mica_server_json);

      }
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

    //update dataset
    if (!empty($study_dataset_finded_mica_server)) {
      $dataset_dto->setId($study_dataset_finded_mica_server->id);
      $codec = new \DrSlump\Protobuf\Codec\Json();
      $dataset_dto_json = $dataset_dto->serialize($codec);
      $dto_util->save_operation($dataset_dto_json, 'draft/' . $node_type . '/' . $study_dataset_finded_mica_server->id, 'METHOD_PUT', $node_type);
    }
    //Create  dataset
    else {
      $codec = new \DrSlump\Protobuf\Codec\Json();
      $dataset_dto_json = $dataset_dto->serialize($codec);
      $raw_response = $dto_util->save_operation($dataset_dto_json, 'draft/' . $resource_serv, 'METHOD_POST', $node_type);
      if (!empty($raw_response)) {
        $dataset_node->mica_server_id = $raw_response;
        node_save($dataset_node);
      }
      else {
        $raw_response = $dataset->getIdentifier();
      }
    }
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

function _mica_mica_studies_export_dto_dataset_harmonized($server_study_id, $conector_options, $hamonizaed_dataset_dto = NULL, $dce_population_find_param = NULL) {
  $project = !empty($conector_options) ? $conector_options['datasource'] : 'mica';
  $table = !empty($conector_options) ? $conector_options['table'] : 'und';
  $study_exist = FALSE;
  $datset_harmo_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  if (!empty($hamonizaed_dataset_dto)) {
    $datset_harmo_dto = $hamonizaed_dataset_dto;
  }
  else {
    $datset_harmo_dto = new \obiba\mica\HarmonizationDatasetDto;

  }
  foreach ($datset_harmo_dto->studyTables as $study_table) {
    if ($study_table->studyId == $server_study_id) {
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
  $datset_harmo_st_dto->setStudyId($server_study_id);
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

function _mica_mica_studies_export_dto_dataset_study($server_study_id, $conector_options, $dce_population_find_param = NULL) {
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
  $datset_study_st_dto->setStudyId($server_study_id);
  $datset_study_st_dto->setProject($project);
  $datset_study_st_dto->setTable($table);

  $datset_study_dto = new \obiba\mica\StudyDatasetDto;
  $datset_study_dto->setStudyTable($datset_study_st_dto);

  return $datset_study_dto;
}