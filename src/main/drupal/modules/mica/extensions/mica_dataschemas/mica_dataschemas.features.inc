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
      "field_name" : "Socioeconomic characteristics",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_di_11'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_di_11",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_medication",
    "name" : "Medication facet",
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
      "field_name" : "Medication",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_di_12'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_di_12",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_therapeutic_inter",
    "name" : "Therapeutic interventions facet",
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
      "field_name" : "Therapeutic interventions",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_di_13'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_di_13",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_biochemical_measures",
    "name" : "Biochemical measures facet",
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
      "field_name" : "Biochemical measures"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_di_14'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_di_14",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_body_functions_meas",
    "name" : "Body functions and measures facet",
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
      "field_name" : "Body functions and measures"
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
      "field_name" : "Body structure",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_6'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_6",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_disease_history",
    "name" : "Disease history facet",
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
      "field_name" : "Disease history (ICD10)",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_7'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_7",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_physical_env",
    "name" : "Physical environment facet",
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
      "field_name" : "Physical environment",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_8'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_8",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_social_env",
    "name" : "Social environment facet",
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
      "field_name" : "Social environment",
      "entity_type" : "taxonomy_term"
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
      "field_name" : "Sociodemographic characteristics",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_b'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_b",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_body_functions",
    "name" : "Body functions facet",
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
      "field_name" : "Body functions",
      "entity_type" : "taxonomy_term"
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
      "field_name" : "Disease",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_e'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_e",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_environmental_exp",
    "name" : "Environmental exposures facet",
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
      "field_name" : "Environmental exposures"
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
      "field_name" : "Health information",
      "entity_type" : "taxonomy_term"
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
      "field_name" : "Life habits \\/ Behaviours",
      "entity_type" : "taxonomy_term"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_m'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_m",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_med_health_interv",
    "name" : "Medical health intervention facet",
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
  $items['dataschema_variables_field_dim_r'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_r",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_reproductive_history",
    "name" : "Reproductive history facet",
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
      "field_name" : "Reproductive history",
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
        "field_dim_disease_history" : {
          "name" : "Disease history",
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
        "field_dim_medication" : {
          "name" : "Medication",
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
        "field_dim_reproductive_history" : {
          "name" : "Reproductive history",
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
        "field_dim_sociodemo_charact" : {
          "name" : "Sociodemographic characteristics",
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
        "field_dim_therapeutic_inter" : {
          "name" : "Therapeutic interventions",
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
        "field_dim_biochemical_measures" : {
          "name" : "Biochemical measures",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas" : {
          "name" : "Body functions and measures",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp" : {
          "name" : "Environmental exposures",
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
        "field_dim_disease_history:tid" : {
          "name" : "Disease history \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:name" : {
          "name" : "Disease history \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:description" : {
          "name" : "Disease history \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:weight" : {
          "name" : "Disease history \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:node_count" : {
          "name" : "Disease history \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:url" : {
          "name" : "Disease history \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_disease_history:vocabulary" : {
          "name" : "Disease history \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_disease_history:parent" : {
          "name" : "Disease history \\u00bb Parent terms",
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
        "field_dim_medication:tid" : {
          "name" : "Medication \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:name" : {
          "name" : "Medication \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:description" : {
          "name" : "Medication \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:weight" : {
          "name" : "Medication \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:node_count" : {
          "name" : "Medication \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:url" : {
          "name" : "Medication \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_medication:vocabulary" : {
          "name" : "Medication \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_medication:parent" : {
          "name" : "Medication \\u00bb Parent terms",
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
        "field_dim_reproductive_history:tid" : {
          "name" : "Reproductive history \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:name" : {
          "name" : "Reproductive history \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:description" : {
          "name" : "Reproductive history \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:weight" : {
          "name" : "Reproductive history \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:node_count" : {
          "name" : "Reproductive history \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:url" : {
          "name" : "Reproductive history \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:vocabulary" : {
          "name" : "Reproductive history \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_reproductive_history:parent" : {
          "name" : "Reproductive history \\u00bb Parent terms",
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
        "field_dim_therapeutic_inter:tid" : {
          "name" : "Therapeutic interventions \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:name" : {
          "name" : "Therapeutic interventions \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:description" : {
          "name" : "Therapeutic interventions \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:weight" : {
          "name" : "Therapeutic interventions \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:node_count" : {
          "name" : "Therapeutic interventions \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:url" : {
          "name" : "Therapeutic interventions \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:vocabulary" : {
          "name" : "Therapeutic interventions \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_therapeutic_inter:parent" : {
          "name" : "Therapeutic interventions \\u00bb Parent terms",
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
        "field_dim_biochemical_measures:tid" : {
          "name" : "Biochemical measures \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:name" : {
          "name" : "Biochemical measures \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:description" : {
          "name" : "Biochemical measures \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:weight" : {
          "name" : "Biochemical measures \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:node_count" : {
          "name" : "Biochemical measures \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:url" : {
          "name" : "Biochemical measures \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:vocabulary" : {
          "name" : "Biochemical measures \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_biochemical_measures:parent" : {
          "name" : "Biochemical measures \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:tid" : {
          "name" : "Body functions and measures \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:name" : {
          "name" : "Body functions and measures \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:description" : {
          "name" : "Body functions and measures \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:weight" : {
          "name" : "Body functions and measures \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:node_count" : {
          "name" : "Body functions and measures \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:url" : {
          "name" : "Body functions and measures \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:vocabulary" : {
          "name" : "Body functions and measures \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_body_functions_meas:parent" : {
          "name" : "Body functions and measures \\u00bb Parent terms",
          "indexed" : 0,
          "type" : "list\\u003clist\\u003cinteger\\u003e\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:tid" : {
          "name" : "Environmental exposures \\u00bb Term ID",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:name" : {
          "name" : "Environmental exposures \\u00bb Name",
          "indexed" : 1,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:description" : {
          "name" : "Environmental exposures \\u00bb Description",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:weight" : {
          "name" : "Environmental exposures \\u00bb Weight",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:node_count" : {
          "name" : "Environmental exposures \\u00bb Node count",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:url" : {
          "name" : "Environmental exposures \\u00bb URL",
          "indexed" : 0,
          "type" : "list\\u003curi\\u003e",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:vocabulary" : {
          "name" : "Environmental exposures \\u00bb Vocabulary",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_vocabulary",
          "boost" : "1.0"
        },
        "field_dim_environmental_exp:parent" : {
          "name" : "Environmental exposures \\u00bb Parent terms",
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
