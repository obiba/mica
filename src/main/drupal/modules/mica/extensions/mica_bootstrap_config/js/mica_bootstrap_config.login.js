// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_config_login = {
    attach: function (context, settings) {
      if ($('form#user-login').length > 0 && $('form#user-login .input-prepend').length == 0) {
        $('form#user-login input').wrap('<div class="input-prepend" />');
        $('form#user-login .form-item-name input').before('<span class="add-on"><i class="icon-user"></i></span>');
        $('form#user-login .form-item-pass input').before('<span class="add-on"><i class="icon-lock"></i></span>');
      }

      if ($('form#user-register-form').length > 0 && $('form#user-register-form .input-prepend').length == 0) {
        $('form#user-register-form input').wrap('<div class="input-prepend" />');
        $('form#user-register-form .form-item-name input').before('<span class="add-on"><i class="icon-user"></i></span>');
        $('form#user-register-form .form-item-mail input').before('<span class="add-on"><i class="icon-envelope"></i></span>');
      }
    }
  };

}(jQuery));