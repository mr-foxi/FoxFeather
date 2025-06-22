#include <wifi.h>
#include <oled.h>
#include <WiFi.h>
#include <payloadsList.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */
#include <pass.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */

WIFI::WIFI() {}

void WIFI::up() {
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
void WIFI::RSSI() {
    int signal = WiFi.RSSI();
    Serial.print("RSSI: ");
    Serial.println(signal);
    oled.printString("RSSI: ");
    oled.printlnInt(signal);
}
void WIFI::httpRequest() {
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
WiFiServer server(ESP_PORT); // USING TCP ON PORT 7408
void WIFI::apStart() {
    WiFi.softAPConfig(ESP_IP, ESP_IP, ESP_SUBNET);
    // Start Wi-Fi in AP mode
    WiFi.softAP(ESP_SSID, ESP_PASS);
    Serial.println("Access Point Started");
    Serial.println(WiFi.softAPIP()); // Should print ESP_IP from pass.h

    // Start TCP server
    server.begin();
    Serial.println("Server started");
}
void WIFI::apRecieve() {
    WiFiClient client = server.available();  // Wait for a client
    if (client) {
        Serial.println("Client connected");
        while (client.connected()) {
        if (client.available()) {
            String msg = client.readStringUntil('\n');
            Serial.print("Received: ");
            Serial.println(msg);
        }
        }
        client.stop();
        Serial.println("Client disconnected");
    }
}
void WIFI::sendMessage() {
    Serial.println("Connecting to AP...");
    WiFi.begin(ESP_SSID, ESP_PASS);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());

    // Connect to server
    WiFiClient client;
    if (client.connect(ESP_IP, ESP_PORT)) {
        Serial.println("Connected to Pycom server.");
        Serial.println("Sending Test Payload.");
        client.println("$Test Payload$");
        client.stop();
        Serial.println("Message sent and connection closed.");
    } else {
        Serial.println("Failed to connect to Pycom server.");
    }
}
void WIFI::sdPayload() {
    oled.printlnString("$PAYLOAD$");
    oled.printlnString("$SD$");
    Serial.println("Connecting to AP...");
    WiFi.begin(ESP_SSID, ESP_PASS);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());

    // Connect to server
    WiFiClient client;
    if (client.connect(ESP_IP, ESP_PORT)) {
        oled.printlnString("Roger Roger!");
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending SD Payload Activion.");
        client.println(payloadsList.CONST_SDCARD);
        client.stop();
        Serial.println("Message sent and connection closed.");
        delay(3000);
        oled.foxClear();
    } else {
        Serial.println("Failed to connect to dummyPayload server.");
        oled.printlnString("Connect Failed...");
        delay(3000);
        oled.foxClear();
    }
}
void WIFI::pullScript() {
    oled.printlnString("$PAYLOAD$");
    oled.printlnString("$PULLSCRIPT$");
    Serial.println("Connecting to AP...");
    WiFi.begin(ESP_SSID, ESP_PASS);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());

    // Connect to server
    WiFiClient client;
    if (client.connect(ESP_IP, ESP_PORT)) {
        oled.printlnString("Roger Roger!");
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending Pull Script Payload Activion.");
        client.println(payloadsList.CONST_PULLSCRIPT);
        client.stop();
        Serial.println("Message sent and connection closed.");
        delay(5000);
        oled.foxClear();
    } else {
        Serial.println("Failed to connect to dummyPayload server.");
        oled.printlnString("Connect Failed...");
        delay(5000);
        oled.foxClear();
    }
}
void WIFI::pullScriptExit() {
    oled.printlnString("$PAYLOAD$");
    oled.printlnString("$PULLSCRIPTEXIT$");
    Serial.println("Connecting to AP...");
    WiFi.begin(ESP_SSID, ESP_PASS);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());

    // Connect to server
    WiFiClient client;
    if (client.connect(ESP_IP, ESP_PORT)) {
        oled.printlnString("Roger Roger!");
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending Pull Script Exit Payload Activion.");
        client.println(payloadsList.CONST_PULLSCRIPTEXIT);
        client.stop();
        Serial.println("Message sent and connection closed.");
        delay(3000);
        oled.foxClear();
    } else {
        Serial.println("Failed to connect to dummyPayload server.");
        oled.printlnString("Connect Failed...");
        delay(3000);
        oled.foxClear();
    }
}
WIFI wifi = WIFI();
