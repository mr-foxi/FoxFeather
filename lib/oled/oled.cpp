#include <oled.h>

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

oledWing::oledWing() {}

void oledWing::init() {
  delay(250); // wait for the OLED to power up
  display.begin(0x3C, true); // Address 0x3C default
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.

  display.clearDisplay(); // SPLASHSCREEN BUFFER DISPLAY BYPASS
  display.display();
  display.clearDisplay(); // SPLASHSCREEN BUFFER DISPLAY BYPASS
  display.display();

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  // text display settings
  display.setRotation(1); 
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
}

void oledWing::clear() {
  display.clearDisplay();
  display.setCursor(0,0);  
  // display.display();
}

void oledWing::printlnString(String txt) {
  display.println(txt);
  display.display(); // actually display all of the above
}
void oledWing::printString(String txt) {
  display.print(txt);
  display.display(); // actually display all of the above
}
void oledWing::printlnInt(int num) {
  display.println(num);
  display.display(); // actually display all of the above
}
void oledWing::printInt(int num) {
  display.print(num);
  display.display(); // actually display all of the above
}

oledWing oled = oledWing();

// void oledWing::testPrint() {

//   Serial.println("128x64 OLED FeatherWing test");
//   delay(250); // wait for the OLED to power up
//   display.begin(0x3C, true); // Address 0x3C default

//   Serial.println("OLED begun");

//   // Show image buffer on the display hardware.
//   // Since the buffer is intialized with an Adafruit splashscreen
//   // internally, this will display the splashscreen.
//   display.display();
//   delay(1000);

//   // Clear the buffer.
//   display.clearDisplay();
//   display.display();

//   display.setRotation(1);
//   Serial.println("Button test");

//   pinMode(BUTTON_A, INPUT_PULLUP);
//   pinMode(BUTTON_B, INPUT_PULLUP);
//   pinMode(BUTTON_C, INPUT_PULLUP);

//   // text display tests
//   display.setTextSize(1);
//   display.setTextColor(SH110X_WHITE);
//   display.setCursor(0,0);
//   display.println("HELLO WORLD!");
//   display.display(); // actually display all of the above
// }
