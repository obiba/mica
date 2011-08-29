<?php

/**
 * Class representing a dataset connector.
 *
 * This can handle the same calls as defined in the MicaDatasetConnectionInterface
 * and pass it on to the connection implementation appropriate for this connector.
 */
class MicaDatasetConnector extends Entity {

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
  public $study_id = 0;

  /**
   * @var integer
   */
  public $dataset_id = 0;

  /**
   * @var string
   */
  public $class = '';

  /**
   * @var array
   */
  public $options = array();

  /**
   * @var integer
   */
  public $enabled = 1;

  /**
   * Proxy object for invoking service methods.
   *
   * @var MicaDatasetConnectionInterface
   */
  protected $proxy;

  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_dataset_connector');
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
    $changeable = array('name' => 1, 'enabled' => 1, 'description' => 1, 'options' => 1);
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
    unset($ret['proxy'], $ret['status'], $ret['module'], $ret['is_new']);
    return array_keys($ret);
  }

  /**
   * Helper method for ensuring the proxy object is set up.
   */
  protected function ensureProxy() {
    if (!isset($this->proxy)) {
      $class = mica_datasets_get_connection_info($this->class);
      if ($class && class_exists($class['class'])) {
        if (empty($this->options)) {
          // We always have to provide the options.
          $this->options = array();
        }
        $this->proxy = new $class['class']($this);
      }
      if (!($this->proxy instanceof MicaDatasetConnectionInterface)) {
        throw new MicaException(t('Dataset connector with machine name !name specifies illegal service class !class.', array('!name' => $this->machine_name, '!class' => $this->class)));
      }
    }
  }

  public function displayError(Exception $e) {
    $study = node_load($this->study_id);
    if($e->getCode() == 401) {
      drupal_set_message(t("Study %study: Authentication failed (401).", array("%study" => $study->title)), 'error');
    } else if($e->getCode() == 403) {
      drupal_set_message(t("Study %study: Not authorized to search dataset (403).", array("%study" => $study->title)), 'error');
    } else if($e->getCode() == 404) {
      drupal_set_message(t("Study %study: Cannot find dataset (404). Make sure the study's configuration is valid.", array("%study" => $study->title)), 'error');
    } else {
      drupal_set_message(t("Study %study: Failed executing search. Message was: %msg", array("%study" => $study->title, "%msg" => $e->getMessage())), 'error');
    }
  }

  /**
   * If the service class defines additional methods, not specified in the
   * MicaDatasetConnectionInterface interface, then they are called via this magic
   * method.
   */
  public function __call($name, $arguments = array()) {
    $this->ensureProxy();
    return call_user_func_array(array($this->proxy, $name), $arguments);
  }

  // Proxy methods

  // For increased clarity, and since some parameters are passed by reference,
  // we don't use the __call() magic method for those.

  public function configurationForm($study_node) {
    $this->ensureProxy();
    return $this->proxy->configurationForm($study_node);
  }

  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    $this->ensureProxy();
    return $this->proxy->configurationFormValidate($form, $values, $form_state);
  }

  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    $this->ensureProxy();
    return $this->proxy->configurationFormSubmit($form, $values, $form_state);
  }

  public function supportsFeature($feature) {
    $this->ensureProxy();
    return $this->proxy->supportsFeature($feature);
  }

  public function viewSettings() {
    $this->ensureProxy();
    return $this->proxy->viewSettings();
  }

  public function getImporterId() {
    $this->ensureProxy();
    return $this->proxy->getImporterId();
  }

  public function query($variables) {
    $this->ensureProxy();
    return $this->proxy->query($variables);
  }
}
