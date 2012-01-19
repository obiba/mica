<?php
/**
 * @file
 * mica_devel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_devel_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'devel_switch_user_include_anon';
  $strongarm->value = 0;
  $export['devel_switch_user_include_anon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'devel_switch_user_list_size';
  $strongarm->value = '10';
  $export['devel_switch_user_list_size'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'devel_switch_user_show_form';
  $strongarm->value = 1;
  $export['devel_switch_user_show_form'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_admin_roles';
  $strongarm->value = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    7 => '7',
    6 => '6',
    8 => '8',
  );
  $export['masquerade_admin_roles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_quick_switches';
  $strongarm->value = array(
    0 => '1',
    1 => '3',
    2 => '4',
  );
  $export['masquerade_quick_switches'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'masquerade_test_user';
  $strongarm->value = '';
  $export['masquerade_test_user'] = $strongarm;


  return $export;
}
