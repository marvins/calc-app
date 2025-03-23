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
 * @file    WidgetLayoutItem.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Container which stores widget plus layout data.
 */
#pragma once

// Project Libraries
#include <terminus/app/calc/ui/LayoutPrimitives.hpp>
#include <terminus/app/calc/ui/WidgetBase.hpp>

namespace tmns::calc::ui {

struct WidgetLayoutItem {

    /// Widget to add
    WidgetBase::ptr_t  widget;

    /// Layout Info
    WidgetLayoutInfo   layout_info;
};

} // End of tmns::calc::ui namespace
