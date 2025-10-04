public class NotificationItem : Gtk.ListBoxRow {
  public AstalNotifd.Notification notification { get; set; }
  private NotificationContent _content;

  public NotificationItem (AstalNotifd.Notification notification) {
    Object (
            css_classes: new string[] { "NotificationItem" },
            notification: notification);

    _content = new NotificationContent (notification);
    this.child = _content;

  }
}
