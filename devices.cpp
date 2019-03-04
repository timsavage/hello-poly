#include <Arduino.h>
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

dac::DAC* dacList[] = {&dac0, &dac1, &dac2, &dac3};
devices::DeviceManager<devices::dac::DAC> devices::DACs(dacList, ARRAY_SIZE(dacList)); 


/// Gate configuration ///////////////////////////////////////////////////////

devices::gate::Gate gate0(8);
devices::gate::Gate gate1(9);

devices::gate::Gate* gateList[] = {&gate0, &gate1};
devices::DeviceManager<devices::gate::Gate> devices::Gates(gateList, ARRAY_SIZE(gateList)); 


/// MIDI Port configuration //////////////////////////////////////////////////

devices::midi::SerialMIDI midi0;

devices::midi::MIDI* midiList[] = {&midi0};
devices::DeviceManager<devices::midi::MIDI> devices::MIDI(midiList, ARRAY_SIZE(midiList)); 


/// Display configuration ////////////////////////////////////////////////////

Adafruit_SSD1306 devices::display(-1);


void
devices::begin(void)
{
    Serial.begin(115200);
    Wire.begin();

    DACs.begin();
    Gates.begin();
    MIDI.begin();
    
    delay(400);  // Delay required for display driver.
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);    
}
