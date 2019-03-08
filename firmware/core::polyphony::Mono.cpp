#include "core::polyphony::Mono.h"

using namespace core::polyphony;

Mono::Mono(Key *key)
: _key(key),
  _currentNote(NULL_NOTE)
{}

void
Mono::noteOn(uint8_t note, uint8_t velocity)
{
    if (_currentNote == NULL_NOTE) {
        _key->press(note);
    } else {
        _key->transpose(note);
    }
    _currentNote = note;
}

void
Mono::noteOff(uint8_t note, uint8_t velocity)
{
    if (_currentNote == note) {
        _currentNote = NULL_NOTE;
        _key->release();
    }
}

void
Mono::pitchBend(int16_t amount)
{

}
