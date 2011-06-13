<?php

/**
 * Class representing a dataset connector.
 *
 * This can handle the same calls as defined in the MicaDatasetConnectionInterface
 * and pass it on to the connection implementation appropriate for this connector.
 */
class MicaDatasetQuery extends Entity {

  /* Database values that will be set when object is loaded: */

  /**
   * @var integer
   */
  public $id = 0;

  /**
   * @var string
   */
  public $name = '';
  
  /**
   * @var string
   */
  public $machine_name = '';

  /**
   * @var string
   */
  public $description = '';

  /**
   * @var integer
   */
  public $user_id = 0;
  
  /**
   * @var integer
   */
  public $dataset_id = 0;
  
  /**
   * @var array
   */
  public $options = array();

  /**
   * @var integer
   */
  public $published = 0;
  
  
  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_dataset_query');
  }

  /**
   * Helper method for updating entity properties.
   *
   * NOTE: You shouldn't change any properties of this object before calling
   * this method, as this might lead to the fields not being saved correctly.
   *
   * @param array $fields
   *   The new field values.
   *
   * @return
   *   SAVE_UPDATED on success, FALSE on failure, 0 if the fields already had
   *   the specified values.
   */
  public function update(array $fields) {
    $changeable = array('name' => 1, 'published' => 1, 'description' => 1, 'options' => 1);
    $changed = FALSE;
    foreach ($fields as $field => $value) {
      if (isset($changeable[$field]) && $value !== $this->$field) {
        $this->$field = $value;
        $changed = TRUE;
      }
    }
    // If there are no new values, just return 0.
    if (!$changed) {
      return 0;
    }
    return $this->save();
  }

  /**
   * Magic method for determining which fields should be serialized.
   *
   * Serialize all properties except the proxy object.
   *
   * @return array
   *   An array of properties to be serialized.
   */
  public function __sleep() {
    $ret = get_object_vars($this);
    unset($ret['status'], $ret['module'], $ret['is_new']);
    return array_keys($ret);
  }
  
}
