#include <Arduino.h>
#include <esp32.h>
#include <oled.h>
#include <usb.h>
#include <wifi.h>

void setup() {
    #ifdef USB_h
        usb.init();
    #endif
    #ifdef OLED_H
        oled.init();
        String txt = "foxTest 00 \n";
        oled.printString(txt);
    #endif

    Serial.println("foxTest 01");

    delay(3000);
    oled.clear();

    wifi.wifiUp();
    http.httpRequest();
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