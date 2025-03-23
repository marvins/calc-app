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
 * @file    EventType.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Represent Events from the UI.
 */
#pragma once

// C++ Standard Libraries
#include <string>

namespace tmns::calc::ui {

enum class EventType {
    KEYBOARD_DOWN  =  1,
    KEYBOARD_LEFT  =  2,
    KEYBOARD_RIGHT =  3,
    KEYBOARD_UP    =  4,
}; // End of EventType Event

/**
 * Convert the event-type to string
 */
std::string to_string( EventType tp );

} // End of tmns::calc::ui namespace
