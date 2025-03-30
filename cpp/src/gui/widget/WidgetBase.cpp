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
 * @file    WidgetBase.cpp
 * @author  Marvin Smith
 * @date    03/29/2025
 *
 * @details Base Widget API
 */
#include <terminus/gui/widget/WidgetBase.hpp>

namespace tmns::gui {

/****************************************/
/*          Set a Border Color          */
/****************************************/
void WidgetBase::set_border( math::Vector4u color ){
    m_border = color;
}

/****************************************/
/*          Get a Logging Tag           */
/****************************************/
std::string WidgetBase::log_tag() const {
    return m_log_tag;
}

/****************************************/
/*          Set a Logging Tag           */
/****************************************/
void WidgetBase::set_log_tag( std::string log_tag ){
    m_log_tag = log_tag;
}

/****************************************/
/*          Render the border           */
/****************************************/
bool WidgetBase::render_border( [[maybe_unused]] Session&  session,
                                img::Frame_View&           image )
{
    if( !m_border.has_value() ){
        return false;
    }

    // Set pixels around edge
    for( size_t r = 0; r < static_cast<size_t>(image.rows()); r++ ){
        image.set_pixel( 0, r, m_border.value() );
        image.set_pixel( static_cast<size_t>(image.cols())-1, r, m_border.value() );
    }
    for( size_t c = 1; c < static_cast<size_t>(image.cols()) - 1; c++ ){
        image.set_pixel( c, 0, m_border.value() );
        image.set_pixel( c, static_cast<size_t>(image.rows())-1, m_border.value() );
    }

    return true;
}

} // End of tmns::gui namespace