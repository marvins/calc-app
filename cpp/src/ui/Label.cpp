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
#include <terminus/app/calc/ui/Label.hpp>

namespace tmns::calc::ui {

/****************************/
/*      Get label size      */
/****************************/
math::Size2i Label::size_pixels() const {
    return m_image->size();
}

/********************************/
/*      Render the Image        */
/********************************/
bool Label::render( core::Session&   session,
                    img::FrameView&  image )
{
    // Copy our label onto the frame image
    image.copy( *m_image, img::CopyPolicy::FLEXIBILE );

    return true;
}

/************************************/
/*      Construct from image        */
/************************************/
Label::ptr_t Label::from_image( const std::filesystem::path& image_path,
                                drv::Driver_Base::ptr_t      driver )
{
    // Load the image
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

auto new_lbl = std::make_shared<Label>();


return new_lbl;
}

} // End of tmns::calc::ui namespace