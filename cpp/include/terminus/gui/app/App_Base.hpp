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
 * @file    App_Base.hpp
 * @author  Marvin Smith
 * @date    03/29/2025
 *
 * @details Base Application API
 */
#pragma once

// Terminus Libraries
#include <terminus/core/Options.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/layout/LayoutStack.hpp>
#include <terminus/gui/widget/WidgetLayout.hpp>
#include <terminus/image/Frame.hpp>

/// C++ Standard Libraries
#include <memory>

namespace tmns::gui {

class App_Base : public WidgetLayout
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<App_Base>;

        /**
         * Get the menu icon to show on the main-menu
         */
        virtual img::Frame::ptr_t menu_icon() = 0;

    protected:

        /// Non-Copyable
        App_Base() = delete;
        App_Base( const App_Base& ) = delete;
        App_Base& operator = ( const App_Base& ) = delete;

        /**
         * Parameterized Constructor
         */
        App_Base( gui::LayoutStack::ptr_t layout,
                  core::Options&          options,
                  gui::Session&           session );

        /**
         * Get Configuration Info
         */
        core::Options&  options();
        
        /**
         * Get Session Info
         */
        gui::Session& session();

    private:

        /// Configuration Information
        core::Options&  m_options;

        /// Session Information
        gui::Session&  m_session;

}; // End of App_Base class

} // End of tmns::calc namespace