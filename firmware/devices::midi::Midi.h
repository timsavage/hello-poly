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
    virtual void 
    begin(void) = 0;

    virtual void
    loop(void) = 0;

    void 
    noteOffCallback(twoByteCallbackFunc callback) 
    { 
        _noteOffCallback = callback; 
    }

    void 
    noteOnCallback(twoByteCallbackFunc callback) 
    { 
        _noteOnCallback = callback; 
    }
    
    void 
    controlChangeCallback(twoByteCallbackFunc callback) 
    { 
        _controlChangeCallback = callback; 
    }
    
    void 
    programChangeCallback(oneByteCallbackFunc callback) 
    { 
        _programChangeCallback = callback; 
    }
    
    void
    pitchBendCallback(oneWordCallbackFunc callback) 
    { 
        _pitchBendCallback = callback; 
    }

protected:
    void
    handleMessage(Command command, uint8_t channel, uint8_t high, uint8_t low)
    {
        switch (command) {
        case NoteOff:
            if (_noteOffCallback) {
                _noteOffCallback(channel, high, low);
            }
            break;

        case NoteOn:
            if (_noteOnCallback) {
                _noteOnCallback(channel, high, low);
            }    
            break;

        case ControlChange:
            if (_controlChangeCallback) {
                _controlChangeCallback(channel, high, low);
            }
            break;

        case ProgramChange:
            if (_programChangeCallback) {
                _programChangeCallback(channel, high);
            }        
            break;

        case PitchBend:
            if (_pitchBendCallback) {
                _pitchBendCallback(channel, ((low & 0x7f) | ((high & 0x7f) << 7)) + MIDI_PITCHBEND_MIN);
            }        
            break;

        default:
            Serial.print("Command: "); Serial.print(command);
            Serial.print("; Channel: "); Serial.print(channel);
            Serial.print("; High: "); Serial.print(high); 
            Serial.print("; Low: "); Serial.println(low);
            break;
        }
    }

    twoByteCallbackFunc _noteOffCallback;
    twoByteCallbackFunc _noteOnCallback;
    twoByteCallbackFunc _controlChangeCallback;
    oneByteCallbackFunc _programChangeCallback;
    oneWordCallbackFunc _pitchBendCallback;
};

}} //! midi::devices
