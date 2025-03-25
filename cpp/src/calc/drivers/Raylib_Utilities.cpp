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
 * @file    Raylib_Utilities.hpp
 * @author  Marvin Smith
 * @date    03/25/2025
 *
 * @details Raylib Graphics API Wrapper Header
 */
#include <terminus/calc/drivers/Raylib_Utilities.hpp>

// C++ Standard Libraries
#include <iostream>
#include <sstream>

namespace tmns::calc::drv {

/********************************************************************/
/*      Convert a Raylib format enum into number of channels        */
/********************************************************************/
int raylib_format_to_channels( PixelFormat fmt )
{
    switch( fmt ){
        case PIXELFORMAT_UNCOMPRESSED_GRAYSCALE:
        case PIXELFORMAT_UNCOMPRESSED_R32:
        case PIXELFORMAT_UNCOMPRESSED_R16:
            return 1;
        case PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA:
            return 2;
        case PIXELFORMAT_UNCOMPRESSED_R5G6B5:
        case PIXELFORMAT_UNCOMPRESSED_R8G8B8:
        case PIXELFORMAT_UNCOMPRESSED_R32G32B32:
        case PIXELFORMAT_UNCOMPRESSED_R16G16B16:
        
            return 3;
        case PIXELFORMAT_UNCOMPRESSED_R5G5B5A1:
        case PIXELFORMAT_UNCOMPRESSED_R4G4B4A4:
        case PIXELFORMAT_UNCOMPRESSED_R8G8B8A8:
        case PIXELFORMAT_UNCOMPRESSED_R32G32B32A32:
        case PIXELFORMAT_UNCOMPRESSED_R16G16B16A16:
            return 4;
        
        case PIXELFORMAT_COMPRESSED_DXT1_RGB:
        case PIXELFORMAT_COMPRESSED_DXT1_RGBA:
        case PIXELFORMAT_COMPRESSED_DXT3_RGBA: 
        case PIXELFORMAT_COMPRESSED_DXT5_RGBA: 
        case PIXELFORMAT_COMPRESSED_ETC1_RGB:
        case PIXELFORMAT_COMPRESSED_ETC2_RGB:
        case PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA:
        case PIXELFORMAT_COMPRESSED_PVRT_RGB:
        case PIXELFORMAT_COMPRESSED_PVRT_RGBA:
        case PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA:
        case PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA:
        default:
        {
            std::stringstream sout;
            sout << "Unsupported or unknown format type: " << fmt;
            throw std::runtime_error( sout.str() );
        }
    }   
}

/********************************************/
/*      Convert PixelFormat to String       */
/********************************************/
std::string to_string( PixelFormat fmt ){

    switch( fmt )
    {
        case PIXELFORMAT_UNCOMPRESSED_GRAYSCALE:
            return "PIXELFORMAT_UNCOMPRESSED_GRAYSCALE";
        case PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA:
            return "PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA";
        case PIXELFORMAT_UNCOMPRESSED_R5G6B5:
            return "PIXELFORMAT_UNCOMPRESSED_R5G6B5";
        case PIXELFORMAT_UNCOMPRESSED_R8G8B8:
            return "PIXELFORMAT_UNCOMPRESSED_R8G8B8";
        case PIXELFORMAT_UNCOMPRESSED_R5G5B5A1:
            return "PIXELFORMAT_UNCOMPRESSED_R5G5B5A1";
        case PIXELFORMAT_UNCOMPRESSED_R4G4B4A4:
            return "PIXELFORMAT_UNCOMPRESSED_R4G4B4A4";
        case PIXELFORMAT_UNCOMPRESSED_R8G8B8A8:
            return "PIXELFORMAT_UNCOMPRESSED_R8G8B8A8";
        case PIXELFORMAT_UNCOMPRESSED_R32:
            return "PIXELFORMAT_UNCOMPRESSED_R32";
        case PIXELFORMAT_UNCOMPRESSED_R32G32B32:
            return "PIXELFORMAT_UNCOMPRESSED_R32G32B32";
        case PIXELFORMAT_UNCOMPRESSED_R32G32B32A32:
            return "PIXELFORMAT_UNCOMPRESSED_R32G32B32A32";
        case PIXELFORMAT_UNCOMPRESSED_R16:
            return "PIXELFORMAT_UNCOMPRESSED_R16";
        case PIXELFORMAT_UNCOMPRESSED_R16G16B16:
            return "PIXELFORMAT_UNCOMPRESSED_R16G16B16";
        case PIXELFORMAT_UNCOMPRESSED_R16G16B16A16:
            return "PIXELFORMAT_UNCOMPRESSED_R16G16B16A16";
        case PIXELFORMAT_COMPRESSED_DXT1_RGB:
            return "PIXELFORMAT_COMPRESSED_DXT1_RGB";
        case PIXELFORMAT_COMPRESSED_DXT1_RGBA:
            return "PIXELFORMAT_COMPRESSED_DXT1_RGBA";
        case PIXELFORMAT_COMPRESSED_DXT3_RGBA:
            return "PIXELFORMAT_COMPRESSED_DXT3_RGBA";
        case PIXELFORMAT_COMPRESSED_DXT5_RGBA:
            return "PIXELFORMAT_COMPRESSED_DXT5_RGBA";
        case PIXELFORMAT_COMPRESSED_ETC1_RGB:
            return "PIXELFORMAT_COMPRESSED_ETC1_RGB";
        case PIXELFORMAT_COMPRESSED_ETC2_RGB:
            return "PIXELFORMAT_COMPRESSED_ETC2_RGB";
        case PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA:
            return "PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA";
        case PIXELFORMAT_COMPRESSED_PVRT_RGB:
            return "PIXELFORMAT_COMPRESSED_PVRT_RGB";
        case PIXELFORMAT_COMPRESSED_PVRT_RGBA:
            return "PIXELFORMAT_COMPRESSED_PVRT_RGBA";
        case PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA:
            return "PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA";
        case PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA: 
            return "PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA";
        default: return "UNKNOWN";
    }
}

} // End of tmns::calc::drv namespace