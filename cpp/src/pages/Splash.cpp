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
#include <tmns/app/calc/pages/Splash.hpp>

// Project Libraries
#include <tmns/app/calc/image/FrameView.hpp>
#include <tmns/app/calc/ui/Label.hpp>

namespace tmns::calc::page {

/**************************************/
/*          Show Splash Screen        */
/**************************************/
void Splash::show( core::Options& config,
                   core::Session& session )
{
    // Render the internal layout on top of the view
    LayoutVertical::render( session,
                            img::FrameView( session.active_frame() ) );

}

/************************************/
/*          Build Instance          */
/************************************/
Splash::ptr_t Splash::create( const core::Options& config,
                              core::Session&       session )
{
    // Build the new instance
    auto splash = std::make_shared<Splash>();
    
    // Set the dimensions to screen size
    splash->set_layout_dimensions( session.driver()->get_screen_dimensions() );
    
    // Load the icon first
    auto icon_label = ui::Label::from_image( config.setting<std::filesystem::path>("menu","splash_icon_path"),
                                             session.driver() );
    splash->append( icon_label );


    // Add a text label
    //auto text_label = ui::Label::from_text( "Terminus Converter",
    //                                        session.driver() );
    //splash->append( text_label );

    return splash;
}

} // End of tmns::calc::page namespace