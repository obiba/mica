<?php
/**
 * @file
 * mica_studies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_studies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "corresponding_node_references" && $api == "default_corresponding_node_references_presets") {
    return array("version" => "1");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
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
function mica_studies_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function mica_studies_image_default_styles() {
  $styles = array();

  // Exported image style: study_logo.
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
          'width' => 120,
          'height' => 120,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'study_logo',
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
      'description' => t('How to contact a person in an institution.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'data_collection_event' => array(
      'name' => t('Data Collection Event'),
      'base' => 'node_content',
      'description' => t('A data collection event is a specific period of time during which a defined set of data/sample is collected.'),
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
    'population' => array(
      'name' => t('Population'),
      'base' => 'node_content',
      'description' => t('A population is a set of individuals sharing the same selection criteria. In some cases, a study can have two or more populations (i.e. 2 sets of individuals with distinct selection criteria).'),
      'has_title' => '1',
      'title_label' => t('Population'),
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
        "type" : { "type" : "string" },
        "title" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "title_field" : { "type" : "text" },
        "field_access_biosamples" : { "type" : "boolean" },
        "field_access_data" : { "type" : "boolean" },
        "field_access_other" : { "type" : "boolean" },
        "field_acroym" : { "type" : "text" },
        "field_design" : { "type" : "list\\u003Cstring\\u003E" },
        "field_no_limits_participants" : { "type" : "boolean" },
        "field_no_limits_samples" : { "type" : "boolean" },
        "field_recruitment" : { "type" : "list\\u003Cstring\\u003E" },
        "field_recruitment_other_sp" : { "type" : "text" },
        "field_study_end_year" : { "type" : "integer" },
        "field_study_start_year" : { "type" : "integer" },
        "field_target_number_biosamples" : { "type" : "integer" },
        "field_target_number_participants" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "field_study_populations_field_pop_age_max_asc" : { "type" : "integer" },
        "field_study_populations_field_pop_age_max_desc" : { "type" : "integer" },
        "field_study_populations_field_pop_age_min_asc" : { "type" : "integer" },
        "field_study_populations_field_pop_age_min_desc" : { "type" : "integer" },
        "field_study_populations_field_pop_dce_field_dce_end_year_asc" : { "type" : "integer" },
        "field_study_populations_field_pop_dce_field_dce_end_year_desc" : { "type" : "integer" },
        "field_study_populations_field_pop_dce_field_dce_start_year_asc" : { "type" : "integer" },
        "field_study_populations_field_pop_dce_field_dce_start_year_desc" : { "type" : "integer" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_access_other_sp:value" : { "type" : "text" },
        "field_contacts_ref:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_city" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_contact_country" : { "type" : "list\\u003Cstring\\u003E" },
        "field_contacts_ref:field_contact_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_daco" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_contacts_ref:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_postal_code" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_state" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_design_other_sp:value" : { "type" : "text" },
        "field_info_design_follow_up:value" : { "type" : "text" },
        "field_investigators:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_city" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_contact_country" : { "type" : "list\\u003Cstring\\u003E" },
        "field_investigators:field_contact_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_daco" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_investigators:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_postal_code" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_state" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_recruitment_supp_info:value" : { "type" : "text" },
        "field_study_populations:field_pop_age_max" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_study_populations:field_pop_age_min" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_study_populations:field_pop_country" : { "type" : "list\\u003Clist\\u003Cstring\\u003E\\u003E" },
        "field_study_populations:field_pop_exist_study_part" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_study_populations:field_pop_gender" : { "type" : "list\\u003Cstring\\u003E" },
        "field_study_populations:field_pop_select_criteria" : { "type" : "list\\u003Clist\\u003Cstring\\u003E\\u003E" },
        "field_study_populations:field_pop_src_recruit" : { "type" : "list\\u003Clist\\u003Cstring\\u003E\\u003E" },
        "field_supp_infos:value" : { "type" : "text" },
        "field_target_nb_supp_info:value" : { "type" : "text" },
        "field_study_populations:body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:body:summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_dce:field_dce_bio_samples_management" : { "type" : "list\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E" },
        "field_study_populations:field_pop_dce:field_dce_data_sources" : { "type" : "list\\u003Clist\\u003Clist\\u003Cstring\\u003E\\u003E\\u003E" },
        "field_study_populations:field_pop_dce:field_dce_end_year" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_study_populations:field_pop_dce:field_dce_start_year" : { "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E" },
        "field_study_populations:field_pop_partcipant_sel_supp_in:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_participants_nb_supp_i:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_recruit_supp_info:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_recruitment_other:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_selection_others_sp:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_specific_pop_other_sp:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_supp_infos:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_territory:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_study_populations:field_pop_dce:body:value" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_study_populations:field_pop_dce:body:summary" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_study_populations:field_pop_dce:field_dce_samples_man_other_sp:value" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : {
              "field_study_populations:field_pop_age_max" : "field_study_populations:field_pop_age_max",
              "field_study_populations:field_pop_age_min" : "field_study_populations:field_pop_age_min",
              "field_study_populations:field_pop_dce:field_dce_end_year" : "field_study_populations:field_pop_dce:field_dce_end_year",
              "field_study_populations:field_pop_dce:field_dce_start_year" : "field_study_populations:field_pop_dce:field_dce_start_year"
            }
          }
        },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "contact" : "contact",
              "data_collection_event" : "data_collection_event",
              "population" : "population",
              "study" : "study"
            }
          }
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
                "name" : "Title_Full_text",
                "type" : "fulltext",
                "fields" : [ "title_field" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
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
              "field_acroym" : true,
              "field_recruitment_other_sp" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_access_other_sp:value" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_city" : true,
              "field_contacts_ref:field_contact_country" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_postal_code" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_design_other_sp:value" : true,
              "field_info_design_follow_up:value" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_contact_country" : true,
              "field_investigators:field_contact_email" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_postal_code" : true,
              "field_investigators:field_state" : true,
              "field_investigators:field_telephone" : true,
              "field_recruitment_supp_info:value" : true,
              "field_study_populations:field_pop_exist_study_part" : true,
              "field_supp_infos:value" : true,
              "field_target_nb_supp_info:value" : true,
              "field_study_populations:body:value" : true,
              "field_study_populations:body:summary" : true,
              "field_study_populations:field_pop_partcipant_sel_supp_in:value" : true,
              "field_study_populations:field_pop_participants_nb_supp_i:value" : true,
              "field_study_populations:field_pop_recruit_supp_info:value" : true,
              "field_study_populations:field_pop_recruitment_other:value" : true,
              "field_study_populations:field_pop_selection_others_sp:value" : true,
              "field_study_populations:field_pop_specific_pop_other_sp:value" : true,
              "field_study_populations:field_pop_supp_infos:value" : true,
              "field_study_populations:field_pop_territory:value" : true,
              "field_study_populations:field_pop_dce:body:value" : true,
              "field_study_populations:field_pop_dce:body:summary" : true,
              "field_study_populations:field_pop_dce:field_dce_samples_man_other_sp:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_recruitment_other_sp" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_access_other_sp:value" : true,
              "field_design_other_sp:value" : true,
              "field_info_design_follow_up:value" : true,
              "field_recruitment_supp_info:value" : true,
              "field_supp_infos:value" : true,
              "field_target_nb_supp_info:value" : true,
              "field_study_populations:body:value" : true,
              "field_study_populations:body:summary" : true,
              "field_study_populations:field_pop_partcipant_sel_supp_in:value" : true,
              "field_study_populations:field_pop_participants_nb_supp_i:value" : true,
              "field_study_populations:field_pop_recruit_supp_info:value" : true,
              "field_study_populations:field_pop_recruitment_other:value" : true,
              "field_study_populations:field_pop_selection_others_sp:value" : true,
              "field_study_populations:field_pop_specific_pop_other_sp:value" : true,
              "field_study_populations:field_pop_supp_infos:value" : true,
              "field_study_populations:field_pop_territory:value" : true,
              "field_study_populations:field_pop_dce:body:value" : true,
              "field_study_populations:field_pop_dce:body:summary" : true,
              "field_study_populations:field_pop_dce:field_dce_samples_man_other_sp:value" : true
            },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : [],
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
