/**
 * View
 * ~~~~
 */
#pragma once

namespace core {
namespace ui {

class View
{
public:
    // 
    // Render view
    //
    virtual void
    render(void *display) = 0;

    //
    // Determine if rendering is required
    //
    virtual int
    renderRequired(void) = 0;
};

}}  //! ui::core