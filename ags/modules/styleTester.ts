import { PI_4 } from "types/@girs/glib-2.0/glib-2.0.d.cts";
import popupwindow from "./misc/popupwindow.ts";

const WINDOW_NAME: string = "styleTester";

const colors = [
    "primary_paletteKeyColor",
    "secondary_paletteKeyColor",
    "tertiary_paletteKeyColor",
    "neutral_paletteKeyColor",
    "neutral_variant_paletteKeyColor",
    "background",
    "onBackground",
    "foreground",
    "surface",
    "surfaceDim",
    "surfaceBright",
    "surfaceContainerLowest",
    "surfaceContainerLow",
    "surfaceContainer",
    "surfaceContainerHigh",
    "surfaceContainerHighest",
    "onSurface",
    "surfaceVariant",
    "onSurfaceVariant",
    "inverseSurface",
    "inverseOnSurface",
    "outline",
    "outlineVariant",
    "shadow",
    "scrim",
    "surfaceTint",
    "primary",
    "onPrimary",
    "primaryContainer",
    "onPrimaryContainer",
    "inversePrimary",
    "secondary",
    "onSecondary",
    "secondaryContainer",
    "onSecondaryContainer",
    "tertiary",
    "onTertiary",
    "tertiaryContainer",
    "onTertiaryContainer",
    "error",
    "onError",
    "errorContainer",
    "onErrorContainer",
    "primaryFixed",
    "primaryFixedDim",
    "onPrimaryFixed",
    "onPrimaryFixedVariant",
    "secondaryFixed",
    "secondaryFixedDim",
    "onSecondaryFixed",
    "onSecondaryFixedVariant",
    "tertiaryFixed",
    "tertiaryFixedDim",
    "onTertiaryFixed",
    "onTertiaryFixedVariant"
];

// Split colors into chunks of 20
const chunkedColors = [];
for (let i = 0; i < colors.length; i += 4) {
    chunkedColors.push(colors.slice(i, i + 4));
}

// Create columns
const columns = chunkedColors.map((colorChunk) =>
    Widget.Box({
        css: `min-width: 200px;`,
        class_name: "column",
        vertical: false,
        children: colorChunk.map((color) =>
            Widget.Box({
                class_name: `color_${color}`,
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
