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
 * @file    ConfigParser.cpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#include <tmns/app/calc/core/ConfigParser.hpp>

// Project Libraries
#include <tmns/app/calc/utils/StringUtilities.hpp>

// C++ Standard Libraries
#include <fstream>
#include <iostream>
#include <sstream>


namespace tmns::calc::core {

/************************************************/
/*          Parse Configuration File            */
/************************************************/
ConfigParser::SETTINGS_TYPE ConfigParser::parse( const std::filesystem::path& path ){

    ConfigParser::SETTINGS_TYPE settings;

    // Verify the file exists
    if( !std::filesystem::exists( path ) ){
        throw std::runtime_error( "Config file does not exist: " + path.native() );
    }

    // Parse the file
    std::ifstream fin;
    fin.open( path );

    std::string line;

    std::getline( fin, line );

    std::string current_section;

    while( fin.good() ){

        // Strip out junk
        auto input = utils::string_trim( line );

        // Check for comment
        if( input.empty() || input[0] == '#' ){
            std::getline( fin, line );
            continue;
        }

        // Check for section name
        if( input[0] == '[' && input[input.size()-1] == ']' ){
            current_section = input.substr( 1, input.size() - 2 );
            
            if( settings.find( current_section ) == settings.end() ){
                settings[current_section] = std::map<std::string,std::string>();
            }
            std::getline( fin, line );
            continue;
        }

        // Split line based on equal sign
        auto parts = utils::string_split( input, '=' );
        
        if( parts.size() > 2 ){
            settings[current_section][parts[0]] = parts[1];
        }

        // Grab next line
        std::getline( fin, line );
    }

    fin.close();

    return settings;
}

} // End of tmns::core namespace