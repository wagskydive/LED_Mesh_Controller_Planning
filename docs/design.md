# LED Mesh Controller Design

The system uses ESP32 boards arranged in a mesh network to drive LED fixtures. Nodes elect a root that bridges to Art-Net or DMX sources. A web-based console provides configuration and playback controls.

## Components
 - **MeshManager**: Initializes ESP-Mesh, handles root election, broadcast messaging, and indicates mesh state using the onboard LED.
- **SettingsManager**: Persists configuration using NVS.
- **WiFiManager**: Connects to configured network or starts an access point.
- **WebServer**: Provides REST API and serves the web console.
- **LEDManager**: Wraps Adafruit_NeoPixel to drive the LED strip.
- **FXEngine**: Generates lighting effects for connected LEDs.
- **ArtNetReceiver**: Parses incoming Art-Net packets and produces DMX frames.
- **DMXOutput**: Sends DMX512 data over RS485 using a MAX485 driver.
- **DMXOverride**: Pauses FX playback whenever Art-Net DMX data is received so external controllers can take over.
- **WebConsole**: Serves an interface from SPIFFS for managing scenes and settings.
