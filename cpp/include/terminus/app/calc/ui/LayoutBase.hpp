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
#include <tmns/app/calc/core/Session.hpp>
#include <tmns/app/calc/image/FrameView.hpp>
#include <tmns/app/calc/ui/WidgetLayoutItem.hpp>

namespace tmns::calc::ui {

/**
 * @class LayoutBase
 */
class LayoutBase
{
    public:

        /**
         * Show the contents of the layout on the screen
         */
        virtual bool render( core::Session&  session,
                             img::FrameView& image ) = 0;

        /**
         * Get the layout dimensions
         */
        img::Dimensions layout_dimensions() const;

        /**
         * Update the layout dimensions
         */
        virtual void set_layout_dimensions( img::Dimensions dims );

    private:

        // Declared Size
        img::Dimensions m_layout_dims;

};// End of LayoutBase class

} // End of tmns::calc::ui namespace
