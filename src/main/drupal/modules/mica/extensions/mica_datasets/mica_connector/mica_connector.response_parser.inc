<?php

abstract class  MicaConnectorResponseParserAbstract {
  public abstract function parseQueryResponse($data, $terms);
  public abstract function parseQueryByResponse($data, $terms);
  public abstract function parseCrossQueryByResponse($data, $terms, $is_continuous);
  public abstract function parseFacetTermResponse($data, $term);
  protected function count($facet) {
    return 0;
  }
}

class MicaConnectorResponseParserJson extends MicaConnectorResponseParserAbstract {

  public function parseQueryResponse($data, $terms) {
    $total = $data['hits']['total'];
    $result = array('total' => array('_all' => $total));
    $result["_matched"] = $this->count($data['facets']['_matched']);

    foreach ($terms as $term) {
      $impl = $term->termImpl();
      $result[$impl->getName()] = $this->count($data['facets'][$impl->getName()]);
    }

    return $result;
  }

  public function parseQueryByResponse($data, $terms) {
    $result = $this->parseQueryResponse($data, $terms);
    $result["_all"] = $this->count($data['facets']['_all']);

    return $result;
  }

  public function parseCrossQueryByResponse($data, $terms, $is_continuous) {
    $total = $data['hits']['total'];

    $result = array('total' => array('_all' => $total));
    //$result["_all"] = $this->count($data['facets']['_all']);
    $result["_matched"] = $this->count($data['facets']['_matched']);
    $term = $terms[0];
    $impl = $term->termImpl();

    foreach ($impl->categories() as $i => $category) {
      if (!$is_continuous) {
        $result[$category] = $this->count($data['facets'][$category]);
      }
      else {
        $result[$category] = $data['facets'][$category];
      }
    }

    if ($is_continuous) {
      $result['total_mean'] = $data['facets']['total_mean'];
      return $result;
    }
    return $result;
  }

  public function parseFacetTermResponse($data, $term) {
    $facetResponse = $data['facets'][$term->getName()];

    // TODO: handle statistical result
    if ($term->getType() == 'CategoryTerm' || $term->getType() == 'TodoTerm') {
      return $this->count($facetResponse);
    }

    $result = $facetResponse;
    return $result;
  }

  protected function count($facet) {
    $rval = array('_all' => 0);
    switch ($facet['_type']) {
      case 'filter':
        $rval['_all'] = $facet['count'];
        break;
      case 'terms':
        $rval['_all'] = $facet['total'];
        $rval['_missing'] = $facet['missing'];
        $rval['_other'] = $facet['other'];
        foreach ($facet['terms'] as $term) {
          $rval[$term['term']] = $term['count'];
        }
        break;
      case 'histogram':
        $sum = 0;
        foreach ($facet['entries'] as $term) {
          $sum += $term['count'];
        }
        $rval['_all'] = $sum;
        break;
    }
    return $rval;
  }
}

class MicaConnectorResponseParserDto extends MicaConnectorResponseParserAbstract {

  public function parseQueryResponse($data, $terms) {
    $result = array('total' => array('_all' => $data->getTotalHits()));

    $facets = $data->getFacetsList();

    foreach ($facets as $facet) {
      $category = $facet->getFacet();

      if ($facet->hasStatistics()) {
        $result[$category] = $this->parseContinuous($facet->getStatistics(0));
      }
      else {
        $result[$category] = $this->count($facet);
      }
    }

    return $result;
//
//
//    foreach ($terms as $term) {
//      $impl = $term->termImpl();
//      $result[$impl->getName()] = $this->count($data['facets'][$impl->getName()]);
//    }

//    return $result;
  }

  public function parseQueryByResponse($data, $terms) {
    $result = $this->parseQueryResponse($data, $terms);
    $all = $this->findResponseFacetByName($data, "_all");

    if (isset($all)) {
      $result["_all"] = $this->count($all);
    }

    return $result;
  }

  private function findResponseFacetByName($data, $facetName) {
    $responseFacets = $data->getFacetsList();

    foreach ($responseFacets as $responseFacet) {
      if ($responseFacet->getFacet() == $facetName) {
        return $responseFacet;
      }
    }

    return null;
  }

  public function parseCrossQueryByResponse($data, $terms, $is_continuous) {
    $result = array();
    $facets = $data->getFacetsList();

    foreach ($facets as $facet) {
      $category = $facet->getFacet();

      if ($facet->hasStatistics()) {
        $result[$category] = $this->parseContinuous($facet->getStatistics(0));
      }
      else {
        $result[$category] = $this->count($facet);
      }
    }

    return $result;
  }

  public function parseFacetTermResponse($data, $term) {
    $facet = $data->getFacets(0);

    if ($facet->hasStatistics()) {
      $result = $this->parseContinuous($facet->getStatistics(0));
    }
    else {
      $result = $this->count($facet);
    }

    return $result;
  }

  protected function count($facet) {
    $rval = array('_all' => 0);

    if ($facet->hasFilters()) {
      $filters = $facet->getFiltersList();
      $total = 0;

      foreach ($filters as $filter) {
        $total += $filter->getCount();
      }

      $rval['_all'] = $total;
    }
    else if ($facet->hasFrequencies()) {
      $frequenciesList = $facet->getFrequenciesList();
      $total = 0;

      foreach ($frequenciesList as $frequency) {
        $count = $frequency->getCount();
        $rval[$frequency->getTerm()] = $count;
        $total += $count;
      }

      $rval['_all'] = $total;
    }

    return $rval;
  }

  private function parseContinuous($facetResponse) {
    $result = array();
    $result['count'] = $facetResponse->getCount();
    $result['mean'] = $facetResponse->getMean();
    $result['min'] = $facetResponse->getMin();
    $result['max'] = $facetResponse->getMax();
    $result['std_deviation'] = $facetResponse->getStdDeviation();
    return $result;
  }

}
