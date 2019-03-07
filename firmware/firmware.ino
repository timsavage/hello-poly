#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// #include "devices.h"
#include "devices::gate.h"
#include "devices::midi::Serial.h"

devices::gate::Gate gate0(PB12);
devices::gate::Gate gate1(PB13);
devices::gate::Gate gate2(PB14);
devices::gate::Gate gate3(PB15);

devices::gate::Gate* gateList[] = {&gate0, &gate1, &gate2, &gate3};

devices::midi::SerialMIDI midi(&Serial2);


/// Initialisation code //////////////////////////////////////////////////////

void setup() {
  // Set up the built-in LED pin as an output:
  pinMode(PC13, OUTPUT);

  Serial.begin(115200);
  
  Wire.begin();
  SPI.begin();

  // devices::DACs.begin();
  for (int i; i < 4; i++) {
    gateList[i]->begin();
    gateList[i]->setState(devices::gate::GateClosed);
  }
  midi.begin();
  // devices::Gates.begin();
  // devices::MIDI.begin();
  
  // delay(500);  // Delay required for display driver.
  // devices::display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


  // devices::display.clearDisplay();
  // devices::display.setCursor(0, 0);
  // devices::display.setTextSize(2);
  // devices::display.setTextColor(WHITE);
  // devices::display.print("Savage\nCompany 2");
  // devices::display.display();

  Serial.print("Started...");
}

void loop() {
  midi.loop();

  // Let devices handle events
  // devices::loop();
  delay(100);
  static word level = 0;
  level ++;
  if (level >= 4095) level = 0;

  for (int idx = 0; idx < 4; idx++) {
    gateList[idx]->setState((devices::gate::GateState)((level & 0b111) == idx));
  }
}
