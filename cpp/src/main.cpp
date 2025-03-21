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

int main( int argc, char* argv[] ){

    // Parse Command-Line and Configuration-File Options
    auto config = tmns::calc::core::Options::parse( argc, argv );

    // Create the primary session
    auto session = tmns::calc::core::Session::create( config );

    return 0;
}