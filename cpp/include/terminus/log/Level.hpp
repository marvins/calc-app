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
 * @file    Level.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Log Level Type
 */
#pragma once

// C++ Standard Libraries
#include <string>

namespace tmns::log {

enum class Level {
    TRACE   = 0,
    DEBUG   = 1,
    INFO    = 2,
    WARNING = 3,
    ERROR   = 4,
}; // End of Level Enumeration

/**
 * Convert the Log Level to String
 */
std::string to_string( Level );

} // End of tmns::log namespace