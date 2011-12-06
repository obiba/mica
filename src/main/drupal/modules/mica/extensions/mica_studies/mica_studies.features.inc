<?php
/**
 * @file
 * mica_studies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_studies_ctools_plugin_api() {
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
function mica_studies_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function mica_studies_image_default_styles() {
  $styles = array();

  // Exported image style: study_logo
  $styles['study_logo'] = array(
    'name' => 'study_logo',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '120',
          'height' => '120',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mica_studies_node_info() {
  $items = array(
    'documents' => array(
      'name' => t('Documents'),
      'base' => 'node_content',
      'description' => t('Content type to present one or more documents'),
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
function mica_studies_default_search_api_index() {
  $items = array();
  $items['fields_description_index'] = entity_import('search_api_index', '{
    "name" : "Fields Description Index",
    "machine_name" : "fields_description_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "title" : { "type" : "text" },
        "field_bundle" : { "type" : "string" },
        "field_bundle_label" : { "type" : "text" },
        "field_categories" : { "type" : "list\\u003cstring\\u003e" },
        "field_original_field_label" : { "type" : "text" },
        "field_original_field_name" : { "type" : "string" },
        "field_repeatable" : { "type" : "boolean" },
        "field_value_type" : { "type" : "string" },
        "field_full_name" : { "type" : "text" },
        "field_target_number_biosamples" : { "type" : "integer" },
        "field_target_number_participants" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "field_description" : "field_description" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_bundle_label" : true,
              "field_original_field_label" : true,
              "field_full_name" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "taxonomy_hierarchy_processor.inc" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_bundle_label" : true,
              "field_original_field_label" : true,
              "field_full_name" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_bundle_label" : true,
              "field_original_field_label" : true,
              "field_full_name" : true,
              "body:value" : true,
              "body:summary" : true
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
              "field_bundle_label" : true,
              "field_original_field_label" : true,
              "field_full_name" : true,
              "body:value" : true,
              "body:summary" : true
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
              "field_bundle_label" : true,
              "field_original_field_label" : true,
              "field_full_name" : true,
              "body:value" : true,
              "body:summary" : true
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
  $items['studies_index'] = entity_import('search_api_index', '{
    "name" : "Studies Index",
    "machine_name" : "studies_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "field_full_name" : { "type" : "text" },
        "field_target_number_biosamples" : { "type" : "integer" },
        "field_target_number_participants" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "mica_study_information:field_access" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_access_other" : { "type" : "text" },
        "mica_study_information:field_age_max" : { "type" : "integer" },
        "mica_study_information:field_age_min" : { "type" : "integer" },
        "mica_study_information:field_biosamples_collected" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_biosamples_collected_other" : { "type" : "text" },
        "mica_study_information:field_biosamples_tissues" : { "type" : "text" },
        "mica_study_information:field_design" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_design_other" : { "type" : "text" },
        "mica_study_information:field_design_target" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_gender" : { "type" : "string" },
        "mica_study_information:field_gwas_analysis" : { "type" : "string" },
        "mica_study_information:field_gwas_number" : { "type" : "integer" },
        "mica_study_information:field_selection_criteria" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_status_end" : { "type" : "integer" },
        "mica_study_information:field_status_start" : { "type" : "integer" },
        "mica_study_information:field_study_country" : { "type" : "list\\u003cstring\\u003e" },
        "mica_study_information:field_target_other" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "study" : "study",
              "study_documents" : "study_documents",
              "study_information" : "study_information"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_full_name" : true,
              "body:value" : true,
              "mica_study_information:field_access_other" : true,
              "mica_study_information:field_biosamples_collected_other" : true,
              "mica_study_information:field_biosamples_tissues" : true,
              "mica_study_information:field_design_other" : true,
              "mica_study_information:field_target_other" : true
            }
          }
        },
        "taxonomy_hierarchy_processor.inc" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_full_name" : true,
              "body:value" : true,
              "mica_study_information:field_access_other" : true,
              "mica_study_information:field_biosamples_collected_other" : true,
              "mica_study_information:field_biosamples_tissues" : true,
              "mica_study_information:field_design_other" : true,
              "mica_study_information:field_target_other" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_full_name" : true,
              "body:value" : true,
              "mica_study_information:field_access_other" : true,
              "mica_study_information:field_biosamples_collected_other" : true,
              "mica_study_information:field_biosamples_tissues" : true,
              "mica_study_information:field_design_other" : true,
              "mica_study_information:field_target_other" : true
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
              "field_full_name" : true,
              "body:value" : true,
              "mica_study_information:field_access_other" : true,
              "mica_study_information:field_biosamples_collected_other" : true,
              "mica_study_information:field_biosamples_tissues" : true,
              "mica_study_information:field_design_other" : true,
              "mica_study_information:field_target_other" : true
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
              "field_full_name" : true,
              "body:value" : true,
              "mica_study_information:field_access_other" : true,
              "mica_study_information:field_biosamples_collected_other" : true,
              "mica_study_information:field_biosamples_tissues" : true,
              "mica_study_information:field_design_other" : true,
              "mica_study_information:field_target_other" : true
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

/**
 * Implements hook_default_search_api_server().
 */
function mica_studies_default_search_api_server() {
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
