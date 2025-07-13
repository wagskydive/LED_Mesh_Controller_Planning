# LED Mesh Controller

This project controls a network of LED nodes using ESP32 devices. It features a mesh networking framework, an LED manager powered by Adafruit NeoPixel, an FX engine for lighting effects, Art-Net/DMX support, and a web-based control console.

The firmware stores configuration in NVS, connects to Wi-Fi with a fallback access point, and exposes a REST API via AsyncWebServer. It now listens for Art-Net packets and forwards them over a MAX485 interface for DMX lighting fixtures.

See `docs/design.md` for the high-level design and `docs/planning.md` for the project milestones.
