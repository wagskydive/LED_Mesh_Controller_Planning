#!/bin/bash
# Simple helper script to verify, compile and upload using arduino-cli

BOARD_FQBN="esp32:esp32:esp32"    # FQBN for ESP32 Dev Module
PORT=${1:-/dev/ttyUSB0}            # Serial port, override with first arg

PROJECT_DIR="$(dirname "$0")/.."

# Ensure board platform is installed
arduino-cli core update-index
arduino-cli core install esp32:esp32

# Verify/build the sketch
arduino-cli compile --fqbn "$BOARD_FQBN" "$PROJECT_DIR"

# Upload if compile succeeds
arduino-cli upload -p "$PORT" --fqbn "$BOARD_FQBN" "$PROJECT_DIR"
