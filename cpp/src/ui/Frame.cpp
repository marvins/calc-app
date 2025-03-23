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
 * @file    Frame.cpp
 * @author  Marvin Smith
 * @date    03/22/2025
 *
 * @details Image Frame
 */
#include <tmns/app/calc/ui/Frame.hpp>

namespace tmns::calc::ui {

/********************************/
/*          Constructor         */
/********************************/
Frame::Frame( int rows, int cols, int channels )
  : m_rows { rows },
    m_cols { cols },
    m_channels { channels }
{
    m_image.resize( rows * cols * channels );
}

} // End of tmns::calc::ui namespace