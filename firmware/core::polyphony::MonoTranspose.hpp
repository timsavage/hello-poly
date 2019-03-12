/**
 * Mono Transpose
 * ~~~~~~~~~~~~~~
 *
 * The Mono polyphony model is where only one note per channel is used. This
 * is not really polyphony at all but a fallback to the simplest model.
 *
 */
#pragma once

#include "core::Key.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

class MonoTranspose : public Polyphony
{
public:
    MonoTranspose(Key *key) : 
        _key(key)
    {}

    void
    noteOn(uint8_t note, uint8_t velocity)
    {
        _key->transpose(note);        
    }

    void
    noteOff(uint8_t note, uint8_t velocity)
    {
        if (_key->getNote() == note) {
            _key->release();
        }
    }

    void
    afterTouchChannel(uint8_t value)
    {

    }

    void
    pitchBend(int16_t amount)
    {
        _key->pitchBend(amount);
    }

private:
    Key *_key;
};

}}  // !polyphony::core
