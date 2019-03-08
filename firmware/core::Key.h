/**
 * Note
 * ~~~~
 *
 * A note is combination of a DAC and a Gate
 *
 */
#pragma once

#include "devices::dac::DAC.h"
#include "devices::gate::Gate.h"

namespace core {

class Key
{
public:
    Key(devices::dac::DAC *dac, devices::gate::Gate *gate);

    //
    // Press a key (this will retrigger if already pressed)
    //
    // A pitch bend can be applied.
    //
    void
    press(uint8_t note, int16_t bend=0);

    //
    // Transpose a key (this will not retrigger, but will close the gate if required)
    //
    // A pitch bend can be applied.
    //
    void
    transpose(uint8_t note, int16_t bend=0)
    
    //
    // Release a key
    //
    void
    release(uint8_t note);

private:
    devices::dac::DAC *_dac;
    devices::gate::Gate *_gate;

};

}  //! core

