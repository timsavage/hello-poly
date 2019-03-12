/**
 * Interface and common constants for Polyphony model.
 */
#pragma once

#include <Arduino.h>

namespace core {
namespace polyphony {

enum PolyphonyMode : uint8_t
{
    ModeMonoPress,
    ModeMonoSingle,
    ModeMonoTranspose,
    ModeOrderedLIFO,
    ModeOrderedFIFO,
    ModeOrderedLimit,
    ModePositionalLow,
    ModePositionalHigh,
};

// 
// ABC class that provides the interface for Polyphony models.
//
class Polyphony
{
public:
    // 
    // Event generated when a MIDI note off message is routed to model
    //
    virtual void
    noteOff(uint8_t note, uint8_t velocity) = 0;

    //
    // Event generated when a MIDI note on message is routed to model
    //
    virtual void
    noteOn(uint8_t note, uint8_t velocity) = 0;

    //
    // Event generated when a MIDI after touch channel bend message is routed to model
    //
    virtual void
    afterTouchChannel(uint8_t value) = 0;

    //
    // Event generated when a MIDI pitch bend message is routed to model
    //
    virtual void
    pitchBend(int16_t amount) = 0;
};

}}  //! polyphony::core
