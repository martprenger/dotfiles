[GtkTemplate(ui = "/ui/Dashboard.ui")]
public class Dashboard : Astal.Window {
  public static Dashboard instance { get; private set; }

  // [GtkChild]
  // private unowned Gtk.Calendar calendar;

  public Dashboard() {
    namespace = "Dashboard";
    title = "Dashboard";

    if (instance == null) {
      instance = this;
    } else {
      this.destroy();
    }

    this.layer = Astal.Layer.OVERLAY;
    PopupWindow.register_popup(this);

    this.notify["visible"].connect(() => {
      if (this.visible) {
        // Center at top of current monitor
        var monitor = this.get_current_monitor();
        if (monitor != null) {
          var geo = monitor.get_geometry();
          this.margin_top = geo.height / 12;
        }
      }
    });
  }

  [GtkCallback]
  public void key_released(uint keyval) {
    if (keyval == Gdk.Key.Escape) {
      this.visible = false;
    }
  }
}
