#ifndef DEFAULT_INDEX_H
#define DEFAULT_INDEX_H

const char DEFAULT_INDEX[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <title>LED Mesh Controller</title>
</head>
<body>
    <h1>Web Console Missing</h1>
    <p>Upload the web interface with <code>pio run --target uploadfs</code>.</p>
</body>
</html>
)rawliteral";

#endif // DEFAULT_INDEX_H
