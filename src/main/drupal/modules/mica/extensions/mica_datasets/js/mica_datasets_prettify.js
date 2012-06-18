// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_datasets_pretty = {
    attach: function (context, settings) {

      prettyPrint();

    }
  };

}(jQuery));
