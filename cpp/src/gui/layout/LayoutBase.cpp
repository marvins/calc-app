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
 * @file    LayoutBase.cpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Base Layout API
 */
#include <terminus/gui/layout/LayoutBase.hpp>

// Terminus Libraries
#include <terminus/log.hpp>

namespace tmns::gui {

/****************************************/
/*          Get Layout Dimensions       */
/****************************************/
math::Size2i LayoutBase::layout_size() const {
    return m_layout_size;
}

/****************************************/
/*          Set Layout Dimensions       */
/****************************************/
void LayoutBase::set_layout_size( math::Size2i layout_size ){
    m_layout_size = layout_size;
}

/************************************/
/*          Get the Padding         */
/************************************/
math::Vector4i LayoutBase::padding() const
{
    return m_padding;
}

/************************************/
/*          Set the Padding         */
/************************************/
void LayoutBase::set_padding( math::Vector4i padding ){
    m_padding = padding;
}

/************************************/
/*          Set the Padding         */
/************************************/
void LayoutBase::set_padding( int left, int right, int top, int bottom ){
    set_padding( math::Vector4i( { left, right, top, bottom } ) );
}

/********************************************/
/*          Get access to widgets           */
/********************************************/
std::vector<WidgetLayoutItem>& LayoutBase::widgets()
{
    return m_widgets;
}

/************************************************************/
/*          Align the Widget within the Bounding Box        */
/************************************************************/
math::Rect2i LayoutBase::align_widget( math::Rect2i              bbox_allocated,
                                       math::Size2i              widget_size,
                                       std::set<AlignmentPolicy> alignment )
{
    math::Rect2i output;

    //////////////////////////////////////////////
    // First we resolve the width
    //////////////////////////////////////////////

    // - If the width of the widget is greater than the bbox, then we crop
    if( widget_size.width() >= bbox_allocated.width() ){
        output.min().x() = bbox_allocated.min().x();
        output.width()   = bbox_allocated.width();
    }

    // If left, then do nothing
    if( alignment.count( AlignmentPolicy::LEFT ) > 0 ){
        output.min().x() = bbox_allocated.min().x();
        output.width()   = widget_size.width();
    }

    // If Center, align appropriately
    else if( alignment.count( AlignmentPolicy::CENTER_HORIZONTAL ) > 0 ){
        int offset = bbox_allocated.width() / 2 - widget_size.width() / 2;
        output.min().x() = bbox_allocated.min().x() + offset;
        output.width()   = widget_size.width();
    }

    // If Right, work with the size
    else if( alignment.count( AlignmentPolicy::RIGHT ) > 0 ){
        int offset = bbox_allocated.width() - widget_size.width() - 1;
        output.min().x() = bbox_allocated.min().x() + offset;
        output.width()   = widget_size.width();
    }

    // Otherwise, error
    else {
        throw std::runtime_error( "No horizontal policy included.  This is a bug on the layout provider's part.");
    }

    //////////////////////////////////////////////
    // Finally we resolve the height
    //////////////////////////////////////////////

    // - If the width of the widget is greater than the bbox, then we crop
    if( widget_size.height() >= bbox_allocated.height() ){
        output.min().y() = bbox_allocated.min().y();
        output.height() = widget_size.height();
    }

    // If top, then do nothing
    if( alignment.count( AlignmentPolicy::TOP ) > 0 ){
        output.min().y() = bbox_allocated.min().y();
        output.height()  = widget_size.height();
    }

    // If Center, align appropriately
    else if( alignment.count( AlignmentPolicy::CENTER_VERTICAL ) > 0 ){
        int offset = bbox_allocated.height() / 2 - widget_size.height() / 2;
        output.min().y() = bbox_allocated.min().y() + offset;
        output.height()  = widget_size.height();
    }

    // If bottom, work with the size
    else if( alignment.count( AlignmentPolicy::BOTTOM ) > 0 ){
        int offset = bbox_allocated.height() - widget_size.height() - 1;
        output.min().y() = bbox_allocated.min().y() + offset;
        output.height()  = widget_size.height();
    }

    // Otherwise, error
    else {
        throw std::runtime_error( "No horizontal policy included.  This is a bug on the layout provider's part.");
    }

    {
        std::stringstream sout;
        sout << "Widget Alignment:" << std::endl;
        sout << "  - Allocated: " << bbox_allocated.to_string() << std::endl;
        sout << "  - Widget Size: " << widget_size.to_string() << std::endl;
        sout << "  - Output: " << output.to_string() << std::endl;
        LOG_DEBUG( sout.str() );
    }

    return output;
}

} // End of tmns::gui namespace
