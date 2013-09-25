<?php
/**
 * @file
 * mica_datasets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_datasets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "corresponding_node_references" && $api == "default_corresponding_node_references_presets") {
    return array("version" => "1");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mica_datasets_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
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
    'study_variable_attributes' => array(
      'name' => t('Study Variable Attributes'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
  $items['dataset_index'] = entity_import('search_api_index', '{
    "name" : "Dataset Index",
    "machine_name" : "dataset_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_dataset_dces" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_dataset_studies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_dataset_type" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_aggregation_2" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_dataset_dces:field_dce_population" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "dataset" : "dataset" } }
        },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_combined" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "Title full text",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              },
              "search_api_aggregation_2" : {
                "name" : "Study count",
                "type" : "count",
                "fields" : [ "field_dataset_studies" ],
                "description" : "A Count aggregation of the following fields: Studies."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_dataset_type" : true,
              "search_api_aggregation_1" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
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
  $items['variable_index'] = entity_import('search_api_index', '{
    "name" : "Variables Index",
    "machine_name" : "variable_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_repeatable" : { "type" : "boolean" },
        "field_value_type" : { "type" : "string" },
        "field_administrative_information" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_anthropometric_structures" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_body_functions" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_body_structures" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_data_source" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dataset" : { "type" : "integer", "entity_type" : "node" },
        "field_disease_history" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_early_life" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_label" : { "type" : "text" },
        "field_laboratory_measures" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_life_habits_behaviours" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_medical_health_interv" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_medication" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_perception_of_health" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_physical_environment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_position" : { "type" : "integer" },
        "field_reproductive_history" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_social_environment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sociodemographic_charact" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_unit" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_aggregation_2" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_combined_1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_dataset:nid" : { "type" : "integer" },
        "field_dataset:title" : { "type" : "text" },
        "field_dataset:field_dataset_dces" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_dataset:field_dataset_studies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_dataset:field_dataset_type" : { "type" : "string" },
        "field_variable_categories:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_variable_categories:label" : { "type" : "list\\u003Ctext\\u003E" },
        "field_variable_categories:missing" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_variable_study_var_att:field_sva_status" : { "type" : "list\\u003Cstring\\u003E" },
        "field_dataset:field_dataset_dces:field_dce_data_sources" : { "type" : "list\\u003Clist\\u003Cstring\\u003E\\u003E" },
        "field_dataset:field_dataset_dces:field_dce_population" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_dataset:field_dataset_dces:field_dce_population:field_pop_select_criteria" : { "type" : "list\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E" },
        "field_dataset:field_dataset_dces:field_dce_population:field_pop_src_recruit" : { "type" : "list\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "variable" : "variable" } }
        },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_combined" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_combined_1" : {
                "name" : "Study",
                "imitate" : "field_dataset:field_dataset_studies",
                "fields" : [
                  "field_dataset:field_dataset_studies",
                  "field_variable_study_var_att:field_sva_study"
                ],
                "description" : "A @type combined of the following fields: Dataset \\u00bb Studies, Study Variables Attributes \\u00bb Study."
              }
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_anthropometric_structures:parent" : "field_anthropometric_structures:parent",
              "field_anthropometric_structures:parents_all" : "field_anthropometric_structures:parents_all",
              "field_body_functions:parent" : "field_body_functions:parent",
              "field_body_functions:parents_all" : "field_body_functions:parents_all",
              "field_body_structures:parent" : "field_body_structures:parent",
              "field_body_structures:parents_all" : "field_body_structures:parents_all",
              "field_data_source:parent" : "field_data_source:parent",
              "field_data_source:parents_all" : "field_data_source:parents_all",
              "field_disease_history:parent" : "field_disease_history:parent",
              "field_disease_history:parents_all" : "field_disease_history:parents_all",
              "field_early_life:parent" : "field_early_life:parent",
              "field_early_life:parents_all" : "field_early_life:parents_all",
              "field_life_habits_behaviours:parent" : "field_life_habits_behaviours:parent",
              "field_life_habits_behaviours:parents_all" : "field_life_habits_behaviours:parents_all",
              "field_medical_health_interv:parent" : "field_medical_health_interv:parent",
              "field_medical_health_interv:parents_all" : "field_medical_health_interv:parents_all",
              "field_medication:parent" : "field_medication:parent",
              "field_medication:parents_all" : "field_medication:parents_all",
              "field_perception_of_health:parent" : "field_perception_of_health:parent",
              "field_perception_of_health:parents_all" : "field_perception_of_health:parents_all",
              "field_physical_environment:parent" : "field_physical_environment:parent",
              "field_physical_environment:parents_all" : "field_physical_environment:parents_all",
              "field_reproductive_history:parent" : "field_reproductive_history:parent",
              "field_reproductive_history:parents_all" : "field_reproductive_history:parents_all",
              "field_social_environment:parent" : "field_social_environment:parent",
              "field_social_environment:parents_all" : "field_social_environment:parents_all",
              "field_sociodemographic_charact:parent" : "field_sociodemographic_charact:parent",
              "field_sociodemographic_charact:parents_all" : "field_sociodemographic_charact:parents_all",
              "field_target:parent" : "field_target:parent",
              "field_target:parents_all" : "field_target:parents_all"
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "Title and Label",
                "type" : "fulltext",
                "fields" : [ "title", "field_original_field_label", "field_label" ],
                "description" : "A Fulltext aggregation of the following fields: Title, Label, Label."
              },
              "search_api_aggregation_2" : {
                "name" : "Title Label and Body",
                "type" : "fulltext",
                "fields" : [ "title", "field_original_field_label" ],
                "description" : "A Fulltext aggregation of the following fields: Title, Label."
              }
            }
          }
        },
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
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
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
