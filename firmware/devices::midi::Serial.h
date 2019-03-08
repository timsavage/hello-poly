/**
 * MIDI Device support for serial UART
 */
#pragma once

#include <Arduino.h>

#include "devices::midi::Midi.h"

namespace devices {
namespace midi {

class SerialMIDI : public MIDI
{
public:
    SerialMIDI(HardwareSerial *serial);

    void
    begin(void);

    void
    loop(void);

private:
    HardwareSerial *_serial;

    // Status of reading
    uint8_t _buffer;
    uint8_t _phase;
    uint32_t _dataTimeout;

    // Current message
    Command _command;
    uint8_t _channel;
    uint8_t _high;
    uint8_t _low;
};

}}  //! midi::devices
