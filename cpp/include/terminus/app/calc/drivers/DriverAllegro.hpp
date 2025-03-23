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
 * @file    DriverAllegro.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Vertical Layout API
 */
#pragma once

// Allegro APIs
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

// OpenCV APIs


// Project Libraries
#include <terminus/app/calc/core/Options.hpp>
#include <terminus/app/calc/drivers/DriverBase.hpp>

namespace tmns::calc::drv {

class Driver_Allegro : public Driver_Base {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Driver_Allegro>;

        /**
         * Initialize Library
         */
        bool initialize( core::Options& config ) override;

        /**
         * Close / Finalize
         */
        void finalize() override;

        /**
         * Get screen dimensions
         */
        img::Dimensions get_screen_dimensions() const override;

        /**
         * Load image from disk.
         */
        img::Frame::ptr_t load_image( const std::filesystem::path& path ) override;

        /**
         * Print log-friendly string
         */
        std::string to_log_string( size_t offset = 0 ) const override;
        
        /**
         * Create a new instance of the driver.
         */
        static Driver_Allegro::ptr_t create( core::Options& config );

    protected:

        void configure_display( core::Options& options );

    private:

        ALLEGRO_TIMER* m_timer { nullptr };

        ALLEGRO_EVENT_QUEUE* m_queue { nullptr };

        ALLEGRO_DISPLAY* m_display { nullptr };

        ALLEGRO_FONT* m_font { nullptr };

}; // End of Driver_Allegro class

} // End of tmns::calc::drv namespace
