#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_STM32.h>

#include "devices::hal.hpp"

Adafruit_SSD1306 display(-1);

void setup() {
  Serial.begin(115200);
  Serial.println("Hi!");
  Wire.begin();

  // Set up the built-in LED pin as an output:
  pinMode(PC13, OUTPUT);

  // Configure hardware
  devices::DACs.begin();
  devices::Gates.begin();
  devices::MIDI.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(WHITE);    
  display.print("Savage\nCompany");
  display.display();
}

void loop() {
  digitalWrite(PC13, !digitalRead(PC13));
  delay(1000);
  static word level = 0;
  level += 128;
  devices::DACs.get(1)->setValue(level);
}
