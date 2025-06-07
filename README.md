# Fox Feather Project

## Adafruit **ESP32** HUZZAH32, 128x64 OLED FeatherWing
## Made in Archlinux Visual Studio Code with **PlatformIO**

### platform.ini Settings Information

#### Defining where the ESP32 is connected
upload_port = 
Default is: /dev/ttyUSB0 

#### Including / Excluding Libraries when Compiling
build_flags =
To exclude a library from compiling, comment out the corrosponding line
i.e: To exlude the OLED screen library from compiling.
Change "-D OLED_h" to "; -D OLED_h"

#### pass.h format: 
const char WIFI_SSID[] = "YOUR_SSID"; 
const char WIFI_PASSWORD[] = "YOUR_PASSWORD"; 

#### HUZZAH32 (ESP32)
https://www.adafruit.com/product/3405
#### Arduino BLE
https://docs.arduino.cc/libraries/arduinoble/
#### Arduino WiFi
