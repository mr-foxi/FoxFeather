#ifndef SERIALS_H
#define SERIALS_H

#include <Arduino.h>

const int RX_PIN = 16;
const int TX_PIN = 17;
const int SERIALS_BAUD = 115200;

enum ResponseCode {
  RESPONSE_UNKNOWN,
  RESPONSE_HELLO,
//   RESPONSE_PULLSCRIPT,
  RESPONSE_EMPTY,
  RESPONSE_ERROR404,
  RESPONSE_ERROR222,
  RESPONSE_ERROR
};

class SERIALS
{
public:
    SERIALS();
    void usbInit();
    void pinInit();
    void pinSendHello();
    String pinRead();
    void print(String);
    void checkResponse(String);
    // void usbUp();
    // void pinUp();
    // void usbDown();
    // void pinDown();
};

extern SERIALS serials;

#endif