[GtkTemplate(ui = "/ui/QuickMenu.ui")]
public class QuickMenu : Astal.Window {
    public static QuickMenu instance { get; private set; }

    [GtkChild]
    private unowned Qheader header;

    construct {
        if (instance == null) {
            instance = this;
        } else {
            this.destroy();
        }

        this.anchor = TOP | RIGHT;
    }

    [GtkCallback]
    public void key_released(uint keyval) {
        if (keyval == Gdk.Key.Escape) {
            this.visible = false;
        }
    }
}
