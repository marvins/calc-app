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
#include <terminus/calc/image/Primitives.hpp>

namespace tmns::calc::img {

/********************************/
/*      Convert to String       */
/********************************/
std::string to_string( CopyPolicy policy )
{
    switch( policy ){
        case CopyPolicy::FLEXIBILE:
            return "FLEXIBLE";
        default:
            return "UNKNOWN";
    }
}

/********************************/
/*          Constructor         */
/********************************/
Dimensions::Dimensions( size_t cols, size_t rows, size_t channels )
    : m_cols { cols },
      m_rows { rows },
      m_channels { channels }
{}

/********************************************/
/*          Get the size in bytes           */
/********************************************/
size_t Dimensions::size_bytes() const {
    return m_rows * m_cols * m_channels;
}

/********************************************/
/*          Get the size in pixels          */
/********************************************/
math::Size2i Dimensions::size() const {
    return math::Size2i( { static_cast<int>(m_cols),
                           static_cast<int>(m_rows) } );
}

} // End of tmns::calc::img namespace