<?php

/**
 * @file
 * Hooks provided by the Mica Datasets module.
 */

/**
 * Alter the Mica Dataset connection info.
 *
 * Modules may implement this hook to alter the information that defines
 * Mica Dataset connections. All properties that are available in
 * hook_mica_datasets_connection_info() can be altered here.
 *
 * @see hook_mica_datasets_connection_info()
 *
 * @param array $connection_info
 *   The Mica Dataset connection info array, keyed by connection id.
 */
function hook_mica_datasets_connection_info(array &$connection_info) {
  foreach ($connection_info as $id => $info) {
    $connection_info[$id]['class'] = 'MyProxyConnectionClass';
    $connection_info[$id]['example_original_class'] = $info['class'];
  }
}