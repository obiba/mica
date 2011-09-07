<?php
/**
 * @file
 * mica_datasets.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_datasets_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mica_datasets_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_default_search_api_index().
 */
function mica_datasets_default_search_api_index() {
  $items = array();
  $items['participant_variable_index'] = entity_import('search_api_index', '{
    "name" : "Participant Variable Index",
    "machine_name" : "participant_variable_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "index_directly" : 1,
      "fields" : {
        "search_api_language" : {
          "name" : "Item language",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "search_api_aggregation_1" : {
          "name" : "Title and Label",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "nid" : { "name" : "Node ID", "indexed" : 1, "type" : "integer", "boost" : "1.0" },
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
        "title" : { "name" : "Title", "indexed" : 1, "type" : "string", "boost" : "1.0" },
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
        "field_categories" : {
          "name" : "Categories",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_dataset" : {
          "name" : "Dataset",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_label" : { "name" : "Label", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "field_repeatable" : {
          "name" : "Repeatable",
          "indexed" : 1,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_value_type" : {
          "name" : "Value Type",
          "indexed" : 1,
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
        "field_original_field_label" : { "name" : "Label", "indexed" : 0, "type" : "string", "boost" : "1.0" },
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
          "type" : "integer",
          "entity_type" : "user",
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
        "field_project" : {
          "name" : "Project",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
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
        "field_dataset:nid" : {
          "name" : "Dataset \\u00bb Node ID",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataset:vid" : {
          "name" : "Dataset \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataset:is_new" : {
          "name" : "Dataset \\u00bb Is new",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataset:type" : {
          "name" : "Dataset \\u00bb Content type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dataset:title" : {
          "name" : "Dataset \\u00bb Title",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataset:language" : {
          "name" : "Dataset \\u00bb Language",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataset:url" : {
          "name" : "Dataset \\u00bb URL",
          "indexed" : 1,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_dataset:edit_url" : {
          "name" : "Dataset \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "field_dataset:status" : {
          "name" : "Dataset \\u00bb Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataset:promote" : {
          "name" : "Dataset \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataset:sticky" : {
          "name" : "Dataset \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataset:created" : {
          "name" : "Dataset \\u00bb Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_dataset:changed" : {
          "name" : "Dataset \\u00bb Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "field_dataset:author" : {
          "name" : "Dataset \\u00bb Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "field_dataset:source" : {
          "name" : "Dataset \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_dataset:log" : {
          "name" : "Dataset \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dataset:revision" : {
          "name" : "Dataset \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "field_dataset:comment" : {
          "name" : "Dataset \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataset:comment_count" : {
          "name" : "Dataset \\u00bb Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_dataset:comment_count_new" : {
          "name" : "Dataset \\u00bb New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "default" : "0",
            "bundles" : { "participant_variable" : "participant_variable" }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "fields" : { "search_api_aggregation_1" : {
                "name" : "Title and Label",
                "type" : "fulltext",
                "fields" : {
                  "title" : "title",
                  "field_label" : "field_label",
                  "search_api_language" : 0,
                  "search_api_aggregation_1" : 0,
                  "nid" : 0,
                  "vid" : 0,
                  "is_new" : 0,
                  "type" : 0,
                  "language" : 0,
                  "url" : 0,
                  "edit_url" : 0,
                  "status" : 0,
                  "promote" : 0,
                  "sticky" : 0,
                  "created" : 0,
                  "changed" : 0,
                  "author" : 0,
                  "source" : 0,
                  "log" : 0,
                  "revision" : 0,
                  "comment" : 0,
                  "comment_count" : 0,
                  "comment_count_new" : 0,
                  "taxonomy_forums" : 0,
                  "field_tags" : 0,
                  "field_categories" : 0,
                  "field_dataset" : 0,
                  "field_repeatable" : 0,
                  "field_value_type" : 0,
                  "field_studies" : 0,
                  "field_bundle" : 0,
                  "field_bundle_label" : 0,
                  "field_original_field_label" : 0,
                  "field_original_field_name" : 0,
                  "mica_dataset" : 0,
                  "field_contact" : 0,
                  "field_full_name" : 0,
                  "field_investigator" : 0,
                  "field_study_legacy_id" : 0,
                  "field_target_number_biosamples" : 0,
                  "field_target_number_participants" : 0,
                  "mica_study_documents" : 0,
                  "mica_study_information" : 0,
                  "field_authors" : 0,
                  "field_publication_pmid" : 0,
                  "field_publication_reference" : 0,
                  "field_daco" : 0,
                  "field_contact_email" : 0,
                  "field_institution" : 0,
                  "field_telephone" : 0,
                  "field_city" : 0,
                  "field_country_text" : 0,
                  "field_data_access_review" : 0,
                  "field_dataset_access" : 0,
                  "field_institution_name" : 0,
                  "field_postal_code" : 0,
                  "field_rep_email" : 0,
                  "field_street" : 0,
                  "field_data_access" : 0,
                  "field_review_notes" : 0,
                  "field_review_status" : 0,
                  "field_project" : 0,
                  "field_teleconference_description" : 0,
                  "field_access" : 0,
                  "field_access_other" : 0,
                  "field_age_max" : 0,
                  "field_age_min" : 0,
                  "field_biosamples_collected" : 0,
                  "field_biosamples_collected_other" : 0,
                  "field_biosamples_tissues" : 0,
                  "field_design" : 0,
                  "field_design_other" : 0,
                  "field_design_target" : 0,
                  "field_gender" : 0,
                  "field_gwas_analysis" : 0,
                  "field_gwas_number" : 0,
                  "field_selection_criteria" : 0,
                  "field_status_end" : 0,
                  "field_status_start" : 0,
                  "field_study_country" : 0,
                  "field_target_other" : 0,
                  "field_dataset:nid" : 0,
                  "field_dataset:vid" : 0,
                  "field_dataset:is_new" : 0,
                  "field_dataset:type" : 0,
                  "field_dataset:title" : 0,
                  "field_dataset:language" : 0,
                  "field_dataset:url" : 0,
                  "field_dataset:edit_url" : 0,
                  "field_dataset:status" : 0,
                  "field_dataset:promote" : 0,
                  "field_dataset:sticky" : 0,
                  "field_dataset:created" : 0,
                  "field_dataset:changed" : 0,
                  "field_dataset:author" : 0,
                  "field_dataset:source" : 0,
                  "field_dataset:log" : 0,
                  "field_dataset:revision" : 0,
                  "field_dataset:comment" : 0,
                  "field_dataset:comment_count" : 0,
                  "field_dataset:comment_count_new" : 0
                },
                "actions" : { "remove" : "Remove field" }
              }
            },
            "actions" : { "add_field" : "Add new field" }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : "title",
              "field_dataset" : "field_dataset",
              "field_label" : "field_label",
              "search_api_language" : 0,
              "search_api_aggregation_1" : 0,
              "nid" : 0,
              "vid" : 0,
              "type" : 0,
              "field_repeatable" : 0,
              "field_value_type" : 0,
              "field_dataset:nid" : 0,
              "field_dataset:title" : 0,
              "field_dataset:url" : 0
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "search_api_language" : 0,
              "search_api_aggregation_1" : 0,
              "nid" : 0,
              "vid" : 0,
              "type" : 0,
              "title" : 0,
              "field_dataset" : 0,
              "field_label" : 0,
              "field_repeatable" : 0,
              "field_value_type" : 0,
              "field_dataset:nid" : 0,
              "field_dataset:title" : 0,
              "field_dataset:url" : 0
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "search_api_aggregation_1" : "search_api_aggregation_1",
              "field_dataset" : "field_dataset",
              "search_api_language" : 0,
              "nid" : 0,
              "vid" : 0,
              "type" : 0,
              "title" : 0,
              "field_label" : 0,
              "field_repeatable" : 0,
              "field_value_type" : 0,
              "field_dataset:nid" : 0,
              "field_dataset:title" : 0,
              "field_dataset:url" : 0
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
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
