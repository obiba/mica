<?php
/**
 * @file
 * mica_networks.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_networks_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_network';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_network';
  $strongarm->value = 0;
  $export['comment_anonymous_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_network';
  $strongarm->value = 1;
  $export['comment_default_mode_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_network';
  $strongarm->value = '50';
  $export['comment_default_per_page_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_network';
  $strongarm->value = 1;
  $export['comment_form_location_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_network';
  $strongarm->value = '0';
  $export['comment_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_network';
  $strongarm->value = '1';
  $export['comment_preview_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_network';
  $strongarm->value = 1;
  $export['comment_subject_field_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_network';
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
  $export['content_access_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__network';
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
        'custom_settings' => TRUE,
      ),
      'left_area' => array(
        'custom_settings' => TRUE,
      ),
      'right_area' => array(
        'custom_settings' => TRUE,
      ),
      'center_area' => array(
        'custom_settings' => TRUE,
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
          'weight' => '10',
        ),
        'path' => array(
          'weight' => '11',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_network';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_network';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_network';
  $strongarm->value = '1';
  $export['node_preview_network'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_network';
  $strongarm->value = 0;
  $export['node_submitted_network'] = $strongarm;

  return $export;
}
