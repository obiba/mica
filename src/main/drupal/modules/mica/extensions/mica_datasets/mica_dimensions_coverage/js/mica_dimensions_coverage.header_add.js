(function ($) {
    Drupal.behaviors.datatables_add_head = {
        attach: function (context, settings) {
            /*Need to be fixed if loged the lables are not correctly displayed */
            var content_headstudy = "<th  class='noborderhead' ></th>";
            $.each(settings.header_study_to_add, function (index, value) {
                if (value.data) {
                    var group_color = "group_color";
                }
                content_headstudy += "<th class='study-group-header-title " + group_color + "' colspan='" + value.colspan + "'>" +
                    value.data + "</th>";
            });
            $("<tr class='study-group-header'  role='row'>" + content_headstudy + "</tr>").insertBefore("#example > thead > tr:first");
        }
    }
})(jQuery);