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
 * @file    LayoutBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Base Layout API
 */
#pragma once

// Project Libraries
#include <tmns/app/calc/core/Session.hpp>
#include <tmns/app/calc/ui/Frame.hpp>

namespace tmns::calc::ui {

/**
 * @class LayoutBase
 */
class LayoutBase : public Frame
{
    public:

        /**
         * Show the contents of the layout on the screen
         */
        virtual bool show( core::Session& session ) = 0;

    private:

};// End of LayoutBase class

} // End of tmns::calc::ui namespace
