/**
 * Home View
 * ~~~~~~~~~
 * 
 */
#pragma once

#include "core::ui::View.h"

using namespace devices::display;

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
    render(SSD1306 *display)
    {
        display->clearDisplay();
        display->drawFastVLine(0, 16, 16, WHITE);

        // display->clearDisplay();
        // display->setCursor(0, 0);
        // display->print("Home!");

        _renderRequired = 0;
    }
};

}}  //! ui::core

