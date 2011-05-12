(function($){
  Drupal.behaviors.search_api_ranges = {
    attach: function(context, settings){
      
      $('div.search-api-ranges-widget').each(function(){
        var widget = $(this);
        if(!widget.find('input[name=range-is-date]').val()) {
	        
	        var slider = widget.find('div.range-slider');
	        var rangeMin = widget.find('input[name=range-min]');
	        var rangeMax = widget.find('input[name=range-max]');
	        var rangeFrom = widget.find('input[name=range-from]');
	        var rangeTo = widget.find('input[name=range-to]');
	        slider.slider({
	          range: true,
	          animate: true,
	          min: parseInt(rangeMin.val()),
	          max: parseInt(rangeMax.val()),
	          values: [parseInt(rangeFrom.val()), parseInt(rangeTo.val())],
	          // on change: when clicking somewhere in the bar
	          change: function(event, ui){
	            var values = slider.slider("option", "values");
	            widget.find('input[name=range-from]').val(values[0]);
	            widget.find('input[name=range-to]').val(values[1]);
	          },
	          // on slide: when sliding with the controls
	          slide: function(event, ui){
	            var values = slider.slider("option", "values");
	            widget.find('input[name=range-from]').val(values[0]);
	            widget.find('input[name=range-to]').val(values[1]);
	          }
	        });
	        
	        rangeFrom.bind('change', function(){
	          var value = parseInt(rangeFrom.val());
	          if (value > parseInt(rangeTo.val())) {
	            value = parseInt(rangeTo.val());
	          }
	          slider.slider("option", "values", [value, parseInt(rangeTo.val())]);
	        });
	        
	        rangeTo.bind('change', function(){
	          var value = parseInt(rangeTo.val());
	          if (value < parseInt(rangeFrom.val())) {
	            value = parseInt(rangeFrom.val());
	          }
	          slider.slider("option", "values", [parseInt(rangeFrom.val()), value]);
	        });
      
        }
	        
      });
    }
  };
})(jQuery);
