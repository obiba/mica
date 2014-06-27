<?php
/**
 * @file
 * mica_publications.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function mica_publications_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_publication_pmid.translatable"] = 0;

  // Exported overrides for: search_api_index
  $overrides["search_api_index.publications.options|fields|field_category"] = array(
    'type' => 'list<integer>',
    'entity_type' => 'taxonomy_term',
  );

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_node__publication.value|extra_fields|display|language"] = array(
    'teaser' => array(
      'weight' => 0,
      'visible' => FALSE,
    ),
  );
  $overrides["variable.field_bundle_settings_node__publication.value|extra_fields|form|language"] = array(
    'weight' => -50,
  );
  $overrides["variable.field_bundle_settings_node__publication.value|extra_fields|form|path"] = array(
    'weight' => 30,
  );

  // Exported overrides for: views_view
  $overrides["views_view.publication_search.display|default|display_options|fields|field_abstract"]["DELETED"] = TRUE;
  $overrides["views_view.publication_search.display|default|display_options|fields|field_category"] = array(
    'id' => 'field_category',
    'table' => 'search_api_index_publications',
    'field' => 'field_category',
    'label' => 'Tags :',
    'element_label_colon' => FALSE,
    'hide_empty' => TRUE,
    'link_to_entity' => 0,
    'view_mode' => 'full',
    'bypass_access' => 0,
  );

  return $overrides;
}
