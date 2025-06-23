private enum PowerOption {
	NONE,
	SHUTDOWN,
	REBOOT,
	LOGOUT
}

[GtkTemplate(ui="/ui/PowerMenu.ui")]
class PowerMenu : Astal.Window {
	public static PowerMenu instance { get; private set; }

	private PowerOption _option;
	public string user_name { get; private set; }
	public string confirm_option {get; private set; }

	public static Gtk.Stack mstack { get; private set; }

	[GtkChild]
	private unowned Gtk.Stack main_stack;

	construct {
        namespace = "bar";
		if (instance == null) {
			instance = this;
		} else {
			this.destroy();
		}

		_option = PowerOption.NONE;
		mstack = main_stack;
		user_name = Environment.get_user_name();

		this.notify["visible"].connect(() => {
			if (!this.visible) {
			} else {
        this.margin_top = this.get_current_monitor().get_geometry().height / 4;
			}
		});
  }

  [GtkCallback]
  public void key_released(uint keyval) {
   	if (keyval == Gdk.Key.Escape) {
  		this.visible = false;
   	}
  }

  [GtkCallback]
  private void show_shutdown_confirm() {
   	_option = PowerOption.SHUTDOWN;
   	this.confirm_option = "Shutdown";
   	main_stack.visible_child_name = "confirm";
  }

  [GtkCallback]
  private void show_logout_confirm() {
   	_option = PowerOption.LOGOUT;
   	this.confirm_option = "Logout";
   	main_stack.visible_child_name = "confirm";
  }

  [GtkCallback]
  private void show_reboot_confirm() {
   	_option = PowerOption.REBOOT;
   	this.confirm_option = "Reboot";
   	main_stack.visible_child_name = "confirm";
  }

  [GtkCallback]
  private void cancel_action() {
   	_option = PowerOption.NONE;
   	main_stack.visible_child_name = "main";
  }

  [GtkCallback]
  private void confirm_action() {
   	switch (_option) {
  		case PowerOption.SHUTDOWN:
   			shutdown();
  		break;

  		case PowerOption.REBOOT:
   			reboot();
  		break;

  		case PowerOption.LOGOUT:
   			logout();
  		break;

  		default:
   			message("Unreachable code reached");
  		break;
   	}
   	_option = PowerOption.NONE;
   	main_stack.visible_child_name = "main";
  }

  private void shutdown() {
   	try {
  		Process.spawn_command_line_async("systemctl poweroff");
   	} catch (SpawnError e) {
  		warning("Failed to shutdown: %s", e.message);
   	}
  }

  private void reboot() {
   	try {
  		Process.spawn_command_line_async("systemctl reboot");
   	} catch (SpawnError e) {
  		warning("Failed to reboot: %s", e.message);
   	}
  }

  public void logout() {
   	try {
  		Process.spawn_command_line_async(@"loginctl terminate-user $user_name");
   	} catch (SpawnError e) {
  		warning("Failed to logout: %s", e.message);
   	}
  }

  [GtkCallback]
  public void suspend() {
   	try {
  		Process.spawn_command_line_async("systemctl suspend");
   	} catch (SpawnError e) {
  		warning("Failed to suspend: %s", e.message);
   	}
  }

  [GtkCallback]
  public void hibernate() {
   	try {
  		Process.spawn_command_line_async("systemctl hibernate");
   	} catch (SpawnError e) {
  		warning("Failed to hibernate: %s", e.message);
   	}
  }

  [GtkCallback]
  public void lock() {
   	try {
  		Process.spawn_command_line_async("loginctl lock-session");
   	} catch (SpawnError e) {
  		warning("Failed to lock: %s", e.message);
   	}
  }
}
