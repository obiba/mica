<?php
/**
 * @file
 * Mica Datasets facet block configuration
 */

include_once(drupal_get_path('module', 'mica_core') . '/mica_core.search.utils.inc');

function mica_datasets_configure_facet_blocks() {

  $variable_facet_config = array(
    'field_dataset:field_dataset_type' => array(
      'name' => t('Dataset Type'),
    ),
    'field_dataset' => array(),
    'field_variable_study_var_att:field_sva_status' => array(
      'name' => t('Harmonization Status')
    ),
    'field_dataset:field_dataset_dces' => array(
      'name' => t('Data Collection Event')
    ),
    'field_dataset:field_dataset_dces:field_dce_population' => array(
      'name' => t('Population')
    ),
    'field_dataset:field_dataset_dces:field_dce_population:field_pop_select_criteria' => array(
      'name' => t('Selection Criteria')
    ),
    'field_dataset:field_dataset_dces:field_dce_population:field_pop_src_recruit' => array(
      'name' => t('Sources of Recruitment')
    ),
    'field_dataset:field_dataset_dces:field_dce_data_sources' => array(
      'name' => t('Data Sources')
    ),
    'search_api_combined_1' => array(
      'name' => t('Study')
    ),
    'field_data_source' => array(),
    'field_disease_history' => array(),
    'field_medical_health_interv' => array(),
    'field_medication' => array(),
    'field_reproductive_history' => array(),
    'field_early_life' => array(),
    'field_life_habits_behaviours' => array(),
    'field_sociodemographic_charact' => array(),
    'field_physical_environment' => array(),
    'field_social_environment' => array(),
    'field_perception_of_health' => array(),
    'field_anthropometric_structures' => array(),
    'field_body_structures' => array(),
    'field_body_functions' => array(),
    'field_laboratory_measures' => array(),
    'field_target' => array(),
    'field_value_type' => array(),
  );
  mica_core_configure_facet_blocks('variable_index', 'variable', $variable_facet_config, 'variable-search
variables-dimensions
variables-dimensions/*', 'variable_current_search');
}