import { App, Gtk, Gdk } from "astal/gtk3";
import { bind, execAsync, Variable } from "astal";
import Hyprland from "gi://AstalHyprland";
import BarButton from "../BarButton";
import { range } from "../../../lib/utils";
import BarItem from "../BarItem";

export default ({ gdkmonitor }: { gdkmonitor: Gdk.Monitor }) => {
  const hypr = Hyprland.get_default();
  const ws: number = 10;

  var monitorID: number = 0;
  for (var hyprMonitor of hypr.monitors) {
    if (hyprMonitor.model === gdkmonitor.model) {
      monitorID = hyprMonitor.id;
    }
  }

  /*              className={bind(
    hypr.get_monitor(monitorID),
    "activeWorkspace",
  ).as((fw) => {
    console.log(fw.id);

    return i === fw.id
      ? "bar__workspaces-indicator active"
      : "bar__workspaces-indicator";
  })} */

  const focusWorkspace = (workspaceId: number) =>
    hypr.dispatch("workspace", workspaceId.toString());

  return (
    <BarItem>
      <box spacing={8}>
        {range(ws).map((i) => {
          return (
            <button
              valign={Gtk.Align.CENTER}
              className={Variable.derive(
                [bind(hypr.get_monitor(monitorID), "activeWorkspace")],
                (active) => {
                  return `
                        ${active.id === ws ? "active" : ""}
                        workspacebutton
                      `;
                },
              )}
              onClicked={() => focusWorkspace(i)}
            >
              <label label={i.toString()} />
            </button>
          );
        })}
      </box>
    </BarItem>
  );
};
