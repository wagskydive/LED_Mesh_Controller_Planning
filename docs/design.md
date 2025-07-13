# LED Mesh Controller Design

The system uses ESP32 boards arranged in a mesh network to drive LED fixtures. Nodes elect a root that bridges to Art-Net or DMX sources. A web-based console provides configuration and playback controls.

## Components
- **MeshManager**: Maintains ESP-Mesh connections and handles message routing.
- **SettingsManager**: Persists configuration using NVS.
- **FXEngine**: Generates lighting effects for connected LEDs.
- **WebConsole**: Serves an interface from SPIFFS for managing scenes and settings.
