import { bind } from "astal";
import Battery from "gi://AstalBattery";

export default () => {
  const bat = Battery.get_default();

  return (
    <box className="control-center__battery" visible={bind(bat, "isPresent")}>
      <box spacing={4}>
        <icon icon={bind(bat, "battery_icon_name").as(String)} />
        <label
          label={bind(bat, "percentage").as((p) => `${Math.floor(p * 100)} %`)}
        />
      </box>
    </box>
  );
};
