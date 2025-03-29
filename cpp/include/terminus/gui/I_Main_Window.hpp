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
#include <terminus/image/Frame_View.hpp>

namespace tmns::gui {

/**
 * Pure-Virtual Abstract interface for Main-Windows.
 */
class I_Main_Window 
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<I_Main_Window>;

        /**
         * Render the Main-Window
         */
        virtual void render( core::Options&          config,
                             drv::Driver_Base::ptr_t driver,
                             img::Frame_View&        frame_view ) = 0;

}; // End of Main-Window Class

} // End of tmns::gui Namespace