<?php
/**
 * @file
 * MicaDatasetOpalConnection class
 */

class MicaDatasetOpalConnectionClass extends MicaDatasetAbstractConnection implements MicaDatasetQueryInterface {

  protected $fieldname_map;
  private $esQueryDefault;
  private $esQueryApi;

  public function __construct(MicaDatasetConnector $connector) {
    parent::__construct($connector);
    $this->esQueryDefault = new MicaDatasetElasticSearchQuery($this);
    $this->esQueryApi = new MicaDatasetElasticSearchQueryApi($this);
  }

  public function configurationForm($study_node) {
    $form_items = array();
    $opal_url = isset($study_node->mica_opal[LANGUAGE_NONE])
      && isset($study_node->mica_opal[LANGUAGE_NONE][0])
      && isset($study_node->mica_opal[LANGUAGE_NONE][0]['url']) ? $study_node->mica_opal[LANGUAGE_NONE][0]['url'] : '';

    if (!empty($opal_url)) {
      $form_items['opal-url'] = array(
        '#type' => 'item',
        '#title' => t('Opal server'),
        '#markup' => empty($opal_url) ? '' : ('<a href="' . $opal_url . '">' . $opal_url . '</a>'),
      );
    }
    else {
      $form_items['opal-url'] = array(
        '#title' => t('Opal server'),
        '#type' => 'textfield',
        '#description' => t('The Opal server secured url (https is required).'),
        '#required' => TRUE,
      );
    }
    $form_items['datasource'] = array(
      '#title' => t('Datasource'),
      '#type' => 'textfield',
      '#description' => t('The Opal datasource name.'),
      '#required' => TRUE,
    );
    $form_items['table'] = array(
      '#title' => t('Table'),
      '#type' => 'textfield',
      '#description' => t('The Opal table name from which variables and data can be fetched.'),
      '#required' => TRUE,
    );

    return $form_items;
  }


  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    $form_errors = array();
    if (isset($values['opal-url'])
      && (trim($values['opal-url']) === '' || strpos($values['opal-url'], 'https://') === FALSE)) {
      $form_errors['opal-url'] = t('You must provide a valid Opal server url: https://...');
    }
    // todo check for valid chars in names
    if (!isset($values['datasource']) || trim($values['datasource']) === '') {
      $form_errors['datasource'] = t('You must provide a valid Opal datasource name.');
    }
    if (!isset($values['table']) || trim($values['table']) === '') {
      $form_errors['table'] = t('You must provide a valid Opal table name.');
    }
    return $form_errors;
  }


  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    $options = array();
    if (array_key_exists('opal-url', $values)) {
      $study_node = node_load($form_state['values'][MICA_STUDY_ID]);
      $study_node->mica_opal[LANGUAGE_NONE][0]['url'] = $values['opal-url'];
      node_save($study_node);
    }
    $options['datasource'] = trim($values['datasource']);
    $options['table'] = trim($values['table']);

    return $options;
  }


  public function getImporterId() {
    return 'opal_variables';
  }

  public function getTableResourceURI($resource) {
    $connector = $this->connector;
    $study_node = node_load($connector->study_id);
    $url = $study_node->mica_opal[LANGUAGE_NONE][0]['url'];

    // remove trailing slashes
    while (drupal_strlen($url) > 0 && substr($url, drupal_strlen($url) - 1) == '/') {
      $url = substr($url, 0, drupal_strlen($url) - 1);
    }
    $url .= '/ws/datasource/' . $connector->options['datasource'] . '/table/' . $connector->options['table'] . '/' . $resource;
    return $url;
  }

  public function getFieldNameMapping($fieldname) {
    if (!is_array($this->fieldname_map)) {
      $this->requestFieldNameMapping();
    }

    // if mapping is defined return it, otherwise return identity
    if (array_key_exists($fieldname, $this->fieldname_map)) {
      return $this->fieldname_map[$fieldname];
    }
    else {
      return $fieldname;
    }
  }

  /**
   * Get the field name mapping from Opal if this is defined.
   */
  private function requestFieldNameMapping() {
    $url = $this->getTableResourceURI('index/_schema');

    $get = new HttpClientRequest($url, array(
      'method' => 'GET',
      'headers' => array('Accept' => array('application/json')),
      'parameters' => array(),
    ));

    $this->fieldname_map = array();
    try {
      $client = $this->client();
      $schema = json_decode($client->execute($get), TRUE);

      if (isset($schema['keys']) && is_array($schema['keys'])) {
        $keys = $schema['keys'];
        $values = $schema['values'];
        $count = count($keys);
        foreach ($keys as $idx => $key) {
          $this->fieldname_map[$key] = $values[$idx];
          // do not know why it goes in infinite loop
          if ($idx >= $count) {
            break;
          }
        }
      }
    } catch (HttpClientException $e) {
      // ignore
    }
    //debug($this->fieldname_map);
  }

  public function sendQueryEx($query, $resourceUrl, $method, $contentType) {
    $url = $this->getTableResourceURI($resourceUrl);

    $post = new HttpClientRequest($url, array(
      'method' => $method,
      'headers' => array('Accept' => array($contentType), 'Content-Type' => array($contentType)),
      'data' => $query,
      'parameters' => array(),
    ));

    try {
      $client = $this->client();
      $body = $client->execute($post);
    } catch (HttpClientException $e) {
      if ($e->getCode() == 0) {
        // curl error

        throw new Exception($e->getMessage());
      }
      elseif (!in_array($e->getCode(), array(200, 201, 202, 203, 204, 205, 206))) {
        throw $e;
      }
      // http_client throws an exception on all codes that are not 200 (even 201)
      // http://drupal.org/node/722886
      $body = $e->getResponse()->body;
    }

    return $body;
  }

  /**
   * @param string $query
   * @return mixed|the
   * @throws HttpClientException
   * @throws Exception
   */
  public function sendQuery($query) {
    return (json_decode($this->sendQueryEx($query, "index/_search", 'POST', 'application/json'), TRUE));
  }

  /**
   * Extract the underlying file-system path from a file reference (private://someFile.pem)
   */
  private function realpath($reference) {
    if (file_valid_uri($reference)) {
      $wrapper = file_stream_wrapper_get_instance_by_uri($reference);
      if ($wrapper) {
        return $wrapper->realpath();
      }
    }
    return $reference;
  }

  public function client() {
    $client = new HttpClient($formatter = FALSE);

    if (!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSLVERSION => 3,
      CURLOPT_SSL_VERIFYHOST => FALSE,
      CURLOPT_SSL_VERIFYPEER => FALSE,
      CURLOPT_SSLCERT => $this->realpath(PUBLIC_KEY_FILE),
      CURLOPT_SSLKEY => $this->realpath(PRIVATE_KEY_FILE),
    );

    return $client;
  }

  public function query(array $terms) {
    $result = array();

    try {
      $result = $this->esQueryApi->query($terms);
    } catch (Exception $e) {
      $result = $this->esQueryDefault->query($terms);
    }

    return $result;
  }

  public function queryBy(array $terms, array $fields) {
    $result = array();

    try {
      $result = $this->esQueryApi->queryBy($terms, $fields);
    } catch (Exception $e) {
      $result = $this->esQueryDefault->queryBy($terms, $fields);
    }

    return $result;
  }

  public function crossQueryBy(array $terms, array $fields) {
    $result = array();

    try {
      $result = $this->esQueryApi->crossQueryBy($terms, $fields);
    } catch (Exception $e) {
      $result = $this->esQueryDefault->crossQueryBy($terms, $fields);
    }

    return $result;
  }

  public function facetTerm(QueryTermInterface $term) {
    $result = array();

    try {
      $result = $this->esQueryApi->facetTerm($term);
    } catch (Exception $e) {
      $result = $this->esQueryDefault->facetTerm($term);
    }

    return $result;
  }
}
