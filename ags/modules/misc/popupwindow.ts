import App from "resource:///com/github/Aylur/ags/app.js";
import Widget from "resource:///com/github/Aylur/ags/widget.js";
import { WindowProps, Window } from "types/widgets/window";
import Gtk from "gi://Gtk?version=3.0";

type _WindowProps = WindowProps<any, unknown, Window<any, unknown>> | undefined[];

type Type = {
    name: string;
    child: any;
    showClassName?: string;
    hideClassName?: string;
};

export function Popupcloser(monitor = 0) {
    return Widget.Window({
        monitor,
        name: `popupcloser-${monitor}`,
        visible: false,
        layer: "top", // Behind AGS windows, above other popups
        resizable: false,
        anchor: ["top", "left", "bottom", "right"], // Changed "top" to "right" to cover the whole screen
        setup: (self) => {
            self.set_opacity(0);
            self.set_keep_below(true);
            // Close all popups when clicked
            self.connect("button-press-event", () => {
                App.windows.forEach((window) => {
                    if (window.name !== "popupcloser" && window.type === Gtk.WindowType.POPUP) {
                        App.closeWindow(window.name);
                    }
                });
            });
        }
    });
}

export default <T extends Type>({
    name,
    child,
    showClassName = "",
    hideClassName = "",
    ...props
}: T & Omit<_WindowProps, keyof Type>) => {
    return Widget.Window({
        name,
        visible: false,
        type: Gtk.WindowType.POPUP,
        layer: "overlay",
        resizable: true,
        ...props,
        setup: (self) => {
            self.keybind("Escape", () => {
                App.windows.forEach((window) => {
                    App.closeWindow(window.name);
                });
            });
            if (showClassName != "" && hideClassName !== "") {
                self.hook(App, (self, currentName, visible) => {
                    if (currentName === name) {
                        self.toggleClassName(hideClassName, !visible);
                    }
                });

                if (showClassName !== "" && hideClassName !== "") self.class_name = `${showClassName} ${hideClassName}`;
            }
            // Update openPopups count on window visibility changes
            self.hook(App, (self, windowName, visible) => {
                // loop to all windows in app and print name
                var openPopups = 0;
                for (const window of App.windows) {
                    if (window.type === Gtk.WindowType.POPUP) {
                        if (window.visible) {
                            openPopups++;
                        }
                    }
                }
                // get all windows that contain the popupcloser name
                const popupcloser = App.windows.filter((window) => window.name.includes("popupcloser"));
                for (const window of popupcloser) {
                    if (openPopups > 0) {
                        window.show();
                    } else {
                        window.hide();
                    }
                }
            });
        },
        child: child
    });
};
