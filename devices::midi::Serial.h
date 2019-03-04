/**
 * MIDI Device support for serial UART
 */
#pragma once

#include "devices::midi.h"

namespace devices {
namespace midi {

class SerialMIDI : public MIDI
{
public:
    SerialMIDI();

    void
    begin(void);
};

}}  //! midi::devices
