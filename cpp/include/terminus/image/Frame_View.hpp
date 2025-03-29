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
 * @file    Frame_View.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Image Frame View
 */
#pragma once

// Project Libraries
#include <terminus/image/Frame.hpp>
#include <terminus/image/Primitives.hpp>
#include <terminus/math/Rectangle.hpp>

namespace tmns::img {

/**
 * @class Frame_View
 */
struct Frame_View {

    public:

        /// @brief Deleted Default Constructor
        Frame_View() = delete;

        /**
         * Pass in an entire frame image.
         */
        Frame_View( Frame& frame );

        /**
         * Pass in a subview of the input.
         */
        Frame_View( Frame&              frame, 
                    const math::Rect2i& bbox );

        /**
         * Return image cols
         */
        inline int cols() const { return m_bbox.width(); }
        
        /**
         * Return image rows
         */
        inline int rows() const { return m_bbox.height(); }

        /**
         * Return image channels
         */
        inline int channels() const { return 4; }

        /**
         * Get a specific pixel value
         */
        uint8_t& get_pixel( int col, int row, int channel );

        /**
         * Get a specific pixel value
         */
        uint8_t get_pixel( int col, int row, int channel ) const;

        /**
         * Get a specific pixel value
         */
        math::Vector4u get_pixel( int col, int row ) const;

        /**
         * Set a specific pixel
         *
         */
        void set_pixel( int row, int col, int channel, uint8_t value );

        /**
         * Set a specific pixel
         *
         */
        void set_pixel( int row, int col, math::Vector4u value );
        
        /**
         * @brief Return another view of the frame, given a smaller window.
         * @note  Window input is in this view's perspective, but the resulting
         *        view will be kept in the perspective of the original frame.
         */
        Frame_View subview( const math::Rect2i& bbox );

        /**
         * Copy the input frame into this view.  
         * @param frame Input image to copy
         * @param copy_policy  Rules for copying imagery.
         */
        bool copy( const Frame_View& frame,
                   CopyPolicy        copy_policy );
        
        /**
         * Copy the input frame into this view.  
         * @param frame Input image to copy
         * @param copy_policy  Rules for copying imagery.
         */
        bool copy( const Frame& frame,
                   CopyPolicy   copy_policy );

        /**
         * Print information to log-friendly string
         */
        std::string to_log_string( size_t offset = 0 ) const;


    private:

        /// Internal Frame Handle
        Frame& m_frame;

        /// Bounding box (Original frame's view)
        math::Rect2i m_bbox;
    
};// End of Frame_View class

} // End of tmns::img namespace