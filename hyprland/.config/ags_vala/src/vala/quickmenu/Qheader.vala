[GtkTemplate(ui = "/ui/Qheader.ui")]
public class Qheader : Gtk.Box {
    public string user_name { get; private set; }
    public string user_image { get; private set; }
    public string battery_percentage { get; private set; }

    construct {
        user_name = Environment.get_user_name();
		user_image = Environment.get_home_dir() + "/user.png";
        var battery = AstalBattery.get_default();
        if (battery != null) {
            battery.notify["percentage"].connect(() => {
                battery_percentage = battery.percentage.to_string() + "%";
            });
            battery_percentage = battery.percentage.to_string() + "%";
        }
    }

    [GtkCallback]
    public void toggle_power_menu() {
        print("test");
        if (PowerMenu.instance != null) {
            PowerMenu.instance.visible = !PowerMenu.instance.visible;
        }

        if (QuickMenu.instance != null && PowerMenu.instance.visible) {
            QuickMenu.instance.visible = false;
        }
    }
}
