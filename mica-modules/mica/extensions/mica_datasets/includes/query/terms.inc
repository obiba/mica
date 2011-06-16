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
   * The name of the field this term works on (i.e.: the variable name)
   */
  function getFieldName();

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
    return $this->qt->id;
  }

  function getFieldName() {
    return $this->getVariable()->title;
  }

  function isInverted() {
    return $this->not;
  }

  function setInverted($inverted) {
    $this->not = $inverted;
    return $this->options['not'] = $inverted;
  }

  function getOptions() {
    return $this->options;
  }

  function toString() {
    return $this->getFieldName();
  }

  protected function getVariable() {
    return node_load($this->qt->variable_id);
  }

  protected function getConnectors() {
    $query = mica_dataset_query_load($this->qt->query_id);
    return mica_dataset_connector_query_multiple($query->dataset_id, TRUE);
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

    // One column for the category name and one per study
    $headers = array('Name');
    $facets = array();
    $connectors = $this->getConnectors();
    foreach($connectors as $connector) {
      $study = node_load($connector->study_id);
      $headers[] = $study->title;
      $facets[$connector->id] = $connector->facetTerm($this);
    }

    $defaultValues = array();
    $options = array();
    $variable = $this->getVariable();
    foreach($variable->field_categories['und'] as $category) {
      $defaultValues[$category["value"]] = 0;
      $row = array($category["value"]);
      foreach($connectors as $connector) {
        if(isset($facets[$connector->id][$category["value"]])) {
          $row[] = $facets[$connector->id][$category["value"]];
        } else {
          $row[] = 0;
        }
      }
      $options[$category["value"]] = $row;
    }

    $form['categories'] = array(
      '#type' => 'tableselect',
      '#header' => $headers, 
      '#options' => $options,
      '#default_value' => $this->categoriesToForm($defaultValues),
    );
    return $form;
  }

  function submit($form, &$form_state) {
    $selection = $form_state['values']['categories'];
    $inverted = $form_state['values']['inverted'];

    $this->setInverted($inverted == 'notin');
    $this->setCategories($this->formToCategories($selection));
  }

  function toString() {
    $str = parent::toString();
    if(count($this->categories()) > 0) {
      switch ($this->operator()) {
        case 'AND':
          $str.= $this->isInverted() ? ' is not ' : ' is ';
          break;
        default:
          $str.= $this->isInverted() ? ' not in ' : ' in ';
          break;
      }
      $str .= '(' . implode(', ', $this->categories()) . ')';
    }
    return $str;
  }

  /**
   * Returns an array category => 0/1
   */
  private function categoriesToForm($rows) {
    foreach($this->categories() as $c) {
      $rows[$c] = 1;
    }
    return $rows;
  }

  /**
   * Undoes the categoriesToForm() function
   * @param unknown_type $formCategories
   */
  private function formToCategories($formCategories) {
    // array_filter will remove all non-selected categories
    // array_keys will return only the array keys
    return array_keys(array_filter($formCategories));
  }

}

class RangeTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('RangeTerm', $qt);
  }

  public function ranges() {
    return isset($this->options['ranges']) ? $this->options['ranges'] : array();
  }

  function form($form, &$form_state) {
    $variable=$this->getVariable();

    $is_categorical=$variable->field_categories['und'][0]['value'] !== '';
    $is_repeatable=$variable->field_repeatable['und'][0]['value'] === '1';
    $type=$variable->field_value_type['und'][0]['value'];

    $operator=isset($form_state['values']['operator']) ?
    $form_state['values']['operator'] :
    NULL;

    $form['inverted']=array(
      '#title' => t('Operator'), 
      '#type' => 'select',
      '#options' => array('in' => 'in', 'notin' => 'not in'),
      '#default_value' => $this->isInverted() ? 'notin' : 'in',
    );

    $form['valuecontainer'] = array(
     '#type' => 'item',
     '#prefix' => '<div id="'."valuecontainer".'">',
     '#suffix' => '</div>',
    );
    $form['valuecontainer']['fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => 'Value',
    );

    //TODO incomplete
    $default_exact=0;
    $default_value=NULL;
    $default_range_min=NULL;
    $default_range_max=NULL;
    $ranges=$this->ranges();
    if (isset($ranges) && isset($ranges[0])) {
      $value=$ranges[0]['value'];
      if ($value!=='') {
        $default_exact = 1;
        $default_value=$value;
      } else {
        $default_exact = 0;
        $default_range_min=$ranges[0]['from'];
        $default_range_max=$ranges[0]['to'];
      }
    }

    $form['valuecontainer']['fieldset']['exact'] = array(
      '#type' => 'checkbox',
      '#title' => 'Exact Value',
      '#default_value' => $default_exact,
    );

    $form['valuecontainer']['fieldset']['value'] = array(
      '#type' => 'textfield',
      '#title' => 'Value',
      '#default_value' => $default_value,
      '#required' => $default_exact===1,
      '#dependency' => array(
        'edit-exact' => array(1),
    ),
    );
     
    $form['valuecontainer']['fieldset']['min'] = array(
      '#type' => 'textfield',
      '#title' => 'Min',
      '#default_value' => $default_range_min,
      '#required' => $default_exact===0,
      '#dependency' => array(
        'edit-exact' => array(0),
    ),
    );
    $form['valuecontainer']['fieldset']['max'] = array(
      '#type' => 'textfield',
      '#title' => 'Max',
      '#default_value' => $default_range_max,
      '#required' => $default_exact===0,
      '#dependency' => array(
        'edit-exact' => array(0),
    ),
    );

    //Code for add range.
    /*$form['add_range'] = array(
    '#type' => 'button',
    '#value' => 'add range',
    '#ajax' => array(
    'callback' => 'append_range',
    'wrapper' => 'valuecontainer',
    'method' => 'append'),
    '#prefix' => '<span id="add_range">',
    '#suffix' => '</span>',
    );*/

    return $form;
  }

  function submit($form, &$form_state) {
    $inverted=$form_state['values']['inverted'];
    $selection=NULL;
    if($form_state['values']['exact'] === 0) {
      $min=$form_state['values']['min'];
      $max=$form_state['values']['max'];
      $selection=$this->formToRanges('', $min, $max);
    } else {
      $value=$form_state['values']['value'];
      $selection=$this->formToRanges($value, '', '');
    }
    $this->setInverted($inverted === 'notin');
    $this->setRange($selection);
  }

  private function formToRanges($value, $min, $max) {
    return array(array('from' => $min,
                       'to' => $max,
                       'value' => $value ));
  }

  private function rangesToForm() {
    return array(array('from' => $min,
                       'to' => $max,
                       'value' => $value ));
  }

  function setRange($ranges = array()) {
    $this->options['ranges'] = $ranges;
  }

  function toString() {
    $str = parent::toString();
    $str_range=' ';
    $ranges=$this->ranges();
    if (isset($ranges['0'])) {
      $first_range=$ranges['0'];
      if ($first_range['value'] === '') {
        $str_range.='with range: ['.$first_range['from'].', '.$first_range['to'] .'[';
      } else {
        $str_range.='= '.$first_range['value'];
      }
    }
    return $str . ($this->isInverted() ? ' not' :'') . $str_range;
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