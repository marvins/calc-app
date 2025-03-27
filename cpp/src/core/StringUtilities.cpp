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
 * @file    StringUtilities.cpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#include <terminus/core/StringUtilities.hpp>

// C++ Standard Libraries
#include <algorithm>
#include <sstream>

namespace tmns::core {

/********************************************/
/*          Convert to Lower-Case           */
/********************************************/
std::string to_lower( const std::string& input )
{
    std::string result = input;
    std::transform( result.begin(),
                    result.end(),
                    result.begin(),
                    [](unsigned char c) {
                        return std::tolower(c);
                    });
    return result;
}

/************************************/
/*          Trim the String         */
/************************************/
std::string  string_trim( const std::string& input,
                          const std::string& whitespace ){

    // Find first occurrance
    auto start = input.find_first_not_of( whitespace );
    auto end   = input.find_last_not_of( whitespace );
    return (start == std::string::npos || end == std::string::npos) ? "" : input.substr(start, end - start + 1);
}

/****************************************/
/*          Split the String            */
/****************************************/
std::vector<std::string> string_split( const std::string& input, char delimiter )
{
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

} // End of tmns::core namespace