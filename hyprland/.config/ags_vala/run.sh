#!/bin/bash

PID_FILE="$HOME/.simple-bar-pid"

start_simple_bar() {
  meson setup build --wipe --prefix "$(pwd)/result"
  meson install -C build
  ./result/bin/simple-bar &
  echo $! > "$PID_FILE" # $! gets the PID of the last backgrounded process
  echo "simple-bar started with PID: $(cat $PID_FILE)"
}

stop_simple_bar() {
  if [ -f "$PID_FILE" ]; then
    PID=$(cat "$PID_FILE")
    kill "$PID"
    rm "$PID_FILE"
    echo "simple-bar stopped (PID: $PID)"
  else
    echo "simple-bar is not running."
  fi
}

if [ "$1" == "-c" ]; then
  stop_simple_bar
else
  stop_simple_bar #stop previous one if it exists
  start_simple_bar
fi
