import GLib from "gi://GLib";
import DateTime from "../../services/datetime.js";
import calendarServer from "../../services/ecal.js";

const events = Widget.Box({
    vertical: true,
    homogeneous: false,
    className: "events",
    vpack: "fill",
    hpack: "fill",
    children: calendarServer.bind("events").as((e) =>
        e
            .sort((a, b) => a.start - b.start)
            .map((event) => {
                const time = Widget.Label({
                    className: "time",
                    hpack: "start",
                    justification: "left",
                    wrap: true
                });

                const start = GLib.DateTime.new_from_unix_utc(event.start);

                if (event.whole_day) {
                    if (event.single_day) time.label = "O dia inteiro";
                    else {
                        const end = GLib.DateTime.new_from_unix_utc(event.end - 1);
                        time.label = `${start.format("%a %d")} - ${end.format("%a %d")}`;
                    }
                } else {
                    const end = GLib.DateTime.new_from_unix_utc(event.end);
                    if (event.single_day) time.label = `${start.format("%R")} - ${end.format("%R")}`;
                    else time.label = `${start.format("%a %d, %R")} - ${end.format("%a %d, %R")}`;
                }

                return Widget.Box({
                    vertical: true,
                    homogeneous: false,
                    hpack: "fill",
                    vpack: "fill",
                    className: "event",
                    css: event.color ? `color: ${event.color};` : null,
                    children: [
                        Widget.Label({
                            hpack: "start",
                            justification: "left",
                            wrap: true,
                            className: "summary",
                            visible: event.summary ? event.summary.length > 0 : false,
                            label: event.summary ? event.summary : ""
                        }),
                        time,

                        ...event.description.map((d) =>
                            Widget.Label({
                                hpack: "start",
                                justification: "left",
                                wrap: true,
                                label: d
                            })
                        ),

                        event.location?.length > 0
                            ? Widget.Label({
                                  className: "location",
                                  label: event.location,
                                  hpack: "start",
                                  justification: "left",
                                  wrap: true
                              })
                            : null
                    ]
                });
            })
    ),
    visible: calendarServer.bind("events").as((e) => e.length > 0)
});

export default () =>
    Widget.Box({
        vertical: true,
        class_name: "date-column vertical",
        children: [
            Widget.Box({
                children: [
                    Widget.Calendar({
                        class_name: "calendar",
                        hexpand: true,
                        hpack: "center"
                    })
                        .on("day-selected", (self) => {
                            const [y, m, d] = self.get_date();
                            calendarServer.setDate(y, m + 1, d);
                        })
                        .hook(
                            DateTime,
                            (self) => {
                                self.select_day(DateTime._day);
                            },
                            "day"
                        )
                        .hook(
                            DateTime,
                            (self) => {
                                self.select_month(DateTime._month - 1, DateTime._year);
                            },
                            "month"
                        )
                ]
            }),
            events
        ]
    });
