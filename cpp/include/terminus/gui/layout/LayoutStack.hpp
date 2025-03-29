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
#include <terminus/gui/layout/LayoutBase.hpp>
#include <terminus/gui/widget/WidgetBase.hpp>

namespace tmns::gui {

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
        int append( WidgetBase::ptr_t new_widget ) override;

        /**
         * Show the contents of the layout
         */
        bool render( Session&         session,
                     img::Frame_View& image ) override;

        /**
         * Get allocated region for widgets
         * 
         * @note:  This is not the space it'll use.  This is the space reserved
         *         - This takes into account the number of widgets, ratio, stretch policy, etc.
         */
        std::vector<math::Rect2i> allocate_bboxes() const override;

    private:

        /// Index of current frame to show.  Optional since it's invalid until used.
        std::optional<size_t> m_current_frame { 0 };

};// End of LayoutStack class

} // End of tmns::gui namespace
