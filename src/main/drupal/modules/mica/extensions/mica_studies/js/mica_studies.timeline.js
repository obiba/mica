// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_studies_timeline = {
    attach: function (context, settings) {
      var timelineData = createTimelineData(settings.timeline_data);
      if (timelineData != null && timelineData != undefined) createTimeline(timelineData);
    }
  };

  function createTimelineData(populations) {
    var timelineData = [];
    for (var p = 0; p < populations.length; p++) {
      var events = populations[p].events;
      var eventData = [];
      for (var e = 0; e < events.length; e++) {
        if (events[e].start == events[e].end) {
          events[e].end++;
        }
        eventData.push({
          id: events[e].dce_nid,
          title: events[e].dce_title,
          starting_time: events[e].start,
          ending_time: events[e].end
//          popover: events[e].popover
        });
      }
      timelineData.push({population: populations[p].pop_title, color: populations[p].color, times: eventData});
    }

    return timelineData;
  }

  function createTimeline(timelineData) {
    var width = $("#timeline").width();
    var chart = d3.timeline()
      .width(width)
      .stack()
      .tickFormat({
        format: d3.format("d"),
        tickTime: 1,
        tickNumber: 1,
        tickSize: 10
      })
      .margin({left: 15, right: 15, top: 0, bottom: 20})
      .rotateTicks(45)
      .click(function (d, i, datum) {
        $('#event-' + d.id).modal();
      });

    d3.select("#timeline").append("svg").attr("width", width).datum(timelineData).call(chart);
  }

}(jQuery));