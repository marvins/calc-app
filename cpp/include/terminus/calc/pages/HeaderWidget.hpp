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
#include <terminus/calc/ui/Label.hpp>
#include <terminus/calc/ui/LayoutHorizontal.hpp>
#include <terminus/calc/ui/WidgetLayout.hpp>

namespace tmns::calc::page {

/**
 * @class Header_Widget
 */
class Header_Widget : public ui::WidgetLayout
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Header_Widget>;

        /**
         * Create the widget
         */
        static Header_Widget::ptr_t create( const core::Options& config,
                                            core::Session&       session );

    private:

        Header_Widget() = delete;

        Header_Widget( ui::LayoutBase::ptr_t layout );


        /// Label storing time information
        ui::Label::ptr_t m_time_data;

        /// Label storing title page
        ui::Label::ptr_t m_title_data;

};// End of Header_Widget class

} // End of tmns::calc::page namespace
