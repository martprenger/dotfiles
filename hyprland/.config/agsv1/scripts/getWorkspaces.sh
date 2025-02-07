#!/bin/bash

# Function for handling workspaces
workspaces() {
    hyprctl workspaces -j
}

# Function for handling monitor with a specific integer monitor ID
monitor() {
    hyprctl monitors -j
}

# Main script logic
if [ "$1" == "workspaces" ]; then
    workspaces
elif [ "$1" == "monitors" ]; then
    monitor "$@"
else
    echo "Error: Invalid option. Please use 'workspaces' or 'monitor <id>'."
    exit 1
fi
