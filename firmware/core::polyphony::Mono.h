/**
 * Mono Model
 * ~~~~~~~~~~
 *
 * The Mono polyphony model is where only one note per channel is used. This
 * is not really polyphony at all but a fallback to the simplest model.
 *
 */
#pragma once

#include "core::Key.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

enum MonoMode
{
    // Press a new note
    ModePress,
    // Transpose to a new note
    ModeTranspose,
    // A second note is ignored
    ModeSingle,
};

class Mono : public Polyphony
{
public:
    Mono(Key *key, MonoMode mode=ModePress);

    void
    noteOn(uint8_t note, uint8_t velocity);

    void
    noteOff(uint8_t note, uint8_t velocity);

    void
    pitchBend(int16_t amount);

private:
    Key *_key;
    MonoMode _mode;
};

}}  // !polyphony::core

