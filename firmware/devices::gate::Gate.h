/**
 * Gate
 * ~~~~
 *
 * A gate is a binary device that is either Open or Closed. A gate provides a 
 * 5-12V signal to indicate it is closed and are used to indicate a state 
 * between modules eg a Key is pressed on a keyboard.
 *
 */
#pragma once

#include <Arduino.h>

namespace devices {
namespace gate {

//
// Gate state
//
enum GateState : uint8_t
{
    GateOpen   = 0,
    GateClosed = 1,
};


//
// Gate device
//
class Gate
{
public:
    Gate(int pin);

    //
    // Initialise the gate
    //
    void
    begin(void);

    //
    // Reset gate
    //
    void
    reset(void);

    //
    // Open the gate
    //
    void
    open(void);

    //
    // Close the gate
    //
    void
    close(void);

    //
    // Toggle the current gate state and return new state.
    //
    GateState
    toggle(void);

    //
    // Bounce the current gate state and return the state. An optional delay
    // can be provided to be used between state transitions to allow for other
    // modules to settle and respond.
    //
    GateState
    bounce(uint16_t delay_ms=10);

    // 
    // Get the current gate state
    //
    GateState
    getState(void);

private:
    uint8_t _pin;
};

}} //! gate::devices
