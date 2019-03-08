#include "core::polyphony::Mono.h"

using namespace core::polyphony;

#define NULL_NOTE 255

Mono::Mono(Key *key)
: _key(key),
  _currentNote(NULL_NOTE)
{}

Mono::noteOn(uint8_t note, uint8_t velocity)
{
    if (_currentNote == NULL_NOTE) {
        _key->press(note);
    } else {
        _key->transpose(note);
    }
    _currentNote = note;
}

Mono::noteOff(uint8_t note, uint8_t velocity)
{
    if (_currentNote == note) {
        _currentNote = NULL_NOTE;
        _key->release();
    }
}

Mono::pitchBend(uint16_t amount)
{

}

