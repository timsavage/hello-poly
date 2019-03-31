/**
 * Positional Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include "config.h"
#include "core::polyphony::Polyphony.h"
#include "core::Key.h"
#include "core::KeyList.h"

namespace core {
namespace polyphony {

class PositionalHigh : public Polyphony
{
public:
    PositionalHigh(Key** keys, size_t keyCount) : 
        _keyList(keys, keyCount)
    {
        memset(_notes, NULL_NOTE, MAX_NOTES + 1);
    }

    ~PositionalHigh(void)
    {}

    const char *
    name(void) 
    {
        return "Chrd Hi";
    }

    void
    noteOff(uint8_t note, uint8_t)
    {
        size_t count = _keyList.count();
        for (size_t idx = 0; idx < count; idx++) {
            if (note >= _notes[idx]) {
                _notes[idx] = _notes[idx+1];
            }
        }

        // Release key
        Key *key = _keyList.find(note);
        if (key) {
            key->release();
        }
    }

    void
    noteOn(uint8_t note, uint8_t)
    {
        // Insert note into buffer
        uint8_t val;
        size_t count = _keyList.count();
        for (size_t idx = count - 1; idx < count; idx--) {
            val = _notes[idx];
            if (note > val || val == NULL_NOTE) {
                _notes[idx + 1] = _notes[idx];
                _notes[idx] = note;
            }
        }

        // Press key
        Key *key = _keyList.firstOpen();
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
    uint8_t _notes[MAX_NOTES + 1];
};

}} //! polyphony::core
