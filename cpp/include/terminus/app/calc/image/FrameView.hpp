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
#include <terminus/app/calc/image/Frame.hpp>
#include <terminus/app/calc/image/Primitives.hpp>
#include <terminus/math/Rectangle.hpp>

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

        /**
         * Pass in a subview of the input.
         */
        FrameView( Frame&              frame, 
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
        FrameView subview( const math::Rect2i& bbox );

        /**
         * Copy the input frame into this view.  
         * @param frame Input image to copy
         * @param copy_policy  Rules for copying imagery.
         */
        bool copy( const FrameView& frame,
                   CopyPolicy       copy_policy );
        
        /**
         * Copy the input frame into this view.  
         * @param frame Input image to copy
         * @param copy_policy  Rules for copying imagery.
         */
        bool copy( const Frame& frame,
                   CopyPolicy   copy_policy );


    private:

        /// Internal Frame Handle
        Frame& m_frame;

        /// Bounding box (Original frame's view)
        math::Rect2i m_bbox;
    
};// End of FrameView class

} // End of tmns::calc::img namespace