(function () {

  d3.timeline = function () {
    var DISPLAY_TYPES = ["circle", "rect"];

    var hover = function () {
      },
      click = function () {
      },
      scroll = function () {
      },
      orient = "bottom",
      width = null,
      height = null,
      tickFormat = { format: d3.time.format("%I %p"),
        tickTime: d3.time.hours,
        tickNumber: 1,
        tickSize: 6 },
      colorCycle = d3.scale.category20(),
      display = "rect",
      beginning = 0,
      ending = 0,
      margin = {left: 30, right: 30, top: 30, bottom: 30},
      stacked = false,
      rotateTicks = false,
      itemHeight = 10,
      itemMargin = 5
      ;

    function timeline(gParent) {
      var g = gParent.append("g");
      var gParentSize = gParent[0][0].getBoundingClientRect();
      var gParentItem = d3.select(gParent[0][0]);

      var yAxisMapping = {},
        maxStack = 1,
        minTime = 0,
        maxTime = 0;

      setWidth();

      // check how many stacks we're gonna need
      // do this here so that we can draw the axis before the graph
      if (stacked || (ending == 0 && beginning == 0)) {
        g.each(function (d, i) {
          d.forEach(function (datum, index) {

            // create y mapping for stacked graph
            if (stacked && Object.keys(yAxisMapping).indexOf(index) == -1) {
              yAxisMapping[index] = maxStack;
              maxStack++;
            }

            // figure out beginning and ending times if they are unspecified
            if (ending == 0 && beginning == 0) {
              datum.times.forEach(function (time, i) {
                if (time.starting_time < minTime || minTime == 0)
                  minTime = time.starting_time;
                if (time.ending_time > maxTime)
                  maxTime = time.ending_time;
              });
            }
          });
        });

        if (ending == 0 && beginning == 0) {
          beginning = minTime;
          ending = maxTime;
        }
      }

      var scaleFactor = (1 / (ending - beginning)) * (width - margin.left - margin.right);

      // draw the axis
      var xScale = d3.time.scale()
        .domain([beginning, ending])
        .range([margin.left, width - margin.right]);


      var xAxis = d3.svg.axis()
        .scale(xScale)
        .orient(orient)
        .tickFormat(tickFormat.format)
        .tickSize(tickFormat.tickSize);

      // draw axis
      g.append("g")
        .attr("class", "axis")
        .attr("transform", "translate(" + 0 + "," + (margin.top + (itemHeight + itemMargin) * maxStack) + ")")
        .call(xAxis);

      // draw the chart
      g.each(function (d, i) {
        d.forEach(function (datum, index) {
          var data = datum.times;
          var hasLabel = (typeof(datum.label) != "undefined");
          g.selectAll("svg").data(data).enter()
            .append("path")
            .attr("d", function drawRect(d, i) {
              var rectX = getXPos(d, i);
              var rectY = getStackPosition(d, i);
              var rectWidth = getWidth(d, i);
              return rightRoundedRect(rectX, rectY, rectWidth, itemHeight, 5);
            })
            .style("fill", datum.color)
            .append("title").text(function (d) {
              return d.title;
            })
            .on("mouseover", function (d, i) {
              hover(d, index, datum);
            })
            .on("click", function (d, i) {
              click(d, index, datum);
            })
          ;

          // add the label
          if (hasLabel) {
            gParent.append('text')
              .attr("class", "timeline-label")
              .attr("transform", "translate(" + 0 + "," + (itemHeight / 2 + margin.top + (itemHeight + itemMargin) * yAxisMapping[index]) + ")")
              .text(hasLabel ? datum.label : datum.id);
          }

          if (typeof(datum.icon) != "undefined") {
            gParent.append('image')
              .attr("class", "timeline-label")
              .attr("transform", "translate(" + 0 + "," + (margin.top + (itemHeight + itemMargin) * yAxisMapping[index]) + ")")
              .attr("xlink:href", datum.icon)
              .attr("width", margin.left)
              .attr("height", itemHeight);
          }

          function getStackPosition(d, i) {
//            console.log("i:", i);
//            console.log("index:", index);
            if (stacked) {
              return margin.top + (itemHeight + itemMargin) * yAxisMapping[index];
            }
            return margin.top;
          }
        });
      });

      if (width > gParentSize.width) {
        var zoom = d3.behavior.zoom().x(xScale).on("zoom", move);

        function move() {
          var x = Math.min(0, Math.max(gParentSize.width - width, d3.event.translate[0]));
          zoom.translate([x, 0]);
          g.attr("transform", "translate(" + x + ",0)");
          scroll(x * scaleFactor, xScale);
        }

        gParent
          .attr("class", "scrollable")
          .call(zoom);
      }

      if (rotateTicks) {
        g.selectAll("text")
          .attr("transform", function (d) {
            return "rotate(" + rotateTicks + ")translate("
              + (this.getBBox().width / 2 + 10) + "," // TODO: change this 10
              + this.getBBox().height / 2 + ")";
          });
      }

      var gSize = g[0][0].getBoundingClientRect();
      setHeight();

      function getXPos(d, i, index) {
//        console.log("getXPos", d, i, index);
        return margin.left + (d.starting_time - beginning) * scaleFactor;
      }

      function getWidth(d, i) {
        return (d.ending_time - d.starting_time) * scaleFactor;
      }

      function setHeight() {
        if (!height && !gParentItem.attr("height")) {
          if (itemHeight) {
            // set height based off of item height
            height = gSize.height + gSize.top - gParentSize.top;
            // set bounding rectangle height
            d3.select(gParent[0][0]).attr("height", height);
          } else {
            throw "height of the timeline is not set";
          }
        } else {
          if (!height) {
            height = gParentItem.attr("height");
          } else {
            gParentItem.attr("height", height);
          }
        }
      }

      function setWidth() {
        if (!width && !gParentSize.width) {
          throw "width of the timeline is not set";
        } else if (!(width && gParentSize.width)) {
          if (!width) {
            width = gParentItem.attr("width");
          } else {
            gParentItem.attr("width", width);
          }
        }
        // if both are set, do nothing
      }

      function drawRect(d, i) {
        var rectX = getXPos(d, i);
        var rectY = getStackPosition(d, i);
        var rectWidth = getWidth(d, i);

        return rightRoundedRect(rectX, rectY, rectWidth, itemHeight, 5);
      }

      function rightRoundedRect(x, y, width, height, radius) {
        return "M" + x + "," + y
          + "h" + (width - radius)
          + "a" + radius + "," + radius + " 0 0 1 " + radius + "," + radius
          + "v" + (height - 2 * radius)
          + "a" + radius + "," + radius + " 0 0 1 " + -radius + "," + radius
          + "h" + (radius - width)
          + "z";
      }

    }

    timeline.margin = function (p) {
      if (!arguments.length) return margin;
      margin = p;
      return timeline;
    }

    timeline.orient = function (orientation) {
      if (!arguments.length) return orient;
      orient = orientation;
      return timeline;
    };

    timeline.itemHeight = function (h) {
      if (!arguments.length) return itemHeight;
      itemHeight = h;
      return timeline;
    }

    timeline.itemMargin = function (h) {
      if (!arguments.length) return itemMargin;
      itemMargin = h;
      return timeline;
    }

    timeline.height = function (h) {
      if (!arguments.length) return height;
      height = h;
      return timeline;
    };

    timeline.width = function (w) {
      if (!arguments.length) return width;
      width = w;
      return timeline;
    };

    timeline.display = function (displayType) {
      if (!arguments.length || (DISPLAY_TYPES.indexOf(displayType) == -1)) return display;
      display = displayType;
      return timeline;
    };

    timeline.tickFormat = function (format) {
      if (!arguments.length) return tickFormat;
      tickFormat = format;
      return timeline;
    };

    timeline.hover = function (hoverFunc) {
      if (!arguments.length) return hover;
      hover = hoverFunc;
      return timeline;
    };

    timeline.click = function (clickFunc) {
      if (!arguments.length) return click;
      click = clickFunc;
      return timeline;
    };

    timeline.scroll = function (scrollFunc) {
      if (!arguments.length) return scroll;
      scroll = scrollFunc;
      return timeline;
    }

    timeline.colors = function (colorFormat) {
      if (!arguments.length) return colorCycle;
      colorCycle = colorFormat;
      return timeline;
    };

    timeline.beginning = function (b) {
      if (!arguments.length) return beginning;
      beginning = b;
      return timeline;
    };

    timeline.ending = function (e) {
      if (!arguments.length) return ending;
      ending = e;
      return timeline;
    };

    timeline.rotateTicks = function (degrees) {
      rotateTicks = degrees;
      return timeline;
    }

    timeline.stack = function () {
      stacked = !stacked;
      return timeline;
    };

    return timeline;
  };
})();