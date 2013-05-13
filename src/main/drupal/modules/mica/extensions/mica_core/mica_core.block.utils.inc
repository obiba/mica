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
