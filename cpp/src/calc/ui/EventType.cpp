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
 * @file    EventType.cpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Represent Events from the UI.
 */
#include <terminus/calc/ui/EventType.hpp>

// C++ Standard Libraries
#include <string>

namespace tmns::calc::ui {

/************************************************/
/*      Convert the event-type to string        */
/************************************************/
std::string to_string( EventType tp )
{
    switch( tp )
    {
        case EventType::KEYBOARD_DOWN:
            return "KEYBOARD_DOWN";
        case EventType::KEYBOARD_LEFT:
            return "KEYBOARD_LEFT";
        case EventType::KEYBOARD_RIGHT:
            return "KEYBOARD_RIGHT";
        case EventType::KEYBOARD_UP:
            return "KEYBOARD_UP";
        default:
            return "UNKNOWN";
    }
}

} // End of tmns::calc::ui namespace