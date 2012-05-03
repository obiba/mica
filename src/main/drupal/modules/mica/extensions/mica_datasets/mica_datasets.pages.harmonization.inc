<?php

/**
* Display queries.
*/
function mica_datasets_dataset_harmonization_page($dataset_node) {
	drupal_set_title(t('!title -- Harmonization', array('!title' => $dataset_node->title)));

	$header = array(
    'name' => t('Variable'),
	);

	$options = array();

	$wrapper = entity_metadata_wrapper('node', $dataset_node);
	$variables = $wrapper->field_dataset_variables->value();
	$studies = $wrapper->field_dataset_studies->value();
 
	$status_values = field_info_field('field_sv_script_status');
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
          'name' => "<a href='".url('node/'.$variable->nid)."'>$variable->title</a>",
				);
				
		  foreach($variable->field_variable_study_variables[$variable->language] as $study_variable){
		  
        $study_id = $study_variables[$study_variable['nid']]->field_sv_study['und'][0]['nid'];
        if (!empty($study_variables[$study_variable['nid']]->field_sv_script_status)){
          $status = $study_variables[$study_variable['nid']]->field_sv_script_status['und'][0]['value'];
          $status_label = $status_values['settings']['allowed_values'][$status];
        }
        else{
          $status = 'not_available';
          $status_label = t('Not Available');
        }
        $script = empty($study_variables[$study_variable['nid']]->field_sv_script['und'][0]['value']) ? '':$study_variables[$study_variable['nid']]->field_sv_script['und'][0]['value'];
        $script = '<code>'.check_markup($script).'</code>';
        $comment = empty($study_variables[$study_variable['nid']]->field_sv_comment['und'][0]['value']) ? '': $study_variables[$study_variable['nid']]->field_sv_comment['und'][0]['value'];
        
        // inner tooltip
        $tooltip = "<table><tr><td style=\"vertical-align:top\"><b>Status:</b></td><td>$status_label</td></tr><tr><td style=\"vertical-align:top\"><b>Script:</b></td><td>".check_plain($script)."</td></tr>";
        
        if (!empty($comment)){
          $tooltip .= "<tr><td style=\"vertical-align:top\"><b>Comment:</b></td><td>$comment</td></tr></table>";
        }
        $option[$header_ids[$study_id]]['data'][] = array(
        	'#type' => 'markup',
        	'#markup' => "<a href='".url('node/'.$study_variable['nid'])."'><div class='harmonization-" . $status ." tipsy' title='$tooltip'></div></a>",
        );
			}

			$options[] = $option;
		}
	}
  unset($result);
  unset($study_variables);
  
//   pager_default_initialize(32, 1, $element = 0);
//   debug(theme('pager', array('quantity' => 3)));
  
  
	$output = theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No harmonization found')));
// 	$output .= theme('pager', array('quantity' => 3));
	$output .= drupal_render(drupal_get_form('mica_datasets_harmonization_legend_form'));
	
	return $output; 
}

function mica_datasets_harmonization_legend_form($form, $form_state){
  $form['legend'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('Legend'),
	  '#collapsed' => FALSE,
	  '#collapsible' => TRUE,
	  '#tree' => TRUE,
  );
  $form['legend']['complete'] = array(
  	'#type' => 'markup',
  	'#markup' => "<div class='harmonization-complete'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<b>Complete</b> - 
  		<i>the meaning and format of the question or questions of the questionnaire allow the construction of 
  		the variable as described (definition and format).</i></div>",
  );
  $form['legend']['inprogress'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-in_progress'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<b>In Progress</b> - 
  		<i>the status of this variable is being evaluated.</i></div>",
  );
  $form['legend']['impossible'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-impossible'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<b>Impossible</b> - 
  		<i>there is no information or insufficient information in the questionnaire to allow the construction of 
  		the variable as described.</i></div>",
  );
  $form['legend']['not_available'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-not_available'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<b>Not Available</b> - 
  		<i>information not available.</i></div>",
  );
  
  return $form;
}