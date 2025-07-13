# LED Mesh Controller

This project controls a network of LED nodes using ESP32 devices. It features a mesh networking framework, FX engine for lighting effects, Art-Net/DMX support, and a web-based control console.

The firmware stores configuration in NVS, connects to Wi-Fi with a fallback access point, and exposes a REST API via AsyncWebServer.

See `docs/design.md` for the high-level design and `docs/planning.md` for the project milestones.
