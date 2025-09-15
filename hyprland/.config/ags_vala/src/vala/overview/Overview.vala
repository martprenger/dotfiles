[CCode(cname = "mpars_evaluate")]
public extern double mpars_evaluate(string expression, out string? error);

[GtkTemplate(ui = "/ui/Overview.ui")]
class Overview : Astal.Window {
  public static Overview instance { get; private set; }

  public AstalApps.Apps apps { get; construct set; }

  [GtkChild]
  private unowned Gtk.Entry entry;

  [GtkChild]
  private unowned Astal.Bin math_bin;

  [GtkChild]
  private unowned Gtk.Label math_label;

  [GtkChild]
  private unowned Gtk.ListBox app_list;

  private int sort_func(Gtk.ListBoxRow la, Gtk.ListBoxRow lb) {
    AppButton a = (AppButton) la;
    AppButton b = (AppButton) lb;

    if (a.score == b.score) {
      return b.app.frequency - a.app.frequency;
    }
    return (a.score > b.score) ? -1 : 1;
  }

  private bool filter_func(Gtk.ListBoxRow row) {
    AppButton app = (AppButton) row;

    return app.score >= 0;
  }

  private bool looks_like_math(string text) {
    return text[0] != ':' &&
           (text.contains("+") ||
            text.contains("-") ||
            text.contains("*") ||
            text.contains("/") ||
            text.contains("^"));
  }

  [GtkCallback]
  public void update_list() {
    string input = this.entry.text.strip();

    // Handle math expressions
    if (looks_like_math(input)) {
      string error;
      double result = mpars_evaluate(input, out error);

      if (error == null) {
        math_label.set_text(result.to_string());
        math_bin.visible = true;
        return;
      } else {
        math_bin.visible = false;
      }
      app_list.visible = false;
      return;
    } else {
      app_list.visible = true;
      math_bin.visible = false;
    }

    // Update app filtering
    var child = this.app_list.get_first_child();
    while (child != null) {
      if (child is AppButton) {
        var app = (AppButton) child;
        app.score = apps.fuzzy_score(input, app.app);
      }
      child = child.get_next_sibling();
    }

    this.app_list.invalidate_sort();
    this.app_list.invalidate_filter();
  }

  [GtkCallback]
  public void launch_first_runner_button() {
    AppButton selected_button = (AppButton) this.app_list.get_first_child();

    if (selected_button != null && app_list.visible) {
      selected_button.activate();
      this.visible = false;
    }
  }

  [GtkCallback]
  public bool key_pressed(uint event) {
    if (event == Gdk.Key.Down && (entry.get_focus_child() != null) && app_list.visible) {
      Gtk.ListBoxRow? first_row = app_list.get_first_child() as Gtk.ListBoxRow;
      if (first_row != null) {
        app_list.select_row(first_row);
        first_row.grab_focus();
        return true;
      }
    }

    if (event == Gdk.Key.Up && app_list.visible && (app_list.get_focus_child() != null)) {
      if (app_list.get_first_child() == app_list.get_focus_child()) {
        entry.grab_focus();
      }
    }
    return false;
  }

  [GtkCallback]
  public void key_released(uint keyval) {
    if (keyval == Gdk.Key.Escape) {
      this.visible = false;
    }
  }

  construct {
    namespace = "Overview";
    if (instance == null) {
      instance = this;
    } else {
      this.destroy();
    }

    this.layer = Astal.Layer.OVERLAY;
    PopupWindow.register_popup(this);

    this.apps = new AstalApps.Apps();

    this.app_list.set_sort_func(sort_func);
    this.app_list.set_filter_func(filter_func);

    this.apps.list.@foreach(app => {
      this.app_list.append(new AppButton(app));
    });

    this.notify["visible"].connect(() => {
      if (!this.visible) {
        this.entry.text = "";
      } else {
        this.margin_top = this.get_current_monitor().get_geometry().height / 8;
        this.entry.grab_focus();

        // Clear the app_list
        var child = this.app_list.get_first_child();
        while (child != null) {
          var next = child.get_next_sibling();
          this.app_list.remove(child);
          child = next;
        }

        // Fetch new apps and add to app_list
        this.apps = new AstalApps.Apps();
        this.apps.list.@foreach(app => {
          this.app_list.append(new AppButton(app));
        });
      }
    });
  }
}
