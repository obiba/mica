<?php
/**
 * @file
 * mica_data_access.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_data_access_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_data_access_request';
  $strongarm->value = 0;
  $export['comment_anonymous_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_data_access_review';
  $strongarm->value = 0;
  $export['comment_anonymous_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_data_access_request';
  $strongarm->value = '0';
  $export['comment_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_data_access_review';
  $strongarm->value = '2';
  $export['comment_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_data_access_request';
  $strongarm->value = 1;
  $export['comment_default_mode_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_data_access_review';
  $strongarm->value = 1;
  $export['comment_default_mode_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_data_access_request';
  $strongarm->value = '50';
  $export['comment_default_per_page_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_data_access_review';
  $strongarm->value = '50';
  $export['comment_default_per_page_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_data_access_request';
  $strongarm->value = 1;
  $export['comment_form_location_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_data_access_review';
  $strongarm->value = 1;
  $export['comment_form_location_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_data_access_request';
  $strongarm->value = '1';
  $export['comment_preview_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_data_access_review';
  $strongarm->value = '1';
  $export['comment_preview_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_data_access_request';
  $strongarm->value = 1;
  $export['comment_subject_field_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_data_access_review';
  $strongarm->value = 1;
  $export['comment_subject_field_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__data_access_review';
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
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_data_access_request';
  $strongarm->value = '0';
  $export['language_content_type_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_data_access_review';
  $strongarm->value = '0';
  $export['language_content_type_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_data_access_request';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_data_access_review';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_data_access_request';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_data_access_review';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_data_access_request';
  $strongarm->value = '1';
  $export['node_preview_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_data_access_review';
  $strongarm->value = '1';
  $export['node_preview_data_access_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_data_access_request';
  $strongarm->value = 0;
  $export['node_submitted_data_access_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_data_access_review';
  $strongarm->value = 0;
  $export['node_submitted_data_access_review'] = $strongarm;

  return $export;
}
