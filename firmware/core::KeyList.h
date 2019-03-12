/**
 * Key List
 * ~~~~~~~~
 *
 * Helper for managing keys
 *
 */
#pragma once

#include "core::Key.h"

namespace core {

class KeyList
{
public:
    KeyList(Key **keys, size_t keyCount);

    //
    // Find a key by active note; return NULL if not found
    //
    Key *
    find(uint8_t note);

    //
    // Find an open key; return NULL if not found
    //
    Key *
    firstOpen(void);

    //
    // Get key by index; return NULL if out of range.
    //
    Key *
    get(size_t idx);

    //
    // Size of list
    //
    size_t
    count(void);

    //
    // Apply a pitch bend
    //
    void
    pitchBend(int16_t amount);

private:
    Key **_keys;
    size_t _count;
};

}  //! core
