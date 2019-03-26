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
        
        display->setCursor(0, 0);
        display->print("Program: 1");
        display->drawFastVLine(0, 16, 16, WHITE);
        display->drawFastVLine(6, 16, 16, WHITE);
        display->drawFastVLine(12, 16, 16, WHITE);
        display->drawFastVLine(18, 16, 16, WHITE);
        display->drawFastVLine(24, 16, 16, WHITE);
        display->drawFastVLine(30, 16, 16, WHITE);
        display->drawFastVLine(36, 16, 16, WHITE);
        display->drawFastHLine(0, 31, 36, WHITE);
        display->display();
        display->startscrollright(0, 16);

        _renderRequired = 0;
    }
};

}}  //! ui::core

