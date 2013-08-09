<?php
/**
 * @file
 * mica_devel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_devel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
