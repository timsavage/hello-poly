#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "config.h"

#include "devices::dac::DAC.h"
#include "devices::dac::MSP4X2X.hpp"
#include "devices::gate::Gate.h"
#include "devices::midi::Serial.h"
#include "devices::display::SSD1306.h"

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

#include "core::Router.hpp"

#include "core::ui::View.h"
#include "core::ui::HomeView.hpp"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))


//-- Define devices ------------------------------------------------

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

devices::gate::Gate gate0(PB12);
devices::gate::Gate gate1(PB13);
devices::gate::Gate gate2(PB14);
devices::gate::Gate gate3(PB15);
devices::gate::Gate *gateList[] = {&gate0, &gate1, &gate2, &gate3};

devices::midi::SerialMIDI midi(&Serial2);
devices::display::SSD1306 display;


//-- Controls ------------------------------------------------------

core::Key key0(&dac0, &gate0);
core::Key key1(&dac1, &gate1);
core::Key key2(&dac2, &gate2);
core::Key key3(&dac3, &gate3);

core::Key *keyList[] = {&key0, &key1, &key2, &key3};

core::ui::View *currentView = NULL;
core::Router routeTable;


//-- Initialisation code -------------------------------------------

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
    display.begin();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
}


//-- Message routing -----------------------------------------------

void
setupProgram(void)
{
    routeTable.empty();
    routeTable.add(0, new core::polyphony::OrderedLimit(&keyList[0], 4));
}

void
onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
    routeTable.onNoteOff(channel, note, velocity);
}

void
onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
    routeTable.onNoteOn(channel, note, velocity);
}

void
onAfterTouch(uint8_t channel, uint8_t value)
{
    routeTable.onAfterTouch(channel, value);
}

void
onPitchBend(uint8_t channel, int16_t change)
{
    routeTable.onPitchBend(channel, change);
}

void
onControlChange(uint8_t channel, uint8_t control, uint8_t value)
{
    static core::polyphony::PolyphonyMode currentMode;

    if (control == 0x4b) {
        core::polyphony::PolyphonyMode mode = (core::polyphony::PolyphonyMode)((value >> 2) % 8);
        if (mode != currentMode) {
            currentMode = mode;
            core::polyphony::Polyphony *newModel = NULL;

            switch(mode) {
            case core::polyphony::ModeMonoPress:
                newModel = new core::polyphony::MonoPress(&keyList[0], 1);
                break;

            case core::polyphony::ModeMonoSingle:
                newModel = new core::polyphony::MonoSingle(&keyList[0], 1);
                break;

            case core::polyphony::ModeMonoTranspose:
                newModel = new core::polyphony::MonoTranspose(&keyList[0], 1);
                break;

            case core::polyphony::ModeOrderedLIFO:
                newModel = new core::polyphony::OrderedLIFO(&keyList[0], 4);
                break;

            case core::polyphony::ModeOrderedFIFO:
                newModel = new core::polyphony::OrderedFIFO(&keyList[0], 4);
                break;

            case core::polyphony::ModeOrderedLimit:
                newModel = new core::polyphony::OrderedLimit(&keyList[0], 4);
                break;

            case core::polyphony::ModePositionalLow:
                newModel = new core::polyphony::PositionalLow(&keyList[0], 4);
                break;

            case core::polyphony::ModePositionalHigh:
                newModel = new core::polyphony::PositionalHigh(&keyList[0], 4);
                break;
            }
            routeTable.updateModel(0, newModel);

            Serial.print("Activate model: "); Serial.println(newModel->name());
            String fmt("M: ");
            fmt += newModel->name();
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

    currentView = new core::ui::HomeView();
}

void 
loop(void) 
{
    midi.loop();

    if (currentView->renderRequired()) {
        currentView->render(&display);
    }
}
