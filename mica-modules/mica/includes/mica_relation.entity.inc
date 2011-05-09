<?php

/**
 * Class representing a relation.
 */
class MicaRelation extends Entity {

  /* Database values that will be set when object is loaded: */

  /**
   * @var integer
   */
  public $id = 0;

  /**
   * @var string
   */
  public $parent_bundle = '';

  /**
   * @var string
   */
  public $child_bundle = '';

  /**
   * @var string
   */
  public $label = '';

  /**
   * @var integer
   */
  public $enabled = 1;

  /**
   * @var array
   */
  public $options = array();

  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_relation');
    // Always set default options.
    // Since at this point, $this->options might still be a serialized string, this has to be done a bit hack-ish.
    if (!is_array($this->options)) {
      if ($this->options) {
        $this->options = unserialize($this->options);
        $was_serialized = TRUE;
      }
      else {
        $this->options = array();
      }
    }
    $this->options += array(
      'indexed' => TRUE,
      'cascaded' => TRUE,
      'node_reference' => '',
      'relation' => '',
      'relation_parent_field' => '',
      'relation_child_field' => '',
    );
    if (isset($was_serialized)) {
      $this->options = serialize($this->options);
    }
  }

  /**
   * Add children to search index
   * @see Entity::save()
   */
  public function save() {
  	$indexes = entity_load('search_api_index', array_keys($this->options['child_indexes']));
	  foreach ($indexes as $index) {
	    $index->options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'][$this->child_bundle] = $this->child_bundle;
	    entity_save('search_api_index', $index);
	  }
	  // we don't want to keep index info in MicaRelation   
	  unset($this->options['parent_indexes']);
	  unset($this->options['child_indexes']);
    return parent::save();
  }  

}
