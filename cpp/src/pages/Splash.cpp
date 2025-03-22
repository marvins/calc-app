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
#include <tmns/app/calc/ui/Label.hpp>

namespace tmns::calc::page {

/************************************/
/*          Build Instance          */
/************************************/
Splash::ptr_t Splash::create( const core::Options& config,
                              core::Session&       session )
{
    auto splash = std::make_shared<Splash>();
    
    // Load the icon first
    auto icon_label = ui::Label::from_image( config.get_path("menu","splash_icon") );
    splash->append( icon_label );

    // Add a text label
    auto text_label = ui::Label::from_text( "Terminus Converter" );
    splash->append( text_label );

    return splash;
}

} // End of tmns::calc::page namespace