#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"

#include "devices::dac::DAC.h"
#include "devices::dac::MSP4X2X.hpp"
#include "devices::gate::Gate.h"
#include "devices::midi::Serial.h"

#include "core::Control.h"
#include "core::Key.h"

#include "core::polyphony::Polyphony.h"
#include "core::polyphony::MonoPress.hpp"
#include "core::polyphony::MonoSingle.hpp"
#include "core::polyphony::MonoTranspose.hpp"
#include "core::polyphony::OrderedFIFO.hpp"
#include "core::polyphony::OrderedLIFO.hpp"
#include "core::polyphony::OrderedLimit.hpp"
#include "core::polyphony::PositionalHigh.hpp"
#include "core::polyphony::PositionalLow.hpp"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

// Define DACs
devices::dac::MSP4X22 dac0(PA1, MSP4X22_DAC_A);
devices::dac::MSP4X22 dac1(PA1, MSP4X22_DAC_B);
// devices::dac::MSP4X22 dac2(PA4, MSP4X22_DAC_A);
// devices::dac::MSP4X22 dac3(PA4, MSP4X22_DAC_B);
// devices::dac::MSP4X22 dac4(PA5, MSP4X22_DAC_A);
// devices::dac::MSP4X22 dac5(PA5, MSP4X22_DAC_B);
// devices::dac::MockDAC dac0;
// devices::dac::MockDAC dac1;
devices::dac::MockDAC dac2;
devices::dac::MockDAC dac3;
devices::dac::MockDAC dac4;
devices::dac::MockDAC dac5;
devices::dac::DAC *dacList[] = {&dac0, &dac1, &dac2, &dac3, &dac4, &dac5};

// Define devices
devices::gate::Gate gate0(PB12);
devices::gate::Gate gate1(PB13);
devices::gate::Gate gate2(PB14);
devices::gate::Gate gate3(PB15);
devices::gate::Gate *gateList[] = {&gate0, &gate1, &gate2, &gate3};

devices::midi::SerialMIDI midi(&Serial2);
Adafruit_SSD1306 display;

core::Key key0(&dac0, &gate0);
core::Key key1(&dac1, &gate1);
core::Key key2(&dac2, &gate2);
core::Key key3(&dac3, &gate3);
core::Key *keyList[] = {&key0, &key1, &key2, &key3};

core::polyphony::PolyphonyMode currentMode;


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

    // Delay Initialisation so device can stablise after power is applied.
    delay(500);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Savage\nCompany");
    display.display();
}


/// Message routing //////////////////////////////////////////////////////

typedef struct {
    uint8_t channel;
    core::polyphony::Polyphony *model;
} Route;

Route routeTable[MAX_NOTES] = {
    {255, NULL},
    {255, NULL},
    {255, NULL},
    {255, NULL},
};

void
setupProgram(void)
{
    routeTable[0].channel = 0;
    routeTable[0].model = new core::polyphony::MonoSingle(&key0);

    routeTable[1].channel = 1;
    routeTable[1].model = new core::polyphony::OrderedLimit(&keyList[1], 3);
}

void
onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
    Route *route;
    for (size_t idx = 0; idx < MAX_NOTES; idx++) {
        route = &routeTable[idx];
        if (route->channel == channel) {
            route->model->noteOff(note, velocity);
        }
    }
}

void
onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
    Route *route;
    for (size_t idx = 0; idx < MAX_NOTES; idx++) {
        route = &routeTable[idx];
        if (route->channel == channel) {
            route->model->noteOn(note, velocity);
        }
    }
}

void
onAfterTouch(uint8_t channel, uint8_t value)
{
    Route *route;
    for (size_t idx = 0; idx < MAX_NOTES; idx++) {
        route = &routeTable[idx];
        if (route->channel == channel) {
            route->model->afterTouch(value);
        }
    }
}

void
onPitchBend(uint8_t channel, int16_t change)
{
    Route *route;
    for (size_t idx = 0; idx < MAX_NOTES; idx++) {
        route = &routeTable[idx];
        if (route->channel == channel) {
            route->model->pitchBend(change);
        }
    }
}

void
onControlChange(uint8_t channel, uint8_t control, uint8_t value)
{
    if (control == 0x4b) {
        core::polyphony::PolyphonyMode mode = (core::polyphony::PolyphonyMode)((value >> 2) % 8);
        if (mode != currentMode) {
            currentMode = mode;
            core::polyphony::Polyphony *newModel = NULL;

            switch(mode) {
            case core::polyphony::ModeMonoPress:
                delete routeTable[0].model;
                routeTable[0].model = newModel = new core::polyphony::MonoPress(&key0);
                break;

            case core::polyphony::ModeMonoSingle:
                delete routeTable[0].model;
                routeTable[0].model = newModel = new core::polyphony::MonoSingle(&key0);
                break;

            case core::polyphony::ModeMonoTranspose:
                delete routeTable[0].model;
                routeTable[0].model = newModel = new core::polyphony::MonoTranspose(&key0);
                break;

            case core::polyphony::ModeOrderedLIFO:
                delete routeTable[1].model;
                routeTable[1].model = newModel = new core::polyphony::OrderedLIFO(&keyList[1], 3);
                break;

            case core::polyphony::ModeOrderedFIFO:
                delete routeTable[1].model;
                routeTable[1].model = newModel = new core::polyphony::OrderedFIFO(&keyList[1], 3);
                break;

            case core::polyphony::ModeOrderedLimit:
                delete routeTable[1].model;
                routeTable[1].model = newModel = new core::polyphony::OrderedLimit(&keyList[1], 3);
                break;

            case core::polyphony::ModePositionalLow:
                delete routeTable[1].model;
                routeTable[1].model = newModel = new core::polyphony::PositionalLow(&keyList[1], 3);
                break;

            case core::polyphony::ModePositionalHigh:
                delete routeTable[1].model;
                routeTable[1].model = newModel = new core::polyphony::PositionalHigh(&keyList[1], 3);
                break;
            }

            Serial.print("Activate model: "); Serial.println(newModel->name());
            display.clearDisplay();
            display.setCursor(0, 0);
            display.print("M: "); display.print(newModel->name());
            display.display();
        }
    } else {
        Serial.print("Channel: "); Serial.print(channel);
        Serial.print("; Control: "); Serial.print(control, HEX); 
        Serial.print("; Value: "); Serial.println(value);  
    }
}

void
onProgramChange(uint8_t channel, uint8_t program)
{
    Serial.print("Channel: "); Serial.print(channel);
    Serial.print("; Program: "); Serial.println(program);
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
    midi.controlChangeCallback(&onControlChange);
    midi.programChangeCallback(&onProgramChange);
    midi.afterTouchCallback(&onAfterTouch);
    //midi.pitchBendCallback(&onPitchBend);

    Serial.print("Started...");
}

void 
loop(void) 
{
    midi.loop();
}
