<?php
/**
 * @file
 * mica_dataschemas.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_dataschemas_ctools_plugin_api() {
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
 * Implementation of hook_views_api().
 */
function mica_dataschemas_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_dataschemas_node_info() {
  $items = array(
    'category' => array(
      'name' => t('Category'),
      'base' => 'node_content',
      'description' => t('Defines a category'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dataschema' => array(
      'name' => t('DataSchema'),
      'base' => 'node_content',
      'description' => t('Identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_variable' => array(
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
 * Implementation of hook_default_search_api_facet().
 */
function mica_dataschemas_default_search_api_facet() {
  $items = array();
  $items['dataschema_variables_field_datas'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_datas",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dataschema_ref",
    "name" : "Dataschema facet",
    "enabled" : "1",
    "options" : {
      "limit" : "10",
      "display_more_link" : 0,
      "more_limit" : "10",
      "min_count" : "1",
      "sort" : "count",
      "missing" : 1,
      "show_active" : 1,
      "default_true" : true,
      "ids_list" : [],
      "type" : "",
      "field_name" : "DataSchema",
      "entity_type" : "node"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_di_10'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_di_10",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_socioeco",
    "name" : "Socioeconomic characteristics facet",
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
      "type" : "",
      "field_name" : "Socioeconomic characteristics"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_1'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_1",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_collection_mode",
    "name" : "Collection mode facet",
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
      "type" : "",
      "field_name" : "Collection mode",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_2'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_2",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_target",
    "name" : "Target facet",
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
      "type" : "",
      "field_name" : "Target",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_3'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_3",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_target_gender",
    "name" : "Target gender facet",
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
      "type" : "",
      "field_name" : "Target gender",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_4'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_4",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_source_of_info",
    "name" : "Source of information facet",
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
      "type" : "",
      "field_name" : "Source of information",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_5'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_5",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_body_structure",
    "name" : "Body structure facet",
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
      "type" : "",
      "field_name" : "Body structure"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_6'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_6",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_disease_history",
    "name" : "Disease history (ICD10) facet",
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
      "type" : "",
      "field_name" : "Disease history (ICD10)"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_7'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_7",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_physical_env",
    "name" : "Physical environment facet",
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
      "type" : "",
      "field_name" : "Physical environment"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_8'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_8",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_social_env",
    "name" : "Social environment facet",
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
      "type" : "",
      "field_name" : "Social environment"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_9'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_9",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_sociodemo_charact",
    "name" : "Sociodemographic characteristics facet",
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
      "type" : "",
      "field_name" : "Sociodemographic characteristics"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_b'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_b",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_body_functions",
    "name" : "Body functions facet",
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
      "type" : "",
      "field_name" : "Body functions"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_c'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_c",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_class",
    "name" : "Class facet",
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
      "type" : "",
      "field_name" : "Class",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_d'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_d",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_disease",
    "name" : "Disease facet",
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
      "type" : "",
      "field_name" : "Disease",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_f'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_f",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_format",
    "name" : "Format facet",
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
      "type" : "",
      "field_name" : "Format",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_h'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_h",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_health_information",
    "name" : "Health information facet",
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
      "type" : "",
      "field_name" : "Health information"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_l'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_l",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_life_habits_behaviours",
    "name" : "Life habits \\/ Behaviours facet",
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
      "type" : "",
      "field_name" : "Life habits \\/ Behaviours"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_m'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_m",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_med_health_interv",
    "name" : "Medical health intervention facet",
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
      "type" : "",
      "field_name" : "Medical health intervention",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_p'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_p",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_period",
    "name" : "Period facet",
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
      "type" : "",
      "field_name" : "Period",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_s'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_s",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_sample",
    "name" : "Sample facet",
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
      "type" : "",
      "field_name" : "Sample",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_t'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_t",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_type",
    "name" : "Type facet",
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
      "type" : "",
      "field_name" : "Type",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_index().
 */
function mica_dataschemas_default_search_api_index() {
  $items = array();
  $items['dataschema_variables_index'] = entity_import('search_api_index', '{
    "name" : "DataSchema variables index",
    "machine_name" : "dataschema_variables_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "100",
      "index_directly" : 1,
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
        "taxonomy_forums" : {
          "name" : "Forums",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_tags" : {
          "name" : "Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_is_missing" : { "name" : "Missing", "indexed" : 0, "type" : "boolean", "boost" : "1.0" },
        "field_name" : { "name" : "Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_computation_variables" : {
          "name" : "Computation Source Variables",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_contraindication_variables" : {
          "name" : "Contraindication variables",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dataschema_ref" : {
          "name" : "DataSchema",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dim_class" : {
          "name" : "Class",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_collection_mode" : {
          "name" : "Collection mode",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_disease" : {
          "name" : "Disease",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_format" : {
          "name" : "Format",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv" : {
          "name" : "Medical health intervention",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_period" : {
          "name" : "Period",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_sample" : {
          "name" : "Sample",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_source_of_info" : {
          "name" : "Source of information",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_target" : {
          "name" : "Target",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_target_gender" : {
          "name" : "Target gender",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_type" : {
          "name" : "Type",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_interpretation_variables" : {
          "name" : "Interpretation Variables",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_unit" : { "name" : "Unit", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_uri" : { "name" : "URI", "indexed" : 1, "type" : "uri", "boost" : "1.0" },
        "field_variable_categories" : {
          "name" : "Categories",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dim_body_functions" : {
          "name" : "Body functions",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_body_structure" : {
          "name" : "Body structure",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_disease_history" : {
          "name" : "Disease history (ICD10)",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_health_information" : {
          "name" : "Health information",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours" : {
          "name" : "Life habits \\/ Behaviours",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_physical_env" : {
          "name" : "Physical environment",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_social_env" : {
          "name" : "Social environment",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact" : {
          "name" : "Sociodemographic characteristics",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_socioeco" : {
          "name" : "Socioeconomic characteristics",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_match" : { "name" : "Match", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_project" : {
          "name" : "Project",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_study" : {
          "name" : "Study",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_variable" : {
          "name" : "Variable",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_categories" : {
          "name" : "Categories",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dataset" : {
          "name" : "Dataset",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_label" : { "name" : "Label", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_repeatable" : {
          "name" : "Repeatable",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_value_type" : {
          "name" : "Value Type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_studies" : {
          "name" : "Studies",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_bundle" : {
          "name" : "Content Type",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_bundle_label" : {
          "name" : "Content Type Label",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_original_field_label" : { "name" : "Label", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_original_field_name" : { "name" : "Field Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "mica_dataset" : {
          "name" : "Datasets",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_contact" : {
          "name" : "Contacts",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_full_name" : { "name" : "Full Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_investigator" : {
          "name" : "Investigators",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_study_legacy_id" : {
          "name" : "Legacy Id",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_target_number_biosamples" : {
          "name" : "Target number of biological samples",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_target_number_participants" : {
          "name" : "Target number of participants",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_documents" : {
          "name" : "Study Documents",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "mica_study_information" : {
          "name" : "Study Information",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_authors" : {
          "name" : "Authors",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_publication_pmid" : { "name" : "PMID", "indexed" : 0, "type" : "integer", "boost" : "1.0" },
        "field_publication_reference" : { "name" : "Reference", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_daco" : {
          "name" : "Data Access Committee member",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_contact_email" : { "name" : "Email", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_institution" : {
          "name" : "Institution",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_telephone" : { "name" : "Telephone", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_city" : { "name" : "City", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_country_text" : { "name" : "Country", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_data_access_review" : {
          "name" : "Data Access Review",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dataset_access" : {
          "name" : "Dataset",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_institution_name" : {
          "name" : "Institution Name",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_postal_code" : {
          "name" : "Postal Code",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_rep_email" : {
          "name" : "Representative Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_street" : { "name" : "Street", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_data_access" : {
          "name" : "Data Access Request",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_review_notes" : { "name" : "Notes", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_review_status" : { "name" : "Status", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_teleconference_description" : {
          "name" : "Description",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_access" : {
          "name" : "Access to the following features is provided or foreseen",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_access_other" : {
          "name" : "Oher type of access",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_age_max" : {
          "name" : "Maximum age selection criteria",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_age_min" : {
          "name" : "Minimum age selection criteria",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_biosamples_collected" : {
          "name" : "Biological samples collected",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_biosamples_collected_other" : {
          "name" : "Other type of samples collected",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_biosamples_tissues" : {
          "name" : "Type of tissues collected",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_design" : {
          "name" : "Baseline design of the study",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_design_other" : {
          "name" : "Other type of design",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_design_target" : {
          "name" : "Recruitment targets",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_gender" : {
          "name" : "Gender selection criteria",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_gwas_analysis" : {
          "name" : "Proceeding to genome-wide association (GWA) analysis",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_gwas_number" : {
          "name" : "GWA approximate number of participants",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_selection_criteria" : {
          "name" : "Selection criteria \\/ Charactecteristic of the population",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_status_end" : {
          "name" : "Study end year",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_status_start" : {
          "name" : "Study start year",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_country" : {
          "name" : "Country selection criteria",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_target_other" : {
          "name" : "Other type of target",
          "indexed" : 0,
          "type" : "text",
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
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "body:format" : {
          "name" : "The main body text \\u00bb Text format",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dataschema_ref:nid" : {
          "name" : "DataSchema \\u00bb Node ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataschema_ref:vid" : {
          "name" : "DataSchema \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataschema_ref:is_new" : {
          "name" : "DataSchema \\u00bb Is new",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataschema_ref:type" : {
          "name" : "DataSchema \\u00bb Content type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dataschema_ref:title" : {
          "name" : "DataSchema \\u00bb Title",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataschema_ref:language" : {
          "name" : "DataSchema \\u00bb Language",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataschema_ref:url" : {
          "name" : "DataSchema \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_dataschema_ref:edit_url" : {
          "name" : "DataSchema \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_dataschema_ref:status" : {
          "name" : "DataSchema \\u00bb Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataschema_ref:promote" : {
          "name" : "DataSchema \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataschema_ref:sticky" : {
          "name" : "DataSchema \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataschema_ref:created" : {
          "name" : "DataSchema \\u00bb Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_dataschema_ref:changed" : {
          "name" : "DataSchema \\u00bb Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_dataschema_ref:author" : {
          "name" : "DataSchema \\u00bb Author",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_dataschema_ref:source" : {
          "name" : "DataSchema \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dataschema_ref:log" : {
          "name" : "DataSchema \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataschema_ref:revision" : {
          "name" : "DataSchema \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataschema_ref:comment" : {
          "name" : "DataSchema \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataschema_ref:comment_count" : {
          "name" : "DataSchema \\u00bb Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataschema_ref:comment_count_new" : {
          "name" : "DataSchema \\u00bb New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dim_class:tid" : {
          "name" : "Class \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:name" : {
          "name" : "Class \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:description" : {
          "name" : "Class \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:weight" : {
          "name" : "Class \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:node_count" : {
          "name" : "Class \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:url" : {
          "name" : "Class \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_class:vocabulary" : {
          "name" : "Class \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_class:parent" : {
          "name" : "Class \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:tid" : {
          "name" : "Collection mode \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:name" : {
          "name" : "Collection mode \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:description" : {
          "name" : "Collection mode \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:weight" : {
          "name" : "Collection mode \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:node_count" : {
          "name" : "Collection mode \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:url" : {
          "name" : "Collection mode \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:vocabulary" : {
          "name" : "Collection mode \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_collection_mode:parent" : {
          "name" : "Collection mode \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_disease:tid" : {
          "name" : "Disease \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:name" : {
          "name" : "Disease \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:description" : {
          "name" : "Disease \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:weight" : {
          "name" : "Disease \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:node_count" : {
          "name" : "Disease \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:url" : {
          "name" : "Disease \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease:vocabulary" : {
          "name" : "Disease \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_disease:parent" : {
          "name" : "Disease \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_format:tid" : {
          "name" : "Format \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:name" : {
          "name" : "Format \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:description" : {
          "name" : "Format \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:weight" : {
          "name" : "Format \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:node_count" : {
          "name" : "Format \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:url" : {
          "name" : "Format \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format:vocabulary" : {
          "name" : "Format \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_format:parent" : {
          "name" : "Format \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:tid" : {
          "name" : "Medical health intervention \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:name" : {
          "name" : "Medical health intervention \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:description" : {
          "name" : "Medical health intervention \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:weight" : {
          "name" : "Medical health intervention \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:node_count" : {
          "name" : "Medical health intervention \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:url" : {
          "name" : "Medical health intervention \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:vocabulary" : {
          "name" : "Medical health intervention \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_med_health_interv:parent" : {
          "name" : "Medical health intervention \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_period:tid" : {
          "name" : "Period \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:name" : {
          "name" : "Period \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:description" : {
          "name" : "Period \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:weight" : {
          "name" : "Period \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:node_count" : {
          "name" : "Period \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:url" : {
          "name" : "Period \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_period:vocabulary" : {
          "name" : "Period \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_period:parent" : {
          "name" : "Period \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_sample:tid" : {
          "name" : "Sample \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:name" : {
          "name" : "Sample \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:description" : {
          "name" : "Sample \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:weight" : {
          "name" : "Sample \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:node_count" : {
          "name" : "Sample \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:url" : {
          "name" : "Sample \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sample:vocabulary" : {
          "name" : "Sample \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_sample:parent" : {
          "name" : "Sample \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:tid" : {
          "name" : "Source of information \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:name" : {
          "name" : "Source of information \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:description" : {
          "name" : "Source of information \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:weight" : {
          "name" : "Source of information \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:node_count" : {
          "name" : "Source of information \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:url" : {
          "name" : "Source of information \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:vocabulary" : {
          "name" : "Source of information \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_source_of_info:parent" : {
          "name" : "Source of information \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_target:tid" : {
          "name" : "Target \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:name" : {
          "name" : "Target \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:description" : {
          "name" : "Target \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:weight" : {
          "name" : "Target \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:node_count" : {
          "name" : "Target \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:url" : {
          "name" : "Target \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target:vocabulary" : {
          "name" : "Target \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_target:parent" : {
          "name" : "Target \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_target_gender:tid" : {
          "name" : "Target gender \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:name" : {
          "name" : "Target gender \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:description" : {
          "name" : "Target gender \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:weight" : {
          "name" : "Target gender \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:node_count" : {
          "name" : "Target gender \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:url" : {
          "name" : "Target gender \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_target_gender:vocabulary" : {
          "name" : "Target gender \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_target_gender:parent" : {
          "name" : "Target gender \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_type:tid" : {
          "name" : "Type \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:name" : {
          "name" : "Type \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:description" : {
          "name" : "Type \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:weight" : {
          "name" : "Type \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:node_count" : {
          "name" : "Type \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:url" : {
          "name" : "Type \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type:vocabulary" : {
          "name" : "Type \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_type:parent" : {
          "name" : "Type \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_variable_categories:nid" : {
          "name" : "Categories \\u00bb Node ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:vid" : {
          "name" : "Categories \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:is_new" : {
          "name" : "Categories \\u00bb Is new",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:type" : {
          "name" : "Categories \\u00bb Content type",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:title" : {
          "name" : "Categories \\u00bb Title",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:language" : {
          "name" : "Categories \\u00bb Language",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:url" : {
          "name" : "Categories \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:edit_url" : {
          "name" : "Categories \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:status" : {
          "name" : "Categories \\u00bb Published",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:promote" : {
          "name" : "Categories \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:sticky" : {
          "name" : "Categories \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:created" : {
          "name" : "Categories \\u00bb Date created",
          "indexed" : 0,
          "type" : "list\\u003cdate\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:changed" : {
          "name" : "Categories \\u00bb Date changed",
          "indexed" : 0,
          "type" : "list\\u003cdate\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:author" : {
          "name" : "Categories \\u00bb Author",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_variable_categories:source" : {
          "name" : "Categories \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_variable_categories:log" : {
          "name" : "Categories \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:revision" : {
          "name" : "Categories \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "list\\u003cboolean\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:comment" : {
          "name" : "Categories \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:comment_count" : {
          "name" : "Categories \\u00bb Comment count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:comment_count_new" : {
          "name" : "Categories \\u00bb New comment count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:tid" : {
          "name" : "Body functions \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:name" : {
          "name" : "Body functions \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:description" : {
          "name" : "Body functions \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:weight" : {
          "name" : "Body functions \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:node_count" : {
          "name" : "Body functions \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:url" : {
          "name" : "Body functions \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions:vocabulary" : {
          "name" : "Body functions \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_body_functions:parent" : {
          "name" : "Body functions \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_body_structure:tid" : {
          "name" : "Body structure \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:name" : {
          "name" : "Body structure \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:description" : {
          "name" : "Body structure \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:weight" : {
          "name" : "Body structure \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:node_count" : {
          "name" : "Body structure \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:url" : {
          "name" : "Body structure \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_structure:vocabulary" : {
          "name" : "Body structure \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_body_structure:parent" : {
          "name" : "Body structure \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_disease_history:tid" : {
          "name" : "Disease history (ICD10) \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:name" : {
          "name" : "Disease history (ICD10) \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:description" : {
          "name" : "Disease history (ICD10) \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:weight" : {
          "name" : "Disease history (ICD10) \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:node_count" : {
          "name" : "Disease history (ICD10) \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:url" : {
          "name" : "Disease history (ICD10) \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:vocabulary" : {
          "name" : "Disease history (ICD10) \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_disease_history:parent" : {
          "name" : "Disease history (ICD10) \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_health_information:tid" : {
          "name" : "Health information \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:name" : {
          "name" : "Health information \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:description" : {
          "name" : "Health information \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:weight" : {
          "name" : "Health information \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:node_count" : {
          "name" : "Health information \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:url" : {
          "name" : "Health information \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_health_information:vocabulary" : {
          "name" : "Health information \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_health_information:parent" : {
          "name" : "Health information \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:tid" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:name" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:description" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:weight" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:node_count" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:url" : {
          "name" : "Life habits \\/ Behaviours \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:vocabulary" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_life_habits_behaviours:parent" : {
          "name" : "Life habits \\/ Behaviours \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_physical_env:tid" : {
          "name" : "Physical environment \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:name" : {
          "name" : "Physical environment \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:description" : {
          "name" : "Physical environment \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:weight" : {
          "name" : "Physical environment \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:node_count" : {
          "name" : "Physical environment \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:url" : {
          "name" : "Physical environment \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_physical_env:vocabulary" : {
          "name" : "Physical environment \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_physical_env:parent" : {
          "name" : "Physical environment \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_social_env:tid" : {
          "name" : "Social environment \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:name" : {
          "name" : "Social environment \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:description" : {
          "name" : "Social environment \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:weight" : {
          "name" : "Social environment \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:node_count" : {
          "name" : "Social environment \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:url" : {
          "name" : "Social environment \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_social_env:vocabulary" : {
          "name" : "Social environment \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_social_env:parent" : {
          "name" : "Social environment \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:tid" : {
          "name" : "Sociodemographic characteristics \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:name" : {
          "name" : "Sociodemographic characteristics \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:description" : {
          "name" : "Sociodemographic characteristics \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:weight" : {
          "name" : "Sociodemographic characteristics \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:node_count" : {
          "name" : "Sociodemographic characteristics \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:url" : {
          "name" : "Sociodemographic characteristics \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:vocabulary" : {
          "name" : "Sociodemographic characteristics \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_sociodemo_charact:parent" : {
          "name" : "Sociodemographic characteristics \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_socioeco:tid" : {
          "name" : "Socioeconomic characteristics \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:name" : {
          "name" : "Socioeconomic characteristics \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:description" : {
          "name" : "Socioeconomic characteristics \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:weight" : {
          "name" : "Socioeconomic characteristics \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:node_count" : {
          "name" : "Socioeconomic characteristics \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:url" : {
          "name" : "Socioeconomic characteristics \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_socioeco:vocabulary" : {
          "name" : "Socioeconomic characteristics \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_socioeco:parent" : {
          "name" : "Socioeconomic characteristics \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_variable_categories:body:value" : {
          "name" : "Categories \\u00bb The main body text \\u00bb Text",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:body:summary" : {
          "name" : "Categories \\u00bb The main body text \\u00bb Summary",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_variable_categories:body:format" : {
          "name" : "Categories \\u00bb The main body text \\u00bb Text format",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "default" : "0", "bundles" : { "ds_variable" : "ds_variable" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "taxonomy_hierarchy_processor.inc" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : {
              "field_dim_class" : "field_dim_class",
              "field_dim_collection_mode" : "field_dim_collection_mode",
              "field_dim_disease" : "field_dim_disease",
              "field_dim_format" : "field_dim_format",
              "field_dim_med_health_interv" : "field_dim_med_health_interv",
              "field_dim_period" : "field_dim_period",
              "field_dim_sample" : "field_dim_sample",
              "field_dim_source_of_info" : "field_dim_source_of_info",
              "field_dim_target" : "field_dim_target",
              "field_dim_target_gender" : "field_dim_target_gender",
              "field_dim_type" : "field_dim_type",
              "field_dim_body_functions" : "field_dim_body_functions",
              "field_dim_body_structure" : "field_dim_body_structure",
              "field_dim_disease_history" : "field_dim_disease_history",
              "field_dim_health_information" : "field_dim_health_information",
              "field_dim_life_habits_behaviours" : "field_dim_life_habits_behaviours",
              "field_dim_physical_env" : "field_dim_physical_env",
              "field_dim_social_env" : "field_dim_social_env",
              "field_dim_sociodemo_charact" : "field_dim_sociodemo_charact",
              "field_dim_socioeco" : "field_dim_socioeco",
              "search_api_language" : 0,
              "type" : 0,
              "title" : 0,
              "field_dataschema_ref" : 0,
              "field_unit" : 0,
              "field_uri" : 0,
              "field_variable_categories" : 0,
              "body:value" : 0,
              "body:summary" : 0,
              "field_dataschema_ref:title" : 0,
              "field_dim_class:name" : 0,
              "field_dim_collection_mode:name" : 0,
              "field_dim_disease:name" : 0,
              "field_dim_format:name" : 0,
              "field_dim_med_health_interv:name" : 0,
              "field_dim_period:name" : 0,
              "field_dim_sample:name" : 0,
              "field_dim_source_of_info:name" : 0,
              "field_dim_target:name" : 0,
              "field_dim_target_gender:name" : 0,
              "field_dim_type:name" : 0,
              "field_variable_categories:title" : 0,
              "field_dim_body_functions:name" : 0,
              "field_dim_body_structure:name" : 0,
              "field_dim_disease_history:name" : 0,
              "field_dim_health_information:name" : 0,
              "field_dim_life_habits_behaviours:name" : 0,
              "field_dim_physical_env:name" : 0,
              "field_dim_social_env:name" : 0,
              "field_dim_sociodemo_charact:name" : 0,
              "field_dim_socioeco:name" : 0
            }
          }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : { "fields" : {
              "title" : "title",
              "field_dataschema_ref" : "field_dataschema_ref",
              "field_dim_class" : "field_dim_class",
              "field_dim_collection_mode" : "field_dim_collection_mode",
              "field_dim_disease" : "field_dim_disease",
              "field_dim_format" : "field_dim_format",
              "field_dim_med_health_interv" : "field_dim_med_health_interv",
              "field_dim_period" : "field_dim_period",
              "field_dim_sample" : "field_dim_sample",
              "field_dim_source_of_info" : "field_dim_source_of_info",
              "field_dim_target" : "field_dim_target",
              "field_dim_target_gender" : "field_dim_target_gender",
              "field_dim_type" : "field_dim_type",
              "field_unit" : "field_unit",
              "field_variable_categories" : "field_variable_categories",
              "field_dim_body_functions" : "field_dim_body_functions",
              "field_dim_body_structure" : "field_dim_body_structure",
              "field_dim_disease_history" : "field_dim_disease_history",
              "field_dim_health_information" : "field_dim_health_information",
              "field_dim_life_habits_behaviours" : "field_dim_life_habits_behaviours",
              "field_dim_physical_env" : "field_dim_physical_env",
              "field_dim_social_env" : "field_dim_social_env",
              "field_dim_sociodemo_charact" : "field_dim_sociodemo_charact",
              "field_dim_socioeco" : "field_dim_socioeco",
              "body:value" : "body:value",
              "body:summary" : "body:summary",
              "field_dataschema_ref:title" : "field_dataschema_ref:title",
              "field_dim_class:name" : "field_dim_class:name",
              "field_dim_collection_mode:name" : "field_dim_collection_mode:name",
              "field_dim_disease:name" : "field_dim_disease:name",
              "field_dim_format:name" : "field_dim_format:name",
              "field_dim_med_health_interv:name" : "field_dim_med_health_interv:name",
              "field_dim_period:name" : "field_dim_period:name",
              "field_dim_sample:name" : "field_dim_sample:name",
              "field_dim_source_of_info:name" : "field_dim_source_of_info:name",
              "field_dim_target:name" : "field_dim_target:name",
              "field_dim_target_gender:name" : "field_dim_target_gender:name",
              "field_dim_type:name" : "field_dim_type:name",
              "field_variable_categories:title" : "field_variable_categories:title",
              "field_dim_body_functions:name" : "field_dim_body_functions:name",
              "field_dim_body_structure:name" : "field_dim_body_structure:name",
              "field_dim_disease_history:name" : "field_dim_disease_history:name",
              "field_dim_health_information:name" : "field_dim_health_information:name",
              "field_dim_life_habits_behaviours:name" : "field_dim_life_habits_behaviours:name",
              "field_dim_physical_env:name" : "field_dim_physical_env:name",
              "field_dim_social_env:name" : "field_dim_social_env:name",
              "field_dim_sociodemo_charact:name" : "field_dim_sociodemo_charact:name",
              "field_dim_socioeco:name" : "field_dim_socioeco:name",
              "search_api_language" : 0,
              "type" : 0,
              "field_uri" : 0
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "-48",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_unit" : "field_unit",
              "body:value" : "body:value",
              "search_api_language" : 0,
              "type" : 0,
              "field_dataschema_ref" : 0,
              "field_dim_class" : 0,
              "field_dim_collection_mode" : 0,
              "field_dim_disease" : 0,
              "field_dim_format" : 0,
              "field_dim_med_health_interv" : 0,
              "field_dim_period" : 0,
              "field_dim_sample" : 0,
              "field_dim_source_of_info" : 0,
              "field_dim_target" : 0,
              "field_dim_target_gender" : 0,
              "field_dim_type" : 0,
              "field_uri" : 0,
              "field_variable_categories" : 0,
              "field_dim_body_functions" : 0,
              "field_dim_body_structure" : 0,
              "field_dim_disease_history" : 0,
              "field_dim_health_information" : 0,
              "field_dim_life_habits_behaviours" : 0,
              "field_dim_physical_env" : 0,
              "field_dim_social_env" : 0,
              "field_dim_sociodemo_charact" : 0,
              "field_dim_socioeco" : 0,
              "body:summary" : 0,
              "field_dataschema_ref:title" : 0,
              "field_dim_class:name" : 0,
              "field_dim_collection_mode:name" : 0,
              "field_dim_disease:name" : 0,
              "field_dim_format:name" : 0,
              "field_dim_med_health_interv:name" : 0,
              "field_dim_period:name" : 0,
              "field_dim_sample:name" : 0,
              "field_dim_source_of_info:name" : 0,
              "field_dim_target:name" : 0,
              "field_dim_target_gender:name" : 0,
              "field_dim_type:name" : 0,
              "field_variable_categories:title" : 0,
              "field_dim_body_functions:name" : 0,
              "field_dim_body_structure:name" : 0,
              "field_dim_disease_history:name" : 0,
              "field_dim_health_information:name" : 0,
              "field_dim_life_habits_behaviours:name" : 0,
              "field_dim_physical_env:name" : 0,
              "field_dim_social_env:name" : 0,
              "field_dim_sociodemo_charact:name" : 0,
              "field_dim_socioeco:name" : 0
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_unit" : "field_unit",
              "body:value" : "body:value",
              "search_api_language" : 0,
              "type" : 0,
              "field_dataschema_ref" : 0,
              "field_dim_class" : 0,
              "field_dim_collection_mode" : 0,
              "field_dim_disease" : 0,
              "field_dim_format" : 0,
              "field_dim_med_health_interv" : 0,
              "field_dim_period" : 0,
              "field_dim_sample" : 0,
              "field_dim_source_of_info" : 0,
              "field_dim_target" : 0,
              "field_dim_target_gender" : 0,
              "field_dim_type" : 0,
              "field_uri" : 0,
              "field_variable_categories" : 0,
              "field_dim_body_functions" : 0,
              "field_dim_body_structure" : 0,
              "field_dim_disease_history" : 0,
              "field_dim_health_information" : 0,
              "field_dim_life_habits_behaviours" : 0,
              "field_dim_physical_env" : 0,
              "field_dim_social_env" : 0,
              "field_dim_sociodemo_charact" : 0,
              "field_dim_socioeco" : 0,
              "body:summary" : 0,
              "field_dataschema_ref:title" : 0,
              "field_dim_class:name" : 0,
              "field_dim_collection_mode:name" : 0,
              "field_dim_disease:name" : 0,
              "field_dim_format:name" : 0,
              "field_dim_med_health_interv:name" : 0,
              "field_dim_period:name" : 0,
              "field_dim_sample:name" : 0,
              "field_dim_source_of_info:name" : 0,
              "field_dim_target:name" : 0,
              "field_dim_target_gender:name" : 0,
              "field_dim_type:name" : 0,
              "field_variable_categories:title" : 0,
              "field_dim_body_functions:name" : 0,
              "field_dim_body_structure:name" : 0,
              "field_dim_disease_history:name" : 0,
              "field_dim_health_information:name" : 0,
              "field_dim_life_habits_behaviours:name" : 0,
              "field_dim_physical_env:name" : 0,
              "field_dim_social_env:name" : 0,
              "field_dim_sociodemo_charact:name" : 0,
              "field_dim_socioeco:name" : 0
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "-46",
          "settings" : { "file" : "", "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc" }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
