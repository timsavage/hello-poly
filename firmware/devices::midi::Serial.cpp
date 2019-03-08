/**
 * MIDI Device support for serial UART
 */

#include "devices::midi::Serial.h"

using namespace devices::midi;


SerialMIDI::SerialMIDI(HardwareSerial *serial)
: _serial(serial),
  _dataTimeout(0)
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
        handleByte(_serial->read());

        _dataTimeout = millis() + 50;
        digitalWrite(PC13, 0);
    }

    if (_dataTimeout && (_dataTimeout < millis())) {
        _dataTimeout = 0;
        digitalWrite(PC13, 1);
    }
}
