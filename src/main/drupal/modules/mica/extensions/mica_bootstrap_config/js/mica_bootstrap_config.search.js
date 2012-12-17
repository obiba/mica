// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_config_search = {
    attach: function (context, settings) {

      if ($('form#search-form .input-prepend').length > 0) return;

      var label = $('form#search-form .form-item-keys label');
      var input = $('#edit-keys');

      input.wrap('<div class="input-prepend" />');
      input.before('<span class="add-on"><i class="icon-search"></i></span>');
      input.attr('placeholder', $.trim(label.html()));

      label.hide();

      $('button#edit-submit').hide();

    }
  };

}(jQuery));