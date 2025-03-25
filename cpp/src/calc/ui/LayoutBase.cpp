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
#include <terminus/app/calc/ui/LayoutBase.hpp>

namespace tmns::calc::ui {

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

/****************************************/
/*      Get allocated bounding box      */
/****************************************/
std::vector<math::Rect2i> LayoutBase::allocate_bboxes() const
{
    // Get layout dimensions
    auto full_bbox = math::Rect2i( math::Vector2i( { 0, 0 } ),
                                   layout_size() );

    // Shrink from padding
    auto pad = padding();
    full_bbox.min() += math::Vector2i( { pad[0], pad[2] } );
    full_bbox.width()  -= pad[0] + pad[1];
    full_bbox.height() -= pad[2] + pad[3];

    // If a ratio is supplied, sum up the total ratio values. 
    double ratio_sum = 0;
    for( const auto& widget : m_widgets ){
        if( widget.layout_info.ratio ){
            ratio_sum += widget.layout_info.ratio.value();
        }
    }

    // Normalize

    

}

} // End of tmns::calc::ui namespace
