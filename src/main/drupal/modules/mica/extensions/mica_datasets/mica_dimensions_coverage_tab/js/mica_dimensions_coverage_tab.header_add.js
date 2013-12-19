(function ($) {
  Drupal.behaviors.datatables_add_head = {
    attach: function (context, settings) {
      var content_head = "<th colspan='2'>" + settings.study_title + "</th>";
      $.each(settings.header_to_add, function (index, value) {
        if (value.data) {
          var group_color = "group_color";
          console.log(value.data);
        }
        content_head += "<th class='study-group-header-title " + group_color + "' colspan='" + value.colspan + "'>" + value.data + "</th>";
      });

      $("<tr class='study-group-header'  role='row'>" + content_head + "</tr>").insertBefore("#example > thead > tr:first");
    }
  }

})(jQuery);