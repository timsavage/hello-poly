#pragma once

#include <Arduino.h>

namespace devices {
namespace gate {

//
// Gate state
//
enum GateState : uint8_t
{
    GateOpen   = 0,
    GateClosed = 1,
};


//
// Gate device
//
class Gate
{
public:
    Gate(uint8_t pin) :
        _pin(pin)
    {}

    void
    begin(void)
    {
        pinMode(_pin, OUTPUT);
    }

    void
    setState(GateState state)
    {
        digitalWrite(_pin, state);
    }

private:
    uint8_t _pin;
};

}} //! gate::devices
