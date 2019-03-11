#include "core::polyphony::Mono.h"

using namespace core::polyphony;

Mono::Mono(Key *key, MonoMode mode)
: _key(key),
  _mode(mode)
{}

void
Mono::noteOn(uint8_t note, uint8_t velocity)
{
    switch(_mode) {
    case ModeSingle:
        if (_key->getNote() == NULL_NOTE) {
            _key->press(note);
        }
        break;
    
    case ModePress:
        _key->press(note);
        break;

    case ModeTranspose:
        _key->transpose(note);
    }
    
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
