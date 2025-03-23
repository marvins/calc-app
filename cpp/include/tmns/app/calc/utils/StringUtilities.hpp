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
 * @file    StringUtilities.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#pragma once

// C++ Standard Libraries
#include <string>
#include <vector>

namespace tmns::calc::utils {

/**
 * Make the string lower-case
 */
std::string to_lower( const std::string& input );

/**
 * @brief Trim the string
 */
std::string string_trim( const std::string& input,
                         const std::string& chars = " \n\r\t\f\v" );

/**
 * @brief Split the string based on deliminator
 */
std::vector<std::string> string_split( const std::string& input,
                                       char               deliminator );


} // End of tmns::calc::utils namespace