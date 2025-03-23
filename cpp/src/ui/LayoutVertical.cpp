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
#include <tmns/app/calc/ui/LayoutVertical.hpp>

namespace tmns::calc::ui {

/*****************************************/
/*         Add Layout to Widget List     */
/*****************************************/
void LayoutVertical::append( WidgetBase::ptr_t new_widget ){
    std::unique_lock<std::mutex> lck( m_widget_mtx );
    m_widgets.push_back( new_widget );
}

/****************************************/
/*          Show the Contents           */
/****************************************/
bool LayoutVertical::render( core::Session& session,
                             img::Frame&    image )
{
    return false;
}


} // End of tmns::calc::ui namespace