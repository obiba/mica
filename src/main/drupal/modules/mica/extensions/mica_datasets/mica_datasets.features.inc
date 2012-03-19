<?php
/**
 * @file
 * mica_datasets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_datasets_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_views_api().
 */
function mica_datasets_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mica_datasets_node_info() {
  $items = array(
    'dataset' => array(
      'name' => t('Dataset'),
      'base' => 'node_content',
      'description' => t('Dataset resource.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'variable' => array(
      'name' => t('Variable'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function mica_datasets_default_search_api_index() {
  $items = array();
  $items['variable_index'] = entity_import('search_api_index', '{
    "name" : "Variables Index",
    "machine_name" : "variable_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "-1",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "string" },
        "field_repeatable" : { "type" : "boolean" },
        "field_value_type" : { "type" : "string" },
        "field_data_sources" : { "type" : "list\\u003Cstring\\u003E" },
        "field_data_sources_sp" : { "type" : "text" },
        "field_anthropometric_structures" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_body_functions" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_body_structures" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_data_source" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dataset" : { "type" : "integer", "entity_type" : "node" },
        "field_disease_history" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_early_life" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_essence" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_label" : { "type" : "string" },
        "field_life_habits_behaviours" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_measure" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_medical_health_interv" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_medication" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_perception_of_health" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_period" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_physical_environment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_position" : { "type" : "integer" },
        "field_reproductive_history" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_social_environment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sociodemographic_charact" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_dataset:nid" : { "type" : "integer" },
        "field_dataset:title" : { "type" : "text" },
        "field_variable_categories:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_variable_categories:label" : { "type" : "list\\u003Ctext\\u003E" },
        "field_variable_categories:missing" : { "type" : "list\\u003Cboolean\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "variable" : "variable" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title and Label",
                "type" : "fulltext",
                "fields" : [ "title", "field_original_field_label", "field_label" ],
                "description" : "A Fulltext aggregation of the following fields: Title, Label, Label."
              }
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_label" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_dataset:title" : true,
              "field_variable_categories:name" : true,
              "field_variable_categories:label" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "search_api_aggregation_1" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
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
