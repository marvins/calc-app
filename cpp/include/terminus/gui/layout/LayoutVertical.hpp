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
#include <memory>

// Project Libraries
#include <terminus/gui/layout/LayoutBase.hpp>
#include <terminus/gui/widget/WidgetBase.hpp>

namespace tmns::gui {

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
         * Get the Vertical Stretch Policy
         */
        StretchPolicy vertical_stretch_policy() const;

        /**
         * Set the Vertical Stretch Policy
         */
        void set_vertical_stretch_policy( StretchPolicy policy );

        /**
         * Add Widget to Lyout
         */
        int append( WidgetBase::ptr_t new_widget ) override;

        /**
         * Add Widget to Lyout
         */
        int append( WidgetBase::ptr_t          new_widget,
                    std::set<AlignmentPolicy>  alignment,
                    std::optional<double>      ratio ) override;

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
         * 
         * Guidance on how rules are applied
         * - If StretchPolicy is FIXED:
         *    1. The total widget size is fetched
         *    2. The size is adjusted according to padding
         *        Rectangles are adjusted as well
         *    3. Ratios (for widgets which have them) are summed to get total.
         *      - Ratios are normalized so the ratios sum to 1  (in-ratio / sum-ratio)
         *    4. Widgets without ratios get auto-assigned the leftover ratios
         *    5. All widgets are assigned a box size
         * 
         * - non-Fixed is unsupported at this time
         */
        std::vector<math::Rect2i> allocate_bboxes() const override;

        /**
         * Print to Log-Friendly String
         */
        std::string to_log_string( size_t offset = 0 ) const override;

    protected: 
    
        /// Vertical Stretch Policy
        StretchPolicy m_vertical_stretch_policy { StretchPolicy::FIXED };

};// End of LayoutVertical class

} // End of tmns::gui namespace
