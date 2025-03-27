/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/*                                                                                    */
/*                           Copyright (c) 2025 Terminus LLC                          */
/*                                                                                    */
/*                                All Rights Reserved.                                */
/*                                                                                    */
/*          Use of this source code is governed by LICENSE in the repo root.          */
/*                                                                                    */
/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/**
 * @file    Main_Window.cpp
 * @author  Marvin Smith
 * @date    3/25/2025
 */
#include <terminus/calc/pages/Main_Window.hpp>

// Project Libraries
#include <terminus/gui/widget/WidgetLayout.hpp>

namespace tmns::calc::page {

/****************************************/
/*          Create new Window           */
/****************************************/
Main_Window::ptr_t Main_Window::create( core::Options& config,
                                        gui::Session&  session )
{
    /// Create window instance
    auto window = std::make_shared<Main_Window>();

    /// Create the header
    window->m_header = Header_Widget::create( config, session );
    window->append( window->m_header );

    // Create the primary app stack
    window->m_stack_layout = std::make_shared<gui::LayoutStack>();

    // Add our main menu
    window->m_main_app_menu = Main_Menu::create( config, session );
    window->m_stack_layout->append( window->m_main_app_menu );

    // Add subsequent apps here!

    // Add the stack layout to the main window layout
    window->append( gui::WidgetLayout::from_layout( window->m_stack_layout ) );

    /// Create the footer
    window->m_footer = Footer_Widget::create( config, session );
    window->append( window->m_footer );

    return window;
}

} // End of tmns::calc::page namespace