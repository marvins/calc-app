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
 * @file    Options.cpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#include <terminus/core/Options.hpp>

// Project Libraries
#include <terminus/core/ConfigParser.hpp>

// C++ Standard Libraries
#include <chrono>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace tmns::core {

/********************************/
/*      Get the log level       */
/********************************/
log::Level Options::log_level() const{
    return m_log_level;
}

/*************************************/
/*      Print Log-Friendly String    */
/*************************************/
std::string Options::to_log_string( size_t offset ) const
{
    std::string gap( offset, ' ' );

    std::stringstream sout;
    sout << gap << "Configuration:" << std::endl;
    sout << gap << "  - app_name: " << m_app_name.native() << std::endl;
    sout << gap << "  - settings: (sections: " << m_settings.size() << ")" << std::endl;
    for( const auto& setting : m_settings ){
        sout << gap << "     - " << setting.first << std::endl;
        for( const auto& kvp : setting.second ){
            sout << gap << "        - " << kvp.first << " = " << kvp.second << std::endl;
        }
    }
    return sout.str();
}

/*************************************/
/*      Print Usage Instructions     */
/*************************************/
std::string Options::usage() const{
    
    std::stringstream sout;
    sout << "usage: " << m_app_name.filename() << " [optional flags] -c <config-path>" << std::endl;
    sout << std::endl;
    sout << "required flags:" << std::endl;
    sout << "  -c <config-path> | --config-path <config-path> : Path to Python INI formatted config-file" << std::endl;
    sout << "                     - Note:  Use gen-config flag to see available options" << std::endl;
    sout << std::endl;
    sout << "optional flags:" << std::endl;
    sout << "  -h | --help : Print usage instructions and exit." << std::endl;
    sout << std::endl;
    sout << "  -g | --gen-config : Generate new config file at path specified by -c flag." << std::endl;
    sout << std::endl;
    sout << "  -v | --verbose : Use debug logging." << std::endl;
    sout << "  -vv | --trace : Use trace logging." << std::endl;
    sout << std::endl;
    sout << "  -l <path> | --log-path <path> : Write output to log file." << std::endl;
    sout << std::endl;

    // Print examples of the app


    return sout.str();
}

/****************************************************************/
/*      Parse Command-Line Options and Config-File Options      */
/****************************************************************/
Options Options::parse( int argc, char* argv[] )
{
    auto app_name = std::filesystem::path( argv[0] );
    auto options = Options( app_name );

    // Get all arguments
    std::deque<std::string> args;
    for( int i = 1; i < argc; i++ ){
        args.push_back( argv[i] );
    }

    // Parse each argument in sequence
    while( !args.empty() ){

        // Pop next argument
        auto arg = args.front();
        args.pop_front();

        // Check if usage printed
        if( arg == "-h" || arg == "--help" ){
            auto msg = options.usage();
            std::cerr << msg;
            std::exit(0);
        }

        // Check if verbose / debug
        else if( arg == "-v" || arg == "--debug" ){
            options.m_log_level = log::Level::DEBUG;
        }

        else if( arg == "-vv" || arg == "--trace" ){
            options.m_log_level = log::Level::TRACE;
        }

        // Check if generate-config flag specified
        else if( arg == "-g" || arg == "--gen-config" ){
            options.m_gen_config = true;
        }

        // Check if config-path specified
        else if( arg == "-c" || arg == "--config-path" ){

            if( args.empty() ){
                throw std::runtime_error("Cannot get config-path as arg list is empty");
            }

            options.m_config_path = args.front();
            args.pop_front();
        }

        else {
            std::cerr << "error: Unsupported argument (" << arg << ")" << std::endl;
            std::cerr << options.usage() << std::endl;
            std::exit(1);
        }

    }

    // Verify options
    std::string errstr; 
    if( !options.verify(errstr) ){
        throw std::runtime_error( "Cannot verify configuration.  Issues: " + errstr );
    }

    // If we should generate a config, then just knock this out now and exit
    if( options.m_gen_config ){
        options.generate_config_file( options.m_config_path );
        std::exit(0);
    }

    // Parse the configuration file
    options.m_settings = ConfigParser::parse( options.m_config_path );

    return options;
}

/*************************************************/
/*          Generate Configuration File          */
/*************************************************/
void Options::generate_config_file( const std::filesystem::path& pathname )
{

    std::ofstream fout( pathname );

    fout << "#" << std::endl;
    fout << "#  Terminus Calculator Application Configuration File" << std::endl;
    fout << "#" << std::endl;
    fout << "#  File: " << pathname.native() << std::endl;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    fout << "#  Date: " << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << std::endl;
    fout << "#" << std::endl;
    fout << std::endl;

    // Print display options
    fout << "#  Display Options" << std::endl;
    fout << "#   - These are highly dependent on hardware.  Given that the systems are primarily embedded, we have" << std::endl;
    fout << "#     a flag called \"override\" which tells the app whether or not to use the default size as found by the system." << std::endl;
    fout << "[display]" << std::endl;
    fout << std::endl;
    fout << "#  Allow the system to determine screen size.  Set to true for embedded systems." << std::endl;
    fout << "override_screen_size=true" << std::endl;
    fout << std::endl;

    fout << "#  Set the default screen size" << std::endl;
    fout << "screen_width=1280" << std::endl;
    fout << "screen_height=780" << std::endl;
    fout << std::endl;

    fout << "#  Set the Header's height.  Eventually we should make this more dynamic" << std::endl;
    fout << "header_height=80" << std::endl;
    fout << std::endl;

    fout << "#  Set the Footers's height.  Eventually we should make this more dynamic" << std::endl;
    fout << "footer_height=80" << std::endl;
    fout << std::endl;

    fout << "#  Section for the Primary Menu" << std::endl;
    fout << "[menu]" << std::endl;
    fout << std::endl;
    fout << "#  Icon to use for the splash screen" << std::endl;
    fout << "splash_icon_path=./cpp/resources/images/logo/logo_360_144.png" << std::endl;
    fout << std::endl;
    fout << "#  Sleep time in ms for splash screen" << std::endl;
    fout << "splash_time_sleep_ms=5000" << std::endl;
    fout << std::endl;

    fout << "# Settings for the resource manager" << std::endl;
    fout << "[resources]" << std::endl;
    fout << std::endl;
    fout << "# Base directory for all resource data." << std::endl;
    fout << "root_dir=./cpp/resources" << std::endl;    

}

/************************************************/
/*          Parameterized Constructor           */
/************************************************/
Options::Options( const std::filesystem::path& app_name )
    : m_app_name (app_name){}

/********************************************************/
/*          Verify Application Configuration            */
/********************************************************/
bool Options::verify( std::string& error_str ) const {

    // Clear string
    error_str = "";

    // Make sure config-path exists only if gen-config does not exist
    if( !m_gen_config && !std::filesystem::exists( m_config_path ) ){
        std::stringstream sout;
        sout << "Configuration file (" << m_config_path.native() << ") does not exist.";
        sout << "  This can only not-exist when --gen-config (-g) is passed.";
        error_str = sout.str();
        return false;
    }

    // If nothing causes us to blow up, then consider it good
    return true;
}

/****************************************************************/
/*          Verify if a setting exists and return it            */
/****************************************************************/
std::optional<std::string> Options::get_setting( std::string section_name,
                                                 std::string key_name ) const {

    // Verify Section Exists
    const auto& sec_iter = m_settings.find( section_name );
    if( sec_iter == m_settings.end() ){
        return {};
    }

    // Verify key exists
    const auto& key_iter = sec_iter->second.find( key_name );
    if( key_iter == sec_iter->second.end() ){
        return {};
    }

    return key_iter->second;
}

} // End of tmns::core namespace