#pragma once

#include <Arduino.h>

#define MAX_NOTES 4

namespace core {
namespace polyphony {

class Polyphony
{
public:
    virtual void
    on_note_on(uint8_t note, uint8_t velocity) = 0;

    virtual void
    on_note_off(uint8_t note, uint8_t velocity) = 0;

    virtual void
    on_pitch_bend(int16_t range) = 0;

};

}}  //! polyphony::core
