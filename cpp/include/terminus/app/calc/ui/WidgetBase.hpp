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
#include <terminus/app/calc/core/Session.hpp>
#include <terminus/app/calc/image/Frame.hpp>

namespace tmns::calc::ui {

/**
 * @class WidgetBase
 */
class WidgetBase
{
    public:

        /// @brief  Pointer Type
        using ptr_t = std::shared_ptr<WidgetBase>;

        /**
         * @brief Render the image to the desired screen instance
         */
        virtual bool render( core::Session& session,
                             img::Frame&    image ) = 0;

    private:

};// End of WidgetBase class

} // End of tmns::calc::ui namespace
