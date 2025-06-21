#include <serials.h>
#include <oled.h>

HardwareSerial pinSerial(1); // Use UART1 (you can pick another depending on your setup)

SERIALS::SERIALS() {}

void SERIALS::usbInit() {
    Serial.begin(SERIALS_BAUD);
    Serial.println("Hello USB Serial World!");
}

void SERIALS::pinInit() {
    pinSerial.begin(SERIALS_BAUD, SERIAL_8N1, RX_PIN, TX_PIN);
}

void SERIALS::pinSendHello() {
    pinSerial.println("Hello DUE!");
}

String SERIALS::pinRead() {
    if (pinSerial.available()) {
        String msg = pinSerial.readStringUntil('\n');
        msg.trim();
        return msg;
    } else {
        // Serial.println("Serial pins not available...");
        return "!ERROR: 222!";
    }
}

void SERIALS::print(String msg) {
    Serial.println(msg);
    pinSerial.println(msg);
}

ResponseCode parseResponse(String response) {
  response.trim();
  if (response == "") return RESPONSE_EMPTY;
  if (response == "Hello WING!") return RESPONSE_HELLO;
//   if (response == "OK") return RESPONSE_PULLSCRIPT;
  if (response == "Error") return RESPONSE_ERROR;
  if (response == "!ERROR: 404!") return RESPONSE_ERROR404;
  if (response == "!ERROR: 222!") return RESPONSE_ERROR222;
  return RESPONSE_UNKNOWN;
}

void SERIALS::checkResponse(String response) {
    switch(parseResponse(response)) {
        case RESPONSE_EMPTY:
            Serial.println("No Response Yet...");
            break;
        case RESPONSE_ERROR:
            Serial.println("Response Error");
            break;
        case RESPONSE_ERROR404:
            Serial.println("!Error: 404! - Error Not Found");
            break;
        case RESPONSE_ERROR222:
            Serial.println("!Error: 222! - Serial Pin Not Available");
            break;
        case RESPONSE_HELLO:
            oled.clear();
            oled.printlnString("Recieved Hello!!!");
            Serial.println("Recieved Hello!!");
            break;
        // case RESPONSE_SDPAYLOAD:
        //     sd.getPayload(response);
        //     break;
        case RESPONSE_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;

    }
}
SERIALS serials = SERIALS();