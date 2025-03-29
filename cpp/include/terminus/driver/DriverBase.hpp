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
#include <terminus/core/Options.hpp>
#include <terminus/image/Frame.hpp>

namespace tmns::drv {

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
        virtual int finalize() = 0;

        /**
         * Check if we have any exit conditions.
         * @returns True if good to keep running, false if we should exit.
         */
        virtual bool okay_to_run() = 0;

        /**
         * Display the current image.
         */
        virtual void show( img::Frame& frame ) = 0;

        /**
         * Get default screen dimensions
         */
        virtual img::Dimensions get_screen_dimensions() const = 0;

        /**
         * Load image from disk
         */
        virtual img::Frame::ptr_t load_image( const std::filesystem::path& path ) = 0;

        /**
         * Rasterize Text
         */
        virtual img::Frame::ptr_t rasterize_text( const std::string& message ) = 0;

        /**
         * Print Log-Friendly String
         */
        virtual std::string to_log_string( size_t offset = 0 ) const = 0;

}; // End of Driver_Base class


} // End of tmns::drv namespace