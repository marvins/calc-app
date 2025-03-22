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
#include <tmns/app/calc/core/Options.hpp>
#include <tmns/app/calc/core/Session.hpp>
#include <tmns/app/calc/log/HandlerConsole.hpp>
#include <tmns/app/calc/log/Logger.hpp>
#include <tmns/app/calc/pages/Splash.hpp>

int main( int argc, char* argv[] ){

    // Parse Command-Line and Configuration-File Options
    auto config = tmns::calc::core::Options::parse( argc, argv );

    // Setup the console logger
    {
        auto handler = std::make_unique<tmns::calc::log::HandlerConsole>( config.log_level() );
        tmns::calc::log::Logger::add_handler( std::move( handler ) );
    }
    LOG_DEBUG( config.to_log_string() );

    // Create the primary session
    auto session = tmns::calc::core::Session::create( config );

    // Launch the Splash Screen
    auto splash = tmns::calc::page::Splash::create( config, session );
    splash->show( session );
    session.sleep_for( std::chrono::milliseconds(5000) );

    return 0;
}