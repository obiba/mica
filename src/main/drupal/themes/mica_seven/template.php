<?php

function mica_seven_form_element($variables) {
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

function mica_seven_field_multiple_value_form($variables) {
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
