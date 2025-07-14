#!/usr/bin/env -S bash -e
# Build ESP32 firmware image using PlatformIO

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUTPUT_DIR="$ROOT_DIR/images"

# Ensure PlatformIO is installed and up to date
if command -v platformio >/dev/null 2>&1; then
  echo "Updating PlatformIO..."
else
  echo "Installing PlatformIO..."
fi
python3 -m pip install --user -U platformio
export PATH="$HOME/.local/bin:$PATH"

cd "$ROOT_DIR"
platformio run

mkdir -p "$OUTPUT_DIR"
cp .pio/build/esp32dev/firmware.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/bootloader.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/partitions.bin "$OUTPUT_DIR/" 2>/dev/null || true

echo "Firmware images stored in $OUTPUT_DIR"
