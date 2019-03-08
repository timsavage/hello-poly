#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "devices::dac::DAC.h"
#include "devices::dac::MSP4X2X.h"
#include "devices::gate::Gate.h"
#include "devices::midi::Serial.h"

#include "core::Key.h"
#include "core::polyphony::Polyphony.h"
#include "core::polyphony::Mono.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

// Define DACs
devices::dac::MSP4X22 dac0(PA3, MSP4X22_DAC_A);
devices::dac::MSP4X22 dac1(PA3, MSP4X22_DAC_B);
devices::dac::MSP4X22 dac2(PA4, MSP4X22_DAC_A);
devices::dac::MSP4X22 dac3(PA4, MSP4X22_DAC_B);
devices::dac::MSP4X22 dac4(PA5, MSP4X22_DAC_A);
devices::dac::MSP4X22 dac5(PA5, MSP4X22_DAC_B);
devices::dac::DAC *dacList[] = {&dac0, &dac1, &dac2, &dac3, &dac4, &dac5};

// Define devices
devices::gate::Gate gate0(PB12);
devices::gate::Gate gate1(PB13);
devices::gate::Gate gate2(PB14);
devices::gate::Gate gate3(PB15);
devices::gate::Gate *gateList[] = {&gate0, &gate1, &gate2, &gate3};

devices::midi::SerialMIDI midi(&Serial2);
// Adafruit_SSD1306 display;

core::Key key0(&dac0, &gate0);
core::Key key1(&dac1, &gate1);
core::Key key2(&dac2, &gate2);
core::Key key3(&dac3, &gate3);

core::polyphony::Polyphony *models[4] = {NULL, NULL, NULL, NULL};

/// Initialisation code //////////////////////////////////////////////////////

void 
setupDevices(void)
{
  Wire.begin();
  SPI.begin();

  // Initialise DACs
  for (size_t i = 0; i < ARRAY_SIZE(dacList); i++) {
    dacList[i]->begin();
  }

  // Initialise gates
  for (size_t i = 0; i < ARRAY_SIZE(gateList); i++) {
    gateList[i]->begin();
    gateList[i]->reset();
  }

  midi.begin();
  // delay(500);
  // display.begin(SSD1306_SWITCHCAPVCC, 0x3C)
}

void
setupProgram(void)
{
  models[0] = new core::polyphony::Mono(&key0);
  models[1] = new core::polyphony::Mono(&key1);
}

void
onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
  if (channel == 0) {
    models[0]->noteOff(note, velocity);
  }
  if (channel == 1) {
    models[1]->noteOff(note, velocity);
  }
}

void
onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
  if (channel == 0) {
    models[0]->noteOn(note, velocity);
  }
  if (channel == 1) {
    models[1]->noteOn(note, velocity);
  }
}

void 
setup(void) 
{
  // Set up the built-in LED pin as an output:
  pinMode(PC13, OUTPUT);

  Serial.begin(115200);
  
  setupDevices();
  setupProgram();

  midi.noteOffCallback(&onNoteOff);
  midi.noteOnCallback(&onNoteOn);

  // devices::display.clearDisplay();
  // devices::display.setCursor(0, 0);
  // devices::display.setTextSize(2);
  // devices::display.setTextColor(WHITE);
  // devices::display.print("Savage\nCompany 2");
  // devices::display.display();

  Serial.print("Started...");
}

void 
loop(void) 
{
  midi.loop();
}
