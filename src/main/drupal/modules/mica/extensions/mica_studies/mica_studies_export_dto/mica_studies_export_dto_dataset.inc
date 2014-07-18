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

  foreach ($wrapper_study->mica_dataset->getIterator() as $dataset) {
    $mica_server_id = NULL;
    $dataset_finded_mica_server = NULL;
    $dataset_node = node_load($dataset->getIdentifier());
    $mica_server_id = trim($dataset_node->mica_server_id);

    $connector = mica_connector_query($dataset->getIdentifier(), $node->nid);

    if ($dataset->field_dataset_type->value() == 'harmonization') {
      if (!empty($mica_server_id)) {
        $dataset_finded_mica_server_json = $dto_util->get_from_mica_server('/draft/harmonization-dataset/' . $mica_server_id);

        $dtoObj = new \obiba\mica\DatasetDto;
        $codec = new \DrSlump\Protobuf\Codec\Json();
        $dataset_finded_mica_server = $codec->decode($dtoObj, $dataset_finded_mica_server_json);
      }
      if (!empty($dataset_finded_mica_server)) {
        $hamonizaed_dataset_dto = $dataset_finded_mica_server->getExtensionList('obiba.mica.HarmonizationDatasetDto.type');

      }
      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_harmonized($context['results']['created_study'],
        $connector->options, $hamonizaed_dataset_dto);

      $dataset_type_parse = "obiba.mica.HarmonizationDatasetDto.type";
      $resource_serv = 'harmonization-datasets';
      $node_type = 'harmonization-dataset';
    }

    elseif ($dataset->field_dataset_type->value() == 'study') {
      if (!empty($mica_server_id)) {
        $dataset_finded_mica_server_json = $dto_util->get_from_mica_server('/draft/study-dataset/' . $mica_server_id);

        $dtoObj = new \obiba\mica\DatasetDto;
        $codec = new \DrSlump\Protobuf\Codec\Json();
        $dataset_finded_mica_server = $codec->decode($dtoObj, $dataset_finded_mica_server_json);
      }
      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_study($context['results']['created_study'],
        $connector->options);
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
    if (!empty($dataset_finded_mica_server)) {
      $dataset_dto->setId($dataset_finded_mica_server->id);
      $codec = new \DrSlump\Protobuf\Codec\Json();
      $dataset_dto_json = $dataset_dto->serialize($codec);
      $dto_util->save_operation($dataset_dto_json, 'draft/' . $node_type . '/' . $dataset_finded_mica_server->id, 'METHOD_PUT', $node_type);
      $raw_response = $dataset_finded_mica_server->id;
    }
    //Create  dataset
    else {
      $codec = new \DrSlump\Protobuf\Codec\Json();
      $dataset_dto_json = $dataset_dto->serialize($codec);
      $raw_response = $dto_util->save_operation($dataset_dto_json, 'draft/' . $resource_serv, 'METHOD_POST', $node_type);
      $dataset_node->mica_server_id = $raw_response;
      node_save($dataset_node);
    }

  }

}

function _mica_mica_studies_export_dto_dataset_harmonized($server_study_id, $conector_options, $hamonizaed_dataset_dto = NULL) {
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

  $datset_harmo_st_dto->setStudyId($server_study_id);
  $datset_harmo_st_dto->setProject($project);
  $datset_harmo_st_dto->setTable($table);

  $datset_harmo_dto->setProject('mica');
  $datset_harmo_dto->setTable('und');
  if (!$study_exist) {
    $datset_harmo_dto->addStudyTables($datset_harmo_st_dto);
  }
  return $datset_harmo_dto;
}

function _mica_mica_studies_export_dto_dataset_study($server_study_id, $conector_options) {
  $project = !empty($conector_options) ? $conector_options['datasource'] : 'mica';
  $table = !empty($conector_options) ? $conector_options['table'] : 'und';
  $datset_study_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_study_st_dto->setStudyId($server_study_id);
  $datset_study_st_dto->setProject($project);
  $datset_study_st_dto->setTable($table);

  $datset_study_dto = new \obiba\mica\StudyDatasetDto;
  $datset_study_dto->setStudyTable($datset_study_st_dto);

  return $datset_study_dto;
}