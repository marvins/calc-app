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
 * @file    LayoutStack.cpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Stack Layout API
 */
#include <terminus/gui/layout/LayoutStack.hpp>

// Terminus Libraries
#include <terminus/log/Logger.hpp>


namespace tmns::gui {

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
int LayoutStack::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget = new_widget;

    // Add to layout
    m_widgets.push_back( new_layout_item );

    // If the first item, initialize the current-frame index
    if( !m_current_frame.has_value() ){
        m_current_frame = 0;
    } else {
        m_current_frame.value()++;
    }

    return (m_widgets.size() - 1);
}

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
int LayoutStack::append( WidgetBase::ptr_t         new_widget,
                         std::set<AlignmentPolicy> alignment,
                         std::optional<double>     ratio ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.layout_info.alignment = alignment;
    new_layout_item.layout_info.ratio     = ratio;
    new_layout_item.widget = new_widget;

    // Add to layout
    m_widgets.push_back( new_layout_item );

    // If the first item, initialize the current-frame index
    if( !m_current_frame.has_value() ){
        m_current_frame = 0;
    } else {
        m_current_frame.value()++;
    }

    return (m_widgets.size() - 1);
}

/****************************************/
/*          Render the Frame            */
/****************************************/
bool LayoutStack::render( Session&         session,
                          img::Frame_View& image )
{
    // First render the padding
    render_padding( session, image );

    if( m_widgets.size() <= 0 ){
        throw std::runtime_error( "LayoutStack instance has no widgets added." );
    }

    // If the current frame is invalid, say so
    if( !m_current_frame.has_value() ){
        throw std::runtime_error( "No widgets inside layout" );
    }

    {
        std::stringstream sout;
        sout << "Rendering Widget: " << m_current_frame.value();
        LOG_DEBUG( sout.str() );
        sout.clear();
        sout.str("");
        sout << "Widget Info: " << m_widgets[m_current_frame.value()].widget->to_log_string();
        LOG_DEBUG(sout.str() );
    }
    return m_widgets[m_current_frame.value()].widget->render( session, image );
    
    return true;
}

/****************************************/
/*      Get allocated bounding box      */
/****************************************/
std::vector<math::Rect2i> LayoutStack::allocate_bboxes() const
{
    std::vector<math::Rect2i> bboxes;
    
    for( const auto& widget : m_widgets ){
        bboxes.push_back( math::Rect2i( math::Point2i( { 0, 0 } ),
                                        widget.widget->size_pixels() ) );
    }
    return bboxes;
}

/************************************************/
/*          Create Log-Friendly String          */
/************************************************/
std::string LayoutStack::to_log_string( size_t offset ) const
{
    std::stringstream sout;

    std::string gap( offset, ' ' );

    sout << gap << " - LayoutStack:" << std::endl;
    sout << gap << "    - Size: " << layout_size().to_string() << std::endl;
    sout << gap << "    - Padding: " << padding().to_log_string() << std::endl;
    sout << gap << "    - Number Widgets: " << m_widgets.size() << std::endl;
    return sout.str();
}

} // End of tmns::gui namespace