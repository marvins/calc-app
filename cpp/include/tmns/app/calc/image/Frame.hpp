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
 * @file    Frame.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Image Frame
 */
#pragma once

// C++ Libraries
#include <memory>
#include <vector>

// Project Libraries
#include <tmns/app/calc/image/Primitives.hpp>

namespace tmns::calc::img {

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
        Frame( const Dimensions& dims );

        /**
         * Get the image dimensions
         */
        inline Dimensions dims() const { return m_dims; }

        /**
         * Get a copy of the pixel data
         */
        inline std::vector<char> image() const{
            return m_image;
        }

        /**
         * Get a reference of the pixel data
         */
        inline std::vector<char>& image_ref() {
            return m_image;
        }

        /**
         * Resize the image to new dimensions
         */
        void resize( Dimensions new_dims );

    private:

        /// @brief  Pixel Data
        std::vector<char> m_image;

        // Image Dimensions
        Dimensions m_dims {};
    
};// End of Frame class

} // End of tmns::calc::img namespace