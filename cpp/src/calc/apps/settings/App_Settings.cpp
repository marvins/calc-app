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
 * @file    App_Settings.cpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Settings Panel
 */
#include <terminus/calc/apps/settings/App_Settings.hpp>

namespace tmns::calc::app {

/************************************/
/*          Get the Menu Icon       */
/************************************/
img::Frame::ptr_t App_Settings::menu_icon() {
    return nullptr;
}

/****************************************************/
/*          Create the calculator instance          */
/****************************************************/
App_Settings::ptr_t App_Settings::create( core::Options& config,
                                          gui::Session&  session )
{
    // Build a layout
    auto layout = std::make_shared<gui::LayoutStack>();

    auto inst = std::shared_ptr<App_Settings>( new App_Settings( layout,
                                                                 config,
                                                                 session ) );

    return inst;
}

/****************************************/
/*      Parameterized Constructor       */
/****************************************/
App_Settings::App_Settings( gui::LayoutStack::ptr_t layout,
                            core::Options&          options,
                            gui::Session&           session )
    : gui::App_Base( layout,
      options,
      session ){}

} // End of tmns::calc::app namespace