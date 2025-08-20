[GtkTemplate(ui = "/ui/QMultimedia.ui")]
public class QMultimedia : Gtk.Box {
  public AstalWp.Wp? wp { get; private set; }
  public AstalWp.Endpoint speaker { get; private set; }
  public AstalWp.Endpoint microphone { get; private set; }

  public Gtk.Adjustment speaker_adj { get; private set; }
  public Gtk.Adjustment microphone_adj { get; private set; }

  [GtkChild]
  public unowned Gtk.ListBox sources;

  [GtkChild]
  public unowned Gtk.ListBox mixers;

  [GtkChild]
  public unowned Gtk.ListBox sinks;

  [GtkChild]
  private unowned Gtk.Revealer sources_revealer;

  [GtkChild]
  private unowned Gtk.ToggleButton sources_toggle;

  [GtkChild]
  private unowned Gtk.Revealer sinks_revealer;

  [GtkChild]
  private unowned Gtk.ToggleButton sinks_toggle;

  [GtkChild]
  private unowned Gtk.Revealer mixers_revealer;

  [GtkChild]
  private unowned Gtk.ToggleButton mixers_toggle;

  public bool sources_visible {
    get { return _sources_visible; }
    set {
      if (_sources_visible != value) {
        _sources_visible = value;
        notify_property("sources-visible");
      }
    }
  }
  private bool _sources_visible = false;

  public bool sinks_visible {
    get { return _sinks_visible; }
    set {
      if (_sinks_visible != value) {
        if (_mixers_visible) {
          _mixers_visible = false;
        }
        notify_property("sinks-visible");
        _sinks_visible = value;
        notify_property("mixers-visible");
      }
    }
  }
  private bool _sinks_visible = false;

  public bool mixers_visible {
    get { return _mixers_visible; }
    set {
      if (_mixers_visible != value) {
        if (_sinks_visible) {
          _sinks_visible = false;
        }
        notify_property("mixers-visible");
        _mixers_visible = value;
        notify_property("sinks-visible");
      }
    }
  }
  private bool _mixers_visible = false;

  construct {
      this.wp = AstalWp.get_default();
      if (wp == null) {
          critical("Failed to initialize wp");
      } else {
          this.speaker = wp.audio.default_speaker;
          this.microphone = wp.audio.default_microphone;
      }

      this.speaker_adj = new Gtk.Adjustment(speaker.volume, 0, 1, 0, 0, 0);
      this.microphone_adj = new Gtk.Adjustment(microphone.volume, 0, 1, 0, 0, 0);

      speaker.bind_property(
          "volume",
          speaker_adj,
          "value",
          BindingFlags.SYNC_CREATE | BindingFlags.BIDIRECTIONAL
      );

      microphone.bind_property(
          "volume",
          microphone_adj,
          "value",
          BindingFlags.SYNC_CREATE | BindingFlags.BIDIRECTIONAL
      );

      wp.audio.speakers.@foreach((e) => on_added(e, sinks));
      wp.audio.microphones.@foreach((e) => on_added(e, sources));
      wp.audio.streams.@foreach((e) => on_added(e, mixers));

      wp.audio.speaker_added.connect((e) => on_added(e, sinks));
      wp.audio.speaker_removed.connect((e) => on_removed(e, sinks));

      wp.audio.microphone_added.connect((e) => on_added(e, sources));
      wp.audio.microphone_removed.connect((e) => on_removed(e, sources));

      wp.audio.stream_added.connect((e) => on_added(e, mixers));
      wp.audio.stream_removed.connect((e) => on_removed(e, mixers));

      // Optional: Ensure UI is in sync at startup
      sources_revealer.reveal_child = sources_visible;
      sources_toggle.active = sources_visible;
      sinks_revealer.reveal_child = sinks_visible;
      sinks_toggle.active = sinks_visible;
      mixers_revealer.reveal_child = mixers_visible;
      mixers_toggle.active = mixers_visible;

      // Keep revealer and toggle in sync with property
      this.notify["sources-visible"].connect(() => {
          sources_revealer.reveal_child = sources_visible;
          sources_toggle.active = sources_visible;
      });
      this.notify["sinks-visible"].connect(() => {
          sinks_revealer.reveal_child = sinks_visible;
      });
      this.notify["mixers-visible"].connect(() => {
          mixers_revealer.reveal_child = mixers_visible;
      });
  }

  [GtkCallback]
  void toggle_speaker() {
    speaker.mute = !speaker.mute;
  }

  [GtkCallback]
  public void toggle_sinks() {
    sinks_visible = !sinks_visible;
  }

  [GtkCallback]
  public void toggle_mixers() {
    mixers_visible = !mixers_visible;
  }

  [GtkCallback]
  void toggle_microphone() {
    microphone.mute = !microphone.mute;
  }

  private void on_added(AstalWp.Node e, Gtk.ListBox l) {
    string? app_icon = null;
    if (l == mixers) {
      // Try to get app icon for this stream
      app_icon = get_app_icon_for_stream(e);
    }
    l.append(new QAudioItem(e, app_icon));
  }

  private string? get_app_icon_for_stream(AstalWp.Node stream) {
    string? icon_name = null;

    // Try to get the icon from PipeWire properties
    icon_name = stream.get_pw_property("application.icon_name");
    if (icon_name != null && icon_name != "") {
      return icon_name;
    }

    // Try desktop entry (often used by MPRIS)
    icon_name = stream.get_pw_property("mpris:desktop-entry");
    if (icon_name != null && icon_name != "") {
      return icon_name;
    }

    // Try process binary name as a fallback
    icon_name = stream.get_pw_property("application.process.binary");
    if (icon_name != null && icon_name != "") {
      return icon_name;
    }

    // Fallback to a generic icon
    return "audio-card-symbolic";
  }


  private void on_removed(AstalWp.Node e, Gtk.ListBox l) {
      var current = (QAudioItem)l.get_first_child();

      while (current != null) {
          if (current.endpoint == e) {
              l.remove(current);
              break;
          }
          current = (QAudioItem)current.get_next_sibling();
      }
  }

  [GtkCallback]
  public void toggle_sources() {
      sources_visible = !sources_visible;
  }

  [GtkCallback]
  public string toggle_icon(bool visible) {
      return visible ? "pan-up-symbolic" : "pan-down-symbolic";
  }
}
