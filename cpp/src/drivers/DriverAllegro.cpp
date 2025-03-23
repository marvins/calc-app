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
 * @file    Allegro.cpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Vertical Layout API
 */
#include <tmns/app/calc/drivers/DriverAllegro.hpp>

// OpenCV Libraries
#include <opencv4/opencv2/imgcodecs.hpp>

namespace tmns::calc::drv {

/****************************************/
/*          Initialize Driver           */
/****************************************/
bool Driver_Allegro::initialize( core::Options& config )
{
    // Initialization provided courtesy of Allegro docs
    //    https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace-%E2%80%93-Basic-game-structure
    
    al_init();

    al_install_keyboard();

    m_timer = al_create_timer(1.0 / 30.0);

    m_queue = al_create_event_queue();

    m_display = al_create_display(320, 200);

    m_font = al_create_builtin_font();

    // Configure handlers
    al_register_event_source( m_queue, al_get_keyboard_event_source() );
    al_register_event_source( m_queue, al_get_display_event_source(m_display) );
    al_register_event_source( m_queue, al_get_timer_event_source(m_timer) );

    return true;
}

/****************************************/
/*            Finalize Driver           */
/****************************************/
void Driver_Allegro::finalize()
{
    al_destroy_font( m_font );
    al_destroy_display( m_display );
    al_destroy_timer( m_timer );
    al_destroy_event_queue( m_queue );    
}

/************************************/
/*          Load the Image          */
/************************************/
ui::Frame::ptr_t Driver_Allegro::load_image( const std::filesystem::path& pathname )
{
    auto img = cv::imread( pathname.native(), cv::IMREAD_COLOR );

    // build new frame instance
    auto frame = std::make_shared<ui::Frame>( img.cols, img.rows, img.channels() );

    return frame;
}

/************************************************/
/*          Create new driver instance          */
/************************************************/
Driver_Allegro::ptr_t Driver_Allegro::create( core::Options& config )
{
    // Create new driver
    auto driver = std::make_shared<Driver_Allegro>();

    driver->initialize( config );
    return driver;
}

} // End of tmns::calc::drv namespace
