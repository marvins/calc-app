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
#include <terminus/app/calc/log/Level.hpp>

namespace tmns::calc::log {

/**********************************************/
/*      Convert the Log Level to String       */
/**********************************************/
std::string to_string( Level lvl )
{
    switch( lvl ){
        case Level::TRACE:   return "TRACE";
        case Level::DEBUG:   return "DEBUG";
        case Level::INFO:    return "INFO";
        case Level::WARNING: return "WARNING";
        case Level::ERROR:   return "ERROR";
        default:             return "UNKNOWN";
    }
}

} // End of tmns::calc::log namespace