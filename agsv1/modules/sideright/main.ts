import popupwindow from "../misc/popupwindow.js";
import { SideBar } from "./sidebar.ts";

export const WINDOW_NAME = "sideright";

export const sideright = popupwindow({
    name: WINDOW_NAME,
    class_name: "sideright",
    visible: false,
    keymode: "exclusive",
    child: SideBar(),
    anchor: ["top", "right", "bottom"]
    // css: "min-width: 443px;"
});
