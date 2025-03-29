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
 * @file    I_Main_Window.hpp
 * @author  Marvin Smith
 * @date    3/27/2025
 */
#pragma once

// Terminus Libraries
#include <terminus/core/Options.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/image/Frame_View.hpp>

namespace tmns::gui {

/**
 * Pure-Virtual Abstract interface for anything with a "Render" call
 */
class I_Renderable 
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<I_Renderable>;

        /**
         * @brief Render the image to the desired screen instance
         */
        virtual bool render( Session&         session,
                             img::Frame_View& image ) = 0;

}; // End of Main-Window Class

} // End of tmns::gui Namespace