<?php

class MicaDatasetOpalConnectionClass extends MicaDatasetAbstractConnection {

  public function __construct(MicaDatasetConnector $connector) {
    parent::__construct($connector);
  }

  public function configurationForm($study_node) {
    $form_items = array();
    
    $opal_url = array();
    $field = $study_node->mica_opal;
    if ($field) {
      $opal_url = $field[$study_node->language];
    }

    if (isset($opal_url) && !empty($opal_url)) {
      $form_items['opal-url'] = array (
        '#type' => 'item',
        '#title' => t('Opal server'),
        '#markup' => !empty($opal_url) ? '<a href="' . $opal_url[0]['url'] . '">' . $opal_url[0]['url'] . '</a></div>' : '',
      );
    }
    else {
      $form_items['opal-url'] = array (
      '#title' => t('Opal server'),
      '#type' => 'textfield',
      '#description' => t('The Opal server secured url (https is required).'),
      '#required' => TRUE,
      );
    }
    $form_items['datasource'] = array (
      '#title' => t('Datasource'),
      '#type' => 'textfield',
      '#description' => t('The Opal datasource name.'),
      '#required' => TRUE,
    );
    $form_items['table'] = array (
      '#title' => t('Table'),
      '#type' => 'textfield',
      '#description' => t('The Opal table name from which variables and data can be fetched.'),
      '#required' => TRUE,
    );

    return $form_items;
  }


  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    $form_errors = array();

    if (array_key_exists('opal-url', $values)) {
      $value = trim($values['opal-url']);
      if ($value == '' || strpos($value,'https://') === FALSE) {
        $form_errors['opal-url'] = t('You must provide a valid Opal server url: https://...');
      }
    }
    // todo check for valid chars in names
    $value = trim($values['datasource']);
    if ($value == '') {
      $form_errors['datasource'] = t('You must provide a valid Opal datasource name.');
    }
    $value = trim($values['table']);
    if ($value == '') {
      $form_errors['table'] = t('You must provide a valid Opal table name.');
    }

    return $form_errors;
  }


  public function configurationFormSubmit(array $form, array &$values, array &$form_state){
    $options = array();
    if (array_key_exists('opal-url', $values)) {
      $study_node = node_load($form_state['values'][MICA_STUDY_ID]);
      $study_node->mica_opal[$study_node->language][] = array('url' => $values['opal-url']);
      node_save($study_node);
    }
    $options['datasource'] = trim($values['datasource']);
    $options['table'] = trim($values['table']);

    return $options;
  }


  public function getImporterId() {
    return 'opal_participant_variables';
  }

  public function getTableResourceURI($resource) {
    $connector = $this->connector;
    $study_node = node_load($connector->study_id);
    $url = $study_node->mica_opal[$study_node->language][0]['url'];
    $url .= "/ws/datasource/" . $connector->options['datasource'] . '/table/' . $connector->options['table'] . "/" . $resource;
    return $url;
  }

  public function query($terms) {

    $facets = array();
    foreach($terms as $term) {
      $impl = $term->termImpl();
      $facet = $this->asFacet($impl);
      array_push($facets, $facet);
    }

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= implode(',', $facets);
    $q.='}}';

    $data = $this->sendQuery($q);
    
    $total = $data['hits']['total'];

    $result = array('total'=>$total);
    foreach($terms as $term) {
      $impl = $term->termImpl();
      $result[$impl->getName()] = $this->count($data['facets'][$impl->getName()]);
    }

    return $result;
  }
  
  public function facetTerm(QueryTermInterface $term) {
    switch($term->getType()) {
      case 'CategoryTerm' :
        $facets = <<< END
      "{$term->getName()}" : {
        "terms" : {
          "field" : "{$term->getName()}",
          "size": 1000,
          "all_fields" : true
        }
      }
END;
        break;
      case 'RangeTerm' :
        $facets = <<< END
      "{$term->getName()}" : {
        "statistical" : {
          "field" : "{$term->getName()}"
        }
      }
END;
        break;
    }

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= $facets;
    $q.='}}';
    
    $data = $this->sendQuery($q);
    
    $facetResult = $data['facets'][$term->getName()];

    // TODO: handle statistical result
    $result = array();
    foreach($facetResult['terms'] as $termCount) {
      $result[$termCount['term']] = $termCount['count'];
    }
    
    $result['missing'] = $facetResult['missing'];
    
//    debug($result);
    return $result;
  }
  
  private function sendQuery($query) {
//    debug($query);
    
    $url = $this->getTableResourceURI("index/_search");

    $post = new HttpClientRequest($url, array(
        'method' => 'GET',
        'headers' => array('Accept' => array('application/json')),
        'data' => $query,
        'parameters' => array(),
      ));

    try {
      $client = $this->client();
      $body = $client->execute($post);
//      debug($body);
    }  catch(HttpClientException $e) {
      if($e->getCode() == 0) {
        // curl error
        throw new Exception($e->getMessage());
      } else if (!in_array($e->getCode(), array(200, 201, 202, 203, 204, 205, 206))) {
        throw $e;
      }
      // http_client throws an exception on all codes that are not 200 (even 201)
      // http://drupal.org/node/722886
      $body = $e->getResponse()->body;
    }

    return json_decode($body, TRUE);
  }
  
  private function count($facet) {
    switch($facet['_type']) {
      case 'filter':
      return $facet['count'];
      case 'terms':
      $sum =0;
      foreach($facet['terms'] as $term) {
        $sum += $term['count'];
      }
      return $sum;
      case 'histogram':
      $sum =0;
      foreach($facet['entries'] as $term) {
        $sum += $term['count'];
      }
      return $sum;
    }
    return -1; 
  }

  private function asFacet(QueryTermInterface $term) {
        $facet = <<< END
"{$term->getName()}" : {
  "filter" : {
    {$this->asFilter($term)}
  }
}
END;
    return $facet;
  }

  private function asFilter(QueryTermInterface $term) {

    // The default filter
    $filter = <<< END
  "exists" : {
    "field" : "{$term->getName()}"
  }
END;
    switch ($term->getType()) {
      case 'CategoryTerm':
        if(count($term->categories()) > 0) {
          $terms = '"'. implode('","', $term->categories()) . '"';
          $filter = <<< END
  "terms" : {
    "{$term->getName()}":[$terms]
  }
END;
        }
        break;
      case 'RangeTerm':
        if(count($term->ranges()) > 0) {
          $ranges = $term->ranges();
          $range = $ranges[0];
          $filter = <<< END
  "numeric_range" : {
    "{$term->getName()}": {
      "from" : {$range['from']},
      "to" : {$range['to']},
      "include_lower" : true, 
      "include_upper" : false
    }
  }
END;
        }
        break;
      default:
      break;
    }

    if($term->isInverted()) {
      $invert = $filter;
      $filter = <<< END
  "not" : {
    "filter" : {
      $invert
    }
  }
END;
    }
    return $filter;
  }

  /**
   * Extract the underlying file-system path from a file reference (private://someFile.pem)
   */
  private function realpath($reference) {
    if(file_valid_uri($reference)) {
      $wrapper = file_stream_wrapper_get_instance_by_uri($reference);
      if($wrapper) {
        return $wrapper->realpath();
      }
    }
    return $reference;
  }
  
  public function client() {
    $client = new HttpClient($formatter = FALSE);

    if(!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSL_VERIFYHOST => FALSE,
      CURLOPT_SSL_VERIFYPEER => FALSE,
      CURLOPT_SSLCERT => $this->realpath(PUBLIC_KEY_FILE),
      CURLOPT_SSLKEY => $this->realpath(PRIVATE_KEY_FILE),
    );

    return $client;
  }
}
