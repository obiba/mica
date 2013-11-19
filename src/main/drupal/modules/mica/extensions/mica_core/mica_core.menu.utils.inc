<?php

/**
 * @file
 * Menu utilities
 */

define('MAIN_MENU', 'main-menu');

function mica_core_create_menu($menu_title, $menu_path, $router_path, $hidden = FALSE, $expanded = FALSE, $weight = 0, $parent_path = '', $parent_mlid = '') {
  $menu = array();
  _mica_core_create_menu($menu, $menu_title, $menu_path, $router_path, $hidden, $expanded, $weight, $parent_path, $parent_mlid);
  return $menu;
}

function mica_core_create_node_menu($node, $hidden = FALSE, $expanded = FALSE, $weight = 0, $parent_path = '', $parent_mlid = '') {
  $menu = isset($node->menu) ? $node->menu : array();

  $wrapper = entity_metadata_wrapper('node', $node);
  _mica_core_create_menu($menu, $wrapper->title->value(), 'node/' . $node->nid, 'node/%', $hidden, $expanded, $weight, $parent_path, $parent_mlid);
  return $menu;
}

function _mica_core_create_menu(&$menu, $menu_title, $menu_path, $router_path, $hidden = FALSE, $expanded = FALSE,
  $weight = 0, $parent_path = '', $parent_mlid = '') {

  $menu_exist = db_query(
    "SELECT * FROM {menu_links} WHERE link_path= :link_path AND  link_title = :link_title",
    array(':link_path' => $menu_path, ':link_title' => $menu_title)
  )->fetchObject();

  if (isset($menu_exist) && $menu_exist !== FALSE) {
    $menu['mlid'] = $menu_exist->mlid;
    $menu['exist'] = 1;
    return $menu;
  }
  else {
    $menu['enabled'] = 1;
    $menu['expanded'] = $expanded ? 1 : 0;
    $menu['hidden'] = $hidden ? 1 : 0;
    $menu['menu_name'] = MAIN_MENU;
    $menu['link_title'] = $menu_title;
    $menu['link_path'] = $menu_path;
    $menu['weight'] = $weight;

    if (!empty($router_path)) {
      $menu['router_path'] = $router_path;
    }

    if ($menu['link_path'] === '<firstchild>') {
      $menu['options']['alter'] = TRUE;
      $menu['options']['unaltered_hidden'] = $menu['hidden'];
    }
    else {
      unset($menu['options']['unaltered_hidden']);
    }

    if (!empty($parent_mlid)) {
      $menu['plid'] = $parent_mlid;
    }
    else if (!empty($parent_path)) {
      $parent_menu = db_query(
        "SELECT * FROM {menu_links} WHERE link_path = :link_path",
        array(':link_path' => $parent_path)
      )->fetchObject();
      if (!empty($parent_menu)) {
        $menu['plid'] = $parent_menu->mlid;
      }
    }
    menu_link_save($menu);
    menu_cache_clear($menu['menu_name']);
  }
}

/**
 * Get node object from url alias
 * @param $alias
 * @return node if find
 */
function _mica_core_get_node_by_url_alias($alias) {
  $path = drupal_lookup_path("source", $alias);
  $node = menu_get_object("node", 1, $path);
  if (!$node) {
    return FALSE;
  }
  return $node;
}

/**
 * Creates a menu for the item being created if the content type as a default menu set.
 * The menu entry is hidden; this is useful to populate the breadcrumbs without having to manually add a menu entry.
 * @param $node
 * @param $hidden TRUE to hide this menu, FALSE to show it
 * @param $expanded TRUE to expand this menu, FALSE to collapse it
 * @param $weight
 * @param $default_menu_name used if no menu was configured for this node type
 * @param $default_parent_path used if no menu was configured for this node type
 */
function mica_core_create_node_default_menu($node, $hidden = FALSE, $expanded = FALSE, $weight = 0, $default_parent_path = '', $parent_mlid = '') {

  if (empty($node)) {
    return NULL;
  }

  // create menu based on content type menu config
  $menu = isset($node->menu) ? $node->menu : array();

  if (empty($menu['enabled']) || !$menu['enabled']) {

    $menu_options = variable_get('menu_options_' . $node->type);
    $wrapper = entity_metadata_wrapper('node', $node->nid);

    if (empty($menu_options)) {
      if (!empty($default_menu_name)) {
        _mica_core_create_menu($menu, $wrapper->title->value(), 'node/' . $node->nid, '', $hidden, $expanded, $weight, $default_parent_path, $parent_mlid);
      }
    }
    else {

      $menu_parent = variable_get('menu_parent_' . $node->type);
      if (!empty($menu_parent)) {
        $split = explode(":", $menu_parent);
        if (!empty($split[1])) {
          $mlid = $split[1];
          // check that this parent menu exists
          $existing_menu = db_query(
            "SELECT * FROM {menu_links} WHERE mlid = :mlid",
            array(':mlid' => $mlid)
          )->fetchObject();
          if (!empty($existing_menu) && $existing_menu->mlid == $mlid) {
            $menu['plid'] = $mlid;
          }
        }
      }

      _mica_core_create_menu($menu, $wrapper->title->value(), 'node/' . $node->nid, '', $hidden, $expanded, $weight, NULL, NULL);
    }

  }
  return $menu;
}

function mica_core_find_menu_weight($menu_path) {
  $menu = db_query(
    "SELECT * FROM {menu_links} WHERE link_path = :link_path AND menu_name = :menu_name",
    array(
      ':link_path' => $menu_path,
      ':menu_name' => MAIN_MENU
    )
  )->fetchObject();
  return empty($menu) ? $menu->weight : NULL;
}

function mica_core_find_menu_for_alias($url_alias) {
  $path = path_load(array('alias' => $url_alias));
  if (empty($path)) {
    return NULL;
  }
  $menu = db_query(
    "SELECT * FROM {menu_links} WHERE link_path = :link_path AND menu_name = :menu_name",
    array(
      ':link_path' => $path['source'],
      ':menu_name' => MAIN_MENU
    )
  )->fetchObject();
  return $menu;
}

function mica_core_set_menu_option($type, $menu_mlid) {
  variable_set('menu_parent_' . $type, MAIN_MENU . ':' . $menu_mlid);
}

function mica_core_disable_menu($menu_path) {
  $menu = db_query(
    "SELECT * FROM {menu_links} WHERE link_path = :link_path AND menu_name = :menu_name",
    array(
      ':link_path' => $menu_path,
      ':menu_name' => MAIN_MENU
    )
  )->fetchObject();
  if (!empty($menu)) {
    db_update('menu_links') // Table name no longer needs {}
      ->fields(array(
        'hidden' => 1,
      ))
      ->condition('link_path', $menu_path, '=')
      ->condition('menu_name', MAIN_MENU, '=')
      ->execute();
    menu_cache_clear(MAIN_MENU);
  }
}