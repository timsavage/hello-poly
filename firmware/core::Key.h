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

#define NULL_NOTE 255

namespace core {

class Key
{
public:
    Key(devices::dac::DAC *dac, devices::gate::Gate *gate, uint8_t offset=12, uint16_t bounce_ms=10);

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
    transpose(uint8_t note, int16_t bend=0);
    
    //
    // Release a key
    //
    void
    release(void);

    // 
    // Get the current note
    //
    uint8_t
    getNote(void);

    // 
    // Get the current step
    //
    uint16_t
    getStep(void);

    //
    // Key is released
    //
    uint8_t
    isReleased(void);

private:
    devices::dac::DAC *_dac;
    devices::gate::Gate *_gate;
    uint8_t _offset;
    uint16_t _bounce_ms;
    uint8_t _note;
    uint16_t _step;
};

}  //! core

