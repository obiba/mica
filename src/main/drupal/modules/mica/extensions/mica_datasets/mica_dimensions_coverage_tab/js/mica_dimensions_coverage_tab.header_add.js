(function ($) {
  Drupal.behaviors.datatables_add_head = {
    attach: function (context, settings) {
      var content_headstudy = "<th colspan='2'>" + settings.study_title + "</th>";
      $.each(settings.header_study_to_add, function (index, value) {
        if (value.data) {
          var group_color = "group_color";
        }
        content_headstudy += "<th class='study-group-header-title " + group_color + "' colspan='" + value.colspan + "'>" + value.data + "</th>";
      });

      $("<tr class='study-group-header'  role='row'>" + content_headstudy + "</tr>").insertBefore("#example > thead > tr:first");
    }
  }

})(jQuery);