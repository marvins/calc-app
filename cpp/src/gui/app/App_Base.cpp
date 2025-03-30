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
 * @file    App_Base.cpp
 * @author  Marvin Smith
 * @date    03/29/2025
 *
 * @details Base Application API
 */
#include <terminus/gui/app/App_Base.hpp>

namespace tmns::gui {

/**************************************/
/*      Parameterized Constructor     */
/**************************************/
App_Base::App_Base( gui::LayoutStack::ptr_t layout,
                    core::Options&          options,
                    gui::Session&           session )
    : WidgetLayout( layout ),
      m_options { options },
      m_session { session }{}

/**************************************/
/*      Get Configuration Options     */
/**************************************/
core::Options&  App_Base::options() {
    return m_options;
}

/**************************************/
/*      Get Session Information       */
/**************************************/
gui::Session& App_Base::session() {
    return m_session;
}
    
} // End of tmns::calc namespace