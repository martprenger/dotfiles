[GtkTemplate(ui = "/ui/QMediaPlayer.ui")]
public class QMediaPlayer : Gtk.Box {
	public AstalMpris.Player player { get; set; }

	[GtkCallback]
	public void next() {
		this.player.next();
	}

	[GtkCallback]
	public void prev() {
		this.player.previous();
	}

	[GtkCallback]
	public void play_pause() {
		this.player.play_pause();
	}

	[GtkCallback]
	public string pause_icon(AstalMpris.PlaybackStatus status) {
		switch (status) {
			case AstalMpris.PlaybackStatus.PLAYING:
				return "media-playback-pause-symbolic";

			case AstalMpris.PlaybackStatus.PAUSED:
			case AstalMpris.PlaybackStatus.STOPPED:
			default:
				return "media-playback-start-symbolic";
		}
	}

	[GtkCallback]
	public string art_url(string? url) {
    if (url == null || url == "") {
        return "";
    }

    // Handle local file:// paths
    if (url.has_prefix("file://")) {
      return url.substring(7); // strip file://
    }

    // Handle http/https URLs
    if (url.has_prefix("http://") || url.has_prefix("https://")) {
      try {
        var file = File.new_for_uri(url);
        var input_stream = file.read(null);

        // Create a temp file
        string tmp_dir = Environment.get_tmp_dir();
        string tmp_path = Path.build_filename(tmp_dir, "downloaded_art.png");
        var tmp_file = File.new_for_path(tmp_path);

        var output_stream = tmp_file.replace(null, false, FileCreateFlags.NONE, null);

        // Copy from input to output
        output_stream.splice(input_stream,
            OutputStreamSpliceFlags.CLOSE_SOURCE | OutputStreamSpliceFlags.CLOSE_TARGET,
            null);

        return tmp_path;
      } catch (Error e) {
        warning("Failed to download image: %s", e.message);
        return "";
      }
    }

    // If nothing matches, just return as-is
    return url;
}

	[GtkCallback]
	public string current_pos(double pos) {
		int minutes = (int)(pos / 60);
		int seconds = (int)(pos % 60);

		if (seconds < 10) {
			return @"$minutes:0$seconds";
		} else {
			return @"$minutes:$seconds";
		}
	}

	[GtkCallback]
	public string total_pos(double len) {
		int minutes = (int)(len / 60);
		int seconds = (int)(len % 60);

		if (seconds < 10) {
			return @"$minutes:0$seconds";
		} else {
			return @"$minutes:$seconds";
		}
	}

	[GtkChild]
	public unowned Gtk.Adjustment media_len_adjust;

	public QMediaPlayer(AstalMpris.Player player) {
		Object();
		this.player = player;

		this.player.bind_property("position", media_len_adjust, "value",
								  GLib.BindingFlags.BIDIRECTIONAL | GLib.BindingFlags.SYNC_CREATE);
	}
}
