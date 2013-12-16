/**
 * Created by root on 13/12/13.
 */

(function ($) {
  Drupal.behaviors.datatables_gen = {
    attach: function (context, settings) {
      // var settings = Drupal.settings.mica_dimensions_coverage_tab[selector];
      //$('#dynamic').html('<table cellpadding="0" cellspacing="0" border="0" class="display" id="example" width="300%"></table>');
      var oTable = $('#example').dataTable({
        "aaSorting": [],
        "sScrollY": "450px",
        "sScrollX": "110%",
        "sScrollXInner": "1200px",
        "bScrollCollapse": true,
        "bPaginate": false,
        "aaSortingFixed": [
          [1, 'asc']
        ],
        "aoColumnDefs": [
          { "bVisible": false, "aTargets": [1] }
        ],
        "sDom": 'TC<"clear">lfrtip',
        "oTableTools": {
          "sSwfPath": "../profiles/mica_distribution/libraries/datatables/swf/copy_csv_xls_pdf.swf",
          "aButtons": ["xls", "csv", "pdf" ]
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
  }

})(jQuery);