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
 * @file    App_Calculator.hpp
 * @author  Marvin Smith
 * @date    03/30/2025
 *
 * @details Settings Panel
 */
#pragma once

// Terminus Libraries
#include <terminus/gui/app/App_Base.hpp>

namespace tmns::calc::app {

class App_Calculator : public gui::App_Base
{
    public:

        /// @brief Pointer Type
        using ptr_t = std::shared_ptr<App_Calculator>;

        /**
         * Destructor
         */
        ~App_Calculator() override = default;

        /**
         * Get the menu icon to show on the main-menu
         */
        img::Frame::ptr_t menu_icon() override;

        /**
         * Create an instance 
         */
        static App_Calculator::ptr_t create( core::Options& config,
                                             gui::Session&  session );

    private:

        /// @brief This class is noncopyable
        App_Calculator() = delete;
        App_Calculator& operator = ( const App_Calculator& ) = delete;

        /**
         * Parameterized Constructor
         */
        App_Calculator( gui::LayoutStack::ptr_t layout,
                        core::Options&          options,
                        gui::Session&           session );

}; // End of App_Calculator class

} // End of tmns::calc::app namespace