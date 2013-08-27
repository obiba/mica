<?php

/**
 * @file
 * The Node export JSON format handler.
 *
 * Adds JSON format to Node export.
 */

/**
 * Export callback.
 */
function mica_studies_export_json_export($nodes, $format) {
  return drupal_json_encode(node_export_json_encode_objects($nodes));
}

/**
 * Import callback.
 */
function mica_studies_export_json_import($code_string) {
  return mica_studies_export_json_decode_objects(drupal_json_decode($code_string));
}

/**
 * Mark objects as being objects.
 */
function mica_studies_export_json_encode_objects($var) {
  if (is_object($var)) {
    $var = (array)$var;
    $var['#node_export_object'] = '1';
  }
  if (is_array($var)) {
    foreach ($var as $key => $value) {
      $var[$key] = mica_studies_export_json_encode_objects($value);
    }
  }
  return $var;
}

/**
 * Recursively convert arrays back to objects.
 */
function mica_studies_export_json_decode_objects($array) {
  if (is_array($array)) {
    foreach ($array as $k => $v) {
      if (is_array($v)) {
        $array[$k] = mica_studies_export_json_decode_objects($v);
      }
    }
    if (isset($array['#node_export_object'])) {
      unset($array['#node_export_object']);
      $array = (object)$array;
    }
    return $array;
  }
}

/**
 * Callback for actions.
 */
function mica_studies_export_json_action_form($context, &$form_state) {
  return mica_studies_export_action_form($context, $form_state, 'json');
}