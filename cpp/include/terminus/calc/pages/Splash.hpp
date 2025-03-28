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
 * @file    Splash.hpp
 * @author  Marvin Smith
 * @date    3/22/2025
 */
#pragma once

// Project Libraries
#include <terminus/core/Options.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/layout/LayoutVertical.hpp>


namespace tmns::calc::page {

class Splash : public gui::LayoutVertical
{
    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Splash>;

        /**
         * Show the screen for a bit, then exit
         */
        void show( core::Options& config,
                   gui::Session&  session );

        /**
         * Create a new Splash Screen
         */
        static Splash::ptr_t create( const core::Options& config,
                                     gui::Session&        session );
        
        
}; // End Splash class

} // End of tmns::calc::page namespace