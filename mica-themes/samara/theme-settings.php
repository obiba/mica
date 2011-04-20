<?php
// $Id:

/**
 * @file
 * Theme setting callbacks for the Samara theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function samara_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['common'] = array(
    '#title' => t('Samara common settings'), 
    '#type' => 'fieldset',
  );

  $form['common']['color_scheme'] = array(
    '#type' => 'select',
    '#title' => t('Color scheme'),
    '#default_value' => theme_get_setting('color_scheme'),
    '#options' => array(
      'default' => t('default'),
      'dark'   => t('dark'),
    ),
  );
  $form['common']['base_font_size'] = array(
    '#title' => t('Base font size'),
    '#type' => 'select', 
    '#default_value' => theme_get_setting('base_font_size'),
    '#options' => array(
      '9px'  => '9px',
      '10px' => '10px',
      '11px' => '11px',
      '12px' => '12px',
      '13px' => '13px',
      '14px' => '14px',
      '15px' => '15px',
      '16px' => '16px',
      '100%' => '100%',
    ),
  );
  $form['common']['sidebar_first_weight'] = array(
    '#title' => t('First sidebar position'),
    '#type' => 'select',
    '#default_value' => theme_get_setting('sidebar_first_weight'),
    '#options' => array(
      -2 => 'Far left',
      -1 => 'Left',
       1 => 'Right',
       2 => 'Far right',
    ),
  );
  $form['common']['sidebar_second_weight'] = array(
    '#title' => t('Second sidebar position'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('sidebar_second_weight'),
    '#options' => array(
      -2 => 'Far left',
      -1 => 'Left',
       1 => 'Right',
       2 => 'Far right',
    ),
  );
  $form['layout_1'] = array(
    '#title' => t('1-column layout'), 
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );
  $form['layout_1']['layout_1_width'] = array(
    '#title' => t('Width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_1_width'),
    '#options' => samara_generate_array(30, 100, 5, '%'),
  );
  $form['layout_1']['layout_1_min_width'] = array(
    '#title' => t('Min width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_1_min_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['layout_1']['layout_1_max_width'] = array(
    '#title' => t('Max width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_1_max_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['layout_2'] = array(
    '#title' => t('2-column layout'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );
  $form['layout_2']['layout_2_width'] = array(
    '#title' => t('Width'),
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_2_width'),
    '#options' => samara_generate_array(30, 100, 5, '%'),
  );
  $form['layout_2']['layout_2_min_width'] = array(
    '#title' => t('Min width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_2_min_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['layout_2']['layout_2_max_width'] = array(
    '#title' => t('Max width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_2_max_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['layout_3'] = array(
    '#title' => t('3-column layout'), 
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );
  $form['layout_3']['layout_3_width'] = array(
    '#title' => t('Width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_3_width'),
    '#options' => samara_generate_array(30, 100, 5, '%'),
  );
  $form['layout_3']['layout_3_min_width'] = array(
    '#title' => t('Min width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_3_min_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['layout_3']['layout_3_max_width'] = array(
    '#title' => t('Max width'), 
    '#type' => 'select',
    '#default_value' => theme_get_setting('layout_3_max_width'),
    '#options' => samara_generate_array(200, 1200, 10, 'px'),
  );
  $form['copyright_information'] = array(
    '#title' => t('Copyright information'),
    '#description' => t('Information about copyright holder of the website - will show up at the bottom of the page'), 
    '#type' => 'textfield',
    '#default_value' => theme_get_setting('copyright_information'),
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => FALSE,
  );

  return $form;
}


/**
 * Generate options array
 */
function samara_generate_array($min, $max, $increment, $postfix, $unlimited = NULL) {
  $array = array();
  if ($unlimited == 'first') {
    $array['none'] = t('Unlimited');
  }
  for ($a = $min; $a <= $max; $a += $increment) {
    $array[$a . $postfix] = $a . ' ' . $postfix;
  }
  if ($unlimited == 'last') {
    $array['none'] = t('Unlimited');
  }
  return $array;
}
