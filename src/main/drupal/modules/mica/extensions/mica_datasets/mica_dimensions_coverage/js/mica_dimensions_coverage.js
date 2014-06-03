(function ($) {
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
    var    oTable = $('#example').DataTable({
      stateSave: true,
      oLanguage: {
        sSearch: Drupal.t('Search by domains - terms :')
      },
      columnDefs: [
        { "width": '30%', aTargets: [ 0 ]}
      ],
      aaSorting: [],
      scrollY: 700,
      scrollX:        true,
      scrollCollapse: true,
      sScrollXInner: "150%",
      bScrollCollapse: true,
      bLengthChange: false,
      bPaginate: false,
      bSort: false,

      sDom: 'Tf<"clear">lrt',
      oTableTools: {
        sSwfPath: libPath + "/extensions/TableTools/swf/copy_csv_xls_pdf.swf",
        aButtons: ["csv" ]
      }
    });
    new $.fn.dataTable.FixedColumns(oTable);

  }
})(jQuery);