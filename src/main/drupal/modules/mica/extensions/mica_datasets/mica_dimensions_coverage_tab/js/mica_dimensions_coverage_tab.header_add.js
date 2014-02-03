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

      /*
       var content_headdce = "<th colspan='2'>" + settings.dce_title + "</th>";
       $.each(settings.header_dce_to_add, function (index, value) {
       if (value.data) {
       var group_color = "group_color";
       }
       content_headdce += "<th class='study-group-header-title " + group_color + "' colspan='" + value.colspan + "'>" + value.data + "</th>";
       });

       $("<tr class='study-group-header'  role='row'>" + content_headdce + "</tr>").insertAfter("#example > thead > tr.study-group-header:first");
       */

    }
  }
// array('class'=> $is_bootstrap ? '' : 'tooltip',  'data-original-title' =>'this is tooltip', 'data-content' =>'content tooltip')
})(jQuery);