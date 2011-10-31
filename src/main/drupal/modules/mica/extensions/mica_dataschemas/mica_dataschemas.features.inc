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
    'dataschema' => array(
      'name' => t('DataSchema'),
      'base' => 'node_content',
      'description' => t('Identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_domain' => array(
      'name' => t('Domain'),
      'base' => 'node_content',
      'description' => t('A domain is a risk factor or an outcome of interest, subsuming a number of variables.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_module' => array(
      'name' => t('Module'),
      'base' => 'node_content',
      'description' => t('A module is a grouping based on variables main unit of interest, assessment modes or type of element measured or collected. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_theme' => array(
      'name' => t('Theme'),
      'base' => 'node_content',
      'description' => t('A theme is a general area of interest.'),
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
    "name" : "DataSchema variables index: DataSchema",
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
      "field_name" : "DataSchema",
      "entity_type" : "node"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_dim_c'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_dim_c",
    "index_id" : "dataschema_variables_index",
    "field" : "field_dim_class",
    "name" : "DataSchema variables index: Class",
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
  $items['dataschema_variables_field_domai'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_domai",
    "index_id" : "dataschema_variables_index",
    "field" : "field_domain",
    "name" : "DataSchema variables index: Domain",
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
      "field_name" : "Domain",
      "entity_type" : "node"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_modul'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_modul",
    "index_id" : "dataschema_variables_index",
    "field" : "field_module",
    "name" : "DataSchema variables index: Module",
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
      "field_name" : "Module",
      "entity_type" : "node"
    },
    "rdf_mapping" : []
  }');
  $items['dataschema_variables_field_theme'] = entity_import('search_api_facet', '{
    "delta" : "dataschema_variables_field_theme",
    "index_id" : "dataschema_variables_index",
    "field" : "field_theme",
    "name" : "DataSchema variables index: Theme",
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
      "field_name" : "Theme",
      "entity_type" : "node"
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
      "cron_limit" : "50",
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
        "field_associations" : {
          "name" : "Associations",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_scientific_references" : {
          "name" : "Scientific References",
          "indexed" : 0,
          "type" : "list\\u003ctext\\u003e",
          "boost" : "1.0"
        },
        "field_uri" : { "name" : "URI", "indexed" : 1, "type" : "uri", "boost" : "1.0" },
        "field_variables_justification" : {
          "name" : "Variables Justification",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_dim_class" : {
          "name" : "Class",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_dim_collection_mode" : {
          "name" : "Collection mode",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dim_disease" : {
          "name" : "Disease",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_dim_format" : { "name" : "Format", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_dim_med_health_interv" : {
          "name" : "Medical Health Intervention",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dim_period" : { "name" : "Period", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_dim_sample" : {
          "name" : "Sample",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_dim_source_of_info" : {
          "name" : "Source of information",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_dim_target" : { "name" : "Target", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_dim_target_gender" : {
          "name" : "Target gender",
          "indexed" : 0,
          "type" : "list\\u003cstring\\u003e",
          "boost" : "1.0"
        },
        "field_dim_type" : { "name" : "Type", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_domain" : {
          "name" : "Domain",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_module" : {
          "name" : "Module",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_theme" : {
          "name" : "Theme",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_unit" : { "name" : "Unit", "indexed" : 1, "type" : "text", "boost" : "1.0" },
        "field_dataschema_ref" : {
          "name" : "DataSchema",
          "indexed" : 1,
          "type" : "list\\u003cinteger\\u003e",
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
          "settings" : { "default" : "0", "bundles" : { "ds_variable" : "ds_variable" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : "title",
              "field_unit" : "field_unit",
              "body:value" : "body:value",
              "search_api_language" : 0,
              "type" : 0,
              "field_uri" : 0,
              "field_dim_class" : 0,
              "field_domain" : 0,
              "field_module" : 0,
              "field_theme" : 0
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : "title",
              "field_unit" : "field_unit",
              "body:value" : "body:value",
              "search_api_language" : 0,
              "type" : 0,
              "field_uri" : 0,
              "field_dim_class" : 0,
              "field_domain" : 0,
              "field_module" : 0,
              "field_theme" : 0
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
              "title" : "title",
              "field_unit" : "field_unit",
              "body:value" : "body:value",
              "search_api_language" : 0,
              "type" : 0,
              "field_uri" : 0,
              "field_dim_class" : 0,
              "field_domain" : 0,
              "field_module" : 0,
              "field_theme" : 0
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
    "enabled" : "0",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
