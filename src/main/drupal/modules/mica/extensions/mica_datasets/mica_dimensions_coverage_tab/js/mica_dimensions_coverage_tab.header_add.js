(function ($) {
  Drupal.behaviors.datatables_add_head = {
    attach: function (context, settings) {
      var $content_head = "<th colspan='2'></th>";
      $.each(settings.header_to_add, function (index, value) {
        $content_head += "<th class='study-group-header-title' colspan='" + value.colspan + "'>" + value.data + "</th>";
      });
      console.log($content_head);
      $("<tr class='study-group-header'  role='row'>" + $content_head + "</tr>").insertBefore("#example > thead > tr:first");
    }
  }

})(jQuery);