<?php

include_once('mica_datasets.views_bulk_operations.inc');

/**
 * Implements hook_views_data_alter().
 */
function mica_datasets_views_data_alter(&$data) {
  if (isset($data['search_api_index'])) {
    foreach (search_api_index_load_multiple(FALSE) as $index) {
      $data['search_api_index_' . $index->machine_name]['views_bulk_operations'] = array(
        'title' => t('Bulk operations'),
        'help' => t('Provide a checkbox to select the row for bulk operations.'),
        'real field' => 'id',
        'field' => array(
          'handler' => 'mica_datasets_handler_field_operations',
          'item_type' => $index->item_type,
          'click sortable' => FALSE,
        ),
      );
    }
  }
}