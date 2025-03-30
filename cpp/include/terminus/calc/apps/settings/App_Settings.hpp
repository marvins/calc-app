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
 * @file    App_Settings.hpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Settings Panel
 */
#pragma once

// Terminus Libraries
#include <terminus/gui/app/App_Base.hpp>

namespace tmns::calc::app {

class App_Settings : public gui::App_Base
{
    public:

        /// @brief Pointer Type
        using ptr_t = std::shared_ptr<App_Settings>;

        /**
         * Destructor
         */
        ~App_Settings() override = default;

        /**
         * Get the menu icon to show on the main-menu
         */
        img::Frame::ptr_t menu_icon() override;

        /**
         * Create an instance 
         */
        static App_Settings::ptr_t create( core::Options& config,
                                           gui::Session&  session );

    private:

        /// @brief This class is noncopyable
        App_Settings() = delete;
        App_Settings& operator = ( const App_Settings& ) = delete;
        
        /**
         * Parameterized Constructor
         */
        App_Settings( gui::LayoutStack::ptr_t layout,
                      core::Options&          options,
                      gui::Session&           session );

}; // End of App_Settings class

} // End of tmns::calc::app namespace