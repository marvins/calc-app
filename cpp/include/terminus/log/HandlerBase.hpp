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
#include <terminus/log/Level.hpp>

// C++ Standard Libraries
#include <chrono>
#include <memory>

namespace tmns::log {

class HandlerBase {

    public:

        using ptr_t = std::unique_ptr<HandlerBase>;

        // Time to use for logging
        using TIME_TP = std::chrono::system_clock::time_point;

        /**
         * Log a message to the respective handler destination
         */
        virtual void log( Level       lvl,
                          TIME_TP     log_time,
                          std::string filename,
                          std::string func,
                          int         line_no,
                          std::string message ) = 0;


}; // End of HandlerBase class

} // End of tmns::log namespace