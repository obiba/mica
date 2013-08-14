// Using the closure to map jQuery to $.
(function ($) {

  var MAX_VALUE = 20;

  Drupal.behaviors.mica_studies_timeline = {
    attach: function (context, settings) {
      var timelineData = createTimelineData(settings.timeline_data);
      if (timelineData != null && timelineData != undefined) createTimeline(timelineData);
    }
  };

  function createTimelineData(populations) {
    var timelineData = {};
    var timelines = [];
    var minYear = Number.MAX_VALUE;
    var maxYear = Number.MIN_VALUE;

    for (var p = 0; p < populations.length; p++) {
      var events = populations[p].events;
      var eventData = [];
      for (var e = 0; e < events.length; e++) {
        if (events[e].start_year == events[e].end_year) {
          events[e].end_year++;
        }

        minYear = Math.min(minYear, events[e].start_year);
        maxYear = Math.max(maxYear, events[e].end_year);

        eventData.push({
          id: events[e].dce_nid,
          title: events[e].dce_title,
          starting_time: events[e].start_year,
          ending_time: events[e].end_year
//          popover: events[e].popover
        });
      }

      timelines.push({
        population: populations[p].pop_title,
        color: populations[p].color,
        times: eventData
      });
    }

    timelineData.data = timelines;
    timelineData.min = minYear;
    timelineData.max = maxYear;

    return timelineData;
  }

  function createTimeline(timelineData) {
    var width = $("#timeline").width();
    var tickValues = _createTickValues(timelineData.min,timelineData.max);
    var chart = d3.timeline()
      .width(width)
      .stack()
      .tickFormat({
        format: d3.format("d"),
        tickTime: 1,
        tickNumber: 1,
        tickValues: tickValues,
        tickSize: 10
      })
      .margin({left: 15, right: 15, top: 0, bottom: 20})
      .rotateTicks(tickValues.length > MAX_VALUE ? 45 : 0)
      .click(function (d, i, datum) {
        $('#event-' + d.id).modal();
      });

    d3.select("#timeline").append("svg").attr("width", width).datum(timelineData.data).call(chart);
  }

  function _createTickValues(min, max) {
    var tickValues = [];
    var n = max - min;
    var step = n > MAX_VALUE ? 2 : 1;

    for (var i = 0; i < n; i+= step) {
      tickValues.push(i + min);
    }

    // include the last value
    tickValues.push(max);

    return tickValues;
  }

}(jQuery));