#include <Arduino.h>

#include "devices.h"

/// Initialisation code //////////////////////////////////////////////////////

void setup() {
  // Initialise core devices
  devices::begin();

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
