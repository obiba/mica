<?php

/**
 * Views bulk operations integration
 */

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

class mica_datasets_handler_field_operations extends views_bulk_operations_handler_field_operations {

  /**
  * Override their get entity type since the base table name won't match at all.
  */
  function get_entity_type() {
    return $this->definition['item_type'];
  }

  /**
  * Overridden to try to fish out the id.
  */
  public function get_value($values, $field = NULL) {
  // I'm not sure this is the best source for this but the name seemed consistent.
    return $values->_entity_properties['search_api_item_id'];
  }
}