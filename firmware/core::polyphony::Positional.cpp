#include "config.h"
#include "core::polyphony::Positional.h"

using namespace core;
using namespace core::polyphony;


Positional::Positional(Key** keys, size_t keyCount, PositionalMode mode)
: _keyList(keys, keyCount),
  _mode(mode)
{
    memset(_notes, NULL_NOTE, MAX_NOTES + 1);
}


void
Positional::noteOff(uint8_t note, uint8_t velocity)
{
    size_t idx;
    size_t count = _keyList.count();
    Key *key = NULL;

    // Remove note from buffer
    if (_mode == ModeLow) {
        for (idx = 0; idx < count; idx++) {
            if (note <= _notes[idx]) {
                _notes[idx] = _notes[idx+1];
            }
        }
    } else {
        for (idx = 0; idx < count; idx++) {
            if (note >= _notes[idx]) {
                _notes[idx] = _notes[idx+1];
            }
        }
    }

    // Release key
    key = _keyList.find(note);
    if (key) {
        key->release();
    }
}

void
Positional::noteOn(uint8_t note, uint8_t velocity)
{
    size_t idx;
    size_t count = _keyList.count();
    uint8_t val;
    Key *key;

    // Insert note into buffer
    if (_mode == ModeLow) {
        for (idx = count - 1; idx < count; idx--) {
            val = _notes[idx];
            if (note < val) {
                _notes[idx + 1] = val;
                _notes[idx] = note;
            }
        }
    } else {
        for (idx = count - 1; idx < count; idx--) {
            val = _notes[idx];
            if (note > val || val == NULL_NOTE) {
                _notes[idx + 1] = _notes[idx];
                _notes[idx] = note;
            }
        }
    }

    // Press key
    key = _keyList.firstOpen();
    if (key == NULL) {
        key = _keyList.find(_notes[count]);
    }
    if (key) {
        key->press(note);
    }

    // Clear last entry
    _notes[count] = NULL_NOTE;
}

void
Positional::pitchBend(int16_t range)
{

}
