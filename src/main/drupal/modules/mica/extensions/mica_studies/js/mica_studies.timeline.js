// Using the closure to map jQuery to $.
(function ($) {

  var MAX_MONTHS = 300;

  Drupal.behaviors.mica_studies_timeline = {
    attach: function (context, settings) {
      var timelineData = createTimelineData(settings.timeline_data);
      if (timelineData != null && timelineData != undefined) createTimeline(timelineData);
    }
  };

  function createTimelineData(populations) {
    var bounds = _findDataBounds(populations);
    var timelineData = {};
    var timelines = [];

    for (var p = 0; p < populations.length; p++) {
      var events = populations[p].events;
      var eventData = [];

      for (var e = 0; e < events.length; e++) {
        eventData.push({
          id: events[e].dce_nid,
          title: events[e].dce_title,
          starting_time: _convertToMonths(events[e].start_year - bounds.start, events[e].start_month),
          ending_time: _convertToMonths(events[e].end_year - bounds.start, events[e].end_month)
        });
      }

      timelines.push({
        population: populations[p].pop_title,
        color: populations[p].color,
        times: eventData
      });
    }

    timelineData.data = timelines;
    timelineData.start = bounds.start;
    timelineData.min = bounds.min;
    timelineData.max = bounds.max;

    return timelineData;
  }

  function _findDataBounds(populations) {
    var startYear = Number.MAX_VALUE;
    var minYear = 0;
    var maxYear = Number.MIN_VALUE;

    for (var p = 0; p < populations.length; p++) {
      var events = populations[p].events;
      for (var e = 0; e < events.length; e++) {
        startYear = Math.min(startYear, events[e].start_year);
        maxYear = Math.max(maxYear, _convertToMonths(events[e].end_year-startYear, events[e].end_month));
      }
    }

    return {min: minYear, max: Math.ceil(maxYear/12) * 12, start: startYear};
  }

  function createTimeline(timelineData) {
    var width = $("#timeline").width();
    var chart = d3.timeline()
      .startYear(timelineData.start)
      .beginning(timelineData.min)
      .ending(timelineData.max)
      .width(width)
      .stack()
      .tickFormat({
        format: d3.format("d"),
        tickTime: 1,
        tickNumber: 1,
        tickSize: 10
      })
      .margin({left: 15, right: 15, top: 0, bottom: 20})
      .rotateTicks(timelineData.max > MAX_MONTHS ? 45 : 0)
      .click(function (d, i, datum) {
        $('#event-' + d.id).modal();
      });

    d3.select("#timeline").append("svg").attr("width", width).datum(timelineData.data).call(chart);
  }

  function _convertToMonths(year, month) {
    return 12 * parseInt(year) + parseInt(month);
  }

}(jQuery));