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
 * @file    FooterWidget.cpp
 * @author  Marvin Smith
 * @date    03/26/2025
 *
 * @details Represent data shown in the footer
 */
#include <terminus/calc/pages/FooterWidget.hpp>

// Project Libraries
#include <terminus/gui/layout/LayoutHorizontal.hpp>
#include <terminus/gui/widget/Label.hpp>
#include <terminus/gui/widget/WidgetLayout.hpp>
#include <terminus/log.hpp>

namespace tmns::calc::page {

/******************************************/
/*          Create Footer Widget          */
/******************************************/
Footer_Widget::ptr_t Footer_Widget::create( const core::Options& config,
                                            gui::Session&        session )
{
    // Construct the layout.
    int footer_width  = session.driver()->get_screen_dimensions().cols(); 
    int footer_height = config.setting<int>("display","footer_height");

    LOG_TRACE( "Setting Footer Size: " + std::to_string(footer_width) + " x " + std::to_string(footer_height) );
    auto layout = std::make_shared<gui::LayoutHorizontal>();
    layout->set_layout_size( math::Size2i( { footer_width,
                                             footer_height } ) );


    // Commands for the footer will be provided by the context manager
    std::string commands = "some-text to be solved later.";

    ///////////////////////////////////
    // Create the title label
    auto command_label = gui::Label::from_text( commands, session.driver() );
    std::set<gui::AlignmentPolicy> alignment { { gui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                 gui::AlignmentPolicy::CENTER_VERTICAL } };
    layout->append( command_label, alignment, {} );

    // Create instance
    auto inst = std::shared_ptr<Footer_Widget>( new Footer_Widget( layout ) );

    inst->m_command_data = command_label;

    return inst;
}

/********************************************/
/*          Parameterized Constructor       */
/********************************************/
Footer_Widget::Footer_Widget( gui::LayoutBase::ptr_t layout )
: gui::WidgetLayout( layout ){}

} // End of tmns::calc::page namespace
