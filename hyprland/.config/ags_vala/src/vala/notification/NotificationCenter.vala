[GtkTemplate(ui = "/ui/NotificationCenter.ui")]
class NotificationCenter : Astal.Window {
  public static NotificationCenter instance { get; private set; }

 	private AstalNotifd.Notifd _notifd;
	private Gtk.ListBox _notif_list_box;
	private GSound.Context _scontext;
	private uint _notif_count = 0;

  construct {
    namespace = "NotificationCenter";
    if (instance == null) {
      instance = this;
    } else {
      this.destroy();
    }
  }
}
