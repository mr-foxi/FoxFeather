#include <wifi.h>
#include <oled.h>

WIFI::WIFI() {}
wifiHTTP::wifiHTTP() {}

void WIFI::wifiUp() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting");
    oled.printString("Connecting");
while(WiFi.status() != WL_CONNECTED) { 
        int i = 0;    
        delay(1000);
        Serial.print(".");
        oled.printString(".");
        i++;
        if (i > 60) {break;}
    }
    if (WL_CONNECTED) {
        oled.clear();
        Serial.print("Connected to WiFi network with IP Address: ");
        oled.printlnString("Connected to WiFi!");
        oled.printlnString("IP address: ");
        String ipAddr = WiFi.localIP().toString();
        Serial.println(WiFi.localIP());
        oled.printlnString(ipAddr);
    } else {
        Serial.println("WiFi Connection Failed");
        oled.printlnString("WiFi Connection Failed");
    }
}

void wifiHTTP::httpRequest() {
    HTTPClient http;
    http.begin(HOST_NAME + PATH_NAME); //HTTP
    int httpCode = http.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
    // file found at server
    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
        oled.printString(payload);
    } else {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        oled.printString("[HTTP] GET... code: ");
        oled.printlnInt(httpCode);
    }
    } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        oled.printString("[HTTP] GET... failed, error: ");
        oled.printlnInt(httpCode);
    }
    http.end();
}
WIFI wifi = WIFI();
wifiHTTP http = wifiHTTP();
