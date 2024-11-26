import popupwindow from "../misc/popupwindow.ts";
import powermenu, { type Action } from "services/powermenu";
import icons from "lib/icons";
import type Gtk from "gi://Gtk?version=3.0";

const SysButton = (action: Action, label: string) =>
    Widget.Button({
        on_clicked: () => powermenu.action(action),
        child: Widget.Box({
            vertical: true,
            class_name: "system-button",
            children: [
                Widget.Icon(icons.powermenu[action]),
                Widget.Label({
                    label
                })
            ]
        })
    });

export const Powermenu = popupwindow({
    name: "powermenu",
    visible: false,
    keymode: "exclusive",
    child: Widget.Box({
        class_name: "powermenu horizontal",
        children: [
            SysButton("shutdown", "Shutdown"),
            SysButton("logout", "Log Out"),
            SysButton("reboot", "Reboot"),
            SysButton("sleep", "Sleep")
        ]
    })
});
