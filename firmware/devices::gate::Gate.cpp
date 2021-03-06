#include "devices::gate::Gate.h"

using namespace devices::gate;


Gate::Gate(int pin)
: _pin(pin)
{}

void
Gate::begin(void)
{
    pinMode(_pin, OUTPUT);
}

void
Gate::reset(void)
{
    digitalWrite(_pin, 0);
}

void
Gate::open(void)
{
    digitalWrite(_pin, 0);
}

void
Gate::close(void)
{
    digitalWrite(_pin, 1);
}

GateState
Gate::toggle(void)
{
    uint8_t state = !digitalRead(_pin);
    digitalWrite(_pin, state);
    return (GateState)state;
}

GateState
Gate::bounce(uint16_t delay_ms)
{
    uint8_t state = digitalRead(_pin);
    digitalWrite(_pin, !state);
    delay(delay_ms);
    digitalWrite(_pin, state);
    return (GateState)state;
}

GateState
Gate::getState(void)
{
    return (GateState)digitalRead(_pin);
}

