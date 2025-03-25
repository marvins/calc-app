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
 * @date    3/25/2025
 */

// GoogleTest
#include <gtest/gtest.h>

int main( int argc, char* argv[] )
{
    // Parse Command-Line Options

    
    // Initialize Logging
    {
        auto handler = std::make_unique<tmns::log::HandlerConsole>( tmns::log::Level::DEBUG );
        tmns::calc::log::Logger::add_handler( std::move( handler ) );
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}