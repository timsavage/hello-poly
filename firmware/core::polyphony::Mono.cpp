#include "core::polyphony::Mono.h"

using namespace core::polyphony;

Mono::Mono(Key *key)
: _key(key)
{}

void
Mono::noteOn(uint8_t note, uint8_t velocity)
{
    _key->press(note);
}

void
Mono::noteOff(uint8_t note, uint8_t velocity)
{
    if (_key->getNote() == note) {
        _key->release();
    }
}

void
Mono::pitchBend(int16_t amount)
{

}
