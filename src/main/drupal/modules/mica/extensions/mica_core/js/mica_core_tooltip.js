// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_core_tooltip = {
    attach: function (context, settings) {

      // for all elements with class 'tooltip',
      // displays the content of the elements with parent_id_tooltip id as tooltips content.

      $('.tooltip').tooltip({
        delay: 0,
        showURL: false,
        top: -30,
        opacity: 1.5,
        bodyHandler: function () {
          return $('#' + $(this).attr('id') + '_tooltip').html();
        }
      });

    }
  };

}(jQuery));
