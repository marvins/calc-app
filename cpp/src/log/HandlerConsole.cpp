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
 * @file    HandlerConsole.cpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Logging Interface
 */
#include <terminus/log/HandlerConsole.hpp>

// C++ Standard Libraries
#include <filesystem>
#include <iostream>
#include <sstream>

namespace tmns::log {

/********************************/
/*          Constructor         */
/********************************/
HandlerConsole::HandlerConsole( Level min_severity )
    : m_severity { min_severity }
{}

/********************************/
/*          Log a Message       */
/********************************/
void HandlerConsole::log( Level       lvl,
                          TIME_TP     log_time,
                          std::string filename,
                          std::string func,
                          int         line_no,
                          std::string message ) 
{
    std::stringstream sout;
    
    // Process log time
    auto t = std::chrono::system_clock::to_time_t( log_time );
    auto tm = *std::localtime(&t);
    std::cout << "[" << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << "] ";

    // Process severity 
    std::cout << "[" << to_string( lvl ) << "] ";

    // Process filename
    std::cout << "(" << std::filesystem::path(filename).filename().native();
    
    // Process function and line
    std::cout << " func: " << func << " line: " << line_no << ") ";

    // Process message
    std::cout << message << std::endl;
}


} // End of tmns::log namespace