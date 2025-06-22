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

void SERIALS::sdPayload() {
    Serial.println();
    Serial.println("Sending Command: sdPayload");
    oled.clear();
    oled.printlnString("Sending Command:");
    oled.printlnString("sdPayload");
    // pinSerial.println("sdPayload");
    pinSerial.println("payload");
}
void SERIALS::pullScript() {
    Serial.println();
    Serial.println("Sending Command: pullScript");
    oled.clear();
    oled.printlnString("Sending Command:");
    oled.printlnString("pullScript");
    pinSerial.println("pullScript");
}

String SERIALS::pinRead() {
    if (pinSerial.available()) {
        String msg = pinSerial.readStringUntil('\n');
        msg.trim();
        return msg;
    } else {
        return "";
    //     return "!ERROR: 222!"; GOOD DEBUG LINE
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
  if (response == "Error") return RESPONSE_ERROR;
  if (response == "!ERROR: 404!") return RESPONSE_ERROR404;
//   if (response == "!ERROR: 222!") return RESPONSE_ERROR222; GOOD DEBUG LINE
  if (response == "#Roger Roger#") return RESPONSE_ROGER;
  return RESPONSE_UNKNOWN;
}

void SERIALS::checkResponse(String response) {
    switch(parseResponse(response)) {
        case RESPONSE_EMPTY:
            // Serial.println("No Response Yet..."); GOOD DEBUG LINE
            break;
        case RESPONSE_ERROR:
            Serial.println("Response Error");
            break;
        case RESPONSE_ERROR404:
            Serial.println("!Error: 404! - Error Not Found");
            break;
        // case RESPONSE_ERROR222:
        //     Serial.println("!Error: 222! - Serial Pin Not Available"); GOOD DEBUG LINE
        //     break;
        case RESPONSE_ROGER:
            Serial.println("Roger Roger!");
            // oled.clear();
            oled.printlnString("Roger Roger!");
            delay(3000);
            oled.foxClear();
            break;
        case RESPONSE_HELLO:
            oled.printString(".");
            Serial.print(".");
            break;
        case RESPONSE_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;

    }
}
SERIALS serials = SERIALS();