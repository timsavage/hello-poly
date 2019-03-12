#include "core::Key.h"

using namespace core;
using namespace devices;

//
// Note map for a 12bit ADC utilising a 4.096V Vref
//
const int noteMap[] = {
       0,   42,   83,  125,  167,  208,  250,  292,  333,  375,  417,  458, 
     500,  542,  583,  625,  667,  708,  750,  792,  833,  875,  917,  958, 
    1000, 1042, 1083, 1125, 1167, 1208, 1250, 1292, 1333, 1375, 1417, 1458, 
    1500, 1542, 1583, 1625, 1667, 1708, 1750, 1792, 1833, 1875, 1917, 1958, 
    2000, 2042, 2083, 2125, 2167, 2208, 2250, 2292, 2333, 2375, 2417, 2458, 
    2500, 2542, 2583, 2625, 2667, 2708, 2750, 2792, 2833, 2875, 2917, 2958, 
    3000, 3042, 3083, 3125, 3167, 3208, 3250, 3292, 3333, 3375, 3417, 3458, 
    3500, 3542, 3583, 3625, 3667, 3708, 3750, 3792, 3833, 3875, 3917, 3958, 
    4000, 4042, 4083, 
};
const int noteCount = 99;


Key::Key(dac::DAC *dac, gate::Gate *gate, uint8_t offset, uint16_t bounce_ms)
: _dac(dac),
  _gate(gate),
  _offset(offset),
  _bounce_ms(bounce_ms),
  _note(NULL_NOTE),
  _step(0),
  _amount(0)
{}

void
Key::press(uint8_t note)
{
    _note = note;
    _step = noteMap[note - _offset];
    if (_gate->getState()) {
        _gate->open();
        delay(_bounce_ms);
    }
    _dac->setValue(_step);
    _gate->close();
}

void
Key::transpose(uint8_t note)
{
    _note = note;
    _step = noteMap[note - _offset];
    _dac->setValue(_step);
    _gate->close();
}

void
Key::release(void)
{
    _note = NULL_NOTE;
    _step = 0;
    _gate->open();
}

void
Key::pitchBend(int16_t amount)
{
    _amount = amount;
}

uint8_t
Key::getNote(void)
{
    return _note;
}

uint16_t
Key::getStep(void)
{
    return _step;
}

uint8_t
Key::isReleased(void)
{
    return _note == NULL_NOTE;
}
