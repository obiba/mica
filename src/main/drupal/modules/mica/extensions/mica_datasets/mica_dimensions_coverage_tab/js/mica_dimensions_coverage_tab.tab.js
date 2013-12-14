/**
 * Created by root on 13/12/13.
 */

(function ($) {
  Drupal.behaviors.datatables_gen = {
    attach: function (context, settings) {
      // var settings = Drupal.settings.mica_dimensions_coverage_tab[selector];
      $('#dynamic').html('<table cellpadding="0" cellspacing="0" border="0" class="display" id="example"></table>');
      $('#example').dataTable({
        "sAjaxSource": settings.test_array_header
      });
    }
  }

})(jQuery);