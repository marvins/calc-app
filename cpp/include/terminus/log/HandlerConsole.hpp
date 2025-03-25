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
 * @file    HandlerBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Logging Interface
 */
#pragma once

// Project Libraries
#include <terminus/log/HandlerBase.hpp>
#include <terminus/log/Level.hpp>

// C++ Standard Libraries
#include <memory>

namespace tmns::log {

class HandlerConsole : public HandlerBase
{
    public:

        using ptr_t = std::unique_ptr<HandlerConsole>;

        /**
         * Construct a new Console Log Handler
         */
        HandlerConsole( Level min_severity = Level::INFO );

        /**
         * Log a message to the console
         */
        void log( Level       lvl,
                  TIME_TP     log_time,
                  std::string filename,
                  std::string func,
                  int         line_no,
                  std::string message ) override;

    private:

        /// Log Severity
        Level m_severity;

}; // End of HandlerConsole class

} // End of tmns::log namespace