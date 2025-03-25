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
#include <terminus/app/calc/log/Logger.hpp>

// C++ Standard Libraries
#include <memory>

namespace tmns::calc::log {

static std::unique_ptr<Logger> g_logger;

/********************************************/
/*          Get Logger Instance             */
/********************************************/
Logger& Logger::instance()
{
    if( !g_logger ){
        g_logger = std::unique_ptr<Logger>( new Logger() );
    }

    return *g_logger;
}

/************************************/
/*          Finalize Logger         */
/************************************/
void Logger::finalize(){
    g_logger.reset();
}

/************************************/
/*          Add New Handler         */
/************************************/
void Logger::add_handler( HandlerBase::ptr_t logger )
{
    auto& inst = Logger::instance();
    std::unique_lock<std::mutex> lck( inst.m_mtx );
    inst.m_handlers.push_back( std::move( logger ) );
}

/********************************/
/*          Log Message         */
/********************************/
void Logger::log( Level                lvl,
                  HandlerBase::TIME_TP log_time,
                  std::string          filename,
                  std::string          func,
                  int                  line_no,
                  std::string          message )
{
    auto& inst = Logger::instance();
    std::unique_lock<std::mutex> lck( inst.m_mtx );

    for( auto& handler : inst.m_handlers ){
        handler->log( lvl, log_time, filename, func, line_no, message );
    }
}

} // End of tmns::calc::utils namespace