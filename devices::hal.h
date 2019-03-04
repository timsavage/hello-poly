/**
 * The HAL provides a separation between application logic and physical 
 * hardware.
 * 
 * Currently this HAL supports:
 * 
 *  - DACs       0-3
 *  - Display    0
 *  - Gates      0-3
 *  - MIDI Port  0
 */ 
#pragma once

#include <Adafruit_SSD1306_STM32.h>

#include "devices.hpp"
#include "devices::dac.h"
#include "devices::gate.h"
#include "devices::midi.h"

namespace devices {

extern DeviceManager<devices::dac::DAC> DACs;
extern DeviceManager<devices::gate::Gate> Gates;
extern DeviceManager<devices::midi::MIDI> MIDI;
extern Adafruit_SSD1306 display;

} //! devices
