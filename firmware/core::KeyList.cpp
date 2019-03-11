#include "core::KeyList.h"

using namespace core;

KeyList::KeyList(Key** keys, size_t count)
: _keys(keys),
  _count(count)
{}

//
// Find a key by active note.
//
Key*
KeyList::find(uint8_t note)
{
    Key* key;
    for (size_t idx; idx < _count; idx++) {
        key = _keys[idx];
        if (key->getNote() == note) {
            return key;
        }
    }
    return NULL;
}

//
// Find a key by active note.
//
Key*
KeyList::firstOpen(void)
{
    Key* key;
    for (size_t idx; idx < _count; idx++) {
        key = _keys[idx];
        if (key->isReleased()) {
            return key;
        }
    }
    return NULL;
}

//
// Get key
//
Key*
KeyList::get(size_t idx)
{
    if (idx < _count) {
        return _keys[idx];
    }
    return NULL;
}

//
// Size of list
//
size_t
KeyList::count(void)
{
    return _count;
}
