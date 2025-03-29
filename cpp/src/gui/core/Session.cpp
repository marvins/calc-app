


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
 * @file    Session.cpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#include <terminus/gui/core/Session.hpp>

// Project Libraries
#if RENDER_DRIVER == 2
#include <terminus/driver/DriverAllegro.hpp>
#elif RENDER_DRIVER == 3
#include <terminus/driver/DriverRaylib.hpp>
#endif

// C++ Standard Libraries
#include <iostream>
#include <sstream>
#include <thread>

namespace tmns::gui {

/****************************************/
/*          Get Copy of Driver          */
/****************************************/
drv::Driver_Base::ptr_t Session::driver() const{
    return m_driver;
}

/****************************************/
/*          Get Frame Instance          */
/****************************************/
img::Frame& Session::active_frame(){
    return m_active_frame;
}

/********************************************/
/*          Check if we should exit         */
/********************************************/
bool Session::okay_to_run(){
    return m_driver->okay_to_run();
}

/****************************************/
/*      Close up session and exit       */
/****************************************/
int Session::finalize()
{
    return m_driver->finalize();
}

/************************************************/
/*          Sleep for Designated Amount         */
/************************************************/
void Session::sleep_for( std::chrono::milliseconds sleep_time )
{
    std::this_thread::sleep_for( sleep_time );
}

/********************************************************/
/*          Print the current frame to the screen       */
/********************************************************/
void Session::show()
{
    m_driver->show( m_active_frame );
}

/************************************************/
/*          Print Log-Friendly String           */
/************************************************/
std::string Session::to_log_string( size_t offset ) const
{
    std::string gap( offset, ' ' );

    std::stringstream sout;
    sout << gap << "Session:" << std::endl;
    sout << gap << "  - Active Frame:" << std::endl;
    sout << m_active_frame.to_log_string( offset + 4 ) << std::endl;
    return sout.str();
}

/****************************************************/
/*          Create a Session API Instance           */
/****************************************************/
Session Session::create( core::Options config )
{
    Session new_session;
    
#if RENDER_DRIVER == 2
    #warning "Building desktop variant"
    new_session.m_driver = drv::Driver_Allegro::create( config );
#elif RENDER_DRIVER == 3
    #warning "Building Raylib Variant"
    new_session.m_driver = drv::Driver_Raylib::create( config );
#else
    #error Not supported yet
#endif

    // Set the default frame size
    new_session.m_active_frame.resize( new_session.driver()->get_screen_dimensions(),
                                       255 );
    
    return new_session;
}

} // End of tmns::gui namespace