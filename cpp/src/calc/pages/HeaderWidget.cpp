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
#include <terminus/gui/layout/LayoutHorizontal.hpp>
#include <terminus/gui/layout/LayoutPrimitives.hpp>
#include <terminus/log.hpp>

// C++ Standard Libraries
#include <chrono>
#include <iostream>
#include <sstream>

namespace tmns::calc::page {

/******************************************/
/*          Create Header Widget          */
/******************************************/
Header_Widget::ptr_t Header_Widget::create( const core::Options& config,
                                            gui::Session&        session,
                                            math::Size2i         parent_size )
{
    // Construct the layout.
    int header_width  = parent_size.width();
    int header_height = std::min( config.check_and_get_setting<int>("display","header_height"),
                                  parent_size.height() );

    LOG_TRACE( "Setting Header Size: " + std::to_string(header_width) + " x " + std::to_string(header_height) );
    LOG_TRACE( "Parent Size: " + parent_size.to_string() );
    auto layout = std::make_shared<gui::LayoutHorizontal>();
    layout->set_layout_size( math::Size2i( { header_width,
                                             header_height } ) );

    ///////////////////////////////////
    // Create the title label
    auto title_data = gui::Label::from_text( "Main Menu", session.driver() );
    std::set<gui::AlignmentPolicy> alignment { { gui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                 gui::AlignmentPolicy::CENTER_VERTICAL } };
    layout->append( title_data, alignment, {} );


    /////////////////////////////////
    // Create the time label
    std::string time_info;
    {
        std::stringstream sout;
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        sout << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
        time_info = sout.str();
    }

    auto time_data = gui::Label::from_text( time_info, session.driver() );
    alignment = std::set<gui::AlignmentPolicy>( { { gui::AlignmentPolicy::LEFT,
                                                    gui::AlignmentPolicy::CENTER_VERTICAL } } );
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
Header_Widget::Header_Widget( gui::LayoutBase::ptr_t layout )
    : gui::WidgetLayout( layout ){
        set_log_tag( "Header_Widget" );
    }


} // End of tmns::calc::page namespace
