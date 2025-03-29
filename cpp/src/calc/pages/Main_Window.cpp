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
#include <terminus/image.hpp>
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
    master_layout->set_padding( 10, 10, 10, 10 );
    master_layout->set_padding_color( img::PIXEL_PINK() );

    // Get the area inside the bbox without padding
    auto master_bbox = master_layout->get_bbox_with_padding( math::Rect2i( { math::Vector2i({0,0}),
                                                                             master_layout->layout_size() }));
    math::Size2i master_render_size( { master_bbox.width(), master_bbox.height() } );

    /// Create window instance
    auto window = std::shared_ptr<Main_Window>( new Main_Window( master_layout ) );

    /// Create the header
    window->m_header = Header_Widget::create( config, session, master_render_size );
    window->m_header->set_border( img::PIXEL_BLACK() );
    window->m_base_widget->layout()->append( window->m_header, gui::ALIGN_TOP_CENTER(), {} );

    // Create the primary app stack
    window->m_stack_layout = std::make_shared<gui::LayoutStack>();
    window->m_stack_layout->set_padding( 10, 10, 10, 10 );
    window->m_stack_layout->set_padding_color( img::PIXEL_GREEN() );

    // Add our main menu
    window->m_main_app_menu = Main_Menu::create( config, session, master_render_size );
    window->m_stack_layout->append( window->m_main_app_menu );

    // Add subsequent apps here!

    // Add the stack layout to the main window layout
    window->m_base_widget->layout()->append( gui::WidgetLayout::from_layout( window->m_stack_layout ) );

    /// Create the footer
    window->m_footer = Footer_Widget::create( config, session, master_render_size );
    window->m_footer->set_border( img::PIXEL_BLACK() );
    window->m_base_widget->layout()->append( window->m_footer, gui::ALIGN_BOTTOM_CENTER(), {} );

    /// Get the stack layout size
    /*
    auto stack_view_size = window->m_header->layout()->get_bbox_with_padding();

    int stack_width  = stack_view_size.width();
    int stack_height = stack_view_size.height()
                       - window->m_header->layout()->layout_size().height()
                       - window->m_footer->layout()->layout_size().height();
    window->m_stack_layout->set_layout_size( math::Size2i( { stack_width, stack_height } ) );
    */

    return window;
}

/********************************/
/*          Constructor         */
/********************************/
Main_Window::Main_Window( gui::LayoutBase::ptr_t layout )
    : m_base_widget( gui::WidgetLayout::from_layout( layout ) )
{}

} // End of tmns::calc::page namespace