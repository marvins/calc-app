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
#include <terminus/log.hpp>

namespace tmns::calc::page {

/****************************************/
/*          Update Main Window          */
/****************************************/
void Main_Window::update( core::Options& config,
                          gui::Session&  session )
{
    LOG_DEBUG( "Updating Main Window" );
}

/************************************/
/*          Render Widget           */
/************************************/
bool Main_Window::render( gui::Session&    session,
                          img::Frame_View& image )
{
    return m_base_widget->render( session, image );
}

/****************************************/
/*          Create new Window           */
/****************************************/
Main_Window::ptr_t Main_Window::create( core::Options& config,
                                        gui::Session&  session )
{
    // Create the master layout
    auto master_layout = std::make_shared<gui::LayoutVertical>();
    master_layout->set_layout_size( session.driver()->get_screen_dimensions().size() );

    /// Create window instance
    auto window = std::shared_ptr<Main_Window>( new Main_Window( master_layout ) );

    /// Create the header
    window->m_header = Header_Widget::create( config, session );
    window->m_base_widget->layout()->append( window->m_header );

    // Create the primary app stack
    window->m_stack_layout = std::make_shared<gui::LayoutStack>();

    // Add our main menu
    window->m_main_app_menu = Main_Menu::create( config, session );
    window->m_stack_layout->append( window->m_main_app_menu );

    // Add subsequent apps here!

    // Add the stack layout to the main window layout
    window->m_base_widget->layout()->append( gui::WidgetLayout::from_layout( window->m_stack_layout ) );

    /// Create the footer
    window->m_footer = Footer_Widget::create( config, session );
    window->m_base_widget->layout()->append( window->m_footer );

    return window;
}

/********************************/
/*          Constructor         */
/********************************/
Main_Window::Main_Window( gui::LayoutBase::ptr_t layout )
    : m_base_widget( gui::WidgetLayout::from_layout( layout ) )
{}

} // End of tmns::calc::page namespace