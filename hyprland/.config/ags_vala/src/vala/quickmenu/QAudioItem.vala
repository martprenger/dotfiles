[GtkTemplate(ui = "/ui/QAudioItem.ui")]
public class QAudioItem : Gtk.ListBoxRow {
  public AstalWp.Node endpoint { get; construct; }
  public string? app_icon_name { get; construct; } // Add this

  [GtkChild]
  private unowned Gtk.Adjustment volume_adjust;

  public QAudioItem(AstalWp.Node endpoint, string? app_icon_name = null) {
    Object(endpoint: endpoint, app_icon_name: app_icon_name);

    this.endpoint.bind_property(
                                "volume",
                                volume_adjust,
                                "value",
                                BindingFlags.SYNC_CREATE | BindingFlags.BIDIRECTIONAL
    );
  }

  [GtkCallback]
  public string fallback_icon(string? icon_name) {
    if (app_icon_name != null && app_icon_name != "") {
      return app_icon_name; // Use app icon if available
    }
    switch (icon_name) {
    case "audio-card-analog-pci":
      return "audio-card-symbolic";
    case "audio-headset-bluetooth":
      return "audio-headset-symbolic";
    default:
      return icon_name;
    }
  }
}
