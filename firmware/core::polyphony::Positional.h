/**
 * Positional Polyphonic
 * 
 */
#pragma once

#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

typedef enum PositionalMode
{
    Low,
    High,
};


class Positional : public Polyphony
{
public:
    Positional(PositionalMode mode);

    void
    on_note_on(uint8_t note, uint8_t velocity);

    void
    on_note_off(uint8_t note, uint8_t velocity);

    void
    on_pitch_bend(int16_t range);

private:
    PositionalMode _mode;
};

}} //! polyphony::core
