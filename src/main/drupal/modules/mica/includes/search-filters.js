jQuery(document).ready(function () {

  jQuery('#edit-block').hide();

  jQuery(document).bind('click', function (e) {
    jQuery('#edit-block').hide();
  });

  jQuery('#mica-search-filters-form').bind('click', function (e) {
    e.stopPropagation();
  });

  jQuery('#edit-search-filter').bind('focus', function () {
    jQuery('#edit-block').show();
  });

  jQuery('#edit-search-filter').bind('keyup', function () {

    var criteria = jQuery('#edit-search-filter').val().toLowerCase();
    var items = jQuery('#edit-block').find('label');

    for (var i = 0; i < items.length; i++) {
      var text = items[i].innerHTML.toLowerCase().replace(/[^a-zA-Z 0-9]+/g, '').replace(/\s\s/g, ' ');

      if (text.indexOf(criteria) < 0) {
        items[i].parentNode.style.display = 'none';
      }
      else {
        items[i].parentNode.style.display = 'inherit';
      }
    }
  });
});

