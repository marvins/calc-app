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
 * @file    Splash.cpp
 * @author  Marvin Smith
 * @date    3/22/2025
 */
#include <terminus/calc/pages/Splash.hpp>

// Project Libraries
#include <terminus/image/FrameView.hpp>
#include <terminus/gui/widget/Label.hpp>
#include <terminus/version.hpp>

// C++ Standard Libraries
#include <thread>

namespace tmns::calc::page {

/**************************************/
/*          Show Splash Screen        */
/**************************************/
void Splash::show( core::Options& config,
                   gui::Session&  session )
{
    img::FrameView frame_view( session.active_frame() );
    
    // Render the internal layout on top of the view
    LayoutVertical::render( session,
                            frame_view );
    
    // Render Screen
    auto start_time = std::chrono::system_clock::now();

    while( std::chrono::duration_cast<std::chrono::seconds>( std::chrono::system_clock::now() - start_time ) < std::chrono::seconds(5) )
    {
        session.show();
        std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    }
    

    // Sleep for a bit
    std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );

}

/************************************/
/*          Build Instance          */
/************************************/
Splash::ptr_t Splash::create( const core::Options& config,
                              gui::Session&        session )
{
    // Build the new instance
    auto splash = std::make_shared<Splash>();
    splash->set_padding( 100, 100, 100, 100 );
    
    // Set the dimensions to screen size
    splash->set_layout_size( session.driver()->get_screen_dimensions().size() );
    
    // Load the icon first
    auto icon_label = gui::Label::from_image( config.setting<std::filesystem::path>("menu","splash_icon_path"),
                                              session.driver() );
    splash->append( icon_label );


    // Add a text label
    auto text_label = gui::Label::from_text( "Terminus Converter",
                                             session.driver() );
    splash->append( text_label );


    // Add Build Information
    {
        std::stringstream sout;
        sout << "Version: " << VERSION() << ", Build Date: " << BUILD_DATE();

        auto version_label = gui::Label::from_text( sout.str(),
                                                    session.driver() );

        std::set<gui::AlignmentPolicy> alignment( { gui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                    gui::AlignmentPolicy::BOTTOM } );
        splash->append( version_label, alignment, std::optional<double>() );
    }


    return splash;
}

} // End of tmns::calc::page namespace