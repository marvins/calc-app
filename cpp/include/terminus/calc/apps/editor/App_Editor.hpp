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
 * @file    App_Editor.hpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Settings Panel
 */
#pragma once

// Terminus Libraries
#include <terminus/gui/app/App_Base.hpp>

namespace tmns::calc::app {

class App_Editor : public gui::App_Base
{
    public:

        /// @brief Pointer Type
        using ptr_t = std::shared_ptr<App_Editor>;

        /**
         * Destructor
         */
        ~App_Editor() override = default;

        /**
         * Get the menu icon to show on the main-menu
         */
        img::Frame::ptr_t menu_icon() override;

        /**
         * Create an instance 
         */
        static App_Editor::ptr_t create( core::Options& config,
                                         gui::Session&  session );


    private:

        /// @brief This class is noncopyable
        App_Editor() = delete;
        App_Editor& operator = ( const App_Editor& ) = delete;
    
        /**
         * Parameterized Constructor
         */
        App_Editor( gui::LayoutStack::ptr_t layout,
                    core::Options&          options,
                    gui::Session&           session );

}; // End of App_Editor class

} // End of tmns::calc::app namespace