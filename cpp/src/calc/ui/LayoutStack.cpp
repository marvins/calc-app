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
 * @file    LayoutStack.cpp
 * @author  Marvin Smith
 * @date    03/27/2025
 *
 * @details Stack Layout API
 */
#include <terminus/calc/ui/LayoutStack.hpp>

// Terminus Libraries
#include <terminus/log/Logger.hpp>


namespace tmns::calc::ui {

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
size_t LayoutStack::append( WidgetBase::ptr_t new_widget ){

    // Wrap with new layout item
    WidgetLayoutItem new_layout_item;
    new_layout_item.widget = new_widget;

    // Add to layout
    m_widgets.push_back( new_layout_item );

    return (m_widgets.size() - 1);
}

} // End of tmns::calc::ui namespace