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
 * @file    App_Editor.cpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Text editor application
 */
#include <terminus/calc/apps/editor/App_Editor.hpp>

namespace tmns::calc::app {

/************************************/
/*          Get the Menu Icon       */
/************************************/
img::Frame::ptr_t App_Editor::menu_icon() {
    return nullptr;
}

/****************************************************/
/*          Create the calculator instance          */
/****************************************************/
App_Editor::ptr_t App_Editor::create( core::Options& config,
                                      gui::Session&  session )
{
    // Build a layout
    auto layout = std::make_shared<gui::LayoutStack>();

    auto inst = std::shared_ptr<App_Editor>( new App_Editor( layout,
                                                             config,
                                                             session ) );

    return inst;
}

/****************************************/
/*      Parameterized Constructor       */
/****************************************/
App_Editor::App_Editor( gui::LayoutStack::ptr_t layout,
                        core::Options&          options,
                        gui::Session&           session )
    : gui::App_Base( layout,
      options,
      session ){}

} // End of tmns::app::cc namespace