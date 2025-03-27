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
 * @file    TEST_LayoutVertical.cpp
 * @author  Marvin Smith
 * @date    03/25/2025
 *
 * @details Vertical Layout API Unit-Test
 */
#include <gtest/gtest.h>

// Project Libraries
#include <terminus/gui/layout/LayoutVertical.hpp>
#include <terminus/gui/widget/Label.hpp>
#include <terminus/log.hpp>

using namespace tmns;

class gui_LayoutVertical : public testing::Test 
{
    protected:

        void SetUp() override {

            // Build 3 sample frames for creating labels with
            test_frames.push_back( std::make_shared<img::Frame>( img::Dimensions( 300, 200, 4 ) ) );
            test_frames.push_back( std::make_shared<img::Frame>( img::Dimensions( 300, 200, 4 ) ) );
            test_frames.push_back( std::make_shared<img::Frame>( img::Dimensions( 300, 200, 4 ) ) );
        }

        void TearDown() override {
            test_frames.clear();
        }

        /// Internal Frames for test use
        std::vector<img::Frame::ptr_t> test_frames;

}; // End of calc_ui_LayoutVertical class

/**
 * Verify that we can allocate bboxes with fixed policy, plus a mixture of ratio and non-ratio elements
 * 
 * A good example of a basic Vertical Layout is the Splash screen (Splash.hpp/cpp)
 */
TEST_F( gui_LayoutVertical, allocate_bbox_test1 )
{
    // Create a Vertical Layout
    auto layout = std::make_shared<gui::LayoutVertical>();

    // Set padding
    int y_top_pad = 100;
    layout->set_padding( 100, 100, y_top_pad, 100 );

    // Set the layout size
    layout->set_layout_size( math::Size2i( { 800, 1000 } ) );

    // Demo alignment policy
    std::set<gui::AlignmentPolicy> alignment { { gui::AlignmentPolicy::CENTER_HORIZONTAL, 
                                                 gui::AlignmentPolicy::TOP } };

    // This gives us a working window of 300 x 800 starting at 100, 100
    auto label1 = gui::Label::from_frame( test_frames[0] );
    layout->append( label1, alignment, 0.6 );

    auto label2 = gui::Label::from_frame( test_frames[1] );
    layout->append( label2, alignment, 0.8 );

    auto label3 = gui::Label::from_frame( test_frames[2] );
    layout->append( label3, alignment, std::optional<double>() );

    // Get the BBOX Assignments
    auto bboxes = layout->allocate_bboxes();

    // Verify the list has 3 elements
    ASSERT_EQ( bboxes.size(), 3 );

    for( const auto& bbox : bboxes ){
        LOG_DEBUG( bbox.to_string() );
    }

    // Verify item 1, which is 0.6, has (0.6/1.4)*800 space
    int item1_height = static_cast<int>((0.6/1.4)*800);
    ASSERT_NEAR( bboxes[0].min().x(), 100, 0.001 );
    ASSERT_NEAR( bboxes[0].min().y(), 100, 0.001 );
    ASSERT_NEAR( bboxes[0].width(),   600, 0.001 );
    ASSERT_NEAR( bboxes[0].height(),  item1_height, 0.001 );

    // Verify item 2, which is 0.8, has (0.8/1.4)*800 space
    int item2_height = static_cast<int>((0.8/1.4)*800);
    ASSERT_NEAR( bboxes[1].min().x(), 100, 0.001 );
    ASSERT_NEAR( bboxes[1].min().y(), item1_height + y_top_pad, 0.001 );
    ASSERT_NEAR( bboxes[1].width(),   600, 0.001 );
    ASSERT_NEAR( bboxes[1].height(),  item2_height, 0.001 );

    // Verify item 3 has no space allocated
    ASSERT_NEAR( bboxes[2].area(), 0, 0.0001 );

}