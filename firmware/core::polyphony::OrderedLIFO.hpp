/**
 * Ordered LIFO Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include "config.h"
#include "core::KeyList.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

class OrderedLIFO : public Polyphony
{
public:
    OrderedLIFO(core::Key** keys, size_t keyCount) :
        _keyList(keys, keyCount)
    {}

    ~OrderedLIFO(void)
    {}

    const char *
    name(void) 
    {
        return "LIFO *";
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
