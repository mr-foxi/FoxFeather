#include <Arduino.h>
#include <esp32.h>
#include <oled.h>
#include <usb.h>
#include <wifi.h>
#include <blue.h>

void setup() {
    #ifdef USB_h
        usb.init();
        Serial.println("foxTest 00: USB Serial");
    #endif
    #ifdef OLED_H
        oled.init();
        oled.printlnString("foxTest 01: OLED");
    #endif

    delay(3000);
    oled.clear();

    wifi.up();
    wifi.RSSI();
    wifi.httpRequest();
    delay(3000);

    blue.up();
    delay(3000);
    blue.poll();
    delay(2000);
    blue.poll();
    delay(2000);

    oled.clear();
    oled.printlnString("foxTest Procedure");
    oled.printlnString("Complete...");
}

void loop () {
    #ifdef OLED_H
        if(!digitalRead(BUTTON_A)) display.print("A");
        if(!digitalRead(BUTTON_B)) display.print("B");
        if(!digitalRead(BUTTON_C)) display.print("C");
        delay(10);
        yield();
        display.display();
    #endif
}