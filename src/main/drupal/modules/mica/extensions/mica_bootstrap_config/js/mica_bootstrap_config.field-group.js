// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_config_field_group = {
    attach: function (context, settings) {
      $('a.field-group-format-title').before('<i class="icon-chevron-right"></i> ');
    }
  };

}(jQuery));