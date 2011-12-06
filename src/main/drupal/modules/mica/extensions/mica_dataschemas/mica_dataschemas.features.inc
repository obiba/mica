<?php
/**
 * @file
 * mica_dataschemas.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_dataschemas_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mica_dataschemas_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function mica_dataschemas_node_info() {
  $items = array(
    'dataschema' => array(
      'name' => t('DataSchema'),
      'base' => 'node_content',
      'description' => t('Identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dataschema_category' => array(
      'name' => t('Category'),
      'base' => 'node_content',
      'description' => t('Defines a category'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dataschema_variable' => array(
      'name' => t('Variable'),
      'base' => 'node_content',
      'description' => t('DataSchema variable'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pairing' => array(
      'name' => t('Pairing'),
      'base' => 'node_content',
      'description' => t('Describe a pairing for a variable of a study within a dataset'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function mica_dataschemas_default_search_api_index() {
  $items = array();
  $items['dataschema_variables_index'] = entity_import('search_api_index', '{
    "name" : "DataSchema variables index",
    "machine_name" : "dataschema_variables_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "field_dataschema_ref" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "node" },
        "field_dim_biochemical_measures" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_body_functions_meas" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_class" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_collection_mode" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_disease_history" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_environmental_exp" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_format" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_life_habits_behaviours" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_medication" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_period" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_reproductive_history" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_sample" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_sociodemo_charact" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_source_of_info" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_target" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_target_gender" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_therapeutic_inter" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_dim_type" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "taxonomy_term" },
        "field_unit" : { "type" : "text" },
        "field_uri" : { "type" : "uri" },
        "field_variable_categories" : { "type" : "list\\u003cinteger\\u003e", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_dataschema_ref:title" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_biochemical_measures:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_body_functions_meas:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_class:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_collection_mode:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_disease_history:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_environmental_exp:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_format:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_life_habits_behaviours:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_medication:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_period:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_reproductive_history:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_sample:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_sociodemo_charact:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_source_of_info:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_target:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_target_gender:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_therapeutic_inter:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_dim_type:name" : { "type" : "list\\u003ctext\\u003e" },
        "field_variable_categories:title" : { "type" : "list\\u003ctext\\u003e" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "dataschema_variable" : "dataschema_variable" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_dim_biochemical_measures:parents_all" : "field_dim_biochemical_measures:parents_all",
              "field_dim_body_functions_meas:parents_all" : "field_dim_body_functions_meas:parents_all",
              "field_dim_class:parents_all" : "field_dim_class:parents_all",
              "field_dim_collection_mode:parents_all" : "field_dim_collection_mode:parents_all",
              "field_dim_disease_history:parents_all" : "field_dim_disease_history:parents_all",
              "field_dim_environmental_exp:parents_all" : "field_dim_environmental_exp:parents_all",
              "field_dim_format:parents_all" : "field_dim_format:parents_all",
              "field_dim_life_habits_behaviours:parents_all" : "field_dim_life_habits_behaviours:parents_all",
              "field_dim_medication:parents_all" : "field_dim_medication:parents_all",
              "field_dim_period:parents_all" : "field_dim_period:parents_all",
              "field_dim_reproductive_history:parents_all" : "field_dim_reproductive_history:parents_all",
              "field_dim_sample:parents_all" : "field_dim_sample:parents_all",
              "field_dim_sociodemo_charact:parents_all" : "field_dim_sociodemo_charact:parents_all",
              "field_dim_source_of_info:parents_all" : "field_dim_source_of_info:parents_all",
              "field_dim_target:parents_all" : "field_dim_target:parents_all",
              "field_dim_target_gender:parents_all" : "field_dim_target_gender:parents_all",
              "field_dim_therapeutic_inter:parents_all" : "field_dim_therapeutic_inter:parents_all",
              "field_dim_type:parents_all" : "field_dim_type:parents_all"
            }
          }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_dataschema_ref" : true,
              "field_unit" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataschema_ref:title" : true,
              "field_variable_categories:title" : true
            }
          }
        },
        "taxonomy_hierarchy_processor.inc" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_unit" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataschema_ref:title" : true,
              "field_variable_categories:title" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_unit" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataschema_ref:title" : true,
              "field_variable_categories:title" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_unit" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataschema_ref:title" : true,
              "field_variable_categories:title" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_unit" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataschema_ref:title" : true,
              "field_variable_categories:title" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
