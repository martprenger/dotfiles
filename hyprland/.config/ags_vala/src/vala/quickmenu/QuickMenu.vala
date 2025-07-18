[GtkTemplate(ui = "/ui/QuickMenu.ui")]
public class QuickMenu : Astal.Window {
    public static QuickMenu instance { get; private set; }

    [GtkChild]
    private unowned Qheader header;

    [GtkChild]
    private unowned QMultimedia multimedia;

    [GtkChild]
    private unowned QMediaPlayer mediaPlayer;

    construct {
        if (instance == null) {
            instance = this;
        } else {
            this.destroy();
        }

        this.anchor = TOP | RIGHT;
    }

    [GtkCallback]
    public void key_released(uint keyval) {
        if (keyval == Gdk.Key.Escape) {
            this.visible = false;
        }
    }

   	private void on_player_added(AstalMpris.Player player) {
		var mpris_widget = new MprisPlayer(player);

		this.players.append(mpris_widget);
	}

	private void on_player_removed(AstalMpris.Player player) {
		MprisPlayer current = (MprisPlayer)this.players.get_first_child();

		while (current != null) {
			if (current.player == player) {
				this.players.remove(current);
				break;
			}
			current = (MprisPlayer)current.get_next_sibling();
		}
	}
}
