


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

/********************************/
/*          Destructor          */
/********************************/
Session::~Session()
{
    finalize();
}

/****************************************/
/*          Get Copy of Driver          */
/****************************************/
drv::Driver_Base& Session::driver() const{
    return (*m_driver);
}

/****************************************/
/*          Get Frame Instance          */
/****************************************/
img::Frame& Session::active_frame(){
    return m_active_frame;
}

/****************************************/
/*          Get Resource-Manager        */
/****************************************/
Resource_Manager& Session::resource_manager()
{
    return (*m_resource_manager);
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
    int ecode = 0;

    // Clean up the driver
    if( m_driver ){
        ecode |= m_driver->finalize();
    }
    m_driver.reset();

    // Clean up the resource-manager
    m_resource_manager->finalize();

    // Clean up active frame
    m_active_frame.clear();

    return ecode;
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
Session::ptr_t Session::create( core::Options config )
{
    // Grab some relevant config parameters
    auto resource_root = config.check_and_get_setting<std::filesystem::path>( "resources", "root_dir" );

    // Build the driver depending on how we compiled the app
    drv::Driver_Base::ptr_t driver;

#if RENDER_DRIVER == 2
    driver = drv::Driver_Allegro::create( config );
#elif RENDER_DRIVER == 3
    driver = drv::Driver_Raylib::create( config );
#else
    #error Not supported yet
#endif

    // Construct new resource manager
    auto resource_manager = Resource_Manager::create( resource_root, (*driver) );

    // Build the new session
    return Session::ptr_t( new Session( std::move( driver ), 
                                        std::move( resource_manager ) ) );
}

/************************************************/
/*          Parameterized Constructor           */
/************************************************/
Session::Session( drv::Driver_Base::ptr_t driver,
                  Resource_Manager::ptr_t resource_manager )
    : m_driver { std::move( driver ) },
      m_resource_manager { std::move( resource_manager ) }
{
    // Set the default frame size
    m_active_frame.resize( m_driver->get_screen_dimensions(), 255 );
}

} // End of tmns::gui namespace