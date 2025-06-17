[GtkTemplate(ui = "/ui/QuickMenu.ui")]
public class QuickMenu : Astal.Window {
	public static QuickMenu instance { get; private set; }

	construct {
		if (instance == null) {
			instance = this;
		} else {
			this.destroy();
		}

		this.anchor = TOP | RIGHT;

		var header = new Qheader();
		this.set_child(header);
	}
}
