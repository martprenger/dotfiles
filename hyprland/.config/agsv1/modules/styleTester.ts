import popupwindow from "./misc/popupwindow.ts";

const WINDOW_NAME: string = "styleTester";

const colors = [
    ["background", "surface", "surfaceDim", "surfaceBright"],
    ["surfaceContainerLowest", "surfaceContainerLow", "surfaceContainer"],
    ["surfaceContainerHigh", "surfaceContainerHighest"],
    ["surfaceVariant", "inverseSurface", "surfaceTint"],
    ["layer0", "layer0Hover", "layer0Active"],
    ["layer1", "layer1Hover", "layer1Active"],
    ["layer2", "layer2Hover", "layer2Active"],
    ["layer3", "layer3Hover", "layer3Active"]
];

// Create columns
const columns = colors.map((colorChunk) =>
    Widget.Box({
        css: `min-width: 200px;`,
        class_name: "column",
        vertical: false,
        children: colorChunk.map((color) =>
            Widget.Box({
                class_name: `color_${color} color_box`,
                child: Widget.Label({ label: color })
            })
        )
    })
);

export const styleTester = popupwindow({
    name: WINDOW_NAME,
    class_name: "styleTester",
    visible: false,
    keymode: "exclusive",

    child: Widget.Box({
        children: [
            Widget.Box({
                vertical: true,
                children: [
                    Widget.Label({ label: "Style Tester" }),
                    Widget.Box({
                        class_name: "buttons",
                        children: [
                            Widget.Button({
                                child: Widget.Label({ label: "Button 1" })
                            }),
                            Widget.Button({
                                child: Widget.Label({ label: "Button 2" })
                            }),
                            Widget.Button({
                                child: Widget.Label({ label: "Button 3" })
                            })
                        ]
                    }),
                    Widget.Box({
                        class_name: "sliders",
                        children: [
                            Widget.Slider({
                                min: 0,
                                max: 100,
                                draw_value: false,
                                hexpand: true,
                                vpack: "end"
                            }),
                            Widget.Slider({
                                min: 0,
                                max: 100,
                                draw_value: false,
                                hexpand: true,
                                vpack: "end"
                            }),
                            Widget.Slider({
                                min: 0,
                                max: 100,
                                draw_value: false,
                                hexpand: true,
                                vpack: "end"
                            })
                        ]
                    })
                ]
            }),
            Widget.Box({
                class_name: "colors_widget",
                vertical: true,
                child: Widget.Box({
                    vertical: true,
                    children: columns
                })
            })
        ]
    }),
    anchor: ["top", "right", "bottom", "left"]
});
