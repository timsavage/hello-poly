/**
 * The HAL provides a separation between application logic and physical 
 * hardware.
 * 
 * Currently this HAL supports:
 * 
 *  - DACS  0-3
 *  - Gates 0-3
 */ 
#pragma once

#include "devices::dac.hpp"
#include "devices::gate.hpp"
#include "devices::midi.hpp"

#include "devices::dac::MSP4X2X.hpp"
#include "devices::midi::Serial.hpp"

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


/// DAC configuration ////////////////////////////////////////////////////////

dac::MSP4X22 dac0(6, MSP4X22_DAC_A);
dac::MSP4X22 dac1(6, MSP4X22_DAC_B);
dac::MSP4X22 dac2(7, MSP4X22_DAC_A);
dac::MSP4X22 dac3(7, MSP4X22_DAC_B);

dac::DAC* dacList[] = {&dac0, &dac1, &dac2, &dac3};
DeviceManager<dac::DAC> DACs(dacList, ARRAY_SIZE(dacList)); 


/// Gate configuration ///////////////////////////////////////////////////////

gate::Gate gate0(8);
gate::Gate gate1(9);

gate::Gate* gateList[] = {&gate0, &gate1};
DeviceManager<gate::Gate> Gates(gateList, ARRAY_SIZE(gateList)); 


/// MIDI Port configuration //////////////////////////////////////////////////

midi::SerialMIDI midi0;

midi::MIDI* midiList[] = {&midi0};
DeviceManager<midi::MIDI> MIDI(midiList, ARRAY_SIZE(midiList)); 

} //! devices
