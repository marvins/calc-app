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
    // Build view of the "active" frame to render
    img::Frame_View view( m_session.active_frame() );

    while( m_okay_to_run )
    {
        // Render the main window
        m_main_window->render( m_config,
                               m_session.driver(),
                               view );


    }

    return 0;
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