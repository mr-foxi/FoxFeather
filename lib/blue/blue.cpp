#include <blue.h>
#include <oled.h>
#include "Arduino.h"
#include "ArduinoBLE.h"

void blePeripheralConnectHandler(BLEDevice central) {
    // central connected event handler
    Serial.print("Connected event, central: ");
    Serial.println(central.address());
    oled.printlnString("Connected event, central: ");
    oled.printlnString(central.address());
}

void blePeripheralDisconnectHandler(BLEDevice central) {
    // central disconnected event handler
    Serial.print("Disconnected event, central: ");
    Serial.println(central.address());
    oled.printlnString("Disconnected event, central: ");
    oled.printlnString(central.address());
}

BLUE::BLUE() {}

void BLUE::up() {
    oled.clear();
    Serial.println("Initiating Bluetooth Low Energy module...");
    oled.printlnString("Initiating Bluetooth Low Energy module...");
    delay(100);

    // int i = 0;
    // if (!BLE.begin() && i<3 ) {
    //     Serial.println("Bluetooth Low Energy did not initiate...");//
    //     oled.printlnString("Bluetooth Low Energy did not intiate...");//
    //     // Serial.println("starting Bluetooth® Low Energy module failed!");
    //     i++;
    //     while (1);
    // }

    int blueCon = BLE.begin(); // 1 = Success, 0 = Fail
    if (blueCon == 1) {
        Serial.println("Bluetooth Low Energy up...");
        oled.clear();
        oled.printlnString("Bluetooth Low Energy connected...");
    } else {
        Serial.println("Bluetooth Low Energy did not connect...");
        oled.printlnString("Bluetooth Low Energy did not connected...");
        blueCon = BLE.begin();
    }

    // bool blueCon = BLE.begin(); // 1 = Success, 0 = Fail
    // while (blueCon != 1) {
    //     Serial.println("Bluetooth Low Energy NOT initiated...");
    //     oled.printlnString("Bluetooth Low Energy NOT initiated...");
    //     blueCon = BLE.begin();
    // } 
}
void BLUE::poll() {
    oled.clear();
    Serial.println("Bluetooth polling...");
    oled.printlnString("Bluetooth polling...");
    // assign event handlers for connected, disconnected to peripheral
    BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
    BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
    BLE.poll(2000);
    Serial.println("Bluetooth polled...");
    oled.printlnString("Bluetooth polled...");
}
BLUE blue = BLUE();