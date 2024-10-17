import popupwindow from "../misc/popupwindow.ts";
import Gtk from "gi://Gtk?version=3.0";
import Widget from "resource:///com/github/Aylur/ags/widget.js";
import { SearchAndWindows } from "./windowcontent.js";

export const overview = popupwindow({
    name: "overview",
    class_name: "sideleft",
    visible: false,
    keymode: "exclusive",
    anchor: ["top"],
    child: SearchAndWindows()
});
