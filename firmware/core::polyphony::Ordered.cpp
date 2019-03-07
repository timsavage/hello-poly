#include "core::polyphony::Ordered.h"

using namespace core::polyphony;

Ordered::Ordered(OrderedMode mode)
: _mode(mode)
{    
}

void
Ordered::on_note_on(uint8_t note, uint8_t velocity)
{
    // Find existing note
    size_t noteIdx = -1;
    for (size_t idx = 0; idx < MAX_NOTES; idx++) {
        if (note == _notes[idx]) {
            noteIdx = note;
            break;
        }
    }
    
}

void
Ordered::on_note_off(uint8_t note, uint8_t velocity)
{}

void
Ordered::on_pitch_bend(int16_t range)
{}
