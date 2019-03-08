/**
 * MIDI Device support for serial UART
 */

#include "devices::midi::Serial.h"

using namespace devices::midi;

#define MIDI_STATUS_BYTE  B10000000
#define MIDI_CHANNEL_MASK B00001111
#define MIDI_COMMAND_MASK B11110000


SerialMIDI::SerialMIDI(HardwareSerial *serial)
: _serial(serial),
  _buffer(0),
  _phase(0),
  _dataTimeout(0),
  _channel(0),
  _command(InvalidType),
  _high(0),
  _low(0)
{}

void
SerialMIDI::begin(void) 
{
    // Begin at MIDI baud rate
    _serial->begin(31250);
}

void
SerialMIDI::loop(void)
{
    while (_serial->available()) {
        _buffer = _serial->read();
        switch (_phase) {
        case 0:
            // Phase one (start of message)
            if (_buffer & MIDI_STATUS_BYTE) {
                _phase = 1;
                _channel = _buffer & MIDI_CHANNEL_MASK;
                _command = (Command)(_buffer & MIDI_COMMAND_MASK);
            }
            break;

        case 1:
            // Second phase (high byte)
            _phase = 2;
            _high = _buffer;
            break;

        case 2:
            // Set indicator
            _dataTimeout = millis() + 50;
            digitalWrite(PC13, 0);

            // Third phase (low byte)
            _phase = 0;
            _low = _buffer;

            handleMessage(_command, _channel, _high, _low);
            break;
        }
    }

    if (_dataTimeout && (_dataTimeout < millis())) {
        _dataTimeout = 0;
        digitalWrite(PC13, 1);
    }
}
