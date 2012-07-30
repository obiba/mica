<?php

/**
 * @file
 * Home of the FeedsHTTPFetcher and related classes.
 */

/**
 * Result of FeedsHTTPFetcher::fetch().
 */
class FeedsRestFetcherResult extends FeedsFetcherResult {

  protected $url;
  protected $config;

  /**
   * Constructor.
   */
  public function __construct($url = NULL, $fetcher_config = NULL) {
    $this->url = $url;
    $this->config = $fetcher_config;

    $this->no_verify_peer = $fetcher_config['no_verify_peer'];
    $this->no_verify_host = $fetcher_config['no_verify_host'];
    $this->client_cert = $fetcher_config['client_cert_file'];
    $this->client_pk = $fetcher_config['private_key_file'];
    parent::__construct($url);
  }

  /**
   * Overrides FeedsFetcherResult::getRaw();
   */
  public function getRaw() {
    $client = new HttpClient($formatter = FALSE);

    if (!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSL_VERIFYHOST => ($this->config['no_verify_host'] == FALSE),
      CURLOPT_SSL_VERIFYPEER => ($this->config['no_verify_peer'] == FALSE),
    );

    if ($this->config['use_client_cert']) {
      $client->options['curlopts'] += array(
        CURLOPT_SSLCERT => $this->realpath($this->config['client_cert_file']),
        CURLOPT_SSLKEY => $this->realpath($this->config['private_key_file']),
      );
    }

    try {
      $get = new HttpClientRequest($this->url, array(
        'method' => $this->config['method'],
        'parameters' => array(),
      ));

      $get->addHeader('Accept', $this->config['content_type']);
      $result = $client->execute($get);
    } catch (HttpClientException $e) {
      if ($e->getCode() == 0) {
        // curl error
        throw new Exception(t('Download of @url failed: @msg', array(
          '@url' => $this->url,
          '@msg' => $e->getMessage()
        )));
      }
      elseif (!in_array($e->getCode(), array(200, 201, 202, 203, 204, 205, 206))) {
        throw new Exception(t('Download of @url failed with code !code.', array(
          '@url' => $this->url,
          '!code' => $e->getCode()
        )));
      }
      // http_client throws an exception on all codes that are not 200 (even 201)
      // http://drupal.org/node/722886
      $result = $e->getResponse()->body;
    }
    return $this->sanitizeRaw($result);
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
}

/**
 * A RESTful fetcher. Allows overriding many parts of the underlying http request.
 */
class FeedsRestFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    return new FeedsRestFetcherResult($source_config['source'], $this->config);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $config = array(
      'method' => 'GET',
      'content_type' => '*',
      'no_verify_peer' => FALSE,
      'no_verify_host' => FALSE,
      'use_client_cert' => FALSE,
      'private_key_file' => '',
      'client_cert_file' => '',
    );
    return $config;
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();

    $form['method'] = array(
      '#type' => 'select',
      '#title' => t('HTTP Method'),
      '#description' => t('The HTTP verb to use'),
      '#options' => array('GET', 'POST'),
      '#default_value' => $this->config['method'],
    );
    $form['content_type'] = array(
      '#type' => 'textfield',
      '#title' => t('Accept Header'),
      '#description' => t('The value for the Accept HTTP header. Used for content-type negotiation (e.g.: application/json).'),
      '#default_value' => $this->config['content_type'],
    );
    $form['https'] = array(
      '#type' => 'fieldset',
      '#title' => t('HTTPs Options'),
      '#description' => t('Change the behaviour for https connections'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['https']['no_verify_peer'] = array(
      '#type' => 'checkbox',
      '#title' => t('Accept self-signed certificates'),
      '#description' => t('Enable this if you wish to accept self-signed certificates when connecting to the HTTPs server'),
      '#default_value' => $this->config['no_verify_peer'],
    );
    $form['https']['no_verify_host'] = array(
      '#type' => 'checkbox',
      '#title' => t('Accept any hostname'),
      '#description' => t('Enable this to accept a certificate for a different hostname.'),
      '#default_value' => $this->config['no_verify_host'],
    );
    $form['https']['use_client_cert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Client-side Certificate (https)'),
      '#description' => t('Provide a client certificate when connecting to a feed through HTTPs.'),
      '#default_value' => $this->config['use_client_cert'],
    );
    $form['https']['private_key_file'] = array(
      '#type' => 'textfield',
      '#title' => t('Private Key File'),
      '#description' => t('Enter the filename of the private key (PEM format)'),
      '#default_value' => $this->config['private_key_file'],
      '#dependency' => array(
        'edit-use-client-cert' => array(1),
      ),
    );
    $form['https']['client_cert_file'] = array(
      '#type' => 'textfield',
      '#title' => t('Certificate File'),
      '#description' => t('Enter the filename of the certificate file (PEM format)'),
      '#default_value' => $this->config['client_cert_file'],
      '#dependency' => array(
        'edit-use-client-cert' => array(1),
      ),
    );
    return $form;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('Enter a feed URL.'),
      '#default_value' => isset($source_config['source']) ? $source_config['source'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    return $form;
  }

}
