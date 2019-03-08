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


Key::Key(dac::DAC *dac, gate::Gate *gate)
: _dac(dac),
  _gate(gate)
{}

void
Key::press(uint8_t note, int16_t bend)
{
  if (_gate->getState()) {
    _gate->bounce();
  } else {
    _gate->close();
  }
}

void
Key::transpose(uint8_t note, int16_t bend)
{
  _gate->close();
}

void
Key::release(void)
{
  _gate->open();
}
