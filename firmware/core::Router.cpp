/**
 * Positional Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#include "core::Router.h"
#include "core::polyphony::MonoPress.hpp"
#include "core::polyphony::MonoSingle.hpp"
#include "core::polyphony::MonoTranspose.hpp"
#include "core::polyphony::OrderedFIFO.hpp"
#include "core::polyphony::OrderedLIFO.hpp"
#include "core::polyphony::OrderedLimit.hpp"
#include "core::polyphony::PositionalHigh.hpp"
#include "core::polyphony::PositionalLow.hpp"

using namespace core;

static Route 
table[MAX_ROUTES] = {
    {255, NULL},
    {255, NULL},
    {255, NULL},
    {255, NULL},
    {255, NULL},
    {255, NULL},
};

static size_t
tableCount = 0;

static void
onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
    for (size_t idx = 0; idx < tableCount; idx++) {
        if (table[idx].channel == channel) {
            table[idx].mode->noteOff(note, velocity);
        }
    }
}

static void
onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
    for (size_t idx = 0; idx < tableCount; idx++) {
        if (table[idx].channel == channel) {
            table[idx].mode->noteOn(note, velocity);
        }
    }
}

static void
onAfterTouch(uint8_t channel, uint8_t value)
{
    for (size_t idx = 0; idx < tableCount; idx++) {
        if (table[idx].channel == channel) {
            table[idx].mode->afterTouch(value);
        }
    }
}

static void
onPitchBend(uint8_t channel, int16_t change)
{
    for (size_t idx = 0; idx < tableCount; idx++) {
        if (table[idx].channel == channel) {
            table[idx].mode->pitchBend(change);
        }
    }
}


GlobalRouter::GlobalRouter() {}

void
GlobalRouter::begin(devices::midi::MIDI *midi)
{
    // Register midi events
    midi->noteOffCallback(&onNoteOff);
    midi->noteOnCallback(&onNoteOn);
    midi->afterTouchCallback(&onAfterTouch);
    // midi->pitchBendCallback(&onPitchBend);
}

//
// Empty routing table
//
void
GlobalRouter::empty(void) 
{
    tableCount = 0;
    for (size_t idx = 0; idx < MAX_ROUTES; idx++) {
        table[idx].channel = 255;
        if (table[idx].mode) {
            delete table[idx].mode;
            table[idx].mode = NULL;
        }
    }
}

polyphony::Polyphony *
GlobalRouter::initMode(polyphony::PolyphonyMode mode, Key** keys, size_t keyCount)
{
    switch(mode) {
    case polyphony::ModeMonoPress:
        return new polyphony::MonoPress(keys, keyCount);

    case polyphony::ModeMonoSingle:
        return new polyphony::MonoSingle(keys, keyCount);

    case polyphony::ModeMonoTranspose:
        return new polyphony::MonoTranspose(keys, keyCount);

    case polyphony::ModeOrderedLIFO:
        return new polyphony::OrderedLIFO(keys, keyCount);

    case polyphony::ModeOrderedFIFO:
        return new polyphony::OrderedFIFO(keys, keyCount);

    case polyphony::ModeOrderedLimit:
        return new polyphony::OrderedLimit(keys, keyCount);

    case polyphony::ModePositionalLow:
        return new polyphony::PositionalLow(keys, keyCount);

    case polyphony::ModePositionalHigh:
        return new polyphony::PositionalHigh(keys, keyCount);
    }

    return NULL;
}

//
// Add a Route
//
int8_t
GlobalRouter::add(uint8_t channel, polyphony::PolyphonyMode mode, core::Key** keys, size_t keyCount)
{
    if (tableCount + 1 == MAX_ROUTES) {
        return -1;
    }

    table[tableCount].channel = channel;
    table[tableCount].mode = initMode(mode, keys, keyCount);

    return tableCount++;
}

//
// Update a route
//
int8_t
GlobalRouter::update(size_t idx, uint8_t channel, polyphony::PolyphonyMode mode, core::Key** keys, size_t keyCount)
{
    if (idx >= tableCount) {
        return -1;
    }

    // Remove old entry
    delete table[idx].mode;

    // Add new entry
    table[idx].channel = channel;
    table[idx].mode = initMode(mode, keys, keyCount);

    return idx;
}

Route *
GlobalRouter::getRoute(size_t idx)
{
    if (idx >= tableCount) {
        return NULL;
    }

    return &table[idx];
}


// Router instance
GlobalRouter Router;
