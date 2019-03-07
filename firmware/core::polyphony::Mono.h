/**
 * Mono Polyphonic
 * 
 */
#pragma once

#include "core::polyphony.h"

namespace core {
namespace polyphony {

class Mono : public Polyphony
{
public:
    Mono();

    void
    on_note_on(uint8_t note, uint8_t velocity);

    void
    on_note_off(uint8_t note, uint8_t velocity);

    void
    on_pitch_bend(int16_t range);

private:
    uint8_t _currentNote;

};

}} //! polyphony::core
