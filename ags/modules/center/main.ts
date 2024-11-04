import popupwindow from "../misc/popupwindow.ts";
import NotificationColumn from "./NotificationColumn";
import DateColumn from "./DateColumn";

const Center = () =>
    Widget.Box({
        class_name: "center",
        vexpand: false,
        children: [NotificationColumn(), Widget.Separator({ orientation: 1 }), DateColumn()]
    });

export const center = popupwindow({
    name: "center",
    class_name: "center_popupwindow",
    visible: false,
    keymode: "exclusive",
    child: Center(),
    anchor: ["top"]
});
