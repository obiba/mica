// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_studies_timeline = {
    attach: function (context, settings) {
      console.log(settings.timeline_data);
    }
  };

}(jQuery));