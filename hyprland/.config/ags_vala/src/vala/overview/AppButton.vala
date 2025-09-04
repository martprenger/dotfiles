
[GtkTemplate(ui = "/ui/AppButton.ui")]
public class AppButton : Gtk.ListBoxRow {
  public AstalApps.Application app { get; construct; }
  public double score { get; set; }

  [GtkCallback]
  public void clicked() {
    activated();
  }

  [GtkCallback]
  public void activated() {
    app.launch();
    if (Overview.instance != null) {
      Overview.instance.visible = false;
    }
  }

  public AppButton(AstalApps.Application app) {
    Object(app: app);
  }
}
