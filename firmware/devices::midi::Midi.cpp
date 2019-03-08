#include "devices::midi::Midi.h"

#define MIDI_STATUS_BYTE  B10000000
#define MIDI_CHANNEL_MASK B00001111
#define MIDI_COMMAND_MASK B11110000

using namespace devices::midi;

MIDI::MIDI()
: _phase(0),
  _channel(0),
  _command(InvalidType),
  _high(0),
  _low(0),
  _noteOffCallback(NULL),
  _noteOnCallback(NULL),
  _controlChangeCallback(NULL),
  _programChangeCallback(NULL),
  _pitchBendCallback(NULL)
{}

void 
MIDI::noteOffCallback(twoByteCallbackFunc callback) 
{ 
    _noteOffCallback = callback; 
}

void 
MIDI::noteOnCallback(twoByteCallbackFunc callback) 
{ 
    _noteOnCallback = callback; 
}

void 
MIDI::controlChangeCallback(twoByteCallbackFunc callback) 
{ 
    _controlChangeCallback = callback; 
}

void 
MIDI::programChangeCallback(oneByteCallbackFunc callback) 
{ 
    _programChangeCallback = callback; 
}

void
MIDI::pitchBendCallback(oneWordCallbackFunc callback) 
{ 
    _pitchBendCallback = callback; 
}

void
MIDI::handleByte(uint8_t buffer)
{
    uint8_t status = buffer & MIDI_STATUS_BYTE;
    if (status) {
        _phase = 0;
    }

    switch (_phase) {
    case 0:
        // Phase one (start of message)
        if (status) {
            _phase = 1;
            _channel = buffer & MIDI_CHANNEL_MASK;
            _command = (Command)(buffer & MIDI_COMMAND_MASK);
        }
        break;

    case 1:
        // Second phase (high byte)
        _phase = 2;
        _high = buffer;

        switch (_command) {
        case ProgramChange:
        case AfterTouchChannel:
            _phase = 0;
            _low = 0;
            handleMessage();
        }
        break;

    case 2:
        // Third phase (low byte)
        _phase = 0;
        _low = buffer;

        handleMessage();
        break;
    }
}

void
MIDI::handleMessage()
{
    switch (_command) {
    case NoteOff:
        if (_noteOffCallback) {
            _noteOffCallback(_channel, _high, _low);
        }
        break;

    case NoteOn:
        if (_noteOnCallback) {
            _noteOnCallback(_channel, _high, _low);
        }    
        break;

    case ControlChange:
        if (_controlChangeCallback) {
            _controlChangeCallback(_channel, _high, _low);
        }
        break;

    case ProgramChange:
        if (_programChangeCallback) {
            _programChangeCallback(_channel, _high);
        }        
        break;

    case PitchBend:
        if (_pitchBendCallback) {
            _pitchBendCallback(_channel, ((_low & 0x7f) | ((_high & 0x7f) << 7)) + MIDI_PITCHBEND_MIN);
        }        
        break;

    default:
        Serial.print("Command: "); Serial.print(_command);
        Serial.print("; Channel: "); Serial.print(_channel);
        Serial.print("; High: "); Serial.print(_high); 
        Serial.print("; Low: "); Serial.println(_low);
        break;
    }
}
