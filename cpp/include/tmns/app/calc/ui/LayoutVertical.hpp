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
 * @file    LayoutVertical.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Vertical Layout API
 */
#pragma once

// C++ Standard Libraries
#include <deque>
#include <memory>
#include <mutex>

// Project Libraries
#include <tmns/app/calc/ui/LayoutBase.hpp>
#include <tmns/app/calc/ui/WidgetBase.hpp>

namespace tmns::calc::ui {

/**
 * @class LayoutVertical
 */
class LayoutVertical : public LayoutBase
{
    public:

        /// @brief Pointer Type
        typedef std::shared_ptr<LayoutVertical> ptr_t;

        // Default Constructor
        LayoutVertical() = default;

        /**
         * Add Widget to Lyout
         */
        void append( WidgetBase::ptr_t new_widget );

        /**
         * Show the contents of the layout
         */
        bool render( core::Session& session,
                     img::Frame&    image ) override;

    protected:

        /// Access to widget list
        std::mutex m_widget_mtx;

        /// List of widgets
        std::deque<WidgetBase::ptr_t> m_widgets;

};// End of LayoutVertical class

} // End of tmns::calc::ui namespace
