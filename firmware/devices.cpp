#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "devices.h"

#include "devices::dac::MSP4X2X.h"
#include "devices::midi::Serial.h"

using namespace devices;

/// DAC configuration ////////////////////////////////////////////////////////

dac::MSP4X22 dac0(4, MSP4X22_DAC_A);
dac::MSP4X22 dac1(4, MSP4X22_DAC_B);
dac::MSP4X22 dac2(5, MSP4X22_DAC_A);
dac::MSP4X22 dac3(5, MSP4X22_DAC_B);
dac::MSP4X22 dac4(6, MSP4X22_DAC_A);
dac::MSP4X22 dac5(6, MSP4X22_DAC_B);

dac::DAC* dacList[] = {&dac0, &dac1, &dac2, &dac3, &dac4, &dac5};
DeviceManager<dac::DAC> DACs(dacList, ARRAY_SIZE(dacList)); 


/// Gate configuration ///////////////////////////////////////////////////////

// gate::Gate gate0(PB12);
// gate::Gate gate1(PB13);
// gate::Gate gate2(PB14);
// gate::Gate gate3(PB15);

// gate::Gate* gateList[] = {&gate0, &gate1, &gate2, &gate3};
// DeviceManager<gate::Gate> Gates(gateList, ARRAY_SIZE(gateList)); 


/// MIDI Port configuration //////////////////////////////////////////////////

midi::SerialMIDI midi0(&Serial2);

midi::MIDI* midiList[] = {&midi0};
DeviceManager<midi::MIDI> MIDI(midiList, ARRAY_SIZE(midiList)); 


/// Display configuration ////////////////////////////////////////////////////

Adafruit_SSD1306 display(-1);
