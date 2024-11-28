import { App, Astal, Gtk, Gdk } from "astal/gtk3";
import Workspaces from "./items/Workspaces";
import { spacing } from "../../lib/variables";
import Clock from "./items/Clock";
import Battery from "./items/Battery";
import Tray from "./items/Tray";
import SystemIndicators from "./items/SystemIndicators";
import Notifications from "./items/Notifications";
import KeyboardLayout from "./items/KeyboardLayout";
import Weather from "./items/Weather";
import RecordingIndicator from "./items/RecordingIndicator";

const Start = ({ gdkmonitor }: { gdkmonitor: Gdk.Monitor }) => {
  return (
    <box halign={Gtk.Align.START} spacing={spacing}>
      <Workspaces gdkmonitor={gdkmonitor} />
    </box>
  );
};

const Center = () => {
  return (
    <box spacing={spacing}>
      <box halign={Gtk.Align.CENTER} spacing={spacing}>
        <Clock />
      </box>
      <box halign={Gtk.Align.END} spacing={spacing}>
        <Weather />
      </box>
    </box>
  );
};

const End = () => {
  return (
    <box halign={Gtk.Align.END} spacing={spacing}>
      <RecordingIndicator />
      <Battery />
      <box className="bar__rounded-box" spacing={spacing / 2}>
        <Notifications />
        <Tray />
        <SystemIndicators />
      </box>
    </box>
  );
};

export default function Bar(gdkmonitor: Gdk.Monitor) {
  return (
    <window
      vexpand={true}
      className="Bar"
      namespace="bar"
      gdkmonitor={gdkmonitor}
      exclusivity={Astal.Exclusivity.EXCLUSIVE}
      anchor={
        Astal.WindowAnchor.TOP |
        Astal.WindowAnchor.LEFT |
        Astal.WindowAnchor.RIGHT
      }
      application={App}
    >
      <centerbox className="bar" valign={Gtk.Align.CENTER}>
        <Start gdkmonitor={gdkmonitor} />
        <Center />
        <End />
      </centerbox>
    </window>
  );
}
