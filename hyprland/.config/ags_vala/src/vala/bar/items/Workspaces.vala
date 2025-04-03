public class Workspaces : Gtk.Box {
  private AstalHyprland.Hyprland _hyprland;
  private int _monitor_id;
  private int _workspaces_per_monitor;
  private int _starting_workspace;

  public Workspaces(AstalHyprland.Hyprland hyprland, AstalHyprland.Monitor monitor) {
    this._hyprland = hyprland;
    this._monitor_id = monitor.id;
    this._workspaces_per_monitor = 10;
    this._starting_workspace = (monitor.active_workspace.id / _workspaces_per_monitor) * _workspaces_per_monitor + 1;

    for (int i = _starting_workspace; i <= _starting_workspace + _workspaces_per_monitor - 1; i++) {
      var label =  new Gtk.Label((i%_workspaces_per_monitor).to_string());
			label.set_justify(Gtk.Justification.CENTER);
      var workspace_button = new Gtk.Button() {
				child = label
			};
			connect_button_to_workspace(workspace_button, i);
			this.append(workspace_button);
		}		

    update_workspaces();
		setup_workspace_event_handlers();
		setup_workspace_scroll();
  }

	private void setup_workspace_event_handlers() {
		_hyprland.notify["focused-workspace"].connect(update_workspaces);
		_hyprland.client_added.connect(update_workspaces);
		_hyprland.client_removed.connect(update_workspaces);
		_hyprland.client_moved.connect(update_workspaces);
	}

	private void setup_workspace_scroll() {
		var scroll_controller = new Gtk.EventControllerScroll(Gtk.EventControllerScrollFlags.VERTICAL);

		scroll_controller.scroll.connect((delta_x, delta_y) => {
			string direction = delta_y > 0 ? "e-1" : "e+1";
			_hyprland.dispatch("workspace", direction);
			return true;
		});
		this.add_controller(scroll_controller);
	}

	private void update_workspaces() {
		int index = 0;
		var current = (Gtk.Button)this.get_first_child();
    
    var loop = new GLib.MainLoop (null, false);
    _hyprland.sync_monitors.begin((source_object, res) => {
      try {
        _hyprland.sync_monitors.end(res);
      } catch (Error e) {
        stderr.printf("Error during sync_monitors: %s\n", e.message);
      } finally {
        AstalHyprland.Monitor monitor = _hyprland.get_monitor(this._monitor_id);
		    var focused_workspace_id = monitor.active_workspace.id;

	    	while (current != null) {
			    if (_starting_workspace + index == focused_workspace_id) {
				    current.set_css_classes({ "focused" });
			    } else if (workspace_exists(_starting_workspace+ index)) {
				    current.set_css_classes({ "occupied" });
			    } else {
				    current.set_css_classes({ "empty" });
			    }
			    current = (Gtk.Button)current.get_next_sibling();
			    index++;
		    }
        loop.quit ();
      }
    });
	}
	
  private void connect_button_to_workspace(Gtk.Button button, int workspace_number) {
		var middle_click = new Gtk.GestureClick() {
			button = Gdk.BUTTON_MIDDLE
		};

		middle_click.pressed.connect(() => {
			_hyprland.dispatch("movetoworkspacesilent", workspace_number.to_string());
		});
		button.add_controller(middle_click);
		button.clicked.connect(() => {
			_hyprland.dispatch("workspace", workspace_number.to_string());
		});
	}

	private bool workspace_exists(int workspace_number) {
		var workspace = _hyprland.get_workspace(workspace_number);

		return workspace != null && workspace.clients != null && workspace.clients.length() > 0;
	}
}
