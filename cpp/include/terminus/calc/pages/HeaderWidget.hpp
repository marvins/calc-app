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
 * @file    HeaderWidget.hpp
 * @author  Marvin Smith
 * @date    03/26/2025
 *
 * @details Represent data shown in the header
 */
#pragma once

// Terminus Libraries
#include <terminus/gui/layout/LayoutHorizontal.hpp>
#include <terminus/gui/widget/Label.hpp>
#include <terminus/gui/widget/WidgetLayout.hpp>

namespace tmns::calc::page {

/**
 * @class Header_Widget
 */
class Header_Widget : public gui::WidgetLayout
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Header_Widget>;

        /**
         * Create the widget
         */
        static Header_Widget::ptr_t create( const core::Options& config,
                                            gui::Session&        session,
                                            math::Size2i         parent_size );

    private:

        Header_Widget() = delete;

        Header_Widget( gui::LayoutBase::ptr_t layout );


        /// Label storing time information
        gui::Label::ptr_t m_time_data;

        /// Label storing title page
        gui::Label::ptr_t m_title_data;

};// End of Header_Widget class

} // End of tmns::calc::page namespace
