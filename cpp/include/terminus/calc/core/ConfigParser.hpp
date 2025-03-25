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
 * @file    ConfigParser.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#pragma once

// C++ Standard Libraries
#include <filesystem>
#include <map>
#include <string>

namespace tmns::calc::core {

class ConfigParser {

    public:

        using SETTINGS_TYPE = std::map<std::string,std::map<std::string,std::string>>;

        /**
         * Parse Configuration File
         */
        static SETTINGS_TYPE parse( const std::filesystem::path& path );

    private:


}; // End of ConfigParser Class

} // End of tmns::core namespace