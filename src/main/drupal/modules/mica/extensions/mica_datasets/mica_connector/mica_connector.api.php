<?php

/**
 * @file
 * Hooks provided by the Mica Connector module.
 */

/**
 * Defines one or more dataset connection classes a module offers.
 *
 * Note: The ids should be valid PHP identifiers.
 *
 * @return array
 *   An associative array of dataset connection classes, keyed by a unique
 *   identifier and containing associative arrays with the following keys:
 *   - name: The connection class' translated name.
 *   - description: A translated string to be shown to administrators when
 *     selecting a connection class.
 *   - class: The service class, which has to implement the
 *     MicaDatasetConnectionInterface interface.
 */
function hook_mica_connector_connection_info() {
  $connections = array();
  $connections['example_some'] = array(
    'name' => t('Some Connection'),
    'description' => t('Connection for some data repository.'),
    'class' => 'SomeConnectionClass',
    // Unknown keys can later be read by the object for additional information.
    'init args' => array('foo' => 'Foo', 'bar' => 42),
  );
  $connections['example_other'] = array(
    'name' => t('Other Connection'),
    'description' => t('Connection for another data repository.'),
    'class' => 'OtherConnectionClass',
  );

  return $connections;
}