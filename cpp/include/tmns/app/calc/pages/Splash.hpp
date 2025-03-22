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
#include <tmns/app/calc/core/Options.hpp>
#include <tmns/app/calc/core/Session.hpp>
#include <tmns/app/calc/ui/LayoutVertical.hpp>

namespace tmns::calc::page {

class Splash : public ui::LayoutVertical
{
    public:

        /**
         * Create a new Splash Screen
         */
        static Splash::ptr_t create( const core::Options& config,
                                     core::Session&       session );
        
        
}; // End Splash class

} // End of tmns::calc::page namespace