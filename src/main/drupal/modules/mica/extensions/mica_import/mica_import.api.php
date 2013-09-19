<?php

/**
 * @file
 * Documentation of Mica_import hooks.
 */

/**
 * @return array permission parameter to access this features
 */
function hook_mica_import_permission_parameters() {
  return array(
    'import studies' => array(
      'title' => t('Import Studies'),
      'description' => t('Allow users importing studies')
    )
  );
}

/**
 * @return true, false to verify if user have permission to this features
 */
function hook_mica_import_can_import_node() {
  return user_access('import studies');
}


/*
 * Get correct mapped array to create node
 * @param $value_xml : array generated XML
 * @return $fields_array
 * */


function hook_mica_import_get_fields($value_xml){


}

