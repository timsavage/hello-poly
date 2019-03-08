#pragma once

#include <Arduino.h>

namespace devices {
namespace midi {

enum MidiType
{
    InvalidType           = 0x00,    // For notifying errors
    NoteOff               = 0x80,    // Note Off
    NoteOn                = 0x90,    // Note On
    AfterTouchPoly        = 0xA0,    // Polyphonic AfterTouch
    ControlChange         = 0xB0,    // Control Change / Channel Mode
    ProgramChange         = 0xC0,    // Program Change
    AfterTouchChannel     = 0xD0,    // Channel (monophonic) AfterTouch
    PitchBend             = 0xE0,    // Pitch Bend
    SystemExclusive       = 0xF0,    // System Exclusive
    TimeCodeQuarterFrame  = 0xF1,    // System Common - MIDI Time Code Quarter Frame
    SongPosition          = 0xF2,    // System Common - Song Position Pointer
    SongSelect            = 0xF3,    // System Common - Song Select
    TuneRequest           = 0xF6,    // System Common - Tune Request
    Clock                 = 0xF8,    // System Real Time - Timing Clock
    Start                 = 0xFA,    // System Real Time - Start
    Continue              = 0xFB,    // System Real Time - Continue
    Stop                  = 0xFC,    // System Real Time - Stop
    ActiveSensing         = 0xFE,    // System Real Time - Active Sensing
    SystemReset           = 0xFF,    // System Real Time - System Reset
};

typedef void (*noteCallbackFunc)(uint8_t channel, uint8_t note, uint8_t velocity);
typedef void (*controlChangeCallbackFunc)(uint8_t channel, uint8_t control, uint8_t value);
typedef void (*programChangeCallbackFunc)(uint8_t channel, uint8_t program);
typedef void (*pitchBendCallbackFunc)(uint8_t channel, int16_t change);

class MIDI
{
public:
    virtual void 
    begin(void) = 0;

    virtual void
    loop(void) = 0;

    void 
    noteOffCallback(noteCallbackFunc callback) 
    { 
        _offNoteCallback = callback; 
    }

    void 
    noteOnCallback(noteCallbackFunc callback) 
    { 
        _onNoteCallback = callback; 
    }
    
    void 
    controlChangeCallback(controlChangeCallbackFunc callback) 
    { 
        _controlChangeCallback = callback; 
    }
    
    void 
    programChangeCallback(programChangeCallbackFunc callback) 
    { 
        _programChangeCallback = callback; 
    }
    
    void
    pitchBendCallback(pitchBendCallbackFunc callback) 
    { 
        _pitchBendCallback = callback; 
    }

protected:
    noteCallbackFunc _offNoteCallback;
    noteCallbackFunc _onNoteCallback;
    controlChangeCallbackFunc _controlChangeCallback;
    programChangeCallbackFunc _programChangeCallback;
    pitchBendCallbackFunc _pitchBendCallback;
};

}} //! midi::devices
