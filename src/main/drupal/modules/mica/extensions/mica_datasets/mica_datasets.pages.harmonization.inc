<?php

/*
 * Menu for callback of refresh harmonization
 */
function mica_datasets_harmonization_menu(){
 $items = array();
 $items['mica/mica_datasets_harmonization/ajax'] = array(
 	'page callback' => 'mica_datasets_harmonization_ajax_callback',
  'access arguments' => TRUE,
  'type' => MENU_CALLBACK,
 );
 $items['/mica/mica_datasets_harmonization/ajax/%'] = array(
     'page callback' => 'mica_datasets_harmonization_ajax_callback',
     'page arguments' => array(2, 3),
     'access arguments' => TRUE,
     'type' => MENU_CALLBACK,
 );
 return $items;
}

/**
 * Display queries.
 */
function mica_datasets_dataset_harmonization_page($dataset_node) {
  drupal_set_title(t('!title -- Harmonization', array('!title' => $dataset_node->title)));
  $path = drupal_get_path('module', 'mica_datasets');
  drupal_add_css($path . '/includes/prettify.css');
  drupal_add_js($path . '/includes/prettify.js');
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'jquery.form');
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
  foreach ($studies as $study) {
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $acronym = $study_wrapper->field_acroym->value();
    $name = !empty($acronym) ? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();
    
    // See http://www.jide.fr/english/using-ajax-in-drupal-7-outside-of-form-api
    // show link only for studies that have an opal connection
    if (node_access('update', $dataset_node) && mica_dataset_connector_query($wrapper->nid->value(), $study_wrapper->nid->value())){
      $ajax_link = l("<img src='".MICA_HARMONIZATION_REFRESH."' class='harmonization-refresh-icon' title='Refresh harmonization of $name'/>", 'mica_datasets_harmonization/ajax/nojs/' . $wrapper->nid->value() . '/' .$study_wrapper->nid->value(), array('html' => TRUE, 'attributes' => array('class' => array('use-ajax'))));
    }
    else{
      $ajax_link = '';
    }
    
    $header[] = "<div class='harmonization-study-title'>$name$ajax_link</div><br>";//"<div class='harmonization-study-icon'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>";

    $header_ids[$study_wrapper->nid->value()] = $name;
  }

  if (!empty($variables) && !empty($studies)) {

    uasort($variables, 'sort_by_position');

    // sort varibles based on their field_position
    // get the ids of all study_variable_attributes and load at once
    $svids = array();
    foreach ($variables as $variable) {
      if (!empty($variable->field_variable_study_var_att[$variable->language])) {
        foreach ($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes) {
          $svids[] = $study_variable_attributes['nid'];
        }
      }
    }
    $svas = node_load_multiple($svids);

    // Add rows to the harmonization table
    foreach ($variables as $variable) {
      $option = array(
        'name' => "<a href='" . url('node/' . $variable->nid) . "'>$variable->title</a>",
      );
      if (!empty($variable->field_variable_study_var_att[$variable->language])) {
        foreach ($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes) {

          if (!empty($svas[$study_variable_attributes['nid']]->field_sva_study)) {
            $study_id = $svas[$study_variable_attributes['nid']]->field_sva_study['und'][0]['nid'];
            $sva_node = $svas[$study_variable_attributes['nid']];
            if (array_key_exists($study_id, $header_ids)) {
              $sva_wrapper = entity_metadata_wrapper('node', $sva_node);
							
              if (!empty($sva_node->field_sva_script_status)) {
                $status = $sva_wrapper->field_sva_script_status->value();
                $status_label = $status_values['settings']['allowed_values'][$status];
              }
              else {
                $status = 'undetermined';
                $status_label = t('Undetermined');
              }
              
              $script = $sva_wrapper->field_sva_script->value() ? $sva_wrapper->field_sva_script->value(): '';
              $comment = $sva_wrapper->field_sva_comment->value() ? $sva_wrapper->field_sva_comment->value(): '';

              // inner tooltip
              $tooltip = "<table><tr><td><b>".t('Status')."</b></td><td>$status_label</td></tr>";
              
              if (!empty($comment)){
                $tooltip .= "<tr><td style='vertical-align: text-top'><b>".t('Comment')."</b></td><td>"._mica_datasets_toHtmlTruncate($comment, 'comment', 200, FALSE)."</td></tr>";
              }
              
              $tooltip .= "<tr><td style='vertical-align: top'><b>".t('Script')."</b></td><td>"._mica_datasets_toHtmlTruncate($script, 'script', 200, TRUE) . "</td></tr></table>";

              if ($status !== 'undetermined') {
                $option[$header_ids[$study_id]]['data'][] = array(
                  '#type' => 'markup',
                  '#markup' =>
                  "<a href='" . url('node/' . $study_variable_attributes['nid']) . "'><div class='tipsy'><img src='"
                    . _mica_datasets_get_status_icon($status). "' /><div class=\"tooltip_content\">$tooltip</div></div></a>",
                );
              }
              else {
                $option[$header_ids[$study_id]]['data'][] = array(
                  '#type' => 'markup',
                  '#markup' =>
                  "<a href='" . url('node/' . $study_variable_attributes['nid']) . "'><div class='tipsy'><img src='"
                    .  _mica_datasets_get_status_icon($status) . "'><div class=\"tooltip_content\"><b>".t('Status')."</b>  $status_label</div></div></a>",
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
  $output .= theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No harmonization found'), 'sticky' => FALSE, 'attributes' => array('id' => 'harmonization_overview')));

  return $output;
}

function mica_datasets_harmonization_legend_form($form, $form_state) {
  $form['legend'] = array(
    '#type' => 'container',
  );
  $form['legend']['undetermined'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . constant('MICA_HARMONIZATION_UNDETERMINED') . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Undetermined") . "</b> - <i>"
      . t("the harmonization potential of this variable has not yet been evaluated.")
      . "</i><br />",
  );
  $form['legend']['complete'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . constant('MICA_HARMONIZATION_COMPLETE') . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Complete") . "</b> - <i>"
      . t("the study assessment item(s) (e.g. survey question, physical measure, biochemical measure) allow construction of the variable as defined in the dataset.")
      . "</i><br />",
  );
  $form['legend']['impossible'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . constant('MICA_HARMONIZATION_IMPOSSIBLE') . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Impossible") . "</b> - <i>"
      . t("there is no information or insufficient information collected by this study to allow the construction of the variable as defined in the dataset.")
      . "</i>",
  );

  return $form;
}

function mica_datasets_harmonization_refresh_form($form, &$form_state, $dataset_nid, $study_nid) {  
  $connector = mica_dataset_connector_query($dataset_nid, $study_nid);
  if ($connector){
    // See http://www.jide.fr/english/using-ajax-in-drupal-7-outside-of-form-api
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_library('system', 'jquery.form');
    $ajax_link = l("<img src='".MICA_HARMONIZATION_REFRESH."' />", 'mica_datasets_harmonization/ajax/nojs/' . $dataset_nid . '/' .$study_nid, array('html' => TRUE, 'attributes' => array('class' => array('use-ajax'))));
    
    $form['refresh'] = array(
      '#type' => 'markup',
      '#markup' => $ajax_link//,
    );
    $form['study_nid'] = array(
      '#type' => 'hidden',
      '#value' => $study_nid,
    );
    $form['dataset_nid'] = array(
      '#type' => 'hidden',
      '#value' => $dataset_nid,
    );
  }
  else{
    $form['refresh'] = array('#markup' => '&nbsp;');
  }
  return $form;
}


function mica_datasets_harmonization_refresh_callback($type = 'ajax', $dataset_nid, $study_nid){

  $harmonizations = _mica_opal_fetch_harmonization_view($dataset_nid, $study_nid);
    
  global $user;
  $position = 1;
  foreach($harmonizations['variables'] as $harmonization){
    $query = new EntityFieldQuery();
    
		$result = $query->entityCondition('entity_type', 'node')
  		->entityCondition('bundle', 'variable')
  		->propertyCondition('title', $harmonization['title'])
  		->fieldCondition('field_dataset', 'nid', $harmonizations['dataset_nid'])
  		->execute();
    
    if (empty($result)){
			$infos = array(
			  'type' => 'variable',
			  'title' =>  $harmonization['title'],
			  'language' => LANGUAGE_NONE,
			  'uid' => $user->uid,
			  'status' => 0,// sva should be draft by default
			  'menu' => '',
			  'field_dataset' => $harmonizations['dataset_nid'],
			);

			$variable = entity_property_values_create_entity('node', $infos);
			$variable->save();

    }else{
		  $variable = entity_load_single('node', array_shift(array_keys($result['node'])));
		}
		
		$wrapper = entity_metadata_wrapper('node', $variable);
		$wrapper->field_label->set($harmonization['label']);
		$wrapper->field_value_type->set($harmonization['value_type']);
    $wrapper->field_position->set($position++);
    $wrapper->body->value->set($harmonization['description']);
    
    // Update categories
    if (!empty($harmonization['categories'])){
    	//  clear existing categories
			$size = count($wrapper->field_variable_categories->value());
			for ($i = 0; $i < $size; $i++){
				unset($wrapper->field_variable_categories[$i]);
			}
    
    	for ($i = 0; $i < count($harmonization['categories']); $i++) {
				$wrapper->field_variable_categories[$i]->name->set($harmonization['categories'][$i]['name']);
				$wrapper->field_variable_categories[$i]->label->set($harmonization['categories'][$i]['label']);
				$wrapper->field_variable_categories[$i]->missing->set($harmonization['categories'][$i]['missing']);
    	}
    }
    
    // Update study_variable_attributes
		foreach ($wrapper->field_variable_study_var_att->value() as $study_variable_attributes){
			$sva = entity_metadata_wrapper('node', $study_variable_attributes);

			if ($sva->field_sva_study->nid->value() === $harmonizations['study_nid']){
				$sva->field_sva_script->set($harmonization['script']);
				$sva->field_sva_script_status->set($harmonization['status']);
				$sva->field_sva_comment->set($harmonization['comment']);
				
				$sva->save();
			}
		}
		
    $wrapper->save();
  }
  drupal_set_message(t('Harmonization variables have been refreshed.'));

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands[] = ctools_ajax_command_reload(); //region-content
  print ajax_render($commands);
  exit;
}

function sort_by_position($x, $y) {
  // TODO use entity_metadata_wrapper
  $x_pos = $x->field_position['und'][0]['value'];
  $y_pos = $y->field_position['und'][0]['value'];
  if ($x_pos === $y_pos) {
    return 0;
  }
  if ($x_pos < $y_pos) {
    return -1;
  }
  return 1;
}

