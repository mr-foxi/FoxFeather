#include <Arduino.h>
#include <esp32.h>
#include <oled.h>
#include <serials.h>
#include <wifi.h>
#include <blue.h>

const int POLL_TIME = 500;

void setup() {
    #ifdef OLED_H
        oled.init();
        oled.printlnString("foxTest 01: OLED");
    #endif
    #ifdef SERIALS_H
        serials.usbInit();
        serials.pinInit();
    #endif

    delay(3000);
    oled.clear();
    oled.clear();
    oled.printlnString("!!  FoxDev BADUSB  !!");

    // wifi.up();
    // wifi.RSSI();
    // wifi.httpRequest();
    // delay(3000);
    // blue.up();
    // delay(3000);
    // blue.poll();
    // delay(2000);
    // blue.poll();
    // delay(2000);
    // oled.clear();
    // oled.printlnString("foxTest Procedure");
    // oled.printlnString("Complete...");

    // serials.pinSendHello();
    // oled.clear();
    // oled.printlnString("Attempting Arduino Communication...");
}

void loop () {
    // #ifdef OLED_H
    //     if(!digitalRead(BUTTON_A)) display.print("A");
    //     if(!digitalRead(BUTTON_B)) display.print("B");
    //     if(!digitalRead(BUTTON_C)) display.print("C");
    //     delay(10);
    //     yield();
    //     display.display();
    // #endif

    // serials.pinSendHello();
    String pinResponse = serials.pinRead();
    serials.checkResponse(pinResponse);
    if(!digitalRead(BUTTON_A)) serials.sdPayload();
    if(!digitalRead(BUTTON_B)) serials.pullScript();

    delay(POLL_TIME);
}