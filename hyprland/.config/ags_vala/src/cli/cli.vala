using GLib;

public class MuiCtl {
	private static string request = "";
	private static bool start = false;
	private static string? toggle_window = null;
	private static bool show_inspector = false;
	private static bool quit = false;
	private static bool show_version = false;
	private static string? autostart = null;
	private static string version = "1.0-alpha";

	public static int main(string[] args) {
		var options = new OptionEntry[] {
			{ "request", 'r', OptionFlags.NONE, OptionArg.STRING, out request, "Send request to the application", "REQUEST" },
			{ "start", 0, OptionFlags.NONE, OptionArg.NONE, out start, "Start the application", null },
			{ "toggle-window", 't', OptionFlags.NONE, OptionArg.STRING, out toggle_window, "Toggle window(s)", "WINDOW" },
			{ "show-inspector", 'i', OptionFlags.NONE, OptionArg.NONE, out show_inspector, "Show inspector", null },
			{ "autostart", 'a', OptionFlags.NONE, OptionArg.STRING, out autostart, "Control autostart (on/off/status)", "STATE" },
			{ "quit", 'q', OptionFlags.NONE, OptionArg.NONE, out quit, "Quit the application", null },
			{ "version", 'v', OptionFlags.NONE, OptionArg.NONE, out show_version, "Show version", null },
		};

		var context = new OptionContext(null);

		context.add_main_entries(options, null);

		try {
			context.parse(ref args);
		} catch (OptionError e) {
			stderr.printf("Option parsing failed: %s\n", e.message);
			return 1;
		}

		if (show_version) {
			stdout.printf("Mui version %s\n", version);
			return 0;
		} else if (start) {
			return start_mui();
		} else if (toggle_window != null) {
			return toggle_window_func(toggle_window);
		} else if (show_inspector) {
			return toggle_inspector();
		} else if (autostart != null) {
			return manage_autostart(autostart);
		} else if (quit) {
			return exit_mui();
		} else {
			return send_request(request);
		}
	}

	private static int send_request(string req) {
		try {
			Process.spawn_command_line_async(@"astal -i mui $req");
		} catch (SpawnError e) {
			stderr.printf("Failed to send request: %s\n", e.message);
			return 1;
		}
		return 0;
	}

	private static int exit_mui() {
		try {
			Process.spawn_command_line_async("astal -i mui -q");
		} catch (SpawnError e) {
			stderr.printf("Failed to quit the application: %s\n", e.message);
			return 1;
		}
		return 0;
	}

	private static int toggle_inspector() {
		try {
			Process.spawn_command_line_async("astal -i mui -I");
		} catch (SpawnError e) {
			stderr.printf("Failed to show inspector: %s\n", e.message);
			return 1;
		}
		return 0;
	}

	private static int manage_autostart(string state) {
		string autostart_dir = Path.build_filename(Environment.get_user_config_dir(), "autostart");
		string target_file = Path.build_filename(autostart_dir, "mui.desktop");

		switch (state.down()) {
			case "on":
				try {
					DirUtils.create_with_parents(autostart_dir, 0755);
					File source = File.new_for_path("/usr/share/applications/com.github.ARKye03.mui.desktop");
					File dest = File.new_for_path(target_file);
					source.copy(dest, FileCopyFlags.NONE);
					stdout.printf("Autostart enabled\n");
					return 0;
				} catch (Error e) {
					stderr.printf("Failed to enable autostart: %s\n", e.message);
					return 1;
				}

			case "off":
				try {
					File file = File.new_for_path(target_file);
					if (file.query_exists()) {
						file.delete();
					}
					stdout.printf("Autostart disabled\n");
					return 0;
				} catch (Error e) {
					stderr.printf("Failed to disable autostart: %s\n", e.message);
					return 1;
				}

			case "status":
				File file = File.new_for_path(target_file);
				stdout.printf("Autostart is %s\n", file.query_exists() ? "enabled" : "disabled");
				return 0;

			default:
				stderr.printf("Invalid autostart option. Use 'on', 'off' or 'status'\n");
				return 1;
		}
	}

	private static int toggle_window_func(string window) {
		try {
			Process.spawn_command_line_async(@"astal -i mui -t $window");
		} catch (SpawnError e) {
			stderr.printf("Failed to toggle window: %s\n", e.message);
			return 1;
		}
		return 0;
	}

	private static string? find_mui_binary() {
		try {
			string output;
			string error;
			int exit_status;
			Process.spawn_command_line_sync("which mui", out output, out error, out exit_status);
			if (exit_status == 0 && output.strip() != "") {
				return output.strip();
			} else {
				return null;
			}
		} catch (SpawnError e) {
			stderr.printf("Failed to find mui binary: %s\n", e.message);
			return null;
		}
	}

	private static bool is_process_running(string process_name) {
		try {
			string output;
			string error;
			int exit_status;
			Process.spawn_command_line_sync("pgrep -x " + process_name, out output, out error, out exit_status);
			stdout.printf(output + "\n");
			return !(output == null || output == "");
		} catch (SpawnError e) {
			stderr.printf("Failed to check if process is running: %s\n", e.message);
			return false;
		}
	}

	private static int start_mui() {
		if (is_process_running("mui")) {
			stdout.printf("Mui process is already running.\n");
			return 0;
		}

		string? mui_path = find_mui_binary();
		if (mui_path == null) {
			stderr.printf("Mui binary not found in PATH.\n");
			return 1;
		}

		try {
			Pid child_pid;
			Process.spawn_async(
				null,
				new string[] { mui_path },
				null,
				SpawnFlags.DO_NOT_REAP_CHILD,
				null,
				out child_pid
			);
			stdout.printf("Starting the application…\n");
		} catch (SpawnError e) {
			stderr.printf("Failed to start the application: %s\n", e.message);
			return 1;
		}
		return 0;
	}
}
