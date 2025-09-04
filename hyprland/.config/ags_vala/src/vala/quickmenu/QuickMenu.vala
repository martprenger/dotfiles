[GtkTemplate(ui = "/ui/QuickMenu.ui")]
public class QuickMenu : Astal.Window {
  public static QuickMenu instance { get; private set; }

  [GtkChild]
  private unowned Qheader header;

  [GtkChild]
  private unowned QMultimedia multimedia;

  private AstalMpris.Mpris _mpris;

  [GtkChild]
  private unowned Adw.Carousel players;

  public QuickMenu() {
    this.layer = Astal.Layer.OVERLAY;
    if (instance == null) {
      instance = this;
    } else {
      this.destroy();
    }

    PopupWindow.register_popup(this);

    _mpris = AstalMpris.get_default();
    _mpris.players.@foreach((p) => on_player_added(p));
    _mpris.player_added.connect((p) => on_player_added(p));
    _mpris.player_closed.connect((p) => on_player_removed(p));

    this.anchor = TOP | RIGHT;
  }

  private void on_player_added(AstalMpris.Player player) {
    var mpris_widget = new QMediaPlayer(player);
    this.players.append(mpris_widget);
  }

  private void on_player_removed(AstalMpris.Player player) {
    QMediaPlayer current = (QMediaPlayer) this.players.get_first_child();

    while (current != null) {
      if (current.player == player) {
        this.players.remove(current);
        break;
      }
      current = (QMediaPlayer) current.get_next_sibling();
    }
  }

  [GtkCallback]
  public void key_released(uint keyval) {
    if (keyval == Gdk.Key.Escape) {
      this.visible = false;
    }
  }
}
