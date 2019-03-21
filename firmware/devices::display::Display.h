/**
 * Display
 * ~~~~~~~
 *
 */
#pragma once

namespace devices {
namespace display {

class Display
{
public:
    Display();

	virtual void
	begin(void) = 0;

	virtual void
	display(void) = 0;
};

}}  //! display::devices
