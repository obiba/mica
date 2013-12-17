/**
 * Created by root on 13/12/13.
 */

(function ($) {
  Drupal.behaviors.datatables_add_head = {
    attach: function (context, settings) {
      var $content_head = "<th colspan='2'></th>";
      $.each(settings.header_to_add, function (index, value) {
        $content_head += "<th  style='text-align: center; font-size: 0.7em'  colspan='" + value.colspan + "'>" + value.data + "</th>";
      });
      console.log($content_head);
      $("<tr role='row' style='text-align: center'>" + $content_head + "</tr>").insertBefore("#example > thead > tr:first");
    }
  }

})(jQuery);