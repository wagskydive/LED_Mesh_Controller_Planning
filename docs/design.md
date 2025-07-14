# LED Mesh Controller Design

The system uses ESP32 boards arranged in a mesh network to drive LED fixtures. Nodes elect a root that bridges to Art-Net or DMX sources. A web-based console provides configuration and playback controls.

## Components

- **MeshManager**: Initializes ESP-Mesh, handles root election, broadcast messaging, and indicates mesh state using the onboard LED.
- **SettingsManager**: Persists configuration using NVS.
- **WiFiManager**: Connects to configured network or starts an access point.
- **WebServer**: Provides REST API and serves the web console.
- **LEDManager**: Wraps Adafruit_NeoPixel to drive the LED strip.
- **FXEngine**: Generates lighting effects for connected LEDs. Effects include
  chase, pulse, static, wipe, bounce, color cycle and complementary modes. The
  engine can cycle automatically through effects.
- **ArtNetReceiver**: Parses incoming Art-Net packets and produces DMX frames.
- **DMXOutput**: Sends DMX512 data over RS485 using a MAX485 driver.
- **DMXOverride**: Pauses FX playback whenever Art-Net DMX data is received so external controllers can take over.
- **SceneManager**: Stores lighting scenes on SPIFFS for recall.
- **WebConsole**: Serves an interface from SPIFFS for managing scenes and settings.
- **MicInput**: Reads microphone data to trigger FX on beat or drive the
  audio-reactive effect.
- **TopologyAPI**: Lists connected nodes for the web console.
