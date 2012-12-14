// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_config_login = {
    attach: function (context, settings) {
      $('form#user-login input').wrap('<div class="input-prepend" />');
      $('#edit-name').before('<span class="add-on"><i class="icon-user"></i></span>');
      $('#edit-pass').before('<span class="add-on"><i class="icon-lock"></i></span>');
    }
  };

}(jQuery));