#include <Arduino.h>
#include <esp32.h>
#include <oled.h>
#include <serials.h>
#include <wifi.h>
#include <blue.h>

const int POLL_TIME = 200;

void pinMode_default() {
    if(!digitalRead(BUTTON_A)) display.print("A");
    if(!digitalRead(BUTTON_B)) display.print("B");
    if(!digitalRead(BUTTON_C)) display.print("C");
    delay(10);
    yield();
    display.display();
}

void pinMode_00() {
    if(!digitalRead(BUTTON_A)) serials.sdPayload();
    if(!digitalRead(BUTTON_B)) serials.pullScript();
    if(!digitalRead(BUTTON_C)) wifi.sdPayload();
}

void pinMode_01() {
    if(!digitalRead(BUTTON_A)) wifi.sdPayload();
    if(!digitalRead(BUTTON_B)) wifi.pullScript();
    if(!digitalRead(BUTTON_C)) serials.sdPayload();
}

void pinMode_02() {
    if(!digitalRead(BUTTON_A)) wifi.sdPayload();
    if(!digitalRead(BUTTON_B)) wifi.pullScript();
    if(!digitalRead(BUTTON_C)) wifi.pullScriptExit();
}

void setup() {
    #ifdef OLED_H
        oled.init();
        // oled.printlnString("foxTest 01: OLED");
    #endif
    #ifdef SERIALS_H
        serials.usbInit();
        serials.pinInit();
    #endif

    delay(3000); //  DO NOT TOUCH
    oled.clear(); //  DO NOT TOUCH
    oled.clear(); //  DO NOT TOUCH
    oled.printlnString("!!  FoxDev BADUSB  !!");


    // wifi.apStart();
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
}

void loop () {
    // String pinResponse = serials.pinRead();
    // serials.checkResponse(pinResponse);

    // wifi.apRecieve();
    // wifi.sendMessage();
    
    pinMode_02();
    delay(POLL_TIME);
}