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
#include <span>
#include <vector>

// Project Libraries
#include <terminus/image/Primitives.hpp>

namespace tmns::img {

/**
 * @class Frame
 */
struct Frame {

    public:

        /// @brief Number of "Expected Channels when none are available"
        static constexpr int CHANNELS { 4 };

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
         * Parameterized Constructor
         */
        Frame( std::span<char>   pixel_data,
               const Dimensions& dims );

        /**
         * Return image cols
         */
        inline int cols() const { return size()[0]; }
        
        /**
         * Return image rows
         */
        inline int rows() const { return size()[1]; }

        /**
         * Return image channels
         */
        inline int channels() const { return dims().channels(); }

        /**
         * Image Size
         */
        inline math::Size2i size() const { return m_dims.size(); }
        
        /**
         * Get the image dimensions
         */
        inline Dimensions dims() const { return m_dims; }

        /**
         * Get a copy of the pixel data
         */
        inline std::vector<uint8_t> image() const{
            return m_image;
        }

        /**
         * Get a reference of the pixel data
         */
        inline std::vector<uint8_t>& image_ref() {
            return m_image;
        }

        /**
         * Resize the image to new dimensions
         */
        void resize( Dimensions new_dims, uint8_t pixel );

        /**
         * Get a specific pixel
         *
         */
        uint8_t& get_pixel( int col, int row, int channel );

        /**
         * Get a specific pixel
         *
         */
        uint8_t get_pixel( int col, int row, int channel ) const;

        /**
         * Get a specific pixel
         *
         */
        math::Vector4u get_pixel( int col, int row ) const;
        
        /**
         * Set a specific pixel
         *
         */
        void set_pixel( int col, int row, int channel, uint8_t value );

        /**
         * Set a specific pixel
         *
         */
        void set_pixel( int col, int row, math::Vector4u value );

        /**
         * Print information about frame data
         */
        std::string to_log_string( size_t offset = 0 ) const;

    private:

        /// @brief  Pixel Data
        std::vector<uint8_t> m_image;

        // Image Dimensions
        Dimensions m_dims {};
    
};// End of Frame class

} // End of tmns::img namespace