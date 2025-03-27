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
 * @file    WidgetLayout.hpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Simple widget for assigning Layouts to.
 */
#pragma once

// Project Libraries
#include <terminus/calc/ui/LayoutBase.hpp>
#include <terminus/calc/ui/WidgetBase.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::calc::ui {

/**
 * Simple widget object which effectively wraps a layout. 
 * Does nothing but show the contents of the layout.
 */
class WidgetLayout : public WidgetBase {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<WidgetLayout>;
        
        /**
         * Get the label size
         */
        math::Size2i size_pixels() const override;

        /**
         * Get the layout info
         */
        LayoutBase::ptr_t layout();

        /**
         * Show the label
         */
        bool render( core::Session&  session,
                     img::FrameView& image ) override;

        /**
         * Load an image and store in the label
         */
        static WidgetLayout::ptr_t from_layout( LayoutBase::ptr_t layout );

    protected:

        WidgetLayout() = delete;

        /**
         * Construct from existing layout
         */
        WidgetLayout( LayoutBase::ptr_t layout );

    private:

        /// Layout
        LayoutBase::ptr_t m_layout;

}; // End of WidgetLayout Class

} // End of tmns::calc::ui namespace