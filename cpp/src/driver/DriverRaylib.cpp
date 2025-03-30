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
 * @file    DriverRaylib.cpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Raylib Graphics API Wrapper Source
 */
#include <terminus/driver/DriverRaylib.hpp>

// Project Libraries
#include <terminus/driver/Raylib_Utilities.hpp>
#include <terminus/log/Logger.hpp>

// OpenCV Libraries
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

namespace tmns::drv {

/****************************************/
/*          Initialize Driver           */
/****************************************/
bool Driver_Raylib::initialize( core::Options& config )
{
    // Initialization provided courtesy of Raylib docs
    //    https://www.raylib.com/examples/textures/loader.html?name=textures_to_image
    
    // Setup OpenGL Context
    configure_display( config );

    SetTargetFPS(30);

    return true;
}

/****************************************/
/*            Finalize Driver           */
/****************************************/
int Driver_Raylib::finalize()
{
    CloseWindow();  

    return 0;
}

/********************************************/
/*          Check if we should exit         */
/********************************************/
bool Driver_Raylib::okay_to_run()
{
    bool okay_to_run = true;

    // Check if raylib encountered any abort conditions
    okay_to_run &= !WindowShouldClose();

    return okay_to_run;
}

/********************************************************/
/*          Print the current frame to the screen       */
/********************************************************/
void Driver_Raylib::show( img::Frame& image )
{

    // Create raylib image
    Image img = {
        .data = &image.image_ref()[0],
        .width = image.size().width(),
        .height = image.size().height(),
        .mipmaps = 1,
        .format = static_cast<int>(PIXELFORMAT_UNCOMPRESSED_R8G8B8A8) };

    // Generate Texture
    Texture2D texture = LoadTextureFromImage(img);

    // Put texture onto frame 
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();

    UnloadTexture( texture );
}

/******************************************/
/*        Get the screen dimensions       */
/******************************************/
img::Dimensions Driver_Raylib::get_screen_dimensions() const
{
    return img::Dimensions( m_window_cols, m_window_rows, 4 );
}

/************************************/
/*          Load the Image          */
/************************************/
img::Frame::ptr_t Driver_Raylib::load_image( const std::filesystem::path& pathname )
{
    auto img = cv::imread( pathname.native(), cv::IMREAD_COLOR );

    // Make sure the image is 4 channels
    cv::cvtColor( img, img, cv::COLOR_BGR2RGBA );
    //cv::imshow( "PRE", img );
    //cv::waitKey(0);
    
    std::span<char> image_span( reinterpret_cast<char*>(img.data),
                                static_cast<size_t>(img.cols) * static_cast<size_t>(img.rows) * static_cast<size_t>(img.channels()) );

    // build new frame instance
    auto frame = std::make_shared<img::Frame>( image_span, 
                                               img::Dimensions( static_cast<size_t>(img.cols), 
                                                                static_cast<size_t>(img.rows),
                                                                static_cast<size_t>(img.channels()) ) );

    return frame;
}

/************************************/
/*          Rasterize Text          */
/************************************/
img::Frame::ptr_t Driver_Raylib::rasterize_text( const std::string& message )
{
    // If the message is empty, then return empty frame
    if( message.empty() ){
        LOG_WARNING( "Message is empty" );
        return std::make_shared<img::Frame>();
    }

    // Create image from text
    auto text_image = ImageText( message.c_str(), 16, DARKBLUE );

    size_t nchannels = raylib_format_to_channels(static_cast<PixelFormat>(text_image.format));
    
    std::span<char> image_span( reinterpret_cast<char*>(text_image.data),
                                static_cast<size_t>(text_image.width) * static_cast<size_t>(text_image.height) * nchannels );
                                    
    // build new frame instance
    auto frame = std::make_shared<img::Frame>( image_span, 
                                               img::Dimensions( static_cast<size_t>(text_image.width), 
                                                                static_cast<size_t>(text_image.height),
                                                                nchannels ) );

    // Delete image
    UnloadImage( text_image );

    LOG_DEBUG( "Text Image Info: " + frame->to_log_string() );

    return frame;
}

/********************************************/
/*          Print Log-Friendly String       */
/********************************************/
std::string Driver_Raylib::to_log_string( size_t offset ) const
{
    std::string gap( offset, ' ' );
    std::stringstream sout;
    sout << gap << "Driver_Raylib:" << std::endl;
    
    return sout.str();
}

/************************************************/
/*          Create new driver instance          */
/************************************************/
Driver_Raylib::ptr_t Driver_Raylib::create( core::Options& config )
{
    // Create new driver
    auto driver = Driver_Raylib::ptr_t( new Driver_Raylib() );

    driver->initialize( config );
    return driver;
}

/************************************************/
/*          Configure Display Settings          */
/************************************************/
void Driver_Raylib::configure_display( core::Options& config )
{
    if( config.setting<bool>( "display", "override_screen_size" ) ){

        // Get size parameters
        m_window_cols = config.check_and_get_setting<size_t>( "display", "screen_width" );
        m_window_rows = config.check_and_get_setting<size_t>( "display", "screen_height" );
    }

    // Currently not implemented
    else {
        throw std::runtime_error( "Unable to get display settings at this time.");
    }

    InitWindow( static_cast<int>(m_window_cols),
                static_cast<int>(m_window_rows),
                "Terminus Converter Application" );
}

} // End of tmns::drv namespace
