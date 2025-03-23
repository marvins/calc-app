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
 * @file    FrameView.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Image Frame View
 */
#pragma once

// Project Libraries
#include <tmns/app/calc/image/Frame.hpp>

namespace tmns::calc::img {

/**
 * @class FrameView
 */
struct FrameView {

    public:

        /// @brief Deleted Default Constructor
        FrameView() = delete;

        /**
         * Pass in an entire frame image.
         */
        FrameView( Frame& frame );
        

    private:

        /// Internal Frame Handle
        Frame& m_frame;
    
};// End of FrameView class

} // End of tmns::calc::img namespace