import { App, Gdk, Gtk } from "astal/gtk3";
import style from "./style/main.scss";
import Bar from "./widget/Bar";
import {
  monitorColorsChange,
  monitorDashboard,
  toggleWindow,
} from "./lib/utils";

function main() {
  const bars = new Map<Gdk.Monitor, Gtk.Widget>();

  for (const gdkmonitor of App.get_monitors()) {
    bars.set(gdkmonitor, Bar(gdkmonitor));
  }

  App.connect("monitor-added", (_, gdkmonitor) => {
    bars.set(gdkmonitor, Bar(gdkmonitor));
  });

  App.connect("monitor-removed", (_, gdkmonitor) => {
    bars.get(gdkmonitor)?.destroy();
    bars.delete(gdkmonitor);
  });

  monitorColorsChange();
  monitorDashboard();
}

App.start({
  css: style,
  main: main,
});
