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
 * @file    App_Factory.hpp
 * @author  Marvin Smith
 * @date    03/29/2025
 *
 * @details Factory API
 */
#include <terminus/calc/apps/App_Factory.hpp>

// Apps to import
#include <terminus/calc/apps/calculator/App_Calculator.hpp>
#include <terminus/calc/apps/editor/App_Editor.hpp>
#include <terminus/calc/apps/settings/App_Settings.hpp>

namespace tmns::calc {

/************************************************/
/*          Generate the default set            */
/************************************************/
std::vector<gui::App_Base::ptr_t> App_Factory::default_apps( core::Options& config,
                                                             gui::Session&  session )
{
    // Create list
    std::vector<gui::App_Base::ptr_t> apps;

    apps.push_back( app::App_Calculator::create( config, session ) );
    apps.push_back( app::App_Editor::create( config, session ) );
    apps.push_back( app::App_Settings::create( config, session ) );

    return apps;
}

} // End of tmns::calc namespace