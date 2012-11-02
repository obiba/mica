<?php

/**
 * @file
 * Mica Datasets Query entity
 */

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
  public $cross_variable_id = 0;

  /**
   * @var integer
   */
  public $published = 0;


  /**
   * Constructor as a helper to the parent constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mica_query');
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

  public static function compare(MicaDatasetQuery $query_a, MicaDatasetQuery $query_b) {
    return strcmp($query_a->name, $query_b->name);
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
    require_once('mica_query.terms.inc');
    $values['module'] = 'mica_query';
    if (!isset($values['options']['type']) && isset($values['variable_id'])) {
      $values['options']['type'] = AbstractTerm::typeFor(node_load($values['variable_id']));
    }
    parent::__construct($values, 'mica_query_term');
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
    if (!isset($type)) {
      $variable = node_load($this->variable_id);
      $type = AbstractTerm::typeFor($variable);
    }
    return new $type($this);
  }

  public function toString() {
    return $this->termImpl()->toString();
  }

  public static function compare(MicaDatasetQueryTerm $term_a, MicaDatasetQueryTerm $term_b) {
    if ($term_a->weight == $term_b->weight) {
      return 0;
    }
    else {
      return $term_a->weight > $term_b->weight ? 1 : -1;
    }
  }
}

class MicaDatasetQueryManager {

  /**
   * Check if query is in the cache.
   * @param MicaDatasetQuery $query
   * @return boolean
   */
  public static function isCached(MicaDatasetQuery $query) {
    return isset($_SESSION['mica_query'][$query->id]);
  }

  /**
   * Check if query was a persisted one, modified and stored in the session.
   * @param MicaDatasetQuery $query
   * @return boolean
   */
  public static function isModified(MicaDatasetQuery $query) {
    return self::isCached($query) && is_numeric($query->id);
  }

  /**
   * Remove query and terms from the cache and save.
   * @param MicaDatasetQuery $query
   */
  public static function save(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      $terms = self::getCache($query)->getTerms();
      self::delete($query);

      if (is_numeric($query->id)) {
        $query->save();
        foreach ($terms as $term) {
          $term->query_id = $query->id;
          $term->save();
        }
      }
      else {
        $query->id = 0;
        $query->is_new = TRUE;
        $query->module = 'mica_query';
        $query->save();
        foreach ($terms as $term) {
          $term->id = 0;
          $term->query_id = $query->id;
          $term->is_new = TRUE;
          $term->module = 'mica_query';
          $term->save();
        }
      }
    }
  }

  /**
   * Delete query from cache.
   * @param MicaDatasetQuery $query
   */
  public static function delete(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      unset($_SESSION['mica_query'][$query->id]);
    }
  }

  /**
   * Delete all cached queries of a dataset.
   * @param $dataset_id
   */
  public static function deleteQueries($dataset_id) {
    if (isset($_SESSION['mica_query'])) {
      foreach ($_SESSION['mica_query'] as $query_id => $cache) {
        $query_cache = unserialize($cache);
        if ($query_cache->query->dataset_id == $dataset_id) {
          unset($_SESSION['mica_query'][$query_id]);
        }
      }
    }
  }

  /**
   * @param MicaDatasetQuery $query
   * @return MicaDatasetQueryCache
   */
  public static function getCache(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      return unserialize($_SESSION['mica_query'][$query->id]);
    }
    return FALSE;
  }

  /**
   * @param array $values
   * @return MicaDatasetQuery
   */
  public static function addQuery(array $values) {
    $query = new MicaDatasetQuery($values);
    $query->is_new = TRUE;
    $query->id = $query->dataset_id . ':' . $query->name;
    self::addCache($query);
    return $query;
  }

  /**
   * Create a new cache instance for the given query.
   * @param MicaDatasetQuery $query
   * @return MicaDatasetQueryCache
   */
  public static function addCache(MicaDatasetQuery $query) {
    $cache = new MicaDatasetQueryCache($query);
    $_SESSION['mica_query'][$query->id] = serialize($cache);
    return $cache;
  }

  /**
   * Update the query in the cache.
   * @param MicaDatasetQuery $query
   * @return MicaDatasetQueryCache
   *   NULL if was not cached
   */
  public static function updateQuery(MicaDatasetQuery $query) {
    if (self::isCached($query)) {
      $query_cache = self::getCache($query);
      $query_cache->updateQuery($query);
      return $query_cache;
    }
    return NULL;
  }

  /**
   * @param string $term_id
   * @return MicaDatasetQueryTerm
   */
  public static function getTerm($term_id) {
    // look for the query in the cache by name
    if (isset($_SESSION['mica_query'])) {
      foreach ($_SESSION['mica_query'] as $cache) {
        $query_cache = unserialize($cache);
        if (preg_match('/^' . $query_cache->query->id . ':/', $term_id)) {
          foreach ($query_cache->getTerms() as $term) {
            if ($term->id == $term_id) {
              return $term;
            }
          }
        }
      }
    }
    return FALSE;
  }

  /**
   * @param string $dataset_id
   * @return array of MicaDatasetQuery
   */
  public static function getQueries($dataset_id) {
    $queries = array();
    if (isset($_SESSION['mica_query'])) {
      foreach ($_SESSION['mica_query'] as $cache) {
        $query_cache = unserialize($cache);
        if ($query_cache->query->dataset_id == $dataset_id) {
          $queries[] = $query_cache->query;
        }
      }
    }
    return $queries;
  }

  /**
   * @param $query_id
   * @return MicaDatasetQuery
   */
  public static function getQuery($query_id) {
    if (isset($_SESSION['mica_query'][$query_id])) {
      $query_cache = unserialize($_SESSION['mica_query'][$query_id]);
      return $query_cache->query;
    }
    return FALSE;
  }

  /**
   * Get all queries: cached and persisted.
   * @param $dataset_id
   */
  public static function getAllQueries($dataset_id) {
    $queries_persisted = self::getPersistedQueries($dataset_id);
    $queries_cached = self::getQueries($dataset_id);
    $queries = array_merge($queries_persisted, $queries_cached);
    usort($queries, array("MicaDatasetQuery", "compare"));
    return $queries;
  }

  /**
   * Load the dataset queries corresponding to the specified dataset and user id.
   * @param $dataset_id
   * @param $user_id
   * @param $published
   *
   * @return MicaDatasetQuery
   *   An array of query objects
   */
  public static function getPersistedQueries($dataset_id, $user_id = NULL, $published = NULL) {
    $q = db_select('mica_query', 'c');
    $q->addField('c', 'id');
    $q->condition('c.dataset_id', $dataset_id, '=');
    if (isset($user_id)) {
      $q->condition('c.user_id', $user_id, '=');
    }
    if (isset($published)) {
      $q->condition('c.published', $published, '=');
    }
    $result = $q->execute();

    $rval = array();
    while ($record = $result->fetchAssoc()) {
      $rval[] = $record['id'];
    }

    return !empty($rval) ? mica_query_load_multiple($rval) : array();
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
   * Update the query.
   * @param MicaDatasetQuery $query
   * @return boolean
   *   FALSE if not the same query id
   */
  public function updateQuery(MicaDatasetQuery $query) {
    // consistency check
    if ($query->id == $this->query->id) {
      $this->query = $query;
      $this->save();
      return TRUE;
    }
    return FALSE;
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
    $index = count($this->terms) + 1;
    $term->id = $this->query->id . ':' . $index;
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
    $list = $this->terms;
    usort($list, array("MicaDatasetQueryTerm", "compare"));
    return $list;
  }

  public function save() {
    $_SESSION['mica_query'][$this->query->dataset_id . ':' . $this->query->name] = serialize($this);
  }
}