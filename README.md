# LED Mesh Controller

This project controls a network of LED nodes using ESP32 devices. It features a mesh networking framework, an LED manager powered by Adafruit NeoPixel, an FX engine for lighting effects, Art-Net/DMX support, and a web-based control console.

The firmware stores configuration in NVS, connects to Wi-Fi with a fallback access point, and exposes a REST API via AsyncWebServer. It now listens for Art-Net packets and forwards them over a MAX485 interface for DMX lighting fixtures.

DMX frames temporarily suspend the local FX engine, allowing external control sources to override animations.

Scenes can be saved and recalled from the web console.

New smart features include a complementary color effect, microphone beat sync,
and a topology viewer showing connected nodes.

See `docs/design.md` for the high-level design and `docs/planning.md` for the project milestones.
