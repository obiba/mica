<?php

/**
 * @file
 * Mica Dataset Connection model
 */

/**
 * Interface defining the methods search connections have to implement.
 *
 * Before a connection object is used, the corresponding connector's data will be read
 * from the database (see MicaDatasetAbstractConnection for a list of fields).
 */
interface MicaDatasetConnectionInterface
{

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

    /**
     * @param array of MicaDatasetQueryTerm $terms
     */
    public function query($terms);

    /**
     * @param array of MicaDatasetQueryTerm $terms
     * @param array of strings $fields
     */
    public function queryBy($terms, $fields);

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
abstract class MicaDatasetAbstractConnection implements MicaDatasetConnectionInterface
{

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
    public function __construct(MicaDatasetConnector $connector)
    {
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
    public function configurationForm($study_node)
    {
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
    public function configurationFormValidate(array $form, array &$values, array &$form_state)
    {
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
    public function configurationFormSubmit(array $form, array &$values, array &$form_state)
    {
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
    public function supportsFeature($feature)
    {
        return FALSE;
    }

    /**
     * View this connector's settings. Output can be HTML or a render array, a <dl>
     * listing all relevant settings is preferred.
     *
     * The default implementation does a crude output as a definition list, with
     * option names taken from the configuration form.
     */
    public function viewSettings()
    {
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

/**
 * An abstract implementation of a dataset connection that builds and sends an Elastic Search query from the query terms.
 */
abstract class MicaDatasetElasticSearchConnection extends MicaDatasetAbstractConnection
{

    /**
     * Sends the Elastic Search query to study server.
     * @param string $query
     * @return the Elastic Search query response
     */
    protected abstract function sendQuery($query);

    /**
     * Given a query term, get with which field it is indexed in ES.
     * @param QueryTermInterface $term
     * @return the field name string
     */
    protected function getFieldName(QueryTermInterface $term)
    {
        return $this->getFieldNameMapping($term->getFieldName());
    }

    /**
     * Given a expected field name, allow mapping to a study specific field name. Default implementation is identity,
     * @param $fieldname
     * @return the field name string
     */
    protected function getFieldNameMapping($fieldname)
    {
        return $fieldname;
    }

    public function query($terms)
    {
        $facets = array();
        $filters = array();
        if ($terms !== FALSE) {
            foreach ($terms as $term) {
                $impl = $term->termImpl();
                $facets[] = $this->asFacet($impl);
                $filters[] = $this->asFilter($impl);
            }
        }

        $facets[] = '"_matched" :{ "filter":{ "and":[ {' . implode('},{', $filters) . '}]}}';

        $q = '{"query": {"match_all":{}},"size":0,"facets":{';
        $q .= implode(',', $facets);
        $q .= '}}';

        $data = $this->sendQuery($q);

        $total = $data['hits']['total'];

        $result = array('total' => array('_all' => $total));
        $result["_matched"] = $this->count($data['facets']['_matched']);
        foreach ($terms as $term) {
            $impl = $term->termImpl();
            $result[$impl->getName()] = $this->count($data['facets'][$impl->getName()]);
        }

        //debug($result);
        return $result;
    }

    public function queryBy($terms,$fields)
    {
        $by_field = $fields[0];

        // one facet for population matching each term
        $facets = array();
        $filters = array();
        if ($terms !== FALSE) {
            foreach ($terms as $term) {
                $impl = $term->termImpl();
                $facets[] = $this->asFacetBy($impl, $by_field);
                $filters[] = $this->asFilter($impl);
            }
        }

        // one facet for the population matching all terms
        $and_filters =implode('},{', $filters);
        $facets[] = <<< END
"_matched" : {
      "terms" : {
        "field":"{$this->getFieldNameMapping($by_field)}","all_terms":true
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
        "field":"{$this->getFieldNameMapping($by_field)}","all_terms":true
      }
}
END;

        $q = '{"query": {"match_all":{}},"size":0,"facets":{';
        $q .= implode(',', $facets);
        $q .= '}}';

        $data = $this->sendQuery($q);

        $total = $data['hits']['total'];

        $result = array('total' => array('_all' => $total));
        $result["_all"] = $this->count($data['facets']['_all']);
        $result["_matched"] = $this->count($data['facets']['_matched']);
        foreach ($terms as $term) {
            $impl = $term->termImpl();
            $result[$impl->getName()] = $this->count($data['facets'][$impl->getName()]);
        }

        //debug($result);
        return $result;
    }


    public function facetTerm(QueryTermInterface $term)
    {
        $fieldname = $this->getFieldName($term);
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
        }

        $q = '{"query": {"match_all":{}},"size":0,"facets":{';
        $q .= $facets;
        $q .= '}}';

        $data = $this->sendQuery($q);

        $facetResult = $data['facets'][$term->getName()];

        // TODO: handle statistical result
        $result = array();
        if ($term->getType() == 'CategoryTerm') {
            $result = $this->count($facetResult);
        }
        else {
            $result = $facetResult;
        }
        //debug($result);
        return $result;
    }

    protected function asFacet(QueryTermInterface $term)
    {
        $facet = <<< END
"{$term->getName()}" : {
  "filter" : {
  {$this->asFilter($term)}
  }, "global":true
}
END;
        return $facet;
    }

    protected function asFacetBy(QueryTermInterface $term, $field)
    {
        $facet = <<< END
"{$term->getName()}" : {
      "terms" : {
        "field":"{$this->getFieldNameMapping($field)}","all_terms":true
      }
      , "facet_filter":  {
        {$this->asFilter($term)}
      }
}
END;
        return $facet;
    }

    private function asFilter(QueryTermInterface $term)
    {
        $fieldname = $this->getFieldName($term);
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

    private function count($facet)
    {
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
