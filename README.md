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

## Folder Structure
```
/src  - firmware source
/data - web console files
/docs - project documentation
```

## Documentation
Detailed information about each component is available in [docs/wiki.md](docs/wiki.md). Additional planning notes can be found in [docs/design.md](docs/design.md) and [docs/planning.md](docs/planning.md).
