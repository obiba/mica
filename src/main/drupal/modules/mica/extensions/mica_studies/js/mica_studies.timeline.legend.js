// Using the closure to map jQuery to $.
(function ($) {
  Drupal.behaviors.mica_studies_timeline_legend = {
    attach: function (context, settings) {
      for (var i = 0; i < settings.timeline_legend_data.length; i++) {
        var pop_nid = settings.timeline_legend_data[i].pop_nid;
        var svg = settings.timeline_legend_data[i].svg;
        var h2 = $('article#node-' + pop_nid + ' header h2');
        h2.html(svg + h2.html());
      }
    }
  };


}(jQuery));