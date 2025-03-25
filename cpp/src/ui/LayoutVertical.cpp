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
 * @file    LayoutVertical.cpp
 * @author  Marvin Smith
 * @date    03/22/2025
 *
 * @details Vertical Layout API
 */
#include <terminus/app/calc/ui/LayoutVertical.hpp>

// Terminus Libraries
#include <terminus/app/calc/log/Logger.hpp>
#include <terminus/math/Rectangle.hpp>

namespace tmns::calc::ui {

/********************************************/
/*          Get access to widgets           */
/********************************************/
std::deque<WidgetLayoutItem>& LayoutVertical::widgets()
{
    return m_widgets;
}

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
void LayoutVertical::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget      = new_widget;
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::CENTER_HORIZONTAL );
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::TOP );

    // Add to layout
    m_widgets.push_back( new_layout_item );
}

/********************************************/
/*      Get the Vertical Stretch Policy     */
/********************************************/
StretchPolicy LayoutVertical::vertical_stretch_policy() const {
    return m_vertical_stretch_policy;
}

/********************************************/
/*      Set the Vertical Stretch Policy     */
/********************************************/
void LayoutVertical::set_vertical_stretch_policy( StretchPolicy policy ){
    m_vertical_stretch_policy = policy;
}

/****************************************/
/*          Show the Contents           */
/****************************************/
bool LayoutVertical::render( core::Session&  session,
                             img::FrameView& image )
{
    // @todo:  Keep track of "rendered" vs "full" view
    //         Add support for sub-views
    auto point_tl = math::Vector2i( { 0, 0 } );

    // Iterate over each element, rendering
    for( const auto& widget : m_widgets )
    {
        // Get widget info
        auto widget_size = widget.widget->size_pixels();
        LOG_DEBUG( "Widget Size: " + widget_size.to_string() );

        // Compute view for frame
        auto widget_bbox = math::Rect2i( point_tl,
                                         widget_size );
        
        // Crop a section of the input image to apply our rendering to
        // @todo:  Figure out how the alignment API fits here
        auto subview = image.subview( widget_bbox );

        widget.widget->render( session, subview );

        point_tl.y() += widget_size.height();
    }
    
    return false;
}


} // End of tmns::calc::ui namespace