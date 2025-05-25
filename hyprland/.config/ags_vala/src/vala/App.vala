using GLib;

public class App : Astal.Application {
  static App instance;

  private HashTable<Gdk.Monitor, Bar> bars = new HashTable<Gdk.Monitor, Bar>(GLib.direct_hash, GLib.direct_equal);
  private Scss scss;

  public override void request(string request, SocketConnection conn) {
    print(@"incoming request: $request\n");
    AstalIO.write_sock.begin(conn, "response", null);
  }

  public override void activate() {
    scss = new Scss(this);

    foreach (Gdk.Monitor monitor in this.monitors) {
        var bar = new Bar(monitor);
        this.add_window(bar); // Add the window
        bars.insert(monitor, bar); // Store in the dictionary
    }
    this.add_window(new Overview());
    this.add_window(new PowerMenu());

    this.window_added.connect(on_app_window_added);
    this.window_removed.connect(on_app_window_removed);
  }

  // Handler for Gtk.Application::window-added
  private void on_app_window_added(Gtk.Application app, Gtk.Window window) {
      print(@"Window added to application: $(window.get_title() ?? window.get_name() ?? "Untitled")\n");
  }

  // Handler for Gtk.Application::window-removed
  private void on_app_window_removed(Gtk.Application app, Gtk.Window window) {
      print(@"Window removed from application: $(window.get_title() ?? window.get_name() ?? "Untitled")\n");
  }


  static int main(string[] argv) {
    App.instance = new App() { instance_name = "mui" };
    try {
      App.instance.acquire_socket();
      return App.instance.run(null);
    } catch (Error _) {
      try {
        var response = AstalIO.send_request("mui", string.joinv(" ", argv[1:]));
        print(@"$response\n");
        return 0;
      } catch (Error err) {
        printerr(err.message);
        return 1;
      }
    }
  }
}
