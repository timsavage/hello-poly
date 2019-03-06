/**
 * Config
 * ~~~~~~
 *
 * Holds the configuration and mapping of incoming MIDI messages to notes and
 * polyphony models.
 *
 */
#pragma once

#include <Arduino.h>

#include "core::Note.h"
#include "core::Polyphony.h"

namespace core {

class Config
{
public:
    Config(void);

    void
    on_note_on(uint8_t channel, uint8_t note, uint8_t velocity);

    void
    on_note_off(uint8_t channel, uint8_t note);
    
    void
    on_pitch_bend(uint8_t channel, int16_t amount);

private:
    uint8_t    _channel;
    Note*      _notes[4];  // References to notes included in this config
    Polyphony* _model;
};

} //! core

