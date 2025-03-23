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
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
 */
#pragma once

// C++ Standard Libraries
#include <filesystem>
#include <map>
#include <string>
#include <type_traits>

// Project Libraries
#include <tmns/app/calc/log/Level.hpp>
#include <tmns/app/calc/utils/StringUtilities.hpp>

namespace tmns::calc::core {

class Options final {

    public:

        /**
         * Get the configuration settings
         */
        template <typename VALTYPE>
        VALTYPE setting( const std::string& section,
                         const std::string& key ) const {
            return m_settings.find(section)->second.find(key)->second;
        }

        /**
         * Instanciation for bools
         */
        template <typename VALTYPE>
        VALTYPE setting( const std::string& section,
                         const std::string& key ) const requires std::is_same<VALTYPE,bool>::value {
            auto bval = utils::to_lower( setting<std::string>( section, key ) );
            return ( bval == "true" || bval == "1" );
        }

        /**
         * Instanciation for integers
         */
        template <typename VALTYPE>
        VALTYPE setting( const std::string& section,
                         const std::string& key ) const requires std::is_same<VALTYPE,int32_t>::value {
            return std::stoi( setting<std::string>( section, key ) );
        }

        /**
         * Instanciation for floats
         */
        template <typename VALTYPE>
        VALTYPE setting( const std::string& section,
                         const std::string& key ) const requires std::is_same<VALTYPE,float>::value {
            return std::stof( setting<std::string>( section, key ) );
        }

        /**
         * Instanciation for paths
         */
        template <typename VALTYPE>
        VALTYPE setting( const std::string& section,
                         const std::string& key ) const requires std::is_same<VALTYPE,std::filesystem::path>::value {
            return std::filesystem::path( setting<std::string>( section, key ) );
        }

        
        /**
         * Get the log severity
         */
        log::Level log_level() const;

        /**
         * Print Log-Friendly String
         */
        std::string to_log_string( size_t offset = 0 ) const;

        /**
         * Print usage as log-friendly string
         */
        std::string usage() const;

        /**
         * @brief Parse command-line and config-file options and return 
         *        usable Options structure. 
         * 
         * @note  This method will abort if it finds a configuration that is
         *        not usable 
         */
        static Options parse( int argc, char* argv[] );

        /**
         * @brief Generate a configuration file at the specified path.
         * 
         * @param pathname
         */
        static void generate_config_file( const std::filesystem::path& pathname );

    private:

        /**
         * Parameterized Constructor
         */
        Options( const std::filesystem::path& app_name );

        /**
         * Verify configuration
         */
        bool verify( std::string& error_str ) const;

        /// Application Name
        std::filesystem::path m_app_name;

        /// Configuration file path
        std::filesystem::path m_config_path;

        /// Log Severity
        log::Level m_log_level { log::Level::INFO };

        /// Flag to create configuration-file
        bool m_gen_config { false };

        /// Configuration File Settings
        std::map<std::string,std::map<std::string,std::string>> m_settings;

}; // End of Options Class

} // End of tmns::core namespace