<?php

/**
 * @file
 * Home of the FeedsHTTPFetcher and related classes.
 */

/**
 * Result of FeedsHTTPFetcher::fetch().
 */
class FeedsHTTPSFetcherResult extends FeedsHTTPFetcherResult {
  
  protected $no_verify_peer;
  protected $no_verify_host;
  protected $client_cert;
  protected $client_pk;

  /**
   * Constructor.
   */
  public function __construct($url = NULL, $fetcher_config = NULL) {
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

    if(!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSL_VERIFYHOST => ($this->no_verify_host == FALSE),
      CURLOPT_SSL_VERIFYPEER => ($this->no_verify_peer == FALSE),
      CURLOPT_SSLCERT => $this->client_cert,
      CURLOPT_SSLKEY => $this->client_pk,
    );

    try {
      $result = $client->get($this->url);
    } catch(HttpClientException $e) {
      if($e->getCode() == 0) {
        // curl error
        throw new Exception(t('Download of @url failed: @msg', array('@url' => $this->url, '@msg' => $e->getMessage())));
      } else if (!in_array($e->getCode(), array(200, 201, 202, 203, 204, 205, 206))) {
        throw new Exception(t('Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $e->getCode())));
      }
      $result = $e->getResponse()->body;
    }
    return $this->sanitizeRaw($result);
  }
}

/**
 * Fetches data via HTTPs.
 */
class FeedsHTTPSFetcher extends FeedsHTTPFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    return new FeedsHTTPSFetcherResult($source_config['source'], $this->config);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $config = parent::configDefaults();
    $config += array(
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
    
    $form = parent::configForm($form_state);
    
    $form['no_verify_peer'] = array(
      '#type' => 'checkbox',
      '#title' => t('Accept self-signed certificates'),
      '#description' => t('Enable this if you wish to accept self-signed certificates when connecting to the HTTPs server'),
      '#default_value' => $this->config['no_verify_peer'],
    );

    $form['no_verify_host'] = array(
      '#type' => 'checkbox',
      '#title' => t('Accept any hostname'),
      '#description' => t('Enable this to accept a certificate for a different hostname.'),
      '#default_value' => $this->config['no_verify_host'],
    );

    $form['use_client_cert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Client-side Certificate (https)'),
      '#description' => t('Provide a client certificate when connecting to a feed through HTTPs.'),
      '#default_value' => $this->config['use_client_cert'],
    );
    $form['private_key_file'] = array(
      '#type' => 'textfield',
      '#title' => t('Private Key File'),
      '#description' => t('Enter the filename of the private key (PEM format)'),
      '#default_value' => $this->config['private_key_file'],
      '#dependency' => array(
        'edit-use-client-cert' => array(1),
      ),
    );
    $form['client_cert_file'] = array(
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

}
