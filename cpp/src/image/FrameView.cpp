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
#include <tmns/app/calc/image/FrameView.hpp>

namespace tmns::calc::img {

/****************************/
/*      Constructor         */
/****************************/
FrameView::FrameView( Frame& frame )
  : m_frame { frame }
{}

} // End of tmns::calc::img namespace