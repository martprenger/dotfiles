public class Underlay : Astal.Window {
  public signal void closed ();

  public Underlay (Gdk.Monitor monitor) {
    this.gdkmonitor = monitor;
    this.anchor = Astal.WindowAnchor.TOP | Astal.WindowAnchor.RIGHT | Astal.WindowAnchor.LEFT | Astal.WindowAnchor.BOTTOM;
    this.exclusivity = Astal.Exclusivity.EXCLUSIVE;
    this.add_css_class ("underlay");
    this.present ();

    // Make the window fully transparent and non-focusable
    // needs to be not 0 for some reason
    this.opacity = 0.01;
    this.focusable = false;
    this.can_focus = false;
    this.visible = false;

    // Create a box to fill the window
    var box = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);
    box.hexpand = true;
    box.vexpand = true;
    this.set_child (box);

    var gesture = new Gtk.GestureClick ();
    gesture.pressed.connect (() => {
      closed ();
      PopupWindow.close_all_popups ();
    });
    box.add_controller (gesture);
  }
}
