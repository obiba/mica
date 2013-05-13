<?php

/**
 * @file
 * Block utilities
 */

function mica_core_set_block_node_type($type, $module, $delta) {
  db_delete('block_node_type')
    ->condition('module', $module)
    ->condition('delta', $delta)
    ->execute();
  db_insert('block_node_type')
    ->fields(array('type', 'module', 'delta'))
    ->values(array(
      'type' => $type,
      'module' => $module,
      'delta' => $delta
    )
  )->execute();
}

function mica_core_disable_block_display($module, $delta) {
  $modif = "<?php
    if(arg(0) == 'node' && is_numeric(arg(1)) && ((arg(2) == ''|| arg(2) == 'view'))) {
      return TRUE;
    }
?>";
  $weight = NULL;
  $region = 'content';
  if ($delta == 'study-general-info') {
    $weight = 10;
  }
  else if ($delta == 'study-general-design') {
    $weight = 20;
  }
  else if ($delta == 'study-access') {
    $weight = 30;
  }
  else if ($delta == 'study-marker-paper') {
    $weight = 40;
  }
  else if ($delta == 'study-documents') {
    $weight = 50;
  }
  else if ($delta == 'study-supp-infos') {
    $weight = 60;
  }
  else if ($delta == 'study-timeline') {
    $weight = 70;
  }
  else if ($delta == 'study-populations') {
    $weight = 80;
  }
  else if ($delta == 'study-datasets') {
    $weight = 90;
  }
  else if ($delta == 'study-authorization') {
    $weight = 100;
  }
  else if ($delta == 'study-menu') {
    $weight = 10;
    $region = 'sidebar_second';
  }

  $themes = array();
  $themes[0] = 'mica_subtheme';
  $themes[1] = 'seven';
  foreach ($themes as $theme) {
    db_delete('block')
      ->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
    db_insert('block')
      ->fields(array('pages', 'visibility', 'module', 'delta', 'theme', 'status', 'region', 'weight'))
      ->values(array(
        'pages' => $modif,
        'visibility' => 2,
        'module' => $module,
        'delta' => $delta,
        'theme' => $theme,
        'status' => 1,
        'region' => $region,
        'weight' => $weight
      )
    )->execute();
  }

}