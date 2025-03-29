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
size_t LayoutStack::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget = new_widget;

    // Add to layout
    m_widgets.push_back( new_layout_item );

    return (m_widgets.size() - 1);
}

/****************************************/
/*          Render the Frame            */
/****************************************/
bool LayoutStack::render( Session&         session,
                          img::Frame_View& image )
{

    if( m_widgets.size() <= 0 ){
        throw std::runtime_error( "LayoutStack instance has no widgets added." );
    }

    return m_widgets[m_current_frame].widget->render( session, image );
    
    return false;
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

} // End of tmns::gui namespace