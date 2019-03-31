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

#include "core::Router.h"

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

devices::midi::SerialMIDI midi(&Serial3);
devices::display::SSD1306 display;


//-- Controls ------------------------------------------------------

core::Key key0(&dac0, &gate0);
core::Key key1(&dac1, &gate1);
core::Key key2(&dac2, &gate2);
core::Key key3(&dac3, &gate3);

core::Key *keyList[] = {&key0, &key1, &key2, &key3};

core::ui::View *currentView = NULL;


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
    core::Router.begin(&midi);

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
    core::Router.empty();
    core::Router.add(0, core::polyphony::ModeOrderedLimit, &keyList[0], 4);
}

void
onControlChange(uint8_t channel, uint8_t control, uint8_t value)
{
    static core::polyphony::PolyphonyMode currentMode;

    if (control == 0x4b) {
        core::polyphony::PolyphonyMode mode = (core::polyphony::PolyphonyMode)((value >> 2) % 8);
        if (mode != currentMode) {
            currentMode = mode;

            core::Router.empty();
            core::Router.add(0, mode, &keyList[0], 4);

            Serial1.print("Activate mode: "); Serial1.print(mode); Serial1.print(" - ");
            core::Route *route = core::Router.getRoute(0);
            Serial1.println(route->mode == NULL);
            Serial1.println(route->mode->name());
            String fmt("M: ");
            fmt += route->mode->name();
        }
    } else {
        Serial1.print("Channel: "); Serial1.print(channel);
        Serial1.print("; Control: "); Serial1.print(control, HEX); 
        Serial1.print("; Value: "); Serial1.println(value);  
    }
}

void
onProgramChange(uint8_t channel, uint8_t program)
{
    Serial1.print("Channel: "); Serial1.print(channel);
    Serial1.print("; Program: "); Serial1.println(program);

    display.setCursor(0, 0);
    display.clearDisplay();
    display.print("Program: "); display.print(program); 
    display.display();
}

void 
setup(void) 
{
    // Set up the built-in LED pin as an output:
    pinMode(PC13, OUTPUT);

    Serial1.begin(115200);
    Serial1.print("Hello Polly - Savage.Company - v0.1\n");
    
    setupDevices();
    setupProgram();

    midi.controlChangeCallback(&onControlChange);
    midi.programChangeCallback(&onProgramChange);

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
