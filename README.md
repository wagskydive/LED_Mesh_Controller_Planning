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

If `pip` reports an "externally-managed-environment" error or the script
cannot create the virtual environment, install the `python3-venv` package
and run the script without `sudo`. The helper creates a `.venv` directory
automatically to isolate PlatformIO.

If you encounter `/usr/bin/env: ‘bash\r’: No such file or directory`, convert the
script to Unix line endings with `dos2unix scripts/build_image.sh` and rerun the
command. The resulting files appear in the `images/` directory.

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
