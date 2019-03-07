#include "core::polyphony::Positional.h"

using namespace core::polyphony;


Positional::Positional(PositionalMode mode)
: _mode(mode)
{}

void
Positional::on_note_on(uint8_t note, uint8_t velocity)
{}

void
Positional::on_note_off(uint8_t note, uint8_t velocity)
{}

void
Positional::on_pitch_bend(int16_t range)
{}
