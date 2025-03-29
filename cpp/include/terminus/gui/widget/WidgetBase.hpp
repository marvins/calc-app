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
 * @file    WidgetBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Base Widget API
 */
#pragma once

// C++ Libraries
#include <memory>

// Project Libraries
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/I_Renderable.hpp>
#include <terminus/image/Frame_View.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::gui {

/**
 * @class WidgetBase
 */
class WidgetBase : public I_Renderable
{
    public:

        /// @brief  Pointer Type
        using ptr_t = std::shared_ptr<WidgetBase>;

        /**
         * @brief Get the size of the widget, in pixels
         */
        virtual math::Size2i size_pixels() const = 0;

    private:

};// End of WidgetBase class

} // End of tmns::gui namespace
