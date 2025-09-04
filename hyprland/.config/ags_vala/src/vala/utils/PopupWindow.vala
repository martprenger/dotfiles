public abstract class PopupWindow {
  private static List<Astal.Window> popups = new List<Astal.Window> ();
  public static List<Underlay> underlays = new List<Underlay> ();

  public static void register_popup(Astal.Window popup) {
    popups.append(popup);
    popup.notify["visible"].connect(() => {
      if (popup.visible) {
        PopupWindow.ensure_underlays();
      } else {
        // Check if all popups are hidden
        bool any_visible = false;
        foreach (var p in popups) {
          if (p.visible) {
            any_visible = true;
            break;
          }
        }
        if (!any_visible) {
          PopupWindow.close_underlays();
        }
      }
    });
  }

  public static void ensure_underlays() {
    foreach (var underlay in underlays) {
      underlay.visible = true;
    }
  }

  public static void close_underlays() {
    foreach (var underlay in underlays) {
      underlay.visible = false;
    }
  }

  public static void close_all_popups() {
    foreach (var popup in popups.copy()) {
      popup.visible = false;
    }
    close_underlays();
  }
}
