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
#include <terminus/image/Frame.hpp>

// C++ Standard Libraries
#include <iostream>
#include <sstream>

namespace tmns::img {

/********************************/
/*          Constructor         */
/********************************/
Frame::Frame( const Dimensions& dims )
  : m_dims( dims )
{
    resize( m_dims, 0 );
}

/********************************/
/*          Constructor         */
/********************************/
Frame::Frame( std::span<char>   pixel_data,
              const Dimensions& dims )
  : m_dims( dims )
{
    resize( m_dims, 0 );
    std::copy( pixel_data.begin(),
               pixel_data.end(),
               m_image.begin() );
}

/******************************/
/*         Resize image       */
/******************************/
void Frame::resize( Dimensions new_dims, uint8_t pixel )
{
    m_dims = new_dims;
    m_image.resize( new_dims.size_bytes(), pixel );   
}

/******************************/
/*      Get Pixel Value       */
/******************************/
uint8_t& Frame::get_pixel( int col, int row, int channel ){
    return m_image[ row * m_dims.cols() + col * m_dims.channels() + channel];
}

/******************************/
/*      Get Pixel Value       */
/******************************/
uint8_t Frame::get_pixel( int col, int row, int channel ) const {
  return m_image[ row * m_dims.cols() + col * m_dims.channels() + channel];
}

/******************************/
/*      Get Pixel Value       */
/******************************/
math::Vector4u Frame::get_pixel( int col, int row ) const {

  // Get the start position
  size_t pos = row * m_dims.cols() * m_dims.channels() + col * m_dims.channels();

  return math::Vector4u( { m_image[pos+0],
                           m_image[pos+1],
                           m_image[pos+2],
                           m_image[pos+3]});
}

/******************************/
/*      Set Pixel Value       */
/******************************/
void Frame::set_pixel( int col, int row, int channel, uint8_t value ){
  m_image[ row * m_dims.cols() * m_dims.channels() + col * m_dims.channels() + channel] = value;
}

/******************************/
/*      Set Pixel Value       */
/******************************/
void Frame::set_pixel( int col, int row, math::Vector4u value ){

  // Point to the first position
  size_t pos = row * m_dims.cols() * m_dims.channels() + col * m_dims.channels();

  std::copy( value.begin(), 
             value.end(),
             m_image.begin() + pos );
}

/************************************************/
/*          Print Log-Friendly String           */
/************************************************/
std::string Frame::to_log_string( size_t offset ) const
{
    std::string gap( offset, ' ' );

    std::stringstream sout;
    sout << gap << "Frame:" << std::endl;
    sout << gap << "  - Cols: " << cols() << ", Rows: " << rows() << ", Channels: " << channels() << std::endl;
    sout << gap << "  - Image Allocated Size: " << m_image.size() << std::endl; 
    return sout.str();
}


} // End of tmns::img namespace