[GtkTemplate(ui = "/ui/Bar.ui")]
class Bar : Astal.Window {
  private AstalHyprland.Hyprland _hyprland;
  private AstalHyprland.Monitor _monitor;

  public string clock { get; set; }
  public AstalBattery.Device battery { get; private set; }
  public AstalWp.Endpoint speaker { get; private set; }
  public AstalNetwork.Network network { get; private set; }

  public bool mpris_visible { get; set; }
  public string mpris_label { get; set; }
  public string mpris_art { get; set; }
  public string power_profile_icon { get; set; }
  public bool bluetooth_visible { get; set; }

  AstalIO.Time timer;
  AstalMpris.Player player;
  HashTable<string, TrayButton> tray_items;

  [GtkChild] private unowned Astal.Bin workspaces;

  [GtkChild] unowned Gtk.Box traybox;

  public Bar(Gdk.Monitor monitor) {
    gdkmonitor = monitor;
    anchor = TOP | LEFT | RIGHT;
    exclusivity = EXCLUSIVE;
    namespace = "bar";

    add_css_class("Bar");
    present();

    // Hyprland
    _hyprland = AstalHyprland.Hyprland.get_default();
    foreach (AstalHyprland.Monitor hyprMonitor in _hyprland.monitors) {
      if (monitor.get_connector() == hyprMonitor.name) {
        _monitor = hyprMonitor;
      }
    }
    workspaces.child = new Workspaces(_hyprland, _monitor);

    battery = AstalBattery.Device.get_default();
    speaker = AstalWp.get_default().audio.default_speaker;
    network = AstalNetwork.get_default();

    // clock
    timer = AstalIO.Time.interval(1000, null);
    timer.now.connect(() => {
      clock = new DateTime.now_local().format("%a %d %b, %H:%M");
    });

    // tray
    var tray = AstalTray.get_default();
    tray_items = new HashTable<string, TrayButton> (str_hash, str_equal);
    tray.item_added.connect(on_tray_item_added);
    tray.item_removed.connect(on_tray_item_removed);
  }

  void on_tray_item_added(AstalTray.Tray tray, string id) {
    var button = new TrayButton(id);
    tray_items.set(id, button);
    traybox.append(button);
  }

  void on_tray_item_removed(string id) {
    var button = tray_items.get(id);
    traybox.remove(button);
    tray_items.remove(id);
  }

  public override void dispose() {
    var tray = AstalTray.get_default();
    tray.item_added.disconnect(on_tray_item_added);
    tray.item_removed.disconnect(on_tray_item_removed);

    foreach (var button in tray_items.get_values()) {
      button.dispose();
    }

    timer.cancel();
    timer.dispose();
    player.dispose();
    base.dispose();
  }

  [GtkCallback]
  public string current_battery(double percentage) {
    return @"$(Math.round(percentage * 100))%";
  }

  [GtkCallback]
  public void toggleQuickMenu() {
    QuickMenu.instance.visible = !QuickMenu.instance.visible;
  }

  public string network_icon {
    get {
      network = AstalNetwork.get_default();
      if (network.wired != null && network.wired.icon_name != null) {
        return network.wired.icon_name;
      } else if (network.wifi != null && network.wifi.icon_name != null) {
        return network.wifi.icon_name;
      } else {
        return "network-offline-symbolic";
      }
    }
  }

  class TrayButton : Astal.Bin {
    AstalTray.TrayItem item;
    Gtk.Popover popover;
    Gtk.Image image;

    public TrayButton(string id) {
      var tray = AstalTray.get_default();
      item = tray.get_item(id);

      image = new Gtk.Image();
      popover = new Gtk.PopoverMenu.from_model(item.menu_model);

      child = new Gtk.MenuButton() {
        child = image,
        popover = popover,
      };

      item.bind_property("gicon", image, "gicon", BindingFlags.SYNC_CREATE);
      popover.insert_action_group("dbusmenu", item.action_group);
      item.notify["action-group"].connect(on_action_group);
    }

    void on_action_group() {
      popover.insert_action_group("dbusmenu", item.action_group);
    }

    public override void dispose() {
      item.notify.disconnect(on_action_group);
    }
  }

  [GtkCallback]
  public void toggleDashboard() {
    if (Dashboard.instance != null) {
      Dashboard.instance.visible = !Dashboard.instance.visible;
    }
  }
}
