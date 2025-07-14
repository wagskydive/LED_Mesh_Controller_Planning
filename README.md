# LED Mesh Controller

A firmware project for ESP32 devices that controls a network of LED nodes. It implements mesh networking, Art-Net to DMX bridging and a web-based console with lighting effects.

## Features
- Mesh networking with automatic root election
- REST API and web console for settings and scene playback
- FX engine with chase, pulse and complementary modes
- Art-Net receiver and DMX512 output with override handling
- Scene storage on SPIFFS
- Optional microphone beat detection and node topology viewer

## Getting Started
1. Install [PlatformIO](https://platformio.org/).
2. Run `pio run` to build the firmware.
3. Upload the web console with `pio run --target uploadfs`.
4. Flash the firmware with `pio run --target upload`.

### Build Script
The `scripts/build_image.sh` helper installs PlatformIO (if missing) and
generates firmware binaries. Run it from the project root:

```bash
chmod +x scripts/build_image.sh
./scripts/build_image.sh
```

Do **not** run the script with `sudo`; it creates a `.venv` directory in the
project root to isolate PlatformIO.

If `pip` reports an "externally-managed-environment" error or the script
cannot create the virtual environment, install the `python3-venv` package and
rerun the command. On Debian/Ubuntu run:

```bash
sudo apt update && sudo apt install python3-venv
```


The helper creates the `.venv` directory automatically. If you see
```
ERROR: Could not install packages due to an OSError: [Errno 13] Permission denied
```
or `Invalid value for '-d' / '--project-dir': Path ... is not writable`, fix the
directory ownership:

```bash
sudo chown -R $(whoami):$(whoami) /path/to/LED_Mesh_Controller_Planning
```
Then rerun the script.

If you encounter `/usr/bin/env: ‘bash\r’: No such file or directory`, convert the
script to Unix line endings with `dos2unix scripts/build_image.sh` and rerun the
command. The resulting files appear in the `images/` directory.

### Flashing Prebuilt Images
The build script places three `.bin` files in the `images/` directory. To flash
these images directly without using PlatformIO:

1. Install [esptool.py](https://github.com/espressif/esptool) with `pip install esptool`.
2. Put the ESP32 into bootloader mode (usually by holding the **BOOT** button
   while pressing **RESET**).
3. Run the following command, replacing `/dev/ttyUSB0` with your serial port:

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 write_flash -z \
  0x1000 bootloader.bin \
  0x8000 partitions.bin \
  0x10000 firmware.bin
```
After flashing completes, reset the board to start the new firmware.

### Arduino CLI
An optional helper script is provided for those using the Arduino IDE or
`arduino-cli`. Execute `scripts/arduino_cli.sh` and pass your serial port to
verify, build and upload the firmware:

```bash
./scripts/arduino_cli.sh /dev/ttyUSB0
```
The script will install the ESP32 core if needed and then compile and upload.

### Arduino IDE
When compiling with the Arduino IDE, select an **ESP32** board such as "ESP32 Dev Module". The firmware relies on ESP32-specific libraries and cannot be built for Arduino Uno or other AVR boards.

## Folder Structure
```
/src  - firmware source
/data - web console files
/docs - project documentation
```

## Documentation
Detailed information about each component is available in [docs/wiki.md](docs/wiki.md). Additional planning notes can be found in [docs/design.md](docs/design.md) and [docs/planning.md](docs/planning.md).
