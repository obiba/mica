<?php

require_once('mica_connector.response_parser.inc');

/**
 * An abstract implementation of a dataset connection that builds and sends an Elastic Search query from the query terms.
 */
class MicaDatasetElasticSearchQuery extends MicaDatasetAbstractQuery {

  const INDEX_SERACH_URL = 'index/_search';

  public function query(array $terms) {
    list($facets, $filters) = $this->getQueryFacetsFilters($terms);

    $facets[] = '"_matched" :{ "filter":{ "and":[ {' . implode('},{', $filters) . '}]}}';

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= implode(',', $facets);
    $q .= '}}';

//        debug($q);

    $data = $this->connection->sendQuery($q);
    $parser = new MicaConnectorResponseParserJson();

    return $parser->parseQueryResponse($data, $terms);
  }

  public function queryBy(array $terms, array $fields) {
    $by_field = $fields[0];

    // one facet for population matching each term
    list($facets, $filters) = $this->getQueryByFacetsFilters($terms, $by_field);

    // one facet for the population matching all terms
    $and_filters = implode('},{', $filters);
    $facets[] = <<< END
"_matched" : {
      "terms" : {
        "field":"{$this->connection->getFieldNameMapping($by_field)}","all_terms":true
      }
      , "facet_filter":  {
        "and":[{{$and_filters}}]
      }
}
END;

    // one facet for all the population
    $facets[] = <<< END
"_all" : {
      "terms" : {
        "field":"{$this->connection->getFieldNameMapping($by_field)}","all_terms":true
      }
}
END;

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= implode(',', $facets);
    $q .= '}}';

    $data = $this->connection->sendQuery($q);
    $parser = new MicaConnectorResponseParserJson();

    return $parser->parseQueryByResponse($data, $terms);
  }

    public function crossQueryBy(array $terms, array $fields) {
    $by_field = $fields[0];
    $is_continuous = (isset($fields[1]) ? $fields[1] : FALSE);

    // one facet for population matching each term
    $facets = array();
    if ($terms !== FALSE) {
      // Always only one term for this type of query
      $term = $terms[0];
      $impl = $term->termImpl();
      $categories_filter = array();
      foreach($impl->categories() as $i => $category){

        if (!$is_continuous){
          $facets[] = $this->asCrossFacetBy($category, $impl, $by_field, $category);
        }
        else {
          $facets[] = $this->asCrossStatFacetBy($category, $impl, $by_field, $category);
          $categories_filter[] = "\"$category\"";
        }
      }
    }

    // if stats facet, have a facet for total mean and std deviation
    if ($is_continuous){
      $filter = implode(',', $categories_filter);
      $facets[] = <<< END
"total_mean" : {
      "statistical" : {
        "field":"{$this->connection->getFieldNameMapping($by_field)}","size":0
      }
      , "facet_filter":  {
          "terms" : { "{$this->connection->getFieldName($impl)}" : [{$filter}] }
      }
}
END;
    }
    // one facet for the population matching all terms

    $facets[] = <<< END
"_matched" : {
      "terms" : {
        "field":"{$this->connection->getFieldName($impl)}","all_terms":true
      }
      , "facet_filter":  {
        "exists":{
            "field":"{$this->connection->getFieldNameMapping($by_field)}"}
        }
      }
}
END;

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= implode(',', $facets);
    $q .= '}}';

    $data = $this->connection->sendQuery($q);
    $parser = new MicaConnectorResponseParserJson();

    return $parser->parseCrossQueryByResponse($data, $terms, $is_continuous);
  }

  public function facetTerm(QueryTermInterface $term) {
    $fieldname = $this->connection->getFieldName($term);
    switch ($term->getType()) {
      case 'CategoryTerm' :
        $facets = <<< END
      "{$term->getName()}" : {
        "terms" : {
          "field" : "{$fieldname}",
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
          "field" : "{$fieldname}"
        }
      }
END;
        break;
      default:
        $facets = <<< END
      "{$term->getName()}" : {
        "filter": {
          "exists" : {
            "field" : "{$fieldname}"
          }
        }
      }
END;
      break;
    }

    $q = '{"query": {"match_all":{}},"size":0,"facets":{';
    $q .= $facets;
    $q .= '}}';

    $data = $this->connection->sendQuery($q);
    $parser = new MicaConnectorResponseParserJson();

    return $parser->parseFacetTermResponse($data, $term);
  }

  protected  function asFacet(QueryTermInterface $term) {
    $facet = <<< END
"{$term->getName()}" : {
  "filter" : {
  {$this->asFilter($term)}
  }, "global":true
}
END;
    return $facet;
  }

  protected  function asFilter(QueryTermInterface $term) {
    $fieldname = $this->connection->getFieldName($term);
    // The default filter
    $filter = <<< END
  "exists" : {
    "field" : "{$fieldname}"
  }
END;
    switch ($term->getType()) {
      case 'CategoryTerm':
        if (count($term->categories()) > 0) {
          $terms = '"' . implode('","', $term->categories()) . '"';
          $filter = <<< END
  "terms" : {
    "{$fieldname}":[$terms]
  }
END;
        }
        break;
      case 'RangeTerm':
        if (count($term->ranges()) > 0) {
          $ranges = $term->ranges();
          $range = $ranges[0];
          if (isset($range['value'])) {
            $filter = <<< END
  "term" : {
    "{$fieldname}": {$range['value']}
  }
END;
          }
          else {
            $bounds = array();
            if (isset($range['from'])) {
              $bounds[] = '"from" : ' . $range['from'];
              $bounds[] = '"include_lower" : true';
            }
            if (isset($range['to'])) {
              $bounds[] = '"to" : ' . $range['to'];
              $bounds[] = '"include_upper" : false';
            }
            $boundStr = implode(',', $bounds);
            $filter = <<< END
  "numeric_range" : {
    "{$fieldname}": {
    {$boundStr}
    }
  }
END;
          }
        }
        break;
      case 'TodoTerm':
        if (count($term->match()) > 0) {
          $matchStr = implode('","', $term->match());
          $filter = <<< END
  "terms" : {
    "{$fieldname}":["{$matchStr}"]
  }
END;
        }
        break;
      default:
        break;
    }

    if ($term->isInverted()) {
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

  protected  function asFacetBy(QueryTermInterface $term, $field) {
    $facet = <<< END
"{$term->getName()}" : {
      "terms" : {
        "field":"{$this->connection->getFieldNameMapping($field)}","all_terms":true
      }
      , "facet_filter":  {
        {$this->asFilter($term)}
      }
}
END;
    return $facet;
  }

  private function asCrossFacetBy($facetName, QueryTermInterface $term, $field, $category) {
    $facet = <<< END
"{$facetName}" : {
      "terms" : {
        "field":"{$this->connection->getFieldNameMapping($field)}","all_terms":true
      }
      , "facet_filter":  {
        {$this->asCrossFilter($term, $category)}
      }
}
END;
    return $facet;
  }

  private function asCrossStatFacetBy($facetName, QueryTermInterface $term, $field, $category) {
    $facet = <<< END
"{$facetName}" : {
      "statistical" : {
        "field":"{$this->connection->getFieldNameMapping($field)}","size":0
      }
      , "facet_filter":  {
        {$this->asCrossFilter($term, $category)}
      }
}
END;
    return $facet;
  }

  private function asCrossFilter(QueryTermInterface $term, $category) {
    $fieldname = $this->connection->getFieldName($term);
    // The default filter

    switch ($term->getType()) {
      case 'CategoryTerm':
        if (count($term->categories()) > 0) {
          //$terms = '"' . $category . '"';
          $filter = <<< END
  "term" : {
    "{$fieldname}":"{$category}"
  }
END;
        }
        break;
      default:
        break;
    }
    return $filter;
  }

}
