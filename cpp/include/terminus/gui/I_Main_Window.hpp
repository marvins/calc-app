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
#include <terminus/driver/DriverBase.hpp>
#include <terminus/gui/I_Renderable.hpp>
#include <terminus/image/Frame_View.hpp>

namespace tmns::gui {

/**
 * Pure-Virtual Abstract interface for Main-Windows.
 */
class I_Main_Window : public I_Renderable
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<I_Main_Window>;

        /**
         * Check for updates to the main window.
         */
        virtual void update( core::Options& config,
                             gui::Session&  session ) = 0;

}; // End of Main-Window Class

} // End of tmns::gui Namespace