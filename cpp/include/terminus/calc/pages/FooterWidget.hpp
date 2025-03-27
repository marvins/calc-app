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
 * @file    FooterWidget.hpp
 * @author  Marvin Smith
 * @date    03/26/2025
 *
 * @details Represent data shown in the footer
 */
#pragma once

// Project Libraries
#include <terminus/calc/ui/Label.hpp>
#include <terminus/calc/ui/LayoutHorizontal.hpp>
#include <terminus/calc/ui/WidgetLayout.hpp>

namespace tmns::calc::page {

/**
 * @class Footer_Widget
 */
class Footer_Widget : public ui::WidgetLayout
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Footer_Widget>;

        /**
         * Create the widget
         */
        static Footer_Widget::ptr_t create( const core::Options& config,
                                            core::Session&       session );

    private:

        Footer_Widget() = default;

        Footer_Widget( ui::LayoutBase::ptr_t layout );

        /// Label storing command information
        ui::Label::ptr_t m_command_data;

};// End of Footer_Widget class

} // End of tmns::calc::page namespace
