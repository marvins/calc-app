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
 * @file    Application.hpp
 * @author  Marvin Smith
 * @date    3/27/2025
 */
#pragma once

// Project Libraries
#include <terminus/calc/core/Options.hpp>
#include <terminus/calc/core/Session.hpp>
#include <terminus/calc/pages/Main_Window.hpp>

namespace tmns::gui {

class Application
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Application>;

        /**
         * Run the application
         * 
         * @return Exit code.
         */
        int run( core::Options& config,
                 core::Session& session );

        /**
         * Create a new Splash Screen
         */
        static Application::ptr_t create( const core::Options& config,
                                          core::Session&       session );
        
    private:

        /// @brief Application Configuration
        core::Options& m_config;

        /// @brief Application session data
        core::Session& m_session;

        // Main Window context
        page::I_Main_Window::ptr_t m_main_window { nullptr };
        
}; // End Application class

} // End of tmns::gui namespace