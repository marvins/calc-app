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
#include <terminus/calc/ui/WidgetLayout.hpp>

namespace tmns::calc::ui {

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
bool WidgetLayout::render( core::Session&  session,
                           img::FrameView& image )
{
    
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

} // End of tmns::calc::ui namespace