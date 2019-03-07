/**
 * Ordered Polyphonic
 * 
 */
#pragma once

#include "core::polyphony.h"

namespace core {
namespace polyphony {

typedef enum OrderedMode
{
    FIFO,   // First in first out
    LIFO,   // Last in first out
    Limit,  // Limit (if all notes are used ignore new items)
};


class Ordered : public Polyphony
{
public:
    Ordered(OrderedMode mode);

    void
    on_note_on(uint8_t note, uint8_t velocity);

    void
    on_note_off(uint8_t note, uint8_t velocity);

    void
    on_pitch_bend(int16_t range);

private:
    OrderedMode _mode;
    uint8_t _notes[MAX_NOTES];
    
};

}} //! polyphony::core
