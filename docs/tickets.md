# 🎟️ Ticket Backlog

## 🎟️ Ticket T0.1: Initialize Development Environment & Git Repository

**Milestone**: Project Bootstrap  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: Critical

### 🎯 Description

Set up the development environment so that the project can be managed, versioned, and extended automatically. Tasks include:

- Initialize a new Git repository
- Create a `.gitignore` file
- Create `/src`, `/data`, `/docs`, `/lib`
- Add basic `README.md`
- Create PlatformIO or Arduino project base

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T8.5: Handle PEP 668 Python Environments

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

`build_image.sh` fails on systems where Python enforces the
"externally-managed-environment" policy. Update the script to use a local
virtual environment and document the fix in the README.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.1: Integrate NeoPixel

**Milestone**: FX Engine and LED Control
**Created by**: system
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Add Adafruit_NeoPixel library support and provide an `LEDManager` class to drive the LED strip.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.2: FX Engine Core

**Milestone**: FX Engine and LED Control
**Created by**: system
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Implement an `FXEngine` class capable of running timed lighting effects across the LED strip.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.3: Basic Effects (Chase, Pulse)

**Milestone**: FX Engine and LED Control
**Created by**: system
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Add chase and pulse effects to the `FXEngine` as initial demonstrations.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.4: AutoFX Mode

**Milestone**: FX Engine and LED Control
**Created by**: system
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Rotate through available effects automatically when no external control is present.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.1: NVS Settings Schema

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Create a settings manager using Preferences:

- universe, startChannel, ledCount, dmxUniverse, mode, isRoot
- Load on boot, update via API

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.2: Wi-Fi Setup with Fallback AP Mode

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Implement dual-mode Wi-Fi setup:

- Connect to saved network
- Fallback to AP with captive portal
- Save SSID/pass using Preferences

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.3: HTTP Server & API Bootstrap

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Setup AsyncWebServer and REST API:

- Serve HTML UI
- GET/POST `/settings`
- Use SPIFFS + ArduinoJson

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.1: ESP-Mesh Init

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Set up the ESP-Mesh network layer so nodes can join a mesh.
Use the ESP-IDF mesh APIs. Prepare a MeshManager class with a `begin()` method.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.2: Root Node Auto-Election

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Implement logic so that one node in the mesh becomes the root automatically.
Expose `is_root_node()` in `MeshManager`.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.3: Mesh Messaging

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Provide broadcast messaging between nodes.
Add `send_message()` and `on_message()` handlers in `MeshManager`.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.4: LED Feedback for Mesh State

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Use the onboard LED to indicate mesh status:

- Fast blink when searching
- Solid when connected as root
- Slow blink when connected as a node

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T4.1: Art-Net Receiver

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Implement a UDP listener that parses Art-Net ArtDMX packets and emits DMX frames.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T4.2: MAX485 DMX Output

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description

Send DMX512 frames over RS485 using a MAX485 transceiver.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T4.3: Universe Filtering

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Only process ArtDMX packets that match the configured universe.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T4.4: Override Modes

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Allow DMX input to override local FX modes when active.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T5.1: UI Layout

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Create the basic HTML layout for the web console with scene and playback sections.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.2: Scene Controls

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Implement saving and listing of scenes through a new `SceneManager` and REST endpoints.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.3: Playback Buttons

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Add buttons to trigger scene playback from the web console.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.4: Scene Save/Recall

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Allow users to save scenes to SPIFFS and recall them via the web API.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.1: Complementary Color FX

**Milestone**: Smart Features
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Create a new FXEngine effect that displays complementary color pairs across the LED strip.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.2: Mic Input for Beat Sync

**Milestone**: Smart Features
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Add a microphone input class and use it to trigger FXEngine effects on audio beats.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.3: Node Topology Viewer

**Milestone**: Smart Features
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Expose the list of connected mesh nodes via a new `/nodes` API endpoint.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T7.1: Project Wiki and README

**Milestone**: Documentation
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Document all firmware functionality in a wiki-style markdown file and update the README with build instructions.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.1: Arduino CLI Script

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Provide a shell script using `arduino-cli` to verify, build and upload the firmware to an ESP32 dev board.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.2: Arduino IDE Sketch

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Add an Arduino IDE compatible `.ino` file so the firmware can be compiled directly in the IDE.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.3: Document ESP32 Board Requirement

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Document that the firmware only supports ESP32 boards. Add a compile guard in the `.ino` file and update the README with board selection instructions.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.4: Fix Build Script Line Endings

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Users reported `bash\r: No such file or directory` when running
`build_image.sh`. Update the shebang to use the `env -S` syntax and document
converting the script to Unix line endings in the README.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.6: Validate Virtual Environment Creation

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Ensure `build_image.sh` gracefully handles missing `python3-venv` by checking
for the `activate` script and guiding the user if creation fails.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.7: Detect Sudo Usage in Build Script

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Abort `build_image.sh` when run with `sudo` and instruct the user to execute it as a regular account.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.8: Apt Instructions for python3-venv

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Add explicit `apt` commands for installing `python3-venv` when the build script
fails to create its virtual environment.
Update `build_image.sh` and the README with these instructions.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.9: Document Permission Fixes

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Update `build_image.sh` to check that the project directory is writable and
expand the README with instructions for fixing ownership when permission errors
occur during setup.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.10: Flashing Image Files

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Document how to use the `.bin` files produced by `build_image.sh`. Explain how
to install `esptool.py` and flash the ESP32 with the bootloader, partitions and
firmware images.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.5: Fallback Web Console Page

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Serve a minimal HTML page when `/index.html` is missing from SPIFFS. The page
informs the user to upload the web console via `pio run --target uploadfs`.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.6: SPIFFS Fallback & Password JSON

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Allow the HTTP server to start even when SPIFFS fails to mount and return the stored Wi-Fi password in the settings API.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T8.11: Combined Firmware Image

**Milestone**: Build Tools
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Extend `build_image.sh` to generate `spiffs.bin` and merge all binaries into
`combined.bin`. Document how to flash the single file.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T5.7: WiFi Credentials Save & Restart

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Allow entering Wi-Fi credentials from the web console with an "Extend Network" option. Display SSID/password fields only when enabled and provide a restart button. On restart the firmware should attempt to join the configured AP a few times before falling back to AP mode.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

## 🎟️ Ticket T5.8: WiFi Network Scan API

**Milestone**: Web-Based Pro Console
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Provide an API endpoint to list nearby Wi-Fi networks so users can select an SSID when configuring network settings.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T0.2: Configure CI Build Check

**Milestone**: Project Bootstrap
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Set up GitHub Actions or PlatformIO to verify firmware builds on every push.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T0.3: Enforce Code Format Hooks

**Milestone**: Project Bootstrap
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Add clang-format and prettier git hooks to ensure consistent code style.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.4: Seed Unit Tests for Core Modules

**Milestone**: Core System Green
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Create initial unit tests covering Settings and Wi-Fi functionality.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.5: Update Ticket Checkboxes

**Milestone**: Core System Green
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Ensure all tickets include "Tests Written" and "Tests Passed" checklist items.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.5: Node Status Endpoint

**Milestone**: Mesh & Sync
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Provide a `/status` API that lists connected nodes and identifies the current root.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.6: WebSocket Status Updates

**Milestone**: Mesh & Sync
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Push node status updates over WebSocket `/ws` every 500 ms.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.5: Additional FX Library

**Milestone**: FX Engine & AutoFX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Implement Static, Wipe, Bounce and ColorCycle effects in the FXEngine.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.6: Color-Harmony Generator

**Milestone**: FX Engine & AutoFX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Generate complementary colors from HSL values for automatic FX modes.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.7: AutoFX Speed Control API

**Milestone**: FX Engine & AutoFX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Expose `/api/auto` endpoint to enable or disable AutoFX with an adjustable speed parameter.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.8: Color Conversion Tests

**Milestone**: FX Engine & AutoFX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Write unit tests verifying HSL to RGB conversion routines.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T3.9: FX Renderer Timing Tests

**Milestone**: FX Engine & AutoFX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Test FXEngine frame timing to ensure consistent animation speed.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T4.5: Map Art-Net to LED Buffer

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Translate incoming DMX frames into the LEDManager buffer for display.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T4.6: DMX Output Toggle

**Milestone**: Art-Net and DMX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Add a setting to enable or disable physical DMX output via the web API.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.9: JS Module Refactor

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Refactor frontend code into `app.js` using ES modules or Vite build tooling.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.10: WebSocket Live Updates

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Send real-time data to the web console using WebSocket communication.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.11: Integrate iro.js Color Wheel

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Add an `iro.js` based color picker to the console for selecting LED colors.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.12: Animated FX Preview Pads

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Show animated previews of each effect on the console's FX buttons.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.13: Node Dashboard Cards

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Display node cards with color swatch, FX icon, RSSI indicator and root badge.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.14: Promote to Root Button

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Provide a manual button in the console to promote a selected node to root.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.15: Scene Rename and Save

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Allow recording new scenes, renaming them and storing to `scenes.json` on SPIFFS.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T5.16: Drawer UI with Click-to-Play

**Milestone**: Pro Console UX
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Implement a drawer-style interface to list scenes and play them with a single click.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.4: Mesh Stress Test

**Milestone**: QA / Field Testing
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Medium

### 🎯 Description

Test mesh stability with at least 10 nodes running simultaneously.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.5: Latency and FPS Measurement

**Milestone**: QA / Field Testing
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Measure end-to-end latency and frames per second under load.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.6: Memory Usage Testing

**Milestone**: QA / Field Testing
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Check for brown-outs and monitor heap usage during long runs.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T6.7: Documentation Suite

**Milestone**: QA / Field Testing
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Write Quick Start, wiring guide and UI walkthrough documentation.

### ✅ Checklist
- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T7.2: Version Bump to v1.0.0

**Milestone**: Release Prep
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Update version numbers across the project to 1.0.0 prior to release.

### ✅ Checklist

- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T7.3: Create GitHub Release

**Milestone**: Release Prep
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Tag the repository and publish a GitHub Release with compiled binaries.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T7.4: Write CHANGELOG

**Milestone**: Release Prep
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Create `CHANGELOG.md` documenting major features and fixes.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T7.5: Final README Updates

**Milestone**: Release Prep
**Created by**: assistant
**Status**: ✅ Completed
**Priority**: Low

### 🎯 Description

Add final badges and screenshots to the README before release.

### ✅ Checklist

- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T9.1: Audio Reactive FX

**Milestone**: Post v1.0 Backlog
**Created by**: assistant
**Status**: 📝 Planned
**Priority**: Low

### 🎯 Description

Use microphone input to drive lighting effects in sync with music.

### ✅ Checklist

- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T9.2: Camera Color-Sample Strobe

**Milestone**: Post v1.0 Backlog
**Created by**: assistant
**Status**: 📝 Planned
**Priority**: Low

### 🎯 Description

Sample colors from a camera feed and strobe the LED strip accordingly.

### ✅ Checklist

- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T9.3: OTA Firmware Updater

**Milestone**: Post v1.0 Backlog
**Created by**: assistant
**Status**: 📝 Planned
**Priority**: Low

### 🎯 Description

Support over-the-air firmware updates to simplify deployments.

### ✅ Checklist

- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T9.4: Native Mobile Wrapper

**Milestone**: Post v1.0 Backlog
**Created by**: assistant
**Status**: 📝 Planned
**Priority**: Low

### 🎯 Description

Package the web console as a native app for iOS and Android devices.

### ✅ Checklist

- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written
