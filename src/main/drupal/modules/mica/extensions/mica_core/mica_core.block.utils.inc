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

  foreach (array('mica_subtheme', 'seven', 'bartik') as $theme) {
    db_delete('block')
      ->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
    db_insert('block')
      ->fields(array('pages', 'visibility', 'module', 'delta', 'theme', 'region'))
      ->values(array(
          'pages' => "<?php if(arg(0) == 'node' && is_numeric(arg(1)) && ((arg(2) == ''|| arg(2) == 'view'))) return TRUE; ?>",
          'visibility' => 2,
          'module' => $module,
          'delta' => $delta,
          'theme' => $theme,
          'region' => '',
        )
      )->execute();
  }

}