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
 * @file    WidgetLayout.cpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Simple widget for assigning Layouts to.
 */
#include <terminus/gui/widget/WidgetLayout.hpp>

// Terminus Libraries
#include <terminus/log.hpp>

namespace tmns::gui {

/****************************************/
/*          Get the widget size         */
/****************************************/
math::Size2i WidgetLayout::size_pixels() const
{
    return m_layout->layout_size();
}

/****************************************/
/*          Get the layout info         */
/****************************************/
LayoutBase::ptr_t WidgetLayout::layout()
{
    return m_layout;
}

/************************************/
/*          Render Widget           */
/************************************/
bool WidgetLayout::render( gui::Session&    session,
                           img::Frame_View& image )
{
    // Render the border
    {
        std::stringstream sout;
        sout << "Rendering Widget.\n";
        if( !log_tag().empty() ){
            sout << " - " << log_tag() << std::endl;
        }
        sout << " - Widget size: " << size_pixels().to_string() << std::endl;
        sout << " - Image: " << image.to_log_string() << std::endl;
        LOG_TRACE( sout.str() );
    }
    render_border( session, image );

    // Render the internal layout on top of the image
    m_layout->render( session, image );
    
    return true;
}

/************************************************/
/*          Create Log-Friendly String          */
/************************************************/
std::string WidgetLayout::to_log_string( size_t offset ) const
{
    std::stringstream sout;

    std::string gap( offset, ' ' );

    sout << gap << " - WidgetLayout:" << std::endl;
    sout << gap << "     - Tag: [" << log_tag() << "]" << std::endl;
    sout << gap << "     - Layout Information:" << std::endl;
    sout << m_layout->to_log_string( offset + 6 );
    return sout.str();
}

/*****************************************/
/*          Create from Layout           */
/*****************************************/
WidgetLayout::ptr_t WidgetLayout::from_layout( LayoutBase::ptr_t layout )
{
    return std::shared_ptr<WidgetLayout>( new WidgetLayout( layout ) );
}

/********************************/
/*          Constructor         */
/********************************/
WidgetLayout::WidgetLayout( LayoutBase::ptr_t layout )
    : m_layout { layout }{}

} // End of tmns::gui namespace