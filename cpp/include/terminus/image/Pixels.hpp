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
 * @file    Pixels.hpp
 * @author  Marvin Smith
 * @date    03/29/2025
 *
 * @details Handy Pixel APIs.
 */
#pragma once

// Terminus Libraries
#include <terminus/math/Vector.hpp>

namespace tmns::img {

static constexpr math::Vector4u PIXEL_BLACK( uint8_t alpha = 255 ){ return math::Vector4u( {   0,   0,   0, alpha } ); };
static constexpr math::Vector4u PIXEL_GREEN( uint8_t alpha = 255 ){ return math::Vector4u( {   0, 255,   0, alpha } ); };
static constexpr math::Vector4u PIXEL_GREY(  uint8_t alpha = 255 ){ return math::Vector4u( {  126, 126,126, alpha } ); };
static constexpr math::Vector4u PIXEL_BLUE(  uint8_t alpha = 255 ){ return math::Vector4u( {   0,   0, 255, alpha } ); };
static constexpr math::Vector4u PIXEL_RED(   uint8_t alpha = 255 ){ return math::Vector4u( { 255,   0,   0, alpha } ); };
static constexpr math::Vector4u PIXEL_WHITE( uint8_t alpha = 255 ){ return math::Vector4u( { 255, 255, 255, alpha } ); };


} // End of tmns::image namespace