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
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
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
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'documents' => array(
      'name' => t('Documents'),
      'base' => 'node_content',
      'description' => t('Content type to present one or more documents'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'study' => array(
      'name' => t('Study'),
      'base' => 'node_content',
      'description' => t('Study portal. Create a content of this type when registering a new study.'),
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
        "field_acroym" : { "type" : "text" },
        "field_complete_name" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_contacts_ref:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_contact_country" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "country" },
        "field_contacts_ref:field_contact_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_state" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_country:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_country:official_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_city" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_contact_country" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "country" },
        "field_investigators:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_telephone" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "study" : "study" } }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : {
            "fields" : {
              "field_acroym" : true,
              "field_complete_name" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_country:name" : true,
              "field_country:official_name" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_telephone" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : {
            "fields" : {
              "field_acroym" : true,
              "field_complete_name" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_country:name" : true,
              "field_country:official_name" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_telephone" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : {
            "fields" : {
              "field_acroym" : true,
              "field_complete_name" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_country:name" : true,
              "field_country:official_name" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_telephone" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : {
              "field_acroym" : true,
              "field_complete_name" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_contact_country" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_country:name" : true,
              "field_country:official_name" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_contact_country" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_telephone" : true
            }
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
