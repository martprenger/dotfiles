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
    this.add_window(new QuickMenu());

    Gdk.Display? default_display = Gdk.Display.get_default();
    if (default_display == null) {
        print("Error: Could not get the default display.\n");
        return;
    }

    // default_display.monitor_added.connect((display, monitor) => {
    //     print("Monitor added: %s (%d x %d at %d, %d)\n",
    //           monitor.get_model(),
    //           monitor.get_width(),
    //           monitor.get_height(),
    //           monitor.get_x(),
    //           monitor.get_y());
    // });

    // default_display.monitor_removed.connect((display, monitor) => {
    //     print("Monitor removed: %s (%d x %d at %d, %d)\n",
    //           monitor.get_model(),
    //           monitor.get_width(),
    //           monitor.get_height(),
    //           monitor.get_x(),
    //           monitor.get_y());
    // });
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
