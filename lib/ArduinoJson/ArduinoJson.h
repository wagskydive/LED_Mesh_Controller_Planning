#ifndef ARDUINOJSON_H
#define ARDUINOJSON_H

#include <Arduino.h>

struct DeserializationError {
    operator bool() const { return false; }
};

template<size_t N>
class StaticJsonDocument {
    class Dummy {
    public:
        template<typename T>
        T as() const { return T(); }
        template<typename T>
        Dummy& operator=(const T&) { return *this; }
    } dummy;
public:
    Dummy operator[](const char*) { return dummy; }
    bool containsKey(const char*) const { return false; }
};

template<typename T>
inline void serializeJson(const T&, String& output) { output = "{}"; }

template<typename T>
inline DeserializationError deserializeJson(T&, const String&) { return DeserializationError(); }

#endif // ARDUINOJSON_H
