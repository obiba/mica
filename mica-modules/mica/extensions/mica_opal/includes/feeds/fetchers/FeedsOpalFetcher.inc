<?php

/**
 * @file
 * Home of the FeedsHTTPFetcher and related classes.
 */

/**
 * A RESTful fetcher. Allows overriding many parts of the underlying http request.
 */
class FeedsOpalFetcher extends FeedsRestFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    // TODO: test presence of dataset_id
    return parent::fetch($source);
  }

  public function sourceForm($source_config) {
    $form = parent::sourceForm($source_config);
    // TODO: test presence of dataset_id
    if(FALSE) {
      $form['source']['#disabled'] = TRUE;
    }
    return $form;
  }
  
}
