<?php
/**
 * @file
 * mica_publications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_publications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mica_publications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function mica_publications_field_default_field_bases_alter(&$data) {
  if (isset($data['field_publication_pmid'])) {
    $data['field_publication_pmid']['translatable'] = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_default_search_api_index_alter().
 */
function mica_publications_default_search_api_index_alter(&$data) {
  if (isset($data['publications'])) {
    $data['publications']->options['fields']['field_category'] = array(
      'type' => 'list<integer>',
      'entity_type' => 'taxonomy_term',
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function mica_publications_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__publication'])) {
    $data['field_bundle_settings_node__publication']->value['extra_fields']['display']['language'] = array(
      'teaser' => array(
        'weight' => 0,
        'visible' => FALSE,
      ),
    ); /* WAS: '' */
    $data['field_bundle_settings_node__publication']->value['extra_fields']['form']['language'] = array(
      'weight' => -50,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__publication']->value['extra_fields']['form']['path'] = array(
      'weight' => 30,
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function mica_publications_views_default_views_alter(&$data) {
  if (isset($data['publication_search'])) {
    $data['publication_search']->display['default']->display_options['fields']['field_category'] = array(
      'id' => 'field_category',
      'table' => 'search_api_index_publications',
      'field' => 'field_category',
      'label' => 'Tags :',
      'element_label_colon' => FALSE,
      'hide_empty' => TRUE,
      'link_to_entity' => 0,
      'view_mode' => 'full',
      'bypass_access' => 0,
    ); /* WAS: '' */
    unset($data['publication_search']->display['default']->display_options['fields']['field_abstract']);
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function mica_publications_default_search_api_index() {
  $items = array();
  $items['publications'] = entity_import('search_api_index', '{
    "name" : "Publications",
    "machine_name" : "publications",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_authors" : { "type" : "list\\u003Cstring\\u003E" },
        "field_publication_reference" : { "type" : "text" },
        "field_contacts_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_pubmedid" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_combined" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "publication count",
                "type" : "count",
                "fields" : [ "nid" ],
                "description" : "A Count aggregation of the following fields: Node ID."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "language", "languages" : [] }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "nid" : true, "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_authors" : true,
              "field_publication_reference" : true
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
            "fields" : { "title" : true, "field_publication_reference" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_authors" : true,
              "field_publication_reference" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
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
