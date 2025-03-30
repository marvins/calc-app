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
#include <terminus/calc/pages/HeaderWidget.hpp>
#include <terminus/calc/pages/FooterWidget.hpp>
#include <terminus/calc/pages/Main_Menu.hpp>
#include <terminus/core/Options.hpp>
#include <terminus/gui/app/App_Base.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/layout/LayoutStack.hpp>
#include <terminus/gui/layout/LayoutVertical.hpp>
#include <terminus/gui/widget/WidgetLayout.hpp>
#include <terminus/gui/I_Main_Window.hpp>

namespace tmns::calc::page {

class Main_Window : public gui::I_Main_Window
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Main_Window>;

        /**
         * Update the main window
         */
        void update( core::Options& config,
                     gui::Session&  session ) override;

        /**
         * Render the main window onto the image.
         */
        bool render( gui::Session&    session,
                     img::Frame_View& image ) override;

        /**
         * Create a new Splash Screen
         */
        static Main_Window::ptr_t create( core::Options&                    config,
                                          gui::Session&                     session,
                                          std::vector<gui::App_Base::ptr_t> apps );
    
    protected:

        /// Deleted Default Constructor
        Main_Window() = delete;

        /**
         * Parameterized Constructor
         */
        Main_Window( gui::LayoutBase::ptr_t layout );

    private:

        /// Underlying base widget
        gui::WidgetLayout::ptr_t m_base_widget;

        /// Header Widget
        Header_Widget::ptr_t m_header;

        /// Stacked Widget holding all app pages
        gui::LayoutStack::ptr_t m_stack_layout;

        /// Main Menu (Stored inside the stacked widget)
        Main_Menu::ptr_t m_main_app_menu;

        /// Footer Widget
        Footer_Widget::ptr_t m_footer;

        /// List of actual apps
        std::vector<gui::App_Base::ptr_t> m_apps;
        
}; // End Main_Window class

} // End of tmns::calc::page namespace