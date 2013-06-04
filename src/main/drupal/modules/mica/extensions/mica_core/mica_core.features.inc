<?php
/**
 * @file
 * mica_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function mica_core_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : true, "use_page" : true },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function mica_core_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : ""
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
