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
 * @file    Label.cpp
 * @author  Marvin Smith
 * @date    3/22/2025
 */
#include <terminus/gui/widget/Label.hpp>

// Project Libraries
#include <terminus/log.hpp>

namespace tmns::gui {

/****************************/
/*      Get label size      */
/****************************/
math::Size2i Label::size_pixels() const {
    return m_image->size();
}

/********************************/
/*      Render the Image        */
/********************************/
bool Label::render( gui::Session&     session,
                    img::Frame_View&  image )
{
    std::stringstream sout;
    sout << "Label Info: " << m_image->to_log_string() << ", View Size: " << image.to_log_string();
    LOG_DEBUG( sout.str() );
    
    // Copy our label onto the frame image
    image.copy( *m_image, img::CopyPolicy::FLEXIBILE );

    return true;
}

/************************************************/
/*          Create Log-Friendly String          */
/************************************************/
std::string Label::to_log_string( size_t offset ) const
{
    std::stringstream sout;

    std::string gap( offset, ' ' );

    sout << gap << " - Label:" << std::endl;
    sout << gap << "     - Frame Information:" << std::endl;
    sout << m_image->to_log_string( offset + 6 );
    return sout.str();
}

/************************************/
/*      Construct from image        */
/************************************/
Label::ptr_t Label::from_image( const std::filesystem::path& image_path,
                                drv::Driver_Base::ptr_t      driver )
{
    // Load the image
    LOG_DEBUG( "Loading Image: " + image_path.native() );
    auto frame = driver->load_image( image_path );

    auto new_lbl = std::make_shared<Label>();

    new_lbl->m_image = frame;

    return new_lbl;
}

/************************************/
/*      Construct from text         */
/************************************/
Label::ptr_t Label::from_text( const std::string&      message,
                               drv::Driver_Base::ptr_t driver )
{
    auto frame = driver->rasterize_text( message );

    auto new_lbl = std::make_shared<Label>();

    new_lbl->m_image = frame;

    return new_lbl;
}

/**********************************************/
/*      Construct from existing frame         */
/**********************************************/
Label::ptr_t Label::from_frame( img::Frame::ptr_t frame )
{
    auto new_lbl = std::make_shared<Label>();

    new_lbl->m_image = frame;

    return new_lbl;
}

} // End of tmns::gui namespace