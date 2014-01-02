(function ($) {
  Drupal.behaviors.datatables_block_table_refresh = {
    attach: function (context, settings) {
      /*Multiselect event populate DCE Multiselect Field */
      table = {
        initial_page: Drupal.behaviors.datatables_gen
      };

      /*Multiselect event populate Dataset Multiselect Field */
      $("#edit-dataset").multiselect({
        click: function (event, ui) {
          retrivecheckeddcebox(event, ui);
        },
        optgrouptoggle: function (event, ui) {
          retrivecheckeddcebox(event, ui);
        },
        checkAll: function () {
          retrivecheckeddcebox();
        },
        uncheckAll: function () {
          retrivecheckeddcebox();
        }
      });

      /**********Ajax function to populate Multiselect Dataset options *****/
//      function retrivecheckeddcebox(event, ui) {
//        var dataset = [];
//        dataset.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
//        var post = "&dataset=" + dataset;
//
//        $.ajax({
//          'url': 'content/datasets-domains-coverage-table-refrech-table-block',
//          'type': 'POST',
//          'dataType': 'json',
//          'data': post,
//          'success': function (data) {
//            $("#table-refresh").html(data);
//
//          },
//          beforeSend: function () {
//            /*
//             $(document).ready(function () {
//             $(#status).attr("innerHTML","Loading....");
//             });
//             */
//          },
//          'error': function (data) {
//          }
//        });
//
//        table.initial_page.refreshTable();
//      }

      /******************************************************/


    }
  }
})(jQuery);