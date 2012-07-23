<?php
/**
 * @file
 * MicaRelation entity
 */

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
    return parent::save();
  }

  /**
   * create and add node reference field for parent type
   */
  public function add_node_reference_to_parent($child_name) {

    $node_ref_field_name = $this->options['node_reference'];

    field_create_field(array(
      'field_name' => $node_ref_field_name,
      'type' => 'node_reference',
      'cardinality' => 1,
      'field_permissions' => array(
        'type' => '0',
      ),
      'settings' => array(
        'referenceable_types' => array(
          $this->child_bundle => $this->child_bundle,
        ),
      ),
    ));

    field_create_instance(array(
      'field_name' => $node_ref_field_name,
      'label' => $child_name,
      'entity_type' => 'node',
      'bundle' => $this->parent_bundle,
      'widget' => array(
        'type' => 'options_select',
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'node_reference_field_name_link',
        ),
      ),
    ));

  }

  /**
   * Create a node child. Returns true if the node was created and linked to its parent
   */
  public function create_child_node($parent_node, array $parent_menu) {

    if (!$this->options['cascaded']) {
      return FALSE;
    }

    $field_ref = $this->options['node_reference'];

    if (property_exists($parent_node, $field_ref)) {
      $field = $parent_node->$field_ref;
    }

    // do not create child if child id is already provided (case of data import)
    if (empty($field) || empty($field[LANGUAGE_NONE])) {

      // create new child
      $node_child = new stdClass();
      $node_child->type = $this->child_bundle;
      node_object_prepare($node_child);
      $node_child->title = $parent_node->title;
      $node_child->language = $parent_node->language;
      $node_child->uid = $parent_node->uid; // same author
      $node_child->status = $parent_node->status; // same publication status

      watchdog('mica', 'Create child %child for parent %parent : %title',
        array(
          '%child' => $this->child_bundle,
          '%parent' => $parent_node->type,
          '%title' => $parent_node->title,
        ), WATCHDOG_INFO);

      node_save($node_child);

      // create menu if parent has menu
      if (!empty($parent_menu) && $parent_menu['mlid'] != 0 && array_key_exists('enabled', $parent_menu) && $parent_menu['enabled']) {
        $field_ref_info = field_info_instance('node', $field_ref, $this->parent_bundle);
        $child_menu_item = array(
          'menu_name' => 'main-menu',
          'link_title' => t('@label', array('@label' => $field_ref_info['label'])),
          'link_path' => 'node/' . $node_child->nid,
          'plid' => $parent_menu['mlid'],
        );
        menu_link_save($child_menu_item);
        menu_cache_clear('main-menu');
      }

      // link this new child node to the parent node
      $parent_node->$field_ref = array(
        LANGUAGE_NONE => array(
          0 => array(
            'nid' => $node_child->nid,
          ),
        ),
      );

      return TRUE;
    }
    return FALSE;
  }

  /**
   * Update child node on parent update
   */
  public function update_child_node($parent_node) {

    if (!$this->options['cascaded']) {
      return;
    }

    $parent_menu = menu_link_get_preferred('node/' . $parent_node->nid);
    if (!empty($parent_menu) && $parent_menu['menu_name'] != 'main-menu') {
      unset($parent_menu);
    }

    $field_ref = $this->options['node_reference'];
    $field = $parent_node->$field_ref;

    $child_nid = $field[LANGUAGE_NONE][0]['nid'];
    $node_child = node_load($child_nid);

    // drop previous child menu in main-menu if exists
    $clear_menu_cache = FALSE;
    $child_menu = menu_link_get_preferred('node/' . $child_nid);
    if (!empty($child_menu) && $child_menu['menu_name'] === 'main-menu') {
      menu_link_delete($child_menu['mlid']);
      $clear_menu_cache = TRUE;
    }

    // create child menu if needed
    if (!empty($parent_menu) && $parent_menu['mlid'] != 0 && array_key_exists('enabled', $parent_menu) && $parent_menu['enabled']) {
      $field_ref_info = field_info_instance('node', $field_ref, $this->parent_bundle);
      $child_menu_item = array(
        'menu_name' => 'main-menu',
        'link_title' => t('@label', array('@label' => $field_ref_info['label'])),
        'link_path' => 'node/' . $child_nid,
        'plid' => $parent_menu['mlid'],
      );
      menu_link_save($child_menu_item);
      $clear_menu_cache = TRUE;
    }

    if ($clear_menu_cache) {
      menu_cache_clear('main-menu');
    }

    $node_child->uid = $parent_node->uid; // same author
    $node_child->title = $parent_node->title;
    node_save($node_child);
  }

  public function delete_child_node($parent_node) {
    if (!$this->options['cascaded']) {
      return;
    }
    $field_ref = $this->options['node_reference'];
    $field = $parent_node->$field_ref;
    $child_nid = $field[LANGUAGE_NONE][0]['nid'];
    node_delete($child_nid);

    watchdog('mica', 'Delete child %child for deleted parent %parent', array(
      '%child' => $this->child_bundle,
      '%parent' => $parent_node->type,
    ), WATCHDOG_INFO);
  }

}
