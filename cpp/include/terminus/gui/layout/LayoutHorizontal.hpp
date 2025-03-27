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
 * @file    LayoutHorizontal.hpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Horizontal Layout API
 */
#pragma once

// C++ Standard Libraries
#include <memory>

// Project Libraries
#include <terminus/gui/layout/LayoutBase.hpp>
#include <terminus/gui/widget/WidgetBase.hpp>

namespace tmns::gui {

/**
 * @class LayoutHorizontal
 */
class LayoutHorizontal : public LayoutBase
{
    public:

        /// @brief Pointer Type
        typedef std::shared_ptr<LayoutHorizontal> ptr_t;

        // Default Constructor
        LayoutHorizontal() = default;

        /**
         * Get the Vertical Stretch Policy
         */
        StretchPolicy horizontal_stretch_policy() const;

        /**
         * Set the Horizontal Stretch Policy
         */
        void set_horizontal_stretch_policy( StretchPolicy policy );

        /**
         * Add Widget to Lyout
         */
        void append( WidgetBase::ptr_t new_widget );

        /**
         * Add Widget to Lyout
         */
        void append( WidgetBase::ptr_t          new_widget,
                     std::set<AlignmentPolicy>  alignment,
                     std::optional<double>      ratio );

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

    protected: 
    
        /// Horizontal Stretch Policy
        StretchPolicy m_horizontal_stretch_policy { StretchPolicy::FIXED };

};// End of LayoutHorizontal class

} // End of tmns::gui namespace