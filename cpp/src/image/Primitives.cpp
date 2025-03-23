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
#include <tmns/app/calc/image/Primitives.hpp>

namespace tmns::calc::img {

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

} // End of tmns::calc::img namespace