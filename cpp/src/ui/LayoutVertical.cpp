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
    // Iterate over each element, rendering
    
    return false;
}


} // End of tmns::calc::ui namespace