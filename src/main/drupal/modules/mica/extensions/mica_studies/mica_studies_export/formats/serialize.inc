<?php

/**
 * @file
 * The Node export serialize format handler.
 *
 * Adds serialize format to Node export.
 */

/**
 * Export callback.
 */
function mica_studies_export_serialize_export($nodes, $format) {
  return 'mica_studies_export_serialize::' . htmlspecialchars(serialize($nodes));
}

/**
 * Import callback.
 */
function mica_studies_export_serialize_import($code_string) {
  // Check for 'node_export_serialize::' at the start.
  if (substr(ltrim($code_string), 0, 23) == 'mica_studies_export_serialize::') {
    return unserialize(htmlspecialchars_decode(str_replace('mica_studies_export_serialize::', '', $code_string)));
  }
}

/**
 * Callback for actions.
 */
function mica_studies_export_serialize_action_form($context, &$form_state) {
  return nmica_studies_export_action_form($context, $form_state, 'serialize');
}