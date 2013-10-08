<?php

// Cannot use require_once(... drupal_get_path('views_bulk_operations')) on an earlier version of Mica because the module is not yet registered
if (drupal_get_path('module', 'views_bulk_operations') !== '') {
  require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'views_bulk_operations') . '/views/views_bulk_operations_handler_field_operations.inc');
}
else if (file_exists(DRUPAL_ROOT . '/profiles/mica_distribution/modules/views_bulk_operations/views/views_bulk_operations_handler_field_operations.inc')){
  require_once(DRUPAL_ROOT . '/profiles/mica_distribution/modules/views_bulk_operations/views/views_bulk_operations_handler_field_operations.inc');
}
else{
  require_once(DRUPAL_ROOT . '/sites/all/modules/views_bulk_operations/views/views_bulk_operations_handler_field_operations.inc');
}

/**
   * Views bulk operations integration
   */

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
  return $values->_entity_properties['search_api_id'];
  }
}
