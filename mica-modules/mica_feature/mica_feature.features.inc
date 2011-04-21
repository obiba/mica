<?php
/**
 * @file
 * mica_feature.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mica_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_feature_node_info() {
  $items = array(
    'mica_relation' => array(
      'name' => t('Mica relationship'),
      'base' => 'node_content',
      'description' => t('Relation between content types that cascade events form parent to children'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'study' => array(
      'name' => t('Study'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'study_information' => array(
      'name' => t('Study Information'),
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
 * Implementation of hook_default_search_api_facet().
 */
function mica_feature_default_search_api_facet() {
  $items = array();
  $items['studies_index_field_study_countr'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_field_study_countr",
    "index_id" : "studies_index",
    "field" : "field_study_country",
    "name" : "Country",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "display_more_link" : false,
      "more_limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "show_active" : true,
      "default_true" : true,
      "ids_list" : [],
      "type" : "string",
      "field_name" : "Country"
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_index().
 */
function mica_feature_default_search_api_index() {
  $items = array();
  $items['studies_index'] = entity_import('search_api_index', '{
    "name" : "Studies Index",
    "machine_name" : "studies_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "fields" : {
        "search_api_language" : {
          "name" : "Item language",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "nid" : { "name" : "Node ID", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "vid" : {
          "name" : "Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "is_new" : { "name" : "Is new", "indexed" : 0, "type" : "boolean", "boost" : "1.0" },
        "type" : {
          "name" : "Content type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "title" : { "name" : "Title", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "language" : { "name" : "Language", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "url" : { "name" : "URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "edit_url" : { "name" : "Edit URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "status" : {
          "name" : "Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "promote" : {
          "name" : "Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "sticky" : {
          "name" : "Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "created" : {
          "name" : "Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "changed" : {
          "name" : "Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author" : {
          "name" : "Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "source" : {
          "name" : "Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "log" : {
          "name" : "Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "revision" : {
          "name" : "Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "comment" : {
          "name" : "Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count" : {
          "name" : "Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count_new" : {
          "name" : "New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "parent_type" : {
          "name" : "Parent content type machine name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "child_type" : {
          "name" : "Child content type machine name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "node_reference_name" : {
          "name" : "Node reference name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tags" : {
          "name" : "Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "mica_study_information" : {
          "name" : "Study Information",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_study_full_name" : { "name" : "Full Name", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_study_contact_email" : {
          "name" : "Contact Email",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_country" : { "name" : "Country", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "body:value" : {
          "name" : "The main body text \\u00bb Text",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:summary" : {
          "name" : "The main body text \\u00bb Summary",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:format" : {
          "name" : "The main body text \\u00bb Text format",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "default" : "0",
            "bundles" : { "study" : "study", "study_information" : "study_information" }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_fulltext" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_processor_study_fields" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_server().
 */
function mica_feature_default_search_api_server() {
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
