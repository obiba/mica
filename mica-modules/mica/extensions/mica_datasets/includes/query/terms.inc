<?php

interface QueryTermInterface {

  /**
   * Returns the implementation's class name.
   */
  function getType();

  /**
   * Generate a human-readable representation of this term
   */
  function toString();

  /**
   * The unique name of this term in the query
   */
  function getName();

  /**
   * Returns true when this term's condition should be inverted (not operator)
   */
  function isInverted();

  /**
   * Returns a form for editing this term
   */
  function form($form, &$form_state);

  /**
   * Handles form submit
   */
  function submit($form, &$form_state);

  function getOptions();

}

/**
 * Recognizes the following options structure:
 * {
 *   'name': 'termName',
 *   'not' : true/false
 * }
 * where
 *   name is the unique name of this term in the query
 *   not: true indicates that criteria should be inverted (not operator)
 */
abstract class AbstractTerm implements QueryTermInterface {

  private $type;

  private $name;

  private $not;

  protected $options = array();

  private $qt;

  function __construct($type, MicaDatasetQueryTerm $qt) {
    // Set initial values.
    foreach ($qt->options as $key => $value) {
      $this->$key = $value;
    }

    $this->type = $type;
    $this->qt = $qt;
    $this->options = &$qt->options;
  }

  static function typeFor($variable) {
    debug($variable->field_categories);
    $is_categorical=$variable->field_categories['und'][0]['value'];
    $type=$variable->field_value_type['und'][0]['value'];
    if($is_categorical) {
      return 'CategoryTerm';
    } else if ($type!= 'date') {
      return 'RangeTerm';
    }
    return 'TodoTerm';
  }

  function getType() {
    return $this->type;
  }

  function getName() {
    $variable = $this->getVariable();
    return $variable->title;
  }

  function isInverted() {
    return $this->not;
  }

  function getOptions() {
    return $this->options;
  }

  function toString() {
    $variable = $this->getVariable();
    return $variable->title;
  }

  protected function getVariable() {
    return node_load($this->qt->variable_id);
  }

}

/**
 * Recognizes the following options structure:
 * {
 *   categories: [ '1', '2', '3' ],
 *   operator : 'OR'
 * }
 * where
 *   categories is a list of categories names (can be empty or null)
 *   operator is either 'AND' or 'OR' (can be empty or null)
 */
class CategoryTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('CategoryTerm', $qt);
  }

  function categories() {
    return isset($this->options['categories']) ? $this->options['categories'] : array();
  }

  function setCategories($categories = array()) {
    $this->options['categories'] = $categories;
  }

  function operator() {
    return isset($this->options['operator']) ? $this->options['operator'] : 'OR';
  }

  function form($form, &$form_state) {

    $form['inverted']=array(
      '#title' => t('Operator'), 
      '#type' => 'select',
      '#options' => array('in' => 'in', 'notin' => 'not in'),
      '#default_value' => $this->isInverted() ? 'notin' : 'in',
    );

    $options = array();
    $variable = $this->getVariable();
    foreach($variable->field_categories['und'] as $category) {
      // TODO: wtf! if the category's label is 0, it does not appear. So we add a &nbsp; so that it is no longer 0.
      $options['c_'.$category["value"]] = $category["value"] . "&nbsp;";
    }

    $form['categories'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Categories'),
      '#options' => $options,
      '#default_value' => $this->categoriesToForm(),
    );
    return $form;
  }

  function submit($form, &$form_state) {
    $selection = $form_state['values']['categories'];
    $inverted = $form_state['values']['inverted'];

    //$this->not=$inverted;
    $this->setCategories($this->formToCategories($selection));
  }

  function toString() {
    $str = parent::toString();
    if(count($this->categories()) > 0) {
      switch ($this->operator()) {
        case 'AND':
          $str.= ' is ';
          ;
          break;
        default:
          $str.= ' in ';
          ;
          break;
      }
      $str .= '(' . implode(', ', $this->categories()) . ')';
    }
    return $str;
  }

  /**
   * Prefixes all selected categories with 'c_' so that we don't have 0 as an array key
   */
  private function categoriesToForm() {
    $map = function($category) {
      return 'c_' . $category;
    };
    return array_map($map, $this->categories());
  }

  /**
   * Undoes the categoriesToForm() function
   * @param unknown_type $formCategories
   */
  private function formToCategories($formCategories) {
    $map = function($form) {
      return substr($form, 2);
    };
    // array_filter will remove all non-selected categories
    // array_keys will return only the array keys
    // the map will remove any 'c_' prefix
    return array_map($map, array_keys(array_filter($formCategories)));
  }

}

class RangeTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('RangeTerm', $qt);
  }

  function form($form, &$form_state) {
    $variable=$this->getVariable();
    
    $is_categorical=$variable->field_categories['und'][0]['value'] !== '';
    $is_repeatable=$variable->field_repeatable['und'][0]['value'] === '1';
    $type=$variable->field_value_type['und'][0]['value'];

    $form['operator']=array(
    '#title' => t('Operator'), 
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => array('inf' => '<', 'sup' => '>', 'eq' => '=', 'dif' => '!=', 'range' => 'Range'),
    '#ajax' => array(
      		'callback' => 'replace_value_container',
            'wrapper' => 'valuecontainer',
            'method' => 'replace')
    );

    //append_range($form, NULL);

    $form['valuecontainer'] = array(
     '#type' => 'item',
     '#prefix' => '<div id="'."valuecontainer".'">',
     '#suffix' => '</div>',
    );

    $form['add_range'] = array(
      '#type' => 'button',
      '#value' => 'add range',
      '#ajax' => array(
      		'callback' => 'append_range',
            'wrapper' => 'valuecontainer',
            'method' => 'append')
    );
    return $form;
  }

  function submit($form, &$form_state) {

  }

  function toString() {
    $str = parent::toString();
    return $str . ' ToDo';
  }
}

class TodoTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('TodoTerm', $qt);
  }

  function form($form, &$form_state) {
    return $form;
  }

  function submit($form, &$form_state) {

  }

  function toString() {
    $str = parent::toString();
    return $str . ' ToDo';
  }
}