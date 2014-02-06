(function ($) {
  Drupal.behaviors.datatables_add_head = {
    attach: function (context, settings) {
      var oblic_header = '<div id="square"><span id="study">' + Drupal.t('Studies') + '</span><span id="dce">' + Drupal.t('DCE') + '</span><span id="domain">' + Drupal.t('Domains') + '</span></div><div id="line2"></div> <div id="line"></div>';
      var content_headstudy = "<th colspan='2' class='noborderhead' ></th>";
      $.each(settings.header_study_to_add, function (index, value) {
        if (value.data) {
          var group_color = "group_color";
        }
        content_headstudy += "<th class='study-group-header-title " + group_color + "' colspan='" + value.colspan + "'>" + value.data + "</th>";
      });
      $("<tr class='study-group-header'  role='row'>" + content_headstudy + "</tr>").insertBefore("#example > thead > tr:first");
      $(oblic_header).insertBefore("#example");
    }
  }
})(jQuery);