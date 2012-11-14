<?php
/**
 * @file
 * DataShiled model class
 */

class DataShieldModel {

  private $process;

  private $pipes;

  private $dataset;

  private $variables = array();

  public function __construct($dataset_node) {
    $this->dataset = $dataset_node;
  }

  public function launch($model, $glm) {
    $connectors = mica_connector_query_multiple($this->dataset->nid, TRUE);

    $params = array();
    $params['curlopts'] = array(
      'sslcert' => mica_dataset_private_file_absolute_path(PUBLIC_KEY_FILE),
      'sslkey' => mica_dataset_private_file_absolute_path(PRIVATE_KEY_FILE),
      'ssl.verifyhost' => FALSE,
      'ssl.verifypeer' => FALSE,
      'sslversion' => 3,
      'cookiejar' => mica_dataset_private_file_absolute_path('private://mycookies'),
    );
    $params['datasource'] = 'bioshare';
    $params['table'] = 'healthy-obese';
    $params['urls'] = array();
    $params['tables'] = array();
    foreach ($connectors as $connector) {
      $study = node_load($connector->study_id);
      $params['urls'][$study->title] = $study->mica_opal[LANGUAGE_NONE][0]['url'];
      $params['tables'][$study->title] = $connector->options['datasource'] . '.' . $connector->options['table'];
    }
    $params['variables'] = $this->names();
    $params['model'] = $model;
    $params['glm'] = $glm;

    $json = json_encode($params);

    $script = array('/usr/bin/Rscript');
    $script[] = DRUPAL_ROOT . '/' . drupal_get_path('module', 'mica_datashield') . '/includes/datashield.R';
    $script[] = "'$json'";
    $script[] = "2>&1";

    $script = implode(" ", $script);

    $descriptorspec = array(
      0 => array("pipe", "r"), // stdin is a pipe that the child will read from
      1 => array("pipe", "w"), // stdout is a pipe that the child will write to
      2 => array("file", "/tmp/stderr.txt", "a"), // stderr is a file to write to
    );

    $this->process = proc_open($script, $descriptorspec, $this->pipes, NULL, NULL);
  }

  public function stdout() {
    return stream_get_contents($this->pipes[1]);
  }

  public function addVariable($variable) {
    $this->variables[] = $variable;
  }

  public function hasVariable($variable) {
    return in_array($variable, $this->variables);
  }

  public function removeVariables($vids) {
    $notInVids = function($node) use ($vids) {
      return in_array($node->nid, $vids) == FALSE;
    };
    $this->variables = array_filter($this->variables, $notInVids);
  }

  public function variables() {
    return $this->variables;
  }

  public function options() {
    $options = array();
    foreach ($this->variables as $index => $variable) {
      $options[$variable->nid] = array($variable->title);
    }
    return $options;
  }

  public function names() {
    $names = array();
    foreach ($this->variables as $index => $variable) {
      $names[] = $variable->title;
    }
    return $names;
  }

  public function model() {
    $names = $this->names();
    $first = array_shift($names);
    $model = $first . " ~ ";
    $model .= implode(' + ', $names);
    return $model;
  }

}