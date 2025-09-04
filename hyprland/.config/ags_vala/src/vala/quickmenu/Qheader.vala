[GtkTemplate(ui = "/ui/Qheader.ui")]
public class Qheader : Gtk.Box {
  public string user_name { get; private set; }
  public string user_image { get; private set; }
  public Gdk.Paintable user_image_paintable { get; private set; }
  public AstalBattery.Device battery { get; private set; }

  construct {
    user_name = Environment.get_user_name();
    user_image = Environment.get_home_dir() + "/user.png";
    try {
      var pixbuf = new Gdk.Pixbuf.from_file(user_image);
      if (pixbuf != null) {
        user_image_paintable = Gdk.Texture.for_pixbuf(pixbuf);
      }
    } catch (Error e) {
      critical("Error loading paintable: %s\n", e.message);
    }
    battery = AstalBattery.Device.get_default();
  }

  [GtkCallback]
  public string current_battery(double percentage) {
    return @"$(Math.round(percentage * 100))%";
  }

  [GtkCallback]
  public void toggle_power_menu() {
    if (PowerMenu.instance != null) {
      PowerMenu.instance.visible = !PowerMenu.instance.visible;
    }

    if (QuickMenu.instance != null && PowerMenu.instance.visible) {
      QuickMenu.instance.visible = false;
    }
  }
}
