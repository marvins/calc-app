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
#include <terminus/app/calc/drivers/DriverRaylib.hpp>

// Project Libraries
#include <terminus/app/calc/log/Logger.hpp>

// OpenCV Libraries
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

namespace tmns::calc::drv {

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
void Driver_Raylib::finalize()
{
    CloseWindow();  
}

/********************************************************/
/*          Print the current frame to the screen       */
/********************************************************/
void Driver_Raylib::show( img::Frame& image )
{

    LOG_DEBUG( image.to_log_string() );

    // Create temporary opencv mat
    /*
    std::cout << "AAAAAAA" << std::endl;
    cv::Mat temp_img( image.rows(), image.cols(), CV_8UC4, &image.image_ref()[0] );
    cv::Mat temp_img2;
    cv::cvtColor( temp_img, temp_img2, cv::COLOR_RGBA2BGR );
    cv::imshow( "Hello World", temp_img2 );
    cv::waitKey(0);
    std::cout << "BBBBBBBB" << std::endl;
    */

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
    DrawText("this IS a texture loaded from an image!", 50, 50, 10, GRAY);
    EndDrawing();
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
                                img.cols * img.rows * img.channels() );

    // build new frame instance
    auto frame = std::make_shared<img::Frame>( image_span, 
                                               img::Dimensions( img.cols, 
                                                                img.rows,
                                                                img.channels() ) );

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
    auto driver = std::make_shared<Driver_Raylib>();

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
        m_window_cols = config.setting<int>( "display", "screen_width" );
        m_window_rows = config.setting<int>( "display", "screen_height" );
    }

    // Currently not implemented
    else {
        throw std::runtime_error( "Unable to get display settings at this time.");
    }

    InitWindow( m_window_cols,
                m_window_rows,
                "Terminus Converter Application" );
}

} // End of tmns::calc::drv namespace
