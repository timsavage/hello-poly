/**
 * View
 * ~~~~
 */
#pragma once

#include "devices::display::SSD1306.h"

using namespace devices::display;

namespace core {
namespace ui {

class View
{
public:
    // 
    // Render view
    //
    virtual void
    render(SSD1306 *display) = 0;

    //
    // Determine if rendering is required
    //
    virtual int
    renderRequired(void) 
    {
        return _renderRequired;
    }

protected:
    int _renderRequired;
    
};

}}  //! ui::core
