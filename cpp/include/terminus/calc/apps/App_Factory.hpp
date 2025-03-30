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
 * @details Factory builder for Application interfaces.
 */
#pragma once

// Terminus Libraries
#include <terminus/core/Options.hpp>
#include <terminus/gui/app/App_Base.hpp>
#include <terminus/gui/core/Session.hpp>
#include <terminus/image/Frame.hpp>

// C++ Standard Libraries
#include <memory>
#include <vector>

namespace tmns::calc {

/**
 * Generate the applications used
 * 
 * @note:  Once I someday get to doing separable compilation and
 *         dynamic linking, this is where a plugin architecture will
 *         make this more than just a set of default apps.
 */
class App_Factory
{
    public:

        /// @brief Pointer Type
        using ptr_t = std::shared_ptr<App_Factory>;

        /**
         * Build an instance using the standard set of apps.
         */
        static std::vector<gui::App_Base::ptr_t> default_apps( core::Options& config,
                                                               gui::Session&  session );

    private:


}; // End of App_Base class

} // End of tmns::calc namespace