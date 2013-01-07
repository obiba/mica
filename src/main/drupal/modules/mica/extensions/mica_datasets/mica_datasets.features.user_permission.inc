<?php
/**
 * @file
 * mica_datasets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_datasets_user_default_permissions() {
  $permissions = array();

  // Exported permission: clear csv_variables feeds.
  $permissions['clear csv_variables feeds'] = array(
    'name' => 'clear csv_variables feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear dataset feeds.
  $permissions['clear dataset feeds'] = array(
    'name' => 'clear dataset feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: create dataset content.
  $permissions['create dataset content'] = array(
    'name' => 'create dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: create study_variable_attributes content.
  $permissions['create study_variable_attributes content'] = array(
    'name' => 'create study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create variable content.
  $permissions['create variable content'] = array(
    'name' => 'create variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dataset content.
  $permissions['delete any dataset content'] = array(
    'name' => 'delete any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study_variable_attributes content.
  $permissions['delete any study_variable_attributes content'] = array(
    'name' => 'delete any study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any variable content.
  $permissions['delete any variable content'] = array(
    'name' => 'delete any variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dataset content.
  $permissions['delete own dataset content'] = array(
    'name' => 'delete own dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study_variable_attributes content.
  $permissions['delete own study_variable_attributes content'] = array(
    'name' => 'delete own study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own variable content.
  $permissions['delete own variable content'] = array(
    'name' => 'delete own variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in anthropometric_structures.
  $permissions['delete terms in anthropometric_structures'] = array(
    'name' => 'delete terms in anthropometric_structures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in body_functions.
  $permissions['delete terms in body_functions'] = array(
    'name' => 'delete terms in body_functions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in body_structures.
  $permissions['delete terms in body_structures'] = array(
    'name' => 'delete terms in body_structures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in data_source.
  $permissions['delete terms in data_source'] = array(
    'name' => 'delete terms in data_source',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in disease_history.
  $permissions['delete terms in disease_history'] = array(
    'name' => 'delete terms in disease_history',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in early_life.
  $permissions['delete terms in early_life'] = array(
    'name' => 'delete terms in early_life',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in essence.
  $permissions['delete terms in essence'] = array(
    'name' => 'delete terms in essence',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in individual_participant_measures.
  $permissions['delete terms in individual_participant_measures'] = array(
    'name' => 'delete terms in individual_participant_measures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in laboratory_measures.
  $permissions['delete terms in laboratory_measures'] = array(
    'name' => 'delete terms in laboratory_measures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in life_habits_behaviours.
  $permissions['delete terms in life_habits_behaviours'] = array(
    'name' => 'delete terms in life_habits_behaviours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in measure.
  $permissions['delete terms in measure'] = array(
    'name' => 'delete terms in measure',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in medical_health_intervention.
  $permissions['delete terms in medical_health_intervention'] = array(
    'name' => 'delete terms in medical_health_intervention',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in medication.
  $permissions['delete terms in medication'] = array(
    'name' => 'delete terms in medication',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in perception_of_health.
  $permissions['delete terms in perception_of_health'] = array(
    'name' => 'delete terms in perception_of_health',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in period.
  $permissions['delete terms in period'] = array(
    'name' => 'delete terms in period',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in physical_environment.
  $permissions['delete terms in physical_environment'] = array(
    'name' => 'delete terms in physical_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in reproductive_history.
  $permissions['delete terms in reproductive_history'] = array(
    'name' => 'delete terms in reproductive_history',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in social_environment.
  $permissions['delete terms in social_environment'] = array(
    'name' => 'delete terms in social_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in sociodemographic_characteristics.
  $permissions['delete terms in sociodemographic_characteristics'] = array(
    'name' => 'delete terms in sociodemographic_characteristics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in sources_of_recruitment.
  $permissions['delete terms in sources_of_recruitment'] = array(
    'name' => 'delete terms in sources_of_recruitment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in target.
  $permissions['delete terms in target'] = array(
    'name' => 'delete terms in target',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any dataset content.
  $permissions['edit any dataset content'] = array(
    'name' => 'edit any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study_variable_attributes content.
  $permissions['edit any study_variable_attributes content'] = array(
    'name' => 'edit any study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any variable content.
  $permissions['edit any variable content'] = array(
    'name' => 'edit any variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dataset content.
  $permissions['edit own dataset content'] = array(
    'name' => 'edit own dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study_variable_attributes content.
  $permissions['edit own study_variable_attributes content'] = array(
    'name' => 'edit own study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own variable content.
  $permissions['edit own variable content'] = array(
    'name' => 'edit own variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in anthropometric_structures.
  $permissions['edit terms in anthropometric_structures'] = array(
    'name' => 'edit terms in anthropometric_structures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in body_functions.
  $permissions['edit terms in body_functions'] = array(
    'name' => 'edit terms in body_functions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in body_structures.
  $permissions['edit terms in body_structures'] = array(
    'name' => 'edit terms in body_structures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in data_source.
  $permissions['edit terms in data_source'] = array(
    'name' => 'edit terms in data_source',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in disease_history.
  $permissions['edit terms in disease_history'] = array(
    'name' => 'edit terms in disease_history',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in early_life.
  $permissions['edit terms in early_life'] = array(
    'name' => 'edit terms in early_life',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in essence.
  $permissions['edit terms in essence'] = array(
    'name' => 'edit terms in essence',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in individual_participant_measures.
  $permissions['edit terms in individual_participant_measures'] = array(
    'name' => 'edit terms in individual_participant_measures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in laboratory_measures.
  $permissions['edit terms in laboratory_measures'] = array(
    'name' => 'edit terms in laboratory_measures',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in life_habits_behaviours.
  $permissions['edit terms in life_habits_behaviours'] = array(
    'name' => 'edit terms in life_habits_behaviours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in measure.
  $permissions['edit terms in measure'] = array(
    'name' => 'edit terms in measure',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in medical_health_intervention.
  $permissions['edit terms in medical_health_intervention'] = array(
    'name' => 'edit terms in medical_health_intervention',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in medication.
  $permissions['edit terms in medication'] = array(
    'name' => 'edit terms in medication',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in perception_of_health.
  $permissions['edit terms in perception_of_health'] = array(
    'name' => 'edit terms in perception_of_health',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in period.
  $permissions['edit terms in period'] = array(
    'name' => 'edit terms in period',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in physical_environment.
  $permissions['edit terms in physical_environment'] = array(
    'name' => 'edit terms in physical_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in reproductive_history.
  $permissions['edit terms in reproductive_history'] = array(
    'name' => 'edit terms in reproductive_history',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in social_environment.
  $permissions['edit terms in social_environment'] = array(
    'name' => 'edit terms in social_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in sociodemographic_characteristics.
  $permissions['edit terms in sociodemographic_characteristics'] = array(
    'name' => 'edit terms in sociodemographic_characteristics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in sources_of_recruitment.
  $permissions['edit terms in sources_of_recruitment'] = array(
    'name' => 'edit terms in sources_of_recruitment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in target.
  $permissions['edit terms in target'] = array(
    'name' => 'edit terms in target',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: import csv_variables feeds.
  $permissions['import csv_variables feeds'] = array(
    'name' => 'import csv_variables feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import dataset feeds.
  $permissions['import dataset feeds'] = array(
    'name' => 'import dataset feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: tamper csv_variables.
  $permissions['tamper csv_variables'] = array(
    'name' => 'tamper csv_variables',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: tamper dataset.
  $permissions['tamper dataset'] = array(
    'name' => 'tamper dataset',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: view any unpublished dataset content.
  $permissions['view any unpublished dataset content'] = array(
    'name' => 'view any unpublished dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished study_variable_attributes content.
  $permissions['view any unpublished study_variable_attributes content'] = array(
    'name' => 'view any unpublished study_variable_attributes content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished variable content.
  $permissions['view any unpublished variable content'] = array(
    'name' => 'view any unpublished variable content',
    'roles' => array(
      'administrator' => 'administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
