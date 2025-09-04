public class Scss {
  private App app;

  private File scss_main_file;
  private File scss_color_file;

  private File css_output_file;

  private FileMonitor css_color_monitor;

  public Scss(App _app) {
    app = _app;

    app.apply_css("resource:///main.css", false);

    string home_dir = Environment.get_home_dir();
    scss_main_file = File.new_for_path(home_dir + "/dotfiles/hyprland/.config/ags_vala/src/scss/main.scss");
    css_output_file = File.new_for_path(home_dir + "/dotfiles/hyprland/.config/ags_vala/build/src/main.css");

    string cache_dir = Environment.get_user_cache_dir();
    scss_color_file = File.new_for_path(cache_dir + "/material/colors.scss");

    monitor_scss_file();
  }

  void monitor_scss_file() {
    if (scss_color_file == null) {
      stderr.printf("Error: filer is null\n");
      return;
    }
    try {
      css_color_monitor = scss_color_file.monitor_file(
                                                       GLib.FileMonitorFlags.WATCH_HARD_LINKS
                                                       | GLib.FileMonitorFlags.WATCH_MOUNTS
                                                       | GLib.FileMonitorFlags.WATCH_MOVES
      );
      if (css_color_monitor == null) {
        message("Error: Could not create GFileMonitor for file: %s\n", scss_color_file.get_path());
        return;
      }
      css_color_monitor.changed.connect((file, other_file, event_type) => {
        if (event_type == FileMonitorEvent.CHANGED) {
          compile_scss();
        } else if (event_type == FileMonitorEvent.CREATED) {
          compile_scss();
        }
      });
    } catch (IOError e) {
      critical("Error: %s\n", e.message);
    }
  }

  void compile_scss() {
    message("css updated");
    string[] command_argv = { "sass", scss_main_file.get_path(), css_output_file.get_path() };

    // --- Variables for spawn_sync ---
    string? standard_output = null;
    string? standard_error = null;
    int exit_status = 0;
    string? working_directory = null; // Use current directory, change if needed
    string[] ? envp = null; // Inherit current environment
    // SEARCH_PATH: Look for "sass" in the system PATH
    // DO_NOT_REAP_CHILD: Necessary for spawn_sync to get exit status correctly
    // SpawnFlags flags = SpawnFlags.SEARCH_PATH | SpawnFlags.DO_NOT_REAP_CHILD;
    SpawnFlags flags = SpawnFlags.SEARCH_PATH;
    // ----------------------------------


    try {
      // stdout.printf ("Executing command: %s\n", string.joinv (" ", command_argv));

      // Spawn the process synchronously using the argument vector
      Process.spawn_sync(working_directory,
                         command_argv,
                         envp,
                         flags,
                         null,    // child_setup function (optional)
                         out standard_output,
                         out standard_error,
                         out exit_status);

      // Check the command's exit status
      // if (exit_status == 0) {
      // stdout.printf ("Command executed successfully.\n");
      // if (standard_output != null && standard_output.length > 0) {
      // stdout.printf ("--- Standard Output ---\n%s\n-----------------------\n", standard_output);
      // }
      // } else {
      // stderr.printf ("Command failed with exit status: %d\n", exit_status);
      // if (standard_error != null && standard_error.length > 0) {
      // stderr.printf ("--- Standard Error ----\n%s\n-----------------------\n", standard_error);
      // }
      //// Optionally print stdout even on failure
      // if (standard_output != null && standard_output.length > 0) {
      // stdout.printf ("--- Standard Output (on failure) ---\n%s\n----------------------------------\n", standard_output);
      // }
      // }
      // Return the exit status of the spawned 'sass' command
      // return exit_status;
      message("apply_css");
      app.apply_css(css_output_file.get_path(), true);
    } catch (SpawnError e) {
      // Handle errors during the spawning process itself (e.g., 'sass' command not found)
      stderr.printf("Error spawning command '%s': %s\n", command_argv[0], e.message);
    }
  }
}
