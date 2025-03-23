#!/bin/bash

BUILD_DIR="build"
PREFIX_DIR="$(pwd)/result"
BINARY="$PREFIX_DIR/bin/simple-bar"
PID_FILE="/tmp/simple-bar.pid"

# Function to stop the running instance
stop_simple_bar() {
    if [[ -f "$PID_FILE" ]]; then
        PREV_PID=$(cat "$PID_FILE")
        if ps -p $PREV_PID > /dev/null; then
            echo "Stopping previous instance ($PREV_PID)..."
            kill $PREV_PID
            sleep 1
        fi
        rm -f "$PID_FILE"
    fi
}

# Help message
if [[ "$1" == "-h" ]]; then
    echo "Usage: $0 [options]"
    echo "Options:"
    echo "  -h  Show this help message"
    echo "  -c  Close the currently running instance"
    exit 0
fi

# Close only mode
if [[ "$1" == "-c" ]]; then
    stop_simple_bar
    exit 0
fi

# Stop previous instance
stop_simple_bar

# Build and install
meson setup "$BUILD_DIR" --wipe --prefix "$PREFIX_DIR"
meson install -C "$BUILD_DIR"

# Run in background and store PID
echo "Starting new instance..."
"$BINARY" &
echo $! > "$PID_FILE"
