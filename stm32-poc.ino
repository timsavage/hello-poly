#include <Arduino.h>
#include <Wire.h>

#include "devices::hal.h"

/// Initialisation code //////////////////////////////////////////////////////

void setup() {
  // Iitialise hardware
  Serial.begin(115200);
  Wire.begin();

  devices::DACs.begin();
  devices::Gates.begin();
  devices::MIDI.begin();
  delay(400);  // Delay required for display driver.
  devices::display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Set up the built-in LED pin as an output:
  pinMode(PC13, OUTPUT);

  devices::display.clearDisplay();
  devices::display.setCursor(0, 0);
  devices::display.setTextSize(2);
  devices::display.setTextColor(WHITE);
  // devices::display.print(idx);
  devices::display.print("Savage\nCompany");
  devices::display.display();
}

void loop() {
  digitalWrite(PC13, !digitalRead(PC13));
  delay(1000);
  static word level = 0;
  level += 64;
  if (level >= 4095) level = 0;
  // devices::DACs.get(1)->setValue(level);

  devices::display.clearDisplay();
  devices::display.setCursor(0, 0);
  devices::display.print(level);
  devices::display.display();
}
