import Gtk from "gi://Gtk?version=3.0";
import { Header } from "./widgets/Header";
import { Volume, Microphone, SinkSelector, AppMixer } from "./widgets/Volume";
import { Brightness } from "./widgets/Brightness";
import { NetworkToggle, WifiSelection } from "./widgets/Network";
import { BluetoothToggle, BluetoothDevices } from "./widgets/Bluetooth";
import { DND } from "./widgets/DND";
import { MicMute } from "./widgets/MicMute";

const Row = (toggles: Array<() => Gtk.Widget> = [], menus: Array<() => Gtk.Widget> = []) =>
    Widget.Box({
        vertical: true,
        children: [
            Widget.Box({
                homogeneous: true,
                class_name: "row horizontal",
                children: toggles.map((w) => w())
            }),
            ...menus.map((w) => w())
        ]
    });

const Settings = () =>
    Widget.Box({
        vertical: true,
        class_name: "quicksettings vertical",
        // css: quicksettings.width.bind().as(w => `min-width: ${w}px;`),
        children: [
            Header(),
            Widget.Box({
                class_name: "sliders-box vertical",
                vertical: true,
                children: [
                    Row([Volume], [SinkSelector, AppMixer]),
                    Microphone(),
                    Brightness(),
                    Row([NetworkToggle, BluetoothToggle], [WifiSelection, BluetoothDevices]),
                    Row([MicMute, DND])
                ]
            })
        ]
    });

export function SideBar() {
    return Widget.Box({
        css: "min-width: 400px;",
        orientation: Gtk.Orientation.VERTICAL,
        class_name: "sideright_main_box",
        hexpand: true,
        child: Settings()
    });
}
