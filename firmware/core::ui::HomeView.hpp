/**
 * Home View
 * ~~~~~~~~~
 * 
 */
#pragma once

#include "core::ui::View.h"

namespace core {
namespace ui {

class HomeView : public View
{
public:
    HomeView(void)
    {
        _renderRequired = 1;
    }

    // 
    // Render view
    //
    void
    render(Adafruit_GFX *display)
    {
        // display->clearDisplay();
        // display->setCursor(0, 0);
        // display->print("Home!");

        _renderRequired = 0;
    }
};

}}  //! ui::core
