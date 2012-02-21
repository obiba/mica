<?php
/**
 * @file
 * mica_datasets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_datasets_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function mica_datasets_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
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
    'participant_variable' => array(
      'name' => t('Participant Variable'),
      'base' => 'node_content',
      'description' => t('Description of participant data.'),
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
  $items['participant_variable_index'] = entity_import('search_api_index', '{
    "name" : "Participant Variable Index",
    "machine_name" : "participant_variable_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "field_categories" : { "type" : "list\\u003Ctext\\u003E" },
        "field_repeatable" : { "type" : "boolean" },
        "field_value_type" : { "type" : "string" },
        "field_dataset" : { "type" : "integer", "entity_type" : "node" },
        "field_label" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "field_dataset:nid" : { "type" : "integer" },
        "field_dataset:title" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "participant_variable" : "participant_variable" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title and Label",
                "type" : "fulltext",
                "fields" : [ "title", "field_label" ],
                "description" : "A Fulltext aggregation of the following fields: Title, Label."
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
              "mica_dataset" : true,
              "field_label" : true,
              "mica_dataset:title" : true
            }
          }
        },
        "taxonomy_hierarchy_processor.inc" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "mica_dataset:title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "mica_dataset:title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "mica_dataset" : true, "search_api_aggregation_1" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "mica_dataset:title" : true },
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
