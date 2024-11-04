import icons from "lib/icons";
import powermenu, { Action } from "services/powermenu";
import { OpenSettings } from "apps/settings/main.ts";

const battery = await Service.import("battery");

const SysButton = (action: Action) =>
    Widget.Button({
        class_name: "button",
        vpack: "center",
        child: Widget.Icon(icons.powermenu[action]),
        on_clicked: () => {
            App.closeWindow("sideright");
            powermenu.action(action);
        }
    });

export const Header = () =>
    Widget.Box(
        { class_name: "header horizontal button-row" },
        Widget.Box({
            vertical: true,
            vpack: "center",
            children: [
                Widget.Box({
                    class_name: "header-battery",
                    visible: battery.bind("available"),
                    children: [
                        Widget.Icon({ icon: battery.bind("icon_name") }),
                        Widget.Label({ label: battery.bind("percent").as((p) => `  ${Math.floor(p)}%`) })
                    ]
                })
            ]
        }),
        Widget.Box({ hexpand: true }),
        Widget.Button({
            class_name: "button",
            vpack: "center",
            child: Widget.Icon(icons.ui.settings),
            on_clicked: () => {
                App.closeWindow("sideright");
                OpenSettings();
            }
        }),
        SysButton("logout"),
        SysButton("shutdown")
    );
