using GLib;

public class App : Astal.Application {
  static App instance;

  private Scss scss;

  public override void request(string request, SocketConnection conn) {
    print(@"incoming request: $request\n");
    AstalIO.write_sock.begin(conn, "response", null);
  }

  public override void activate() {
    scss = new Scss(this);

    foreach (Gdk.Monitor monitor in this.monitors) {
      this.add_window(new Bar(monitor));
    }
  }



  static int main(string[] argv) {
    App.instance = new App() { instance_name = "simple-bar" };
    try {
      App.instance.acquire_socket();
      return App.instance.run(null);
    } catch (Error _) {
      try {
        var response = AstalIO.send_request("simple-bar", string.joinv(" ", argv[1:]));
        print(@"$response\n");
        return 0;
      } catch (Error err) {
        printerr(err.message);
        return 1;
      }
    }
  }
}
