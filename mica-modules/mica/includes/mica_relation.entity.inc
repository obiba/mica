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
   * Create drupal relation
   * @see Entity::save()
   */
  public function save() {
  	$indexes = entity_load('search_api_index', array_keys($this->options['child_indexes']));
	  foreach ($indexes as $index) {
	    $index->options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'][$this->child_bundle] = $this->child_bundle;
	    entity_save('search_api_index', $index);
	  }
	  
	  // we don't want to keep index info in mica_relation table  
	  unset($this->options['parent_indexes']);
	  unset($this->options['child_indexes']);
	  
	  //$this->save_drupal_relation();
	  
    return parent::save();
  }  
  
	private function save_drupal_relation() {
    $drupal_relation = array(
    	'predicate' => $this->options['relation'],
    	'label' => $this->label,
    	'directional' => TRUE,
    	'transitive' => TRUE,
    	'min_arity' => 2,
  		'max_arity' => 2,
    	'source_bundles' => array(
    		'node:' . $this->parent_bundle => 'node:' . $this->parent_bundle, 
    	),
    	'target_bundles' => array(
    		'node:' . $this->child_bundle => 'node:' . $this->child_bundle, 
    	),
    );
    
    $existing = relation_type_load($this->options['relation']);
    
   	// TODO: remove this patch that deletes a field instance before saving relation once it's fixed: 
   	// http://drupal.org/node/1152024   	    
    if (!empty($existing)) {
		  $instance = array(
		    'field_name' => 'endpoints',
		    'entity_type' => 'relation',
		    'bundle' => $drupal_relation['predicate'],
		  );    	
		  field_delete_instance($instance, FALSE);
    }
    
  	relation_type_save($drupal_relation, empty($existing) ? array() : 'predicate');
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
	    'settings' => array(
	      'referenceable_types' => array(
	        $this->child_bundle => $this->child_bundle,
	      ),
	      'field_permissions' => array(
	        'create' => 'create',
	        'view' => 'view',
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
          'type' => 'node_reference_type_link',      
        ),
      ),	 		
	  ));
	  
	  // give 'view' field permission to everyone
	  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('view ' . $node_ref_field_name));
	  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('view ' . $node_ref_field_name));  
	
	  // give 'create' field permission to studies administrator and study administrator
	  $admin_role = user_role_load_by_name('administrator');
	  $studies_admin_role = user_role_load_by_name('studies administrator');
	  $study_admin_role = user_role_load_by_name('study administrator');
	  user_role_grant_permissions($admin_role->rid, array('create ' . $node_ref_field_name));
	  user_role_grant_permissions($studies_admin_role->rid, array('create ' . $node_ref_field_name));
	  user_role_grant_permissions($study_admin_role->rid, array('create ' . $node_ref_field_name));
	}  
	
 
	public function add_relation_fields() {
		$this->add_relation_field($this->options['relation_parent_field'], $this->parent_bundle, $this->child_bundle);
		$this->add_relation_field($this->options['relation_child_field'], $this->child_bundle, $this->parent_bundle);
	}  		
	
	private function add_relation_field($source, $source_bundle, $target_bundle) {
 		field_create_field(array(
	    'field_name' => $source,
	    'type' => 'relation',
	    'cardinality' => 1,
	    'settings' => array(
	      'referenceable_types' => array(
	        $target_bundle => $target_bundle,
	      ),
	      'field_permissions' => array(
	        'create' => 'create',
	        'view' => 'view',
	      ),
	    ),      
	  ));
	
	  $target_bundle_info = node_type_load($target_bundle);
	  field_create_instance(array(
	    'field_name' => $source,
	    'label' => $target_bundle_info->name,
	    'entity_type' => 'node',
	    'bundle' => $source_bundle,
	    'widget' => array('type' => 'relation_default'),
	  ));
	  
	  // give 'view' field permission to everyone
	  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('view ' . $source));
	  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('view ' . $source));  
	
	  // give 'create' field permission to studies administrator and study administrator
	  $admin_role = user_role_load_by_name('administrator');
	  $studies_admin_role = user_role_load_by_name('studies administrator');
	  $study_admin_role = user_role_load_by_name('study administrator');
	  user_role_grant_permissions($admin_role->rid, array('create ' . $source));
	  user_role_grant_permissions($studies_admin_role->rid, array('create ' . $source));
	  user_role_grant_permissions($study_admin_role->rid, array('create ' . $source));		
	}
	
	/**
	 * Create a node child. Returns true if the node was created and linked to its parent
	 */
	public function create_child_node($parent_node, array $parent_menu) {
		
  	if (!$this->options['cascaded']) return FALSE;
      
		$field_ref = $this->options['node_reference'];
    $field = $parent_node->$field_ref;
    $language = $parent_node->language;
      
		// do not create child if child id is already provided (case of data import)
    if (empty($field) || empty($field[$language])) {
      	
    	// create new child
      $node_child = new stdClass();
      $node_child->type = $this->child_bundle;
      node_object_prepare($node_child);
      $node_child->title = $parent_node->title;
      $node_child->language = $parent_node->language;
      $node_child->uid = $parent_node->uid; // same author
      $node_child->status = $parent_node->status; // same publication status
        
      // create menu if parent has menu
      if (!empty($parent_menu)) {
      	$node_child->menu['enabled'] = 1;
        $node_child->menu['menu_name'] = 'main-menu';
        $node_child->menu['link_title'] = $parent_node->title;
        $node_child->menu['description'] = '';
        $node_child->menu['plid'] = $parent_menu['mlid'];
      }         

      watchdog('mica', 'Create child %child for parent %parent', 
      	array(
        	'%child' => $this->child_bundle, 
          '%parent' => $parent_node->type,
        ), WATCHDOG_INFO);          
        
      node_save($node_child);

      // link this new child node to the parent node
      $parent_node->$field_ref = array(
      	$language => array(
        	0 => array(
          	'nid' => $node_child->nid,
          ),
        ),
      );
      
      // relation
      /*
      $endpoints = array(
      	array(
  				'entity_type' => 'node',
		      'entity_id' => $parent_node->nid,
		      'entity_bundle' => $parent_node->type,
       	),
       	array(
  				'entity_type' => 'node',
		      'entity_id' => $node_child->nid,
		     	'entity_bundle' => $node_child->type,
       	),
			);        
      // create drupal relation
			relation_create($this->options['relation'], $endpoints);        
      */  
      
      return TRUE;
    }
  	return FALSE;  		
	}
	
	/**
	 * Update child node on parent update 
	 */
	public function update_child_node($parent_node, array $parent_menu) {
  
		if (!$this->options['cascaded']) return;
		
		$language = $parent_node->language;
      
    $field_ref = $this->options['node_reference'];
    $field = $parent_node->$field_ref;
    $child_nid = $field[$language][0]['nid'];
    $node_child = node_load($child_nid);
      
    if (empty($parent_menu)) {
    	$node_child->menu['enabled'] = FALSE;
    } 
    else {
      $node_child->menu['enabled'] = TRUE;
      $node_child->menu['menu_name'] = 'main-menu';
      $node_child->menu['link_title'] = $parent_node->title;
      $node_child->menu['description'] = '';
      $node_child->menu['plid'] = $parent_menu['mlid'];
    }

    $node_child->uid = $parent_node->uid;  // same author
    $node_child->status = $parent_node->status;  // same publication status
    $node_child->title = $parent_node->title;
    $node_child->language = $parent_node->language;            
    node_save($node_child);		
	}
	
	public function delete_child_node($parent_node) {
		if (!$this->options['cascaded']) return;
    $language = $parent_node->language;
		$field_ref = $this->options['node_reference'];
    $field = $parent_node->$field_ref;
    $child_nid = $field[$language][0]['nid'];
    node_delete($child_nid);
    
    watchdog('mica', 'Delete child %child for deleted parent %parent', 
      array(
        '%child' => $this->child_bundle, 
        '%parent' => $parent_node->type,
      ), WATCHDOG_INFO);      		
	}

}
