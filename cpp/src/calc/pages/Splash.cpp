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
#include <terminus/image.hpp>
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
    std::chrono::milliseconds sleep_time_ms( config.check_and_get_setting<size_t>("menu","splash_time_sleep_ms") );

    img::Frame_View frame_view( session.active_frame() );
    
    // Render the internal layout on top of the view
    LayoutVertical::render( session,
                            frame_view );
    
    // Render Screen
    auto start_time = std::chrono::system_clock::now();

    while( std::chrono::duration_cast<std::chrono::seconds>( std::chrono::system_clock::now() - start_time ) < std::chrono::seconds(5) )
    {
        session.show();
    }

}

/************************************/
/*          Build Instance          */
/************************************/
Splash::ptr_t Splash::create( const core::Options& config,
                              gui::Session&        session )
{
    // Build the new instance
    auto splash = std::make_shared<Splash>();
    splash->set_padding( 10, 10, 10, 10 );
    splash->set_padding_color( img::PIXEL_GREY() );
    
    // Set the dimensions to screen size
    splash->set_layout_size( session.driver().get_screen_dimensions().size() );
    
    // Load the icon first
    auto icon_label = gui::Label::from_image( config.check_and_get_setting<std::filesystem::path>("menu","splash_icon_path"),
                                              session.driver() );
    splash->append( icon_label );


    // Add a text label
    auto text_label = gui::Label::from_text( "Terminus Geospatial Toolbox",
                                             session.driver() );
    splash->append( text_label );


    // Add Build Information
    {
        std::stringstream sout;
        sout << "Version: " << VERSION() << "\nBuild Date: " << BUILD_DATE();

        auto version_label = gui::Label::from_text( sout.str(),
                                                    session.driver() );

        std::set<gui::AlignmentPolicy> alignment( { gui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                    gui::AlignmentPolicy::BOTTOM } );
        splash->append( version_label, alignment, std::optional<double>() );
    }


    return splash;
}

} // End of tmns::calc::page namespace