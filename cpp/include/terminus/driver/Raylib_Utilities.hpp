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
 * @file    Raylib_Utilities.cpp
 * @author  Marvin Smith
 * @date    03/25/2025
 *
 * @details Raylib Graphics API Wrapper Source
 */
#pragma once

// Raylib
#include <raylib.h>

// C++ Standard Libraries
#include <string>

namespace tmns::drv {

/**
 * Convert a Raylib PixelFormat enum into number of channels
 */
size_t raylib_format_to_channels( PixelFormat fmt );

/**
 * Convert a Raylib PixelFormat to a string
 */
std::string to_string( PixelFormat fmt );

} // End of tmns::drv namespace