<?php

/**
 * Class representing a dataset query.
 */
class MicaDatasetQuery extends Entity {

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
  public $description = '';

  /**
   * @var integer
   */
  public $user_id = 0;

  /**
   * @var integer
   */
  public $dataset_id = 0;

  /**
   * @var integer
   */
  public $published = 0;


  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_dataset_query');
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
    $changeable = array('name' => 1, 'published' => 1, 'description' => 1);
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
    unset($ret['status'], $ret['module'], $ret['is_new']);
    return array_keys($ret);
  }

}


/**
 * Class representing a dataset query term.
 */
class MicaDatasetQueryTerm extends Entity {

  /* Database values that will be set when object is loaded: */

  /**
   * @var integer
   */
  public $id = 0;

  /**
   * @var integer
   */
  public $query_id = 0;

  /**
   * @var integer
   */
  public $variable_id = 0;

  /**
   * @var array
   */
  public $options = array();

  /**
   * @var integer
   */
  public $weight = 0;

  /**
   * @var integer
   */
  public $depth = 0;

  /**
   * A transient identifier for building in-memory query terms without having a query defined.
   * @var integer
   */
  public $dataset_id = 0;

  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_dataset_query_term');
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
    $changeable = array('name' => 1, 'weight' => 1, 'depth' => 1);
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
    unset($ret['status'], $ret['module'], $ret['is_new']);
    return array_keys($ret);
  }

  /**
   * Get the type of the term, extracted from the options.
   *
   * @return string
   *   The type name or NULL if not defined.
   */
  public function getType() {
    if (isset($options) && array_key_exists('type', $options)) {
      return $options['type'];
    }
    return NULL;
  }

  public function termImpl() {
    $type = $this->options['type'];
    if(isset($type) == false) {
      $variable = node_load($this->variable_id);
      $type = AbstractTerm::typeFor($variable);
    }
    return new $type($this);
  }

  public function toString() {
    return $this->termImpl()->toString();
  }
}

class MicaDatasetQueryManager {

  public static function isCached(MicaDatasetQuery $query) {
    return isset($_SESSION['mica_dataset_query'][$query->dataset_id][$query->name]);
  }

  public static function delete(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      unset($_SESSION['mica_dataset_query'][$query->dataset_id][$query->name]);
    }
  }

  /**
   * @param string $dataset_id
   * @param string $query_name
   *
   * @return MicaDatasetQueryCache
   */
  public static function getCacheByName($dataset_id, $query_name) {
    if (isset($_SESSION['mica_dataset_query'][$dataset_id][$query_name])) {
      return unserialize($_SESSION['mica_dataset_query'][$dataset_id][$query_name]);
    }
    return FALSE;
  }

  /**
   * @param MicaDatasetQuery $query
   *
   * @return MicaDatasetQueryCache
   */
  public static function getCache(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      return unserialize($_SESSION['mica_dataset_query'][$query->dataset_id][$query->name]);
    }
    return FALSE;
  }

  /**
   * @param array $values
   *
   * @return MicaDatasetQuery
   */
  public static function addQuery(array $values) {
    $query = new MicaDatasetQuery($values);
    $query->is_new = TRUE;
    self::newCache($query);
    return $query;
  }

  public static function newCache(MicaDatasetQuery $query) {
    $cache = new MicaDatasetQueryCache($query);
    $_SESSION['mica_dataset_query'][$query->dataset_id][$query->name] = serialize($cache);
    return $cache;
  }

  /**
   * @param string $term_id
   *
   * @return MicaDatasetQueryTerm
   */
  public static function getTerm($term_id) {
    // look for the query in the cache by name
    if (isset($_SESSION['mica_dataset_query'])) {
      foreach ($_SESSION['mica_dataset_query'] as $dataset_id => $queries) {
        foreach (array_keys($queries) as $query_name) {
          if (preg_match('/^' . $query_name . ':/', $term_id)) {
            return self::getCacheByName($dataset_id, $query_name)->getTerm($term_id);
          }
        }
      }
    }
    return FALSE;
  }

  /**
   * @param string $dataset_id
   *
   * @return array of MicaDatasetQuery
   */
  public static function getQueries($dataset_id) {
    $queries = array();
    if (isset($_SESSION['mica_dataset_query'][$dataset_id])) {
      foreach ($_SESSION['mica_dataset_query'][$dataset_id] as $cache) {
        $query_cache = unserialize($cache);
        $queries[] = $query_cache->query;
      }
    }
    return $queries;
  }

  /**
   * @param string $dataset_id
   * @param string $query_name
   *
   * @return MicaDatasetQuery
   */
  public static function getQuery($dataset_id, $query_name) {
    $rval = self::getCacheByName($dataset_id, $query_name);
    return $rval === FALSE ? FALSE : $rval->query;
  }

  /**
   * @param string $query_name
   * 
   * @return MicaDatasetQuery
   */
  public static function getQueryByName($query_name) {
    if (isset($_SESSION['mica_dataset_query'])) {
      foreach ($_SESSION['mica_dataset_query'] as $dataset_id => $queries) {
        foreach ($queries as $name => $value) {
          if ($query_name == $name) {
            return self::getQuery($dataset_id, $query_name);
          }
        }
      }
    }
    return FALSE;
  }

}

class MicaDatasetQueryCache {

  /**
   * @var MicaDatasetQuery
   */
  public $query;

  /**
   * @var array of MicaDatasetQueryTerm
   */
  public $terms = array();

  public function __construct(MicaDatasetQuery $query) {
    $this->query = $query;
  }

  /**
   * Inserts a new dataset query term.
   *
   * @param array $values
   *   An array containing the values to be inserted.
   *
   * @return MicaDatasetQueryTerm
   *   The newly inserted query term's id, or FALSE on error.
   */
  public function addTerm(array $values) {
    $term = new MicaDatasetQueryTerm($values);
    $term->is_new = TRUE;

    // set the term id
    $index = 1;
    $index = count($this->terms) + 1;
    $term->id = $this->query->name . ':' . $index;
    $term->dataset_id = $this->query->dataset_id;

    $this->updateTerm($term);
  }

  public function updateTerm(MicaDatasetQueryTerm $term) {
    $this->terms[$term->id] = $term;
    $this->save();
  }

  public function deleteTerm(MicaDatasetQueryTerm $term) {
    unset($this->terms[$term->id]);
    $this->save();
  }

  public function hasTerm($term_id) {
    return isset($this->terms[$term_id]);
  }

  /**
   * @param string $term_id
   *
   * @return MicaDatasetQueryTerm
   */
  public function getTerm($term_id) {
    if ($this->hasTerm($term_id)) {
      return $this->terms[$term_id];
    }
    return FALSE;
  }

  /**
   * @return array
   */
  public function getTerms() {
    // TODO sort by weight
    return $this->terms;
  }

  public function save() {
    $_SESSION['mica_dataset_query'][$this->query->dataset_id][$this->query->name] = serialize($this);
  }
}