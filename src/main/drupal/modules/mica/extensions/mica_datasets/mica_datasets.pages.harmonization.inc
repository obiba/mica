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
    $call = drupal_render(drupal_get_form('mica_datasets_harmonization_refresh_form', $wrapper->nid->value(), $study_wrapper->nid->value()));
    $header[] = "<div class='harmonization-study-title'>$name</div><br>".$call;//"<div class='harmonization-study-icon'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>";

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
              
              if (!empty($sva_node->field_sva_script_status)) {
                $status = $sva_node->field_sva_script_status['und'][0]['value'];
                $status_label = $status_values['settings']['allowed_values'][$status];
              }
              else {
                $status = 'undetermined';
                $status_label = t('Undetermined');
              }
              $status_image = "mica_harmonization_{$status}";
              
              $script = empty($sva_node->field_sva_script['und'][0]['value']) ? ''
                : $sva_node->field_sva_script['und'][0]['value'];

              $comment = empty($sva_node->field_sva_comment['und'][0]['value']) ? ''
                : $sva_node->field_sva_comment['und'][0]['value'];

              // inner tooltip
              $tooltip = "<table><tr><td><b>".t('Status')."</b></td><td>$status_label</td></tr>";
              
              if (!empty($comment)){
                $tooltip .= "<tr><td style='vertical-align: top'><b>".t('Comment')."</b></td><td style='vertical-align: top'>".toHtmlTruncate($comment, 'comment', 'i')."</td></tr>";
              }
              
              $tooltip .= "<tr><td style='vertical-align: top'><b>".t('Script')."</b></td><td style='vertical-align: top'>".toHtmlTruncate($script, 'script', '') . "</td></tr></table>";

              if ($status !== 'undetermined') {
                $option[$header_ids[$study_id]]['data'][] = array(
                  '#type' => 'markup',
                  '#markup' =>
                  "<a href='" . url('node/' . $study_variable_attributes['nid']) . "'><div class='tipsy'><img src='"
                    . constant($status_image). "'><div class=\"tooltip_content\">$tooltip</div></div></a>",
                );
              }
              else {
                $option[$header_ids[$study_id]]['data'][] = array(
                  '#type' => 'markup',
                  '#markup' =>
                  "<a href='" . url('node/' . $study_variable_attributes['nid']) . "'><div class='tipsy'><img src='"
                    .  constant($status_image) . "'><div class=\"tooltip_content\"><b>".t('Status')."</b>  $status_label</div></div></a>",
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
  $output .= theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No harmonization found'), 'sticky' => FALSE));

  return $output;
}

function toHtmlTruncate($text, $label, $surrounded_tag) {
  $start = empty($surrounded_tag) ? "" : "<" . $surrounded_tag . ">";
  $end = empty($surrounded_tag) ? "" : "</" . $surrounded_tag . ">";
  $htmlTruncate = '';
  if (empty($text) === FALSE) {
    if (strlen($text) > 500) {
      $htmlTruncate
        = "<code class=\'prettyprint\'>" . $start . check_markup(truncate_utf8($text, 400, FALSE))
        . $end . "</code>[" . $label . " truncated]";
    }
    else {
      $htmlTruncate
        = "<code class=\'prettyprint\'>" . $start . check_markup($text) . $end . "</code>";
    }
  }
  return $htmlTruncate;
}

function mica_datasets_harmonization_legend_form($form, $form_state) {
  $form['legend'] = array(
    '#type' => 'container',
  );
  $form['legend']['undetermined'] = array(
    '#type' => 'markup',
    '#markup' => "<img src='".constant('mica_harmonization_undetermined')."' style='vertical-align: middle'>&nbsp;<b>Undetermined</b> -
  		<i>the harmonization potential of this variable has not yet been evaluated.</i><br>",
  );
  $form['legend']['complete'] = array(
    '#type' => 'markup',
    '#markup' => "<img src='".constant('mica_harmonization_complete')."' style='vertical-align: middle'>&nbsp;<b>Complete</b> -
  		<i> the study assessment item(s) (e.g. survey question, physical measure, biochemical measure) allow construction 
  		of the variable as defined in the dataset.</i><br>",
  );
  $form['legend']['impossible'] = array(
    '#type' => 'markup',
    '#markup' => "<img src='".constant('mica_harmonization_impossible')."' style='vertical-align: middle'>&nbsp;<b>Impossible</b> -
  		<i>there is no information or insufficient information collected by this study to allow the construction of 
  		the variable as defined in the dataset.</i>",
  );

  return $form;
}

function mica_datasets_harmonization_refresh_form($form, &$form_state, $dataset_nid, $study_nid) {  
  $connector = mica_dataset_connector_query($dataset_nid, $study_nid);
  if ($connector){
    $form['refresh'] = array(
      '#type' => 'submit',
      '#value' => 'refresh',
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


function mica_datasets_harmonization_refresh_form_submit($form, &$form_state){
  // Load the connection_entity
  $dataset_nid = $form['dataset_nid']['#value'];
  $study_nid = $form['study_nid']['#value'];
  
  $connector = mica_dataset_connector_query($dataset_nid, $study_nid);
  $opal = new MicaDatasetOpalConnectionClass($connector);
  $post = new HttpClientRequest($connector->__call("getTableResourceURI", array("variables")), array(
      'method' => 'GET',
      'headers' => array('Accept' => array('application/json')),
      'data' => array(),
      'parameters' => array(),
  ));
  $raw= $opal->client()->execute($post);
  
  $array = json_decode($raw, TRUE);
  // Support JSON lines format.
  if (!is_array($array)) {
  	$raw = preg_replace('/}\s*{/', '},{', $raw);
  	$raw = '[' . $raw . ']';
  	$array = json_decode($raw, TRUE);
  }
  
  if (is_array($array)) {
  	require_once drupal_get_path('module', 'mica_opal'). '/includes/jsonpath-0.8.1.php';//drupal_get_library('mica_opal', 'jsonpath-0.8.1.php');
  	require_once drupal_get_path('module', 'mica_datasets'). '/mica_datasets.module';
  
  	$all_items = mica_opal_jsonPath($array, '$.*');
  	unset($array);
  
		$i = 1;
  	foreach ($all_items as $item) {
  		$parsed_item = $variables = array();
  		// check if variable already exists
  		
  		$title = array_shift(mica_opal_jsonPath($item, 'name'));
  		$label = array_shift(mica_opal_jsonPath($item, 'attributes[?(@[\'name\']==\'label\')].value'));
  		$value_type = array_shift(mica_opal_jsonPath($item, 'valueType'));
  		$repeatable = array_shift(mica_opal_jsonPath($item, 'repeatable'));
  		if (empty($repeatable)){
  		  $repeatable = '0';
  		}
  		
  		$script = array_shift(mica_opal_jsonPath($item, 'attributes[?(@[\'name\']==\'script\')].value'));
      $status = array_shift(mica_opal_jsonPath($item, 'attributes[?(@[\'name\']==\'status\')].value'));
      if (empty($status)){
        $status = 'undetermined';
      }
  		$description = array_shift(mica_opal_jsonPath($item, 'attributes[?(@[\'name\']==\'description\')].value'));
  		
  		$categories_name = mica_opal_jsonPath($item, 'categories.*.name');
  		
  		$query = new EntityFieldQuery();
  		$result = $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'variable')
        ->propertyCondition('title', $title)
  		  ->fieldCondition('field_dataset', 'nid', $dataset_nid)
  		  ->execute();
  		
  		if (empty($result)){
  			global $user;
  
  			$infos = array(
  			  'type' => 'variable',
  			  'title' => $title,
  			  'language' => LANGUAGE_NONE,
  			  'uid' => $user->uid,
  			  'status' => 1,
  			  'menu' => '',
			  	'field_label' => $label,
  		  	'field_value_type' => $value_type,
  			  'field_repeatable' =>  $repeatable,
  			  'field_dataset' => $dataset_nid,
					'field_position' => $i++,
  			);

  			// categories
  			//          
  			//          'categories.*.attributes[?(@[\'name\']==\'label\')].value',
  			//          'categories.*.isMissing',
  
  			$variable = entity_property_values_create_entity('node', $infos);
  			$variable->save();
				
  		}else{
  		  $variable = entity_load_single('node', array_shift(array_keys($result['node'])));
  		  $wrapper = entity_metadata_wrapper('node', $variable);
  		  $wrapper->field_label->set($label);
  		  $wrapper->field_repeatable->set($repeatable);
  		  $wrapper->field_value_type->set($value_type);
				$wrapper->field_position->set($i++);
  		  $wrapper->save();
  		}
  		
  		//debug($variable->field_variable_study_var_att[$variable->language], null, true);
  		// Update study_variable_attributes
  		foreach ($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes){
  		  $sva = entity_load_single('node', $study_variable_attributes['nid']);
  		  
  		  if ($sva->field_sva_study[$variable->language][0]['nid'] === $study_nid){
  		    $sva_wrapper = entity_metadata_wrapper('node', $sva);
  		    $sva_wrapper->field_sva_script->set($script);
			  	$sva_wrapper->field_sva_script_status->set($status);
			  	$sva_wrapper->field_sva_comment->set($description);
			  	
			  	$sva_wrapper->save();
  		  }
  		}
  		
  		// Update categories
  		//if (!empty($categories_name)){
  		 // for ($i = 0; $i < $categories_name.lenght; $i++) {
  		 //   $wrapper->field_variable_categories[$i]->name->set();
  		  //}
  		  //$wrapper->field_variable_categories;
//     		if (!empty($wrapper->field_variable_categories)){
//     			foreach($wrapper->field_variable_categories as $category){
//     				debug($category->name->value(), null, true);
//     				break;
//     			}
//     		}
  		//}
  	}
  }
  else {
  	throw new Exception(t('There was an error decoding the JSON document.'));
  }
}

function sort_by_position($x, $y) {
  if ($x->field_position['und'][0]['value'] === $y->field_position['und'][0]['value']) {
    return 0;
  }
  else {
    if ($x->field_position['und'][0]['value'] < $y->field_position['und'][0]['value']) {
      return -1;
    }
    else {
      return 1;
    }
  }
}

/**
* Utilizes the jsonPath function from jsonpath-0.8.1.php
*
* jsonPath returns false if the expression returns zero results and that will
* mess up our for loops, so return an empty array instead.
*
* @todo
*   Firgure out error handling.
* @param $array
*   The input array to parse
* @$expression
*   The JSONPath expression.
* @return array
*   Returns an array that is the output of jsonPath
*/
function mica_opal_jsonPath($array, $expression) {
	$result = jsonPath($array, $expression);
	return ($result === FALSE) ? array() : $result;
}