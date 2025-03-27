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
 * @file    HeaderWidget.cpp
 * @author  Marvin Smith
 * @date    03/26/2025
 *
 * @details Represent data shown in the header
 */
#include <terminus/calc/pages/HeaderWidget.hpp>

// Project Libraries
#include <terminus/calc/ui/LayoutHorizontal.hpp>
#include <terminus/calc/ui/LayoutPrimitives.hpp>

// C++ Standard Libraries
#include <chrono>
#include <iostream>
#include <sstream>

namespace tmns::calc::page {

/******************************************/
/*          Create Header Widget          */
/******************************************/
Header_Widget::ptr_t Header_Widget::create( const core::Options& config,
                                            core::Session&       session )
{
    auto layout = std::make_shared<ui::LayoutHorizontal>();

    ///////////////////////////////////
    // Create the title label
    auto title_data = ui::Label::from_text( "Main Menu", session.driver() );
    std::set<ui::AlignmentPolicy> alignment { { ui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                ui::AlignmentPolicy::CENTER_VERTICAL } };
    layout->append( title_data, alignment, {} );


    /////////////////////////////////
    // Create the time label
    std::string time_info;
    {
        auto cur_time = std::chrono::system_clock::now();
        
        std::stringstream sout;
        sout << std::chrono::current_zone()->to_local(cur_time);
    }

    auto time_data = ui::Label::from_text( time_info, session.driver() );
    alignment = std::set<ui::AlignmentPolicy>( { { ui::AlignmentPolicy::LEFT,
                                                   ui::AlignmentPolicy::CENTER_VERTICAL } } );
    layout->append( time_data, alignment, {} );  

    // Create instance
    auto inst = std::shared_ptr<Header_Widget>( new Header_Widget( layout ) );

    inst->m_title_data = title_data;
    inst->m_time_data  = time_data;

    return inst;
}

/********************************************/
/*          Parameterized Constructor       */
/********************************************/
Header_Widget::Header_Widget( ui::LayoutBase::ptr_t layout )
    : ui::WidgetLayout( layout ){}


} // End of tmns::calc::page namespace
