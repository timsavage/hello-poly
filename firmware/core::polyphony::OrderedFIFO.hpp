/**
 * Ordered FIFO Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include "config.h"
#include "core::KeyList.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

class OrderedFIFO : public Polyphony
{
public:
    OrderedFIFO(core::Key** keys, size_t keyCount) :
        _keyList(keys, keyCount)
    {}

    const char *
    name(void) 
    {
        return "FIFO *";
    }

    void
    noteOff(uint8_t note, uint8_t velocity)
    {
    }

    void
    noteOn(uint8_t note, uint8_t velocity)
    {
    }

    void
    afterTouch(uint8_t value)
    {

    }
    
    void
    pitchBend(int16_t amount)
    {
        _keyList.pitchBend(amount);
    }

private:
    KeyList _keyList;
};

}} //! polyphony::core
