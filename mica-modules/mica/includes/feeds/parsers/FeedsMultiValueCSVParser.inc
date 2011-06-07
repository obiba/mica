<?php
// $Id$

/**
 * Extends FeedsCSVParser to allow cells to contain multiple values, separated by
 * a customizable character string.
 */

class FeedsMultiValueCSVParser extends FeedsCSVParser {
  // $source_config is an internal variable to share info between parse and parseItems.
  protected $source_config = NULL;

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    // Save source configuration so it's available within parseItems.
    $this->source_config = $source->getConfigFor($this);
    // Otherwise, use same processing as FeedsCSVParser.
    return parent::parse($source, $fetcher_result);
  }

  /**
   * Parse all of the items from the CSV.
   *
   * @param ParserCSV $parser
   * @param ParserCSVIterator $iterator
   * @return
   *   An array of rows of the CSV keyed by the column names previously set
   *
   * This is where the real differences from FeedsCSVParser are implemented --
   * i.e., where multiple values in a cell are split into an array.
   */
  protected function parseItems(ParserCSV $parser, ParserCSVIterator $iterator, $start = 0, $limit = 0) {
    // Use FeedsCSVParser for basic processing
    $rows = parent::parseItems($parser, $iterator, $start, $limit);

    // Get the configuration information that was saved in parse.
    $config = $this->source_config ? $this->source_config : $this->config;
    $separator = trim($config['multivalue_separator'], ' ');
    $separator_length = strlen($separator);
    // If separator is empty, don't bother to do any special processing.
    if (!$separator_length) {
      return $rows;
    }
    // Create the regexp pattern corresponding to this separator
    $separator_pattern = '/\s*' . preg_quote($separator, '/') . '\s*/';
    $trim_spaces = $config['multivalue_trim_spaces'];

    foreach ($rows as &$row) {
      foreach ($row as &$cell) {
        // Only process cells that start with the separator
        if ($cell && is_string($cell) && strpos($cell, $separator) !== false) {
          // Strip off the initial separator
          //$cell = substr($cell, $separator_length);
          if ($trim_spaces) {
            // If spaces are being trimmed, use preg_split.
            $cell = preg_split($separator_pattern, ltrim($cell));
          }
          else {
            // If spaces are not being trimmed, use explode since it's faster.
            $cell = explode($separator, $cell);
          }
          $cell = (count($cell) == 1) ? array_shift($cell) : $cell;
        }
      }
    }
    return $rows;
  }

  /**
   * Define defaults
   */
  public function sourceDefaults() {
    // Get standard CSV defaults.
    $defaults = parent::sourceDefaults();
    // Add multivalue defaults.
    $defaults['multivalue_separator'] = $this->config['multivalue_separator'];
    $defaults['multivalue_trim_spaces'] = $this->config['multivalue_trim_spaces'];
    return $defaults;
  }

  /**
   * Source form.
   */
  public function sourceForm($source_config) {
    // Get standard CSV form.
    $form = parent::sourceForm($source_config);
    // Add multivalue selectors to form.
    $form['multivalue_separator'] = array(
      '#type' => 'textfield',
      '#maxlength' => 5,
      '#size' => 3,
      '#title' => t('Multivalue Separator'),
      '#description' => t('The character(s) that are used to separate multiple values within cells.  Any cell containing multiple values must also start with this set of characters.'),
      '#default_value' => isset($source_config['multivalue_separator']) ? $source_config['multivalue_separator'] : '||',
    );
    $form['multivalue_trim_spaces'] = array(
      '#type' => 'checkbox',
      '#title' => t('Trim Spaces'),
      '#description' => t('Check if spaces should be trimmed around the multivalue separator.'),
      '#default_value' => isset($source_config['multivalue_trim_spaces']) ? $source_config['multivalue_trim_spaces'] : TRUE,
    );
    return $form;
  }

  /**
   * Define default configuration.
   */
  public function configDefaults() {
    // Get standard CSV defaults.
    $defaults = parent::configDefaults();
    // Add multivalue defaults.
    $defaults['multivalue_separator'] = '||';
    $defaults['multivalue_trim_spaces'] = TRUE;
    return $defaults;
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form_state) {
    // Get standard CSV form.
    $form = parent::configForm($form_state);
    // Add multivalue selectors to form.
    $form['multivalue_separator'] = array(
      '#type' => 'textfield',
      '#maxlength' => 5,
      '#size' => 3,
      '#title' => t('Multivalue Separator'),
      '#description' => t('The character(s) that are used to separate multiple values within cells.  Any cell containing multiple values must also start with this set of characters.'),
      '#default_value' => $this->config['multivalue_separator'],
    );
    $form['multivalue_trim_spaces'] = array(
      '#type' => 'checkbox',
      '#title' => t('Trim Spaces'),
      '#description' => t('Check if spaces should be trimmed around the multivalue separator.'),
      '#default_value' => $this->config['multivalue_trim_spaces'],
    );
    return $form;
  }

  /**
   * Add validation to configuration form (add to parent's configFormValidate)
   */
  public function configFormValidate(&$values) {
    $this->SeparatorValidate($values);
    parent::configFormValidate($values);
  }

  /**
   * Add validation to source form (add to parent's sourceFormValidate)
   */
  public function sourceFormValidate(&$values) {
    $this->SeparatorValidate($values);
    parent::sourceFormValidate($values);
  }

  /**
   * Validate user input for multivalue_separator
   */
  public function SeparatorValidate(&$values) {
    $delimiter = $values['delimiter'];
    $delimiter = ($delimiter == 'TAB') ? "\t" : $delimiter;
    $separator = $values['multivalue_separator'];
    // Make sure that delimiter and multivalue_separator are different.
    if (strpos($separator, $delimiter) !== FALSE) {
      form_set_error('multivalue_separator', t('The multivalue separator cannot contain the same character as the CSV delimiter.'));
    }
    // Make sure that " is not part of the multivalue_separator.
    if (strpos($separator, '"') !== FALSE) {
      form_set_error('multivalue_separator', t('The multivalue separator cannot contain a quotation mark (&quot;).'));
    }
    // Make sure that spaces are not part of the multivalue_separator
    if (strpos($separator, ' ') !== FALSE) {
      form_set_error('multivalue_separator', t('The multivalue separator cannot contain spaces.'));
    }
    // N.B. opting to not do any extra sanitizing of the user input:
    // only place where the characters are displayed on a web page are within the
    // form's text box, which already does necessary cleanup.
  }
}