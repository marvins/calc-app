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
#include <terminus/calc/ui/Label.hpp>
#include <terminus/calc/ui/LayoutHorizontal.hpp>
#include <terminus/calc/ui/WidgetLayout.hpp>

namespace tmns::calc::page {

/******************************************/
/*          Create Header Widget          */
/******************************************/
Footer_Widget::ptr_t Footer_Widget::create( const core::Options& config,
                                            core::Session&       session )
{
    auto layout = std::make_shared<ui::LayoutHorizontal>();


    // Commands for the footer will be provided by the context manager
    std::string commands = "some-text to be solved later.";


    ///////////////////////////////////
    // Create the title label
    auto command_label = ui::Label::from_text( commands, session.driver() );
    std::set<ui::AlignmentPolicy> alignment { { ui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                ui::AlignmentPolicy::CENTER_VERTICAL } };
    layout->append( command_label, alignment, {} );

    // Create instance
    auto inst = std::shared_ptr<Footer_Widget>( new Footer_Widget( layout ) );

    inst->m_command_data = command_label;

    return inst;
}

/********************************************/
/*          Parameterized Constructor       */
/********************************************/
Footer_Widget::Footer_Widget( ui::LayoutBase::ptr_t layout )
: ui::WidgetLayout( layout ){}

} // End of tmns::calc::page namespace
