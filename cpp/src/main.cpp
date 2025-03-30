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
 * @file    main.cpp
 * @author  Marvin Smith
 * @date    3/21/2025
 */

// Project Libraries
#include <terminus/calc/apps/App_Factory.hpp>
#include <terminus/calc/pages/Main_Window.hpp>
#include <terminus/calc/pages/Splash.hpp>
#include <terminus/core/Options.hpp>
#include <terminus/gui/core/Application.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/log/HandlerConsole.hpp>
#include <terminus/log/Logger.hpp>

int main( int argc, char* argv[] ){

    // Parse Command-Line and Configuration-File Options
    auto config = tmns::core::Options::parse( argc, argv );

    // Setup the console logger
    {
        auto handler = std::make_unique<tmns::log::HandlerConsole>( config.log_level() );
        tmns::log::Logger::add_handler( std::move( handler ) );
    }
    LOG_DEBUG( config.to_log_string() );

    // Create the primary session
    auto session = tmns::gui::Session::create( config );

    LOG_DEBUG( session->to_log_string() );

    // Launch the Splash Screen
    auto splash = tmns::calc::page::Splash::create( config, *session );
    splash->show( config, *session );

    // Create list of applications
    auto app_list = tmns::calc::App_Factory::default_apps( config, *session );

    // Generate the main window
    auto main_window = tmns::calc::page::Main_Window::create( config, *session, app_list );

    // Build application
    auto app = tmns::gui::Application::create( config,
                                               *session,
                                               main_window );
    return app->run();
}