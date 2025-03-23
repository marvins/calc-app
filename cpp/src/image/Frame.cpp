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
#include <terminus/app/calc/image/Frame.hpp>

namespace tmns::calc::img {

/********************************/
/*          Constructor         */
/********************************/
Frame::Frame( const Dimensions& dims )
  : m_dims( dims )
{
    resize( m_dims, 0 );
}

/******************************/
/*         Resize image       */
/******************************/
void Frame::resize( Dimensions new_dims, uint8_t pixel )
{
    m_image.resize( new_dims.size_bytes(), pixel );   
}

} // End of tmns::calc::img namespace