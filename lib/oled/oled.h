#ifndef OLED_H
#define OLED_H

#define BUTTON_A 15
#define BUTTON_B 32
#define BUTTON_C 14

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// #define Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
extern Adafruit_SH1107 display;

class oledWing
{
public:
    oledWing();
    void init();
    void foxInit();
    void foxClear();
    void clear();
    // void testPrint();
    void printlnString(String txt);
    void printString(String txt);
    void printlnInt(int num);
    void printInt(int num);
};
extern oledWing oled;

#endif


// // OLED FeatherWing buttons map to different pins depending on board:
// #if defined(ESP8266)
//   #define BUTTON_A  0
//   #define BUTTON_B 16
//   #define BUTTON_C  2
// #elif defined(ESP32) && \
//     !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2) && \
//     !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3) && \
//     !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3_NOPSRAM)
//   #define BUTTON_A 15
//   #define BUTTON_B 32
//   #define BUTTON_C 14
// #elif defined(ARDUINO_STM32_FEATHER)
//   #define BUTTON_A PA15
//   #define BUTTON_B PC7
//   #define BUTTON_C PC5
// #elif defined(TEENSYDUINO)
//   #define BUTTON_A  4
//   #define BUTTON_B  3
//   #define BUTTON_C  8
// #elif defined(ARDUINO_NRF52832_FEATHER)
//   #define BUTTON_A 31
//   #define BUTTON_B 30
//   #define BUTTON_C 27
// #else // 32u4, M0, M4, nrf52840, esp32-s2, esp32-s3 and 328p
//   #define BUTTON_A  9
//   #define BUTTON_B  6
//   #define BUTTON_C  5
// #endif