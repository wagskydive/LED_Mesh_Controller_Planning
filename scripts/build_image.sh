#!/usr/bin/env -S bash -e
# Build ESP32 firmware image using PlatformIO

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
OUTPUT_DIR="$ROOT_DIR/images"

# Abort if run as root to avoid permission issues
if [ "$EUID" -eq 0 ]; then
  echo "Do not run this script with sudo. It manages a local virtualenv." >&2
  exit 1
fi

# Ensure the project directory is writable
if [ ! -w "$ROOT_DIR" ]; then
  echo "Error: $ROOT_DIR is not writable. Fix permissions before running this script." >&2
  exit 1
fi

# Ensure PlatformIO is installed in a local virtual environment
VENV_DIR="$ROOT_DIR/.venv"
if [ ! -d "$VENV_DIR" ]; then
  echo "Creating Python virtual environment..."
  sudo python3 -m venv "$VENV_DIR"
fi
if [ ! -f "$VENV_DIR/bin/activate" ]; then
  echo "Error: virtual environment not found in $VENV_DIR" >&2
  echo "Install the python3-venv package and rerun this script." >&2
  echo "On Debian/Ubuntu run: sudo apt update && sudo apt install python3-venv" >&2
  exit 1
fi
source "$VENV_DIR/bin/activate"
pip install --upgrade pip > /dev/null
pip install --upgrade platformio esptool > /dev/null

cd "$ROOT_DIR"
platformio run
platformio run --target buildfs

mkdir -p "$OUTPUT_DIR"
cp .pio/build/esp32dev/firmware.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/bootloader.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/partitions.bin "$OUTPUT_DIR/" 2>/dev/null || true
cp .pio/build/esp32dev/spiffs.bin "$OUTPUT_DIR/" 2>/dev/null || true

# Determine SPIFFS offset from the generated partition table
SPIFFS_OFFSET=$(awk -F',' '/spiffs/ {gsub(/^[ \t]+|\r/, "", $4); print $4}' .pio/build/esp32dev/partitions.csv)

# Create a single merged binary containing firmware and filesystem
if [ -n "$SPIFFS_OFFSET" ]; then
  esptool.py --chip esp32 merge_bin -o "$OUTPUT_DIR/combined.bin" \
    0x1000 "$OUTPUT_DIR/bootloader.bin" \
    0x8000 "$OUTPUT_DIR/partitions.bin" \
    0x10000 "$OUTPUT_DIR/firmware.bin" \
    "$SPIFFS_OFFSET" "$OUTPUT_DIR/spiffs.bin" > /dev/null
fi

echo "Firmware images stored in $OUTPUT_DIR"
