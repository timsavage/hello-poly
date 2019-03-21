/**
 * View
 * ~~~~
 */
#pragma once

#include <Adafruit_GFX.h>

namespace core {
namespace ui {

class View
{
public:
    // 
    // Render view
    //
    virtual void
    render(Adafruit_GFX *display) = 0;

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
