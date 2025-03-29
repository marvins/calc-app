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
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#pragma once

// C++ Standard Libraries
#include <chrono>
#include <filesystem>

// Project Libraries
#include <terminus/core/Options.hpp>
#include <terminus/image/Frame.hpp>
#include <terminus/driver/DriverBase.hpp>

namespace tmns::gui {

class Session final {

    public:

        /**
         * Get a copy of the driver
         */
        drv::Driver_Base::ptr_t driver() const;

        /**
         * Get a copy of the current screen buffer
         */
        img::Frame& active_frame();

        /**
         * Check if we should close window
         */
        bool okay_to_run();

        /**
         * Finalize and close session
         * 
         * @returns Exit code to apply
         */
        int finalize();

        /**
         * Sleep for a designated amount
         */
        void sleep_for( std::chrono::milliseconds sleep_time );

        /**
         * Show the active frame
         */
        void show();

        /**
         * Print information about session
         */
        std::string to_log_string( size_t offset = 0 ) const;

        /**
         * Generate a session given command-line instructions
         */
        static Session create( core::Options config );

    private:

        // Internal Driver
        drv::Driver_Base::ptr_t m_driver;

        // Active Frame
        img::Frame m_active_frame;


}; // End of Session class

} // End of tmns::gui namespace