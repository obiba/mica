<?php
/**
 * @file
 * mica_studies.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function mica_studies_content_defaults() {
$content = array();
$content['access'] = (object)array(
  'title' => 'access',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970582',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'access',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_access',
        'format' => NULL,
        'safe_value' => 'field_access',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['access_other'] = (object)array(
  'title' => 'access_other',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970606',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'access_other',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_access_other',
        'format' => NULL,
        'safe_value' => 'field_access_other',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['acroym'] = (object)array(
  'title' => 'acroym',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970122',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'acroym',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_acroym',
        'format' => NULL,
        'safe_value' => 'field_acroym',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['age_max'] = (object)array(
  'title' => 'age_max',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970380',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'age_max',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_age_max',
        'format' => NULL,
        'safe_value' => 'field_age_max',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['age_min'] = (object)array(
  'title' => 'age_min',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970359',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'age_min',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_age_min',
        'format' => NULL,
        'safe_value' => 'field_age_min',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['biosamples_collected'] = (object)array(
  'title' => 'biosamples_collected',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970448',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'biosamples_collected',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_biosamples_collected',
        'format' => NULL,
        'safe_value' => 'field_biosamples_collected',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['biosamples_collected_other'] = (object)array(
  'title' => 'biosamples_collected_other',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970476',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'biosamples_collected_other',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_biosamples_collected_other',
        'format' => NULL,
        'safe_value' => 'field_biosamples_collected_other',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['biosamples_tissues'] = (object)array(
  'title' => 'biosamples_tissues',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970493',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'biosamples_tissues',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_biosamples_tissues',
        'format' => NULL,
        'safe_value' => 'field_biosamples_tissues',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['design'] = (object)array(
  'title' => 'design',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970230',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'design',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_design',
        'format' => NULL,
        'safe_value' => 'field_design',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['design_other'] = (object)array(
  'title' => 'design_other',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970254',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'design_other',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_design_other',
        'format' => NULL,
        'safe_value' => 'field_design_other',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['design_target'] = (object)array(
  'title' => 'design_target',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970274',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'design_target',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_design_target',
        'format' => NULL,
        'safe_value' => 'field_design_target',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['gender'] = (object)array(
  'title' => 'gender',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970343',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'gender',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_gender',
        'format' => NULL,
        'safe_value' => 'field_gender',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['gwas_number'] = (object)array(
  'title' => 'gwas_number',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970558',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'gwas_number',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_gwas_number',
        'format' => NULL,
        'safe_value' => 'field_gwas_number',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['selection_criteria'] = (object)array(
  'title' => 'selection_criteria',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970307',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'selection_criteria',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_selection_criteria',
        'format' => NULL,
        'safe_value' => 'field_selection_criteria',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['status_end'] = (object)array(
  'title' => 'status_end',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970666',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'status_end',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_status_end',
        'format' => NULL,
        'safe_value' => 'field_status_end',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['status_start'] = (object)array(
  'title' => 'status_start',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970624',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'status_start',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_status_start',
        'format' => NULL,
        'safe_value' => 'field_status_start',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['study_country'] = (object)array(
  'title' => 'study_country',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970325',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'study_country',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_study_country',
        'format' => NULL,
        'safe_value' => 'field_study_country',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['target_number_biosamples'] = (object)array(
  'title' => 'target_number_biosamples',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970427',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'target_number_biosamples',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_target_number_biosamples',
        'format' => NULL,
        'safe_value' => 'field_target_number_biosamples',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['target_number_participants'] = (object)array(
  'title' => 'target_number_participants',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970207',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'target_number_participants',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_target_number_participants',
        'format' => NULL,
        'safe_value' => 'field_target_number_participants',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'INTEGER',
      ),
    ),
  ),
);
$content['target_other'] = (object)array(
  'title' => 'target_other',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970290',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'target_other',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study_information',
        'format' => NULL,
        'safe_value' => 'study_information',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'field_target_other',
        'format' => NULL,
        'safe_value' => 'field_target_other',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
$content['variable_body'] = (object)array(
  'title' => 'body',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'variable',
  'language' => 'und',
  'created' => '1304970081',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'variable_body',
  'body' => array(),
  'field_bundle' => array(
    'und' => array(
      0 => array(
        'value' => 'study',
        'format' => NULL,
        'safe_value' => 'study',
      ),
    ),
  ),
  'field_original_field_name' => array(
    'und' => array(
      0 => array(
        'value' => 'body',
        'format' => NULL,
        'safe_value' => 'body',
      ),
    ),
  ),
  'field_value_type' => array(
    'und' => array(
      0 => array(
        'value' => 'TEXT',
      ),
    ),
  ),
);
return $content;
}
