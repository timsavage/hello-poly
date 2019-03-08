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
    uint32_t _dataTimeout;
};

}}  //! midi::devices
