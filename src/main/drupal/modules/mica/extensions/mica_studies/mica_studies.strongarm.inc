<?php
/**
 * @file
 * mica_studies.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_studies_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_address';
  $strongarm->value = 'edit-comment';
  $export['additional_settings__active_tab_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_contact';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_documents';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_population';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_study';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_contact';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_study';
  $strongarm->value = '0';
  $export['auto_entitylabel_node_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_contact';
  $strongarm->value = '<?php
$wrapper = entity_metadata_wrapper(\'node\', $entity);
$institution = $wrapper->language($language)->field_institution_name->value();
$parts = array();
$parts[] = trim($wrapper->field_contact_name->title->value());
$parts[] = trim($wrapper->field_contact_name->given->value());
$parts[] = trim($wrapper->field_contact_name->family->value());
$parts = array_filter($parts);
$title = implode(\' \', $parts);
if (!empty($institution)) $title .= \' (\' . trim($institution) . \')\';
if (strlen($title) > 255) $title = truncate_utf8($title, 255, TRUE);
return $title;
?>';
  $export['auto_entitylabel_pattern_node_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_contact';
  $strongarm->value = 1;
  $export['auto_entitylabel_php_node_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cascaded_population';
  $strongarm->value = 1;
  $export['cascaded_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'child_indexes_population';
  $strongarm->value = array();
  $export['child_indexes_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_address';
  $strongarm->value = '0';
  $export['comment_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_address';
  $strongarm->value = 0;
  $export['comment_anonymous_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_contact';
  $strongarm->value = 0;
  $export['comment_anonymous_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_data_collection_event';
  $strongarm->value = 0;
  $export['comment_anonymous_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_documents';
  $strongarm->value = 0;
  $export['comment_anonymous_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_population';
  $strongarm->value = 0;
  $export['comment_anonymous_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_study';
  $strongarm->value = 0;
  $export['comment_anonymous_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_contact';
  $strongarm->value = '0';
  $export['comment_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_data_collection_event';
  $strongarm->value = '0';
  $export['comment_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_address';
  $strongarm->value = 1;
  $export['comment_default_mode_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_contact';
  $strongarm->value = 1;
  $export['comment_default_mode_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_data_collection_event';
  $strongarm->value = 1;
  $export['comment_default_mode_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_documents';
  $strongarm->value = 1;
  $export['comment_default_mode_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_population';
  $strongarm->value = 0;
  $export['comment_default_mode_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_study';
  $strongarm->value = 1;
  $export['comment_default_mode_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_address';
  $strongarm->value = '50';
  $export['comment_default_per_page_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_contact';
  $strongarm->value = '50';
  $export['comment_default_per_page_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_data_collection_event';
  $strongarm->value = '50';
  $export['comment_default_per_page_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_documents';
  $strongarm->value = '50';
  $export['comment_default_per_page_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_population';
  $strongarm->value = '50';
  $export['comment_default_per_page_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_study';
  $strongarm->value = '50';
  $export['comment_default_per_page_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_documents';
  $strongarm->value = '1';
  $export['comment_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_address';
  $strongarm->value = 1;
  $export['comment_form_location_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_contact';
  $strongarm->value = 1;
  $export['comment_form_location_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_data_collection_event';
  $strongarm->value = 1;
  $export['comment_form_location_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_documents';
  $strongarm->value = 1;
  $export['comment_form_location_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_population';
  $strongarm->value = 1;
  $export['comment_form_location_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_study';
  $strongarm->value = 1;
  $export['comment_form_location_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_institution';
  $strongarm->value = '1';
  $export['comment_institution'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page';
  $strongarm->value = 0;
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_population';
  $strongarm->value = '0';
  $export['comment_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_address';
  $strongarm->value = '1';
  $export['comment_preview_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_contact';
  $strongarm->value = '1';
  $export['comment_preview_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_data_collection_event';
  $strongarm->value = '1';
  $export['comment_preview_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_documents';
  $strongarm->value = '1';
  $export['comment_preview_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_population';
  $strongarm->value = '1';
  $export['comment_preview_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_study';
  $strongarm->value = '1';
  $export['comment_preview_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_study';
  $strongarm->value = '1';
  $export['comment_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_address';
  $strongarm->value = 1;
  $export['comment_subject_field_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_contact';
  $strongarm->value = 1;
  $export['comment_subject_field_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_data_collection_event';
  $strongarm->value = 1;
  $export['comment_subject_field_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_documents';
  $strongarm->value = 1;
  $export['comment_subject_field_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_population';
  $strongarm->value = 1;
  $export['comment_subject_field_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_study';
  $strongarm->value = 1;
  $export['comment_subject_field_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_contact';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'per_node' => 1,
  );
  $export['content_access_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_data_collection_event';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'per_node' => 1,
  );
  $export['content_access_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_population';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 3,
      3 => 4,
    ),
    'per_node' => 1,
  );
  $export['content_access_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_study';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 6,
      3 => 5,
      4 => 3,
      5 => 4,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 6,
      3 => 5,
      4 => 3,
      5 => 4,
    ),
    'per_node' => 1,
  );
  $export['content_access_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_month_year';
  $strongarm->value = 'M Y';
  $export['date_format_month_year'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__data_collection_event';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'banner_area' => array(
        'custom_settings' => FALSE,
      ),
      'left_area' => array(
        'custom_settings' => FALSE,
      ),
      'right_area' => array(
        'custom_settings' => FALSE,
      ),
      'center_area' => array(
        'custom_settings' => FALSE,
      ),
      'footer_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_banner_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_left_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_right_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_center_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_footer_area' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__population';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'banner_area' => array(
        'custom_settings' => FALSE,
      ),
      'left_area' => array(
        'custom_settings' => FALSE,
      ),
      'right_area' => array(
        'custom_settings' => FALSE,
      ),
      'center_area' => array(
        'custom_settings' => FALSE,
      ),
      'footer_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_banner_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_left_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_right_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_center_area' => array(
        'custom_settings' => FALSE,
      ),
      'summary_footer_area' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_fonts_enabled_fonts';
  $strongarm->value = array(
    'Nunito' => array(
      'family' => 'Nunito',
      'variants' => array(
        400 => '400',
      ),
      'subsets' => 'latin',
    ),
    'Yanone_Kaffeesatz' => array(
      'family' => 'Yanone Kaffeesatz',
      'variants' => array(
        400 => '400',
      ),
      'subsets' => 'latin',
    ),
  );
  $export['google_fonts_enabled_fonts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_fonts_webfonts';
  $strongarm->value = array(
    0 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Aclonica',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    1 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Allan',
      'variants' => array(
        0 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    2 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Allerta',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    3 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Allerta Stencil',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    4 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Amaranth',
      'variants' => array(
        0 => 'regular',
        1 => '400italic',
        2 => '700',
        3 => '700italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    5 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Angkor',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    6 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Annie Use Your Telescope',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    7 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Anonymous Pro',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    8 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Anton',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    9 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Architects Daughter',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    10 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Arimo',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    11 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Artifika',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    12 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Arvo',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    13 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Astloch',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    14 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bangers',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    15 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Battambang',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    16 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bayon',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    17 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bentham',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    18 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bevan',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    19 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bigshot One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    20 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Bokor',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    21 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Brawler',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    22 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Buda',
      'variants' => array(
        0 => '300',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    23 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cabin',
      'variants' => array(
        0 => '400',
        1 => '400italic',
        2 => '500',
        3 => '500italic',
        4 => '600',
        5 => '600italic',
        6 => 'bold',
        7 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    24 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cabin Sketch',
      'variants' => array(
        0 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    25 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Calligraffitti',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    26 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Candal',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    27 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cantarell',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    28 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cardo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    29 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Carter One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    30 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Caudex',
      'variants' => array(
        0 => '400',
        1 => 'italic',
        2 => '700',
        3 => '700italic',
      ),
      'subsets' => array(
        0 => 'greek',
        1 => 'greek-ext',
        2 => 'latin',
        3 => 'latin-ext',
      ),
    ),
    31 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cedarville Cursive',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    32 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Chenla',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    33 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cherry Cream Soda',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    34 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Chewy',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    35 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Coda',
      'variants' => array(
        0 => '800',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    36 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Coda Caption',
      'variants' => array(
        0 => '800',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    37 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Coming Soon',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    38 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Content',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    39 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Copse',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    40 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Corben',
      'variants' => array(
        0 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    41 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cousine',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    42 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Covered By Your Grace',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    43 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Crafty Girls',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    44 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Crimson Text',
      'variants' => array(
        0 => 'regular',
        1 => '400italic',
        2 => '600',
        3 => '600italic',
        4 => '700',
        5 => '700italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    45 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Crushed',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    46 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Cuprum',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    47 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Damion',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    48 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Dancing Script',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    49 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Dangrek',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    50 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Dawning of a New Day',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    51 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Didact Gothic',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    52 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Droid Sans',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    53 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Droid Sans Mono',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    54 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Droid Serif',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    55 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'EB Garamond',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'latin',
        3 => 'latin-ext',
        4 => 'vietnamese',
      ),
    ),
    56 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Expletus Sans',
      'variants' => array(
        0 => '400',
        1 => '400italic',
        2 => '500',
        3 => '500italic',
        4 => '600',
        5 => '600italic',
        6 => '700',
        7 => '700italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    57 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Fontdiner Swanky',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    58 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Francois One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    59 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Freehand',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    60 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'GFS Didot',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'greek',
      ),
    ),
    61 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'GFS Neohellenic',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'greek',
      ),
    ),
    62 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Geo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    63 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Goudy Bookletter 1911',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    64 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Gruppo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    65 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Hanuman',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    66 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Holtwood One SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    67 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Homemade Apple',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    68 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell DW Pica',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    69 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell DW Pica SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    70 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell Double Pica',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    71 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell Double Pica SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    72 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell English',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    73 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell English SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    74 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell French Canon',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    75 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell French Canon SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    76 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell Great Primer',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    77 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'IM Fell Great Primer SC',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    78 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Inconsolata',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    79 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Indie Flower',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    80 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Irish Grover',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    81 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Josefin Sans',
      'variants' => array(
        0 => '100',
        1 => '100italic',
        2 => '300',
        3 => '300italic',
        4 => '400',
        5 => '400italic',
        6 => '600',
        7 => '600italic',
        8 => '700',
        9 => '700italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    82 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Josefin Slab',
      'variants' => array(
        0 => '100',
        1 => '100italic',
        2 => '300',
        3 => '300italic',
        4 => '400',
        5 => '400italic',
        6 => '600',
        7 => '600italic',
        8 => '700',
        9 => '700italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    83 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Judson',
      'variants' => array(
        0 => '400',
        1 => '400italic',
        2 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    84 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Jura',
      'variants' => array(
        0 => '300',
        1 => '400',
        2 => '500',
        3 => '600',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    85 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Just Another Hand',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    86 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Just Me Again Down Here',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    87 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Kameron',
      'variants' => array(
        0 => '400',
        1 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    88 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Kenia',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    89 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Khmer',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    90 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Koulen',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    91 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Kranky',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    92 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Kreon',
      'variants' => array(
        0 => '300',
        1 => '400',
        2 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    93 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Kristi',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    94 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'La Belle Aurore',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    95 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Lato',
      'variants' => array(
        0 => '100',
        1 => '100italic',
        2 => '300',
        3 => '300italic',
        4 => '400',
        5 => '400italic',
        6 => '700',
        7 => '700italic',
        8 => '900',
        9 => '900italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    96 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'League Script',
      'variants' => array(
        0 => '400',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    97 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Lekton',
      'variants' => array(
        0 => '400',
        1 => 'italic',
        2 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    98 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Limelight',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    99 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Lobster',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'latin',
        3 => 'latin-ext',
      ),
    ),
    100 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Lora',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    101 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Luckiest Guy',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    102 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Maiden Orange',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    103 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Mako',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    104 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Maven Pro',
      'variants' => array(
        0 => '400',
        1 => '500',
        2 => '700',
        3 => '900',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    105 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Meddon',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    106 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'MedievalSharp',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
        1 => 'latin-ext',
      ),
    ),
    107 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Megrim',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    108 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Merriweather',
      'variants' => array(
        0 => '300',
        1 => 'regular',
        2 => '700',
        3 => '900',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    109 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Metal',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    110 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Metrophobic',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    111 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Michroma',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    112 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Miltonian',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    113 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Miltonian Tattoo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    114 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Molengo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    115 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Monofett',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    116 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Moul',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    117 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Moulpali',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    118 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Mountains of Christmas',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    119 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Muli',
      'variants' => array(
        0 => '300',
        1 => '300italic',
        2 => '400',
        3 => '400italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    120 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Neucha',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    121 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Neuton',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
        1 => 'latin-ext',
      ),
    ),
    122 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'News Cycle',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    123 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nobile',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    124 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Cut',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    125 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Flat',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    126 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Mono',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'greek',
        1 => 'latin',
      ),
    ),
    127 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Oval',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    128 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Round',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    129 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Script',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    130 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Slim',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    131 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nova Square',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    132 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Nunito',
      'variants' => array(
        0 => '300',
        1 => '400',
        2 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    133 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'OFL Sorts Mill Goudy TT',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    134 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Odor Mean Chey',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    135 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Old Standard TT',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    136 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Open Sans',
      'variants' => array(
        0 => '300',
        1 => '300italic',
        2 => '400',
        3 => '400italic',
        4 => '600',
        5 => '600italic',
        6 => '700',
        7 => '700italic',
        8 => '800',
        9 => '800italic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
        6 => 'vietnamese',
      ),
    ),
    137 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Open Sans Condensed',
      'variants' => array(
        0 => '300',
        1 => '300italic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    138 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Orbitron',
      'variants' => array(
        0 => '400',
        1 => '500',
        2 => '700',
        3 => '900',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    139 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Oswald',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    140 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Over the Rainbow',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    141 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'PT Sans',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    142 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'PT Sans Caption',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    143 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'PT Sans Narrow',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    144 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'PT Serif',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    145 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'PT Serif Caption',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    146 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Pacifico',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    147 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Paytone One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    148 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Permanent Marker',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    149 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Philosopher',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'latin',
      ),
    ),
    150 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Play',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    151 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Playfair Display',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    152 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Podkova',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    153 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Preahvihear',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    154 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Puritan',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    155 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Quattrocento',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    156 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Quattrocento Sans',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    157 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Radley',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    158 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Raleway',
      'variants' => array(
        0 => '100',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    159 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Reenie Beanie',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    160 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Rock Salt',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    161 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Rokkitt',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    162 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Ruslan Display',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'latin',
        3 => 'latin-ext',
      ),
    ),
    163 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Schoolbell',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    164 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Shadows Into Light',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    165 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Shanti',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    166 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Siemreap',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    167 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Sigmar One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    168 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Six Caps',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    169 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Slackey',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    170 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Smythe',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    171 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Sniglet',
      'variants' => array(
        0 => '800',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    172 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Special Elite',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    173 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Sue Ellen Francisco',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    174 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Sunshiney',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    175 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Suwannaphum',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    176 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Swanky and Moo Moo',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    177 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Syncopate',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    178 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Tangerine',
      'variants' => array(
        0 => 'regular',
        1 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    179 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Taprom',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'khmer',
      ),
    ),
    180 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Tenor Sans',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'latin',
        3 => 'latin-ext',
      ),
    ),
    181 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Terminal Dosis Light',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    182 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'The Girl Next Door',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    183 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Tinos',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    184 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Ubuntu',
      'variants' => array(
        0 => '300',
        1 => '300italic',
        2 => 'regular',
        3 => 'italic',
        4 => '500',
        5 => '500italic',
        6 => 'bold',
        7 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'cyrillic',
        1 => 'cyrillic-ext',
        2 => 'greek',
        3 => 'greek-ext',
        4 => 'latin',
        5 => 'latin-ext',
      ),
    ),
    185 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Ultra',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    186 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'UnifrakturCook',
      'variants' => array(
        0 => 'bold',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    187 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'UnifrakturMaguntia',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    188 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Unkempt',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    189 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'VT323',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    190 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Vibur',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    191 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Vollkorn',
      'variants' => array(
        0 => 'regular',
        1 => 'italic',
        2 => 'bold',
        3 => 'bolditalic',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    192 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Waiting for the Sunrise',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    193 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Wallpoet',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    194 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Walter Turncoat',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    195 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Wire One',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    196 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Yanone Kaffeesatz',
      'variants' => array(
        0 => '200',
        1 => '300',
        2 => '400',
        3 => '700',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
    197 => (object) array(
      'kind' => 'webfonts#webfont',
      'family' => 'Zeyada',
      'variants' => array(
        0 => 'regular',
      ),
      'subsets' => array(
        0 => 'latin',
      ),
    ),
  );
  $export['google_fonts_webfonts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'gd';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_profiles';
  $strongarm->value = array(
    1 => array(
      'name' => 'User-1',
      'usertab' => 1,
      'filesize' => 0,
      'quota' => 0,
      'tuquota' => 0,
      'extensions' => '*',
      'dimensions' => '1200x1200',
      'filenum' => 0,
      'directories' => array(
        0 => array(
          'name' => '.',
          'subnav' => 1,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 1,
          'resize' => 1,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Small',
          'dimensions' => '90x90',
          'prefix' => 'small_',
          'suffix' => '',
        ),
        1 => array(
          'name' => 'Medium',
          'dimensions' => '120x120',
          'prefix' => 'medium_',
          'suffix' => '',
        ),
        2 => array(
          'name' => 'Large',
          'dimensions' => '180x180',
          'prefix' => 'large_',
          'suffix' => '',
        ),
      ),
    ),
    2 => array(
      'name' => 'Sample profile',
      'usertab' => 1,
      'filesize' => '1',
      'quota' => '2',
      'tuquota' => '0',
      'extensions' => 'gif png jpg jpeg',
      'dimensions' => '800x600',
      'filenum' => '1',
      'directories' => array(
        0 => array(
          'name' => 'u%uid',
          'subnav' => 0,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 0,
          'resize' => 0,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Thumb',
          'dimensions' => '90x90',
          'prefix' => 'thumb_',
          'suffix' => '',
        ),
      ),
    ),
  );
  $export['imce_profiles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_roles_profiles';
  $strongarm->value = array(
    3 => array(
      'weight' => '0',
      'public_pid' => '2',
      'private_pid' => '2',
    ),
    4 => array(
      'weight' => '0',
      'public_pid' => '1',
      'private_pid' => '1',
    ),
    6 => array(
      'weight' => '0',
      'public_pid' => '1',
      'private_pid' => 0,
    ),
    7 => array(
      'weight' => '0',
      'public_pid' => '1',
      'private_pid' => 0,
    ),
    5 => array(
      'weight' => '0',
      'public_pid' => '1',
      'private_pid' => 0,
    ),
    2 => array(
      'weight' => 11,
      'public_pid' => 0,
      'private_pid' => 0,
    ),
    1 => array(
      'weight' => 12,
      'public_pid' => 0,
      'private_pid' => 0,
    ),
  );
  $export['imce_roles_profiles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_settings_absurls';
  $strongarm->value = 0;
  $export['imce_settings_absurls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_settings_disable_private';
  $strongarm->value = 1;
  $export['imce_settings_disable_private'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_settings_replace';
  $strongarm->value = '0';
  $export['imce_settings_replace'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_settings_textarea';
  $strongarm->value = '';
  $export['imce_settings_textarea'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_settings_thumb_method';
  $strongarm->value = 'scale_and_crop';
  $export['imce_settings_thumb_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'indexed_contact';
  $strongarm->value = 1;
  $export['indexed_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'indexed_population';
  $strongarm->value = 1;
  $export['indexed_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'indexed_study';
  $strongarm->value = 1;
  $export['indexed_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_address';
  $strongarm->value = array();
  $export['menu_options_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_contact';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_data_collection_event';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_documents';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_population';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_study';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_address';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_contact';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_data_collection_event';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_documents';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_population';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_study';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_address';
  $strongarm->value = '1';
  $export['node_preview_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_contact';
  $strongarm->value = '1';
  $export['node_preview_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_data_collection_event';
  $strongarm->value = '1';
  $export['node_preview_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_documents';
  $strongarm->value = '1';
  $export['node_preview_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_population';
  $strongarm->value = '1';
  $export['node_preview_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_study';
  $strongarm->value = '1';
  $export['node_preview_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_address';
  $strongarm->value = 0;
  $export['node_submitted_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_contact';
  $strongarm->value = 0;
  $export['node_submitted_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_data_collection_event';
  $strongarm->value = 0;
  $export['node_submitted_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_documents';
  $strongarm->value = 0;
  $export['node_submitted_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = FALSE;
  $export['node_submitted_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_population';
  $strongarm->value = 0;
  $export['node_submitted_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_study';
  $strongarm->value = 0;
  $export['node_submitted_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_contact';
  $strongarm->value = '';
  $export['parent_bundle_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_data_collection_event';
  $strongarm->value = '';
  $export['parent_bundle_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_documents';
  $strongarm->value = '';
  $export['parent_bundle_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_population';
  $strongarm->value = '';
  $export['parent_bundle_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_study';
  $strongarm->value = '';
  $export['parent_bundle_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_type_address';
  $strongarm->value = '';
  $export['parent_type_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_type_study';
  $strongarm->value = '';
  $export['parent_type_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_address';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_documents';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_population';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_study';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_study'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'translation_language_type';
  $strongarm->value = 'language_content';
  $export['translation_language_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_contact';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_data_collection_event';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_data_collection_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_population';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_population'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_study';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_study'] = $strongarm;

  return $export;
}
