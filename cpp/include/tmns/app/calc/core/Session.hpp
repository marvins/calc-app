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
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#pragma once

// C++ Standard Libraries
#include <filesystem>

// Project Libraries
#include <tmns/app/calc/core/Options.hpp>

namespace tmns::calc::core {

class Session final {

    public:

        /**
         * Generate a session given command-line instructions
         */
        static Session create( Options config );

    private:


}; // End of Session class

} // End of tmns::core namespace