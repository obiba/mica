<?php


/**
 * Override or insert variables into the html template.
 */
function mica_samara_preprocess_html(&$vars) {

  // Add font and layout styles
  $css['font'] = 'html {font-size: ' . theme_get_setting('base_font_size') . ';}';
  $css['no-sidebars'] = '
  body.no-sidebars #navigation, body.no-sidebars #header, body.no-sidebars #main-columns, body.no-sidebars #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  $css['one-sidebar'] = '
  body.one-sidebar #navigation, body.one-sidebar #header, body.one-sidebar #main-columns, body.one-sidebar #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  $css['two-sidebars'] = '
  body.two-sidebars #navigation, body.two-sidebars #header, body.two-sidebars #main-columns, body.two-sidebars #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  drupal_add_css(implode($css), array('type' => 'inline', 'group' => CSS_THEME));

  // Add color scheme CSS
  drupal_add_css(path_to_theme() . '/styles/sch-' . theme_get_setting('color_scheme') . '.css', array('group' => CSS_THEME));

  // Add conditional CSS for IE
  drupal_add_css(path_to_theme() . '/styles/ie8.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/styles/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/styles/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}


/**
 * Override or insert variables into the page template.
 */
function mica_samara_preprocess_page(&$vars) {

  $sidebar_first_weight  = theme_get_setting('sidebar_first_weight');
  $sidebar_second_weight = theme_get_setting('sidebar_second_weight');

  $vars['left_sidebars'] = '';
  if($sidebar_first_weight == -2) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == -2) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  if($sidebar_first_weight == -1) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == -1) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  
  $vars['right_sidebars'] = '';
  if($sidebar_first_weight == 1) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == 1) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  if($sidebar_first_weight == 2) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == 2) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_second']);
  }

  // Add $navigation variable, unlike built-in $main_menu variable it supports drop-down menus
  // Does not support multilingual menu (duplicated menu entries) See: http://drupal.org/node/1225094
  if (function_exists('i18n_menu_translated_tree')){
    $vars['navigation'] = $vars['main_menu'] ? render(i18n_menu_translated_tree(variable_get('menu_main_links_source', 'main-menu'))) : FALSE;
  }
  else{
    $vars['navigation'] = $vars['main_menu'] ? render(menu_tree('main-menu')) : FALSE;
  }

  // Add $copyright_information variable
  $vars['copyright_information'] = theme_get_setting('copyright_information');

}


/**
 * Override or insert variables into the region template.
 */
function mica_samara_preprocess_region(&$vars) {

  // Remove default classes from sidebars regions
  if($vars['region'] == 'sidebar_first') {
    $vars['classes_array'] = array('clearfix');
  }
  if( $vars['region'] == 'sidebar_second') {
    $vars['classes_array'] = array('clearfix');
  }
}


/**
 * Override or insert variables into the block template.
 */
function mica_samara_preprocess_block(&$vars) {

  // Remove default classes from some regions
  if(in_array($vars['block']->region, array('content', 'content_top', 'content_bottom', 'highlight'))) {
    $vars['classes_array'] = array();
  }

}


/**
 * Overrides theme_tablesort_indicator().
 */
function mica_samara_tablesort_indicator($vars) {
  $attributes = array(
    'alt' => t('sort icon'),
  );
  if ($vars['style'] == 'asc') {
    $attributes['path']  = path_to_theme() . '/images/tablesort-ascending.png';
    $attributes['title'] = t('sort ascending');
  }
  else {
    $attributes['path']  = path_to_theme() . '/images/tablesort-descending.png';
    $attributes['title'] = t('sort descending');
  }
  return theme('image', $attributes);
}

function mica_samara_form_element($variables) {
	$element = &$variables['element'];
	
	if (key_exists('#bundle', $element) && $element['#bundle'] === 'study'){
    // This is also used in the installer, pre-database setup.
    $t = get_t();
  
    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
      '#title_display' => 'before',
    );
  
    // Add element #id for #type 'item'.
    if (isset($element['#markup']) && !empty($element['#id'])) {
      $attributes['id'] = $element['#id'];
    }
    // Add element's #type and #name as class to aid with JS/CSS selectors.
    $attributes['class'] = array('form-item');
    if (!empty($element['#type'])) {
      $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    }
    if (!empty($element['#name'])) {
      $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    }
    // Add a class for disabled elements to facilitate cross-browser styling.
    if (!empty($element['#attributes']['disabled'])) {
      $attributes['class'][] = 'form-disabled';
    }
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";
  
    // If #title is not set, we don't display any label or required marker.
    if (!isset($element['#title'])) {
      $element['#title_display'] = 'none';
    }
    $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
    $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';
    $description = !empty($element['#description']) ? '<div class="description">' . $element['#description'] . "</div>\n" : '';
    
    switch ($element['#title_display']) {
      case 'before':
      case 'invisible':
        $output .= ' ' . theme('form_element_label', $variables) . $description;
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;
  
      case 'after':
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
        $output .= ' ' . theme('form_element_label', $variables) . $description . "\n";
        break;
  
      case 'none':
      case 'attribute':
        // Output no label and no required marker, only the children.
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;
    }
    
    $output .= "</div>\n";
  
    return $output;
	}
	else{
	  return theme_form_element($variables);
	}
}

function mica_samara_field_multiple_value_form($variables) {
	$element = $variables['element'];
	$output = '';
  if (key_exists('nid', $element[0]) && $element[0]['nid']['#bundle'] === 'study'){
  	if ($element['#cardinality'] > 1 || $element['#cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
  		$table_id = drupal_html_id($element['#field_name'] . '_values');
  		$order_class = $element['#field_name'] . '-delta-order';
  		$required = !empty($element['#required']) ? theme('form_required_marker', $variables) : '';
  
  		$description = $element['#description'] ? '<div class="description" style="font-variant:normal;text-transform:none;">' . $element['#description'] . '</div>' : '';
  		$header = array(
  		  array(
          'data' => '<label>' . t('!title: !required', array('!title' => $element['#title'], '!required' => $required)) . "</label>" . $description,
          'colspan' => 2,
          'class' => array('field-label'),
  		  ),
  		t('Order'),
  		);
  		$rows = array();
  
  		// Sort items according to '_weight' (needed when the form comes back after
  		// preview or failed validation)
  		$items = array();
  		foreach (element_children($element) as $key) {
  			if ($key === 'add_more') {
  				$add_more_button = &$element[$key];
  			}
  			else {
  				$items[] = &$element[$key];
  			}
  		}
  		usort($items, '_field_sort_items_value_helper');
  
  		// Add the items as table rows.
  		foreach ($items as $key => $item) {
  			$item['_weight']['#attributes']['class'] = array($order_class);
  			$delta_element = drupal_render($item['_weight']);
  			$cells = array(
  			array('data' => '', 'class' => array('field-multiple-drag')),
  			drupal_render($item),
  			array('data' => $delta_element, 'class' => array('delta-order')),
  			);
  			$rows[] = array(
          'data' => $cells,
          'class' => array('draggable'),
  			);
  		}
  
  		$output = '<div class="form-item">';
      $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => $table_id, 'class' => array('field-multiple-table'))));
      //$output .= $element['#description'] ? '<div class="description">' . $element['#description'] . '</div>' : '';
      $output .= '<div class="clearfix">' . drupal_render($add_more_button) . '</div>';
      $output .= '</div>';
  
  		drupal_add_tabledrag($table_id, 'order', 'sibling', $order_class);
  	}
  	else {
  		foreach (element_children($element) as $key) {
  			$output .= drupal_render($element[$key]);
  		}
  	}
  
  	return $output;
  }
  else{
    return theme_field_multiple_value_form($variables);
  }
}

/**
 * Implements hook_html_head_alter()
 */
function mica_samara_html_head_alter(&$head_elements){
  // See http://drupal.org/node/1234304
  $head_elements['ie-edge'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=Edge',
    ),
  );
  return $head_elements;
}