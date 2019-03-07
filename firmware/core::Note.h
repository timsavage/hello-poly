/**
 * Note
 * 
 */
#pragma once

#include "devices::dac.h"
#include "devices::gate.h"

namespace core {

using namespace devices;

class Note
{
public:
    Note(dac::DAC *dac, gate::Gate *gate);

    uint8_t
    getCurrentNote(void);

    void
    setCurrentNote(uint8_t note);

private:
    dac::DAC *_dac;
    gate::Gate *_gate;
   
};

} //! core
