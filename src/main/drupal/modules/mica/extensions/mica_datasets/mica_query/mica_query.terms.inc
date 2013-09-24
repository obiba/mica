<?php

/**
 * @file
 * QueryTerm model
 */

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
   * The label of the field this term works on (i.e.: the variable label)
   */
  function getFieldLabel();

  /**
   * Returns true when this term's condition should be inverted (not operator)
   */
  function isInverted();

  /**
   * Returns an HTML block to display a query term
   */
  function view();

  /**
   * Returns a form for editing this term
   */
  function form($form, &$form_state);

  /**
   * Handles form validation
   */
  function validate($form, &$form_state);

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
    $this->options = & $qt->options;
  }

  static function typeFor($variable) {
    $wrapper = entity_metadata_wrapper('node', $variable);

    $is_categorical = FALSE;
    foreach ($wrapper->field_variable_categories->value() as $category) {
      if ($category['missing'] == FALSE) {
        $is_categorical = TRUE;
        break;
      }
    }

    $type = $wrapper->field_value_type->value();

    if ($is_categorical) {
      return 'CategoryTerm';
    }
    if ($type == 'integer' || $type == 'decimal') {
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

  function getFieldLabel() {
    $wrapper = entity_metadata_wrapper('node', $this->getVariable());
    return $wrapper->field_label->value();
  }

  function isInverted() {
    return $this->not;
  }

  function setInverted($inverted) {
    $this->not = $inverted;
    return $this->options['not'] = $inverted;
  }

  function isRepeatable() {
    $variable = $this->getVariable();
    return isset($variable->field_repeatable[LANGUAGE_NONE][0]['value'])
    && $variable->field_repeatable[LANGUAGE_NONE][0]['value'] === '1';
  }

  function getOptions() {
    return $this->options;
  }

  function toString() {
    return $this->getFieldName();
  }

  /**
   * array(
   *   study_id => connector->facetTerm(),
   *   study_id => connector->facetTerm(),
   *   ...
   * )
   */
  function stats() {
    // One column for the category name and one per study
    $facets = array();
    $connectors = $this->getConnectors();
    foreach ($connectors as $connector) {
      try {
        $facets[$connector->study_id] = $connector->facetTerm($this);
      } catch (Exception $e) {
        $connector->displayError($e);
      }
    }
    return $facets;
  }

  protected function getVariable() {
    return node_load($this->qt->variable_id);
  }

  protected function getConnectors() {
    $connectors = array();

    $dataset_id = NULL;
    if (!empty($this->qt->query_id)) {
      $query = mica_query_load($this->qt->query_id);
      $dataset_id = $query->dataset_id;
    }
    elseif (!empty($this->qt->dataset_id)) {
      $dataset_id = $this->qt->dataset_id;
    }

    if (isset($dataset_id)) {
      $connectors = mica_connector_query_multiple($dataset_id, TRUE);
    }

    return $connectors;
  }

  function hasConnectors() {
    return count($this->getConnectors()) > 0;
  }

  protected function getStudyName($study_id) {
    $study = node_load($study_id);
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $acronym = $study_wrapper->field_acroym->value();
    return !empty($acronym) ? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();
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

  function checkStats() {
    $stats = $this->stats();
    foreach ($stats as $study_id => $stat) {
      if (isset($stat['_all']) && $stat['_all'] != 0) {
        return TRUE;
      }
    }
    return FALSE;
  }

  function view() {
    $variable = $this->getVariable();

    $headers = array('Value');
    $stats = $this->stats();
    foreach ($stats as $study_id => $stat) {
      $headers[] = $this->getStudyName($study_id);
    }

    $rows = array();
    $wrapper = entity_metadata_wrapper('node', $variable);
    // Get total of non-missing categories
    $totals = array();
    foreach ($wrapper->field_variable_categories->value() as $category) {
      if (!$category["missing"]) {
        $category_name = $category["name"];
        foreach ($stats as $study_id => $stat) {
          $s = isset($stat[$category_name]) ? $stat[$category_name] : 0;
          $totals[$study_id] = isset($totals[$study_id]) ? $totals[$study_id] + $s : $s;
        }
      }
    }

    foreach ($wrapper->field_variable_categories->value() as $category) {
      $category_name = $category["name"];
      $missing = $category['missing'];
      $row = array($category_name);
      foreach ($stats as $study_id => $stat) {
        if (!$missing && isset($stat[$category_name]) && $totals[$study_id] > 0) {
          $percent = round(($stat[$category_name] / $totals[$study_id]) * 100, 1);
          $row[] = isset($stat[$category_name]) ? $stat[$category_name] . '<br>(' . $percent . '%)' : 0;
        }
        else {
          $row[] = isset($stat[$category_name]) ? $stat[$category_name] : 0;
        }
      }
      $rows[] = $row;
    }

    $row = array(
      array(
        'data' => t('All'),
        'class' => array('active')
      )
    );
    foreach ($stats as $study_id => $stat) {
      $row[] = array(
        'data' => isset($stat['_all']) ? $stat['_all'] : 0,
        'class' => array('active')
      );
    }
    $rows[] = $row;

    return theme('table', array('header' => $headers, 'rows' => $rows, 'empty' => t('No studies available')));
  }

  function form($form, &$form_state) {
    $form['inverted'] = array(
      '#title' => t('Operator'),
      '#type' => 'select',
      '#options' => array('in' => 'in', 'notin' => 'not in'),
      '#default_value' => $this->isInverted() ? 'notin' : 'in',
    );

    // One column for the category name and one per study
    $headers = array('Value');
    $connectors = $this->getConnectors();
    foreach ($connectors as $connector) {
      $study = node_load($connector->study_id);
      $headers[] = $study->title;
    }

    $defaultValues = array();
    $options = array();
    $variable = $this->getVariable();

    $facets = $this->stats();
    $wrapper = entity_metadata_wrapper('node', $variable);
    foreach ($wrapper->field_variable_categories->value() as $category) {
      $category_name = $category["name"];
      $defaultValues[$category_name] = 0;
      $row = array($category_name);
      foreach ($connectors as $connector) {
        if (isset($facets[$connector->study_id][$category_name])) {
          $row[] = $facets[$connector->study_id][$category_name];
        }
        else {
          $row[] = 0;
        }
      }
      $options['c_' . $category_name] = $row;
    }

    $form['valuecontainer']['fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => !empty($connectors) ? 'Values and Statistics' : 'Values',
    );

    $form['valuecontainer']['fieldset']['categories'] = array(
      '#type' => 'tableselect',
      '#header' => $headers,
      '#options' => $options,
      '#default_value' => $this->categoriesToForm($defaultValues),
    );
    return $form;
  }

  function validate($form, &$form_state) {

  }

  function submit($form, &$form_state) {
    $selection = $form_state['values']['categories'];
    $inverted = $form_state['values']['inverted'];

    $this->setInverted($inverted == 'notin');
    $this->setCategories($this->formToCategories($selection));
  }

  function toString() {
    $str = parent::toString();
    if (count($this->categories()) > 0) {
      switch ($this->operator()) {
        case 'AND':
          $str .= $this->isInverted() ? ' is not ' : ' is ';
          break;
        default:
          $str .= $this->isInverted() ? ' not in ' : ' in ';
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
    foreach ($this->categories() as $c) {
      $rows['c_' . $c] = 1;
    }
    return $rows;
  }

  /**
   * Undoes the categoriesToForm() function
   * @param array $formCategories
   */
  private function formToCategories(array $formCategories) {
    // array_filter will remove all non-selected categories
    // array_keys will return only the array keys
    $selected = array_keys(array_filter($formCategories));
    $categories = array();
    foreach ($selected as $c) {
      $categories[] = substr($c, 2);
    }
    return $categories;
  }

}

/**
 * {
 *   ranges : [ {from:10, to: 40}, {value:42} ]
 * }
 */
class RangeTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('RangeTerm', $qt);
  }

  public function ranges() {
    return isset($this->options['ranges']) ? $this->options['ranges'] : array();
  }

  function view() {
    $headers = array('Study', 'Min', 'Max', 'Mean', 'Std. Dev', 'Count');
    $rows = array();
    $stats = $this->stats();
    foreach ($stats as $study_id => $stat) {
      $rows[] = array(
        $this->getStudyName($study_id),
        $this->f($stat['min']),
        $this->f($stat['max']),
        $this->f($stat['mean']),
        $this->f($stat['std_deviation']),
        $stat['count']
      );
    }
    return theme('table', array('header' => $headers, 'rows' => $rows, 'empty' => t('No studies available')));
  }

  function f($number) {
    // TODO: figure out how to specify significant digits instead of # of decimals
    return is_double($number) ? number_format($number, 3) : $number;
  }

  function form($form, &$form_state) {
//    $variable = $this->getVariable();
//    $type = $variable->field_value_type[LANGUAGE_NONE][0]['value'];
//    $operator = isset($form_state['values']['operator']) ?
//      $form_state['values']['operator'] : NULL;

    $form['inverted'] = array(
      '#title' => t('Operator'),
      '#type' => 'select',
      '#options' => array('in' => 'in', 'notin' => 'not in'),
      '#default_value' => $this->isInverted() ? 'notin' : 'in',
    );

    $form['valuecontainer'] = array(
      '#type' => 'item',
      '#prefix' => '<div id="' . "valuecontainer" . '">',
      '#suffix' => '</div>',
    );

    $form['valuecontainer']['fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => 'Values',
    );

    //TODO incomplete
//    $default_exact = 'exact';
    $default_value = NULL;
    $default_range_min = NULL;
    $default_range_max = NULL;
    $ranges = $this->ranges();

    if (isset($ranges[0]['value'])) {
      $default_exact = 'exact';
      $default_value = $ranges[0]['value'];
    }
    elseif (isset($ranges[0]['from']) || isset($ranges[0]['to'])) {
      $default_exact = 'range';
      $default_range_min = isset($ranges[0]['from']) ? $ranges[0]['from'] : NULL;
      $default_range_max = isset($ranges[0]['to']) ? $ranges[0]['to'] : NULL;
    }
    else {
      $default_exact = 'exists';
    }

    $form['valuecontainer']['fieldset']['exact-radio'] = array(
      '#type' => 'radios',
      '#title' => 'Matches',
      '#default_value' => $default_exact,
      '#options' => array(
        'exists' => t('Any value'),
        'exact' => t('Exact Value'),
        'range' => t('Range')
      ),
    );

    $form['valuecontainer']['fieldset']['value'] = array(
      '#type' => 'textfield',
      '#title' => 'Value',
      '#default_value' => $default_value,
      '#states' => array(
        'visible' => array(
          ':input[name="exact-radio"]' => array('value' => 'exact'),
        ),
        'required' => array(
          ':input[name="exact-radio"]' => array('value' => 'exact'),
        ),
      ),
    );

    $sharedStates = array(
      'visible' => array(
        ':input[name="exact-radio"]' => array('value' => 'range'),
      ),
    );

    $form['valuecontainer']['fieldset']['min'] = array(
      '#type' => 'textfield',
      '#title' => 'Min',
      '#default_value' => $default_range_min,
      '#states' => $sharedStates,
    );

    $form['valuecontainer']['fieldset']['max'] = array(
      '#type' => 'textfield',
      '#title' => 'Max',
      '#default_value' => $default_range_max,
      '#states' => $sharedStates,
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

    $form['view']['fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => 'Statistics',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['view']['fieldset']['stats'] = array(
      '#markup' => $this->view()
    );

    return $form;
  }

  function validate($form, &$form_state) {
    if ($form_state['values']['exact-radio'] === 'range') {
      $min = $form_state['values']['min'];
      $max = $form_state['values']['max'];
      if (empty($min) && empty($max)) {
        form_set_error('exact-radio', t('At least one value (min or max) must be specified'));
      }
      elseif (empty($min) == FALSE && empty($max) == FALSE && $min >= $max) {
        form_set_error('exact-radio', t('Min must be lower than max'));
      }
      elseif (empty($min) == FALSE && is_numeric($min) == FALSE) {
        form_set_error('min', t('Value for min must be numeric'));
      }
      elseif (empty($max) == FALSE && is_numeric($max) == FALSE) {
        form_set_error('max', t('Value for max must be numeric'));
      }
    }
    elseif ($form_state['values']['exact-radio'] === 'exact') {
      $value = $form_state['values']['value'];
      if (empty($value) || is_numeric($value) == FALSE) {
        form_set_error('value', t('Exact value is required and must be specified as a number'));
      }
    }
  }

  function submit($form, &$form_state) {
    $inverted = $form_state['values']['inverted'];
    $selection = NULL;
    if ($form_state['values']['exact-radio'] === 'range') {
      $min = $form_state['values']['min'];
      $max = $form_state['values']['max'];
      $min = empty($min) ? NULL : $min;
      $max = empty($max) ? NULL : $max;
      $selection = $this->formToRanges(NULL, $min, $max);
    }
    elseif ($form_state['values']['exact-radio'] === 'exact') {
      $value = $form_state['values']['value'];
      $value = empty($value) ? NULL : $value;
      $selection = $this->formToRanges($value, NULL, NULL);
    }
    $this->setInverted($inverted === 'notin');
    $this->setRange($selection);
  }

  private function formToRanges($value, $min, $max) {
    $range = array();
    if (isset($value)) {
      $range['value'] = $value;
    }
    if (isset($min)) {
      $range['from'] = $min;
    }
    if (isset($max)) {
      $range['to'] = $max;
    }
    return array($range);
  }

  function setRange($ranges = array()) {
    $this->options['ranges'] = $ranges;
  }

  function toString() {
    $str = parent::toString();
    $str_range = ' ';
    $ranges = $this->ranges();
    if (isset($ranges['0'])) {
      $first_range = $ranges['0'];
      if (isset($first_range['from']) || isset($first_range['to'])) {
        $from = isset($first_range['from']) ? '[' . $first_range['from'] : '*'; // can't print infinity symbol: &#8734;
        $to = isset($first_range['to']) ? $first_range['to'] . '[' : '*';
        $str_range .= ": $from, $to";
      }
      elseif (isset($first_range['value'])) {
        $str_range .= '= ' . $first_range['value'];
      }
      else {
        return $str;
      }
    }
    return $str . ($this->isInverted() ? ' not' : '') . $str_range;
  }

  function checkStats() {
    $stats = $this->stats();
    foreach ($stats as $study_id => $stat) {
      if (isset($stat['count']) && $stat['count'] != 0) {
        return TRUE;
      }
    }
    return FALSE;
  }
}

class TodoTerm extends AbstractTerm {

  function __construct(MicaDatasetQueryTerm $qt) {
    parent::__construct('TodoTerm', $qt);
  }

  function view() {
//    $variable = $this->getVariable();

    $headers = array('Value');
    $stats = $this->stats();
    foreach ($stats as $study_id => $stat) {
      $headers[] = $this->getStudyName($study_id);
    }

    $row = array(
      array(
        'data' => t('All'),
        'class' => array('active')
      )
    );
    foreach ($stats as $study_id => $stat) {
      $row[] = array(
        'data' => isset($stat['_all']) ? $stat['_all'] : 0,
        'class' => array('active')
      );
    }
    $rows[] = $row;

    return theme('table', array('header' => $headers, 'rows' => $rows, 'empty' => t('No studies available')));
  }

  function form($form, &$form_state) {
    $form['inverted'] = array(
      '#title' => t('Operator'),
      '#type' => 'select',
      '#options' => array('in' => 'in', 'notin' => 'not in'),
      '#default_value' => $this->isInverted() ? 'notin' : 'in',
    );

    $form['valuecontainer']['fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => 'Values',
    );

    $default_value = implode(" ", $this->match());
    $form['valuecontainer']['fieldset']['value'] = array(
      '#type' => 'textfield',
      '#default_value' => $default_value,
    );

    return $form;
  }

  function validate($form, &$form_state) {

  }

  function submit($form, &$form_state) {
    $selection = trim($form_state['values']['value']);
    $inverted = $form_state['values']['inverted'];

    if (strcmp($selection, '') == 0) {
      $selection = array();
    }
    else {
      $selection = explode(" ", $selection);
      foreach ($selection as $key => $value) {
        $selection[$key] = drupal_strtolower($value);
      }
    }

    $this->setInverted($inverted == 'notin');
    $this->setMatch($selection);
  }

  function setMatch($value = array()) {
    $this->options['match'] = $value;
  }

  public function match() {
    return isset($this->options['match']) ? $this->options['match'] : array();
  }

  function toString() {
    $str = parent::toString();
    if (count($this->match()) > 0) {
      $str .= $this->isInverted() ? ' not in ' : ' in ';
      $str .= '(' . implode(', ', $this->match()) . ')';
    }
    return $str;
  }

  function checkStats() {
    return TRUE;
  }
}