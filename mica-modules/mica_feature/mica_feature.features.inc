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
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'fractures' => array(
      'name' => t('Fractures'),
      'base' => 'node_content',
      'description' => t('Information about Fractures data collected by studies.'),
      'has_title' => '1',
      'title_label' => t('Study Name'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'study' => array(
      'name' => t('Study'),
      'base' => 'node_content',
      'description' => t('Study main page.'),
      'has_title' => '1',
      'title_label' => t('Study Name'),
      'help' => '',
    ),
    'study_files' => array(
      'name' => t('Study Files'),
      'base' => 'node_content',
      'description' => t('Files of a study.'),
      'has_title' => '1',
      'title_label' => t('Study Name'),
      'help' => '',
    ),
    'study_information' => array(
      'name' => t('Study Information'),
      'base' => 'node_content',
      'description' => t('General informations about the study.'),
      'has_title' => '1',
      'title_label' => t('Study Name'),
      'help' => '',
    ),
    'variable' => array(
      'name' => t('Variable'),
      'base' => 'node_content',
      'description' => t('Variable description.'),
      'has_title' => '1',
      'title_label' => t('Variable Name'),
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
  $items['default_node_index_field_102a'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_102a",
    "index_id" : "default_node_index",
    "field" : "field_102a",
    "name" : "Number of MEN with ALL-TYPE of fracture",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Number of MEN with ALL-TYPE of fracture"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_102b'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_102b",
    "index_id" : "default_node_index",
    "field" : "field_102b",
    "name" : "Number of WOMEN with ALL-TYPE of fracture",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Number of WOMEN with ALL-TYPE of fracture"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_f100'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_f100",
    "index_id" : "default_node_index",
    "field" : "field_f100",
    "name" : "Fracture Data Available",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Fracture Data Available",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : [ "", "" ]
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_f106'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_f106",
    "index_id" : "default_node_index",
    "field" : "field_f106",
    "name" : "Discriminate between PREVALENT and INCIDENT fractures",
    "enabled" : "0",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Discriminate between PREVALENT and INCIDENT fractures",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : [ "", "" ]
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g10'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g10",
    "index_id" : "default_node_index",
    "field" : "field_g10",
    "name" : "GWA Data Available",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "GWA Data Available",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : [ "", "" ]
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g3'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g3",
    "index_id" : "default_node_index",
    "field" : "field_g3",
    "name" : "Participation",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Participation",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : { "gefos" : "GEFOS (GWA)", "genomos" : "GENOMOS" }
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g5a'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g5a",
    "index_id" : "default_node_index",
    "field" : "field_g5a",
    "name" : "Country",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Country",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : {
        "CAN" : "Canada",
        "DNK" : "Danemark",
        "FRA" : "France",
        "GBR" : "United Kingdom",
        "USA" : "United States"
      }
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g6'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g6",
    "index_id" : "default_node_index",
    "field" : "field_g6",
    "name" : "Design",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Design",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : { "1" : "Longitudinal", "2" : "Case Control", "3" : "Cross Sectional" }
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g7'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g7",
    "index_id" : "default_node_index",
    "field" : "field_g7",
    "name" : "Base",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Base",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : {
        "1" : "Population-base",
        "2" : "Family-based",
        "3" : "Clinic\\/Hospital-based"
      }
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g8'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g8",
    "index_id" : "default_node_index",
    "field" : "field_g8",
    "name" : "Type of Population",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Type of Population",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : { "1" : "Outbred", "2" : "Inbred\\/Isolate" }
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g8d'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g8d",
    "index_id" : "default_node_index",
    "field" : "field_g8d",
    "name" : "Minimum Age",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Minimum Age"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g8e'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g8e",
    "index_id" : "default_node_index",
    "field" : "field_g8e",
    "name" : "Maximum Age",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Maximum Age"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g9a'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g9a",
    "index_id" : "default_node_index",
    "field" : "field_g9a",
    "name" : "Total Number of Men (with DNA)",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Total Number of Men (with DNA)"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_g9b'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_g9b",
    "index_id" : "default_node_index",
    "field" : "field_g9b",
    "name" : "Total Number of Women (with DNA)",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Total Number of Women (with DNA)"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_study_i'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_study_i",
    "index_id" : "default_node_index",
    "field" : "field_study_info_ref:author:name",
    "name" : "Default node index: Study Information \\u00bb Author \\u00bb Name",
    "enabled" : "0",
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
      "type" : "",
      "field_name" : "Study Information \\u00bb Author \\u00bb Name"
    },
    "rdf_mapping" : []
  }');
  $items['default_node_index_field_type'] = entity_import('search_api_facet', '{
    "delta" : "default_node_index_field_type",
    "index_id" : "default_node_index",
    "field" : "field_type",
    "name" : "Type",
    "enabled" : "1",
    "options" : {
      "limit" : 10,
      "min_count" : 1,
      "sort" : "count",
      "missing" : false,
      "default_true" : true,
      "ids_list" : [],
      "type" : "options",
      "field_name" : "Type",
      "show_active" : true,
      "display_more_link" : false,
      "more_limit" : 10,
      "options" : {
        "text" : "text",
        "integer" : "integer",
        "decimal" : "decimal",
        "boolean" : "boolean",
        "locale" : "locale",
        "binary" : "binary",
        "date" : "date",
        "datetime" : "datetime"
      }
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
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "default" : "0", "bundles" : { "study" : "study" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_fulltext" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\n            h2 = 3\\r\\n            h3 = 2\\r\\n            strong = 2\\r\\n            b = 2\\r\\n            em = 1.5\\r\\n            u = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
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
        "title" : { "name" : "Title", "indexed" : 1, "type" : "text", "boost" : "5.0" },
        "language" : { "name" : "Language", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "url" : { "name" : "URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "edit_url" : { "name" : "Edit URL", "indexed" : 0, "type" : "uri", "boost" : "1.0" },
        "status" : {
          "name" : "Published",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "promote" : {
          "name" : "Promoted to frontpage",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "sticky" : {
          "name" : "Sticky in lists",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "created" : {
          "name" : "Date created",
          "indexed" : 1,
          "type" : "date",
          "boost" : "1.0"
        },
        "changed" : {
          "name" : "Date changed",
          "indexed" : 1,
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
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "comment_count_new" : {
          "name" : "New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_tags" : {
          "name" : "Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_study_info_ref" : {
          "name" : "Study Information",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_fractures_ref" : {
          "name" : "Fractures",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_study_files_ref" : {
          "name" : "Genotyping Files",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_type" : { "name" : "Type", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "field_label" : { "name" : "Label", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_categories" : {
          "name" : "Categories",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_g2" : { "name" : "Full Name", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_g3" : {
          "name" : "Participation",
          "indexed" : 1,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_g4b" : {
          "name" : "Contact Email",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_g5a" : { "name" : "Country", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "field_g6" : {
          "name" : "Design",
          "indexed" : 1,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_g7" : {
          "name" : "Base",
          "indexed" : 1,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_g8" : {
          "name" : "Type of Population",
          "indexed" : 1,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_g8c" : { "name" : "Ethnicity", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_g8d" : {
          "name" : "Minimum Age",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_g8e" : {
          "name" : "Maximum Age",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_g9a" : {
          "name" : "Total Number of Men (with DNA)",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_g9b" : {
          "name" : "Total Number of Women (with DNA)",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_g10" : {
          "name" : "GWA Data Available",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_f100" : {
          "name" : "Fracture Data Available",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_f101" : {
          "name" : "Subjects with DNA available and fracture information (fracture or no fracture)",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_102a" : {
          "name" : "Number of MEN with ALL-TYPE of fracture",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_102b" : {
          "name" : "Number of WOMEN with ALL-TYPE of fracture",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_103a" : {
          "name" : "Number of MEN with VERTEBRAL fracture",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_103b" : {
          "name" : "Number of WOMEN with VERTEBRAL fracture",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_f106" : {
          "name" : "Discriminate between PREVALENT and INCIDENT fractures",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "author:uid" : {
          "name" : "Author \\u00bb User ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "author:name" : {
          "name" : "Author \\u00bb Name",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "author:mail" : {
          "name" : "Author \\u00bb Email",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "author:url" : {
          "name" : "Author \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "author:edit_url" : {
          "name" : "Author \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "author:last_login" : {
          "name" : "Author \\u00bb Last login",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author:created" : {
          "name" : "Author \\u00bb Created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "author:roles" : {
          "name" : "Author \\u00bb User roles",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
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
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:nid" : {
          "name" : "Study Information \\u00bb Node ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:vid" : {
          "name" : "Study Information \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:is_new" : {
          "name" : "Study Information \\u00bb Is new",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_study_info_ref:type" : {
          "name" : "Study Information \\u00bb Content type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_study_info_ref:title" : {
          "name" : "Study Information \\u00bb Title",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_info_ref:language" : {
          "name" : "Study Information \\u00bb Language",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_info_ref:url" : {
          "name" : "Study Information \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_study_info_ref:edit_url" : {
          "name" : "Study Information \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_study_info_ref:status" : {
          "name" : "Study Information \\u00bb Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_study_info_ref:promote" : {
          "name" : "Study Information \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_study_info_ref:sticky" : {
          "name" : "Study Information \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_study_info_ref:created" : {
          "name" : "Study Information \\u00bb Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_study_info_ref:changed" : {
          "name" : "Study Information \\u00bb Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_study_info_ref:author" : {
          "name" : "Study Information \\u00bb Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_study_info_ref:source" : {
          "name" : "Study Information \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_study_info_ref:log" : {
          "name" : "Study Information \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_info_ref:revision" : {
          "name" : "Study Information \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_study_info_ref:comment" : {
          "name" : "Study Information \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:comment_count" : {
          "name" : "Study Information \\u00bb Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:comment_count_new" : {
          "name" : "Study Information \\u00bb New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:uid" : {
          "name" : "Study Information \\u00bb Author \\u00bb User ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:name" : {
          "name" : "Study Information \\u00bb Author \\u00bb Name",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:mail" : {
          "name" : "Study Information \\u00bb Author \\u00bb Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:url" : {
          "name" : "Study Information \\u00bb Author \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:edit_url" : {
          "name" : "Study Information \\u00bb Author \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:last_login" : {
          "name" : "Study Information \\u00bb Author \\u00bb Last login",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:created" : {
          "name" : "Study Information \\u00bb Author \\u00bb Created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_study_info_ref:author:roles" : {
          "name" : "Study Information \\u00bb Author \\u00bb User roles",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
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
