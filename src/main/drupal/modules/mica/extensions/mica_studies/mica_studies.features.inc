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
      'description' => t('How to contact a person in an institution.'),
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
      "cron_limit" : "200",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "status" : { "type" : "integer" },
        "field_access_biosamples" : {
          "name" : "Biological samples",
          "indexed" : true,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_access_data" : {
          "name" : "Data (questionnaire-derived, measured\\u2026)",
          "indexed" : true,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_access_other" : {
          "name" : "Other",
          "indexed" : true,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_access_other_sp" : {
          "name" : "Please specify what study feature",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_acroym" : { "name" : "Acronym", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "field_age_max" : {
          "name" : "Maximum age",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_age_min" : {
          "name" : "Minimum age",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_authorising_date" : { "type" : "date" },
        "field_authorising_date_m" : { "type" : "date" },
        "field_authorising_person_name" : { "type" : "text" },
        "field_authorising_person_name_m" : { "type" : "text" },
        "field_authorization_maelstrom" : { "type" : "boolean" },
        "field_authorization_specific" : { "type" : "boolean" },
        "field_baseline_end_year" : {
          "name" : "End year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_baseline_start_year" : {
          "name" : "Start year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_bio_samples_management" : {
          "name" : "Biological samples",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_complete_name" : {
          "name" : "Complete name",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_contacts_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_country" : {
          "name" : "Country of residence",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_current_part_nb_date" : {
          "name" : "In date of",
          "indexed" : true,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_current_participants_nb" : {
          "name" : "How many people have joined the study?",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_current_sam_supp_info" : {
          "name" : "If needed, supplementary information about current number of collected biological samples",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_current_samples_date" : {
          "name" : "In date of",
          "indexed" : true,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_current_samples_nb" : {
          "name" : "For how many people have biological samples been collected?",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_current_supp_info" : {
          "name" : "If needed, supplementary information about current number of participants recruited at baseline",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_data_sources" : {
          "name" : "Data Sources",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_data_sources_sp" : {
          "name" : "Please specify what other data sources",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_design" : {
          "name" : "What is the design of the study",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_design_other_sp" : {
          "name" : "Please specify what other design",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_ended_end_year" : {
          "name" : "End year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_ethnic_origin" : {
          "name" : "Selection Criteria: Ethnic Origin",
          "indexed" : true,
          "type" : "list\\u003Ctext\\u003E",
          "boost" : "1.0"
        },
        "field_followup_end_year" : {
          "name" : "End year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_followup_start_year" : {
          "name" : "Start year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_gender" : {
          "name" : "Selection Criteria: Gender",
          "indexed" : true,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_health_status" : {
          "name" : "Selection Criteria: Health Status",
          "indexed" : true,
          "type" : "list\\u003Ctext\\u003E",
          "boost" : "1.0"
        },
        "field_investigators" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_marker_paper" : {
          "name" : "Marker paper describing your study",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_no_limits_participants" : {
          "name" : "No limits in the number of participants",
          "indexed" : true,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_no_limits_samples" : {
          "name" : "No limits in the number of samples",
          "indexed" : true,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_partcipant_sel_supp_info" : {
          "name" : "If needed, supplementary information about selection criteria of the population",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_preparation_end_year" : {
          "name" : "End year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_preparation_start_year" : {
          "name" : "Start year",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_pubmedid" : {
          "name" : "Pubmed Id",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recruitement_supp_info" : {
          "name" : "If needed, supplementary information about recruitments procedures",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recruitment" : {
          "name" : "The study targets the recruitment of",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_recruitment_other" : {
          "name" : "Please specify what other source of recruitment",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recruitment_other_sp" : {
          "name" : "Please specify what other recruitment target",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_recruitment_procedures" : {
          "name" : "Specify the sources of recruitment",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_recruitment_supp_info" : {
          "name" : "If needed, supplementary information about study design",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_samples_man_other_sp" : {
          "name" : "Please specify what other biological samples",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_samples_supp_info" : {
          "name" : "If needed, supplementary information about target number of biological samples",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_select_criteria" : {
          "name" : "What are the inclusion criteria for participants\\u2019 selection",
          "indexed" : true,
          "type" : "list\\u003Cstring\\u003E",
          "boost" : "1.0"
        },
        "field_selection_others_sp" : {
          "name" : "Please specify what other selection criteria",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_status_supp_info" : {
          "name" : "If needed, supplementary information about current study status",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_supp_infos" : { "type" : "text" },
        "field_target_nb_supp_info" : {
          "name" : "If needed, supplementary information about target number of participants",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_target_number_biosamples" : {
          "name" : "How many people have provided or should provide biological samples, from which DNA could be extracted?",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_target_number_participants" : {
          "name" : "How many people are planned to be recruited? Or if the study is completed, what is the final number of participants?",
          "indexed" : true,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_territory" : {
          "name" : "Territory or city of residence",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_tissues_sp" : {
          "name" : "Please specify type of tissues",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_contacts_ref:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_city" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_contact_country" : { "type" : "list\\u003Cstring\\u003E" },
        "field_contacts_ref:field_contact_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_postal_code" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_state" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_contacts_ref:field_daco" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_investigators:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_address" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_city" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_contact_country" : { "type" : "list\\u003Cstring\\u003E" },
        "field_investigators:field_contact_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_institution_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_postal_code" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_state" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_investigators:field_daco" : { "type" : "list\\u003Cboolean\\u003E" }
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
          "settings" : { "lang_field" : "", "languages" : { "und" : "und", "en" : "en" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_acroym" : true,
              "field_authorising_person_name" : true,
              "field_authorising_person_name_m" : true,
              "field_complete_name" : true,
              "field_data_sources_sp" : true,
              "field_design_other_sp" : true,
              "field_health_status" : true,
              "field_partcipant_sel_supp_info" : true,
              "field_recruitement_supp_info" : true,
              "field_recruitment_other" : true,
              "field_recruitment_other_sp" : true,
              "field_recruitment_procedures" : true,
              "field_recruitment_supp_info" : true,
              "field_samples_man_other_sp" : true,
              "field_samples_supp_info" : true,
              "field_selection_others_sp" : true,
              "field_status_supp_info" : true,
              "field_supp_infos" : true,
              "field_target_nb_supp_info" : true,
              "field_territory" : true,
              "field_tissues_sp" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_contacts_ref:title" : true,
              "field_contacts_ref:field_address" : true,
              "field_contacts_ref:field_city" : true,
              "field_contacts_ref:field_contact_email" : true,
              "field_contacts_ref:field_institution_name" : true,
              "field_contacts_ref:field_postal_code" : true,
              "field_contacts_ref:field_state" : true,
              "field_contacts_ref:field_telephone" : true,
              "field_investigators:title" : true,
              "field_investigators:field_address" : true,
              "field_investigators:field_city" : true,
              "field_investigators:field_contact_country" : true,
              "field_investigators:field_contact_email" : true,
              "field_investigators:field_institution_name" : true,
              "field_investigators:field_postal_code" : true,
              "field_investigators:field_state" : true,
              "field_investigators:field_telephone" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
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
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
