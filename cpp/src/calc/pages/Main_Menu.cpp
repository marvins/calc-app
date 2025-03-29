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
 * @file    Main_Menu.cpp
 * @author  Marvin Smith
 * @date    3/27/2025
 */
#include <terminus/calc/pages/Main_Menu.hpp>

// Project Libraries
#include <terminus/gui/widget/Label.hpp>
#include <terminus/image.hpp>
#include <terminus/log.hpp>

namespace tmns::calc::page {

/************************************/
/*          Set Layout Size         */
/************************************/
void Main_Menu::set_layout_size( math::Size2i layout_size )
{
    layout()->set_layout_size( layout_size );
}

/************************************/
/*          Create the Menu         */
/************************************/
Main_Menu::ptr_t Main_Menu::create( core::Options& config,
                                    gui::Session&  session,
                                    math::Size2i   parent_size )
{
    // Construct layout
    auto layout = std::make_shared<gui::LayoutVertical>();
    layout->set_padding( 10, 10, 10, 10 );
    layout->set_padding_color( img::PIXEL_RED() );

    // Height of the menu as we add items
    int layout_height = 0;

    // Add temp widget
    auto label = gui::Label::from_text("HELLO WORLD", session.driver());
    layout->append( label );
    layout_height += label->size_pixels().height();

    // Update layout height
    layout->set_layout_size( math::Size2i( { parent_size.width(),
                                             layout_height } ) );

    // Create instance
    auto inst = std::shared_ptr<Main_Menu>( new Main_Menu( layout ) );

    return inst;
}

/************************************/
/*          Constructor             */
/************************************/
Main_Menu::Main_Menu( gui::LayoutVertical::ptr_t main_layout )
    : gui::WidgetLayout( main_layout )
{}

} // End of tmns::calc::page namespace