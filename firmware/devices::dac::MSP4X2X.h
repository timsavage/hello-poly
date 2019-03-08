/**
 * DAC Device support for MSP4821, MSP4822, MSP 4921, MSP4922 12bit DACs.
 */
#pragma once

#include <Arduino.h>
#include <SPI.h>

#include "devices::dac::DAC.h"

// Select DAC A
#define MSP4X22_DAC_A      0b00000000
// Select DAC B
#define MSP4X22_DAC_B      0b10000000

// Specify Unbuffered mode
#define MSP4X2X_UNBUFFERED 0b00000000
// Specify Buffered mode
#define MSP4X2X_BUFFERED   0b01000000

// Specify 2x Gain
#define MSP4X2X_GAIN_2X    0b00000000
// Specify 1x Gain
#define MSP4X2X_GAIN_1X    0b00100000

// Switch to low power mode
#define MSP4X2X_SHUTDOWN   0b00000000
// Enable output
#define MSP4X2X_ENABLED    0b00010000

// Mask for the high data bits
#define MSP4X2X_DATA_HIGH  0b00001111

// Number of steps 
#define MSP4X2X_STEP_MIN 0
#define MSP4X2X_STEP_MAX 4095

namespace devices {
namespace dac {

//
// MSP4X22 DAC Device
//
class MSP4X22 : public DAC
{
public:
    MSP4X22(int ss, byte subDac, byte config=MSP4X2X_UNBUFFERED | MSP4X2X_GAIN_2X | MSP4X2X_ENABLED);

    //
    // Begin and configure pins
    //
    void 
    begin(void);

    //
    // Set DAC output value
    //
    // value - value to set, this is a 12-bit value (0-4095)
    //
    void
    setValue(word value);

private:
    int _ss;
    byte _config;
};

}} //! dac::devices
