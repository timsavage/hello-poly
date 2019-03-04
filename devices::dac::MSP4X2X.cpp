/**
 * DAC Device support for MSP4821, MSP4822, MSP 4921, MSP4922 12bit DACs.
 */
#include <Arduino.h>
#include <SPI.h>

#include "devices::dac::MSP4X2X.h"

using namespace devices::dac;

const SPISettings dacSettings(16000000, MSBFIRST, SPI_MODE0);

//
// MSP4X22 DAC Device
//
MSP4X22::MSP4X22(int ss, byte subDac, byte config)
: _ss(ss),
  _config(subDac | config)
{}

//
// Begin and configure pins
//
void 
MSP4X22::begin(void)
{
    pinMode(_ss, OUTPUT);
    digitalWrite(_ss, HIGH);
}

//
// Set DAC output value
//
// value - value to set, this is a 12-bit value (0-4095)
//
void
MSP4X22::setValue(word value)
{
    byte first = _config | (value & 0xF00) >> 8;
    byte second = value & 0xFF;

    SPI.beginTransaction(dacSettings);
    digitalWrite(_ss, LOW);

    SPI.transfer(first);
    SPI.transfer(second);

    digitalWrite(_ss, HIGH);
    SPI.endTransaction();  
}
