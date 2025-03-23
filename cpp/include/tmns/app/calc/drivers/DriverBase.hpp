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
 * @file    DriverBase.hpp
 * @author  Marvin Smith
 * @date    3/22/2025
 */
#pragma once

// Project Libraries
#include <tmns/app/calc/core/Options.hpp>
#include <tmns/app/calc/ui/Frame.hpp>

namespace tmns::calc::drv {

class Driver_Base {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Driver_Base>;

        /**
         * Initialize the driver
         */
        virtual bool initialize( core::Options& config ) = 0;

        /**
         * Finalize / Destroy the driver
         */
        virtual void finalize() = 0;

        /**
         * Load image from disk
         */
        virtual ui::Frame::ptr_t load_image( const std::filesystem::path& path ) = 0;


}; // End of Driver_Base class


} // End of tmns::calc::drv namespace