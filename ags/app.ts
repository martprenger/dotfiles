import { App, Gdk, Gtk } from "astal/gtk3";
import style from "./style/main.scss";
import Bar from "./widget/Bar";
import ControlCenter from "./widget/ControlCenter";
import Notifications from "./widget/Notifications";
import NotificationsPopup from "./widget/Notifications/NotificationsPopup";
import Scrim from "./widget/Scrims/Scrim";
import OSD from "./widget/OSD";
import Powermenu from "./widget/Powermenu";
import Verification from "./widget/Powermenu/Verification";
import {
  monitorColorsChange,
  monitorDashboard,
  toggleWindow,
} from "./lib/utils";

function main() {
  const bars = new Map<Gdk.Monitor, Gtk.Widget>();
  const notificationsPopups = new Map<Gdk.Monitor, Gtk.Widget>();
  const osds = new Map<Gdk.Monitor, Gtk.Widget>();

  ControlCenter();
  Notifications();
  Scrim({ scrimType: "opaque", className: "scrim" });
  Scrim({ scrimType: "transparent", className: "transparent-scrim" });
  Verification();
  Powermenu();

  for (const gdkmonitor of App.get_monitors()) {
    bars.set(gdkmonitor, Bar(gdkmonitor));
    notificationsPopups.set(gdkmonitor, NotificationsPopup(gdkmonitor));
    osds.set(gdkmonitor, OSD(gdkmonitor));
  }

  App.connect("monitor-added", (_, gdkmonitor) => {
    bars.set(gdkmonitor, Bar(gdkmonitor));
    notificationsPopups.set(gdkmonitor, NotificationsPopup(gdkmonitor));
    osds.set(gdkmonitor, OSD(gdkmonitor));
  });

  App.connect("monitor-removed", (_, gdkmonitor) => {
    bars.get(gdkmonitor)?.destroy();
    notificationsPopups.get(gdkmonitor)?.destroy();
    osds.get(gdkmonitor)?.destroy();
    bars.delete(gdkmonitor);
    notificationsPopups.delete(gdkmonitor);
    osds.delete(gdkmonitor);
  });

  monitorColorsChange();
  monitorDashboard();
}

App.start({
  css: style,
  main: main,
});
