#include <usb.h>

usbSerial::usbSerial() {}

void usbSerial::init() {
    Serial.begin(usbBaud);
}

usbSerial usb = usbSerial();