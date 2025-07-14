# 📖 LED Mesh Controller Wiki

## Overview

The LED Mesh Controller firmware coordinates multiple ESP32 nodes in a mesh network to drive LED strips. It bridges Art-Net data to DMX, runs local lighting effects and exposes a web-based console for configuration.

## Components

- **MeshManager** – initializes ESP-Mesh, elects the root node and keeps track of connected nodes.
- **SettingsManager** – stores configuration parameters in NVS and converts them to JSON.
- **WiFiManager** – connects to a configured access point or starts a fallback AP if none is available.
- **WebServer** – serves the REST API and static web console from SPIFFS.
- **LEDManager** – wraps Adafruit NeoPixel for low level LED control.
- **FXEngine** – runs chase, pulse, static, wipe, bounce, color cycle and complementary effects with optional AutoFX mode.
- **ArtNetReceiver** – listens for Art-Net packets and forwards DMX frames.
- **DMXOutput** – transmits DMX512 data over RS485 via a MAX485 driver.
- **WebSocket** – pushes `/status` updates to the console every 500 ms.
- **SceneManager** – saves and loads scene presets on SPIFFS.
- **MicInput** – detects beats from a microphone input pin.
- **Topology API** – `/status` lists mesh nodes and whether this device is the root.

## Web Console

The web UI served from `/data/index.html` allows editing settings, saving scenes
and triggering playback. A node list displays all detected mesh nodes. If the
SPIFFS partition fails to mount or the files are missing the firmware serves a
minimal fallback page so the console can be uploaded later.

Enable **Extend Network** in the settings panel to enter Wi-Fi credentials. The
password is included in the JSON returned by `/settings` so the form can be
pre-filled. Press **Restart** after saving to reconnect. Use the `/wifi_scan`
endpoint to list nearby networks when choosing an SSID.

DMX output can be disabled through the **Enable DMX Output** checkbox.

## Smart Features

- Complementary color effect cycles through opposing hues.
- Beat detection from the microphone triggers pulse effects.
- Node topology viewer shows which devices are connected.

## File Layout

- `/src` – firmware source code
- `/data` – web console HTML/JS
- `/docs` – design documents and this wiki

Refer to `design.md` for the high-level overview and `planning.md` for project milestones.
