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
 * @file    LayoutStack.hpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Vertical Layout API
 */
#pragma once

// C++ Standard Libraries
#include <memory>

// Project Libraries
#include <terminus/calc/ui/LayoutBase.hpp>
#include <terminus/calc/ui/WidgetBase.hpp>

namespace tmns::calc::ui {

/**
 * @class LayoutStack
 */
class LayoutStack : public LayoutBase
{
    public:

        /// @brief Pointer Type
        typedef std::shared_ptr<LayoutStack> ptr_t;

        // Default Constructor
        LayoutStack() = default;

        // Destructor
        ~LayoutStack() override = default;

        /**
         * Add Widget to Lyout
         * 
         * @returns ID of the widget to use for referencing
         */
        size_t append( WidgetBase::ptr_t new_widget );

        /**
         * Show the contents of the layout
         */
        bool render( core::Session&  session,
                     img::FrameView& image ) override;

        /**
         * Get allocated region for widgets
         * 
         * @note:  This is not the space it'll use.  This is the space reserved
         *         - This takes into account the number of widgets, ratio, stretch policy, etc.
         */
        std::vector<math::Rect2i> allocate_bboxes() const override;

};// End of LayoutStretch class

} // End of tmns::calc::ui namespace
