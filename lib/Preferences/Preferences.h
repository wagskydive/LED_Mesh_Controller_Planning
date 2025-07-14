#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <Arduino.h>

class Preferences {
public:
    bool begin(const char* name, bool readOnly = false) { return true; }
    uint16_t getUShort(const char* key, uint16_t defaultValue = 0) { return defaultValue; }
    uint8_t getUChar(const char* key, uint8_t defaultValue = 0) { return defaultValue; }
    bool getBool(const char* key, bool defaultValue = false) { return defaultValue; }
    String getString(const char* key, const String& defaultValue = "") { return defaultValue; }
    void putUShort(const char* key, uint16_t value) {}
    void putUChar(const char* key, uint8_t value) {}
    void putBool(const char* key, bool value) {}
    void putString(const char* key, const String& value) {}
};

#endif // PREFERENCES_H
