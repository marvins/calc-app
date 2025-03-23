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
 * @file    Primitives.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Image Primivite Types
 */
#pragma once

// C++ Libraries
#include <memory>
#include <vector>

// Terminus Libraries
#include <terminus/math/Size.hpp>

namespace tmns::calc::img {

/**
 * @brief Represents Image Characteristics
 */
class Dimensions {

    public:

        /// @brief Default Constructor
        Dimensions() = default;

        /**
         * Parameterized Constructor
         */
        Dimensions( size_t cols,
                    size_t rows,
                    size_t channels );

        /**
         * Get the columns
         */
        inline size_t cols() const { return m_cols; }

        /**
         * Set the columns
         */
        inline void set_cols( size_t cols ){ m_cols = cols; }

        /**
         * Get the rows
         */
        inline size_t rows() const { return m_rows; }

        /**
         * Set the rows
         */
        inline void set_rows( size_t rows ){ m_rows = rows; }

        /**
         * Get the channels
         */
        inline size_t channels() const { return m_channels; }

        /**
         * Set the channels
         */
        inline void set_channels( size_t channels ){ m_channels = channels; }

        /**
         * Return the size in bytes
         */
        size_t size_bytes() const;

        /**
         * Return Size of Image
         */
        math::Size2i size() const;

    private:

        /// Image Columns
        size_t m_cols { 0 };

        /// Image Rows
        size_t m_rows { 0 };

        /// Channels
        size_t m_channels { 0 };

}; // End of Dimensions Class

} // End of tmns::calc::img namespace