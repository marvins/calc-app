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
#include <terminus/calc/pages/Main_Window.hpp>
#include <terminus/core/Options.hpp>
#include <terminus/gui/core/Session.hpp>

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
        int run();

        /**
         * Create a new Splash Screen
         */
        static Application::ptr_t create( core::Options&       config,
                                          gui::Session&        session,
                                          I_Main_Window::ptr_t main_window );
        
    private:

        /// @brief Deleted Default Constructor
        Application() = delete;

        /**
         * @brief Parameterized Constructor
         */
        Application( core::Options&       config,
                     gui::Session&        session,
                     I_Main_Window::ptr_t main_window );

        /// @brief Application Configuration
        core::Options& m_config;

        /// @brief Application session data
        gui::Session& m_session;

        // Main Window context
        I_Main_Window::ptr_t m_main_window { nullptr };
        
}; // End Application class

} // End of tmns::gui namespace