#include "core::Key.h"

using namespace core;
using namespace devices;

Key::Key(dac::DAC *dac, gate::Gate *gate)
: _dac(dac),
  _gate(gate)
{}

void
Key::press(uint8_t note, uint16_t bend)
{

}

void
Key::transpose(uint8_t note, uint16_t bend)
{

}

void
Key::release(uint8_t note)
{
    
}
