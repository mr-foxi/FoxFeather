#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char WIFI_SSID[] = "EXAMPLE_SSID";         // CHANGE IT
const char WIFI_PASSWORD[] = "EXAMPLE_PASSWD"; // CHANGE IT


//String PATH_NAME   = "/products/arduino.php";      // CHANGE IT

class WIFI
{
public:
    WIFI();
    void wifiUp();
};

class wifiHTTP
{
public:
    wifiHTTP();
    void httpRequest();
    String HOST_NAME   = "http://example.com"; // CHANGE IT
    String PATH_NAME   = "/test";// /products/arduino";      // CHANGE IT
    String queryString = "temperature=26&humidity=70"; // OPTIONAL
};
extern WIFI wifi;
extern wifiHTTP http;

#endif