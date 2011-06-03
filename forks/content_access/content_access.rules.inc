<?php

/**
 * @file
 * Rules specific functions that expose content_access' API.
 */

/**
 * Implementation of hook_action_info().
 */
function content_access_rules_action_info() {
  $actions = array(
    'content_access_action_grant_node_permissions' => array(
      'label' => t('Grant content permissions by role'),
    ),
    'content_access_action_revoke_node_permissions' => array(
      'label' => t('Revoke content permissions by role'),
    ),
    'content_access_action_reset_node_permissions' => array(
      'label' => t('Reset content permissions'),
    ),
  );

  $items = array();
  foreach ($actions as $name => $action) {
    $items[$name] = array(
      'label' => $action['label'],
      'named parameter' => TRUE,
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Content'),
          'description' => t('Add Desc.'),
        ),
        'content_access' => array(
          'type' => 'list<text>',
          'label' => t('Role Based Access Control Settings'),
          'optional' => TRUE,
          'options list' => 'content_access_action_roles_permissions_list',
          'restriction' => 'input',
        ),
      ),
      'group' => t('Content Access'),
      'callbacks' => array(
        #'access' => 'rules_action_entity_createfetch_access',
        'form_alter' => 'content_access_action_form_alter',
      ),
    );
  }

  return $items;
}

/**
 * Desc.
 */
function content_access_action_roles_permissions_list() {
  return _content_access_roles_list();
}

/**
 * Returns an array of operations used by the module.
 */
function _content_access_roles_list() {
  $defaults = array();
  $roles = array_map('filter_xss_admin', user_roles());

  // Make sure defaults are set properly
  foreach (_content_access_get_operations() as $op) {
    foreach ($roles as $role) {
      $defaults[$op][$op . ':' . $role] = $role;
    }
  }

  return $defaults;
}

/**
 * Desc.
 */
function content_access_list_to_checkboxes($element) {
  $checkboxes = array();
  $operations = _content_access_get_operations();

  foreach ($operations as $op) {
    $checkboxes[$op] = $element;
    $checkboxes[$op]['#title'] = t($op);
    $checkboxes[$op]['#type'] = 'checkboxes';
    $checkboxes[$op]['#options'] = $element['#options'][$op];
    unset($checkboxes[$op]['#default_value']);

    // Set defaults values of checkboxes
    foreach ($checkboxes[$op]['#options'] as $op_role => $permission) {
      if (isset($element['#default_value'][$op_role])) {
        $checkboxes[$op]['#default_value'][] = $op_role;
      }
    }

    #$checkboxes[$op]['#process'] = array('form_process_checkboxes', 'content_access_checkboxes');
  }

  return $checkboxes;
}

/**
 * Desc.
 */
function content_access_checkboxes_to_list($element) {
  $list = $element[key($element)];
  $list['#title'] = 'Value';
  $list['#type'] = 'select';
  unset($list['#options']);

  foreach ($element as $op => $value) {
    $list['#options'][$op] = $value['#options'];
  }
  return $list;
}

/**
 * Desc.
 */
function content_access_checkboxes_to_list_submit($element) {
  $list = array();
  foreach (_content_access_roles_list() as $op => $op_roles) {
    foreach ($op_roles as $op_role => $permission) {
      if (isset($element[$op][$op_role]) && $element[$op][$op_role]) {
        $list[$op_role] = $permission;
      }
    }
  }
  return $list;
}

/**
 * Desc.
 */
function content_access_action_form_alter(&$form, &$form_state) {
  // Include content_access.admin.inc in order to use it's functions
  // e.g. content_access_disable_checkboxes() in
  // content_access_rules_role_based_form()
  #$include_file = drupal_get_path('module', 'content_access') . '/content_access.admin.inc';
  #$form_state['build_info']['files']['content_access'] = $include_file;
  #module_load_include('inc', 'content_access', 'content_access.admin');

  // Desc.
  $ca_element =& $form['parameter']['content_access']['settings']['content_access'];
  $ca_element = content_access_list_to_checkboxes($ca_element);

  // Add submit callback to process content_access_rules_role_based_form() vals
  // @todo I think this should go into Rules just like the default form
  // behaviour
  // rules_ui_edit_element_submit is the default submit callback so we add it
  // again
  $form['submit']['#submit'] = array('content_access_action_settings_form_submit', 'rules_ui_edit_element_submit');
}

/**
 * Desc.
 */
function content_access_action_settings_form_submit($form, &$form_state) {
  // Desc.
  $ca_element =& $form_state['input']['parameter']['content_access']['settings']['content_access'];
  $ca_element = content_access_checkboxes_to_list_submit($ca_element);

  $form_state['rules_element']->settings['content_access'] = $ca_element;
}

/**
 * Verifies that per content settings are activated for the given node.
 */
function _content_access_rules_check_setting($node) {
  // @todo node_get_types is D6 only
  if (!content_access_get_settings('per_node', $node->type)) {
    rules_log(t("Can't set per content permissions for content type @type. Make sure to have per content settings activated for content types you want to alter access control for.", array('@type' => node_get_types('name', $node->type))), TRUE);
    return FALSE;
  }
  return TRUE;
}

/**
 * Desc.
 */
function content_access_action_settings($param) {
  $roles_ids = array_flip(user_roles());

  foreach (_content_access_get_operations() as $op) {
    $settings[$op] = array();
  }
  foreach ($param as $op_role => $role) {
    $op = substr($op_role, 0, strpos($op_role, ':'));
    $role_id = $roles_ids[$role];
    $settings[$op][] = $role_id;
  }

  return $settings;
}

/**
 * Action implementation: Grant permissions for a node.
 */
function content_access_action_grant_node_permissions($params) {
  if (_content_access_rules_check_setting($params['node'])) {
    $settings = content_access_action_settings($params['content_access']);
    $ca_settings = array();

    foreach (_content_access_get_operations() as $op) {
      $settings += array($op => array());
      $ca_settings[$op] = array_keys(array_flip(content_access_per_node_setting($op, $params['node'])) + array_flip($settings[$op]));
    }
    content_access_save_per_node_settings($params['node'], $ca_settings);
    // A following node_save() updates the grants for us.
    return array('node' => $params['node']);
  }
}

/**
 * Action implementation: Revoke permissions for a node.
 */
function content_access_action_revoke_node_permissions($params) {
  if (_content_access_rules_check_setting($params['node'])) {
    $settings = content_access_action_settings($params['content_access']);
    $ca_settings = array();

    foreach (_content_access_get_operations() as $op) {
      $settings += array($op => array());
      $ca_settings[$op] = array_diff(content_access_per_node_setting($op, $params['node']), $settings[$op]);
    }

    content_access_save_per_node_settings($params['node'], $ca_settings);
    // A following node_save() updates the grants for us.
    return array('node' => $params['node']);
  }
}

/**
 * Action implementation: Reset permissions for a node.
 */
function content_access_action_reset_node_permissions($params) {
  if (_content_access_rules_check_setting($params['node'])) {
    content_access_delete_per_node_settings($params['node']);
    // A following node_save() updates the grants for us.
    return array('node' => $params['node']);
  }
}