// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_fulltext_search = {
    attach: function (context, settings) {

      if ($('form .input-prepend').length > 0) return;

      var label = $('#edit-search-api-views-fulltext-wrapper label');
      var input = $('#edit-search-api-views-fulltext');

      input.wrap('<div class="input-prepend" />');
      input.before('<span class="add-on"><i class="icon-search"></i></span>');
      input.attr('placeholder', $.trim(label.html()));

      label.hide();

      $('.views-exposed-widgets button.form-submit').hide();
    }
  };

}(jQuery));