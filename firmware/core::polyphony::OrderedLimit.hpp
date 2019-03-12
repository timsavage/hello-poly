/**
 * Ordered Limit Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include "config.h"
#include "core::KeyList.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

//
// Ordered Polyphony Model
//
class OrderedLimit : public Polyphony
{
public:
    OrderedLimit(core::Key** keys, size_t keyCount) :
        _keyList(keys, keyCount)
    {}

    void
    noteOff(uint8_t note, uint8_t velocity)
    {
        Key *key = _keyList.find(note);
        if (key != NULL) {
            key->release();
        }
    }

    void
    noteOn(uint8_t note, uint8_t velocity)
    {
        Key *key = _keyList.firstOpen();
        if (key != NULL) {
            key->press(note);
        }
    }

    void
    afterTouchChannel(uint8_t value)
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
