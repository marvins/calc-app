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
#include <tmns/app/calc/core/Options.hpp>
#include <tmns/app/calc/drivers/DriverBase.hpp>

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
         * Load image from disk.
         */
        ui::Frame::ptr_t load_image( const std::filesystem::path& path ) override;

        /**
         * Create a new instance of the driver.
         */
        static Driver_Allegro::ptr_t create( core::Options& config );

    private:

        ALLEGRO_TIMER* m_timer { nullptr };

        ALLEGRO_EVENT_QUEUE* m_queue { nullptr };

        ALLEGRO_DISPLAY* m_display { nullptr };

        ALLEGRO_FONT* m_font { nullptr };

}; // End of Driver_Allegro class

} // End of tmns::calc::drv namespace
