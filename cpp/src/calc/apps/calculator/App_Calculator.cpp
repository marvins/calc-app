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
 * @file    App_Calculator.cpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Calculator application
 */
#include <terminus/calc/apps/calculator/App_Calculator.hpp>

// Terminus Libraries
#include <terminus/gui/layout/LayoutStack.hpp>

namespace tmns::calc::app {

/****************************************************/
/*          Load the application menu icon          */
/****************************************************/
img::Frame::ptr_t App_Calculator::menu_icon() {
    return nullptr;
}

/****************************************************/
/*          Create the calculator instance          */
/****************************************************/
App_Calculator::ptr_t App_Calculator::create( core::Options& config,
                                              gui::Session&  session )
{
    // Build a layout
    auto layout = std::make_shared<gui::LayoutStack>();

    auto inst = std::shared_ptr<App_Calculator>( new App_Calculator( layout,
                                                                     config,
                                                                     session ) );

    return inst;
}

/****************************************/
/*      Parameterized Constructor       */
/****************************************/
App_Calculator::App_Calculator( gui::LayoutStack::ptr_t layout,
                                core::Options&          options,
                                gui::Session&           session )
    : gui::App_Base( layout,
                     options,
                     session ){}

} // End of tmns::app::cc namespace