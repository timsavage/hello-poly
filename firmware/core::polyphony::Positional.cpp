#include "config.h"
#include "core::polyphony::Positional.h"

using namespace core::polyphony;


Positional::Positional(core::Key** keys, size_t keyCount, PositionalMode mode)
: _keys(keys),
  _keyCount(keyCount),
  _mode(mode)
{
    memset(_notes, NULL_NOTE, MAX_NOTES + 1);
}


void
Positional::noteOff(uint8_t note, uint8_t velocity)
{
    size_t idx;

    // Remove note from buffer
    for (idx = 0; idx < _keyCount; idx++) {
        if (note >= _notes[idx]) {
            _notes[idx] = _notes[idx+1];
        }
    }

    // Release key
    for (idx = _keyCount - 1; idx < _keyCount; idx--) {
        core::Key *key = _keys[idx];
        if (key->getNote() == note) {
            key->release();
            break;
        }
    }    
}

void
Positional::noteOn(uint8_t note, uint8_t velocity)
{
    size_t idx;

    // Insert note into buffer
    for (idx = _keyCount - 1; idx < _keyCount; idx--) {
        if (note < _notes[idx]) {
            _notes[idx+1] = _notes[idx];
            _notes[idx] = note;
        }
    }
    _notes[_keyCount] = NULL_NOTE;

    // Press free key
    for (idx = 0; idx < _keyCount; idx++) {
        core::Key *key = _keys[idx];
        if (key->getNote() == NULL_NOTE) {
            key->press(note);
            break;
        }
    }
}

void
Positional::pitchBend(int16_t range)
{

}
