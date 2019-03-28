/**
 * Positional Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include <stddef.h>

#include "config.h"
#include "core::polyphony::Polyphony.h"

namespace core {

typedef struct {
    uint8_t channel;
    polyphony::Polyphony *model;
} Route;


class Router
{
public:
    Router()
    {
        for (size_t idx = 0; idx < MAX_ROUTES; idx++) {
            _table[idx].channel = 255;
            _table[idx].model = NULL;
        }
    }

    //
    // Empty routing table
    //
    void
    empty(void) 
    {
        _count = 0;
        for (size_t idx = 0; idx < MAX_ROUTES; idx++) {
            _table[idx].channel = 255;
            if (_table[idx].model) {
                delete _table[idx].model;
                _table[idx].model = NULL;
            }
        }
    }

    //
    // Add a Route
    //
    int8_t
    add(uint8_t channel, polyphony::Polyphony *model) 
    {

        if (_count + 1 == MAX_ROUTES) {
            return -1;
        }

        _table[_count].channel = channel;
        _table[_count].model = model;

        return _count++;
    }

    int8_t
    updateModel(size_t idx, polyphony::Polyphony *model) 
    {
        if (idx >= _count) {
            return -1;
        }

        // Ensure old item is deleted
        if (_table[idx].model) {
            delete _table[idx].model;
        }
        _table[idx].model = model;

        return idx;
    }

    int8_t
    updateChannel(size_t idx, polyphony::Polyphony *model) 
    {
        if (idx >= _count) {
            return -1;
        }

        // Ensure old item is deleted
        if (_table[idx].model) {
            delete _table[idx].model;
        }
        _table[idx].model = model;

        return idx;
    }

    void
    onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
    {
        for (size_t idx = 0; idx < _count; idx++) {
            if (_table[idx].channel == channel) {
                _table[idx].model->noteOff(note, velocity);
            }
        }
    }

    void
    onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
    {
        for (size_t idx = 0; idx < _count; idx++) {
            if (_table[idx].channel == channel) {
                _table[idx].model->noteOn(note, velocity);
            }
        }
    }

    void
    onAfterTouch(uint8_t channel, uint8_t value)
    {
        for (size_t idx = 0; idx < _count; idx++) {
            if (_table[idx].channel == channel) {
                _table[idx].model->afterTouch(value);
            }
        }
    }

    void
    onPitchBend(uint8_t channel, int16_t change)
    {
        for (size_t idx = 0; idx < _count; idx++) {
            if (_table[idx].channel == channel) {
                _table[idx].model->pitchBend(change);
            }
        }
    }

private:
    Route _table[MAX_ROUTES];
    uint8_t _count;

};

} //! core
