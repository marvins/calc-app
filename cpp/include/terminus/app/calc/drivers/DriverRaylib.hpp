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
 * @file    DriverRaylib.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Raylib API Driver
 */
#pragma once

// Raylib APIs
//    Helpful Cheatsheet:  https://www.raylib.com/cheatsheet/cheatsheet.html
#include <raylib.h>

// OpenCV APIs


// Project Libraries
#include <terminus/app/calc/core/Options.hpp>
#include <terminus/app/calc/drivers/DriverBase.hpp>

namespace tmns::calc::drv {

class Driver_Raylib : public Driver_Base {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Driver_Raylib>;

        /**
         * Initialize Library
         */
        bool initialize( core::Options& config ) override;

        /**
         * Close / Finalize
         */
        void finalize() override;

        /**
         * Display the current image.
         */
        void show( img::Frame& frame ) override;

        /**
         * Get screen dimensions
         */
        img::Dimensions get_screen_dimensions() const override;

        /**
         * Load image from disk.
         */
        img::Frame::ptr_t load_image( const std::filesystem::path& path ) override;

        /**
         * Generate Image from Text
         */
        img::Frame::ptr_t rasterize_text( const std::string& message ) override;

        /**
         * Print log-friendly string
         */
        std::string to_log_string( size_t offset = 0 ) const override;
        
        /**
         * Create a new instance of the driver.
         */
        static Driver_Raylib::ptr_t create( core::Options& config );

    protected:

        void configure_display( core::Options& options );

    private:

        /// Current Window Size
        int m_window_cols { 0 };
        int m_window_rows { 0 };


}; // End of Driver_Raylib class

} // End of tmns::calc::drv namespace