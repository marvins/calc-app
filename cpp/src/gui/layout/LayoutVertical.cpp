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
#include <terminus/gui/layout/LayoutVertical.hpp>

// Terminus Libraries
#include <terminus/log/Logger.hpp>
#include <terminus/math/Rectangle.hpp>

namespace tmns::gui {

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
int LayoutVertical::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget      = new_widget;
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::CENTER_HORIZONTAL );
    new_layout_item.layout_info.alignment.insert( AlignmentPolicy::TOP );

    // Add to layout
    m_widgets.push_back( new_layout_item );

    return static_cast<int>(m_widgets.size()-1);
}

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
int LayoutVertical::append( WidgetBase::ptr_t          new_widget,
                            std::set<AlignmentPolicy>  alignment,
                            std::optional<double>      ratio ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget                = new_widget;
    new_layout_item.layout_info.alignment = alignment;
    new_layout_item.layout_info.ratio     = ratio;

    // Add to layout
    m_widgets.push_back( new_layout_item );

    return static_cast<int>(m_widgets.size()-1);
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
bool LayoutVertical::render( gui::Session&    session,
                             img::Frame_View& image )
{
    // First render the padding
    render_padding( session, image );

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

        // If widget is empty, then just skip the region
        if( widget_size.area() < 1 ){
            LOG_WARNING( "Widget has empty area.\n" + m_widgets[idx].widget->to_log_string() );

        } else {

            // Align the widget within the bounding box
            auto bbox_aligned = align_widget( widget_bbox_allocated,
                                              m_widgets[idx].widget->size_pixels(),
                                              m_widgets[idx].layout_info.alignment );
            
            {
                std::stringstream sout;
                sout << "Widget: " << idx << " bbox: " << bbox_aligned.to_string();
                LOG_TRACE(sout.str());
            }

            // Crop a section of the input image to apply our rendering to
            // @todo:  Figure out how the alignment API fits here
            auto subview = image.subview( bbox_aligned );

            m_widgets[idx].widget->render( session, subview );
        }
        point_tl.y() += widget_bbox_allocated.height();
    }
    
    return false;
}

/****************************************/
/*      Get allocated bounding box      */
/****************************************/
std::vector<math::Rect2i> LayoutVertical::allocate_bboxes() const
{
    // Get layout dimensions
    auto full_bbox = math::Rect2i( math::Vector2i( { 0, 0 } ),
                                   layout_size() );

    // Shrink from padding
    auto pad = padding();
    full_bbox.min() += math::Vector2i( { pad[0], pad[2] } );
    full_bbox.width()  -= (pad[0] + pad[1]);
    full_bbox.height() -= (pad[2] + pad[3]);

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
    double tl_height = full_bbox.min().y();
    for( size_t idx = 0; idx < m_widgets.size(); idx++ )
    {
        // Compute size 
        int w = full_bbox.width();
        int h = static_cast<int>(full_bbox.height() * weights[idx]);

        auto tl = math::ToPoint2<int>( full_bbox.min().x(),
                                       static_cast<int>(tl_height) );

        bboxes.push_back( math::Rect2i( tl, math::Size2i( { w, h } ) ) );

        tl_height += h;
    }

    return bboxes;
}

/************************************************/
/*          Create Log-Friendly String          */
/************************************************/
std::string LayoutVertical::to_log_string( size_t offset ) const
{
    std::stringstream sout;

    std::string gap( offset, ' ' );

    sout << gap << " - LayoutVertical:" << std::endl;
    sout << gap << "    - Size: " << layout_size().to_string() << std::endl;
    sout << gap << "    - Padding: " << padding().to_log_string() << std::endl;
    sout << gap << "    - Number Widgets: " << m_widgets.size() << std::endl;
    return sout.str();
}

} // End of tmns::gui namespace