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
 * @file    Main_Window.hpp
 * @author  Marvin Smith
 * @date    3/25/2025
 */
#pragma once

// Project Libraries
#include <terminus/calc/core/Options.hpp>
#include <terminus/calc/core/Session.hpp>
#include <terminus/calc/pages/HeaderWidget.hpp>
#include <terminus/calc/pages/FooterWidget.hpp>
#include <terminus/calc/pages/Main_Menu.hpp>
#include <terminus/calc/ui/LayoutStack.hpp>
#include <terminus/calc/ui/LayoutVertical.hpp>

namespace tmns::calc::page {

class Main_Window : public ui::LayoutVertical
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Main_Window>;

        /**
         * Show the screen for a bit, then exit
         */
        void render( core::Options& config,
                     core::Session& session );

        /**
         * Create a new Splash Screen
         */
        static Main_Window::ptr_t create( const core::Options& config,
                                          core::Session&       session );
        
    private:

        /// Header Widget
        Header_Widget::ptr_t m_header;

        /// Stacked Widget holding all app pages
        ui::LayoutStack::ptr_t m_stack_layout;

        /// Main Menu (Stored inside the stacked widget)
        Main_Menu::ptr_t m_main_app_menu;

        /// Footer Widget
        Footer_Widget::ptr_t m_footer;
        
}; // End Main_Window class

} // End of tmns::calc::page namespace