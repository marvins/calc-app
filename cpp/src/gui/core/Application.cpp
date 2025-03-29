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
 * @file    Application.hpp
 * @author  Marvin Smith
 * @date    3/27/2025
 */
#include <terminus/gui/core/Application.hpp>

// Project Libraries
#include <terminus/image/Frame_View.hpp>

namespace tmns::gui {

/****************************************/
/*          Run the Application         */
/****************************************/
int Application::run()
{
    
    while( m_okay_to_run )
    {
        // Check if we should close
        if( !m_session.okay_to_run() ){
            m_okay_to_run = false;
            continue;
        }

        // Update the main window data
        m_main_window->update( m_config, m_session );

        // Build view of the "active" frame to render
        img::Frame_View view( m_session.active_frame() );

        // Render the main window
        m_main_window->render( m_session, view );
        
        // Show the session
        m_session.show();
    }

    // Finalize session
    return m_session.finalize();
}

/********************************/
/*          Constructor         */
/********************************/
Application::Application( core::Options&       config,
                          gui::Session&        session,
                          I_Main_Window::ptr_t main_window )
    : m_config { config },
      m_session { session },
      m_main_window { main_window }
{}

/************************************************/
/*          Create Application Instance         */
/************************************************/
Application::ptr_t Application::create( core::Options&       config,
                                        gui::Session&        session,
                                        I_Main_Window::ptr_t main_window )
{
    // Create new instance
    auto inst = std::shared_ptr<Application>( new Application( config, session, main_window ) );
    return inst;
}

} // End of tmns::gui namespace