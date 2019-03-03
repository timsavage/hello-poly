/**
 * Parameters and common base classes for DAC devices.
 */
#pragma once

#include <Arduino.h>

namespace devices {
namespace dac {

//
// DAC device
//
class DAC
{
public:
    virtual void
    begin(void) = 0;

    virtual void
    setValue(word value) = 0;
};

}}  //! dac::devices
