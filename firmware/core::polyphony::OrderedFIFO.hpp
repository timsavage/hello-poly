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
    
    ~OrderedFIFO(void) 
    {}

    const char *
    name(void) 
    {
        return "FIFO *";
    }

    void
    noteOff(uint8_t note, uint8_t)
    {
    }

    void
    noteOn(uint8_t note, uint8_t)
    {
    }

    void
    afterTouch(uint8_t)
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
