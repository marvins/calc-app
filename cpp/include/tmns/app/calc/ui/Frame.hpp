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
 * @file    WidgetBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Image Frame
 */
#pragma once

// C++ Libraries
#include <memory>

namespace tmns::calc::ui {

/**
 * @class Frame
 */
struct Frame {

    std::vector<char> image;

    int rows;
    int cols;
    int channels;
    
};// End of Frame class

} // End of tmns::calc::ui namespace