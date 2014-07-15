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
  $wrapper_study = entity_metadata_wrapper('node', $node);

  $dto_util = new QuerySendDto();

  foreach ($wrapper_study->mica_dataset->getIterator() as $dataset) {
    $connector = mica_connector_query($dataset->getIdentifier(), $node->nid, TRUE);

    if ($dataset->field_dataset_type->value() == 'harmonization') {
      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_harmonized($context['results']['created_study'],
        $connector->options);
      $dataset_type_parse = "obiba.mica.HarmonizedDatasetDto.type";
      $resource_serv = 'harmonized-datasets';
    }

    elseif ($dataset->field_dataset_type->value() == 'study') {
      $dataset_gen_dto = _mica_mica_studies_export_dto_dataset_study($context['results']['created_study'],
        $connector->options);
      $dataset_type_parse = "obiba.mica.StudyDatasetDto.type";
      $resource_serv = 'study-datasets';
    }

    if (!empty($dataset_gen_dto)) {
      $dataset_dto = new \obiba\mica\DatasetDto;
      $dataset_dto->setPublished(FALSE);

      $dto_util->_mica_studies_export_dto_add_translated_Field($dataset_dto, 'addName', $dataset, 'title');
      $dto_util->_mica_studies_export_dto_add_translated_Field($dataset_dto, 'setDescription', $dataset, 'body', 'value');
      $dataset_dto->setEntityType('participant');
      $dataset_dto[$dataset_type_parse] = $dataset_gen_dto;

      $codec = new \DrSlump\Protobuf\Codec\Json();
      $dataset_dto_json = $dataset_dto->serialize($codec);

      $dto_util->export_dataset($dataset_dto_json, 'draft/' . $resource_serv);

    }

  }

}

function _mica_mica_studies_export_dto_dataset_harmonized($server_study_id, $conector_options) {
  $datset_harmo_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_harmo_st_dto->setStudyId($server_study_id);
  $datset_harmo_st_dto->setProject($conector_options['datasource']);
  $datset_harmo_st_dto->setTable($conector_options['table']);

  $datset_harmo_dto = new \obiba\mica\HarmonizedDatasetDto;
  $datset_harmo_dto->setProject('mica');
  $datset_harmo_dto->setTable('und');
  $datset_harmo_dto->addStudyTables($datset_harmo_st_dto);

  return $datset_harmo_dto;
}

function _mica_mica_studies_export_dto_dataset_study($server_study_id, $conector_options) {
  $datset_study_st_dto = new \obiba\mica\DatasetDto\StudyTableDto;
  $datset_study_st_dto->setStudyId($server_study_id);
  $datset_study_st_dto->setProject($conector_options['datasource']);
  $datset_study_st_dto->setTable($conector_options['table']);

  $datset_study_dto = new \obiba\mica\StudyDatasetDto;
  $datset_study_dto->setStudyTable($datset_study_st_dto);

  return $datset_study_dto;
}