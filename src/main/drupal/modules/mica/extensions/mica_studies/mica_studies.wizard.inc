<?php

function mica_studies_add_wizard($js = NULL, $step = NULL){
  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
  }

  // Define array for ctools multistep wizard.
  $form_info = array(
    'id' => 'multi_example',
    'path' => "example/" . ($js ? 'ajax' : 'nojs') . "/form/%step",
    'show trail' => TRUE,
    'show back' => TRUE,
    'show cancel' => TRUE,
    'show return' => FALSE,
    'next callback' =>  'multi_example_wizard_next',
    'finish callback' => 'multi_example_wizard_finish',
    'cancel callback' => 'multi_example_wizard_cancel',

    // Define forms order.
    'order' => array(
      'study' => t('Edit Study'),
      'population' => t('Edit Population'),
      'collection_event' => t('Edit Data Collection Event'),
    ),


    //  'study_node_form'
//  'population_node_form':
//  'data_collection_event_node_form':

    // Define forms
    'forms' => array(
      'study' => array(
        'form id' => 'multi_example_form_start'
      ),
      'population' => array(
        'form id' => 'multi_example_form_second'
      ),
      'collection_event' => array(
        'form id' => 'multi_example_form_third'
      ),
    ),
  );

  $object_id = 1;

  if (empty($step)) {

    // We reset the form when $step is NULL because that means they have
    // for whatever reason started over.
    multi_example_cache_clear($object_id);
    $step = 'study';
  }

  // This automatically gets defaults if there wasn't anything saved.
  $object = multi_example_cache_get($object_id);

  // live $form_state changes.
  $form_state = array(
    'ajax' => $js,

    // Put our object and ID into the form state cache so we can easily find it.
    'object_id' => $object_id,
    'object' => &$object,
  );

  // Send this all off to our form. This is like drupal_get_form only wizardy.
  ctools_include('wizard');
  $form = ctools_wizard_multistep_form($form_info, $step, $form_state);
  $output = drupal_render($form);
  if ($js) {

    // If javascript is active, we have to use a render array.
    $commands = array();
    if ($output === FALSE || !empty($form_state['complete'])) {
      // Dismiss the modal.
      $commands[] = ajax_command_html('#ctools-sample', render(multi_example_get_result($object)));
      $commands[] = ctools_modal_command_dismiss();
    }
    elseif (!empty($form_state['cancel'])) {

      // If cancelling, return to the activity.
      $commands[] = ctools_modal_command_dismiss();
    }
    else {
      $commands = ctools_modal_form_render($form_state, $output);
    }
    print ajax_render($commands);
  }
  else {
    if ($output === FALSE || !empty($form_state['complete'])) {

      return render(multi_example_get_result($object)) . "\n\r" . l(t('Back'), 'example-link');
    }
    elseif (!empty($form_state['cancel'])) {
      drupal_goto('example-link');
    }
    else {
      return $output;
    }
  }
}


/**
 * Clears the wizard cache.
 *
 * @param integer $id
 *   cache id.
 */
function multi_example_cache_clear($id) {
  ctools_include('object-cache');
  ctools_object_cache_clear('multi_example', $id);
}

/**
 * Stores our little cache so that we can retain data from form to form.
 *
 * @param integer $id
 *   cache id.
 * @param object $object
 *   object with form values.
 */
function multi_example_cache_set($id, $object) {
  ctools_include('object-cache');
  ctools_object_cache_set('multi_example', $id, $object);
}

/**
 * Gets the current object from the cache, or default.
 *
 * @param integer $id
 *   cache id.
 *
 * @return object
 *   cache with stored stuff.
 */
function multi_example_cache_get($id) {
  ctools_include('object-cache');
  $object = ctools_object_cache_get('multi_example', $id);
  if (!$object) {
    // Create a default object.
    $object = new stdClass;
  }

  return $object;
}

/**
 * Handles the 'next' click on the add/edit pane form wizard.
 *
 * All we need to do is store the updated pane in the cache.
 */
function multi_example_wizard_next(&$form_state) {
  multi_example_cache_set($form_state['object_id'], $form_state['object']);
}

/**
 * Handles the 'finish' click on teh add/edit pane form wizard.
 *
 * All we need to do is set a flag so the return can handle adding
 * the pane.
 */
function multi_example_wizard_finish(&$form_state) {
  $form_state['complete'] = TRUE;
}

/**
 * Handles the 'cancel' click on the add/edit pane form wizard.
 */
function multi_example_wizard_cancel(&$form_state) {
  $form_state['cancel'] = TRUE;
}

/**
 * Generates first form.
 *
 * @ingroup forms
 */
function multi_example_form_start($form, &$form_state) {

  $node = new StdClass();
//creating a bare node

  $node->type = 'study';
  return node_form($form, $form_state, $node);
}

/**
 * Handles submit of first form.
 */
function multi_example_form_start_submit($form, &$form_state) {
  $form_state['object']->name = $form_state['values']['name'];
  $form_state['object']->surname = $form_state['values']['surname'];
}

/**
 * Generates second form.
 *
 * @ingroup forms
 */
function multi_example_form_second($form, &$form_state) {
  $form['know'] = array(
    '#type'          => 'checkboxes',
    '#options'       => array('php' => t('PHP'), 'css' => t('CSS'), 'jquery' => t('Jquery'), 'unix' => t('Unix')),
    '#default_value' => isset($form_state['object']->know) ? $form_state['object']->know : array(),
  );
  return $form;
}

/**
 * Handles submit for second form.
 */
function multi_example_form_second_submit($form, &$form_state) {
  $form_state['object']->know = $form_state['values']['know'];
}

/**
 * Generates third form.
 *
 * @ingroup forms
 */
function multi_example_form_third($form, &$form_state) {
  $form['drupal'] = array(
    '#type'          => 'radios',
    '#options'       => array('awesome' => t('Awesome'), 'awful' => t('Awful')),
    '#default_value' => isset($form_state['object']->drupal) ? $form_state['object']->drupal : '',
    '#default_value' => 'awesome',
    '#required'      => TRUE,
  );
  return $form;
}

/**
 * Handles submit for third form.
 */
function multi_example_form_third_submit(&$form, &$form_state) {
  $form_state['object']->drupal = $form_state['values']['drupal'];
}

/**
 * Returns form results.
 *
 * @param object $object
 *   object with form values.
 *
 * @return array
 *   returns renderable array for multistep form result output.
 */
function multi_example_get_result($object) {
  $out = array();
  $out[] = t('Your name: @name', array('@name' => $object->name));
  $out[] = t('Your surname: @surname', array('@surname' => $object->surname));
  $known = array_filter($object->know);
  if (count($known)) {
    $out[] = t('Your know: !know', array('!know' => implode(', ', $known)));
  }
  else {
    $out[] = t("You don't know anything");
  }
  $out[] = t('You think drupal is !mind', array('!mind' => $object->drupal));
  if ($object->work == 'yes') {
    $out[] = t('You like cookies :)');
  }
  else {
    $out[] = t("You don't like cookies :(");
  }
  return array('#theme' => 'item_list', '#items' => $out, '#title' => t('Results:'));
}