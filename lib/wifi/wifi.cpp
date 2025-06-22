#include <wifi.h>
#include <oled.h>
#include <WiFi.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */
#include <pass.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */

// Your Pycom's AP credentials
const char* ESP_SSID = "esp-ap";
const char* ESP_PASS = "TestPass42";

// Server info
const char* host = "192.168.4.1";
const uint16_t port = 7408;

WIFI::WIFI() {}
// wifiHTTP::wifiHTTP() {}

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
WiFiServer server(port); // USING TCP ON PORT 7408
void WIFI::apStart() {
    // Serial.begin(115200);

    // Start Wi-Fi in AP mode
    WiFi.softAP(ESP_SSID, ESP_PASS);
    Serial.println("Access Point Started");
    Serial.println(WiFi.softAPIP()); // Should print 192.168.4.1

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
    //
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
    if (client.connect(host, port)) {
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
    //
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
    if (client.connect(host, port)) {
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending SD Payload Activion.");
        oled.printlnString("sdPayload requested...");
        client.println("$PAYLOAD - SDCARD$");
        client.stop();
        Serial.println("Message sent and connection closed.");
        oled.printlnString("Roger Roger...");
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
    //
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
    if (client.connect(host, port)) {
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending Pull Script Payload Activion.");
        oled.printlnString("pullScript requested...");
        client.println("$PAYLOAD - PULLSCRIPT$");
        client.stop();
        Serial.println("Message sent and connection closed.");
        oled.printlnString("Roger Roger...");
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
    //
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
    if (client.connect(host, port)) {
        Serial.println("Connected to dummyPayload server.");
        Serial.println("Sending Pull Script Exit Payload Activion.");
        oled.printlnString("pullScriptExit requested...");
        client.println("$PAYLOAD - PULLSCRIPTEXIT$");
        client.stop();
        Serial.println("Message sent and connection closed.");
        oled.printlnString("Roger Roger...");
        delay(5000);
        oled.foxClear();
    } else {
        Serial.println("Failed to connect to dummyPayload server.");
        oled.printlnString("Connect Failed...");
        delay(5000);
        oled.foxClear();
    }
}
WIFI wifi = WIFI();
// wifiHTTP http = wifiHTTP();
