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
#include <tmns/app/calc/log/HandlerConsole.hpp>

// C++ Standard Libraries
#include <filesystem>
#include <iostream>
#include <sstream>

namespace tmns::calc::log {

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
                          int         line_no,
                          std::string message ) 
{
    std::stringstream sout;
    
    // Process log time
    std::cout << "[" << std::chrono::current_zone()->to_local(log_time) << "] ";

    // Process severity 
    std::cout << "[" << to_string( lvl ) << "] ";

    // Process filename
    std::cout << "(" << std::filesystem::path(filename).filename().native() << " line: " << line_no << ") ";

    // Process message
    std::cout << message << std::endl;
}


} // End of tmns::calc::utils namespace