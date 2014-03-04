(function ($) {
  var oTable = null;
  Drupal.behaviors.datatables_gen = {
    attach: function (context, settings) {
      var baseUrl = Drupal.settings.BaseLocal;
      createTable(baseUrl);
    }
  };
  /*
   * Initialation of Datatables
   * */
  function createTable(baseUrl) {
    oTable = $('#example').dataTable({
      "oLanguage": {
        "sSearch": Drupal.t('Search by domains - terms :')
      },
      "bAutoWidth": false,
      "aaSorting": [],
      "sScrollY": "450px",
      "sScrollX": "100%",
      "sScrollXInner": "100%",
      "bScrollCollapse": true,
      "bLengthChange": false,
      "bPaginate": false,
      "bSort": true,
      "aoColumnDefs": [
        {"sWidth": "1%", "bVisible": false, "aTargets": [1] },
      ],
      "sDom": 'Tf<"clear">lrt',
      "oTableTools": {
        "sSwfPath": baseUrl + "/profiles/mica_distribution/modules/mica/extensions/mica_datasets/mica_dimensions_coverage/swf/copy_csv_xls_pdf.swf",
        "aButtons": ["csv" ]
        //  "aButtons": ["xls", "csv", "pdf" ]
      }
    });
    new FixedColumns(oTable, {
      "fnDrawCallback": function (left, right) {
        var oSettings = oTable.fnSettings();
        if (oSettings.aiDisplay.length == 0) {
          return;
        }

        var nGroup, nCell, iIndex, sGroup;
        var sLastGroup = "", iCorrector = 0;
        var nTrs = $('#example tbody tr');
        var iColspan = nTrs[0].getElementsByTagName('td').length;

        for (var i = 0; i < nTrs.length; i++) {
          iIndex = oSettings._iDisplayStart + i;
          sGroup = oSettings.aoData[ oSettings.aiDisplay[iIndex] ]._aData[1];

          if (sGroup != sLastGroup) {
            /* Cell to insert into main table */
            nGroup = document.createElement('tr');
            nCell = document.createElement('td');
            nCell.colSpan = iColspan;
            nCell.className = "group";
            nCell.innerHTML = "&nbsp;";
            nGroup.appendChild(nCell);
            nTrs[i].parentNode.insertBefore(nGroup, nTrs[i]);

            /* Cell to insert into the frozen columns */
            nGroup = document.createElement('tr');
            nCell = document.createElement('td');
            nCell.className = "group";
            nCell.innerHTML = sGroup;
            nGroup.appendChild(nCell);
            $(nGroup).insertBefore($('tbody tr:eq(' + (i + iCorrector) + ')', left.body)[0]);

            iCorrector++;
            sLastGroup = sGroup;
          }
        }
      },
      iLeftWidth: 350
    });
  }

})(jQuery);
