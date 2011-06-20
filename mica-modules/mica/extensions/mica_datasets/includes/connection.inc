<?php

/**
 * Interface defining the methods search connections have to implement.
 *
 * Before a connection object is used, the corresponding connector's data will be read
 * from the database (see MicaDatasetAbstractConnection for a list of fields).
 */
interface MicaDatasetConnectionInterface {

  /**
   * Constructor for a connection class, setting the connector configuration used with
   * this connection.
   *
   * @param MicaDatasetConnector $connector
   *   The connector object for this connection.
   */
  public function __construct(MicaDatasetConnector $connector);

  /**
   * Form callback. Might be called on an uninitialized object - in this case,
   * the form is for configuring a newly created connector.
   *
   * @param node $study_node
   *   The study that is to be connected.
   *
   * @return array
   *   A form array for setting connection-specific options.
   */
  public function configurationForm($study_node);

  /**
   * Validation callback for the form returned by configurationForm().
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   *   
   * @return array
   *   A form array with error messages keyed by connection-specific options.
   */
  public function configurationFormValidate(array $form, array &$values, array &$form_state);

  /**
   * Submit callback for the form returned by configurationForm().
   *
   * This method should set the options of this connection' connector according to
   * $values.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state);

  /**
   * Determines whether this connection class implementation supports a given
   * feature. Features are optional extensions to Search API functionality and
   * usually defined and used by third-party modules.
   *
   * @param string $feature
   *   The name of the optional feature.
   *
   * @return boolean
   *   TRUE if this connection knows and supports the specified feature. FALSE
   *   otherwise.
   */
  public function supportsFeature($feature);

  /**
   * View this server's settings. Output can be HTML or a render array, a <dl>
   * listing all relevant settings is preferred.
   */
  public function viewSettings();

  /**
   * Get importer Id
   */
  public function getImporterId();

  public function query($variables);
  
  /**
   * Returns a facet for a specific term.
   * 
   * Categorical variables will return an associative array:
   * array('YES' => 3000, 'NO' => 50000)
   * 
   * Continuous variables will return statistics (min, max, mean, variance,std_deviation,count,total,sum_of_squares)
   * array(
   *   'min' => 10.45,
   *   'max' => 23.78,
   *   ...
   * )
   */
  public function facetTerm(QueryTermInterface $term);

}

/**
 * Abstract class with generic implementation of most connection methods.
 */
abstract class MicaDatasetAbstractConnection implements MicaDatasetConnectionInterface {

  /**
   * @var MicaDatasetConnector
   */
  protected $connector;

  /**
   * Direct reference to the connector's $options property.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Constructor for a connection class, setting the connector configuration used with
   * this connection.
   *
   * The default implementation sets $this->connector and $this->options.
   *
   * @param MicaDatasetConnector $connector
   *   The connector object for this connection.
   */
  public function __construct(MicaDatasetConnector $connector) {
    $this->connector = $connector;
    $this->options = &$connector->options;
  }

  /**
   * Form callback. Might be called on an uninitialized object - in this case,
   * the form is for configuring a newly created connector.
   *
   * Returns an empty form by default.
   *
   * @return array
   *   A form array for setting connection-specific options.
   */
  public function configurationForm($study_node) {
    return array();
  }

  /**
   * Validation callback for the form returned by configurationForm().
   *
   * Does nothing by default.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   */
  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    return;
  }

  /**
   * Submit callback for the form returned by configurationForm().
   *
   * The default implementation just ensures that additional elements in
   * $options, not present in the form, don't get lost at the update.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    if (!empty($this->options)) {
      $values += $this->options;
    }
    $this->options = $values;
  }

  /**
   * Determines whether this connection class implementation supports a given
   * feature. Features are optional extensions to Search API functionality and
   * usually defined and used by third-party modules.
   *
   * @param string $feature
   *   The name of the optional feature.
   *
   * @return boolean
   *   TRUE if this connection knows and supports the specified feature. FALSE
   *   otherwise.
   */
  public function supportsFeature($feature) {
    return FALSE;
  }

  /**
   * View this connector's settings. Output can be HTML or a render array, a <dl>
   * listing all relevant settings is preferred.
   *
   * The default implementation does a crude output as a definition list, with
   * option names taken from the configuration form.
   */
  public function viewSettings() {
    $output = '';
    $form = $form_state = array();
    $option_form = $this->configurationForm($form, $form_state);
    $option_names = array();
    foreach ($option_form as $key => $element) {
      if (isset($element['#title']) && isset($this->options[$key])) {
        $option_names[$key] = $element['#title'];
      }
    }

    foreach ($option_names as $key => $name) {
      $value = $this->options[$key];
      $output .= '<dt>' . check_plain($name) . '</dt>' . "\n";
      $output .= '<dd>' . nl2br(check_plain(print_r($value, TRUE))) . '</dd>' . "\n";
    }

    return $output ? "<dl>\n$output</dl>" : '';
  }

}
