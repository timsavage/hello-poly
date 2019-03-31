/**
 * Positional Polyphonic
 * ~~~~~~~~~~~~~~~~~~~~~
 * 
 */
#pragma once

#include <stddef.h>

#include "config.h"
#include "devices::midi::Midi.h"
#include "core::polyphony::Polyphony.h"
#include "core::Key.h"

namespace core {

typedef struct {
    uint8_t channel;
    polyphony::Polyphony *mode;
} Route;

class GlobalRouter
{
public:
    GlobalRouter();

    void
    begin(devices::midi::MIDI *midi);

    //
    // Empty routing table
    //
    void
    empty(void);

    //
    // Add a Route
    //
    int8_t
    add(uint8_t channel, polyphony::PolyphonyMode mode, core::Key** keys, size_t keyCount);

    //
    // Update a route
    //
    int8_t
    update(size_t idx, uint8_t channel, polyphony::PolyphonyMode mode, core::Key** keys, size_t keyCount);

    Route *
    getRoute(size_t idx);

private:
    polyphony::Polyphony *
    initMode(polyphony::PolyphonyMode mode, core::Key** keys, size_t keyCount);

};

extern GlobalRouter Router;

} //! core
