<?php

/**
* Display queries.
*/
function mica_datasets_dataset_harmonization_page($dataset_node) {
	drupal_set_title(t('!title -- Harmonization', array('!title' => $dataset_node->title)));
	$path = drupal_get_path('module', 'mica_datasets');
	drupal_add_css($path . '/includes/prettify.css');
	drupal_add_js($path . '/includes/prettify.js');
	drupal_add_js('jQuery(document).ready(function (){prettyPrint()});', 'inline');
	
	$header = array(
    'name' => t('Variable'),
	);

	$options = array();

	$wrapper = entity_metadata_wrapper('node', $dataset_node);
	$variables = $wrapper->field_dataset_variables->value();
	$studies = $wrapper->field_dataset_studies->value();
 
	$status_values = field_info_field('field_sva_script_status');
	$header_ids = array();
	foreach($studies as $study){
	  $study_wrapper = entity_metadata_wrapper('node', $study);
	  $acronym = $study_wrapper->field_acroym->value();
	  $name = !empty($acronym)? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();
	  $header[] = "<span style='position:relative;z-index:50;'>$name</span>";
	  
	  $header_ids[$study_wrapper->nid->value()] = $name;
	}
	
 	if (!empty($variables) && !empty($studies)) {
 	  
 	  uasort($variables, 'sort_by_position');
 	  
 	  // sort varibles based on their field_position
 	  // get the ids of all study_variable_attributes and load at once
   	$svids = array();
 	  foreach($variables as $variable){
 	    if (!empty($variable->field_variable_study_var_att[$variable->language])){
  			foreach($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes){
     	  	$svids[] = $study_variable_attributes['nid'];
     	  }
 	    }
 	  }
   	$svas = node_load_multiple($svids);
   	
 	  // Add rows to the harmonization table
 	  foreach($variables as $variable){
 	    $option = array(
 	    	'name' => "<a href='".url('node/'.$variable->nid)."'>$variable->title</a>",
 	    );
 	    if (!empty($variable->field_variable_study_var_att[$variable->language])){
  		  foreach($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes){
  
  		    if (!empty($svas[$study_variable_attributes['nid']]->field_sva_study)){
            $study_id = $svas[$study_variable_attributes['nid']]->field_sva_study['und'][0]['nid'];
            $sva_node = $svas[$study_variable_attributes['nid']];
            if (array_key_exists($study_id, $header_ids)){
              if (!empty($sva_node->field_sva_script_status)){
                $status = $sva_node->field_sva_script_status['und'][0]['value'];
                $status_label = $status_values['settings']['allowed_values'][$status];
              }
              else{
                $status = 'not_available';
                $status_label = t('Not Available');
              }
              $script = empty($sva_node->field_sva_script['und'][0]['value']) ? '':$sva_node->field_sva_script['und'][0]['value'];
              
              // inner tooltip
              $tooltip = "<p>$status_label</p>";
              
              if (!empty($script)){
                if (strlen($script) > 500){
                  $tooltip .= "<p><code class=\'prettyprint\'>".check_markup(truncate_utf8($script, 400, FALSE))."</code>[script truncated]</p>";
                }
                else{
                  $tooltip .= "<p><code class=\'prettyprint\'>".check_markup($script)."</code></p>";
                }
              }
              
              if ($status !== 'undetermined'){
                $option[$header_ids[$study_id]]['data'][] = array(
                	'#type' => 'markup',
                	'#markup' => "<a href='".url('node/'.$study_variable_attributes['nid'])."'><div class='harmonization-" . $status ." tipsy'><div class=\"tooltip_content\">$tooltip</div></div></a>",
                );
              }
              else{
                $option[$header_ids[$study_id]]['data'][] = array(
                	'#type' => 'markup',
                	'#markup' => "<a href='".url('node/'.$study_variable_attributes['nid'])."'><div class='harmonization-" . $status ." tipsy'><div class=\"tooltip_content\">$status_label</div></div></a>",
                );
              }
      			}
  		    }
  		  }
    		$options[] = $option;
  		}
 	  }
	}
  unset($result);
  unset($svas);
  
	$output = drupal_render(drupal_get_form('mica_datasets_harmonization_legend_form'));
	$output .= '<br>';
	$output .= theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No harmonization found')));
	
	return $output; 
}

function mica_datasets_harmonization_legend_form($form, $form_state){
  $form['legend'] = array(
// 	  '#type' => 'fieldset',
  '#type' => 'container',
  
// 	  '#title' => t('Legend'),
// 	  '#collapsed' => FALSE,
// 	  '#collapsible' => FALSE,
// 	  '#tree' => TRUE,
  );
  $form['legend']['inprogress'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-undetermined'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Undetermined</b> - 
  		<i>the harmonization potential of this variable has not yet been evaluated.</i></div>",
  );
	$form['legend']['complete'] = array(
  	'#type' => 'markup',
  	'#markup' => "<div class='harmonization-complete'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Complete</b> - 
  		<i> the study assessment item(s) (e.g. survey question, physical measure, biochemical measure) allow construction 
  		of the variable as defined in the dataset.</i></div>",
  );
  $form['legend']['impossible'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-impossible'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Impossible</b> - 
  		<i>there is no information or insufficient information collected by this study to allow the construction of 
  		the variable as defined in the dataset.</i></div>",
  );
  /*$form['legend']['not_available'] = array(
		'#type' => 'markup',
	  '#markup' => "<div class='harmonization-not_available'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<b>Not Available</b> - 
  		<i>information about the status of the variable is not available.</i></div>",
  );*/
  
  return $form;
}

function sort_by_position($x, $y){
	if ( $x->field_position['und'][0]['value'] === $y->field_position['und'][0]['value'] )
	  return 0;
	else if ( $x->field_position['und'][0]['value'] < $y->field_position['und'][0]['value'] )
	  return -1;
	else
	  return 1;
}