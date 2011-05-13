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
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
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
 * Implementation of hook_default_mica_relation().
 */
function mica_feature_default_mica_relation() {
  $items = array();
  $items['1'] = entity_import('mica_relation', '{
    "id" : "1",
    "parent_bundle" : "study",
    "child_bundle" : "study_information",
    "label" : "Study \\u00bb Study Information",
    "enabled" : "1",
    "options" : {
      "indexed" : 1,
      "cascaded" : 1,
      "node_reference" : "mica_study_information",
      "relation" : "study_study_information",
      "relation_parent_field" : "study_information_relation",
      "relation_child_field" : "study_relation",
    },
    "rdf_mapping" : []
  }');
  $items['2'] = entity_import('mica_relation', '{
    "id" : "2",
    "parent_bundle" : "study",
    "child_bundle" : "study_files",
    "label" : "Study \\u00bb Study Files",
    "enabled" : "1",
    "options" : {
      "indexed" : 0,
      "cascaded" : 1,
      "node_reference" : "mica_study_files",
      "relation" : "study_study_files",
      "relation_parent_field" : "study_files_relation",
      "relation_child_field" : "study_files",
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function mica_feature_node_info() {
  $items = array(
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('Description of a Contact, consisting of a person and an Institution.'),
      'has_title' => '1',
      'title_label' => t('Person and Institution Names'),
      'help' => '',
    ),
    'institution' => array(
      'name' => t('Institution'),
      'base' => 'node_content',
      'description' => t('Description of an Institution.'),
      'has_title' => '1',
      'title_label' => t('Institution Name'),
      'help' => '',
    ),
    'study' => array(
      'name' => t('Study'),
      'base' => 'node_content',
      'description' => t('Study portal. Create a content of this type when registering a new study.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'study_files' => array(
      'name' => t('Study Files'),
      'base' => 'node_content',
      'description' => t('Files attached to a Study. Child of Study.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'study_information' => array(
      'name' => t('Study Information'),
      'base' => 'node_content',
      'description' => t('General Information about a Study. Child of Study.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'variable' => array(
      'name' => t('Variable'),
      'base' => 'node_content',
      'description' => t('Description of information collected about the studies.'),
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
function mica_feature_default_search_api_facet() {
  $items = array();
  $items['studies_index_mica_study_infor_1'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_1",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_design_target",
    "name" : "Study Information \\u00bb Targets Recruitment of",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Targets Recruitment of",
      "options" : {
        "families" : "Families (including twin studies, sibships and family based birth cohorts)",
        "individuals" : "Individuals",
        "other" : "Other"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_2'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_2",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_selection_criteria",
    "name" : "Study Information \\u00bb Selection Criteria \\/ Charactecteristic of the Population",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Selection Criteria \\/ Charactecteristic of the Population",
      "options" : {
        "age" : "Age",
        "country" : "Country(ies) of residence",
        "gender" : "Gender",
        "other" : "Other"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_3'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_3",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_study_country",
    "name" : "Study Information \\u00bb Country",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Country",
      "options" : {
        "CAN" : "Canada",
        "CRI" : "Costa Rica",
        "DNK" : "Danemark",
        "FRA" : "France",
        "GBR" : "United Kingdom",
        "USA" : "United States"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_4'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_4",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_gender",
    "name" : "Study Information \\u00bb Specify Gender",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Specify Gender",
      "options" : { "men" : "Men", "women" : "Women" }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_5'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_5",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_biosamples_collected",
    "name" : "Study Information \\u00bb Biological Samples Collected",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Biological Samples Collected",
      "options" : {
        "blood" : "Blood",
        "others" : "Others",
        "saliva" : "Saliva",
        "tissues" : "Tissues",
        "urine" : "Urine"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_6'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_6",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_gwas_analysis",
    "name" : "Study Information \\u00bb Proceeding to Genome-Wide Association (GWA) Analysis",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Proceeding to Genome-Wide Association (GWA) Analysis",
      "options" : {
        "no" : "No",
        "yes_currently" : "Yes, we already have, or are currently in the process of generating, GWA data",
        "yes_later" : "Yes, we plan to proceed to GWA analysis later"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_7'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_infor_7",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_access",
    "name" : "Study Information \\u00bb Access to the following features is provided or foreseen",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Access to the following features is provided or foreseen",
      "options" : {
        "biological_samples" : "Biological samples",
        "data" : "Data (questionnaire-derived, measured\\u2026)",
        "other" : "Other"
      }
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_informa'] = entity_import('search_api_facet', '{
    "delta" : "studies_index_mica_study_informa",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_design",
    "name" : "Study Information \\u00bb Baseline Design of the Study",
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
      "type" : "options",
      "field_name" : "Study Information \\u00bb Baseline Design of the Study",
      "options" : {
        "case_control" : "Case-control study",
        "case_only" : "Case only study",
        "clinical_trial" : "Clinical trial \\/ intervention trial",
        "cohort_study" : "Cohort study",
        "cross_sectional" : "Cross-sectional prevalence study",
        "other" : "Other",
        "registry" : "Registry"
      }
    },
    "rdf_mapping" : []
  }');
  $items['variables_index_field_bundle'] = entity_import('search_api_facet', '{
    "delta" : "variables_index_field_bundle",
    "index_id" : "variables_index",
    "field" : "field_bundle",
    "name" : "Variables Index: Content Type",
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
      "type" : "string",
      "field_name" : "Content Type"
    },
    "rdf_mapping" : []
  }');
  $items['variables_index_field_value_type'] = entity_import('search_api_facet', '{
    "delta" : "variables_index_field_value_type",
    "index_id" : "variables_index",
    "field" : "field_value_type",
    "name" : "Variables Index: Value Type",
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
      "type" : "string",
      "field_name" : "Value Type"
    },
    "rdf_mapping" : []
  }');
  $items['variables_index_title'] = entity_import('search_api_facet', '{
    "delta" : "variables_index_title",
    "index_id" : "variables_index",
    "field" : "title",
    "name" : "Variables Index: Title",
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
      "type" : "text",
      "field_name" : "Title"
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
  $items['studies_index'] = entity_import('search_api_index', '{
    "name" : "Studies Index",
    "machine_name" : "studies_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
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
        "field_tags" : {
          "name" : "Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_study_legacy_id" : {
          "name" : "Legacy Id",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_files" : {
          "name" : "Study Files",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "mica_study_information" : {
          "name" : "Study Information",
          "indexed" : 1,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_bundle" : {
          "name" : "Content Type",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_original_field_name" : { "name" : "Field Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_value_type" : {
          "name" : "Value Type",
          "indexed" : 0,
          "type" : "string",
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
        "field_postal_code" : {
          "name" : "Postal Code",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_street" : { "name" : "Street", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_access" : {
          "name" : "Access to the following features is provided or foreseen",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_access_other" : {
          "name" : "Specify type of access",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_age_max" : { "name" : "Max age", "indexed" : 1, "type" : "integer", "boost" : "1.0" },
        "field_age_min" : { "name" : "Min age", "indexed" : 1, "type" : "integer", "boost" : "1.0" },
        "field_biosamples_collected" : {
          "name" : "Biological Samples Collected",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_biosamples_collected_other" : {
          "name" : "Specify type of samples collected",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_biosamples_tissues" : {
          "name" : "Specify type of tissues collected",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_contact" : {
          "name" : "Contact",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_design" : {
          "name" : "Baseline Design of the Study",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_design_other" : {
          "name" : "Specify type of design",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_design_target" : {
          "name" : "Targets Recruitment of",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_full_name" : { "name" : "Full Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
        "field_gender" : {
          "name" : "Specify Gender",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_gwas_analysis" : {
          "name" : "Proceeding to Genome-Wide Association (GWA) Analysis",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_gwas_number" : {
          "name" : "Please specify the approximate number of participants",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_investigator" : {
          "name" : "Investigator",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_selection_criteria" : {
          "name" : "Selection Criteria \\/ Charactecteristic of the Population",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_status_end" : {
          "name" : "End year",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_status_start" : {
          "name" : "Start year",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_study_country" : { "name" : "Country", "indexed" : 1, "type" : "string", "boost" : "1.0" },
        "field_target_number_biosamples" : {
          "name" : "Target Number of Biological Samples",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_target_number_participants" : {
          "name" : "Target Number of Participants",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "field_target_other" : {
          "name" : "Specify type of target",
          "indexed" : 1,
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
        },
        "mica_study_information:nid" : {
          "name" : "Study Information \\u00bb Node ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:vid" : {
          "name" : "Study Information \\u00bb Revision ID",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:is_new" : {
          "name" : "Study Information \\u00bb Is new",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "mica_study_information:type" : {
          "name" : "Study Information \\u00bb Content type",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:title" : {
          "name" : "Study Information \\u00bb Title",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:language" : {
          "name" : "Study Information \\u00bb Language",
          "indexed" : 0,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:url" : {
          "name" : "Study Information \\u00bb URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "mica_study_information:edit_url" : {
          "name" : "Study Information \\u00bb Edit URL",
          "indexed" : 0,
          "type" : "uri",
          "boost" : "1.0"
        },
        "mica_study_information:status" : {
          "name" : "Study Information \\u00bb Published",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "mica_study_information:promote" : {
          "name" : "Study Information \\u00bb Promoted to frontpage",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "mica_study_information:sticky" : {
          "name" : "Study Information \\u00bb Sticky in lists",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "mica_study_information:created" : {
          "name" : "Study Information \\u00bb Date created",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "mica_study_information:changed" : {
          "name" : "Study Information \\u00bb Date changed",
          "indexed" : 0,
          "type" : "date",
          "boost" : "1.0"
        },
        "mica_study_information:author" : {
          "name" : "Study Information \\u00bb Author",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "user",
          "boost" : "1.0"
        },
        "mica_study_information:source" : {
          "name" : "Study Information \\u00bb Translation source node",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "mica_study_information:log" : {
          "name" : "Study Information \\u00bb Revision log message",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:revision" : {
          "name" : "Study Information \\u00bb Creates revision",
          "indexed" : 0,
          "type" : "boolean",
          "boost" : "1.0"
        },
        "mica_study_information:comment" : {
          "name" : "Study Information \\u00bb Comments allowed",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:comment_count" : {
          "name" : "Study Information \\u00bb Comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:comment_count_new" : {
          "name" : "Study Information \\u00bb New comment count",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_study_legacy_id" : {
          "name" : "Study Information \\u00bb Study Legacy Id",
          "indexed" : 0,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_access" : {
          "name" : "Study Information \\u00bb Access to the following features is provided or foreseen",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_access_other" : {
          "name" : "Study Information \\u00bb Specify type of access",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:field_age_max" : {
          "name" : "Study Information \\u00bb Max age",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_age_min" : {
          "name" : "Study Information \\u00bb Min age",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_biosamples_collected" : {
          "name" : "Study Information \\u00bb Biological Samples Collected",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_biosamples_collected_other" : {
          "name" : "Study Information \\u00bb Specify type of samples collected",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:field_biosamples_tissues" : {
          "name" : "Study Information \\u00bb Specify type of tissues collected",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:field_contact" : {
          "name" : "Study Information \\u00bb Contact",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "mica_study_information:field_design" : {
          "name" : "Study Information \\u00bb Baseline Design of the Study",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_design_other" : {
          "name" : "Study Information \\u00bb Specify type of design",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:field_design_target" : {
          "name" : "Study Information \\u00bb Targets Recruitment of",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_full_name" : {
          "name" : "Study Information \\u00bb Full Name",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        },
        "mica_study_information:field_gender" : {
          "name" : "Study Information \\u00bb Specify Gender",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_gwas_analysis" : {
          "name" : "Study Information \\u00bb Proceeding to Genome-Wide Association (GWA) Analysis",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_gwas_number" : {
          "name" : "Study Information \\u00bb Please specify the approximate number of participants",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_investigator" : {
          "name" : "Study Information \\u00bb Investigator",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "mica_study_information:field_selection_criteria" : {
          "name" : "Study Information \\u00bb Selection Criteria \\/ Charactecteristic of the Population",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_status_end" : {
          "name" : "Study Information \\u00bb End year",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_status_start" : {
          "name" : "Study Information \\u00bb Start year",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_study_country" : {
          "name" : "Study Information \\u00bb Country",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "mica_study_information:field_target_number_biosamples" : {
          "name" : "Study Information \\u00bb Target Number of Biological Samples",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_target_number_participants" : {
          "name" : "Study Information \\u00bb Target Number of Participants",
          "indexed" : 1,
          "type" : "integer",
          "boost" : "1.0"
        },
        "mica_study_information:field_target_other" : {
          "name" : "Study Information \\u00bb Specify type of target",
          "indexed" : 1,
          "type" : "text",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "default" : "0",
            "bundles" : { "study" : "study", "study_information" : "study_information" }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_fulltext" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_processor_study_fields" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['variables_index'] = entity_import('search_api_index', '{
    "name" : "Variables Index",
    "machine_name" : "variables_index",
    "description" : null,
    "server" : "solr",
    "entity_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "default" : "0", "bundles" : { "variable" : "variable" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_fulltext" : { "status" : 0, "weight" : "0", "settings" : null },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_processor_study_fields" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
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
          "indexed" : 0,
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
        "field_tags" : {
          "name" : "Tags",
          "indexed" : 0,
          "type" : "list\\u003cinteger\\u003e",
          "entity_type" : "taxonomy_term",
          "boost" : "1.0"
        },
        "field_event_date" : { "name" : "Event Date", "indexed" : 0, "type" : "date", "boost" : "1.0" },
        "mica_study_information" : {
          "name" : "Study Information",
          "indexed" : 0,
          "type" : "integer",
          "entity_type" : "node",
          "boost" : "1.0"
        },
        "field_bundle" : {
          "name" : "Content Type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_original_field_name" : {
          "name" : "Field Name",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_value_type" : {
          "name" : "Value Type",
          "indexed" : 1,
          "type" : "string",
          "boost" : "1.0"
        },
        "field_study_contact_email" : {
          "name" : "Contact Email",
          "indexed" : 0,
          "type" : "text",
          "boost" : "1.0"
        },
        "field_study_country" : { "name" : "Country", "indexed" : 0, "type" : "string", "boost" : "1.0" },
        "field_study_full_name" : { "name" : "Full Name", "indexed" : 0, "type" : "text", "boost" : "1.0" },
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
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implementation of hook_default_search_api_range().
 */
function mica_feature_default_search_api_range() {
  $items = array();
  $items['studies_index_mica_study_infor_1'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_1",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_age_min",
    "name" : "Study Information \\u00bb Min age",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Min age"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_2'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_2",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_age_max",
    "name" : "Study Information \\u00bb Max age",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Max age"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_3'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_3",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_target_number_biosamples",
    "name" : "Study Information \\u00bb Target Number of Biological Samples",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Target Number of Biological Samples"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_4'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_4",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_gwas_number",
    "name" : "Study Information \\u00bb Please specify the approximate number of participants",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Please specify the approximate number of participants"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_5'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_5",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_status_start",
    "name" : "Study Information \\u00bb Start year",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Start year"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_infor_6'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_infor_6",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_status_end",
    "name" : "Study Information \\u00bb End year",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb End year"
    },
    "rdf_mapping" : []
  }');
  $items['studies_index_mica_study_informa'] = entity_import('search_api_range', '{
    "delta" : "studies_index_mica_study_informa",
    "index_id" : "studies_index",
    "field" : "mica_study_information:field_target_number_participants",
    "name" : "Study Information \\u00bb Target Number of Participants",
    "enabled" : "1",
    "options" : {
      "field_prefix" : "",
      "field_suffix" : "",
      "default_true" : true,
      "ids_list" : [],
      "type" : "integer",
      "field_name" : "Study Information \\u00bb Target Number of Participants"
    },
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
