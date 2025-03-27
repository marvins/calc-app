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
 * @file    LayoutHorizontal.cpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Vertical Layout API
 */
#include <terminus/gui/layout/LayoutHorizontal.hpp>

// Terminus Libraries
#include <terminus/log/Logger.hpp>
#include <terminus/math/Rectangle.hpp>

namespace tmns::gui {

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
void LayoutHorizontal::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget      = new_widget;
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::LEFT );
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::CENTER_VERTICAL );

    // Add to layout
    m_widgets.push_back( new_layout_item );
}

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
void LayoutHorizontal::append( WidgetBase::ptr_t          new_widget,
                               std::set<AlignmentPolicy>  alignment,
                               std::optional<double>      ratio ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget                = new_widget;
    new_layout_item.layout_info.alignment = alignment;
    new_layout_item.layout_info.ratio     = ratio;

    // Add to layout
    m_widgets.push_back( new_layout_item );
}

/********************************************/
/*      Get the Vertical Stretch Policy     */
/********************************************/
StretchPolicy LayoutHorizontal::horizontal_stretch_policy() const {
    return m_horizontal_stretch_policy;
}

/********************************************/
/*      Set the Vertical Stretch Policy     */
/********************************************/
void LayoutHorizontal::set_horizontal_stretch_policy( StretchPolicy policy ){
    m_horizontal_stretch_policy = policy;
}

/****************************************/
/*          Show the Contents           */
/****************************************/
bool LayoutHorizontal::render( gui::Session&  session,
                              img::FrameView& image )
{
    // @todo:  Keep track of "rendered" vs "full" view
    //         Add support for sub-views
    //         Add support for padding
    auto point_tl = math::Vector2i( { 0, 0 } );

    // Assign bounding boxes for all widgets
    auto widget_bboxes = allocate_bboxes();

    // Iterate over each element, rendering
    for( size_t idx = 0; idx < m_widgets.size(); idx++ )
    {
        // Get actual widget size (internally reported)
        auto widget_size = m_widgets[idx].widget->size_pixels();

        // Get size allocated for widget per this layout
        auto widget_bbox_allocated = widget_bboxes[idx];

        // Align the widget within the bounding box
        auto bbox_aligned = align_widget( widget_bbox_allocated,
                                          m_widgets[idx].widget->size_pixels(),
                                          m_widgets[idx].layout_info.alignment );
        
        {
            std::stringstream sout;
            sout << "Widget: " << idx << " bbox: " << bbox_aligned.to_string();
            LOG_DEBUG(sout.str());
        }

        // Crop a section of the input image to apply our rendering to
        // @todo:  Figure out how the alignment API fits here
        auto subview = image.subview( bbox_aligned );

        m_widgets[idx].widget->render( session, subview );

        point_tl.x() += widget_size.width();
    }
    
    return false;
}

/****************************************/
/*      Get allocated bounding box      */
/****************************************/
std::vector<math::Rect2i> LayoutHorizontal::allocate_bboxes() const
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
    double widgets_without_ratios = 0;
    for( const auto& widget : m_widgets ){
        if( widget.layout_info.ratio ){
            ratio_sum += widget.layout_info.ratio.value();
        } else {
            widgets_without_ratios += 1;
        }
    }

    // Since sum won't equal one, create multiplier
    double multiplier = 1/ratio_sum;

    // Non-ratio'd widgets get leftover
    double non_ratio_weight = (1 - std::min( ratio_sum, 1. )) / widgets_without_ratios;

    // Assign weights to all widgets
    std::vector<double> weights;
    for( const auto& widget : m_widgets ){
        
        // If widget has ratio
        if( widget.layout_info.ratio ){
            weights.push_back( widget.layout_info.ratio.value() * multiplier );
        } else {
            weights.push_back( non_ratio_weight );
        }
    }

    // We will work from top-down
    std::vector<math::Rect2i> bboxes;

    // Compute Sizes
    double tl_width = full_bbox.min().x();
    for( size_t idx = 0; idx < m_widgets.size(); idx++ )
    {
        // Compute size 
        int w = full_bbox.width()  * weights[idx];
        int h = full_bbox.height();

        auto tl = math::ToPoint2<int>( tl_width,
                                       full_bbox.min().x() );

        bboxes.push_back( math::Rect2i( tl, math::Size2i( { w, h } ) ) );

        tl_width += w;
    }

    return bboxes;
}

} // End of tmns::gui namespace