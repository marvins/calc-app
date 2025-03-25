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
 * @file    Logger.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Logging Interface
 */
#pragma once

// Project Libraries
#include <terminus/log/HandlerBase.hpp>
#include <terminus/log/Level.hpp>

// C++ Libraries
#include <chrono>
#include <iostream>
#include <mutex>
#include <vector>

#define LOG_DEBUG( message ) tmns::log::Logger::log( tmns::log::Level::DEBUG, \
                                                     std::chrono::system_clock::now(), \
                                                     __FILE__, \
                                                     __func__, \
                                                     __LINE__, \
                                                     message )

namespace tmns::log {

/**
 * @class Logger
 */
class Logger {

    public:

        /**
         * Initialize logger and return instance
         */
        static Logger& instance();

        /**
         * Destroy logger
         */
        static void finalize();

        /**
         * Add Handler to Logger
         */
        static void add_handler( HandlerBase::ptr_t handler );
    
        /**
         * Get the logger interface at the specified level
         */
        static void log( Level                lvl,
                         HandlerBase::TIME_TP log_time,
                         std::string          filename,
                         std::string          func,
                         int                  line_no,
                         std::string          message );

    private:

        /**
         * Constructor
         */
        Logger() = default;

        /**
         * No Copy Constructor
         */
        Logger( const Logger& ) = delete;

        /**
         * No Assignment Operator
         */
        void operator = ( const Logger& ) = delete;

        /// List of log handlers
        std::vector<HandlerBase::ptr_t> m_handlers;

        /// Log Handler Access Mutex
        std::mutex m_mtx;

}; // End of Logger Class


} // End of tmns::log namespace