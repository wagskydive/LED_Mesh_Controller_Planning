#!/usr/bin/env -S bash -e
# Build ESP32 firmware image using PlatformIO

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUTPUT_DIR="$ROOT_DIR/images"

# Ensure PlatformIO is installed in a local virtual environment
VENV_DIR="$ROOT_DIR/.venv"
if [ ! -d "$VENV_DIR" ]; then
  echo "Creating Python virtual environment..."
  python3 -m venv "$VENV_DIR"
fi
source "$VENV_DIR/bin/activate"
pip install --upgrade pip > /dev/null
pip install --upgrade platformio > /dev/null

cd "$ROOT_DIR"
platformio run

mkdir -p "$OUTPUT_DIR"
cp .pio/build/esp32dev/firmware.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/bootloader.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/partitions.bin "$OUTPUT_DIR/" 2>/dev/null || true

echo "Firmware images stored in $OUTPUT_DIR"
