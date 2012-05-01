<?php

/**
* Display queries.
*/
function mica_datasets_dataset_harmonization_page($dataset_node) {
	drupal_set_title(t('!title -- Harmonization', array('!title' => $dataset_node->title)));

	mica_core_modal_prepare(array(
	array(
      'name' => 'delete-style',
      'width' => 400,
      'height' => 150,
	),
	));

	global $user;

	$header = array(
    'name' => t('Variable'),
    //'description' => t('Description'),
    //'actions' => t('Operations'),
	);

	$options = array();

	$wrapper = entity_metadata_wrapper('node', $dataset_node);
	$variables = $wrapper->field_dataset_variables->value();
	$studies = $wrapper->field_dataset_studies->value();

	$header_ids = array();
	foreach($studies as $study){
	  $study_wrapper = entity_metadata_wrapper('node', $study);
	  $acronym = $study_wrapper->field_acroym->value();
	  $name = !empty($acronym)? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();
	  $header[] = $name;
	  
	  $header_ids[$study_wrapper->nid->value()] = $name;
	}
	
 	if (!empty($variables) && !empty($studies)) {
 	  
 	  $query = new EntityFieldQuery();
 	  $result = $query->entityCondition('entity_type', 'node')
 	  ->entityCondition('bundle', 'study_variable')
 	  ->execute();
 	  $study_variables = node_load_multiple(array_keys($result['node']));

 	  foreach($variables as $variable){
				$option = array(
          'name' => $variable->title,
				);
				
				// Set to not set by default
				foreach($header_ids as $id => $name){  
				  $option[$name]['data'][] = array(
            //'#markup' => '<span style=\'margin-right:10px;\'>' . t('N/Av') . '</span>',
  				);
				}
				
				foreach($variable->field_variable_study_variables[$variable->language] as $study_variable){
          if (!empty($study_variables[$study_variable['nid']]->field_sv_study)){
            $study_id = $study_variables[$study_variable['nid']]->field_sv_study['und'][0]['nid'];
            $status = $study_variables[$study_variable['nid']]->field_sv_script_status['und'][0]['value'];
            
            // inner tooltip
            $tooltip = "Status: <br>Algorithm:<br>Comment:<br>";
            $option[$header_ids[$study_id]]['data'][] = array(
//               '#type' => 'link',
//               '#title' => '_',
//               '#href' => '',//_mica_datasets_dataset_query_url($dataset_node, $query),
//               '#attributes' => array('class' => array('harmonization-' . $status)),
            	'#type' => 'markup',
            	'#markup' => "<a href='".url('node/'.$study_variable['nid'])."' class='tipsy' title='assds'><div class='harmonization-" . $status ."'></div></a>",
              //'#markup' => "<div class='harmonization-" . $status ."'><a href='asd' class='tipsy' title='assds'></div>",
            	
              //'#attributes' => array('class' => array('harmonization-' . $status, 'clear_tipsy')),
              //'#children' => "<a href='' class='clear_tipsy' title='" . $tooltip . "'>asd</a>",
            );
            
          } 
				}
				$options[] = $option;
		}
	}

	return theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No harmonization found')));
}