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
#include <terminus/image/Frame_View.hpp>

/// Terminus Libraries
#include <terminus/log/Logger.hpp>
#include <terminus/math/Point_Utilities.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::img {

/****************************/
/*      Constructor         */
/****************************/
Frame_View::Frame_View( Frame& frame )
    : m_frame { frame }
{
    m_bbox = math::Rect2i( math::ToPoint2<int>( 0, 0 ),
                           frame.size() );
}

/****************************/
/*      Constructor         */
/****************************/
Frame_View::Frame_View( Frame&              frame,
                        const math::Rect2i& bbox )
    : m_frame { frame },
      m_bbox { bbox }
{}

/****************************************/
/*          Get Specific Pixel          */
/****************************************/
uint8_t& Frame_View::get_pixel( int col, int row, int channel )
{
    int act_col = col - m_bbox.bl().x();
    int act_row = row - m_bbox.bl().y();

    return m_frame.get_pixel( act_col, act_row, channel );
}

/****************************************/
/*          Get Specific Pixel          */
/****************************************/
uint8_t Frame_View::get_pixel( int col, int row, int channel ) const
{
    int act_col = col - m_bbox.bl().x();
    int act_row = row - m_bbox.bl().y();

    return m_frame.get_pixel( act_col, act_row, channel );
}

/****************************************/
/*          Get Specific Pixel          */
/****************************************/
math::Vector4u Frame_View::get_pixel( int col, int row ) const
{
    int act_col = col - m_bbox.bl().x();
    int act_row = row - m_bbox.bl().y();

    return m_frame.get_pixel( act_col, act_row );
}

/****************************************/
/*          Set Specific Pixel          */
/****************************************/
void Frame_View::set_pixel( int col, int row, int channel, uint8_t value )
{
    int act_col = col + m_bbox.bl().x();
    int act_row = row + m_bbox.bl().y();
    m_frame.set_pixel( act_col, act_row, channel, value  );
}

/****************************************/
/*          Set Specific Pixel          */
/****************************************/
void Frame_View::set_pixel( int col, int row, math::Vector4u value )
{
    int act_col = col + m_bbox.bl().x();
    int act_row = row + m_bbox.bl().y();
    m_frame.set_pixel( act_col, act_row, value  );
}

/**************************************************/
/*      Return a subview of this current image    */
/**************************************************/
Frame_View Frame_View::subview( const math::Rect2i& bbox )
{
    LOG_DEBUG( "This BBOX: " + m_bbox.to_string() + " that bbox: " + bbox.to_string() );
    // Adjust bottom left corner (Not by actual values, but by DELTA!)
    auto new_bl = m_bbox.bl();
    
    // @todo:  Add some error checking here
    new_bl += bbox.bl();

    auto new_size = math::Size2i( { bbox.width(), bbox.height() } );

    // The new size of the scene
    auto new_bbox = math::Rect2i( new_bl, new_size );
    
    return Frame_View( m_frame, new_bbox );
}

/**************************************************/
/*       Copy from one image onto this image      */
/**************************************************/
bool Frame_View::copy( const Frame& frame,
                      CopyPolicy   copy_policy )
{
    // @todo:  Think about other policies
    if( copy_policy != CopyPolicy::FLEXIBILE ){
        std::stringstream sout;
        sout << "Unsupported CopyPolicy: " << to_string( copy_policy );
        throw std::runtime_error( sout.str() );
    }

    {
        std::stringstream sout;
        sout << "This BBOX: " << m_bbox.to_string() << ", Incoming Frame: " << frame.to_log_string();
        LOG_DEBUG(sout.str());
    }

    // Copy the image row  by row
    for( size_t r = 0; r < frame.rows(); r++ )
    {
        // Get the destination row
        int dest_row = m_bbox.bl()[1] + r;

        // Iterate over each input column
        for( size_t c = 0; c < frame.cols(); c++ )
        {
            // Get the destination column
            int dest_col = m_bbox.bl()[0] + c;

            auto pixel = frame.get_pixel( c, r );
            m_frame.set_pixel( dest_col, dest_row, pixel );
        }
    }

    return true;    
}

/**************************************************/
/*       Copy from one image onto this image      */
/**************************************************/
bool Frame_View::copy( const Frame_View& frame,
                       CopyPolicy        copy_policy )
{
    // @todo:  Think about other policies
    if( copy_policy != CopyPolicy::FLEXIBILE ){
        std::stringstream sout;
        sout << "Unsupported CopyPolicy: " << to_string( copy_policy );
        throw std::runtime_error( sout.str() );
    }

    // Copy the image row  by row
    for( size_t r = 0; r < frame.rows(); r++ )
    {
        // Get the destination row
        int dest_row = m_bbox.bl()[1];

        // Iterate over each input column
        for( size_t c = 0; c < frame.cols(); c++ )
        {
            // Get the destination column
            int dest_col = m_bbox.bl()[0];

            for( size_t x = 0; x < frame.channels(); x++ )
            {
                auto pixel = frame.get_pixel( r, c, x );
                m_frame.set_pixel( r, c, x, pixel );
            }
        }
    }

    return true;    
}

/************************************************/
/*          Print Log-Friendly String           */
/************************************************/
std::string Frame_View::to_log_string( size_t offset ) const
{
    std::string gap( offset, ' ' );

    std::stringstream sout;
    sout << gap << "Frame_View:" << std::endl;
    sout << gap << "  - Frame Information: " << std::endl;
    sout << m_frame.to_log_string( offset + 4 );
    sout << gap << "  - Bounding Box: " << m_bbox.to_string() << std::endl;
    return sout.str();
}

} // End of tmns::img namespace