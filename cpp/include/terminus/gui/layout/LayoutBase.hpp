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
 * @file    LayoutBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Base Layout API
 */
#pragma once

// Project Libraries
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/layout/WidgetLayoutItem.hpp>
#include <terminus/image/FrameView.hpp>

// C++ Standard Libraries
#include <memory>
#include <vector>

namespace tmns::gui {

/**
 * @class LayoutBase
 */
class LayoutBase
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<LayoutBase>;

        /// @brief Destructor
        virtual ~LayoutBase() = default;

        /**
         * Show the contents of the layout on the screen
         */
        virtual bool render( Session&        session,
                             img::FrameView& image ) = 0;

        /**
         * Get the layout dimensions
         */
        math::Size2i layout_size() const;

        /**
         * Update the layout dimensions
         */
        virtual void set_layout_size( math::Size2i size );

        /**
         * Get the assigned padding
         */
        math::Vector4i padding() const;

        /**
         * Set Padding
         * Order is ( left, right, top, bottom )
         */
        void set_padding( math::Vector4i padding );

        /**
         * Set Padding
         * Order is ( left, right, top, bottom )
         */
        void set_padding( int left, int right, int top, int bottom );

        /**
         * Get access to widgets
         */
        std::vector<WidgetLayoutItem>& widgets();
    
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
        virtual std::vector<math::Rect2i> allocate_bboxes() const = 0;

        /**
         * Align the Widget within the Bounding box.
         */
        static math::Rect2i align_widget( math::Rect2i              bbox_allocated,
                                          math::Size2i              widget_size,
                                          std::set<AlignmentPolicy> alignment );

    protected:

        /// List of widgets
        std::vector<WidgetLayoutItem> m_widgets;
        
    private:

        /// @brief Declared Size
        math::Size2i m_layout_size;

        /// @brief Padding to use
        math::Vector4i m_padding { { 0, 0, 0, 0 } };

};// End of LayoutBase class

} // End of tmns::gui namespace
