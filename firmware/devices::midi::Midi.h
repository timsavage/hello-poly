#pragma once

#include <Arduino.h>

namespace devices {
namespace midi {

#define MIDI_PITCHBEND_MIN      -8192
#define MIDI_PITCHBEND_MAX      8191

enum Command
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

typedef void (*twoByteCallbackFunc)(uint8_t channel, uint8_t, uint8_t);
typedef void (*oneByteCallbackFunc)(uint8_t channel, uint8_t);
typedef void (*oneWordCallbackFunc)(uint8_t channel, int16_t);

class MIDI
{
public:
    MIDI();
    
    virtual void 
    begin(void) = 0;

    virtual void
    loop(void) = 0;

    void 
    noteOffCallback(twoByteCallbackFunc callback);

    void 
    noteOnCallback(twoByteCallbackFunc callback);
    
    void 
    controlChangeCallback(twoByteCallbackFunc callback);
    
    void 
    programChangeCallback(oneByteCallbackFunc callback);
    
    void
    pitchBendCallback(oneWordCallbackFunc callback);

protected:
    void
    handleByte(uint8_t buffer);

private:
    void
    handleMessage(void);

    uint8_t _phase;
    Command _command;
    uint8_t _channel;
    uint8_t _high;
    uint8_t _low;

    // Callback functions
    twoByteCallbackFunc _noteOffCallback;
    twoByteCallbackFunc _noteOnCallback;
    twoByteCallbackFunc _controlChangeCallback;
    oneByteCallbackFunc _programChangeCallback;
    oneWordCallbackFunc _pitchBendCallback;
};

}} //! midi::devices
