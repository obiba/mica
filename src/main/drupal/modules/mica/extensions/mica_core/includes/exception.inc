<?php
/**
 * @file
 * Mica Exception definition.
 */

/**
 * Represents an exception or error that occurred in some part of the Mica
 * framework.
 */
class MicaException extends Exception {

  /**
   * Creates a new MicaException.
   *
   * @param $message
   *   A string describing the cause of the exception.
   */
  public function __construct($message = NULL) {
    if (!$message) {
      $message = t('An error occcurred in the Mica framework.');
    }
    parent::__construct($message);
  }

}
