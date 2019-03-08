/**
 * Ordered Polyphonic
 * 
 */
#pragma once

#include "config.h"
#include "core::polyphony::Polyphony.h"

namespace core {
namespace polyphony {

enum OrderedMode
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
    noteOff(uint8_t note, uint8_t velocity);

    void
    noteOn(uint8_t note, uint8_t velocity);

    void
    pitchBend(int16_t amount);

private:
    OrderedMode _mode;
    uint8_t _notes[MAX_POLYBUFFER];
    
};

}} //! polyphony::core
