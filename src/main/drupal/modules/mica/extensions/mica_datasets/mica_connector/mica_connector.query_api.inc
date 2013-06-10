<?php

require_once('mica_connector.response_parser.inc');

//module_load_include('php', 'mica_distribution', 'libraries/opal_php/protobuf/Protobuf');
include_once('opal_php/protobuf/Protobuf.php');

use \DrSlump\Protobuf;
Protobuf::autoload();

//module_load_include('php', 'mica_distribution', 'libraries/opal_php/protos/Search');
include_once('opal_php/protos/Search.php');

/**
 * An abstract implementation of a dataset connection that builds and sends an Elastic Search query from the query terms.
 */
class MicaDatasetElasticSearchQueryApi extends MicaDatasetAbstractQuery {

  const FACETS_SEARCH_URL = 'facets/_search';
  const FACET_SEARCH_URL_FORMAT = "facet/variable/%s/_search";
  const CONTENT_TYPE = 'application/x-protobuf';
  const DEFAULT_METHOD = 'POST';

  public function __construct(MicaDatasetConnectionInterface $connection) {
    parent::__construct($connection);
    Protobuf::setDefaultCodec(new Protobuf\Codec\Binary());
  }

  public function query(array $terms) {

    list($facets, $filters) = $this->getQueryFacetsFilters($terms);

    $dtoMatched = new Search\QueryTermDto();
    $dtoMatched->setFacet('_matched');

    if (!empty($filters)){
      $dtoLogicalTerm = new Search\LogicalTermDto();

      foreach ($filters as $filter) {
        $dtoLogicalTerm->addExtension("Search.FilterDto.filters", $filter);
      }

      $dtoMatched->setExtension("Search.LogicalTermDto.filter", $dtoLogicalTerm);
      $facets[] = $dtoMatched;
    }

    $dtoQueries = new Search\QueryTermsDto();

    foreach ($facets as $facet) {
      $dtoQueries->addQueries($facet);
    }

    $data = $this->connection->sendQueryEx(Protobuf::encode($dtoQueries), self::FACETS_SEARCH_URL, self::DEFAULT_METHOD, self::CONTENT_TYPE);
    $dtoResponse = Protobuf::decode('\Search\QueryResultDto', $data);
    $parser = new MicaConnectorResponseParserDto();

    return $parser->parseQueryResponse($dtoResponse, $terms);
  }

  public function queryBy(array $terms, array $fields) {
    $by_field = $fields[0];

    // one facet for population matching each term
    list($facets, $filters) = $this->getQueryByFacetsFilters($terms, $by_field);

    // one facet for the population matching all terms
    $dtoMatched = new Search\QueryTermDto();
    $dtoMatched->setFacet('_matched');

    $dtoField = new Search\VariableTermDto();
    $dtoField->setVariable($by_field);

    $dtoFacetFilter = new Search\LogicalTermDto();

    foreach ($filters as $filter) {
      $dtoFacetFilter->addExtension("Search.FilterDto.filters", $filter);
    }

    $dtoMatched->setExtension("Search.VariableTermDto.field", $dtoField);
    $dtoMatched->setExtension("Search.LogicalTermDto.facetFilter", $dtoFacetFilter);
    $facets[] = $dtoMatched;

    // one facet for all the population
    $dtoAll = new Search\QueryTermDto();
    $dtoAll->setFacet("_all");

    $dtoField = new Search\VariableTermDto();
    $dtoField->setVariable($by_field);

    $dtoAll->setExtension("Search.VariableTermDto.field", $dtoField);
    $facets[] = $dtoAll;

    $dtoQueries = new Search\QueryTermsDto();

    foreach ($facets as $facet) {
      $dtoQueries->addQueries($facet);
    }

    $data = $this->connection->sendQueryEx(Protobuf::encode($dtoQueries), self::FACETS_SEARCH_URL, self::DEFAULT_METHOD, self::CONTENT_TYPE);
    $dtoResponse = Protobuf::decode('\Search\QueryResultDto', $data);
    $parser = new MicaConnectorResponseParserDto();

    return $parser->parseQueryByResponse($dtoResponse, $terms);
  }

  public function crossQueryBy(array $terms, array $fields) {
    $by_field = $fields[0];
    $is_continuous = (isset($fields[1]) ? $fields[1] : FALSE);
    $dtoQueries = new Search\QueryTermsDto();

    // one facet for population matching each term
    $facets = array();
    if ($terms !== FALSE) {
      // Always only one term for this type of query
      $term = $terms[0];
      $impl = $term->termImpl();
      $categories_filter = array();
      foreach($impl->categories() as $i => $category){

        $dtoQueries->addQueries($this->asCrossFacetBy($category, $impl, $by_field, $impl->getFieldName(), array($category)));

        if ($is_continuous){
          $categories_filter[] = "$category";
        }
      }
    }

    // if stats facet, have a facet for total mean and std deviation
    if ($is_continuous){
      $dtoQueries->addQueries($this->asCrossFacetBy("total_mean", $impl, $by_field, $impl->getFieldName(), $categories_filter));
    }
    // one facet for the population matching all terms
    $dtoQueries->addQueries($this->asCrossFacetBy("_matched", $impl, $impl->getFieldName(), $by_field, array()));
    $data = $this->connection->sendQueryEx(Protobuf::encode($dtoQueries), self::FACETS_SEARCH_URL, self::DEFAULT_METHOD, self::CONTENT_TYPE);
    $dtoReponse = Protobuf::decode('\Search\QueryResultDto', $data);
    $parser = new MicaConnectorResponseParserDto();

    return $parser->parseCrossQueryByResponse($dtoReponse, $terms, $is_continuous);
  }

  public function facetTerm(QueryTermInterface $term) {
    $resourceUrl = self::FACETS_SEARCH_URL;
    $method = self::DEFAULT_METHOD;
    $dtoQueries = new Search\QueryTermsDto();
    $dtoQuery = new Search\QueryTermDto();
    $dtoQuery->setFacet($term->getName());
    $fieldname = $term->getFieldName();

    switch ($term->getType()) {
      case 'CategoryTerm' :
      case 'RangeTerm' :
        $resourceUrl = sprintf(self::FACET_SEARCH_URL_FORMAT, $fieldname);
        $method = 'GET';
        $dtoField = new Search\VariableTermDto();
        $dtoField->setVariable($fieldname);
        $dtoQuery->setExtension("Search.VariableTermDto.field", $dtoField);
        break;

      default:
        $dtoLogicalTerm = new Search\LogicalTermDto();
        $dtoFilter = new Search\FilterDto();
        $dtoFilter->setVariable($fieldname);
        $dtoLogicalTerm->addExtension("Search.FilterDto.filters", $dtoFilter);
        $dtoQuery->setExtension("Search.LogicalTermDto.filter", $dtoLogicalTerm);
        break;
    }

    $dtoQueries->addQueries($dtoQuery);
    $data = $this->connection->sendQueryEx(Protobuf::encode($dtoQueries), $resourceUrl, $method, self::CONTENT_TYPE);
    $dtoResponse = Protobuf::decode('\Search\QueryResultDto', $data);
    $parser = new MicaConnectorResponseParserDto();

    return $parser->parseFacetTermResponse($dtoResponse, $term);
  }

  private function asCrossFilter(QueryTermInterface $term, $filterField, $categories) {
    $dtoFacetFilter = NULL;

    switch ($term->getType()) {
      case 'CategoryTerm':
        if (count($categories) > 0) {
          $dtoFacetFilter = new Search\LogicalTermDto();
          $dtoFilter = new Search\FilterDto();
          $dtoFilter->setVariable($filterField);

          $dtoTerm = new Search\InTermDto();

          foreach ($categories as $category) {
            $dtoTerm->addValues($category);
          }

          $dtoFilter->setExtension("Search.InTermDto.terms", $dtoTerm);
          $dtoFacetFilter->setExtension("Search.FilterDto.filters", $dtoFilter);
        }
        break;
      default:
        break;
    }
    return $dtoFacetFilter;
  }

  protected  function asFacet(QueryTermInterface $term) {
    $dtoQuery = new Search\QueryTermDto();
    $dtoQuery->setFacet($term->getName());
    $dtoQuery->setGlobal(TRUE);

    $dtoLogicalTerm = new Search\LogicalTermDto();
    $dtoLogicalTerm->setExtension("Search.FilterDto.filters", $this->asFilter($term));

    $dtoQuery->setExtension("Search.LogicalTermDto.filter", $dtoLogicalTerm);

    return $dtoQuery;
  }

  protected  function asFacetBy(QueryTermInterface $term, $field) {
    $dtoQuery = new Search\QueryTermDto();
    $dtoQuery->setFacet($term->getName());

    $dtoField = new Search\VariableTermDto();
    $dtoField->setVariable($field);

    $dtoFacetFilter = new Search\LogicalTermDto();
    $dtoFacetFilter->setExtension("Search.FilterDto.filters", $this->asFilter($term));

    $dtoQuery->setExtension("Search.VariableTermDto.field", $dtoField);
    $dtoQuery->setExtension("Search.LogicalTermDto.facetFilter", $dtoFacetFilter);

    return $dtoQuery;
  }

  protected  function asFilter(QueryTermInterface $term) {
    $dtoFilter = new Search\FilterDto();
    $dtoFilter->setVariable($term->getFieldName());

    switch ($term->getType()) {
      case 'CategoryTerm':
        if (count($term->categories()) > 0) {
          $dtoTerms = new Search\InTermDto();

          foreach ($term->categories() as $category) {
            $dtoTerms->addValues($category);
          }

          $dtoFilter->setExtension("Search.InTermDto.terms", $dtoTerms);
        }
        break;

      case 'RangeTerm':
        if (count($term->ranges()) > 0) {
          $ranges = $term->ranges();
          $range = $ranges[0];
          if (isset($range['value'])) {
            $dtoTerms = new Search\InTermDto();
            $dtoTerms->addValues($range['value']);
            $dtoFilter->setExtension("Search.InTermDto.terms", $dtoTerms);
          }
          else {
            $dtoRange = new Search\RangeTermDto();

            if (isset($range['from'])) {
              $dtoRange->setFrom($range['from']);
              $dtoRange->setIncludeLower(TRUE);
            }

            if (isset($range['to'])) {
              $dtoRange->setTo($range['to']);
              $dtoRange->setIncludeUpper(TRUE);
            }

            $dtoFilter->setExtension("Search.RangeTermDto.range", $dtoRange);
          }
        }
        break;
      default:
        break;
    }

    if ($term->isInverted()) {
      $dtoFilter->setNot(TRUE);
    }
    return $dtoFilter;
  }

  private function asCrossFacetBy($facetName, QueryTermInterface $term, $field, $filterField, $categories) {
    $dtoQuery = new Search\QueryTermDto();
    $dtoQuery->setFacet($facetName);
    $dtoField = new Search\VariableTermDto();
    $dtoField->setVariable($field);
    $dtoQuery->setExtension("Search.VariableTermDto.field", $dtoField);

    $dtoFacetFilter = $this->asCrossFilter($term, $filterField, $categories);

    if (isset($dtoFacetFilter)) {
      $dtoQuery->setExtension("Search.LogicalTermDto.facetFilter", $dtoFacetFilter);
    }

    return $dtoQuery;
  }

}
