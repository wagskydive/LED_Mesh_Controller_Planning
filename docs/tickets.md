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

---

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

