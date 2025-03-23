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
#include <vector>

namespace tmns::calc::ui {

/**
 * @class Frame
 */
struct Frame {

    public:

        /// @brief  Pointer Type
        using ptr_t = std::shared_ptr<Frame>;

        /**
         * Constructor
         */
        Frame() = default;

        /**
         * Parameterized Constructor
         */
        Frame( int rows, int cols, int channels );

        inline int rows() const { return m_rows; }

        inline int cols() const { return m_cols; }

        inline int channels() const { return m_channels; }

        std::vector<char> image() const{
            return m_image;
        }

        std::vector<char>& image() {
            return m_image;
        }

    private:

        /// @brief  Pixel Data
        std::vector<char> m_image;

        int m_rows { 0 };
        int m_cols { 0 };
        int m_channels { 0 };
    
};// End of Frame class

} // End of tmns::calc::ui namespace