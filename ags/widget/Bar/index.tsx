import { bind } from "astal";
import { App, Astal, Gtk, Gdk } from "astal/gtk3";
import { isDraggingWorkspace, Workspaces } from "./items/Workspaces";
import { spacing } from "../../lib/variables";
import Clock from "./items/Clock";
import Battery from "./items/Battery";
import Tray from "./items/Tray";
import SystemIndicators from "./items/SystemIndicators";
import Notifications from "./items/Notifications";
import KeyboardLayout from "./items/KeyboardLayout";
import Weather from "./items/Weather";
import RecordingIndicator from "./items/RecordingIndicator";

const Start = ({ monitor }: { monitor: Gdk.Monitor }) => {
  return (
    <box halign={Gtk.Align.START} spacing={spacing}>
      <Workspaces gdkmonitor={monitor} />
    </box>
  );
};

const Center = () => {
  return (
    <box spacing={spacing}>
      <box halign={Gtk.Align.CENTER} spacing={spacing}>
        <Clock />
      </box>
    </box>
  );
};

const End = () => {
  return (
    <box halign={Gtk.Align.END} spacing={spacing}>
      <RecordingIndicator />
      <Weather />
      <box className="bar__rounded-box" spacing={spacing / 2}>
        <Notifications />
        <Tray />
        <SystemIndicators />
      </box>
      <Battery />
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
      keymode={bind(isDraggingWorkspace).as((dragging) =>
        dragging ? Astal.Keymode.ON_DEMAND : Astal.Keymode.NONE,
      )}
    >
      <centerbox className="bar" valign={Gtk.Align.CENTER}>
        <Start monitor={gdkmonitor} />
        <Center />
        <End />
      </centerbox>
    </window>
  );
}
