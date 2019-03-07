#include "core::polyphony::Mono.h"

using namespace core::polyphony;

#define NULL_NOTE 255


Mono::Mono() 
: _currentNote(NULL_NOTE)
{}

void
Mono::on_note_on(uint8_t note, uint8_t velocity)
{
    if (_currentNote != note) {

    }
}

void
Mono::on_note_off(uint8_t note, uint8_t velocity)
{
    if (_currentNote == note) {
        _currentNote = NULL_NOTE;
    }
}

void
Mono::on_pitch_bend(int16_t range)
{}
