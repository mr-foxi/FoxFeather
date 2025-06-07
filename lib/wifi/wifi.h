#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class WIFI
{
public:
    WIFI();
    void up();
    void RSSI();
    void httpRequest();
    String HOST_NAME   = "http://httpforever.com";
    String PATH_NAME   = "";
    // String PATH_NAME   = "/products/arduino.php";
    String queryString = "temperature=26&humidity=70"; // OPTIONAL
};

// class wifiHTTP
// {
// public:
//     wifiHTTP();
// };
extern WIFI wifi;
// extern wifiHTTP http;

#endif