#ifndef USB_H
#define USB_H

#define usbBaud 115200

#include <Arduino.h>

class usbSerial
{
public:
    usbSerial();
    void init();
};
extern usbSerial usb;

#endif