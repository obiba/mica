(function ($) {
  var oTable = null;
  Drupal.behaviors.datatables_gen = {
    attach: function (context, settings) {
      var libPath = Drupal.settings.libPath;
      createTable(libPath);
    }
  };

  /*
   * Initialation of Datatables
   * */
  function createTable(libPath) {
    oTable = $('#example').dataTable({
      "stateSave": true,
      "oLanguage": {
        "sSearch": Drupal.t('Search by domains - terms :')
      },
      "bAutoWidth": false,
      "aaSorting": [],
      "sScrollY": "700px",
      "sScrollX": "100%",
      "sScrollXInner": "200%",
      "bScrollCollapse": true,
      "bLengthChange": false,
      "bPaginate": false,
      "bSort": false,

      "sDom": 'Tf<"clear">lrt',
      "oTableTools": {
        "sSwfPath": libPath + "/extras/TableTools/media/swf/copy_csv_xls_pdf.swf",
        "aButtons": ["csv" ]
      }
    });
    new FixedColumns(oTable, {
      "sLeftWidth": "relative",
      "iLeftWidth": 30,// percentage,
      "sHeightMatch": "none"
    });

  }
})(jQuery);
