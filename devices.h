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

#include <Arduino.h>
#include <Adafruit_SSD1306_STM32.h>

#include "devices::dac.h"
#include "devices::gate.h"
#include "devices::midi.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

namespace devices {

template<class T>
class DeviceManager
{
public:
    DeviceManager(T **devices, size_t count) :
        _devices(devices),
        _count(count)
    {}

    //
    // Count of devices
    //
    size_t
    getCount(void)
    {
        return _count;
    }

    //
    // Get a device
    //
    // id - ID of the device
    //
    T *
    get(size_t id)
    {
        if (id < _count) {
            return _devices[id];
        }
        return NULL;
    }

    //
    // Begin/Initialise devices
    //
    void
    begin(void)
    {
        for (size_t idx = 0; idx < _count; idx++) {
            _devices[idx]->begin();
        }
    }

private:
    T **_devices;
    size_t _count;
};

// DAC devices
extern DeviceManager<devices::dac::DAC> DACs;

// Gate devices
extern DeviceManager<devices::gate::Gate> Gates;

// MIDI devices
extern DeviceManager<devices::midi::MIDI> MIDI;

// Display device
extern Adafruit_SSD1306 display;

// Initialise hardware
void
begin(void);

} //! devices
