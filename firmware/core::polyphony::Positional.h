/**
 * Positional Polyphonic
 * 
 */
#pragma once

#include "core::polyphony::Polyphony.h"
#include "core::Key.h"

namespace core {
namespace polyphony {

enum PositionalMode
{
    // Lowest notes are given priority
    ModeLow,
    // Highest notes are given priority
    ModeHigh,
};

//
// Positional Polyphony Model
//
class Positional : public Polyphony
{
public:
    Positional(core::Key** keys, size_t keyCount, PositionalMode mode=ModeLow);

    void
    noteOff(uint8_t note, uint8_t velocity);

    void
    noteOn(uint8_t note, uint8_t velocity);

    void
    pitchBend(int16_t amount);

private:
    core::Key **_keys;
    size_t _keyCount;
    PositionalMode _mode;

    uint8_t _notes[MAX_NOTES + 1];
};

}} //! polyphony::core
