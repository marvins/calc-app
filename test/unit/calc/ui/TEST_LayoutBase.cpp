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
 * @file    TEST_LayoutBase.cpp
 * @author  Marvin Smith
 * @date    03/25/2025
 *
 * @details Vertical Layout API Unit-Test
 */
#include <gtest/gtest.h>

// Project Libraries
#include <terminus/gui/layout/LayoutBase.hpp>
#include <terminus/log.hpp>

using namespace tmns;

/**
 * Verify the "Align Widget" method
 */
TEST( gui_LayoutBase, align_widget )
{
    // Say we have the following example
    math::Rect2i allocated_bbox( math::ToPoint2(100, 100),
                                 math::Size2i( { 600, 400 } ) );
    
    // 600 x 400 is too large, we only need 300 x 200
    math::Size2i widget_size( { 300, 200 } );

    // If we align from the center (horizontally) and the top vertically, ....
    std::set<gui::AlignmentPolicy> alignment_top { { gui::AlignmentPolicy::CENTER_HORIZONTAL,
                                                     gui::AlignmentPolicy::TOP } };
    auto test1_res = gui::LayoutBase::align_widget( allocated_bbox,
                                                    widget_size,
                                                    alignment_top );

    ASSERT_EQ( test1_res.min().x(), 250 );
    ASSERT_EQ( test1_res.min().y(), 100 );
    ASSERT_EQ( test1_res.width(),   300 );
    ASSERT_EQ( test1_res.height(),  200 );
}